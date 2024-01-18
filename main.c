#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};
typedef struct node node_t;

//Function to print the linkedlist in its entirety.
void printLL(node_t *head){
    node_t *temp = head;
    printf("The LinkedList: \n");

    while (temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

//Function to add a node to the linkedlist.
node_t *add_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

//add a single node of a user-specified value to the linkedlist at the head.
void add_single_node(int value, node_t **head) {
    node_t *new_node = add_node(value);
    new_node->next = *head;
    *head = new_node;
}

//Add a user-specified number of nodes to the list.
void add_multiple_nodes(int amount, node_t **head) {
    node_t *temp;
    for (int i = 0; i < amount; i++) {
        temp = add_node(i);
        temp->next = *head;
        *head = temp;
    }
}

//Add a node into a specific position in the list.
void add_in_position(int value, int pos, node_t **head) {
    node_t *new_node = add_node(value);

    if (pos == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }
    node_t *current = *head;
    for (int i = 0; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        //If position > length of the list.
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    } else {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_in_position(int pos, node_t **head) {
    if (*head == NULL) {
        //If the list is empty.
        return;
    }
    node_t *temp;

    if (pos == 0) {
        temp = *head;
        *head = (*head)->next;
    } else {
        node_t *current = *head;
        for (int i = 0; i < pos - 1 && current->next != NULL; i++) {
            current = current->next;
        }
        if (current->next == NULL) {
            //If position > length of the list.
            return;
        }
        //Deleting the node.
        temp = current->next;
        current->next = temp->next;
    }
    //Freeing memory for the node that was deleted.
    free(temp);
}

int main() {
    node_t *head = NULL;
    node_t *temp;

    //Sample run of the functions.
    add_multiple_nodes(24, &head);
    add_single_node(40, &head);
    add_multiple_nodes(8, &head);
    add_in_position(99, 20, &head);
    delete_in_position(4, &head);

    printLL(head);

    return 0;
}