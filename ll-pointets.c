#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* insertData(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    printf("Data %d inserted successfully.\n", data);

    return head;
}

struct Node* deleteData(struct Node* head, int data) {
    if (head == NULL) {
        printf("Linked list is empty. Cannot delete data.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Data %d not found in the linked list.\n", data);
        return head;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Data %d deleted successfully.\n", data);

    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n");
        printf("1. Insert Data\n");
        printf("2. Delete Data\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insertData(head, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                head = deleteData(head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}