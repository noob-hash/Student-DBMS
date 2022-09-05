/*created by Subin Sedhai
for project work on C programming
modoled as mini- Database Management
but for student data
*/

//libaries used
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int login(),help(),process(int),add(),database(),details(),update(),remove_data(),update_due(),setting(),give_command(),generate_new_Id(int n);
char filename[]="data/data_table.txt";

//structure for data
//structure for data multiple data
typedef struct{
int id;
char f_name[20];
char l_name[20];
char b_group[10];
char contact[13];
int due;
char a_class[10];
char section[4];
char g_contact[10];
}data;
struct info{
	data std;
	char m_name[20];
	char mi_name[20];
	char email[30];
	char desc[100];
}stu[10];

int main() {
	printf("\n\t\t\t+-----------------------------+");
	printf("\n\t\t\t|---------Welcome to----------|");
	printf("\n\t\t\t|---Student Data Management---|");
	printf("\n\t\t\t|------------System-----------|");
	printf("\n\t\t\t+-----------------------------+");
	printf("\n\t\t\t               -By Subin Sedhai");
	help();
}

help()
{
	printf("\nCommands:");
	printf("\nView list of commands: 0");
	printf("\nView detailed data on student: 1");
	printf("\nView spreadsheet data on students: 2");
	printf("\nAdd data on existing sheet: 3");
	printf("\nDelete record: 4");
	printf("\nAccount settings: 5");
	printf("\nUpdate personal informtion of student: 6");
	printf("\nRegister payment of student: 7");
	printf("\nExit: 8");
	printf("\n\n");
	give_command();
}

give_command(){
	int in;
	printf("\nEnter 0 for help");
	//commands
	printf("\nEnter command:\t");
	scanf("%d",&in);
	process(in);
}

process(int command)
{
	//clear the screen from all previous outputs
	//works just like cmd command
	system("cls");
	switch (command)
	{
		case 0:
			//shows help
			help();
		break;
		case 1:
			//info about specified student
			details();
		break;
		case 2:
			//all database data is shown
			database();
		break;
		case 3:
			//adds new data to database and creates comprehensive data base for each student
			add();
		break;
		case 4:
			//delete data
			remove_data();
		break;
		case 5:
			//settings
			//setting();
			printf("\nremoved \n");
		break;
		case 6:
			//settings
			update();
		break;
		case 7:
			//settings
			update_due();
		break;
		case 8:
			//end program 
			printf("\n\t\t\tHAVE A NICE DAY.");
			return 0;
		break;
		default:
			printf("Invalid command \a");
			//give_command();
		break;
	}
}

add()
{
	//adding data
	
	int n;
	printf("Enter number of data you want to enter:\t");
	scanf("%d",&n);
	
	//file saving
		FILE *f;
		f=fopen(filename,"a");
		
		//loop through the input and save the data while looping
		for (int i=0;i<n;i++)
		{
			printf("\n");
			printf("Enter student's first name:");
			scanf("%s",stu[i].std.f_name);
			printf("Enter student's middle name:");
			scanf("%s",stu[i].mi_name);
			printf("Enter student's last name:");
			scanf("%s",stu[i].std.l_name);
			printf("Enter student's contact number:");
			scanf("%s",stu[i].std.contact);
			printf("Enter student's email:");
			scanf("%s",stu[i].email);
			printf("Enter student's blood group:");
			scanf("%s",stu[i].std.b_group);
			printf("Enter student's due payment:");
			scanf("%d",&stu[i].std.due);
			printf("Enter class of student:");
			scanf("%s",stu[i].std.a_class);
			printf("Enter section assigned:");
			scanf("%s",&stu[i].std.section);
			printf("Enter student's gaurdian's number:");
			scanf("%s%*c",stu[i].std.g_contact);
			printf("Enter student's description:");
			scanf("%[^\n]s%*c",stu[i].desc);
			//retriving the id for each student
			stu[i].std.id = generate_new_Id(i);
			//saving the file
			fprintf(f,"%d %s %s %s %s %s %s %s %s %s %d %s\n",stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,stu[i].std.due,stu[i].desc);
		}
		fclose(f);
	system("cls");
	give_command();
}

database()
{
	
	FILE *datab;
	if((datab=fopen(filename,"r"))!=NULL)
	{
		printf("\n+-------+--------------+------------+--------+---------+-------------+---------+");
		printf("\n|Student|              |  Contact   |  Blood |         |  Gaurdian's |   Due   |");
		printf("\n|  Id   |     Name     |   Number   |  Type  | Class   |    Number   | Payment |");
		printf("\n|-------+--------------+------------+--------+---------+-------------+---------|\n");
		int i=0;
		
		while((fscanf(datab,"%d %s %s %s %s %s %s %s %s %s %d %[^\n]s\n",&stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,&stu[i].std.section,stu[i].std.g_contact,&stu[i].std.due,stu[i].desc)!=EOF))
		{
			if((strlen(stu[i].std.f_name) + strlen(stu[i].std.l_name))<12)
			{
				printf(" %d %s %s \t%s \t%s \t%s(%s) \t%s \t%d\n",stu[i].std.id,stu[i].std.f_name,stu[i].std.l_name,stu[i].std.contact,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,stu[i].std.due);
			}
			//if name is longer then follw abb
			else
			{
				char* abbr_name=stu[i].std.f_name;
				printf(" %d %c. %s \t%s \t%s \t%s(%s) \t%s \t%d\n",stu[i].std.id,*abbr_name,stu[i].std.l_name,stu[i].std.contact,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,stu[i].std.due);
			}
			i++;
		}
		printf("\n\n\n");
	}
	else
	{
		printf("\nNO DATA AVAILABLE. \a");
	}
	fclose(datab);
	give_command();

}

