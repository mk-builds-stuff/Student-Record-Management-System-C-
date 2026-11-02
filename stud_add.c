#include "header.h"

//Find the smallest available positive roll no.
int findNextRollNo(ST *ptr)
{
	if(ptr==NULL)
		return 1;
	int prev=0,current=ptr->roll;
	while(ptr!=NULL){

		if((current-prev)>1)
			return prev+1;

		prev=ptr->roll;
		ptr=ptr->next;
		if(ptr != NULL)
			current=ptr->roll;
	}
	return prev+1;
}
void add(ST **ptr,int roll)
{
	
	ST *new=(ST *)malloc(sizeof(ST));
	
	new->roll=roll;

	printf("Enter Student Name:\n");
	scanf(" %19[^\n]",new->name);
	
	printf("Enter Student mark percentage:\n");
	scanf("%f",&new->percent);
	

	if((*ptr)==NULL || ((*ptr)->roll > new->roll)){
		new->next=(*ptr);
		(*ptr)=new;
	}
	else{
		ST *last=(*ptr);
		while((last->next!=NULL) && (last->next->roll < new->roll)){
			last=last->next;
		}
		new->next=last->next;
		last->next=new;
	}
}
