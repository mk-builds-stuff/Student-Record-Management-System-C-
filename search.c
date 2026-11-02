#include "header.h"

int count(ST *);
int my_strcmp(char *,char *);

int search(ST *ptr,int mode){
	
	if(ptr==NULL){
 		printf("No records available to search...\n");
    	return 0;
	}

	char ch;
	switch(mode){
		case 1:
			printf("Search by method:\n");
			printf("[R] by Roll no.\n");
			printf("[N] by Name\n");
			break;
			
		case 2:
			printf("Search by method:\n");
			printf("[R] by Roll no.\n");
			printf("[N] by Name\n");
			printf("[P] by Percentage\n");
			break;
	}
	scanf(" %c",&ch);
	
	int size=count(ptr);
	
	int arr[size],i=0;

	int flag=0,selectedRoll=0;

	if(ch>='a' && ch<='z')
		ch^=32;
	switch(ch){
		case 'R':{
			int roll;
			printf("Enter the desired rollno:\n");
			scanf("%d",&roll);

			printf("|\tRoll\t|\tName\t|\tPercent\t|\n");

			while(ptr!=NULL){
				if(ptr->roll==roll){
					printf("|\t%d\t| %s\t|\t%.2f\t|\n",ptr->roll,ptr->name,ptr->percent);
					selectedRoll=ptr->roll;
					arr[i]=ptr->roll;
					i++;
					flag++;
				}
				ptr=ptr->next;
			}
			if(flag==0){			
				printf("No Records in this roll no...\n");
				return 0;
			}
		}break;
		case 'N':{
			char name[20];
			printf("Enter the desired name:\n");
			scanf(" %19[^\n]",name);
			
			printf("|\tRoll\t|\tName\t|\tPercent\t|\n");

			while(ptr!=NULL){
				if(my_strcmp(name,ptr->name)==0){
					printf("|\t%d\t| %s\t|\t%.2f\t|\n",ptr->roll,ptr->name,ptr->percent);
					selectedRoll=ptr->roll;
					arr[i]=ptr->roll;
					i++;
					flag++;
				}
				ptr=ptr->next;
			}
			if(flag==0){			
				printf("No Records in this name...\n");
				return 0;
			}
		}break;
		case 'P':{
			float percent;
			printf("Enter the desired percent:\n");
			scanf("%f",&percent);

			printf("|\tRoll\t|\tName\t|\tPercent\t|\n");
			
			while(ptr!=NULL){
				if(ptr->percent==percent){
					printf("|\t%d\t| %s\t|\t%.2f\t|\n",ptr->roll,ptr->name,ptr->percent);	
					selectedRoll=ptr->roll;
					arr[i]=ptr->roll;
					i++;
					flag++;
				}
				ptr=ptr->next;
			}
			if(flag==0){			
				printf("No Records in this percentage...\n");
				return 0;
			}
		}break;
		default:
			   printf("Invalid choice\n");
			   return 0;
	}
	


	if(flag>1){
		printf("Which roll no. you want to select to proceed?\n");
		scanf("%d",&selectedRoll);
	}
	for(i=0;i<flag;i++){
		if(arr[i]==selectedRoll)
			break;
	}

	if(i==flag){
		printf("Invalid Choice\n");
		return 0;
	}

	return selectedRoll;
}

