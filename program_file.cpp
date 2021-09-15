/*created by Subin Sedhai
for project work on C programming
modoled as mini- Database Management
but for student data
*/

//libaries used
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int data(),help(),input(),process(int command),add(),generate_new_Id(),detail();
int check(char z[20],int b);

//returning string from check function
char *ret(char s[20])
{
	//uses pointer to show where string is and when called passes the memory from where string is accessed
	char *string= s;
	return string;
 }

//welcome board for first opening
int main()
	{
		//Welcome text
		printf("\n+-----------------------------+");
		printf("\n|---------Welcome to----------|");
		printf("\n|---Student Data Management---|");
		printf("\n|------------System-----------|");
		printf("\n+-----------------------------+");
		printf("\n               -By Subin Sedhai");
		help();
	}

//Commands for program /help
help()
	{
		printf("\n\n");
		printf("Commands:");
		printf("\nView list of commands: 0");
		printf("\nView detailed data on student: 1");
		printf("\nView spreadsheet data on students: 2");
		printf("\nAdd data on existing sheet: 3");
		printf("\nExit: 4");
		input();
	}

input()
	{
		int in;
		//commands
		printf("\nEnter command:\t");
		scanf("%d",&in);
		process(in);
	}

//shows where the program is to go
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
				detail();
			break;
			case 2:
				//all database data is shown
				data();
			break;
			case 3:
				//adds new data to database and creates comprehensive data base for each student
				add();
			break;
			case 4:
				//end program 
				return 0;
			break;
		}
	}

//show detailed data on student with particular id
detail()
	{
		int id;
		char ID[11],ch;
		printf("Enter id of the student:\t");
		scanf("%d",&id);
		
		//convert int to char to search for file
		itoa(id,ID,10);
		strcat(ID,".txt");
		
		FILE *file;
		file=fopen(ID,"r");
		
		do {
			ch=fgetc(file);
			putchar(ch);
		}
		while(ch!=EOF);
		fclose(file);
		input();
	}

//show database data on students
data()
	{
		printf("\n+-------+--------------+------------+--------+---------+-------+--------------+");
		printf("\n|Student|              |  Contact   |  Blood |       |  Gaurdian's |    Due   |");
		printf("\n|  Id   |     Name     |   Number   |  Type  | Class |    Number   |  Payment |");
		printf("\n|-------+--------------+------------+--------+---------+-------+--------------|\n");
		int i=0;
		
		FILE *fptr;
		fptr=fopen("data_table.dat","r");
		
		char ch;
		do {
			ch=fgetc(fptr);
			putchar(ch);
		}
		while(ch!=EOF);
		fclose(fptr);
		input();
	}

