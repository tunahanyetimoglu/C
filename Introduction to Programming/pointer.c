#include <stdio.h>
#include <stdlib.h>

struct student{
  char name[20];
	char lastname[20];
	long age;
};
typedef struct student *StudentPointer;
int main(void){

struct student firstStudent = {"Tunahan","Yetimoglu",20};
*StudentPointer = &firstStudent;
printf("Name : %s\nLastName:%s\nAge: %ld\n",firstStudent.name,firstStudent.lastname,firstStudent.age);

printf("Name :%s",*(StudentPointer.name));

return 0;
}
