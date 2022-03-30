#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct patient
{
	char name[256];
	char sex[10];
	char number[15];
	int age;
	int token;
};

struct patient *patient_db[100];

int patient_count=0;
int last_patient=0;

void Add_patient()
{
	char name[256];
	char sex[10];
	char number[15];
	int age;
	int i=0;
	
	if(patient_count>100)
	{
		printf("\n**Patient DataBase Full**\n");
	}

	printf("Enter the Name , Sex , Age and Number \n");
	scanf("%s%s%d%s",name,sex,&age,number);

	patient_db[patient_count]=malloc(sizeof(struct patient));

	strcpy(patient_db[patient_count]->name,name);
	strcpy(patient_db[patient_count]->sex,sex);
	strcpy(patient_db[patient_count]->number,number);
	patient_db[patient_count]->age=age;
	patient_db[patient_count]->token=patient_count;
	patient_count++;
	return;
}

void Display_db()
{
	int i=0;

	if(patient_count==0)
	{
		printf("List Empty\n");
		return;
	}
	printf("\nName\t\tGender\tAge\tNumber\t\tToken\n");
	for(i=0;i<patient_count;i++)
	{
		printf("%s\t\t%s\t%d\t%s\t\t%d\n",
			patient_db[i]->name,
	      		patient_db[i]->sex,
			patient_db[i]->age,
			patient_db[i]->number,
			patient_db[i]->token );		
	}


}


void Send_patient()
{
}
void main ()
{
	int option=0;
	while(1)
	{
		printf("\n Enter your Option:\n 1. Add Patient\n 2. Display DB\n 3.Send Patient to Doctor\n 4. Exit\n");
		scanf("%d",&option);

		switch (option)
		{
			case 1:Add_patient();
				break;
			case 2:Display_db();
				break;
			case 3:Send_patient();
				break;
			case 4:exit(0);
			default:
				printf("\nEnter vaid option\n");
		}
	}
	


}


