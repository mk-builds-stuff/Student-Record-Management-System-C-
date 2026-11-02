#include "header.h"

int count(ST *ptr){
	int count=0;

	while(ptr!=NULL){
		count++;
		ptr=ptr->next;
	}
	return count;
}
int my_strcmp(char *s1, char *s2){

    while(*s1 && *s2){

        char ch1=*s1;
        char ch2=*s2;

        if(ch1>='A' && ch1<='Z')
            ch1+=32;

        if(ch2>='A' && ch2<='Z')
            ch2+=32;

        if(ch1!=ch2)
            return ch1-ch2;

        s1++;
        s2++;
    }
    return *s1-*s2;
}

void sort(ST *ptr){
	
	if(ptr==NULL){
    	fprintf(stderr,"No records to sort yet...\n");
   		return;
	}

	int size=count(ptr);

	ST **arr=(ST **)malloc(size*sizeof(ST *));
	
	for(int i=0;i<size;i++){
		arr[i]=ptr;
		ptr=ptr->next;
	}
	
	char op;
	printf("How do you want the array sorted?\n");
	printf("[N] by Name(A-Z)\n");
	printf("[P] by Percentage(high-low)\n");
	scanf(" %c",&op);
	
	if(op=='n' || op=='p')
		op^=32;
	
	if(op!='N' && op!='P'){
	    printf("Invalid option\n");
		free(arr);
    	return;
	}

	int i,j;

	for(i=0;i<size;i++){
		for(j=0;j<size-1-i;j++){
			int swap=0;
			switch(op){
				case 'N':
					if(my_strcmp(arr[j]->name,arr[j+1]->name) >0)
						swap=1;
					break;
				case 'P':
					if(arr[j]->percent < arr[j+1]->percent)
						swap=1;
					break;
			}

			ST *temp;
			if(swap){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}

		}
	}
	printf("Sorted Records:\n");

	printf("|\tRoll\t|\tName\t|\tPercent\t|\n");
	
	for(int i=0;i<size;i++){
		printf("|\t%d\t| %s\t|\t%.2f\t|\n",arr[i]->roll,arr[i]->name,arr[i]->percent);
	}

	free(arr);
}
