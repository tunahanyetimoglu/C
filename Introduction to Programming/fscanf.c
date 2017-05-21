#include <stdio.h>

int main(void){

 unsigned int account;
 char name[30];

 FILE* file;
 file = fopen("ogrenci.txt","r");
 printf( "%-10s%-13s%s\n", "Account", "Name", "Balance" );
 fscanf(file,"%d%29s",&account,name);
 while(!feof(file)){
  printf("%-10d%-13s\n",account,name);
  fscanf(file,"%s",name);
 }
 fclose(file);
 return 0;
}
