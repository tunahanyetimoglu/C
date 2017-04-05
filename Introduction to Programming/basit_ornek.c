#include <stdio.h>
#include <math.h>


int main(){

	int count =0;

	for (int i = 1; i < 1000; ++i)
	{
		if( i%3 ==0 || i%5 == 0){     // This program has found multiples 3 and 5 in 1 to 1000. 
			count = count + i;             // and calculated	 multiples sum!
		} 
	}

	 printf("%d",count);         // Answer : 233.168
}
