#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
void displaylist(node* head);

void displaylist(node* head) {
    node* p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
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
void insertatend(struct node** head, int new_data)
{
    printf("enter the data you want to add at the end: ");
    scanf("%d" , &new_data);
    struct node* new_node= (struct node*)malloc(sizeof(struct node));
    struct node* last = *head;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    while(last->next != NULL)
    
      last = last->next;
      last->next = new_node;

    return;
}
void insteratbeginning(struct node** head , int new_data) {
    printf("enter the element you want to add at the start: ");
    scanf("%d" , &new_data);
    struct node* new_node =(struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next =(*head);
    (*head)  = new_node;
    return;
}

void insertAtMiddle(struct node** head, int new_data, int position) {
    printf("enter the position: ");
    scanf("%d", &position);
    printf("enter the data: ");
    scanf("%d" , &new_data);
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;
    int i;

    new_node->data = new_data;

    for (i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("\n%d is an invalid position.\n", position);
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}
int main() 
{
    int n = 0;
    node* head = NULL;
    printf("how many nodes: ");
    scanf("%d", &n);
    head = createlinkedlist(n);
    insertAtMiddle(&head, 3 , 33);
    displaylist(head);
    return 0;
}
