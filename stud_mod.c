#include"header.h"

int search(ST *,int);

void mod(ST **ptr){
	
	int roll=search((*ptr),2);

	if(roll==0)
		return;
	char op;
	printf("What do you wanna modify?\n");
	printf("[N] Name\n");
	printf("[P] Percentage\n");
	scanf(" %c",&op);
	
	if(op=='n' || op=='p')
		op^=32;

	char name[20];
	float percent;
	
	switch(op){
		case 'N':
			printf("Enter the Name to change:\n");
			scanf(" %19[^\n]",name);
			break;
		case 'P':
			printf("Enter the Percentage to change:\n");
			scanf("%f",&percent);
			break;
		default:{
			printf("Invalid Option\n");
			return;
			}
	}
	
	int flag=0;

	ST *last=(*ptr);

	while(last!=NULL){
		if(roll==last->roll){
			if(op=='N'){
				strcpy(last->name,name);
				flag=1;
				break;
			}
			else if(op=='P'){
				last->percent=percent;
				flag=1;
				break;
			}
		}
		last=last->next;
	}

	if(flag==1)
		printf("Student record modified successfully.\n");
	else
    	printf("No Matching record found...\n");
}
