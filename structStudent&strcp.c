#include <stdio.h>
#include <string.h>

struct student{
    char name[20];
    char Matricule[20];
    int Age;
    int Telephone_Number;
};

PrintStudent(struct student  s){
    printf("Name: \t%s\n", s.name);
    printf("Matricule Number: \t%s\n", s.Matricule);
    printf("Age: \t%d\n", s.Age);
    printf("Telephone Number: \t%d\n", s.Telephone_Number);

}
int main{

struct student myInfo;
strcp(myInfo.name, "Your Name");
strcp{myInfo.Matricule, "My matricule Number"};
myInfo.Age = 000;
myInfo.Telephone = 0000;

PrintStudent(myInfo);

return 0;

}