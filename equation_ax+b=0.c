#include <stdio.h>

int main(){
    float a, b, x;

    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);

    if(a==0){ //if a=0, means the eqution will be b = 0 and the value of x can not be determined
        if(b==0){  // and if b=0 then the equation will be 0=0 and according to maths it has infinite roots
            printf("The Equation has infinite solutions");
        }else{ // This else means the b != 0 that is any other value except from 0 (in our case the value entered above)
            //normally in maths we cannot say 8 = 0 so in this scenario and to maths, the equation has no solutions
            printf("The Equation has no solution");
        }
    }else{ // Here the value of a is differnt from 0 which directly means we can look for the value of x
        x = -b/a; // formular to calculate x
        printf("The solution for the equation %.2fx + %.2f = 0 is x = %.2f", a,b,x);
    }

    return 0;
}