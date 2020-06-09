/* 
		   LAB 4 Data Structure
By : 
  
  Nama : I Putu Krisna Dhaema Saputra
  NIM  : 2301924353
  
*/

//Header File
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


//Deklarasi Struct
struct info{
	char name[50];
	char type[50];
	char address[50];
	char phone[50];
	struct info* next;
};

struct info* top = NULL;

//Fungsi Push
int push(char*name, char*type, char*address, char*phone){
	
	struct info* temp = NULL;
	temp = (struct info*)malloc(sizeof(struct info));
	
	if(!temp){
		printf("\n\nHeap Overflow");
		return 0;
	}
	
	strcpy(temp->name,name);
	strcpy(temp->type,type);
	strcpy(temp->address,address);
	strcpy(temp->phone,phone);
	
	if(top == NULL){
		temp->next = NULL;
	}
	else{
		temp->next = top;
	}
	top = temp;
	return 0;
	
}

//Fungsi memunculkan main menu
int main_menu(){
	printf("INFORMATION ADMINISTRATOR\n");
	printf("=========================\n\n");
	printf("1. Information List\n");
	printf("2. Add (PUSH) New Information\n");
	printf("3. Delete (POP) Lastest Information\n");
	printf("4. Exit\n\n");
}

//Fungsi Memunculkan Information List	
void information(){
	struct info* temp = NULL;
	temp = (struct info*)malloc(sizeof(struct info));
	temp = top;
	int no =1;
	
	system("cls");
	
	printf("\t\t\t\t   --- INFORMATION LIST ---\n");
	printf("\n+-----+-----------------------------+----------------+------------------------+------------------+");
	printf("\n| No  | Name                        | Type           | Address                | Phone            |");
	printf("\n+-----+-----------------------------+----------------+------------------------+------------------+\n");
	while(temp != NULL){
		printf("| %-3d | %-27s | %-14s | %-22s |  %-14s  |\n",no,temp->name,temp->type,temp->address,temp->phone);
		temp = temp->next;
		no++;
	}
	printf("+-----+-----------------------------+----------------+------------------------+------------------+");
	getch();
}


//Fungsi menu ke 2 yaitu add (PUSH)
void add_info(){
	char name[100];
	char type[100];
	char address[100];
	char phone[100];
	
	system("cls");
	
	//input name
	do{
		system("cls");
		printf("Input Name of person/company/society [3..20]: ");
		gets(name);
		getch();
	
		if(strlen(name) < 3 || strlen(name) > 20){
			printf("\n\n  Name must be between 3 and 20 characters ");
			getch();
		}
		
	}while(strlen(name) < 3 || strlen(name) > 20);
	
	//Input type
	do{
		system("cls");
		printf("Input Name of person/company/society [3..20]: %s ",name); 
		
		printf("\n\nInput The Type of New Entry Name [person/company/society]: ");
	    gets(type);
		
		if(strcmp(type, "person") !=0 && strcmp(type, "company") !=0 && strcmp(type, "society") !=0){
			printf("\n      		Please choose appropriate type !\n The type of new entry name must be between person, company, or society.");
			getch();
		}
		
	}while(strcmp(type, "person") !=0 && strcmp(type, "company") !=0 && strcmp(type, "society") !=0);
	
	//input address
	do{
		system("cls");
		printf("Input Name of person/company/society [3..20]: %s ",name); 
		printf("\n\nInput The Type of New Entry Name [person/company/society]: %s ",type);
		
		printf("\n\nInput Address of New Entry Name [6...20]: ");
		gets(address);
		
		if(strlen(address) < 6 || strlen(address) > 20){
			printf("\n\n Address must be between 6 and 20 length. ");
			getch();
		}
		
	}while(strlen(address) < 6 || strlen(address) > 20);
	
	//Input Phone Number
	do{
		system("cls");
		printf("Input Name of person/company/society [3..20]: %s ",name); 
		printf("\n\nInput The Type of New Entry Name [person/company/society]: %s ",type);
		printf("\n\nInput Address of New Entry Name [6...20]: %s ",address);
		
		printf("\n\nInput Phone of New Entry Name [9...12]: ");
		gets(phone);
		
		if(strlen(phone) < 9 || strlen(phone) > 12){
			printf("\n\n Phone Number must be between 9 and 12 length. ");
			getch();
		}
	}while(strlen(phone) < 9 || strlen(phone) > 12);
	
	push(name,type,address,phone);
	
}
		
// Fungsi menu ke 3, Delete (POP)
void Delete(){
	char name[50];
	char type[50];
	struct info* temp = NULL;
	
	temp = (struct info*)malloc(sizeof(struct info));

	if(top == NULL){
		printf("\n\n There are no information available!");
		getch();
	}
	else{
		
		temp = top;
		strcpy(name,temp->name);
		strcpy(type,temp->type);
		top = top->next;
		temp->next = NULL;
		free(temp);
		
		printf("\n\n The recently added item %s < %s > is being deleted",name,type);
		getch();
	}
}

//fungsi main
int main(){
	int choice;
	
	
	do{ 
		system("cls");
		
		main_menu();	
		printf(">> Input your choice : ");
	    fflush(stdin);
		scanf("%d",&choice);
			
		switch (choice){
			case 1 :{
				information();
				break;
			}
			case 2 :{
				add_info();
				break;
			}
			case 3 :{
				Delete();
				break;
			}
	
    	}
    
    }while(choice !=4);
    
	system("cls");
 
	printf("\nThanks for Using this program");	


  	getch();
  	
  	return 0;
}

