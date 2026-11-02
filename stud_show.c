#include"header.h"

void print(ST *ptr){
	
	if(ptr==NULL){
		fprintf(stderr,"No records are added yet...\n");
		return;
	}

	printf("\t\tStudent Records:\t\t\n");
	printf("|\tRoll\t|\tName\t|\tPercent\t|\n");
	while(ptr!=NULL){
		printf("|\t%d\t| %s\t|\t%.2f\t|\n",ptr->roll, ptr->name, ptr->percent);
		ptr=ptr->next;
	}

}
