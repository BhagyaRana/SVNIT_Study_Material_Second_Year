#include <stdio.h>
#include <stdlib.h>

/*
Structure Of 4-Directional Node
          up
prev <- [DATA] -> next
         down
*/

struct node
{
    int data;
    struct node *up;
    struct node *down;
    struct node *next;
    struct node *prev;
};

#define MAXROW 10000
#define MAXCOL 10000

int mat[MAXROW][MAXCOL];

// head Pointer -> head of Linked List
struct node *head = NULL;

// Creation of the 2-D Doubly Linked List
struct node *CREATE_2D_LL(int i, int j, int row, int col, struct node *curr_node);
// Display of the 2-D Doubly Linked List
void DISPLAY_2D_LL(struct node *head);

int main()
{
    // Number of Rows
    int row;
    // Number of Columns
    int col;

    printf("Enter the Number of Rows in Matrix : ");
    scanf("%d", &row);
    printf("Enter the Number of Columns in Matrix : ");
    scanf("%d", &col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    head = CREATE_2D_LL(0, 0, row, col, NULL);

    DISPLAY_2D_LL(head);

    return 0;
}

// Creation of the 2-D Doubly Linked List
struct node *CREATE_2D_LL(int i, int j, int row, int col, struct node *curr_node)
{
    // Base Case
    if (i >= row || j >= col)
    {
        return NULL;
    }

    // Create A Temporary Node
    struct node *temp_node;
    temp_node = (struct node *)malloc(sizeof(struct node));

    // Assign the Value in the Node
    temp_node->data = mat[i][j];

    // Intialise the Prev & Up Pointer of node to Current
    // Since temp_node is Linked to Current Pointer
    temp_node->prev = curr_node;
    temp_node->up = curr_node;

    // Recursive Step to Link the Left Sided Node with Current Node
    temp_node->next = CREATE_2D_LL(i, j + 1, row, col, temp_node);
    // Recursive Step to Link the Down Sided Node with Current Node
    temp_node->down = CREATE_2D_LL(i + 1, j, row, col, temp_node);

    // Return the temp_node with all its 4 Links Complete
    return temp_node;
}

// Display of the 2-D Doubly Linked List
void DISPLAY_2D_LL(struct node *head)
{
    // pointer to move right
    struct node *rPtr;

    // pointer to move down
    struct node *dPtr = head;

    rPtr = head;
    {
        printf("         ");
        while (rPtr != NULL)
        {
            printf("NULL  ");
            rPtr = rPtr->next;
        }
    }
    printf("\n");

    rPtr = head;
    // loop till struct node->right is not NULL
    printf("         ");
    while (rPtr != NULL)
    {
        printf("^     ");
        rPtr = rPtr->next;
    }
    printf("\n");

    rPtr = head;
    // loop till struct node->right is not NULL
    printf("         ");
    while (rPtr != NULL)
    {
        printf("|     ");
        rPtr = rPtr->next;
    }
    printf("\n");

    rPtr = head;
    // loop till struct node->right is not NULL
    printf("         ");
    while (rPtr != NULL)
    {
        printf("v     ");
        rPtr = rPtr->next;
    }
    printf("\n");

    int cnt = 0;
    // loop till struct node->down is not NULL
    while (dPtr != NULL)
    {

        rPtr = dPtr;
        // loop till struct node->right is not NULL
        printf("NULL <-> ");
        while (rPtr != NULL)
        {
            printf("%d <-> ", rPtr->data);
            rPtr = rPtr->next;
        }
        printf("NULL\n");

        rPtr = dPtr;
        // loop till struct node->right is not NULL
        printf("         ");
        while (rPtr != NULL)
        {
            printf("^     ");
            rPtr = rPtr->next;
        }
        printf("\n");

        rPtr = dPtr;
        // loop till struct node->right is not NULL
        printf("         ");
        while (rPtr != NULL)
        {
            printf("|     ");
            rPtr = rPtr->next;
        }
        printf("\n");

        rPtr = dPtr;
        // loop till struct node->right is not NULL
        printf("         ");
        while (rPtr != NULL)
        {
            printf("v     ");
            rPtr = rPtr->next;
        }
        printf("\n");

        dPtr = dPtr->down;
    }
    rPtr = head;
    {
        printf("         ");
        while (rPtr != NULL)
        {
            printf("NULL  ");
            rPtr = rPtr->next;
        }
    }
}