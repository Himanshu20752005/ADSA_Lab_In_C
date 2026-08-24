#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int priority(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    char opstack[100];
    int optop = -1;
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isdigit(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            opstack[++optop] = ch;
        }
        else if (ch == ')')
        {
            while (opstack[optop] != '(')
                postfix[j++] = opstack[optop--];

            optop--;
        }
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/')
        {
            while (optop != -1 &&
                   opstack[optop] != '(' &&
                   priority(opstack[optop]) >= priority(ch))
            {
                postfix[j++] = opstack[optop--];
            }

            opstack[++optop] = ch;
        }
    }

    while (optop != -1)
        postfix[j++] = opstack[optop--];

    postfix[j] = '\0';
}

int evaluate(char postfix[])
{
    int i;
    int a, b;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            if (postfix[i] == '+')
                push(a + b);
            else if (postfix[i] == '-')
                push(a - b);
            else if (postfix[i] == '*')
                push(a * b);
            else if (postfix[i] == '/')
                push(a / b);
        }
    }

    return pop();
}

int main(int argc, char *argv[])
{
    char postfix[100];

    if (argc < 2)
    {
        printf("Enter expression as command line argument\n");
        return 1;
    }

    infixToPostfix(argv[1], postfix);

    printf("%d\n", evaluate(postfix));

    return 0;
}