#include <stdio.h> // FILE
#include <stdlib.h>
#include <string.h>

#include <bits/stdc++.h>
#include <map>
#include <string>

using namespace std;

// BASIC STRUCTURE OF PATIENT

struct Date
{
    int date;
    int month;
    int year;
};

struct Patient
{
    int pno;
    char first_name[30];
    char last_name[30];
    int age;
    char gender;
    struct Date admission_date;
    struct Date discharge_date;
    char area[50];
};

// Global File Pointer
FILE *fp;
// Global Counter for Number of Records in Database
int record_count = 0;

// 1 - Add Record in File
void add();

// 2 - Deletion of Record in File
void del();

// 3 - Modify a Record in File
void modify();

// 4 - Generate Summary Report Based on Field
void summary();

// 5 - List Records in Ascending
void List_Ascending();

// 6 - List Records in Descending
// void List_Descending();

// 7 - List all Records of File for Specific Range
// void List_Range();

// 8 - Seperate Record Based on Gender
// void Split_by_Gender();

// 9 - To Display all The Records in File
void display();

int main()
{
    printf("~~ COVID PATIENT DATA [SURAT] ~~\n");

    while (1)
    {
        int ch;
        printf("1 -> Add a Record of Patient\n");
        printf("2 -> Delete a Record of Patient\n");
        printf("3 -> Modify a Record of Patient\n");
        printf("4 -> Generate Summary Report Based on Field\n");
        printf("5 -> List all Records in Ascending Order\n");
        printf("6 -> List all Records in Descending Order\n");
        printf("7 -> List all Records of File for Specific Range\n");
        printf("8 -> Seperate Record Based on Gender\n");
        printf("9 -> Display a Record of All Patients\n");
        printf("10 -> Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            modify();
            break;
        case 4:
            summary();
            break;
        case 5:
            List_Ascending();
            break;
        case 6:
            // List_Descending();
            break;
        case 7:
            // List_Range();
            break;
        case 8:
            // Split_by_Gender();
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Enter a Valid Choice!\n");
            break;
        }
    }

    return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ADD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Add Record in File
void add()
{
    // Append Mode [If Doesnt Exist, it will Create it]
    fp = fopen("Patient_Data.txt", "a+");

    printf("~~ENTER PATIENT DETAILS~~\n");

    struct Patient p;

    printf("Patients Number : \n");
    scanf("%d", &p.pno);
    printf("Patients First Name : \n");
    fflush(stdin);
    gets(p.first_name);
    printf("Patients Last Name : \n");
    fflush(stdin);
    gets(p.last_name);
    printf("Patients Age : \n");
    scanf("%d", &p.age);
    printf("Patients Gender [M(m)/F(f)] : \n");
    fflush(stdin);
    scanf("%c", &p.gender);
    printf("Patients Admission Date [DD/MM/YYYY] : \n");
    scanf("%d %d %d", &p.admission_date.date, &p.admission_date.month, &p.admission_date.year);
    printf("Patients Discharge Date [DD/MM/YYYY] :  \n");
    scanf("%d %d %d", &p.discharge_date.date, &p.discharge_date.month, &p.discharge_date.year);
    printf("Patient Area of Residence : \n");
    fflush(stdin);
    gets(p.area);
    // Increment the Record Count
    record_count += 1;

    fwrite(&p, sizeof(struct Patient), 1, fp);
    fclose(fp);

    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DELETE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Deletion of Record in File
void del()
{
    FILE *fp2;
    fp = fopen("Patient_Data.txt", "r+");
    fp2 = fopen("temp.txt", "a+");
    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        int id;
        printf("\nEnter the Patient Number to be deleted : ");
        scanf("%d", &id);
        struct Patient p;
        // Write all records to the tempfile, except the one(s) you want to delete.
        int found = 0;
        while (fread(&p, sizeof(struct Patient), 1, fp))
        {
            if (p.pno != id)
            {
                fwrite(&p, sizeof(struct Patient), 1, fp2);
            }
            else
            {
                found = 1;
            }
        }
        fclose(fp);
        fclose(fp2);
        // Remove the old file.
        remove("Patient_Data.txt");
        // Rename New File With Old File Name
        rename("temp.txt", "Patient_Data.txt");
        if (found == 1)
        {
            printf("\nRecord Deleted Succesfully!\n");
            record_count -= 1; // 1 Record Deleted
        }
        else
        {
            printf("\nRecord Not Found in DataBase![Already Deleted/Not Added]\n");
        }
    }

    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MODIFY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Modify a Record in File
void modify()
{
    FILE *fp2;

    fp = fopen("Patient_Data.txt", "r+");
    fp2 = fopen("temp.txt", "a+");

    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        // New Record
        struct Patient p1;
        printf("Patients Number to be Updated : \n");
        scanf("%d", &p1.pno);
        printf("New Patients First Name : \n");
        fflush(stdin);
        gets(p1.first_name);
        printf("New Patients Last Name : \n");
        fflush(stdin);
        gets(p1.last_name);
        printf("New Patients Age : \n");
        scanf("%d", &p1.age);
        printf("New Patients Gender [small case] : \n");
        fflush(stdin);
        scanf("%c", &p1.gender);
        printf("New Patients Admission Date [DD/MM/YYYY] : \n");
        scanf("%d %d %d", &p1.admission_date.date, &p1.admission_date.month, &p1.admission_date.year);
        printf("New Patients Discharge Date [DD/MM/YYYY] :  \n");
        scanf("%d %d %d", &p1.discharge_date.date, &p1.discharge_date.month, &p1.discharge_date.year);
        printf("New Patient Area of Residence : \n");
        fflush(stdin);
        gets(p1.area);

        // Temporary Structure to Hold Data
        struct Patient p2;
        int found = 0;
        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            if (p2.pno != p1.pno)
            {
                fwrite(&p2, sizeof(struct Patient), 1, fp2);
            }
            else
            {
                // Write the New Data inplace of Old One
                fwrite(&p1, sizeof(struct Patient), 1, fp2);
                found = 1;
            }
        }

        fclose(fp);
        fclose(fp2);

        // Remove the old file.
        remove("Patient_Data.txt");
        // Rename New File With Old File Name
        rename("temp.txt", "Patient_Data.txt");
        if (found == 1)
        {
            printf("\nRecord Modified Succesfully!\n");
        }
        else
        {
            printf("\nRecord Not Found in the DataBase!\n");
        }
    }
    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SUMMARY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void display_cnt()
{
    FILE *fp;
    fp = fopen("Patient_Data.txt", "r+");

    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        // struct Patient p2;
        // int cnt = 0;
        // while (fread(&p2, sizeof(struct Patient), 1, fp))
        // {
        //     cnt++;
        // }
        printf("\n~~ SUMMARY ~~\n\n");
        cout << "----------------------------" << endl;
        printf("Number of Patient's Record in DataBase = %d\n", record_count);
        cout << "----------------------------" << endl;
        fclose(fp);
        return;
    }
}

