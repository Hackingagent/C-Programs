#include <stdio.h>

void Input(){
int n;
printf("Enter the number of elements in the Array: ");
scanf("%d", &n);
printf("Enter %d Elements   NB 'CLICK ENTER BEFORE ENTERING THE NEXT NUMBER'", n);
int i, Array[n];
for(i=0;i<n;i++){
    scanf("%d", &Array[i]);
}
for(i=0;i<n;i++){
    printf("%d", Array[i]);
}

}

int main(){

    Input();
      
    return 0;
}