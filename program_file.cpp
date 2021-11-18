/*created by Subin Sedhai
for project work on C programming
modoled as mini- Database Management
but for student data
*/

//libaries used
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int login(),help(),process(int),add(),database(),details(),update(),remove_data(),update_due(),setting(),give_command();
//different functions
int change_o_P(),here(),generate_new_Id(),check(char z[20],int b);

//acts as boolean value to know if user has access to all function or not
int access=0;
char pass[20],user[20]="user/";

int main()
{
	login();
	//Welcome text
	printf("\n\t\t\t+-----------------------------+");
	printf("\n\t\t\t|---------Welcome to----------|");
	printf("\n\t\t\t|---Student Data Management---|");
	printf("\n\t\t\t|------------System-----------|");
	printf("\n\t\t\t+-----------------------------+");
	printf("\n\t\t\t               -By Subin Sedhai");
	help();
}

login()
{
	//reset value of user
	strcpy(user,"user/");
	char u_name[10],s_pword[20];
	printf("\nEnter Username:\t");
	scanf("%s",u_name);
	strcat(user,u_name);
	printf("Enter Password:\t");
	scanf("%s",pass);
	strcat(user,".txt");
	//admin has power to create other working account in system
	//have a default password and user name
	FILE *enter;
	if((enter=fopen(user,"r"))!=NULL)
	{
		fscanf(enter,"%s",s_pword);
		if(strcmp(pass,s_pword)==0)
		{
			//check for aurthority user has
			if(u_name[0]=='$')
			{
				access=1;
			}
			//give rights according to privilige can have multiple worker account but only one admin
		}
		else
		{
			printf("\nWrong Username/ Password \a");
			fclose(enter);
			login();
		}
	}	
	else
	{
		printf("\nWrong Username/ Password \a");
		fclose(enter);
		login();
	}
	fclose(enter);
	//right to change password of said username
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
			setting();
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
			give_command();
		break;
	}
}

setting()
{
	int cond;
	printf("Commands:\n");
	printf("Go To Setting(0/1):\t");
	scanf("%d",&cond);
	if(cond==0)
	{
		give_command();
	}
	else if(cond==1)
	{
		here();
	}
	else
	{
		printf("Invalid command.\n");
		setting();
	}	
}

change_o_P()
{
	char Name[20]="user/",n[20];
	printf("Enter User name:\t");
	scanf("%s",n);
	strcat(Name,n);
	strcat(Name,".txt");
	//check if user exist
	FILE *change;
	if((change=fopen(Name,"wb"))!=NULL)
	{
		char A_P[20],new_p[20],confirm_p[20];
		printf("Enter admin password:\t");
		scanf("%s",A_P);
		if(strcmp(A_P,pass)==0)
		{
			printf("Enter new password:\t");
			scanf("%s",new_p);
			printf("Confirm new password: \t");
			scanf("%s",confirm_p);
			if(strcmp(new_p,confirm_p)==0)
			{
				fprintf(change,"%s",new_p);
			}
			else
			{
				printf("Mismatch in new password and confirm password \a");
				//goto enter enter admin password phase
				setting();
			}
		}
		else
		{
			printf("Incorrect password. \a");
			//go to enter admin password phase
			setting();
		}
	}
	fclose(change);
}

