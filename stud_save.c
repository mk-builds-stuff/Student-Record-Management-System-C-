#include "header.h"

void loadRecords(ST **ptr){
	
	FILE *fs=fopen("student.dat","r");

	if(fs==NULL){
		fprintf(stderr,"No prev data available to load...\n");
		return;
	}
	
	int roll;
	char name[20];
	float percent;
	while(fscanf(fs,"%d,%19[^,],%f",&roll,name,&percent)==3)
	{
    	ST *new=(ST *)malloc(sizeof(ST));

		new->roll = roll;
		strcpy(new->name, name);
		new->percent = percent;
		new->next=NULL;

		if((*ptr)==NULL)
			(*ptr)=new;
		else{
			ST *last=(*ptr);
			while(last->next!=NULL)
				last=last->next;
			last->next=new;
		}
	}
	fclose(fs);
}
void save(ST *ptr){

	FILE *fs=fopen("student.dat","w");

	if(ptr==NULL){
		fprintf(stderr,"No Student Records created yet...\n");
	}

	while(ptr!=NULL){
		fprintf(fs,"%d,%s,%.2f\n",ptr->roll,ptr->name,ptr->percent);
		ptr=ptr->next;
	}

	fclose(fs);
	printf("All Student Records saved successfully\n");

}
