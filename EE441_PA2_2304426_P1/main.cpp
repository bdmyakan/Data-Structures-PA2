//
//  main.cpp
//  pa
//
//  Created by Bahadır on 3.12.2022.
//

#include <iostream>
#include "maze.h"

using namespace std;

int main() {
    //Part 1
    /*
    Maze frq;
    frq.print_state();
    cout<<frq.is_solved()<<endl;
    cout<<frq.can_move_back()<<endl;
    cout<<frq.can_move_forward()<<endl;
    cout<<frq.can_move_right()<<endl;
    cout<<frq.can_move_left()<<endl;
    frq.move_right();
    frq.move_forward();
    frq.move_left();
    frq.move_forward();
    frq.move_forward();
    frq.move_right();
    frq.move_forward();
    frq.move_forward();
    frq.move_forward();
    frq.move_left();
    cout<<frq.is_solved()<<endl;
    frq.print_state();
    frq.move_forward();
    cout<<frq.is_solved()<<endl;
    */
    //Part 2
/*
    StackQueue<char> List;
    List.push_front('G');
    List.push_front('A');
    List.push_front('D');
    List.push_rear('F');
    List.push_rear('Z');
    List.push_rear('K');
    List.print_elements();
*/
    //Part 3

    Maze To_be_Solved;
    StackQueue<char> SQ;

    //First Pass
    cout << "First Pass:"<<endl;
    cout << "SQ: ";
    SQ.print_elements();
    cout<<endl;
    To_be_Solved.print_state();
    cout<<endl;

    while(To_be_Solved.is_solved()!=1){
        char seq[3];
        if(To_be_Solved.can_move_left()){
            To_be_Solved.move_left();
            if( SQ.peek_front() != 'B' || SQ.count <2)
                SQ.push_front('L');
            else{
                seq[2] = 'L';
                seq[1] = SQ.pop_front();
                seq[0] = SQ.pop_front();

                if(seq[1] == 'B' && seq[0] == 'L' )
                    SQ.push_front('F');
                else if(seq[1] == 'B' && seq[0] == 'F' )
                    SQ.push_front('R');
                else if(seq[1] == 'B' && seq[0] == 'R' )
                    SQ.push_front('B');
                else{
                    SQ.push_front(seq[0]);
                    SQ.push_front(seq[1]);
                    SQ.push_front(seq[2]);
                }
            }
        }
        else if(To_be_Solved.can_move_forward()){
            To_be_Solved.move_forward();
            if( SQ.peek_front() != 'B'|| SQ.count <2)
                SQ.push_front('F');
            else{
                seq[2] = 'F';
                seq[1] = SQ.pop_front();
                seq[0] = SQ.pop_front();

                if(seq[1] == 'B' && seq[0] == 'L' )
                    SQ.push_front('R');
                else if(seq[1] == 'B' && seq[0] == 'F' )
                    SQ.push_front('B');
                else{
                    SQ.push_front(seq[0]);
                    SQ.push_front(seq[1]);
                    SQ.push_front(seq[2]);
                }
            }
        }
        else if(To_be_Solved.can_move_right()){
            To_be_Solved.move_right();
            if( SQ.peek_front() != 'B' || SQ.count <2)
                SQ.push_front('R');
            else{
                seq[2] = 'R';
                seq[1] = SQ.pop_front();
                seq[0] = SQ.pop_front();

                if(seq[1] == 'B' && seq[0] == 'L' )
                    SQ.push_front('R');
                else{
                    SQ.push_front(seq[0]);
                    SQ.push_front(seq[1]);
                    SQ.push_front(seq[2]);
                }
            }
        }
            else if(To_be_Solved.can_move_back()){
                To_be_Solved.move_back();
                SQ.push_front('B');
            }
        cout << "SQ: ";
        SQ.print_elements();
        cout<<endl;
        To_be_Solved.print_state();
        cout<<endl;
        if(To_be_Solved.is_solved() == 1)
            cout<<"Maze is solved!"<<endl;
    }
    //second pass
    char temp;
    Maze Second_maze;
    cout << "Second Pass:"<<endl;
    cout << "SQ: ";
    SQ.print_elements();
    cout<<endl;
    Second_maze.print_state();
    cout<<endl;
    while(Second_maze.is_solved() != 1){
        temp = SQ.pop_rear();
        if(temp == 'L')
            Second_maze.move_left();
        else if(temp == 'F')
            Second_maze.move_forward();
        else if(temp == 'R')
            Second_maze.move_right();
        else if(temp == 'B')
            Second_maze.move_back();
        cout << "SQ: ";
        SQ.print_elements();
        cout<<endl;
        Second_maze.print_state();
        cout<<endl;
    }

    return 0;
}
