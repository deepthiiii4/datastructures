#include <stdio.h>
#include <stdlib.h>

#define MIN(A, B) (A <= B? A : B)

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
}*newNode, *prev, *curr1, *startp1, *startp2, *startr, *curr2;

void insertp1(int coeff, int exp, int pos) {
    int count = 1;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;

    if (pos == 1) {
        if (startp1 == NULL) {
            startp1 = newNode;
        }
        else {
            newNode->next = startp1;
            startp1 = newNode;
        }
    }
    else {
        curr1 = startp1;
        prev = NULL;
        while (count != pos) {
            prev = curr1;
            curr1 = curr1->next;
            count++;
        }
        prev->next = newNode;
        newNode->next = curr1;
    }
}

void insertp2(int coeff, int exp, int pos) {
    int count = 1;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;

    if (pos == 1) {
        if (startp2 == NULL) {
            startp2 = newNode;
        }
        else {
            newNode->next = startp2;
            startp2 = newNode;
        }
    }
    else {
        curr2 = startp2;
        prev = NULL;
        while (count != pos) {
            prev = curr2;
            curr2 = curr2->next;
            count++;
        }
        prev->next = newNode;
        newNode->next = curr2;
    }
}
void displayp1() {
    printf("(%d)", startp1->coefficient, startp1->exponent);
    curr1 = startp1->next;
    while (curr1 != NULL) {
        printf(" + (%d)x^%d", curr1->coefficient, curr1->exponent);
        curr1 = curr1->next;
    }
}

void displayp2() {
    printf("(%d)", startp2->coefficient, startp2->exponent);
    curr2 = startp2->next;
    while (curr2 != NULL) {
        printf(" + (%d)x^%d", curr2->coefficient, curr2->exponent);
        curr2 = curr2->next;
    }
}

int main() {
    int d1, d2, k1, k2;
    printf("\n-------- f(x) -------- \n");
    printf("Enter degree of f(x): ");
    scanf("%d", &d1);
    printf("Enter constant term: ");
    scanf("%d", &k1);
    insertp1(k1, 0, 1);
    for (int i = 1; i <= d1; i++) {
        int coeff;
        printf("Enter coefficient of x^%d term: ", i);
        scanf("%d", &coeff);
        insertp1(coeff, i, i + 1);
    }
    printf("\n-------- g(x) -------- \n");
    printf("Enter degree of g(x): ");
    scanf("%d", &d2);
    printf("Enter constant term: ");
    scanf("%d", &k2);
    insertp2(k2, 0, 1);
    for (int i = 1; i <= d2; i++) {
        int coeff;
        printf("Enter coefficient of x^%d term: ", i);
        scanf("%d", &coeff);
        insertp2(coeff, i, i + 1);
    }
    printf("----------------------");
    printf("\nThe entered polynomials are: ");
    printf("\nf(x)         = ");
    displayp1();
    printf("\ng(x)         = ");
    displayp2();
    int dr = MIN(d1, d2);
    if (dr == d1) {
        curr1 = startp1;
        curr2 = startp2;
        while (curr1 != NULL) {
            curr2->coefficient += curr1->coefficient;
            curr2 = curr2->next;
            curr1 = curr1->next;
        }
        printf("\nThe result --------");
        printf("\nf(x) + g(x) = ");
        displayp2();
    }
    else {
        curr1 = startp1;
        curr2 = startp2;
        while (curr2 != NULL) {
            curr1->coefficient += curr2->coefficient;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        printf("\n     --------------");
        printf("\nf(x) + g(x) = ");
        displayp1();
    }
    return 0;
    
}
