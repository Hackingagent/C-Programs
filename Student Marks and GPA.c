#include<stdio.h>

 typedef struct student{
char Matricule_Number[20];
char name[20];
struct subject{;
               char ccode[10];
               char cname[100];
               int mark;
               }sub[3];
               int total;
               float gpa;
}student;

void create(){
  student *s;
  FILE *fp;
  int n,i,j,a=4,b=3,c=2,d=1,f=0,gpa,total_grade;
  printf("Enter how many students you want : ");
  scanf("%d", &n);

  s = (student*)calloc(n, sizeof(student));
  fp = fopen("mystudent.txt","w");

  for(i=0;i<n;i++){
        s[i].total = 0;
  s[i].gpa = 0;
    printf("Enter Matricule_Number: ");
    scanf("%s", &s[i].Matricule_Number);
    fflush(stdin);
    printf("Enter Name of Student : ");
    scanf("%[^\n]s", s[i].name);
    for(j=0;j<3;j++){
            printf("Enter course code : ");
            scanf("%s", &s[i].sub[j].ccode);
            printf("Enter course name : ");
            scanf("%s", &s[i].sub[j].cname);
        printf("Enter Mark of course : ", j+1);
        scanf("%d", &s[i].sub[j].mark);
        s[i].total += s[i].sub[j].mark;
         if(s[i].sub[j].mark<=100 && s[i].sub[j].mark>=80){
    printf(" Grade : A\n",a);
         }
else
if(s[i].sub[j].mark>=60 && s[i].sub[j].mark<=79){
    printf(" Grade : B\n",b);
}
else
if(s[i].sub[j].mark>=40 && s[i].sub[j].mark<=59){
    printf(" Grade : C\n",c);
}
else
if(s[i].sub[j].mark>=20 && s[i].sub[j].mark<=39){
    printf(" Grade : D\n",d);
}
else
    if(s[i].sub[j].mark>=0 && s[i].sub[j].mark<=19){
            printf(" \nF",f);

  }
else
{
    printf("Error");

}
 total_grade+=a,b,c,d,f;
 s[i].gpa = total_grade/3.0;
    }



    fwrite(&s[i], sizeof(student),1,fp);
  }
  fclose(fp);
}
void display(){
    int j;
  student s1;
  FILE *fp;
  fp = fopen("mystudent.txt","r");
  while(fread(&s1,sizeof(student),1,fp))
  {
      printf("\n\n%-5s%-20s",s1.Matricule_Number, s1.name);
      for(j=0;j<3;j++){
             printf("\n%-5s%-12s[%-d]",s1.sub[j].ccode, s1.sub[j].cname,s1.sub[j].mark);

      }
      printf("\nTotal : ");
      printf("%5d",s1.total);
      printf("\nGPA : ");
      printf("%.1f",s1.gpa);
  }


    fclose(fp);

}
void append(){
 student *s;
  FILE *fp;
  int n,i,j,a=4,b=3,c=2,d=1,gpa,f=0,total_grade;
  printf("Enter how many students you want : ");
  scanf("%d", &n);

  s = (student*)calloc(n, sizeof(student));
  fp = fopen("mystudent.txt","a");

  for(i=0;i<n;i++){
        s[i].total = 0;
  s[i].gpa = 0;
    printf("Enter Matricule_Number: ");
    scanf("%s", &s[i].Matricule_Number);
    fflush(stdin);
    printf("Enter Name of Student : ");
    scanf("%[^\n]s", s[i].name);
    for(j=0;j<3;j++){
            printf("Enter course code : ");
            scanf("%s", &s[i].sub[j].ccode);
            printf("Enter course name : ");
            scanf("%s", &s[i].sub[j].cname);
        printf("Enter Mark of course : ", j+1);
        scanf("%d", &s[i].sub[j].mark);
        s[i].total += s[i].sub[j].mark;

          if(s[i].sub[j].mark<=100 && s[i].sub[j].mark>=80){
    printf(" Grade : A\n",a);
         }
else
if(s[i].sub[j].mark>=60 && s[i].sub[j].mark<=79){
    printf(" Grade : B\n",b);
}
else
if(s[i].sub[j].mark>=40 && s[i].sub[j].mark<=59){
    printf(" Grade : C\n",c);
}
else
if(s[i].sub[j].mark>=20 && s[i].sub[j].mark<=39){
    printf(" Grade : D\n",d);
}
else
    if(s[i].sub[j].mark>=0 && s[i].sub[j].mark<=19){
            printf(" Grade : F\n",f);

  }
else
{
    printf("Error");

}
 total_grade += a,b,c,d,f;
    s[i].gpa = total_grade/3.0;
    }

    fwrite(&s[i], sizeof(student),1,fp);
  }
  fclose(fp);
}