//add data to files	
add()
	{
		//structure for data multiple data
		typedef struct{
		int id;
		char f_name[20];
		char l_name[20];
		char b_group[10];
		char contact[13];
		int due;
		char a_class[10];
		char section;
		char g_contact[10];
		}data;
		struct info{
			data std;
			char m_name[20];
			char email[30];
			char desc[100];
		};
		struct info stu[10];
		//adding data
		
		int n;
		printf("Enter number of data you want to enter:\t");
		scanf("%d",&n);
		
		//file saving
			FILE *f;
			f=fopen("data_table.dat","a");
			
			//loop through the input and save the data while looping
			for (int i=0;i<n;i++)
			{
				printf("\n");
				printf("Enter student's first name:");
				scanf("%s",stu[i].std.f_name);
				//first name abbeberation
				char* abb_name = stu[i].std.f_name;
				printf("Enter student's middle name:");
				scanf("%s",stu[i].m_name);
				printf("Enter student's last name:");
				scanf("%s",stu[i].std.l_name);
				printf("Enter student's contact number:");
				scanf("%s",stu[i].std.contact);
				printf("Enter student's email:");
				scanf("%[^\n]s",stu[i].email);
				printf("Enter student's blood group:");
				scanf("%s",stu[i].std.b_group);
				printf("Enter student's due payment:");
				scanf("%d",&stu[i].std.due);
				printf("Enter class of student:");
				scanf("%[^\n]s",stu[i].std.a_class);
				printf("Enter section assigned:");
				scanf("%s",&stu[i].std.section);
				printf("Enter student's gaurdian's number:");
				scanf("%s",stu[i].std.g_contact);
				printf("Enter student's description:");
				scanf("%[^\n]s",stu[i].desc);
				//retriving the id for each student
				stu[i].std.id = generate_new_Id();
				//need the data to go through length check and balance the length before saving or saving in short form for database to fit output asthetics
					
				//converting id from int data type to string for saving files
				char cho[11];			
				itoa(stu[i].std.id,cho,10);
				strcat(cho,".txt");
				
				//creating new file for personal info
				FILE *fa;
				fa=fopen(cho,"w");
				fprintf(fa," First name: %s \n Middle name: %s\n Last name: %s\n Id: %d\n Blood Group: %s\n Contact: %s\n Email: %s\n Gaurdian's Contact: %s\n Class: %s\n Section: %c\n Due: %d\n Description: %s\n\n",stu[i].std.f_name,stu[i].m_name,stu[i].std.l_name,stu[i].std.id,stu[i].std.b_group,stu[i].std.contact,stu[i].email,stu[i].std.g_contact,stu[i].std.a_class,stu[i].std.section,stu[i].std.due,stu[i].desc);
				fclose(fa);
				//end of creation
				
				//database file
			if((strlen(stu[0].std.f_name) + strlen(stu[0].std.l_name))<14){
				check(strcat(strcat(stu[0].std.f_name," "),stu[0].std.l_name),13);
				check(stu[0].std.contact,12);
				check(stu[0].std.b_group,7);
					fprintf(f," %d %s  %s  %s  %s(%c)    %s     %d\n",stu[0].std.id,stu[0].std.f_name,stu[0].std.contact,stu[0].std.b_group,stu[0].std.a_class,stu[0].std.section,stu[0].std.g_contact,stu[0].std.due);
				}
				//if name is longer then follw abb
				else
				{
				check(stu[0].std.l_name,10);
				check(stu[0].std.contact,12);
				check(stu[0].std.b_group,7);
					fprintf(f," %d %c. %s  %s  %s  %s(%c)    %s     %d\n",stu[0].std.id,*abb_name,stu[0].std.l_name,stu[0].std.contact,stu[0].std.b_group,stu[0].std.a_class,stu[0].std.section,stu[0].std.g_contact,stu[0].std.due);
				}
			}
			fclose(f);
		input();
	}
	
 //id generator
generate_new_Id()
{
	int numb=2021000;
	int number;
	//creating file
	FILE *f,*fb;
	fb=fopen("f.txt","r");
	//id for each student is 3 digits first 4 digits are to represent for years of joining
	char ch[3];
	//reading complete line in file for 3 digits
	fgets(ch,3,fb);
	fclose(fb);
	
	f=fopen("f.txt","wb");
	
	//check if file is empty
	if(ch!=NULL)
	{
		number=atoi(ch);
		number++;
		fprintf(f,"%d",number);
		fclose(f);
	}
	else
	{
		number=1;
		fprintf(f,"%d",number);
		fclose(f);
	}
	number+=numb;
	return(number);
}

 //compare length
check(char z[20],int b)
{
	int space=b - strlen(z);
	for(;space>0;space--)
	{
		strcat(z," ");
	}
	//to string retuning function
	ret(z);
}

/*Functions that could be added:
print database of student mathematical compparision of due, 
colors, background style,
make more struct data for comprehensibe file,
memory accolation to manage memory space of program,
makeshift interface,
easier interface process like rejecting incorrect data format input, automatic editing, etc,
make program buffer overflow proof. 
and so on.
 
*/
