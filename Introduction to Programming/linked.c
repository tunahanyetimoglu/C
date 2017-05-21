#include <stdio.h>
#include <stdlib.h>

#define SAYI 5

struct student{
 int ogrNo;
 char *ogrSoyad;
 char *ogrAd;
 struct student *sonrakiOgr;
};

typedef struct student Student;
typedef struct student* OgrP;

void printogrList( OgrP *ogrList );
void deleteStudent( OgrP *ogrList, int ogrNo );
void searchStudent( OgrP *ogrList, int ogrNo, OgrP *arananOgr );
void insertStudent( OgrP *ogrList, int ogrNo, char *ogrSoyad, char* ogrAd );

int ogrNolar [ SAYI ] = { 1023, 102, 100, 9999, 23523 };
char *ogrSoyadlar [ SAYI ] = { "Aslan", "Sahin", "Ozkan", "Sahin", "Senturk" };
char *ogrAdlar [ SAYI ] = { "Ahmet", "Varol", "Sedat", "Omer", "Selcuk" };

int main( void ){

 //Define a pointer for head of the linked list
 OgrP ogrList = NULL;
 //Define a pointer for head of the linked list

 //Invoking printogrList method
 printf("After invoking printogrList method...\n");
 printogrList( &ogrList );
 //Invoking printogrList method

 //Adding students to the linked list
 for(int i = 0;i < SAYI;i++ ){
  insertStudent(&ogrList, ogrNolar[i], ogrSoyadlar[i],ogrAdlar[i]);
 }
 printf("\nAfter adding students to the linked list...\n");
 printogrList( &ogrList );

 //Adding a new student to the linked list
 int ogrNo = 40000 ;
 char ogrSoyad [ 7 ] = { 'C', 'a', 'k', 'm', 'a', 'k', '\0' };
 char ogrAd [ 8 ] = { 'N', 'a', 'g', 'i', 'h', 'a', 'n', '\0' };
 insertStudent( &ogrList, ogrNo, ogrSoyad, ogrAd );
 printf("\nAfter adding a new student with the number :%d to the linked list...\n",  ogrNo );
 printogrList( &ogrList );
 //Adding a new student to the linked list

 //Searching a student
 int searchedogrNo = 102;
 OgrP arananOgr = NULL;
 searchStudent( &ogrList, searchedogrNo, &arananOgr );
 printf("\nAfter searching the student with the number :%d\n", searchedogrNo );
 if( arananOgr != NULL ){
  printf("Number:%-10dFirstName:%-10sLastName:%-10s\n", arananOgr->ogrNo, arananOgr->ogrAd, arananOgr->ogrSoyad );
 }
 else{
  printf("\nThere is no student with the number :%d in the linked list...\n", searchedogrNo );
 }
 //Searching a student

 //Deleting a student from linked list
 int deletedogrNo = 1023;
 deleteStudent( &ogrList, deletedogrNo );
 printf("After invoking deleteStudent method...\n");
 printogrList( &ogrList );
 //Deleting a student from linked list

 //Deleting a student from linked list
 deletedogrNo = 40000;
 printf("\nAfter invoking deleteStudent method...\n");
 deleteStudent( &ogrList, deletedogrNo );
 printogrList( &ogrList );
 //Deleting a student from linked list

 return 0;
}

void printogrList( OgrP *ogrList ){
 if( *ogrList != NULL ){
  OgrP seciliOgr = *ogrList;
  while( seciliOgr != NULL ){
   printf("Number:%-10dFirstName:%-10sLastName:%-10s\n", seciliOgr->ogrNo, seciliOgr->ogrAd, seciliOgr->ogrSoyad );
   seciliOgr = seciliOgr->sonrakiOgr;
  }
 }
 else{
  printf("printogrList: There is no student in the linked list...\n");
 }
}
void deleteStudent( OgrP *ogrList, int ogrNo ){
 if( *ogrList != NULL ){
  OgrP oncekiOgr = NULL;
  OgrP seciliOgr = *ogrList;
  //Determining the location of the deleted student
  while( seciliOgr != NULL && seciliOgr->ogrNo != ogrNo ){
   oncekiOgr = seciliOgr;
   seciliOgr = seciliOgr->sonrakiOgr;
  }
  if( seciliOgr != NULL ){
   if( oncekiOgr != NULL ){
    oncekiOgr->sonrakiOgr = seciliOgr->sonrakiOgr;
   }
   else{
    *ogrList = seciliOgr->sonrakiOgr;
   }
   free( seciliOgr );
  }
  else{
   printf("deleteStudent: The student with the number %d was not included by the list...\n", ogrNo );
  }
  //Determining the location of the deleted student
 }
 else{
  printf("deleteStudent: There is no student in the linked list...\n");
 }
}
void searchStudent( OgrP *ogrList, int ogrNo, OgrP *arananOgr ){
 if( *ogrList != NULL ){
  OgrP seciliOgr = *ogrList;
  while( seciliOgr != NULL && seciliOgr->ogrNo != ogrNo ){
   seciliOgr = seciliOgr->sonrakiOgr;
  }
  if( seciliOgr != NULL ){
   *arananOgr = seciliOgr;
  }
 }
 else{
  printf("searchStudent:There is no student in the linked list...\n");
 }
}
void insertStudent( OgrP *ogrList, int ogrNo, char *ogrSoyad, char *ogrAd ){
 OgrP yeniOgr = ( OgrP )malloc( sizeof( Student ) );
 if( yeniOgr != NULL ){
  yeniOgr->ogrNo = ogrNo;
  yeniOgr->ogrSoyad = ogrSoyad;
  yeniOgr->ogrAd = ogrAd;

  //Determining the correct position of the new student
  OgrP oncekiOgr = NULL;
  OgrP seciliOgr = *ogrList;
  while( seciliOgr != NULL && seciliOgr->ogrNo < ogrNo ){
   oncekiOgr = seciliOgr;
   seciliOgr = seciliOgr->sonrakiOgr;
  }
  //Determining the correct postion of the new student

  //Adding the new student to the list
  if( oncekiOgr != NULL ){
   oncekiOgr->sonrakiOgr = yeniOgr;
   yeniOgr->sonrakiOgr = seciliOgr;
  }
  else{
   yeniOgr->sonrakiOgr = *ogrList;
   *ogrList = yeniOgr;
  }
 //Adding the new student to the list
 }
 else{
  printf("insertStudent:There is no space in the memory for new student...\n");
 }
}
