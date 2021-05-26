// Write a program to implement a stack and perform basic operations of stack.
// 1) push
// 2) pop
// 3) peek
// 4) isfull
// 5) isempty
// 6.) To Display whole Stack

#include <stdio.h>

#define MAX 1000 //Maximum number of elements that can be stored

int top = -1, stack[MAX];

int isfull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push()
{
    int val;

    if (isfull())
    {
        printf("\nStack is Full!\n");
    }
    else
    {
        printf("\nEnter element to push : ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (isempty())
    {
        printf("\nStack is Empty!\n");
    }
    else
    {
        printf("\nDeleted element is %d\n", stack[top]);
        top = top - 1;
    }
}

void peek()
{
    if (isempty())
    {
        printf("\nStack is Empty!\n");
    }
    else
    {
        printf("\nStack Top : %d\n", stack[top]);
    }
}

void display()
{
    int i;

    if (isempty())
    {
        printf("\nStack is Empty!\n");
    }
    else
    {
        printf("\nStack :\n");
        for (i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;
    printf("\nStack Operation\n");
    printf("1 - > Push\n");
    printf("2 - > Pop\n");
    printf("3 - > Peek Top\n");
    printf("4 - > Check Stack is Full\n");
    printf("5 - > Check Stack is Empty\n");
    printf("6 - > Display Whole Stack\n");
    printf("7 - > Exit\n");

    while (1) //infinite loop, will end when choice will be 7
    {
        printf("\nEnter your choice [1-7] : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isfull())
                printf("\nStack is Full!\n");
            else
                printf("\nStack is Not Full!\n");
            break;
        case 5:
            if (isempty())
                printf("\nStack is Empty!\n");
            else
                printf("\nStack is Not Empty!\n");
            break;
        case 6:
            display();
            break;
        case 7:
            return 0;

        default:
            printf("\nWrong Choice Entered!");
        }
    }

    return 0;
}
