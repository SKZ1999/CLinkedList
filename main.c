#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};
typedef struct node node_t;

void printLL(node_t *head){
    node_t *temp = head;
    printf("The LinkedList: \n");

    while (temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node_t node1, node2, node3;
    node_t *head;

    node1.value = 45;
    node2.value = 80;
    node3.value = 99;

    //linking nodes together
    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    printLL(head);

    return 0;
}