here(){
	int choice;
	char old_P[20],new_p[20],confirm_p[20],f_pass[20];
	if (access==0)
	{
		printf("Enter current password:\t");
		scanf("%s",old_P);
		printf("Enter new password:\t");
		scanf("%s",new_p);
		printf("Confirm new password:\t");
		scanf("%s",confirm_p);
		//checking for old password
		if (strcmp(pass,old_P)==0)
		{
			if(strcmp(new_p,confirm_p)==0)
			{
				FILE *edit;
				edit=fopen(user,"wb");
				fprintf(edit,"%s",new_p);
				fclose(edit);
			}
		}
	}
	else
	{
		int cmmd;
		printf("\nCommands:\n");
		printf("Change yur password: 0\nChange password for working account: 1\nCreate new working account: 2\nDelete Working account: 3\nExit: 4");
		printf("Enter the command:\t");
		scanf("%d",&cmmd);
		switch (cmmd)
		{
			case 0:
				//changing password for admin
				printf("Enter current password:\t");
				scanf("%s",old_P);
				printf("Enter new password:\t");
				scanf("%s",new_p);
				printf("Confirm new password:\t");
				scanf("%s",confirm_p);
				//checking for old password
				if (strcmp(pass,old_P)==0)
				{
					if(strcmp(new_p,confirm_p)==0)
					{
						FILE *edit;
						edit=fopen(user,"wb");
						fprintf(edit,new_p);
						fclose(edit);
					}
				}
			break;
			case 1:
				//changing password for others
				change_o_P();
			break;
			case 2:
				{
					char some[20]="user/",te[20],c_pword[20];
					printf("Enter username for account:\t");
					scanf("%s",te);
					strcat(some,te);
					strcat(some,".txt");
					//check if file with user name exist
					FILE *u;
					if((u=fopen(some,"w"))!=NULL)
					{
						printf("Enter password:\t");
						scanf("%s",c_pword);
						fprintf(u,"%s",c_pword);
					}
					else
					{
						printf("User Id already exists.\a");
						setting();
					}
					fclose(u);
				}
			break;
			case 3:
				{
					char r_name[20]="user/",input[20];
					printf("Enter user you want to remove:\t");
					scanf("%s",input);
					if(input[0]=='$')
					{
						printf("You cannot delete administrative account.\n");
						setting();
					}
					else
					{
						strcat(r_name,input);
						strcat(r_name,".txt");
						FILE *del;
						if((del=fopen(r_name,"w"))!=NULL)
						{
							remove(r_name);
						}
						fclose(del);
					}
				}
			break;
			case 4:
				system("cls");
				give_command();
			break;
			default:
				printf("Invalid command \a");
				setting();
			break;
		}
		
		//admin should be able to remove other user and change pssword for other user and see more data
	}
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
			f=fopen("data/data_table.txt","a");
			
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
				stu[i].std.id = generate_new_Id();
				//need the data to go through length check and balance the length before saving or saving in short form for database to fit output asthetics
					
				//converting id from int data type to string for saving files
				char indi[20]="data/", cho[11];			
				itoa(stu[i].std.id,cho,10);
				strcat(cho,".txt");
				strcat(indi,cho);
				
				//creating new file for personal info
				FILE *fa;
				fa=fopen(indi,"w");
				fprintf(fa,"%s %s %s %d %s %s %s %s %s %c %d %s\n",stu[i].std.f_name,stu[i].m_name,stu[i].std.l_name,stu[i].std.id,stu[i].std.b_group,stu[i].std.contact,stu[i].email,stu[i].std.g_contact,stu[i].std.a_class,stu[i].std.section,stu[i].std.due,stu[i].desc);
				fclose(fa);
				//end of creation
				
				//database file
				if((strlen(stu[i].std.f_name) + strlen(stu[i].std.l_name))<14)
				{
					fprintf(f,"%d %s %s %s %s %s (%c) %s %d\n",stu[i].std.id,stu[i].std.f_name,stu[i].std.l_name,stu[i].std.contact,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,stu[i].std.due);
				}
				//if name is longer then follw abb
				else
				{
					fprintf(f,"%d %c. %s %s %s %s (%c) %s %d\n",stu[i].std.id,*abb_name,stu[i].std.l_name,stu[i].std.contact,stu[i].std.b_group,stu[i].std.a_class,stu[i].std.section,stu[i].std.g_contact,stu[i].std.due);
				}
			}
			fclose(f);
			system("cls");
		give_command();
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

database()
{
	//structure for data multiple data
	struct data{
	int id;
	char f_name[20];
	char l_name[20];
	char b_group[10];
	char contact[13];
	int due;
	char a_class[10];
	char section[4];
	char g_contact[10];
	};
	struct data stu[10];
	printf("\n+-------+--------------+------------+--------+---------+-------------+---------+");
	printf("\n|Student|              |  Contact   |  Blood |         |  Gaurdian's |   Due   |");
	printf("\n|  Id   |     Name     |   Number   |  Type  | Class   |    Number   | Payment |");
	printf("\n|-------+--------------+------------+--------+---------+-------------+---------|\n");
	FILE *datab;
	if((datab=fopen("data/data_table.txt","r"))!=NULL)
	{
		int i=0;
		while((fscanf(datab,"%d %s %s %s %s %s %s %s %d\n",&stu[i].id,stu[i].f_name,stu[i].l_name,stu[i].contact,stu[i].b_group,stu[i].a_class,stu[i].section,stu[i].g_contact,&stu[i].due))!=EOF)
		{
			printf(" %d %s %s \t%s \t%s \t%s%s \t%s \t%d\n",stu[i].id,stu[i].f_name,stu[i].l_name,stu[i].contact,stu[i].b_group,stu[i].a_class,stu[i].section,stu[i].g_contact,stu[i].due);
			i++;
		}
		printf("\n\n\n");
	}
	else
	{
		printf("\nNO DATA AVAILABLE.");
	}
	fclose(datab);
	give_command();
}

