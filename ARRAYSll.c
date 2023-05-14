#include <stdio.h>

#define MAX_SIZE 100

void createList(int list[], int* size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);

    printf("Enter the elements:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &list[i]);
    }

    printf("List created successfully!\n");
}

void displayList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void insertData(int list[], int* size, int position, int data) {
    if (*size == MAX_SIZE) {
        printf("List is full. Cannot insert data.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position. Cannot insert data.\n");
        return;
    }

    for (int i = position; i< *size; i++) {
        list[i] = list[i + 1];
    }

    list[position] = data;
    (*size)++;

    printf("Data %d inserted at position %d.\n", data, position);
}

void deleteData(int list[], int* size, int position) {
    if (*size == 0) {
        printf("List is empty. Cannot delete data.\n");
        return;
    }

    if (position < 0 || position >= *size) {
        printf("Invalid position. Cannot delete data.\n");
        return;
    }

    int data = list[position];

    for (int i = position; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }

    (*size)--;

    printf("Data %d deleted from position %d.\n", data, position);
}

int searchData(int list[], int size, int data) {
    for (int i = 0; i < size; i++) {
        if (list[i] == data) {
            return i;
        }
    }
    return -1;
}

int main() {
    int list[MAX_SIZE];
    int size = 0;

    int choice, position, data;

    while (1) {
        printf("\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert Data\n");
        printf("4. Delete Data\n");
        printf("5. Search Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                createList(list, &size);
                break;
            case 2:
                displayList(list, size);
                break;
            case 3:
                printf("Enter the position to insert data: ");
                scanf("%d", &position);
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertData(list, &size, position, data);
                break;
            case 4:
                printf("Enter the position to delete data: ");
                scanf("%d", &position);
                deleteData(list, &size, position);
                break;
            case 5:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                position = searchData(list, size, data);
               
                if (position == -1) {
                    printf("Data %d not found in the list.\n", data);
                } else {
                    printf("Data %d found at position %d.\n", data, position);
                }
                break;

        }}}