details()
{
	int due,S_ID;
	int id;
	printf("Enter id of the student:\t");
	scanf("%d",&id);
	FILE *file,*check;
	int j=0;
    check=fopen(filename,"r");
	while((fscanf(check,"%d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*d %*[^\n]s\n",&stu[j].std.id,stu[j].std.f_name,stu[j].mi_name,stu[j].std.l_name,stu[j].std.contact,stu[j].email,stu[j].std.b_group,stu[j].std.a_class,&stu[j].std.section,stu[j].std.g_contact,&stu[j].std.due,stu[j].desc))!=EOF) {
		if(j==1) {
			break;
		}
		if(stu[j].std.id==id) {
			j=1;
		}
	}
	fclose(check);
	id-=2021001;
	if(((file=fopen(filename,"r"))!=NULL)&&j==1)
	{
		int i=0;
		
		//char mi_name[20];
		while((fscanf(file,"%d %s %s %s %s %s %s %s %s %s %d %[^\n]s\n",&stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,&stu[i].std.section,stu[i].std.g_contact,&stu[i].std.due,stu[i].desc)!=EOF))
		{
			//printf("%s",stu[i].m_name);
			if(i==id) {
				//printf("\n%s\n",mi_name);
				printf("\nFirst Name: %s\n",stu[i].std.f_name);
				printf("Middle Name: %s\n",stu[i].mi_name);
				printf("Last Name: %s\n",stu[i].std.l_name);
				printf("Student ID: %d\n",stu[i].std.id);
				printf("Blood Group: %s\n",stu[i].std.b_group);
				printf("Contact: %s\n",stu[i].std.contact);
				printf("Email: %s\n",stu[i].email);
				printf("Gaurdian's Contact: %s\n",stu[i].std.g_contact);
				printf("Class: %s\n",stu[i].std.a_class);
				printf("Section: %s\n",stu[i].std.section);
				printf("Due fee: %d\n",stu[i].std.due);
				printf("Description: %s",stu[i].desc);
				//maybe needs address
				printf("\n\n\n");
			}
			i++;
		}
	}
	else
	{
		printf("\nNo data available for given id \a");
	}
	fclose(file);
	give_command();
}

update_due()
{
    char file2[] ="data/temp.txt";
	int num,update,S_ID,data_no;
	FILE *fptr,*fptr1,*check;
	printf("Enter ID of student whose payment you want to register:\t");
	scanf("%d",&S_ID);
	int j=0;
    check=fopen(filename,"r");
	while((fscanf(check,"%d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*d %*[^\n]s\n",&stu[j].std.id,stu[j].std.f_name,stu[j].mi_name,stu[j].std.l_name,stu[j].std.contact,stu[j].email,stu[j].std.b_group,stu[j].std.a_class,&stu[j].std.section,stu[j].std.g_contact,&stu[j].std.due,stu[j].desc))!=EOF) {
		if(j==1) {
			break;
		}
		if(stu[j].std.id==S_ID) {
			j=1;
		}
	}
	fclose(check);
	S_ID-=2021000;
	if(j==1)
	{
		S_ID-=1;
		//for main database
		fptr=fopen(filename,"r");
		int i=0;
		while(fscanf(fptr,"%d %s %s %s %s %s %s %s %s %s %d %[^\n]s\n",&stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,&stu[i].std.section,stu[i].std.g_contact,&stu[i].std.due,stu[i].desc)!=EOF)
		{
			//printf("\n%s\t%d,%d",info[i].contact,STD,j);
			num=stu[i].std.due;
			if(S_ID==i)
			{
				printf("Update payment amount:\t");
				scanf("%d",&update);
				num-=update;
			}
			fptr1=fopen(file2,"a");
			fprintf(fptr1,"%d %s %s %s %s %s %s %s %s %s %d %s\n",stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,num,stu[i].desc);
			fclose(fptr1);
			i++;
		}
		fclose(fptr);
		remove(filename);
		rename(file2,filename);
	}
	else
	{
		printf("No data exist for given id number \a");
	}
	give_command();	
}

