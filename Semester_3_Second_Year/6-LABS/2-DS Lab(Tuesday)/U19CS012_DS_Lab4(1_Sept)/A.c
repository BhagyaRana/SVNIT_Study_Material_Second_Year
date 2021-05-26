// Create an array to store the student information (ex. Student code, Name, Address, Mobile, Total mark, CGPA)
// Perform following operations:
// (1) Insert
// (2) Delete
// (3) Search
// (4) Traverse
// (5) Update the element at particular position given by the user.
#include <stdio.h>
#include <string.h>

// Declaring a structure class
struct student
{
    int s_code;
    char s_name[100];
    char s_address[10000];
    int s_mark;
    float s_cgpa;
};

struct student stud[101]; // Array of Student Structure
int i, j;
int idx = 0; // Takes Care of Number of Element Inserted

// Common Function for Printing Data
void print_data(int id)
{
    printf("\nStudent Data\n");

    printf("Student Code    : %d\n", stud[id].s_code);
    printf("Student Name    : %s", stud[id].s_name);
    printf("Student Address : %s", stud[id].s_address);
    printf("Student Mark    : %d\n", stud[id].s_mark);
    printf("Student CGPA    : %f\n", stud[id].s_cgpa);
}

// 1. Insertation of Student Data
void fx1()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Inserted :\n");
    scanf("%d", &cnt);
    fflush(stdin); // for another input
    int choice;
    printf("Would you Like to Insert by Position(1 -> yes && 0 -> no)?");
    scanf("%d", &choice);
    // INSERTION LOGIC ADDED
    // BASED ON USER CHOICE
    if (!choice)
    {
        for (int i = 1; i <= cnt; i++)
        {
            if (idx == 100)
            {
                printf("No More Student Data can be Entered!\n");
            }
            else
            {
                printf("Enter Student %d Details :\n", i);
                printf("Student Code :\n");
                scanf("%d", &stud[idx].s_code);
                fflush(stdin);
                printf("Student Name :\n");
                fgets(stud[idx].s_name, sizeof(stud[idx].s_name), stdin);
                printf("Student Address :\n");
                fflush(stdin);
                fgets(stud[idx].s_address, sizeof(stud[idx].s_address), stdin);
                fflush(stdin);
                printf("Student Mark [1-100] :\n");
                scanf("%d", &stud[idx].s_mark);
                printf("Student CGPA [1-10] :\n");
                scanf("%f", &stud[idx].s_cgpa);
                idx += 1;
            }
        }
    }
    else
    {
        for (int i = 1; i <= cnt; i++)
        {
            if (idx == 100)
            {
                printf("No More Student Data can be Entered!\n");
            }
            else
            {
                int pos;
                printf("Enter the Position where Student %d Data Needs to Be Inserted :\n", i);
                scanf("%d", &pos);

                if (pos - 1 >= 0 && pos - 1 <= idx)
                {
                    // Shift all Elements(right of pos) to right
                    for (int k = idx + 1; k >= pos; k--)
                    {
                        stud[k].s_code = stud[k - 1].s_code;
                        strcpy(stud[k].s_name, stud[k - 1].s_name);
                        strcpy(stud[k].s_address, stud[k - 1].s_address);
                        stud[k].s_mark = stud[k - 1].s_mark;
                        stud[k].s_cgpa = stud[k - 1].s_cgpa;
                    }
                    // space made for new data

                    printf("Enter Student %d Details :\n", i);
                    printf("Student Code :\n");
                    scanf("%d", &stud[pos - 1].s_code);
                    fflush(stdin);
                    printf("Student Name :\n");
                    fgets(stud[pos - 1].s_name, sizeof(stud[pos - 1].s_name), stdin);
                    printf("Student Address :\n");
                    fflush(stdin);
                    fgets(stud[pos - 1].s_address, sizeof(stud[pos - 1].s_address), stdin);
                    fflush(stdin);
                    printf("Student Mark [1-100] :\n");
                    scanf("%d", &stud[pos - 1].s_mark);
                    printf("Student CGPA [1-10] :\n");
                    scanf("%f", &stud[pos - 1].s_cgpa);
                    idx += 1;
                }
                else
                {
                    printf("Enter Valid Position!\n");
                }
            }
        }
    }

    return;
}

