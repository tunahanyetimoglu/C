#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBEROFSTUDENTS 30
#define CHANGE(grade)(grade-(grade*0.2))

void printStudentgrades();
void generatedStudentgrades();
void changeGrades();
void passedStudent();

int midtermGrades [ NUMBEROFSTUDENTS ];

void printStudentgrades(){
   
   for(int i=0; i<NUMBEROFSTUDENTS; i++){
       printf("Number:%-5d, Grade:%-5d\n",i+1,midtermGrades[i]);
   }
}

void generateStudentgrades(){
  
   for(int i=0; i<NUMBEROFSTUDENTS; i++){
      midtermGrades[i] = 1+rand() % 100;
   }
}

void passedStudent(){
    for(int i=0;i<NUMBEROFSTUDENTS;i++){
        if (midtermGrades[i] >= 50){
             printf("Number:%-5d, Grade:%-5d\n",i+1,midtermGrades[i]);
        }
    }
}

void changeGrades(){
      for(int i=0;i<NUMBEROFSTUDENTS; i++){
         midtermGrades[i] = CHANGE(midtermGrades[i]);
      }
}
        
           
