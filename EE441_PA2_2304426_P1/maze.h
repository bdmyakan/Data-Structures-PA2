
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;

// Maze Begins
class Maze{
    private:
        int row,column;
        char **state;
    public:
        Maze();
        ~Maze();
        bool can_move_left();
        bool can_move_forward();
        bool can_move_right();
        bool can_move_back();
        void move_left();
        void move_forward();
        void move_right();
        void move_back();

        void print_state();
        bool is_solved();
};

// Maze Class Functions Begin

Maze::Maze(){
    /* reading the maze from file */
    std::fstream input_file;
    /* input file stream */
    input_file.open ("C:/Users/Bahadir/Desktop/input_maze.txt");
    if(input_file.is_open()==0){
        cerr<<"Error occured while opening the input file. Please check"<<endl;
        exit(1);
    }

    int nrow, ncol; /* number of rows and columns */
    input_file >> nrow >> ncol; /* read the size from file */
    if(nrow<20 && ncol<20 && 0<nrow && 0<ncol){
        row = nrow;
        column = ncol;
        state = new char* [nrow];
        for(int i = 0; i < nrow; ++i) {
            state[i] = new char[ncol];
        }

        for(int i=0; i<nrow; ++i){
            for(int j=0; j<ncol; ++j){
                input_file >> state[i][j];
            }
        }

        input_file.close();
    }
    else{
        cerr << "The indices are given wrong" << endl;
        exit(1);
    }
}

Maze::~Maze(){
    for(int i = 0; i < row; ++i)
           delete state[i];
    delete state;
}

bool Maze::can_move_left(){
    char temp = '0';
    int i, j;
    int curr_row=0,curr_col=0;
    for(i=0; row>i ; i++){
        for(j=0; column>j ; j++){
            if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                temp = state[i][j];
                curr_row = i;
                curr_col = j;
                break;
            }
        }
    }
    if (temp == 'E'){
        if(state[curr_row-1][curr_col] == '.' || state[curr_row-1][curr_col] =='T')
            return true;
        else if(state[curr_row-1][curr_col] == '#')
            return false;
    }
    else if (temp == 'N'){
        if(state[curr_row][curr_col-1] == '.' || state[curr_row][curr_col-1] == 'T')
            return true;
        else if(state[curr_row][curr_col-1] == '#')
            return false;
    }
    else if (temp == 'S'){
        if(state[curr_row][curr_col+1] == '.' || state[curr_row][curr_col+1] == 'T')
            return true;
        else if(state[curr_row][curr_col+1] == '#')
            return false;
    }
    else if (temp == 'W'){
        if(state[curr_row+1][curr_col] == '.' || state[curr_row+1][curr_col] == 'T')
            return true;
        else if(state[curr_row+1][curr_col] == '#')
            return false;
    }
    return false;
}

bool Maze::can_move_forward(){
    char temp = '0';
    int i, j;
    int curr_row=0,curr_col=0;
    for(i=0; row>i ; i++){
        for(j=0; column>j ; j++){
            if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                temp = state[i][j];
                curr_row = i;
                curr_col = j;
                break;
            }
        }
    }
    if (temp == 'E'){
        if(state[curr_row][curr_col+1] == '.' || state[curr_row][curr_col+1] == 'T')
            return true;
        else if(state[curr_row][curr_col+1] == '#')
            return false;
    }
    else if (temp == 'N'){
        if(state[curr_row-1][curr_col] == '.' || state[curr_row-1][curr_col] == 'T')
            return true;
        else if(state[curr_row-1][curr_col] == '#')
            return false;
    }
    else if (temp == 'S'){
        if(state[curr_row+1][curr_col] == '.' || state[curr_row+1][curr_col] == 'T' )
            return true;
        else if(state[curr_row+1][curr_col] == '#')
            return false;
    }
    else if (temp == 'W'){
        if(state[curr_row][curr_col-1] == '.' || state[curr_row][curr_col-1] == 'T')
            return true;
        else if(state[curr_row][curr_col-1] == '#')
            return false;
    }
    return false;
}

