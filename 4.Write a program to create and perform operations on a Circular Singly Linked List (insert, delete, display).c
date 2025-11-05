#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the circular linked list
void insert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = data;

    if (*head_ref == NULL) {
        new_node->next = new_node;  // Point to itself if list is empty
        *head_ref = new_node;
        return;
    }

    while (temp->next != *head_ref)
        temp = temp->next;

    temp->next = new_node;
    new_node->next = *head_ref;
}

// Function to delete a node by value in circular singly linked list
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *curr = *head_ref, *prev = NULL;

    // Search for node to delete
    while (curr->data != key) {
        if (curr->next == *head_ref) { 
            printf("Node with value %d not found.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // If node is the only node in list
    if (curr->next == curr) {
        *head_ref = NULL;
        free(curr);
        printf("Node with value %d deleted; list is now empty.\n", key);
        return;
    }

    // If node to delete is head node
    if (curr == *head_ref) {
        prev = *head_ref;
        while (prev->next != *head_ref)
            prev = prev->next;
        *head_ref = curr->next;
        prev->next = *head_ref;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
    printf("Node with value %d deleted.\n", key);
}

// Function to display nodes in the list
void display(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Singly Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(back to head)\n");
}

void main() {
    struct Node* head = NULL;
    int choice, value;

    clrscr();
    while(1) {
        printf("\nCircular Singly Linked List Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
