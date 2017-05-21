#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
	int data;
	struct treeNode *leftTreeNode;
	struct treeNode *rightTreeNode;
};

typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePointer;

void insertTreeNode(TreeNodePointer *treeNodePointer,int data);
void inorderTravelsal(TreeNodePointer treeNodePointer);
void preorderTravelsal(TreeNodePointer treeNodePointer);
void postorderTravelsal(TreeNodePointer treeNodePointer);


int main(void){

	TreeNodePointer root = NULL;
	  insertTreeNode( &root, 55 );
 insertTreeNode( &root, 42 );
 insertTreeNode( &root, 33 );
 insertTreeNode( &root, 69 );
 insertTreeNode( &root, 57 );
 insertTreeNode( &root, 70 );
 insertTreeNode( &root, 75 );
 insertTreeNode( &root, 72 );

 printf("\n");
 inorderTravelsal(root);
 printf("\n");
 preorderTravelsal(root);
 printf("\n");
 postorderTravelsal(root);
 printf("\n");
}

void insertTreeNode(TreeNodePointer *treeNodePointer,int data){
	if(*treeNodePointer == NULL){
		*treeNodePointer = (TreeNodePointer)malloc(sizeof(TreeNode));
		 if(*treeNodePointer != NULL){
		 	(*treeNodePointer)->data = data;
 		    (*treeNodePointer)->leftTreeNode = NULL;
 		    (*treeNodePointer)->rightTreeNode = NULL;
		 }
		 else{
		 	printf("No memmory");
		 	exit(EXIT_FAILURE);
		 }
	}
	else{
		if(data < (*treeNodePointer)->data){
            insertTreeNode(&((*treeNodePointer)->leftTreeNode),data);
		
		}
		else if  (data > (*treeNodePointer)->data){
			insertTreeNode(&((*treeNodePointer)->rightTreeNode),data);
		}
	}
}

      void inorderTravelsal(TreeNodePointer treeNodePointer){
      	 if(treeNodePointer != NULL){
      	 	inorderTravelsal(treeNodePointer->leftTreeNode);
      	 	printf("%-5d",treeNodePointer->data );
      	 	inorderTravelsal(treeNodePointer->rightTreeNode);
      	 }
      }
      void postorderTravelsal(TreeNodePointer treeNodePointer){
      	 if(treeNodePointer != NULL){
      	 	postorderTravelsal(treeNodePointer->leftTreeNode);
      	 	postorderTravelsal(treeNodePointer->rightTreeNode);
      	 	printf("%-5d",treeNodePointer->data );
      	 	
      	 }
      }
        void preorderTravelsal(TreeNodePointer treeNodePointer){
      	 if(treeNodePointer != NULL){
      	 		printf("%-5d",treeNodePointer->data );
      	 	preorderTravelsal(treeNodePointer->leftTreeNode);
      	 	
      	 	preorderTravelsal(treeNodePointer->rightTreeNode);
      	 }
      }

