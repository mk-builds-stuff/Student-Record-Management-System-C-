#include"header.h"

int search(ST *,int);

void deleteNode(ST **ptr)
{	
	if((*ptr)==NULL){
		fprintf(stderr,"No records are added yet...\n");
		return;
	}

	int roll=search((*ptr),1);
	if(roll == 0)
    	return;

	char op;
	printf("Are you sure you wanna delete this record?(y/n)\n");
	scanf(" %c",&op);

	if(op=='n' || op=='N')
		return;
	else if(op=='y' || op=='Y'){
	
	ST *temp=(*ptr), *prev;
	while(temp!=NULL){
		if(roll==temp->roll){
			if(temp==(*ptr))
				(*ptr)=(*ptr)->next;
			else
				prev->next=temp->next;

			free(temp);
			printf("Successfully deleted the node\n");
			return;
		}
		else{
			prev=temp;
			temp=temp->next;
		}
	}
	
	printf("No data matched with given roll...\n");
	}
	else
		printf("Invalid option\n");
}
