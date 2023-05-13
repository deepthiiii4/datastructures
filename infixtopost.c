#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

char infix[MAX], postfix[MAX];
int stack[MAX], top = -1;

void intopost();
int precedence(char);
int space(char);
void push(char);
char pop();
int isempty();
int post_eval();
void print();

int main()
{
    int result;
    printf("Enter the infix expression: ");
    gets(infix);

    intopost();
    result = post_eval();
    print();
    printf("The result: %d\n", result);
    return 0;
}

void intopost()
{
    int i, j = 0;
    char next;
    char symbol;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (!space(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                push(symbol);
                while ((next = pop()) != '(')
                    postfix[j++] = next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isempty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
            }
        }
    }
    while (!isempty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int space(char c)
{
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void print()
{
    int i = 0;
    printf("The postfix expression is: ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void push(char val)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = val;
}

char pop()
{
    char val;
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }

    val = stack[top];
    top = top - 1;
    return val;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int post_eval()
{
    int i;
    int a, b;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a);
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(pow(b, a));
                break;
            }
        }
    }

    return pop();
}