void noofrec(){
student sl;
FILE *fp;
fp = fopen("mystudent.txt","r");
fseek(fp,0,SEEK_END);
int n = ftell(fp)/sizeof(student);
printf("\n\n NO OF RECORDS = %d",n);
fclose(fp);

}
void search(){
  int j,found=0;
  char Matricule_Number[20];
  student s1;
  FILE *fp;
  fp = fopen("mystudent.txt","r");
  printf("Enter Matricule Number to search : ");
  scanf("%s",&s1.Matricule_Number);
  while(fread(&s1,sizeof(student),1,fp))
  {
      if(s1.Matricule_Number == s1.Matricule_Number){
            found=1;
      printf("\n%-5s%-20s",s1.Matricule_Number, s1.name);
      for(j=0;j<3;j++){
             printf("\n%-5s%-12s[%-d]",s1.sub[j].ccode, s1.sub[j].cname,s1.sub[j].mark);

      }
      printf("\nTotal : ");
      printf("%5d",s1.total);
      printf("\nPercentage");
      printf("%7.2f",s1.gpa);
      }
  }
  if(!found)
    printf("\nRecord not found\n");


    fclose(fp);
}

void update(){
  student s1;
  FILE *fp, *fp1;
  int j,found=0,a=4,b=3,c=2,d=1;
  char Matricule_Number[20];
  fp = fopen("mystudent.txt","r");
  fp1 = fopen("temp.txt","w");
  printf("Enter Matricule_Number to update : ");
  scanf("%s",&s1.Matricule_Number);
  while(fread(&s1,sizeof(student),1,fp))
  {
      if(s1.Matricule_Number ==Matricule_Number){
            s1.total = 0;
      s1.gpa = 0;
            found=1;
 fflush(stdin);
    printf("Enter New Name of Student : ");
    scanf("%[^\n]s", s1.name);
    for(j=0;j<3;j++){
            printf("Enter course code : ");
            scanf("%s", &s1.sub[j].ccode);
            printf("Enter New course name : ");
            scanf("%s", &s1.sub[j].cname);
        printf("Enter new Mark of course : ", j+1);
        scanf("%d", &s1.sub[j].mark);
        s1.total += s1.sub[j].mark;
    }
    s1.gpa = (a+b+c+d)/ 3.0;
  }
  fwrite(&s1,sizeof(student),1,fp1);
  }
  fclose(fp);
  fclose(fp1);
if(found){
    fp1 = fopen("temp.txt","r");
    fp = fopen("mystudent.txt","w");

    while(fread(&s1,sizeof(student),1,fp1)){
        fwrite(&s1,sizeof(student),1,fp);
    }

    fclose(fp);
    fclose(fp1);
}
    printf("\n\nRecords not Found\n");

    fclose(fp);
}

void delete_rec(){
  student s1;
  FILE *fp, *fp1;
  int j,found=0;
  char Matricule_Number[20];
  fp = fopen("mystudent.txt","r");
  fp1 = fopen("temp.txt","w");
  printf("Enter Matricule_Number to delete : ");
  scanf("%s",&Matricule_Number);
  while(fread(&s1,sizeof(student),1,fp))
  {
      if(s1.Matricule_Number == Matricule_Number){
            found=1;
      }
      else
  fwrite(&s1,sizeof(student),1,fp1);
  }
  fclose(fp);
  fclose(fp1);
if(found){
    fp1 = fopen("temp.txt","r");
    fp = fopen("mystudent.txt","w");

    while(fread(&s1,sizeof(student),1,fp1)){
        fwrite(&s1,sizeof(student),1,fp);
    }

    fclose(fp);
    fclose(fp1);
}
    printf("\n\nRecords not Found\n");

    fclose(fp);
}


int main(){
    int ch;
    do{

        printf("\n1.CREATE");
        printf("\n2.DISPLAY");
        printf("\n3.APPEND");
        printf("\n4.NO OF RECORDS");
        printf("\n5.SEARCH");
        printf("\n6.UPDATE");
        printf("\n7.DELETE");
        printf("\n0.EXIT");

        printf("\nEnter your choice :");
        scanf("%d", &ch);

        switch(ch){
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
        noofrec();
        break;
    case 5:
        search();
        break;
    case 6:
        update();
        break;
    case 7:
        delete_rec();
        break;

    }
    }
    while(ch!=0);

return 0;


}

