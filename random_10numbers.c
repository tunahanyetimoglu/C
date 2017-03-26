#include <stdio.h>
#include <time.h>
#include <math.h>
 
int main () {

   int n[ 10 ]; /* n is an array of 10 integers */
   int i,j;
    srand(time(NULL));
   /* initialize elements of array n to 0 */         
   for ( i = 0; i < 10; i++ ) {
      n[ i ] = rand() %100;
       printf("Element[%d] = %d\n", i+1, n[i] ); /* set element at location i to i + 100 */
   }
 
   return 0;
}