void display_cnt_gender()
{
    FILE *fp;
    fp = fopen("Patient_Data.txt", "r+");

    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        struct Patient p2;
        int male = 0;
        int female = 0;
        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            char ch = p2.gender;
            if (ch == 'm' || ch == 'M')
            {
                male += 1;
            }
            else
            {
                female += 1;
            }
        }
        printf("\n~~ SUMMARY ~~\n\n");
        cout << "----------------------------" << endl;
        printf("Number of Male Patient's Record in DataBase   = %d\n", male);
        printf("Number of Female Patient's Record in DataBase = %d\n", female);
        cout << "----------------------------" << endl;
        fclose(fp);
        return;
    }
}

void display_age()
{
    FILE *fp;
    fp = fopen("Patient_Data.txt", "r+");

    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        struct Patient p2;
        map<int, int> mp;
        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            mp[p2.age]++;
        }
        printf("\n~~ SUMMARY ~~\n\n");
        cout << "Age   |   Number of Patients" << endl;
        cout << "----------------------------" << endl;
        for (auto x : mp)
        {
            cout << x.first << "     " << x.second << endl;
        }
        cout << "----------------------------" << endl;
        fclose(fp);
        return;
    }
}

void display_area()
{
    FILE *fp;
    fp = fopen("Patient_Data.txt", "r+");

    if (fp == NULL)
    {
        printf("Unable to Open File!\n");
        fclose(fp);
        return;
    }
    else
    {
        struct Patient p2;
        map<string, int> mp;
        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            string s(p2.area);
            mp[s]++;
        }
        printf("\n~~ SUMMARY ~~\n\n");
        cout << "Area     |      Number of Patients" << endl;
        cout << "-----------------------------------" << endl;
        for (auto x : mp)
        {
            cout << x.first << "          " << x.second << endl;
        }
        cout << "-----------------------------------" << endl;
        fclose(fp);
        return;
    }
}

