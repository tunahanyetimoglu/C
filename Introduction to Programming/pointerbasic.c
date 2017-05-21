#include <stdio.h>

int c = 5;

int* a = NULL;

int main(){
 
 printf("1: %d\n",a);
 printf("2: %d\n",&a);
// printf("%d",*a);
  
 a = &c;

 printf("3: %d\n",a);
 printf("4: %d\n",&a);
 printf("5: %d\n",*a);

 *a = 6;
 
 printf("6: %d\n",a);
 printf("7: %d\n",&a);
 printf("8: %d\n",*a);
 

 printf("9: %d\n",c);
 printf("10: %d\n",&c);
       
return 0;}
