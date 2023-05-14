#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear++;
    queue[rear] = item;

    printf("Enqueued: %d\n", item);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }

    printf("Dequeued: %d\n", item);
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for(int i=front; i<rear+1; i++)

    {
    printf("%d\n", queue[i]);
}}

void peek()
{
    if(isEmpty())
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d\n", queue[front]);
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    peek();

    int dequeued = dequeue();
    printf("Dequeued item: %d\n", dequeued);
    display();

    enqueue(4);
    enqueue(5);
    display();

    return 0;
}