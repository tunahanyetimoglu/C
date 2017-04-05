#include <stdio.h>
#include <stdlib.h>

int a,b;
int main(int argc, char *argv[])
{
printf("\t\t\t ========CARPIM TABLOSU========");
printf("\n\n");

for(a=1;a<11;a++){

for(b=1;b<11;b++){

printf("     ");
printf("%d\t",a*b);
} printf("\n");
}
return 0;
}

