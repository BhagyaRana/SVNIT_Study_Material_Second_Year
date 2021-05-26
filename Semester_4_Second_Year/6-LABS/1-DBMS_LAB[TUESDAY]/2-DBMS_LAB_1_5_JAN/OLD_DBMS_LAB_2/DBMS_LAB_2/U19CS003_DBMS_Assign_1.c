//U19CS003 Aman Kumar

#include <stdio.h>
#include <string.h>

struct date
{ //STRUCTURE OF DATE
	int dd;
	int mm;
	int yy;
};

struct patient
{ //STRUCTURE OF PATIENT
	int pno;
	char fname[20];
	char lname[20];
	int age;
	char gender;
	char area[20];
	struct date adate;
	struct date ddate;
};

int tcount = 0;
void tco()
{
	struct patient p1;
	FILE *fp;
	fp = fopen("record.txt", "r+");
	if (fp == NULL)
	{

		fclose(fp);
		return;
	}

	while (fread(&p1, sizeof(struct patient), 1, fp))
	{
		tcount++;
	}
	fclose(fp);
}

void write() //ADDING RECORDS
{
	struct patient p1;
	FILE *fp;
	fp = fopen("record.txt", "a+");
	printf("Enter Patient Number : ");
	scanf("%d", &p1.pno);
	printf("Enter First Name of patient : ");
	fflush(stdin);
	gets(p1.fname);
	printf("Enter Last Name of patient : ");
	fflush(stdin);
	gets(p1.lname);
	printf("Enter age of patient : ");
	scanf("%d", &p1.age);
	printf("Enter gender of patient (M/F) : ");
	fflush(stdin);
	scanf("%c", &p1.gender);
	printf("Enter Area of the patient : ");
	fflush(stdin);
	gets(p1.area);
	printf("Enter Admission date (format : dd mm yyyy ) : ");
	scanf("%d %d %d", &p1.adate.dd, &p1.adate.mm, &p1.adate.yy);
	printf("Enter Discharge date (format : dd mm yyyy ) : ");
	scanf("%d %d %d", &p1.ddate.dd, &p1.ddate.mm, &p1.ddate.yy);
	fwrite(&p1, sizeof(struct patient), 1, fp);
	tcount++;
	fclose(fp);
}

void read() //READING AND DISPLAYING RECORDS
{
	struct patient p1;
	FILE *fp;
	fp = fopen("record.txt", "r+");
	if (fp == NULL)
	{
		printf("Failed to load Records empty!!!");
	}
	else
	{
		while (fread(&p1, sizeof(struct patient), 1, fp))
		{
			printf("\n\n--------------------------------------------------------------");
			printf("\nPatient Number : %d", p1.pno);
			printf("\nFirst Name     : %s", p1.fname);
			printf("\nLast Name      : %s", p1.lname);
			printf("\nAge            : %d", p1.age);
			printf("\nGender         : %c", p1.gender);
			printf("\nArea           : %s", p1.area);
			printf("\nAdmission Date : %d / %d / %d", p1.adate.dd, p1.adate.mm, p1.adate.yy);
			printf("\nDischarge Date : %d / %d / %d", p1.ddate.dd, p1.ddate.mm, p1.ddate.yy);
		}
	}
	fclose(fp);
}

void delrec() //DELETING RECORDS
{
	struct patient p1;
	FILE *fp;
	FILE *fp1;
	fp = fopen("record.txt", "r+");

	if (fp == NULL)
	{
		printf("Failed to delete! Records empty ");
		fclose(fp);
		return;
	}

	else
	{
		fp1 = fopen("copy.txt", "a+");
		int n, flag = 0;
		printf("\nEnter the Patient Number to be deleted : ");
		scanf("%d", &n);
		while (fread(&p1, sizeof(struct patient), 1, fp))
		{
			if (p1.pno != n)
			{
				fwrite(&p1, sizeof(struct patient), 1, fp1);
			}
			else
			{
				flag = 1;
			}
		}
		fclose(fp);
		fclose(fp1);
		remove("record.txt");
		rename("copy.txt", "record.txt");

		if (flag == 1)
		{
			printf("\nDELETED!");
			tcount--;
		}
		else
		{
			printf("Not Found");
		}
	}
}

