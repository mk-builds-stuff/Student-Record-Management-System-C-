#include "header.h"

int main()
{	
	int rollno;
	ST *hptr=NULL;	
	
	loadRecords(&hptr);

	char op;
	do{
		printf("\n\tSTUDENT RECORD MANAGEMENT SYSTEM\n");
		printf("\n");
		printf("\t[A] Add a New Student Record\n");
		printf("\t[M] Modify a Student Record\n");
		printf("\t[S] Show All Student Records\n");
		printf("\t[D] Delete a Student Record\n");
		printf("\t[T] Sort Student Records\n");
		printf("\t[V] Save Student Records\n");
		printf("\t[E] Exit Program\n");
		
		scanf(" %c",&op);
		if(op>='a' && op<='z')
			op^=32;//For making op case-insensitive
		switch(op){
			case 'A':
				rollno=findNextRollNo(hptr);
				add(&hptr,rollno);
				break;
			case 'M':
				mod(&hptr);
				break;
			case 'S':
				print(hptr);
				break;
			case 'D':
				deleteNode(&hptr);
				break;
			case 'T':
				sort(hptr);
				break;
			case 'V':
				save(hptr);
				break;
			case 'E':{ 
				char choice;
				printf("Select:\n");
				printf("[s] Save and Exit\n");
				printf("[e] Exit without Saving\n");
				scanf(" %c",&choice);
				if(choice=='S' || choice=='s'){
					save(hptr);
					op=0;
				}else if(choice=='E' || choice=='e')
					op=0;
				else
					printf("Invalid Choice\n");
				break;
			}
			default:
				printf("Invalid option");
		}

	}while(op!=0);

	 ST *temp;

    while(hptr!=NULL){
        temp=hptr;
        hptr=hptr->next;
        free(temp);
    }
}	