//show detailed data on student with particular id
details()
{
	char f_name[20],m_name[20],l_name[20],b_group[4],contact[10],email[30],g_contact[10],a_class[10],section[3],desc[20];
	int due,S_ID;
	int id;
	char in[11],ID[20]="data/";
	printf("Enter id of the student:\t");
	scanf("%d",&id);
	
	//convert int to char to search for file
	itoa(id,in,10);
	strcat(ID,in);
	strcat(ID,".txt");
	
	FILE *file;
		if((file=fopen(ID,"r"))!=NULL)
	{
		int i=0;
		while((fscanf(file,"%s %s %s %d %s %s %s %s %s %c %d %[^\n]s",f_name,m_name,l_name,&S_ID,b_group,contact,email,g_contact,a_class,section,&due,desc))!=EOF)
		{
			printf("\nFirst Name: %s\n",f_name);
			printf("Middle Name: %s\n",m_name);
			printf("Last Name: %s\n",l_name);
			printf("Student ID: %d\n",S_ID);
			printf("Blood Group: %s\n",b_group);
			printf("Contact: %s\n",contact);
			printf("Email: %s\n",email);
			printf("Gaurdian's Contact: %s\n",g_contact);
			printf("Class: %s\n",a_class);
			printf("Section: %c\n",section[0]);
			printf("Due fee: %d\n",due);
			printf("Description: %s",desc);
			//maybe needs address
			printf("\n\n\n");
		}
	}
	else
	{
		printf("\nNO DATA AVAILABLE.");
	}
	fclose(file);
	give_command();
}

//deleting record
remove_data()
{
	//then so on;
	char file1[] ="data/data_table.txt";
    char file2[] ="data/temp.txt";
    char number[11],ID[20]="data/";
    int temp;
	printf("Enter id of student you wish to delete:\t");
    scanf("%s", number);
    strcat(ID,number);
    strcat(ID,".txt");
    remove(ID);
    int num=atoi(number);
    num-=2021000;
    num--;
    FILE *fptr1, *fptr2;
	fptr1 = fopen(file1,"r");
	fptr2 = fopen(file2, "w");
	char c;
	c=getc(fptr1);
	while(c!=EOF)
	{
		if(c=='\n')
		{
			temp++;
		}
		if(temp!=num)
		{
			fprintf(fptr2,"%c",c);
		}
		c=getc(fptr1);
	}
	fclose(fptr1);
	fclose(fptr2);
	remove(file1);
	rename(file2,file1);
}

update()
{
	char file1[] ="data/data_table.txt";
    char file2[] ="data/temp.txt";
	struct data{
		char f_name[30];
		char l_name[30];
		char b_group[4];
		char contact[10];
		int id;
		int due;
		char a_class[10];
		char section[4];
		char g_contact[10];
	};	
	struct data info[10];
	int num,update;
	FILE * fptr,*fptr1,*fptr2,*fptr3;
	fptr=fopen(file1,"r");
	int STD,j=1,i=0;
	char indi[20]="data/",S_ID[20];
	printf("Enter ID of student whose data you want you alter:\t");
	scanf("%s",S_ID);
	STD=atoi(S_ID);
	strcat(indi,S_ID);
	strcat(indi,".txt");
	if((fptr2=fopen(indi,"r"))!=NULL)
	{
		//for indivisual data
		char fi_name[20],mi_name[20],la_name[20],bl_group[4],m_contact[10],memail[30],ga_contact[10],b_class[10],Asection[3],Desc[20];
		int due,SID=STD;
		//enter data
		printf("\nFirst Name: \t");
		scanf("%s",fi_name);
		printf("Middle Name: \t");
		scanf("%s",mi_name);
		printf("Last Name: \t");
		scanf("%s",la_name);
		printf("Blood Group: \t");
		scanf("%s",bl_group);
		printf("Contact: \t");
		scanf("%s",m_contact);
		printf("Email: \t");
		scanf("%s",memail);
		printf("Gaurdian's Contact: \t");
		scanf("%s",ga_contact);
		printf("Class: \t");
		scanf("%s",b_class);
		printf("Section: \t");
		scanf("%s",Asection);
		printf("Due fee: \t");
		scanf("%d",&due);
		printf("Description: ");
		scanf("%s",Desc);
		//end
		char filename[20]="data/indi.txt";
		fptr3=fopen(filename,"wb");
		fprintf(fptr3,"%s %s %s %d %s %s %s %s %s %s %d %s",fi_name,mi_name,la_name,SID,bl_group,m_contact,memail,ga_contact,b_class,Asection,num,Desc);
		fclose(fptr2);
		fclose(fptr3);
		remove(indi);
		rename(filename,indi);
		//for main database
		STD-=2021000;
		while(fscanf(fptr,"%d %s %s %s %s %s %s %s %d\n",&info[i].id,info[i].f_name,info[i].l_name,info[i].contact,info[i].b_group,info[i].a_class,info[i].section,info[i].g_contact,&info[i].due)!=EOF)
		{
			fptr1=fopen(file2,"a");
			if(STD==j)
			{
				info[i].id=(STD+2021000);
				strcpy(info[j].f_name,fi_name);
				strcpy(info[j].l_name,la_name);
				strcpy(info[j].b_group,bl_group);
				strcpy(info[j].contact,m_contact);
				info[j].due=due;
				strcpy(info[j].g_contact,ga_contact);
				strcpy(info[j].a_class,b_class);
				strcpy(info[j].section,Asection);
				if((strlen(info[i].f_name)+strlen(info[i].l_name))<14)
				{
					fprintf(fptr1,"%d %s %s %s %s %s (%s) %s %d\n",info[i].id,info[j].f_name,info[j].l_name,info[j].contact,info[j].b_group,info[j].a_class,info[j].section,info[j].g_contact,info[j].due);
				}
				else
				{
					char* abb_name = info[i].f_name;
					fprintf(fptr1,"%d %c. %s %s %s %s (%s) %s %d\n",info[j].id,info[j].f_name,info[j].l_name,info[j].contact,info[j].b_group,info[j].a_class,info[j].section,info[j].g_contact,info[j].due);
				}
			}
			else
			{
				fprintf(fptr1,"%d %s %s %s %s %s %.3s %s %d\n",info[i].id,info[i].f_name,info[i].l_name,info[i].contact,info[i].b_group,info[i].a_class,info[i].section,info[i].g_contact,info[i].due);
			}
			fclose(fptr1);
			i++;
			j++;
		}
		fclose(fptr);
		fclose(fptr1);
		remove(file1);
		rename(file2,file1);
	}
	else
	{
		printf("No data exist for given id number \a");
	}
	give_command();	
}