// 4 - Generate Summary Report Based on Field
void summary()
{
    cout << "~~ COVID PATIENT DATA SUMMARY [SURAT] ~~\n";
    cout << "----------------------------------------" << endl;
    while (1)
    {
        int ch;
        printf("1 -> Display Count of Patients\n");
        printf("2 -> Display the Count of Patient Based on the Gender\n");
        printf("3 -> Display the Age-Wise Count of Patients\n");
        printf("4 -> Display the Count of Patient AreaWise\n");
        printf("5 -> Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display_cnt();
            break;
        case 2:
            display_cnt_gender();
            break;
        case 3:
            display_age();
            break;
        case 4:
            display_area();
            break;
        case 5:
            return;
            break;
        default:
            printf("Enter a Valid Choice!\n");
            break;
        }
    }

    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ASCENDING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void asc_sort_fname(int choice)
{
    FILE *fp;
    fp = fopen("Patient_Data.txt", "r+");

    if (fp == NULL)
    {
        printf("Unable to Open File\n");
        fclose(fp);
        return;
    }
    else
    {
        int sz = record_count;
        struct Patient pat[sz], p2, temp;
        int i = 0;

        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            pat[i] = p2;
            i++;
        }

        //For Ascending order ch==1
        if (choice == 1)
        {
            // Bubble Sort
            for (int i = 1; i < record_count; i++)
                for (int j = 0; j < record_count - i; j++)
                {
                    if (strcmp(pat[j + 1].first_name, pat[j].first_name) < 0)
                    {
                        temp = pat[j];
                        pat[j] = pat[j + 1];
                        pat[j + 1] = temp;
                    }
                }
        }
        else //else Descending
        {
            for (int i = 1; i < record_count; i++)
            {
                for (int j = 0; j < record_count - i; j++)
                {
                    if (strcmp(pat[j + 1].first_name, pat[j].first_name) > 0)
                    {
                        temp = pat[j];
                        pat[j] = pat[j + 1];
                        pat[j + 1] = temp;
                    }
                }
            }
        }

        FILE *fp1;

        fp1 = fopen("Sorted_Data.txt", "a+");
        for (int i = 0; i < record_count; i++)
        {
            fwrite(&pat[i], sizeof(struct Patient), 1, fp1);
        }

        fclose(fp);
        fclose(fp1);

        remove("Patient_Data.txt");
        rename("Sorted_Data.txt", "Patient_Data.txt");

        cout << "SORTED based on FIRST NAME Successfully!" << endl;
        display();

        return;
    }

    return;
}

// 5 - List Records in Ascending
void List_Ascending()
{
    cout << "~~ COVID PATIENT ASCENDING SORT [SURAT] ~~\n";
    cout << "----------------------------------------" << endl;
    while (1)
    {
        int ch;
        printf("1 -> Sort Based on Patient's First name\n");
        printf("2 -> Sort Based on Patient's Last name\n");
        printf("3 -> Sort Based on Patient's Age\n");
        printf("4 -> Sort Based on Admission Date\n");
        printf("5 -> Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            asc_sort_fname(1);
            break;
        case 2:
            display_cnt_gender();
            break;
        case 3:
            display_age();
            break;
        case 4:
            display_area();
            break;
        case 5:
            return;
            break;
        default:
            printf("Enter a Valid Choice!\n");
            break;
        }
    }

    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DESCENDING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 6 - List Records in Descending
void List_Descending()
{
    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RANGE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 7 - List all Records of File for Specific Range
void List_Range()
{
    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GENDER~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 8 - Seperate Record Based on Gender
void Split_by_Gender()
{
    return;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DISPLAY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void display()
{
    fp = fopen("Patient_Data.txt", "r+");

    if (fp == NULL)
    {
        printf("Unable to Open File\n");
        fclose(fp);
        return;
    }
    else
    {
        struct Patient p2;
        if (record_count == 0)
        {
            printf("\nNo Records Found!\n");
        }

        while (fread(&p2, sizeof(struct Patient), 1, fp))
        {
            printf("\n~~ PATIENT DETAILS ~~\n");
            printf("Patients Number      : %d\n", p2.pno);
            cout << "Patients First Name  : " << p2.first_name << endl;
            cout << "Patients Last Name   : " << p2.last_name << endl;
            printf("Patients Age         : %d\n", p2.age);
            string gen;
            if (p2.gender == 'm' || p2.gender == 'M')
            {
                gen = "Male";
            }
            else
            {
                gen = "Female";
            }
            cout << "Patient's Gender      : " << gen << endl;
            printf("Patients Admission Date [DD/MM/YYYY] : %d %d %d\n", p2.admission_date.date, p2.admission_date.month, p2.admission_date.year);
            printf("Patients Discharge Date [DD/MM/YYYY] : %d %d %d\n", p2.discharge_date.date, p2.discharge_date.month, p2.discharge_date.year);
            cout << "Patient Area of Residence : " << p2.area << endl;
        }

        fclose(fp);

        return;
    }
}