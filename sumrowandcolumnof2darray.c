#include <stdio.h>
#include <stdlib.h>

int main()
{
    //initializing the variable i,j as counter variables, row and column of the table(array)
    int i,j,row, column;

    //prompting the user to input the values of row and column, row is entered first then you click enter to enter the column
    printf("Enter the number of rows followed by the number of column you wish to have in your table: ");
    scanf("%d%d", &row,&column);

    // declaring the table(array), the rowsum and columnsum variables to store the sum of row and column
    float Array[row][column];
    float rowsum[row];
    float columnsum[column];

    // Taking in the table(array) from the user which is entered row by row. assuming everyone knows how for loop works
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("row %d, column %d: ", i+1,j+1);
            scanf("%f", &Array[i][j]);
        }
    }

    printf("\n\n\n");//just give space inorder to print the table(array)

    //Printing the Table
    for(i=0;i<row;i++){
            rowsum[i] = 0.0;
        for(j=0;j<column;j++){
            printf("%.2f\t", Array[i][j]);
            rowsum[i] += Array[i][j];
            /*for rowsum, during the first i iteration, we have rowsum[0] to. so during the j iterations,
            we continuesly increment the row[0] value with the current value from the table within thesame row.
            Same thing applies during the next i and j iterations. take note 0 inside rowsum above is the current 
            value of i during iterations
            */  
            columnsum[j] += Array[i][j];//Same goes for columnsum.
        }
        printf("|%.2f", rowsum[i]); //Here we print the current row sum before going to print the next row and its sum as well

        printf("\n");
    }

printf("-------------------\n");
        for(j=0;j<column;j++){
            printf("%.2f\t", columnsum[j]); //This is where we print column sum
        }
    return 0;
}