update_due()
{
	char file1[] ="data/data_table.txt";
    char file2[] ="data/temp.txt";
	struct data{
		char f_name[30];
		char l_name[30];
		char b_group[4];
		char contact[10];
		int id;
		int due;
		char a_class[10];
		char section[4];
		char g_contact[10];
	};	
	struct data info[10];
	int num,update;
	FILE * fptr,*fptr1,*fptr2,*fptr3;
	fptr=fopen(file1,"r");
	int STD,j=1,i=0;
	char indi[20]="data/",S_ID[20];
	printf("Enter ID of student whose payment you want to register:\t");
	scanf("%s",S_ID);
	STD=atoi(S_ID);
	strcat(indi,S_ID);
	strcat(indi,".txt");
	if((fptr2=fopen(indi,"r"))!=NULL)
	{
		//for main database
		STD-=2021000;
		while(fscanf(fptr,"%d %s %s %s %s %s %s %s %d\n",&info[i].id,info[i].f_name,info[i].l_name,info[i].contact,info[i].b_group,info[i].a_class,info[i].section,info[i].g_contact,&info[i].due)!=EOF)
		{
			//printf("\n%s\t%d,%d",info[i].contact,STD,j);
			num=info[i].due;
			if(STD==j)
			{
				printf("Update payment amount:\t");
				scanf("%d",&update);
				num-=update;
			}
			fptr1=fopen(file2,"a");
			fprintf(fptr1,"%d %s %s %s %s %s %s %s %d\n",info[i].id,info[i].f_name,info[i].l_name,info[i].contact,info[i].b_group,info[i].a_class,info[i].section,info[i].g_contact,num);
			fclose(fptr1);
			i++;
			j++;
		}
		fclose(fptr);
		fclose(fptr1);
		remove(file1);
		rename(file2,file1);
		//for indivisual data
		char fi_name[20],mi_name[20],la_name[20],bl_group[4],m_contact[10],memail[30],ga_contact[10],b_class[10],Asection[3],Desc[20];
		int due,SID;
		char filename[20]="data/indi.txt";
		fptr3=fopen(filename,"wb");
		fscanf(fptr2,"%s %s %s %d %s %s %s %s %s %c %d %s",fi_name,mi_name,la_name,&SID,bl_group,m_contact,memail,ga_contact,b_class,Asection,&due,Desc);
		due-=update;
		fprintf(fptr3,"%s %s %s %d %s %s %s %s %s %s %d %s",fi_name,mi_name,la_name,SID,bl_group,m_contact,memail,ga_contact,b_class,Asection,due,Desc);
		fclose(fptr2);
		fclose(fptr3);
		remove(indi);
		rename(filename,indi);
	}
	else
	{
		printf("No data exist for given id number \a");
	}
	give_command();	
}
