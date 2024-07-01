#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char Matricule_Number[20];
	char Name[40];
}student;


void create(){
	student *s;
	FILE *fp;
	int n,i;
	printf("How Many student do you want to record: ");
	scanf("%d", &n);
	
	s = (student*)calloc(n, sizeof(student));
	
	fp = fopen("Student.txt", "w");
	
	for(i=0;i<n;i++){
		printf("Enter the Matricule Number of student %d: ", i+1);
		scanf("%s", &s[i]);
		fflush(stdin);
		printf("Enter the name of student %d: ", i+1);
		scanf("%s",&s[i].Name);
		
		fwrite(&s[i],sizeof(student),1,fp);
		printf("\n");
	}
	
	fclose(fp);
}
void display(){
	student s1;
	FILE *fp;
	
	fp = fopen("Student.txt", "r");
	printf("\nMATRICULE NUMBER \t\t NAMES");
	printf("\n---------------- \t\t -----");
	while(fread(&s1,sizeof(student),1,fp)){
		printf("\n%s.......................%s\n",s1.Matricule_Number,s1.Name);
	}
	printf("\n");
	
	
	fclose(fp);
}
void append(){
	
		student *s;
	FILE *fp;
	int n,i;
	printf("How Many student do you want to add: ");
	scanf("%d", &n);
	
	s = (student*)calloc(n, sizeof(student));
	
	fp = fopen("Student.txt", "a");
	
	for(i=0;i<n;i++){
		printf("Enter the Matricule Number of student %d: ", i+1);
		scanf("%s", &s[i]);
		fflush(stdin);
		printf("Enter the name of student %d: ", i+1);
		scanf("%s",&s[i].Name);
		
		fwrite(&s[i],sizeof(student),1,fp);
		printf("\n");
	}
	
	fclose(fp);

}
void no_of_records(){
	student s1;
	FILE *fp;
	fp = fopen("Student.txt", "r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	printf("\nNumber of records = %d\n",n);
	fclose(fp);
}
void search(){
	student s1;
	FILE *fp;
	int i;
	char mn[20];
	fp = fopen("Student.txt", "r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	rewind(fp);
	printf("Enter Matricule Number to search: ");
	scanf("%s", &mn);
	printf("\nMATRICULE NUMBER \t\t NAMES");
	printf("\n---------------- \t\t -----");
	
	while(fread(&s1,sizeof(student),1,fp)){
		
		if(s1.Matricule_Number == mn){
			printf("\n%s.......................%s\n",s1.Matricule_Number,s1.Name);
		}
		else{
			break;
		}
	}
	
	fclose(fp);
}

void Delete(){
	student s1;
	FILE *fp, *fp1;
	char mn[20];
	int found = 0;
	fp = fopen("Student.txt","r");
	fp1 = fopen("temp.txt", "w");
	printf("Enter the Matricule Number to Delete: ");
	scanf("%s", &mn);
	while(fread(&s1,sizeof(student),1,fp)){
		if(s1.Matricule_Number == mn){
			found =1;
			
		}
		else
			fwrite(&s1,sizeof(student),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found){
		fp1 = fopen("temp.txt","r");
		fp = fopen("Student.txt","w");
		
		while(fread(&s1,sizeof(student),1,fp1)){
			fwrite(&s1,sizeof(student),1,fp);
		}
	fclose(fp);
	fclose(fp1);
	}

}

void b_sort_by_name(){
	student *s, s1;
	FILE *fp;
	int i,j;
	fp = fopen("Student.txt", "r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	s=(student*)calloc(n,sizeof(student));
	rewind(fp);
	for(i=0;i<n;i++){
		fread(&s[i],sizeof(student),1,fp);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(s[i].Name,s[j].Name)>0){
				s1 = s[i];
				s[i] = s[j];
				s[j] = s1;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("\n%s.......................%s\n",s[i].Matricule_Number,s[i].Name);
	}
	
	fclose(fp);
}
void b_sort_by_matricle(){
	student *s, s1;
	FILE *fp;
	int i,j;
	fp = fopen("Student.txt", "r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	s=(student*)calloc(n,sizeof(student));
	rewind(fp);
	for(i=0;i<n;i++){
		fread(&s[i],sizeof(student),1,fp);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(s[i].Matricule_Number,s[j].Matricule_Number)>0){
				s1 = s[i];
				s[i] = s[j];
				s[j] = s1;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("\n%s.......................%s\n",s[i].Matricule_Number,s[i].Name);
	}
	
	fclose(fp);
}

void s_sort_by_matricle(){
	student *s, s1;
	FILE *fp;
	int i,j, min_idx;
	fp = fopen("Student.txt", "r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	s=(student*)calloc(n,sizeof(student));
	rewind(fp);
	for(i=0;i<n;i++){
		fread(&s[i],sizeof(student),1,fp);
	}
	char minstr[n];
	for(i=0;i<n;i++){
		min_idx = i;
		strcpy(minstr,s[i].Matricule_Number);
		for(j=i+1;j<n;j++){
			if(strcmp(minstr,s[j].Matricule_Number)>0){
				strcpy(minstr,s[j].Matricule_Number);
				min_idx = j;
			}
		}
		
		if(min_idx != i){
			char temp[n];
			strcpy(temp,s[i].Matricule_Number);
			strcpy(s[i].Matricule_Number,s[min_idx].Matricule_Number);
			strcpy(s[min_idx].Matricule_Number,temp);
		}
	}
	for(i=0;i<n;i++){
		printf("\n%s.......................%s\n",s[i].Matricule_Number,s[i].Name);
	}
}

int main(){
	int choice;
	do{
		printf("\n___________________________________________________________________________");
		printf("\n................WELCOME MY STUDENT MANAGEMENT SYSTEM....................");
		printf("\n1.CREATE");
		printf("\n2.DISPLAY");
		printf("\n3.APPEND");
		printf("\n4.NUMBER OF RECORDS");
		printf("\n5.SEARCH");
		printf("\n6.DELETE");
		printf("\n7.BUBBLE SORT BY NAME");
		printf("\n8.BUBBLE SORT BY MATRICULE NUMBER");
		printf("\n9.SELECTION SORT BY MATRICULE NUMBER");
		printf("\n0.Exit");
		
		printf("\n What do you Wish to do: ");
		scanf("%d", &choice);
		printf("\n_________________________________________________________________________________\n");
		
			switch(choice){
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			append();
		break;
		case 4:
			no_of_records();
			break;
		case 5:
			search();
			break;
		case 6:
			Delete();
			break;
		case 7:
			b_sort_by_name();
			break;
		case 8:
			b_sort_by_matricle();
			break;
		case 9:
			s_sort_by_matricle();
			break;
			
		}
		
	}while(choice!=0);
	
	return 0;
}
