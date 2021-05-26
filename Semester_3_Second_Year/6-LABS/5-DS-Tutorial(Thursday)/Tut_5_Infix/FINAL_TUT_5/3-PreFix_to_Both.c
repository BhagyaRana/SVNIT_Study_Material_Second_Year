#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BLANK ' '
#define TAB '\t'

void PreFix_To_InFix(char prefix_exp[], char infix_exp[]);

#define MAX 100
char stack2[MAX];
int top2;

int is_operator(char symbol);
void push2(char c);
char pop2();

void PreFix_To_PostFix(char prefix[], char postfix[]);

#define SIZE 100
char stack[SIZE][SIZE];
int top;

void push(char *str);
char *pop();
int isempty();
int white_space(char symbol);

int main()
{
    char infix[SIZE], postfix[SIZE], prefix[SIZE];

    int cnt = 0;
    printf("Enter the Number of PreFix Expression to Convert to PostFix & Infix Expression :\n");
    scanf("%d", &cnt);
    fflush(stdin);

    while (cnt--)
    {
        top = -1;
        printf("Enter Valid PreFix Expression : ");
        gets(prefix);

        PreFix_To_PostFix(prefix, postfix);
        printf("PostFix Expression : ");
        puts(postfix);

        top2 = -1;
        PreFix_To_InFix(prefix, infix);
        printf("Infix Expression   : ");
        puts(infix);
        printf("\n");
    }
}

void PreFix_To_PostFix(char prefix[], char postfix[])
{
    int i;
    char operand1[SIZE], operand2[SIZE];
    char symbol;
    char temp[2];
    char strin[SIZE];

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        symbol = prefix[i];
        temp[0] = symbol;
        temp[1] = '\0';

        if (!white_space(symbol))
        {
            switch (symbol)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                // string = operand1 + operand2 + operator
                strcpy(operand1, pop());
                strcpy(operand2, pop());
                strcpy(strin, operand1);
                strcat(strin, operand2);
                strcat(strin, temp);
                //push the string in Stack
                push(strin);
                break;
            // Operand should be pushed in Stack
            default:
                push(temp);
            }
        }
    }
    // printf("\nPostfix Expression :: ");
    // puts(stack[0]);
    strcpy(postfix, stack[0]);
}

void push(char *str)
{
    if (top > SIZE)
    {
        printf("\nStack Overflow!\n");
        exit(1);
    }
    else
    {
        top = top + 1;
        strcpy(stack[top], str);
    }
}

char *pop()
{
    if (top == -1)
    {
        printf("\nStack UnderFlow!Invalid Prefix Expression!\n");
        exit(2);
    }
    else
        return (stack[top--]);
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int white_space(char symbol)
{
    if (symbol == BLANK || symbol == TAB || symbol == '\0')
        return 1;
    else
        return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~PREFIX TO INFIX~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void PreFix_To_InFix(char prefix_exp[], char infix_exp[])
{
    char str[MAX];

    strcpy(str, prefix_exp);

    int i, j = 0;
    char a, b, op;

    int n = strlen(str);

    for (i = 0; i < MAX; i++)
        stack2[i] = '\0';

    for (i = 0; i < n; i++)
    {
        if (is_operator(str[i]))
        {
            push2(str[i]);
        }
        else
        {
            op = pop2();
            a = str[i];
            infix_exp[j] = a;
            j++;
            infix_exp[j] = op;
            j++;
        }
    }

    infix_exp[j] = str[top--];
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push2(char c)
{
    stack2[++top2] = c;
}

char pop2()
{
    return stack2[top2--];
}