bool Maze::can_move_right(){
    char temp = '0';
    int i, j;
    int curr_row=0,curr_col=0;
    for(i=0; row>i ; i++){
        for(j=0; column>j ; j++){
            if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                temp = state[i][j];
                curr_row = i;
                curr_col = j;
                break;
            }
        }
    }
    if (temp == 'E'){
        if(state[curr_row+1][curr_col] == '.' || state[curr_row+1][curr_col] == 'T')
            return true;
        else if(state[curr_row+1][curr_col] == '#')
            return false;
    }
    else if (temp == 'N'){
        if(state[curr_row][curr_col+1] == '.' || state[curr_row][curr_col+1] == 'T')
            return true;
        else if(state[curr_row][curr_col+1] == '#')
            return false;
    }
    else if (temp == 'S'){
        if(state[curr_row][curr_col-1] == '.' || state[curr_row][curr_col-1] == 'T')
            return true;
        else if(state[curr_row][curr_col-1] == '#')
            return false;
    }
    else if (temp == 'W'){
        if(state[curr_row-1][curr_col] == '.' || state[curr_row-1][curr_col] == 'T')
            return true;
        else if(state[curr_row-1][curr_col] == '#')
            return false;
    }
    return false;
}
bool Maze::can_move_back(){
    char temp = '0';
    int i, j;
    int curr_row=0,curr_col=0;
    for(i=0; row>i ; i++){
        for(j=0; column>j ; j++){
            if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                temp = state[i][j];
                curr_row = i;
                curr_col = j;
                break;
            }
        }
    }
    if (temp == 'E'){
        if(state[curr_row][curr_col-1] == '.' || state[curr_row][curr_col-1] == 'T')
            return true;
        else if(state[curr_row][curr_col-1]  == '#')
            return false;
    }
    else if (temp == 'N'){
        if(state[curr_row+1][curr_col] == '.' || state[curr_row+1][curr_col] == 'T')
            return true;
        else if(state[curr_row+1][curr_col] == '#')
            return false;
    }
    else if (temp == 'S'){
        if(state[curr_row-1][curr_col] == '.' || state[curr_row-1][curr_col] == 'T')
            return true;
        else if(state[curr_row-1][curr_col] == '#')
            return false;
    }
    else if (temp == 'W'){
        if(state[curr_row][curr_col+1] == '.' || state[curr_row][curr_col+1] == 'T')
            return true;
        else if(state[curr_row][curr_col+1] == '#')
            return false;
    }
    return false;
}

void Maze::move_left(){
    if(can_move_left()){
        char temp = '0';
        int i=0, j=0;
        int curr_row=0,curr_col=0;
        for(i=0; row>i ; i++){
            for(j=0; column>j ; j++){
                if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    temp = state[i][j];
                    curr_row = i;
                    curr_col = j;
                    break;
                }
            }
        }
        state[curr_row][curr_col]='.';
        if(temp == 'E')
            state[curr_row-1][curr_col]='N';
        else if(temp == 'N')
            state[curr_row][curr_col-1]='W';
        else if(temp == 'S')
            state[curr_row][curr_col+1]='E';
        else if(temp == 'W')
            state[curr_row+1][curr_col]='S';
        cout<<"Moved Left"<<endl;
    }
    else
        cout<<"Move is not possible"<<endl;
}