void update() //MODIFYING RECORDS
{
	struct patient p1, p2;
	FILE *fp;
	FILE *fp1;
	fp = fopen("record.txt", "r+");
	int flag = 0;
	if (fp == NULL)
	{
		printf("Failed to modify! records empty");
		fclose(fp);
		return;
	}

	else
	{
		fp1 = fopen("copy.txt", "a+");
		int n;
		printf("\nEnter the Patient Number to be updated : ");
		scanf("%d", &n);
		p1.pno = n;
		printf("Enter First Name of patient : ");
		fflush(stdin);
		gets(p1.fname);
		printf("Enter Last Name of patient : ");
		fflush(stdin);
		gets(p1.lname);
		printf("Enter age of patient : ");
		scanf("%d", &p1.age);
		printf("Enter gender of patient (M/F) : ");
		fflush(stdin);
		scanf("%c", &p1.gender);
		printf("Enter Area of the patient : ");
		fflush(stdin);
		gets(p1.area);
		printf("Enter Admission date (format : dd mm yyyy ) : ");
		scanf("%d %d %d", &p1.adate.dd, &p1.adate.mm, &p1.adate.yy);
		printf("Enter Discharge date (format : dd mm yyyy ) : ");
		scanf("%d %d %d", &p1.ddate.dd, &p1.ddate.mm, &p1.ddate.yy);

		while (fread(&p2, sizeof(struct patient), 1, fp))
		{
			if (p2.pno != n)
			{
				fwrite(&p2, sizeof(struct patient), 1, fp1);
			}
			else
			{
				fwrite(&p1, sizeof(struct patient), 1, fp1);
				flag = 1;
			}
		}

		fclose(fp);
		fclose(fp1);

		remove("record.txt");
		rename("copy.txt", "record.txt");
		if (flag == 0)
		{
			printf("\nPatient not found!");
		}
		else
		{
			printf("\nUPDATED!");
		}
	}
}

void count() //COUNT
{
	struct patient p1, p2;
	FILE *fp;
	fp = fopen("record.txt", "r+");
	if (fp == NULL)
	{
		printf("Failed to count! Records Empty ");
		fclose(fp);
		return;
	}
	int age[100] = {0}, m = 0;
	while (fread(&p1, sizeof(struct patient), 1, fp))
	{

		age[p1.age]++;
		if (p1.gender == 'M')
			m++;
	}
	fclose(fp);
	printf("\nTotal Number of Patients : %d\n", tcount);
	int i = 0;
	for (i = 1; i < 100; i++)
	{
		if (age[i] != 0)
			printf("\nNumber of people of age %d : %d", i, age[i]);
	}
	printf("\n\nNumber of Male patient : %d", m);
	printf("\nNumber of Female patient : %d\n", tcount - m);

	int acount, flag = 0, v = 0;
	fp = fopen("record.txt", "r+");

	char word[20], visited[tcount][20];
	while (fread(&p1, sizeof(struct patient), 1, fp))
	{
		acount = 0;
		flag = 0;
		strcpy(word, p1.area);
		for (i = 0; i < v; i++)
		{
			if (strcmp(word, visited[i]) == 0)
				flag = 1;
		}
		if (flag == 1)
		{
			continue;
		}
		else
		{

			strcpy(visited[v], word);
			v++;
		}
		FILE *fp1;
		fp1 = fopen("record.txt", "r+");
		while (fread(&p2, sizeof(struct patient), 1, fp1))
		{
			if (strcmp(word, p2.area) == 0)
				acount++;
		}
		printf("\nNumber of people in area %s : %d", word, acount);
		fclose(fp1);
	}
	fclose(fp);
}

