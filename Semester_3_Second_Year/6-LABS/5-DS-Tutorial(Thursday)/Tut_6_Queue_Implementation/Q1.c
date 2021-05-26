// Write a program to implement a queue and perform basic operations of queue using array.
// •	En(enter)queue
// •	De(lete)queue
// •	peek
// •	isfull
// •	isempty
// •    size
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function Declarations
void enqueue();
void dequeue();

//Supportive Operations
int peek();
int isFull();
int isEmpty();
int Size();
void display();

int Queue[MAX];

//Initially Front and Rear Location is -1
int front = -1;
int rear = -1;

int main()
{
    // Menu Driven C Program for Queue implementation Using Array
    printf("\n~~~~~~Queue Operations~~~~~~\n");

    printf("1 -> Enter Element in Queue\n");
    printf("2 -> Delete Element from Queue\n");
    printf("3 -> Peek[Front] Element of Queue\n");
    printf("4 -> Check if Queue is Full or Not?\n");
    printf("5 -> Check if Queue is Empty or Not?\n");
    printf("6 -> Get the Size of Queue\n");
    printf("7 -> Display all Elements of Queue\n");
    printf("8 -> Quit\n");

    int ch;
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:;
            int peek_ele = peek();
            printf("The Front[Peek] Element of Queue is : %d\n", peek_ele);
            break;
        case 4:
            if (isFull())
            {
                printf("Queue is Full!\n");
            }
            else
            {
                printf("Queue is Not Full!\n");
            }
            break;
        case 5:
            if (isEmpty())
            {
                printf("Queue is Empty!\n");
            }
            else
            {
                printf("Queue is Not Empty!\n");
            }
            break;
        case 6:;
            int sz;
            sz = Size();
            printf("Size of Queue : %d\n", sz);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(1);
        default:
            printf("Enter Valid Choice!\n");
        }
    }
}

// Function Definations

int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    return Queue[front];
}

void enqueue()
{
    if (isFull())
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;

        int ele;
        printf("Enter the Element to Insert in Queue : ");
        scanf("%d", &ele);

        rear = rear + 1;   // Increment Rear
        Queue[rear] = ele; // Assign Value at Back
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return;
    }
    else
    {
        printf("Element Deleted from Queue is : %d\n", Queue[front]);
        front = front + 1;
    }
}

int Size()
{
    if (isEmpty())
    {
        printf("Queue is Empty!\n");
        return 0;
    }
    else
    {
        return rear - front + 1;
    }
}

void display()
{
    if (isEmpty())
        printf("Queue is Empty!\n");
    else
    {
        int i;

        printf("Queue is :\n");

        for (i = front; i < rear; i++)
            printf("%d -> ", Queue[i]);

        // Rear Element
        printf("%d\n", Queue[i]);
    }
}