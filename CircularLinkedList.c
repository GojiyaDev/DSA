# Circular Linked List in C Language
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *current = *head, *previous = NULL;

    // If the head node itself holds the key
    if (current->data == key) {
        if (current->next == *head) {
            free(current);
            *head = NULL;
        } else {
            while (current->next != *head) {
                current = current->next;
            }
            current->next = (*head)->next;
            free(*head);
            *head = current->next;
        }
        return;
    }

    // Find the node to be deleted
    while (current->next != *head && current->data != key) {
        previous = current;
        current = current->next;
    }

    if (current->data == key) {
        previous->next = current->next;
        free(current);
    } else {
        printf("Node with data %d not found\n", key);
    }
}

// Main function to test the circular linked list
int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Circular Linked List:\n");
    displayList(head);

    // Delete a node from the circular linked list
    deleteNode(&head, 20);

    printf("After deleting 20:\n");
    displayList(head);

    return 0;
}
