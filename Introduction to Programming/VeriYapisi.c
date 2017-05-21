#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char* ad;
	int boy;
	struct student *next;
};


typedef struct student Student;
typedef struct student *StudentP;


int main(){
	StudentP ogr1 = (StudentP)malloc(sizeof(Student));
	StudentP ogr2 = (StudentP)malloc(sizeof(Student));
	StudentP ogr3 = (StudentP)malloc(sizeof(Student));

	if(ogr1 == NULL){
		printf("Not enough space in memory!\n");
	}else{
		ogr1 -> id  = 1       ;
		ogr1 -> ad  = "Serhat";
		ogr1 -> boy = 175     ;
		ogr1 -> next         = ogr2    ;	
		ogr2 -> id  = 1       ;
		ogr2 -> ad  = "Serhat";
		ogr2 -> boy = 175     ;

		printf("og1 bilgileri:\n\t%d\n\t%s\n\t%d\n",ogr1->id, ogr1->ad, ogr1->boy);
	}

	return 0;	
}