void sortfn(int ch) //Sorting by first name
{
	struct patient p[tcount], p1, temp;
	int i = 0, j;

	FILE *fp;
	fp = fopen("record.txt", "r+");
	while (fread(&p1, sizeof(struct patient), 1, fp))
	{
		p[i] = p1;
		i++;
	}
	if (ch == 1) //For Ascending order ch==1
	{

		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (strcmp(p[j + 1].fname, p[j].fname) < 0)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	else //else descending
	{
		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (strcmp(p[j + 1].fname, p[j].fname) > 0)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	FILE *fp1;
	fp1 = fopen("sorted.txt", "a+");
	for (i = 0; i < tcount; i++)
	{
		fwrite(&p[i], sizeof(struct patient), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("record.txt");
	rename("sorted.txt", "record.txt");
	printf("\n\nSorted Record is : \n");
	read();
}

void sortln(int ch) //Sorting by last name
{
	struct patient p[tcount], p1, temp;
	int i = 0, j;

	FILE *fp;
	fp = fopen("record.txt", "r+");
	while (fread(&p1, sizeof(struct patient), 1, fp))
	{
		p[i] = p1;
		i++;
	}
	if (ch == 1) //For Ascending order ch==1
	{

		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (strcmp(p[j + 1].lname, p[j].lname) < 0)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	else //else descending
	{
		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (strcmp(p[j + 1].lname, p[j].lname) > 0)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	FILE *fp1;
	fp1 = fopen("sorted.txt", "a+");
	for (i = 0; i < tcount; i++)
	{
		fwrite(&p[i], sizeof(struct patient), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("record.txt");
	rename("sorted.txt", "record.txt");
	printf("\n\nSorted Record is : \n");
	read();
}

void sortage(int ch) //Sorting by age
{
	struct patient p[tcount], p1, temp;
	int i = 0, j;

	FILE *fp;
	fp = fopen("record.txt", "r+");
	while (fread(&p1, sizeof(struct patient), 1, fp))
	{
		p[i] = p1;
		i++;
	}
	if (ch == 1) //For Ascending order ch==1
	{

		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (p[j + 1].age < p[j].age)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	else //else descending
	{
		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (p[j + 1].age > p[j].age)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	FILE *fp1;
	fp1 = fopen("sorted.txt", "a+");
	for (i = 0; i < tcount; i++)
	{
		fwrite(&p[i], sizeof(struct patient), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("record.txt");
	rename("sorted.txt", "record.txt");
	printf("\n\nSorted Record is : \n");
	read();
}

int cmp(struct date d1, struct date d2) //comparing dates
{
	if (d1.yy > d2.yy)
		return 1;
	else if (d1.yy < d2.yy)
		return -1;
	else
	{
		if (d1.mm > d2.mm)
			return 1;
		else if (d1.mm < d2.mm)
			return -1;
		else
		{
			if (d1.dd > d2.dd)
				return 1;
			else if (d1.dd < d2.dd)
				return -1;
			else
			{
				return 0;
			}
		}
	}
}

void sort_d(int ch) //Sort by date
{
	struct patient p[tcount], p1, temp;
	int i = 0, j;

	FILE *fp;
	fp = fopen("record.txt", "r+");
	while (fread(&p1, sizeof(struct patient), 1, fp))
	{
		p[i] = p1;
		i++;
	}
	if (ch == 1) //For Ascending order ch==1 admission date
	{

		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (cmp(p[j + 1].adate, p[j].adate) < 0)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	else //else descending discharge date
	{
		for (i = 1; i < tcount; i++)
			for (j = 0; j < tcount - i; j++)
			{
				if (cmp(p[j + 1].ddate, p[j].ddate) > 0)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	FILE *fp1;
	fp1 = fopen("sorted.txt", "a+");
	for (i = 0; i < tcount; i++)
	{
		fwrite(&p[i], sizeof(struct patient), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("record.txt");
	rename("sorted.txt", "record.txt");
	printf("\n\nSorted Record is : \n");
	read();
}

void sort() //SORTING DRIVER FUNCTION
{
	int ch;

	FILE *fp;
	fp = fopen("record.txt", "r+");
	if (fp == NULL)
	{
		printf("Failed to sort! Records Empty ");
		fclose(fp);
		return;
	}
	fclose(fp);

	printf("\n\n1.Ascending order\n2.Descending order");
	printf("\nChoice : ");
	scanf("%d", &ch);

	if (ch == 1) //ASCENDING
	{
		printf("\nSort by ");
		printf("\n1.First Name");
		printf("\n2.Last Name");
		printf("\n3.Age");
		printf("\n4.Admission Date\nChoose : ");
		int tch;
		scanf("%d", &tch);
		switch (tch)
		{
		case 1:
			sortfn(ch);
			break;
		case 2:
			sortln(ch);
			break;
		case 3:
			sortage(ch);
			break;
		case 4:
			sort_d(ch);
			break;
		default:
			printf("\n\nInvalid choice!!");
			break;
		}
	}
	else if (ch == 2) //DESCENDING
	{
		printf("\nSort by ");
		printf("\n1.First Name");
		printf("\n2.Last Name");
		printf("\n3.Age");
		printf("\n4.Discharge Date\nChoose : ");
		int tch;
		scanf("%d", &tch);
		switch (tch)
		{
		case 1:
			sortfn(ch);
			break;
		case 2:
			sortln(ch);
			break;
		case 3:
			sortage(ch);
			break;
		case 4:
			sort_d(ch);
			break;
		default:
			printf("\n\nInvalid choice!!");
			break;
		}
	}
	else
	{
		printf("\n\nInvalid Choice!");
	}
}

void list(int ch) //LISTING ACCORDING TO CONDITION
{
	struct patient p;
	struct date d[11];
	int mon, year, flag = 0;
	FILE *fp;
	fp = fopen("record.txt", "r+");
	if (fp == NULL)
	{
		printf("Failed to list! Records Empty ");
		fclose(fp);
		return;
	}
	switch (ch)
	{
	case 1:

		while (fread(&p, sizeof(struct patient), 1, fp))
		{
			if ((p.fname[0] >= 'A' && p.fname[0] <= 'J') || (p.fname[0] >= 'a' && p.fname[0] <= 'j'))
			{
				printf("\n\n--------------------------------------------------------------");
				printf("\nPatient Number : %d", p.pno);
				printf("\nFirst Name     : %s", p.fname);
				printf("\nLast Name      : %s", p.lname);
				printf("\nAge            : %d", p.age);
				printf("\nGender         : %c", p.gender);
				printf("\nArea           : %s", p.area);
				printf("\nAdmission Date : %d / %d / %d", p.adate.dd, p.adate.mm, p.adate.yy);
				printf("\nDischarge Date : %d / %d / %d", p.ddate.dd, p.ddate.mm, p.ddate.yy);
				flag = 1;
			}
		}
		fclose(fp);
		if (flag == 0)
		{
			printf("\n\nNo desired record found!");
		}
		break;
	case 2:

		printf("Enter given date (format : dd mm yyyy ) : ");
		scanf("%d %d %d", &d[0].dd, &d[0].mm, &d[0].yy);
		int i = 1, m; //m IS MAXIMUM DAYS OF A SPECIFIC MONTH
		while (i != 11)
		{
			if ((d[i - 1].mm % 2 != 0 && d[i - 1].mm <= 7) || (d[i - 1].mm % 2 == 0 && d[i - 1].mm <= 12)) //TO CALCULATE DAYS ON SPECIFIC MONTH
			{
				m = 31;
			}
			else if (d[i - 1].mm == 2)
			{
				if (d[i - 1].yy % 400 == 0)
					m = 29;
				else if (d[i - 1].yy % 100 == 0)
					m = 28;
				else if (d[i - 1].yy % 4 == 0)
					m = 29;
				else
				{
					m = 28;
				}
			}
			else
			{
				m = 30;
			}
			if (d[i - 1].dd == m)
			{
				d[i].dd = (d[i - 1].dd + 1) % m;
				if (d[i - 1].mm == 12)
				{
					d[i].mm = 1;
					d[i].yy = d[i - 1].yy + 1;
				}
				else
				{
					d[i].mm = d[i - 1].mm + 1;
					d[i].yy = d[i - 1].yy;
				}
			}
			else
			{
				d[i].dd = (d[i - 1].dd + 1);
				d[i].mm = d[i - 1].mm;
				d[i].yy = d[i - 1].yy;
			}
			i++;
		}
		while (fread(&p, sizeof(struct patient), 1, fp))
		{
			i = 0;
			while (i < 11)
			{
				if (cmp(p.adate, d[i]) == 0) //cmp() RETURNS 0 IF EQUAL
				{

					printf("\n\n--------------------------------------------------------------");
					printf("\nPatient Number : %d", p.pno);
					printf("\nFirst Name     : %s", p.fname);
					printf("\nLast Name      : %s", p.lname);
					printf("\nAge            : %d", p.age);
					printf("\nGender         : %c", p.gender);
					printf("\nArea           : %s", p.area);
					printf("\nAdmission Date : %d / %d / %d", p.adate.dd, p.adate.mm, p.adate.yy);
					printf("\nDischarge Date : %d / %d / %d", p.ddate.dd, p.ddate.mm, p.ddate.yy);
					flag = 1;
					break;
				}
				i++;
			}
		}
		fclose(fp);
		if (flag == 0)
		{
			printf("\n\nNo desired record found!");
		}
		break;
	case 3:
		printf("\nEnter Admission month & year ( mm yyyy ): ");
		scanf("%d %d", &mon, &year);
		while (fread(&p, sizeof(struct patient), 1, fp))
		{
			if (p.adate.yy == year)
			{
				if (mon <= 7)
				{
					if (p.adate.mm >= mon && p.adate.mm <= mon + 5)
					{
						printf("\n\n--------------------------------------------------------------");
						printf("\nPatient Number : %d", p.pno);
						printf("\nFirst Name     : %s", p.fname);
						printf("\nLast Name      : %s", p.lname);
						printf("\nAge            : %d", p.age);
						printf("\nGender         : %c", p.gender);
						printf("\nArea           : %s", p.area);
						printf("\nAdmission Date : %d / %d / %d", p.adate.dd, p.adate.mm, p.adate.yy);
						printf("\nDischarge Date : %d / %d / %d", p.ddate.dd, p.ddate.mm, p.ddate.yy);
						flag = 1;
					}
				}

				else
				{
					if (p.adate.mm >= mon && p.adate.mm <= 12)
					{
						printf("\n\n--------------------------------------------------------------");
						printf("\nPatient Number : %d", p.pno);
						printf("\nFirst Name     : %s", p.fname);
						printf("\nLast Name      : %s", p.lname);
						printf("\nAge            : %d", p.age);
						printf("\nGender         : %c", p.gender);
						printf("\nArea           : %s", p.area);
						printf("\nAdmission Date : %d / %d / %d", p.adate.dd, p.adate.mm, p.adate.yy);
						printf("\nDischarge Date : %d / %d / %d", p.ddate.dd, p.ddate.mm, p.ddate.yy);
						flag = 1;
					}
				}
			}
			else if (p.adate.yy == year + 1)
			{
				if (p.adate.mm <= mon - 7)
				{
					printf("\n\n--------------------------------------------------------------");
					printf("\nPatient Number : %d", p.pno);
					printf("\nFirst Name     : %s", p.fname);
					printf("\nLast Name      : %s", p.lname);
					printf("\nAge            : %d", p.age);
					printf("\nGender         : %c", p.gender);
					printf("\nArea           : %s", p.area);
					printf("\nAdmission Date : %d / %d / %d", p.adate.dd, p.adate.mm, p.adate.yy);
					printf("\nDischarge Date : %d / %d / %d", p.ddate.dd, p.ddate.mm, p.ddate.yy);
					flag = 1;
				}
			}
		}

		fclose(fp);
		if (flag == 0)
		{
			printf("\n\nNo desired record found!");
		}
		break;

	default:
		printf("\n\nInvalid Input!");
		fclose(fp);
		break;
	}
}

void seperate()
{
	struct patient p;
	FILE *fp;
	FILE *fpm;
	FILE *fpf;
	fp = fopen("record.txt", "r+");
	if (fp == NULL)
	{
		printf("Failed to seperate! Records Empty ");
		fclose(fp);
		return;
	}
	fpm = fopen("malerecord.txt", "a+");
	fpf = fopen("femalerecord.txt", "a+");
	if (fpm != NULL) //TO MAKE A FRESH TEXT FILE
	{
		fclose(fpm);
		remove("malerecord.txt");
		fpm = fopen("malerecord.txt", "a+");
	}
	if (fpf != NULL) //TO MAKE A FRESH TEXT FILE
	{
		fclose(fpf);
		remove("femalerecord.txt");
		fpf = fopen("femalerecord.txt", "a+");
	}

	while (fread(&p, sizeof(struct patient), 1, fp))
	{
		if (p.gender == 'M') //WRITING RECORDS
		{
			fwrite(&p, sizeof(struct patient), 1, fpm);
		}
		else if (p.gender == 'F') //WRITING RECORDS
		{
			fwrite(&p, sizeof(struct patient), 1, fpf);
		}
	}
	fclose(fp);
	fclose(fpm);
	fclose(fpf);

	fpm = fopen("malerecord.txt", "r+");
	fpf = fopen("femalerecord.txt", "r+");

	int flag = 0;
	printf("\n\n\n\n\t\t\t Only males records are : ");
	while (fread(&p, sizeof(struct patient), 1, fpm)) //DISPLAYING RECORDS
	{
		printf("\n\n--------------------------------------------------------------");
		printf("\nPatient Number : %d", p.pno);
		printf("\nFirst Name     : %s", p.fname);
		printf("\nLast Name      : %s", p.lname);
		printf("\nAge            : %d", p.age);
		printf("\nGender         : %c", p.gender);
		printf("\nArea           : %s", p.area);
		printf("\nAdmission Date : %d / %d / %d", p.adate.dd, p.adate.mm, p.adate.yy);
		printf("\nDischarge Date : %d / %d / %d", p.ddate.dd, p.ddate.mm, p.ddate.yy);
		flag = 1;
	}

	if (flag == 0)
	{
		printf("\n\nNo male records found!");
	}
	flag = 0;
	fclose(fpm);
	printf("\n\n\n\n\t\t\t Only females records are : ");
	while (fread(&p, sizeof(struct patient), 1, fpf)) //DISPLAYING RECORDS
	{
		printf("\n\n--------------------------------------------------------------");
		printf("\nPatient Number : %d", p.pno);
		printf("\nFirst Name     : %s", p.fname);
		printf("\nLast Name      : %s", p.lname);
		printf("\nAge            : %d", p.age);
		printf("\nGender         : %c", p.gender);
		printf("\nArea           : %s", p.area);
		printf("\nAdmission Date : %d / %d / %d", p.adate.dd, p.adate.mm, p.adate.yy);
		printf("\nDischarge Date : %d / %d / %d", p.ddate.dd, p.ddate.mm, p.ddate.yy);
		flag = 1;
	}
	if (flag == 0)
	{
		printf("\n\nNo female records found!");
	}
	fclose(fpf);
}

int main() //DRIVER CODE
{

	int ch = 1, t;
	tco(); //to counting existing records initially
	while (ch)
	{
		printf("\n\nEnter your choice : ");
		printf("\n1.Add record");
		printf("\n2.Delete record");
		printf("\n3.Modify Record");
		printf("\n4.Count ");
		printf("\n5.Sort / Arrange");
		printf("\n6.List");
		printf("\n7.Seperate male and female records  ");
		printf("\n8.Display records");
		printf("\n0.Exit\nChoose : ");
		scanf("%d", &ch);
		if (ch == 0)
			break;
		switch (ch)
		{
		case 1:
			write();
			break;
		case 2:
			delrec();
			break;
		case 3:
			update();
			break;
		case 4:
			count();
			break;
		case 5:
			sort();
			break;
		case 6:

			printf("\n1.List all patients from A-J  ");
			printf("\n2.List all patients whose Adm Date between given date till 10 days next  ");
			printf("\n3.List all patients whose Adm month between given month till 5 months next");
			printf("\nChoose : ");
			scanf("%d", &t);

			list(t);
			break;
		case 7:
			seperate();
			break;
		case 8:
			read();
			break;

		default:
			printf("Invalid Input!");
			break;
		}
	}
	return 0;
}