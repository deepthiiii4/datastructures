#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Check if the queue is empty
int isEmpty(struct Node* front) {
    return front == NULL;
}

// Enqueue operation
struct Node* enqueue(struct Node* front, int item) {
    struct Node* newNode = createNode(item);

    if (isEmpty(front)) {
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Enqueued: %d\n", item);

    // Return the updated front
    return front;
}

// Dequeue operation
struct Node* dequeue(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return front;
    }

    struct Node* temp = front;
    int item = temp->data;

    front = front->next;
    free(temp);

    printf("Dequeued: %d\n", item);

    // Return the updated front
    return front;
}

// Display the queue
void display(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    struct Node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Clear the queue
struct Node* clear(struct Node* front) {
    while (!isEmpty(front)) {
        front = dequeue(front);
    }

    // Return the updated front
    return front;
}

int main() {
    struct Node* front = NULL;

    front = enqueue(front, 1);
    front = enqueue(front, 2);
    front = enqueue(front, 3);
    display(front);

    front = dequeue(front);
    display(front);

    return 0;
}