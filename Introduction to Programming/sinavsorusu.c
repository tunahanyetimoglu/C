#include <stdio.h>

double spow(double a, double b);
double main(){
  
  double a = 2;
  double b = -3;
  printf("%f",spow(a,b));
  
 return 0;
}

  double spow(double a, double b){
  
     if ( a == 1.0 || b == 0.0)
        return 1.0;
		 else if( b < 0.0)
					return (1.0/a)*(spow(a,b+1));
     else
          return a*(spow(a,b-1));
  }
