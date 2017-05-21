#include <stdio.h>

void displayBits(int value);

int main()
{
 unsigned x = 1510;

 displayBits(x);

 return 0;
}

 displayBits(int value)
{
 unsigned int c;
 unsigned int displayMask = 2 << 30;
 printf("displayMask = %d",displayMask);
 printf("Value : %10u\n",value);
 for(c=1;c <=32;c++)
 {
  putchar( value & displayMask ? '1' : '0' ); value <<= 1;
  if( c % 4 == 0 ){
  putchar( ' ');

  }
 }
  puts("");
}
