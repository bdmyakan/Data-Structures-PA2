
#include <stdio.h>
#include <iostream>
#include "linked_list.h"

using namespace std;

int main(){
    Node<int>* temp = NULL;
    Node<int>* head = NULL;
    insert(head, 5);
    insert(head, 43);
    insert(head, 31);
    insert(head, 17);

    // Printing the created list
    printList(head);
    push_front(head,36);
    printList(head);

    push_rear(head,56);
    printList(head);

    temp = pop_front(head);
    cout<<temp->data<<endl;

    printList(head);

    temp = pop_rear(head);
    cout<<temp->data<<endl;

    printList(head);

    temp = peek_front(head);
    cout<<temp->data<<endl;

    printList(head);


    print_elements(head);
    return 0;
}
