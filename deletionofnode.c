#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void deletenode(struct node** head , int key)
{
    struct node* temp = *head;
    struct node* prev= *head;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp ==NULL )
    {
        printf("\n%d is  not present.", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
node* createlinkedlist(int n);
void displaylist(node* head);

void displaylist(node* head) {
    node* p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    int n = 0;
    node* head = NULL;
    printf("how many nodes: ");
    scanf("%d", &n);
    head = createlinkedlist(n);
    displaylist(head);
    deletenode(&head , 1);
    return 0;
}

node* createlinkedlist(int n) {
    int i = 0;
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;
    for (i = 0; i < n; i++) {
        temp = (node*)malloc(sizeof(node));
        printf("enter the data for node %d: ", i + 1);
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    return head;
}