//deleting record
remove_data()
{
	//then so on;
    char file2[] ="data/temp.txt";
    int i=0,number,data_no;
    FILE *fptr1, *fptr2, *check;
	printf("Enter id of student you wish to delete:\t");
    scanf("%d",&number);
    int j=0;
    check=fopen(filename,"r");
	while((fscanf(check,"%d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*d %*[^\n]s\n",&stu[j].std.id,stu[j].std.f_name,stu[j].mi_name,stu[j].std.l_name,stu[j].std.contact,stu[j].email,stu[j].std.b_group,stu[j].std.a_class,&stu[j].std.section,stu[j].std.g_contact,&stu[j].std.due,stu[j].desc))!=EOF) {
		if(j==1) {
			break;
		}
		if(stu[j].std.id==number) {
			j=1;
		}
	}
	fclose(check);
    number-=2021000;
	if(j==1)
	{
		number--;
		fptr1 = fopen(filename,"r");
		while(fscanf(fptr1,"%d %s %s %s %s %s %s %s %s %s %d %[^\n]s\n",&stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,&stu[i].std.section,stu[i].std.g_contact,&stu[i].std.due,stu[i].desc)!=EOF)
		{
			if(number!=i)
			{
				fptr2=fopen(file2,"a");
				fprintf(fptr2,"%d %s %s %s %s %s %s %s %s %s %d %s\n",stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,stu[i].std.due,stu[i].desc);
				fclose(fptr2);
			}
			i++;
		}
		fclose(fptr1);
		remove(filename);
		rename(file2,filename);
	}
	else
	{
		printf("No data exist for given id number \a");
	}
	give_command();
}

update()
{
    char file2[] ="data/temp.txt";
	int num,update,data_no;
	FILE *fptr1,*fptr,*check;
	int S_ID,i=0;
	printf("Enter ID of student whose data you want you alter:\t");
	scanf("%d",&S_ID);
	int j=0;
    check=fopen(filename,"r");
	while((fscanf(check,"%d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*d %*[^\n]s\n",&stu[j].std.id,stu[j].std.f_name,stu[j].mi_name,stu[j].std.l_name,stu[j].std.contact,stu[j].email,stu[j].std.b_group,stu[j].std.a_class,&stu[j].std.section,stu[j].std.g_contact,&stu[j].std.due,stu[j].desc))!=EOF) {
		if(j==1) {
			break;
		}
		if(stu[j].std.id==S_ID) {
			j=1;
		}
	}
	fclose(check);
	S_ID-=2021000;
	if(j==1)
	{
		S_ID-=1;
		//for main database
		fptr=fopen(filename,"r");
		while(fscanf(fptr,"%d %s %s %s %s %s %s %s %s %s %d %[^\n]s\n",&stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,&stu[i].std.section,stu[i].std.g_contact,&stu[i].std.due,stu[i].desc)!=EOF)
		{
			if(S_ID==i)
			{
				stu[i].std.id=(S_ID+2021001);
				printf("\n");
				printf("Enter student's first name:");
				scanf("%s",stu[i].std.f_name);
				printf("Enter student's middle name:");
				scanf("%s",stu[i].mi_name);
				printf("Enter student's last name:");
				scanf("%s",stu[i].std.l_name);
				printf("Enter student's contact number:");
				scanf("%s",stu[i].std.contact);
				printf("Enter student's email:");
				scanf("%s",stu[i].email);
				printf("Enter student's blood group:");
				scanf("%s",stu[i].std.b_group);
				printf("Enter student's due payment:");
				scanf("%d",&stu[i].std.due);
				printf("Enter class of student:");
				scanf("%s",stu[i].std.a_class);
				printf("Enter section assigned:");
				scanf("%s",&stu[i].std.section);
				printf("Enter student's gaurdian's number:");
				scanf("%s%*c",stu[i].std.g_contact);
				printf("Enter student's description:");
				scanf("%[^\n]s%*c",stu[i].desc);
			}
			fptr1=fopen(file2,"a");
			fprintf(fptr1,"%d %s %s %s %s %s %s %s %s %s %d %s\n",stu[i].std.id,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,stu[i].std.due,stu[i].desc);
			fclose(fptr1);
			i++;
		}
		fclose(fptr);
		remove(filename);
		rename(file2,filename);
	}
	else
	{
		printf("No data exist for given id number \a");
	}
	give_command();	
}

generate_new_Id(int n)
{
	int number=2021000,i=0;
	//creating file
	FILE *fptr;
	fptr=fopen(filename,"r");
	//id for each student is 3 digits first 4 digits are to represent for years of joining
	if(fptr!=NULL) {
		while(fscanf(fptr,"%d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*d %*[^\n]s\n",&number,stu[i].std.f_name,stu[i].mi_name,stu[i].std.l_name,stu[i].std.contact,stu[i].email,stu[i].std.b_group,stu[i].std.a_class,&stu[i].std.section,stu[i].std.g_contact,&stu[i].std.due,stu[i].desc)!=EOF)
		{
			//check if file is empty	
			i++;
		}
		number+=(n+1);
	}
	else {
		number;
	}
	fclose(fptr);
	return(number);
}
