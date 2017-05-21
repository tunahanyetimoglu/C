#include <stdio.h>

int spow(int a, int b);
int main(){
  
  int a = 2;
  int b = 3;
  printf("%d",spow(a,b));
  
 return 0;
}

  int spow(int a, int b){
  
     if ( a == 1 || b == 0)
        return 1;
     else
          return a*(spow(a,b-1));
  }
