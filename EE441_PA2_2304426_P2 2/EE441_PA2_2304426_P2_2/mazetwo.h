
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

// Maze class functions end
// Maze ends

// Xor linked list begins


template <class T>
class Node{
    public :
    T data;
    // Xor of next node and previous node
    Node<T>* xnode;
};



template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y) {
    return reinterpret_cast<Node<T>*>( reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

template <class T>
void insert(Node<T>* &head_ref, T data) {
    // Allocate memory for the new node
    Node<T>* new_node = new Node<T>();
    new_node -> data = data;
    // Since the new node is inserted at the // start, xnode of new node will always be // Xor of current head and NULL
    new_node -> xnode = head_ref;
    // If the linkedlist is not empty, then xnode of // present head node will be XOR of the new node // and node next to current head */
    if (head_ref != NULL)
    {
        // *(head_ref)->xnode is Xor of (NULL and next). // If we XOR Null with next, we get next
        head_ref->xnode = Xor(new_node, head_ref->xnode);
    }
        // Change head
    head_ref = new_node;

}


template <class T>
void printList_node(Node<T>* head){
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;
    cout << "The nodes of Linked List are: \n";
        // Till condition holds true
    while (currPtr != NULL) {
    // print current node
        cout << currPtr -> data << endl;
    // get the address of next node: currPtr->xnode is
    // {nextPtr (XOR) prevPtr}, so {currPtr->xnode (XOR) prevPtr} will
    // be {nextPtr (XOR) prevPtr (XOR) prevPtr}, which is nextPtr
        nextPtr = Xor(prevPtr, currPtr -> xnode);
    // update prevPtr and currPtr for next iteration
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    cout<<endl;
}

template <class T>
void push_front_node(Node<T>* &head, T data){
    insert(head,data);
}

template <class T>
void push_rear_node(Node<T>* &head , T data){
    if(head != NULL){
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;
    while((Xor(prevPtr, currPtr -> xnode)) != NULL){
        nextPtr = Xor(prevPtr, currPtr -> xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
        }
    insert(currPtr,data);
    }
    else{
        cerr<<"NULL"<<endl;
        exit(1);
    }
}

template <class T>
Node<T>* pop_front_node(Node<T>* &head){
    Node<T>* temp = head;
    Node<T>* prevPtr = NULL;
    if(temp != NULL){
        head = Xor(prevPtr, head -> xnode);
        if(head!=NULL)
            head->xnode = Xor(prevPtr, Xor(temp,head->xnode));
        }
    else{
        cerr<<"NULL"<<endl;
        exit(1);
    }
    return temp;
}

template <class T>
Node<T>* pop_rear_node(Node<T>* &head){
    Node<T>* temp = NULL;
    if(head != NULL){
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;
    while((Xor(prevPtr, currPtr -> xnode)) != NULL){
        nextPtr = Xor(prevPtr, currPtr -> xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
        }
    temp = pop_front_node(currPtr);
    }
    else{
        cerr<<"NULL"<<endl;
        exit(1);
    }
    return temp;
}

template <class T>
T peek_front_node( Node<T>* &head){
    Node<T>* temp = NULL;
    if(head != NULL){
        temp = head;
        return temp->data;
        }

    return 0;
}


template <class T>
void print_elements_node( Node<T>* &head){
    if(head != NULL){
    Node<T>* currPtr = head;
    Node<T>* prevPtr = NULL;
    Node<T>* nextPtr;
    T Array[1024];
    int i = 0;
    while(currPtr != NULL){
        Array[i] = currPtr->data;
        i++;
        nextPtr = Xor(prevPtr, currPtr -> xnode);
        prevPtr = currPtr;
        currPtr = nextPtr;
        }
    while(i>0){
        cout<<Array[i-1]<<" ";
        i--;
    }
    }
    else{
        cerr<<" "<<endl;
    }
}

//Xor linked list ends

// LL_wrapper begins
template <class T> class LL_wrapper{
    private :
        Node<T>* head_node;
    public :
        LL_wrapper();
        int count;
        void push_front(T data){
            push_front_node(*&head_node, data);
            count ++;
        }
        void push_rear(T data){
            push_rear_node(*&head_node, data);
            count ++;
        }
        T pop_front(){
            Node<T>* temp;
            temp = pop_front_node(*&head_node);
            count--;
            return temp->data;
        }
        T pop_rear(){
            Node<T>* temp;
            temp = pop_rear_node(*&head_node);
            count --;
            return temp->data;
        }
        T peek_front(){
            return peek_front_node(*&head_node);
        }
        void print_elements(){
            print_elements_node(*&head_node);
        }
};

template <class T>
LL_wrapper<T>::LL_wrapper(){
    head_node = NULL;
    count = 0;
}

//LL_wrapper ends
