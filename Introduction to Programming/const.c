#include <stdio.h>

int main(){
int a=5;
const int* const x =&a ;
int* const y =&a;
int* p  ;
const int* z;


p = y;
z = p;




 return 0;
}
