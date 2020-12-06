#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBEROFCUSTOMERS 15

struct customer{
  int bill;
  char *customerName;
  struct customer *nextCustomer;
};

typedef struct customer Customer;
typedef struct customer* CustomerPointer;

void printCustomerList ( CustomerPointer *customerList );
void printByBill ( CustomerPointer *customerList, int value);
void printByAlphabet ( CustomerPointer *customerList, char a);
void insertCustomer ( CustomerPointer *customerList, int bill, char *customerName);
void insertDescByBill ( CustomerPointer *customerList, int bill, char *customerName);
void insertDescByName ( CustomerPointer *customerList, int bill, char *customerName);


int bills [ NUMBEROFCUSTOMERS ] = { 100, 1000, 600, 650, 350, 270, 410, 750, 600, 1000, 900, 850, 790, 610, 550 };
char *customerNames [ NUMBEROFCUSTOMERS ] = {"Ahmet", "Bilal", "Cemal", "Adem", "Yasin" ,"Esin", "Emel", "Mustafa", "Ayten", "Ceylan", "Nesrin", "Bekir", "Emin", "Hakan", "Hatice"};

int main( void ){

 //Define a pointer for head of the linked list
 CustomerPointer customerOrderBillList = NULL;
 CustomerPointer customerOrderNameList = NULL;
 //Define a pointer for head of the linked list

 //Invoking insertCustomerDescyByBill method
  for( int customerIndex = 0; customerIndex < NUMBEROFCUSTOMERS; customerIndex++){
    insertDescByBill( &customerOrderBillList, bills[ customerIndex ], customerNames[ customerIndex ]);
  }
  printf( "\nAfter adding customers to desc by bill value the linked list...\n" );
  printCustomerList( &customerOrderBillList );
  printf( "\n Print customer linked list, bill value upper to 900 ...\n" );
  printByBill ( &customerOrderBillList, 900);

  for( int customerIndex = 0; customerIndex < NUMBEROFCUSTOMERS; customerIndex++){
    insertDescByName( &customerOrderNameList, bills[ customerIndex ], customerNames[ customerIndex ]);
  }
  printf( "\nAfter adding customers to desc by bill value the linked list...\n" );
  printCustomerList( &customerOrderNameList );
   //Adding a new customer to the linked list
   int billValue = 875 ;
   char customerName [ 5 ] = { 'A', 'r', 'd', 'a', '\0' };
   insertDescByBill( &customerOrderBillList, billValue, customerName);
   printf( "\nAfter adding a new customer with the bill value :%d to the linked list...\n",  billValue );
   printCustomerList( &customerOrderBillList );


      //Adding a new customer to the linked list
   int _billValue = 1081 ;
   char _customerName [ 6 ] = { 'B', 'u', 'g', 'r', 'a', '\0' };
   insertDescByName( &customerOrderNameList, _billValue, _customerName);
   printf( "\nAfter adding a new customer with the name :%s to the linked list...\n",  _customerName );
   printCustomerList( &customerOrderNameList );

   char search = 'A';
   printf("\n Print customer linked list start with A \n");
   printByAlphabet( &customerOrderNameList, search);


 return 0;
}

void printCustomerList( CustomerPointer *customerList ){
  if( *customerList != NULL ){
    CustomerPointer currentCustomer = *customerList;
    while( currentCustomer != NULL){
      printf( "Name:%-10s Bill:%-10d\n", currentCustomer->customerName,currentCustomer->bill );
      currentCustomer = currentCustomer->nextCustomer;
    }
  }
  else{
    printf("printCustomerList: There is no customer in the linked list..\n");
  }
}

void printByBill( CustomerPointer *customerList, int value  ){
  if( *customerList != NULL ){
    CustomerPointer currentCustomer = *customerList;
    while( currentCustomer != NULL){
      
      if( currentCustomer->bill >= value){
      printf( "Name:%-10s Bill:%-10d\n", currentCustomer->customerName,currentCustomer->bill );
      }
      currentCustomer = currentCustomer->nextCustomer;
    }
  }
  else{
    printf("printCustomerList: There is no customer in the linked list..\n");
  }
}

void printByAlphabet( CustomerPointer *customerList, char a){
  if( *customerList != NULL ){
    CustomerPointer currentCustomer = *customerList;
    while( currentCustomer != NULL){
      if(currentCustomer->customerName[0] == a ){
        printf( "Name:%-10s Bill:%-10d\n", currentCustomer->customerName,currentCustomer->bill );
      }
      
      currentCustomer = currentCustomer->nextCustomer;
    }
  }
  else{
    printf("printCustomerList: There is no customer in the linked list..\n");
  }
}

void insertDescByName( CustomerPointer *customerList, int bill, char *customerName ){
 CustomerPointer newCustomer = ( CustomerPointer )malloc( sizeof( Customer ) );
 if( newCustomer != NULL ){
  newCustomer->bill = bill;
  newCustomer->customerName = customerName;

  //Determining the correct position of the new customer
  CustomerPointer previousCustomer = NULL;
  CustomerPointer currentCustomer = *customerList;
  while( currentCustomer != NULL && strcmp(currentCustomer->customerName, customerName) < 0 ){
   previousCustomer = currentCustomer;
   currentCustomer = currentCustomer->nextCustomer;
  }
  //Determining the correct postion of the new customer
  
  //Adding the new customer to the list
  if( previousCustomer != NULL ){
   previousCustomer->nextCustomer = newCustomer;
   newCustomer->nextCustomer = currentCustomer;
  }
  else{
   newCustomer->nextCustomer = *customerList;
   *customerList = newCustomer;
  }
 //Adding the new customer to the list
 }
 else{
  printf( "insertCustomer:There is no space in the memory for new customer...\n" );
 }
}

void insertDescByBill( CustomerPointer *customerList, int bill, char *customerName ){
 CustomerPointer newCustomer = ( CustomerPointer )malloc( sizeof( Customer ) );
 if( newCustomer != NULL ){
  newCustomer->bill = bill;
  newCustomer->customerName = customerName;

  //Determining the correct position of the new customer
  CustomerPointer previousCustomer = NULL;
  CustomerPointer currentCustomer = *customerList;
  while( currentCustomer != NULL && currentCustomer->bill > bill ){
   previousCustomer = currentCustomer;
   currentCustomer = currentCustomer->nextCustomer;
  }
  //Determining the correct postion of the new customer
  //Adding the new customer to the list
  if( previousCustomer != NULL ){
   previousCustomer->nextCustomer = newCustomer;
   newCustomer->nextCustomer = currentCustomer;
  }
  else{
   newCustomer->nextCustomer = *customerList;
   *customerList = newCustomer;
  }
 //Adding the new customer to the list
 }
 else{
  printf( "insertCustomer:There is no space in the memory for new customer...\n" );
 }
}
