#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	//info field
	int roll;
	char name[20];	
	float percent;
	//link field
	struct student *next; 
} ST;

int findNextRollNo(ST *);
int my_strcmp(char *,char *);
void add(ST **,int);
int search(ST *,int);
void loadRecords(ST **);
void save(ST *);
void deleteNode(ST **);
void print(ST *);
void mod(ST **);
int count(ST *);
void sort(ST *);
