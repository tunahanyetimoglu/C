#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int yas;
    char *firstName;
    char *lastName;
		struct student *next;
		}Student,*studentPointer;
FILE* file;

int main(){

 studentPointer ogr1 = (studentPointer)malloc(sizeof(Student));
 studentPointer ogr2 = (studentPointer)malloc(sizeof(Student));
 
  Student ogr3 = {21,"Omer","Ozen"};
  studentPointer ogrenci3 = &ogr3;

 file = fopen("ogrenci.txt","a+"); 
 if (file == NULL){
  printf("Dosyaya erişilemedi");
 	return 1;
 }
 else{
  ogr1 -> yas       = 20            ;
  ogr1 -> firstName = "Tunahan"     ;
  ogr1 -> lastName  = "Yetimoglu"   ;
  ogr1 -> next      = ogr2          ;
  ogr2 -> yas       = 21            ;
  ogr2 -> firstName = "Serhat Celil";
  ogr2 -> lastName  = "Ileri"       ;
  
	

  fprintf(file,"Ogrencinin adı:%s\t, Ogrencinin Soyadı:%s\t, Ogrencinin Yası:%d\n",
          ogr1->firstName,ogr1->lastName,ogr1->yas);
 }
 
 fclose(file);
 
 return 0;
}
