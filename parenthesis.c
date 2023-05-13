#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int top = -1;
char stack[MAX];
void push(char);
char pop();
int isempty();
int isfull();
int check_balanced(char*);
int match_char(char, char);

int main()
{
    char expr[MAX];
    int balanced;
    printf(" enter the algebric expression: ");
    gets(expr);

    balanced = check_balanced(expr);
    if(balanced == 1)
    printf("the expression is valid");
    else
    printf("invalid");
    return 0;

}

int check_balanced(char* s)
{
    char temp;
    int i;
    for(i=0; i<strlen(s); i++)
    {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
        push(s[i]);

        if(s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if(isempty())
            {
                printf("right brwackets are more than left");
                return 0;
            }
            else{
                temp = pop();
                if(!match_char(temp, s[i]))
                {
                    printf("mismaatched brackets");
                    return 0;
                }
            }
        }
    }

    if(isempty())
    {
        printf("brackets are well balanced");
        return 1;
    }
    else {
        printf("left brackets are more than right");\
        return 0;
    }
}

void push(char c)
{
    if(isfull())
    {
        printf("stack overflow");
        exit(1);
    }
    top++;
    stack[top] = c;
}
 char pop()
 {char c;
    if(isempty())
    {
        printf("stack underflow");
        exit(1);
    }
 }
 int isempty()
 {
    if(top == -1)
     return 1;
     else 
     return 0;
 }
 
 int isfull()
 {
    if(top == MAX-1)
    return 1;
    else
    return 0;
 }

 int match_char(char a, char b)
 {
    if( a =='[' && b==']')
    return 1;
    if (a == '{' && b=='}')
    return 1;
    if( a=='(' && b==')')
    return 1;
 }