void Maze::move_forward(){
    if(can_move_forward()){
        char temp = '0';
        int i=0, j=0;
        int curr_row=0,curr_col=0;
        for(i=0; row>i ; i++){
            for(j=0; column>j ; j++){
                if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    temp = state[i][j];
                    curr_row = i;
                    curr_col = j;
                    break;
                }
            }
        }
        state[curr_row][curr_col]='.';
        if(temp == 'E')
            state[curr_row][curr_col+1]='E';
        else if(temp == 'N')
            state[curr_row-1][curr_col]='N';
        else if(temp == 'S')
            state[curr_row+1][curr_col]='S';
        else if(temp == 'W')
            state[curr_row][curr_col-1]='W';
        cout<<"Moved Forward"<<endl;
    }
    else
        cout<<"Move is not possible"<<endl;
}
void Maze::move_right(){
    if(can_move_right()){
        char temp = '0';
        int i=0, j=0;
        int curr_row=0,curr_col=0;
        for(i=0; row>i ; i++){
            for(j=0; column>j ; j++){
                if(state[0+i][0+j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    temp = state[i][j];
                    curr_row = i;
                    curr_col = j;
                    break;
                }
            }
        }
        state[curr_row][curr_col]='.';
        if(temp == 'E')
            state[curr_row+1][curr_col]='S';
        else if(temp == 'N')
            state[curr_row][curr_col+1]='E';
        else if(temp == 'S')
            state[curr_row][curr_col-1]='W';
        else if(temp == 'W')
            state[curr_row-1][curr_col]='N';
        cout<<"Moved Right"<<endl;
    }
    else
        cout<<"Move is not possible"<<endl;
}
void Maze::move_back(){
    if(can_move_back()){
        char temp = '0';
        int i=0, j=0;
        int curr_row=0,curr_col=0;
        for(i=0; row>i ; i++){
            for(j=0; column>j ; j++){
                if(state[i][j] == 'E' || state[i][j] == 'N' || state[i][j] == 'S' || state[i][j] == 'W' ){
                    temp = state[i][j];
                    curr_row = i;
                    curr_col = j;
                    break;
                }
            }
        }
        state[curr_row][curr_col]='.';
        if(temp == 'E')
            state[curr_row][curr_col-1]='W';
        else if(temp == 'N')
            state[curr_row+1][curr_col]='S';
        else if(temp == 'S')
            state[curr_row-1][curr_col]='N';
        else if(temp == 'W')
            state[curr_row][curr_col+1]='E';
        cout<<"Moved Back"<<endl;
    }
    else
        cout<<"Move is not possible"<<endl;
}

void Maze::print_state(){
    char temp;
    int i=0;
    for(; row>i ; i++){
        int j=0;
        for(; column>j ; j++){
            temp = state[i][j];
            cout<< temp;
        }
        cout<<endl;
    }
}



bool Maze::is_solved(){
    bool end = true;

    for(int i=0; row>i ; i++){
        for(int j=0; column>j ; j++){
            if(state[i][j] == 'T'){
                end = false;
                break;
            }
        }
    }
    return end;
}


// Maze Class Functions End
// Maze Ends

//StackQueue Starts
const int MIN_SIZE = 1024;

template<class T>
class StackQueue{
private:
    T List[MIN_SIZE];
    int front,rear;

public:
    int count;
    StackQueue();
    void push_front(T item);
    void push_rear(T item);
    T pop_front();
    T pop_rear();
    T peek_front() const;
    T peek_rear() const;
    void print_elements() const;
    /*
    friend ostream& operator<< (ostream& stream, const StackQueue& SQ){
     cout<<endl;
    };
    */
};

//StackQueue Functions Start
template <class T>
StackQueue<T>::StackQueue(){
    front = 1;
    rear = 0;
    count = 0;

}

template <class T>
void StackQueue<T>::push_front(T item){
    /*
    if(count == MIN_SIZE){
        cerr<<"Overflow!" <<endl;
        exit(1);
    }
    */
    count++;
    front = ((front-1)+MIN_SIZE)%MIN_SIZE;
    List[front] = item;

}

template <class T>
void StackQueue<T>::push_rear(T item){
    /*
    if(count == MIN_SIZE){
        cerr<<"Overflow!" <<endl;
        exit(1);
    }
    */
    count++;
    rear = ((rear+1)+MIN_SIZE)%MIN_SIZE;
    List[rear] =item;

}

template <class T>
T StackQueue<T>::pop_front(){
    T temp;
    /*
    if(count == 0){
        cerr<<"Empty!" <<endl;
        exit(1);
    }
    */
    temp = List[front];
    count--;
    front = ((front+1)+MIN_SIZE)%MIN_SIZE;
    return temp;
}

template <class T>
T StackQueue<T>::pop_rear(){
    T temp;
    /*
    if(count == 0){
        cerr<<"Empty!" <<endl;
        exit(1);
    }
     */
    temp = List[rear];
    count--;
    rear = ((rear-1)+MIN_SIZE)%MIN_SIZE;
    return temp;
}

template <class T>
T StackQueue<T>::peek_front() const{
    T temp;
    /*
    if(count == 0){
        cerr<<"Empty!" <<endl;
        exit(1);
    }
    */
    temp = List[front];
    return temp;
}

template <class T>
T StackQueue<T>::peek_rear() const{
    T temp;
    /*
    if(count == 0){
        cerr<<"Empty!" <<endl;
        exit(1);
    }
     */
    temp = List[rear];
    return temp;
}

template <class T>
void StackQueue<T>::print_elements() const{
    for(int i = 0 ; i<count ; i++){
        cout << List[((rear-i)+MIN_SIZE)%MIN_SIZE] << " ";
    }
}
//StackQueue Functions End
//StackQueue Ends

