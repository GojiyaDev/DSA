#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;            
    struct Node* next;   
} Node;

// Function to create the linked list
Node* createList() {
    int n, k, element;
    Node *head = NULL, *p = NULL;

    printf("\nHow many elements to enter? ");
    scanf("%d", &n);

    for (k = 0; k < n; k++) {
        if (k == 0) {
            head = (Node*)malloc(sizeof(Node));
            p = head;
        } else {
            p->next = (Node*)malloc(sizeof(Node));
            p = p->next;
        }

        printf("Enter element %d: ", k + 1);
        scanf("%d", &element);
        p->data = element;  
        p->next = NULL;     
    }

    return head;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* p = head;
    printf("\nLinked List Elements:\n");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to insert a node before a given index
Node* insertBeforeIndex(Node* head, int index, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        Node* previous = NULL;
        int currentIndex = 0;

        while (current != NULL && currentIndex < index) {
            previous = current;
            current = current->next;
            currentIndex++;
        }

        if (currentIndex == index) {
            previous->next = newNode;
            newNode->next = current;
        } else {
            printf("Index out of bounds. Unable to insert.\n");
            free(newNode);
        }
    }

    return head;
}

// Main function
int main() {
    Node* head = createList();
    displayList(head);

    int index, data;

    printf("\nEnter the index before which to insert: ");
    scanf("%d", &index);
    printf("Enter the element to insert: ");
    scanf("%d", &data);

    head = insertBeforeIndex(head, index, data);
    displayList(head);

    // Free the allocated memory
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
