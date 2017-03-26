#include <stdio.h>
#include <time.h>
#include <math.h>
 
#define CON 20
#define CIRCLE_AREA( x,y )( ( PI ) * ( x ) * ( y ) )
#define CHANGENOTES( grade )( ( grade ) - ( grade ) * 0.25 )

int a[CON];
void passedStudent();
void raiseStudent();

const int PI = 3;


int main () {



  printf("CIRCLE AREA : %d\n", CIRCLE_AREA(3,4));
     
   srand(time(NULL));

   generate();

   puts("Notes");

   printNote();

   puts ("After Popped...");

   passedStudent();

   raiseStudent();	

   puts ("After Raise...");
   
   passedStudent();	

   return 0;
}

void passedStudent(){
	for (int i = 0 ; i<CON; i++){
		if (a[i] > 50)
			printf("Element [%d] = %d\n", i+1 , a[i]);
	}
}

void raiseStudent(){
	for (int j= 0; j<CON; j++){
	  a[j] = CHANGENOTES(a[j]);
	}

}

void generate(){
   for (int i = 0 ; i<CON; i++){
       a[i+1] = rand() %100;
      }
}

void printNote(){
    for (int i = 0 ; i<CON; i++){
      printf("Element [%d] = %d\n", i+1 , a[i]);
   }
}
