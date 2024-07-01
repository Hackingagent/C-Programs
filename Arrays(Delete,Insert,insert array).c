#include <stdio.h>
#include <stdlib.h>

void Delete(){
	int Array[50], position, n, i;
	printf("Enter the number of elements to in put into the array: ");
	scanf("%d", &n);
	printf("Enter %d elements: \n", n);
	for(i=0;i<n;i++){
		scanf("%d", &Array[i]);
	}
	
	printf("Enter the position you wish to delete: ");
	scanf("%d", &position);
	
	if(position >= n){
		printf("Delete not possible!!");
	}
	else{
		for(i=position - 1;i<n;i++){
			Array[i] = Array[i+1];
		}
		
		printf("Resultant Array:\n ");
		for(i=0;i<n-1;i++){
			printf("%d\n", Array[i]);
		}
	}
	
}

void insert(){
	int array[50],x,n,position,i;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("Enter %d elements: \n", n);
	for(i=0;i<n;i++){
		scanf("%d", &array[i]);
	}
	
	printf("Enter the number you will like to insert: ");
	scanf("%d", &x);
	
	printf("Enter the position wher you love to insert %d: ", x);
	scanf("%d", &position);
	
	if(position > n){
		printf("Invalid Position!!");
	}
	else{
		n = n+1;
		for(i=n-1;i>position-1;i--){
			array[i+1]= array[i];
		}
		array[position-1] = x;
		printf("New array: \n");
		for(i=0;i<n;i++){
			printf("%d\n", array[i]);
		}
	}
	
}

void insert_array(){
	int n,m;
	int i, j;
	printf("Enter the number of elements for the main array: ");
	scanf("%d", &n);
	printf("Enter the number of elements for the array you want to insert: ");
	scanf("%d", &m);
    int Array1[n];
    int array2[m];
    printf("Enter the %d elements for the main array: \n", n);
    for(i=0;i<n;i++){
    	scanf("%d", &Array1[i]);
	}
	printf("Enter the %d elements for the array to insert: \n", m);
	for(i=0;i<m;i++){
		scanf("%d", &array2[i]);
	}
    int index, p;
    printf("Enter the position you want to insert into: ");
    scanf("%d", &p);
    index = p-1;
  

    for (i = m; i >= index; i--) {
        Array1[i+m] = Array1[i];
    }

    for (j = 0; j < n; j++) {
        Array1[index+j] = array2[j];
    }
    for (i = 0; i < n+m; i++) {
        printf("%d,", Array1[i]);
    }
    printf("\n");
}

int main() {
	int choice;
	do{
		printf("-------------------------------------------------------------------");
		printf("\n1.INSERT FUNCTION");
		printf("\n2.DELETE FUNCTION");
		printf("\n3.INSERTING ARRAY FUNCTION");
		printf("\n0.EXIT");
		printf("\n-------------------------------------------------------------------");
		printf("\nWhich function do you wish to call: ");
		scanf("%d", &choice);
		
	
	switch(choice){
	case 1:
		insert();
	break;
	case 2:
		Delete();
	break;
	case 3:
		insert_array();
	break;
		
	}
}while(choice!=0);
	return 0;
}