// 2. Deletion of Student Data
void fx2()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Deleted :\n");
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        int rno;
        printf("Enter the Roll Number of Student :\n");
        scanf("%d", &rno);
        int found = 0;
        for (j = 0; j < idx; j++)
        {
            if (stud[j].s_code == rno)
            {
                stud[j].s_code = -1;
                // SHIFTING LOGIC ADDED
                for (int k = idx - 2; k >= j; k--)
                {
                    stud[k].s_code = stud[k + 1].s_code;
                    strcpy(stud[k].s_name, stud[k + 1].s_name);
                    strcpy(stud[k].s_address, stud[k + 1].s_address);
                    stud[k].s_mark = stud[k + 1].s_mark;
                    stud[k].s_cgpa = stud[k + 1].s_cgpa;
                }
                stud[idx - 1].s_code = -1;
                idx -= 1; // Decrease Size by 1 Element
                printf("Student Data Deleted Succesfully!\n");
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("Student Data Does not Exist!\n");
            printf("Either Data not Inserted by Admin or Deleted!\n");
        }
    }
    return;
}

//3. Search of Student Data
void fx3()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Searched :\n");
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        int rno;
        printf("Enter the Roll Number of Student :\n");
        scanf("%d", &rno);
        int found = 0;
        for (int j = 0; j < idx; j++)
        {
            if (stud[j].s_code == rno)
            {
                printf("Student Found!\n");
                print_data(j);
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("Student Data Does not Exist!\n");
            printf("Either Data not Inserted by Admin or Deleted!\n");
        }
    }
    return;
}

//4.Traverse of Student Data
void fx4()
{
    for (int k = 0; k < idx; k++)
    {
        if (stud[k].s_code != -1)
        {
            print_data(k);
        }
    }
    return;
}

//5. Update the element at particular Roll Number given by the user.
void fx5()
{
    int cnt = 0;
    printf("Enter the Number of Students whose Data is to be Updated :\n");
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        int rno;
        printf("Enter the Roll Number of Student :\n");
        scanf("%d", &rno);
        int found = 0;
        for (int j = 0; j < idx; j++)
        {
            if (stud[j].s_code == rno)
            {
                printf("Enter Student Details :\n", i);
                printf("Student Code :\n");
                scanf("%d", &stud[j].s_code);
                fflush(stdin);
                printf("Student Name :\n");
                fgets(stud[j].s_name, sizeof(stud[j].s_name), stdin);
                printf("Student Address :\n");
                fflush(stdin);
                fgets(stud[j].s_address, sizeof(stud[j].s_address), stdin);
                fflush(stdin);
                printf("Student Mark [1-100] :\n");
                scanf("%d", &stud[j].s_mark);
                printf("Student CGPA [1-10] :\n");
                scanf("%f", &stud[j].s_cgpa);
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            printf("Student Data Does not Exist in DataBase!\n");
            printf("Enter Student Details Again :\n");
            printf("Student Code :\n");
            scanf("%d", &stud[idx].s_code);
            fflush(stdin);
            printf("Student Name :\n");
            fgets(stud[idx].s_name, sizeof(stud[idx].s_name), stdin);
            printf("Student Address :\n");
            fflush(stdin);
            fgets(stud[idx].s_address, sizeof(stud[idx].s_address), stdin);
            fflush(stdin);
            printf("Student Mark [1-100] :\n");
            scanf("%d", &stud[idx].s_mark);
            printf("Student CGPA [1-10] :\n");
            scanf("%f", &stud[idx].s_cgpa);
            idx += 1;
        }
    }
    return;
}

int main()
{
    // Marks of Student Not Initialized = -1
    for (int i = 0; i <= 100; i++)
    {
        stud[i].s_code = -1;
    }

    int choice = 0;
    printf("Perform following operations:\n");
    printf("1 -> Insert\n");
    printf("2 -> Delete\n");
    printf("3 -> Search\n");
    printf("4 -> Traverse\n");
    printf("5 -> Update the element at particular Roll Number\n");

    char ch = 'Y';
    while (ch == 'Y' || ch == 'y')
    {
        int choice = 0;

        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            fx1();
            break;
        case 2:
            fx2();
            break;
        case 3:
            fx3();
            break;
        case 4:
            fx4();
            break;
        case 5:
            fx5();
            break;
        default:
            printf("Enter Valid Choice [1-5] Only!");
            break;
        }
        fflush(stdin); // for character input

        printf("Want to Do Another Operation?(Y/N)\n");
        scanf("%c", &ch);
    }

    return 0;
}