
#include <stdio.h>
#include <iostream>

using namespace std;

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
void printList(Node<T>* head){
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
void push_front(Node<T>* &head, T data){
    insert(head,data);
}

template <class T>
void push_rear(Node<T>* &head , T data){
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
Node<T>* pop_front(Node<T>* &head){
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
Node<T>* pop_rear(Node<T>* &head){
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
    temp = pop_front(currPtr);
    }
    else{
        cerr<<"NULL"<<endl;
        exit(1);
    }
    return temp;
}

template <class T>
Node<T>* peek_front( Node<T>* &head){
    Node<T>* temp = NULL;
    if(head != NULL)
        temp = head;
    else{
        cerr<<"NULL"<<endl;
        exit(1);
    }
    return temp;
}


template <class T>
void print_elements( Node<T>* &head){
    if(head != NULL){
    cout << "The nodes of Linked List are from end to beginning: \n";
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
        cout<<Array[i-1]<<endl;
        i--;
    }
    }
    else{
        cerr<<"NULL"<<endl;
        exit(1);
    }
}
