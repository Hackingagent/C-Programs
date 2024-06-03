#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char ID[20];
	char Name[40];
}Family;

typedef struct{
	char ID[20];
	char Month[40];
    int Amount;
    int Day;
}Revenue;


void AddFamilyMember(){
    Family *f;
	FILE *fp;
	int n,i;
	printf("How Many Family Members do you wish to add: ");
	scanf("%d", &n);
	
	f = (Family*)calloc(n, sizeof(Family));
	
	fp = fopen("Family.txt", "a");
	
	for(i=0;i<n;i++){
		printf("Enter ID of Member %d (Type ID in Capital Letters e.g (FAM3)) : ", i+1);
		scanf("%s", &f[i]);
		fflush(stdin);
		printf("Enter Name of Member %d: ", i+1);
		scanf("%s",&f[i].Name);
		
		fwrite(&f[i],sizeof(Family),1,fp);
		printf("\n");
	}
	
	fclose(fp);
}


void DisplayFamilyMembers(){
    Family f1;
	FILE *fp;
	
	fp = fopen("Family.txt", "r");
	printf("\nID\t\t\t NAMES\n");
	while(fread(&f1,sizeof(Family),1,fp)){
		printf("\n%s.....................%s\n",f1.ID,f1.Name);
	}
	printf("\n");
	
	
	fclose(fp);
}



void AddRevenue(){
    Family f1;
    Revenue *r;
	FILE *fp;
    FILE *fp1;

    int found = 1;
    int  counter, n=1;
    char testId[20];
	
	r = (Revenue*)calloc(n, sizeof(Revenue));
	
	fp = fopen("Revenue.txt", "a");
    fp1 = fopen("Family.txt", "r");

    printf("Enter ID (Type ID in Capital Letters e.g FAM1): ");
    scanf("%s", &testId);
    

    while(fread(&f1,sizeof(Family),1,fp1)){
        if(strcmp(f1.ID, testId) == 0){

            for(counter=0;counter<n;counter++){
                
                strcpy(r[counter].ID, testId);
                fflush(stdin);
                printf("Enter Month (Start every Month with a Capital Letter e.g January): ");
                scanf("%s", &r[counter].Month);
                printf("Enter Day (eg 21): ");
                scanf("%d", &r[counter].Day);
                printf("Enter Amount (eg 2000): ");
                scanf("%d", &r[counter].Amount);

                fwrite(&r[counter],sizeof(Revenue),1,fp);
                printf("\n");

                break;
            }
        }else{
            found = 0;
        }
	}

    if(!found){
        int try;
        printf("\n1.YES\n2.NO\n");
        printf("Member ID not Found Do you wish to try again (Type 1 or 2): ");
        scanf("%d", &try);
        if(try ==1){
            AddRevenue();
        }else {
            main();
        }
        
    }

   

	fclose(fp1);
	fclose(fp);
}

void DisplayRevenueForAParticularMonth(){

    Revenue r1;
	FILE *fp;

    char month[30];
    int notFound = 1;
    printf("Enter the Month you wish to View its Revenue (Start Every Month With A capital Letter): ");
    scanf("%s", &month);
	
	fp = fopen("Revenue.txt", "r");

    if(fp == NULL){
        printf("There are No Revenue Record");
        return 1;
    }

	printf("\nMEMBER'S ID \t\t DAY \t\t MONTH\t\t AMOUNT\n");
	while(fread(&r1,sizeof(Revenue),1,fp)){
        if(strcmp(r1.Month, month) == 0){
            printf("\n %s \t\t\t %d \t\t %s \t %d \n",r1.ID,r1.Day,r1.Month,r1.Amount);
            notFound = 0;
        }
        
		
	}

    if (notFound)
    {
        int try;
        printf("\n\n!!!!!!!!There's no Record For this Month!!!!!!!!!!!!!");
        printf("\n1.YES\n2.NO\n");
        printf("DO you wish to try A different Month (type 1 or 2):");
        scanf("%d", &try);

        if(try == 1){
            DisplayRevenueForAParticularMonth();
        }else{
            main();
        }

    }
    
	printf("\n");
	
	
	fclose(fp);

}

void HighestRevenue(){

    int found = 1;
    char month[30];
    int m =0, total =0;
    char name[20];
    char id[20];
    printf("Enter the Month to View the Person with the highest Income (Start the month with a Capital Letter e.g Janaury) ");
    scanf("%s", &month);


    Family f1;
    Revenue r1;

    FILE *fp;
    FILE *fp1;

    fp1 = fopen("Revenue.txt", "r");
    fp = fopen("Family.txt", "r");

    while(fread(&f1, sizeof(Family), 1, fp)){
        m =0;
        while (fread(&r1, sizeof(Revenue), 1, fp1))
        {
            if (strcmp(r1.Month, month) == 0){
                if(strcmp(f1.ID, r1.ID) == 0){
                    m += r1.Amount;
                    
                }
 
            }else{
                found = 0;
            }
        }
        if(total < m){
            total = m;
            strcpy(name, f1.Name);
            strcpy(id, f1.ID);
        }
        printf("\n");

        fseek(fp1, 0,SEEK_SET);
    }

    if(!found){
        int try;
        printf("\n1.YES\n2.NO\n");
        printf("Wrong Input Month Do you wish to try Again (type 1 or 2):");
        scanf("%d", &try);

        if(try == 1){
            HighestRevenue();
        }else{
            main();
        }

    }else{
        printf("Member with Highest Revenue for the month: %s\n", month);
        printf("%s-------%s--------%d", id,name,total);
    }

    

    
    fclose(fp);
    fclose(fp1);


}



int main(){

    int choice;
    do{
        printf("\n__________________________________________________________________________________");
        printf("\n......................WELCOME TO FAMILY REVENUE MANAGEMENT SYSTEM................");
        printf("\n1. ADD FAMILY MEMBER");
        printf("\n2. DISPLAY MEMBERS");
        printf("\n3. ADD REVENUE");
        printf("\n4. DISPLAY REVENUE FOR A PARTICULAR MONTH");
        printf("\n5. HIGHEST REVENUE OF THE MONTH");


        printf("\n\n0. EXIT");

        printf("\n What do you wish to do: ");
        scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        AddFamilyMember();
    break;
    case 2:
        DisplayFamilyMembers();
    break;
    case 3:
        AddRevenue();
    break;
    case 4:
        DisplayRevenueForAParticularMonth();
    break;
    case 5:
        HighestRevenue();
    break;
    
    }
    }while(choice!=0);
    return 0;
    
}