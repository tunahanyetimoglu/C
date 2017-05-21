#include <stdio.h>

int main(void)
{
 int b[] = {10,20,30,40};
 int* bPtr = b;
 size_t i;
 size_t offset;
 
 for( i=0;i<4;i++)
 {
  printf("b[%u] = %d\n",i,b[i]);
 }
 for(offset=0;offset<4;offset++)
 {
  printf("*(b+%u) = %d\n",offset,*(b+ offset));
 }
 for( i=0;i<4;i++)
 {
  printf("bPtr[%u] = %d\n",i,bPtr[i]);
 }
 for(offset=0;offset<4;offset++)
 {
  printf("*(bPtr+%u) = %d\n",offset,*(bPtr+ offset));
 }
 const char *suit [ 4 ] = { “Hearts”, “Diamonds”, “Clubs”, “Spades” };
 printf("%c",*(*suit));

 return 0;
}
