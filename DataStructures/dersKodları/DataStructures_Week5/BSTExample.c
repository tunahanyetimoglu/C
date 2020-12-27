#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFSTUDENTS 15

struct treeNode
{
  int number;
  int note;
  struct treeNode *leftTreeNode;
  struct treeNode *rightTreeNode;
};
typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePointer;

void insertTreeNode_V2(TreeNodePointer *treeNodePointer, int number, int note);
void updateNote(TreeNodePointer *TreeNodePointer, int number, int new_note);
void inorderTravelsal(TreeNodePointer TreeNodePointer);
void inorderTravelsal_V2(TreeNodePointer treeNodePointer, int number);

TreeNodePointer deleteNode(TreeNodePointer treeNodePointer, int number);
void deleteTreeNode(TreeNodePointer *treeNodePointer, int number);

int numbers[NUMBEROFSTUDENTS] = {18060311, 20060045, 19061091, 20060134, 20060678, 18061086, 20060032, 20060067, 19060456, 18060245, 20060110, 20060234, 20060141, 20060011, 20060012};
int notes[NUMBEROFSTUDENTS] = {40, 50, 75, 90, 40, 75, 50, 60, 60, 75, 40, 90, 60, 50, 60};

int main(void)
{
  //Invoking insertTreeNode method
  TreeNodePointer students = NULL;

  for (int studentIndex = 0; studentIndex < NUMBEROFSTUDENTS; studentIndex++)
  {
    insertTreeNode_V2(&students, numbers[studentIndex], notes[studentIndex]);
  }

  //Invoking inorderTravelsal method
  printf("\nAfter invoking inorderTravelsal method...\n");
  inorderTravelsal(students);
  printf("\n");
  //Invoking inorderTravelsal method
  printf("\n Notes > 60\n ");
  inorderTravelsal_V2(students, 60);

  insertTreeNode_V2(&students, 20060067, 60);
  printf("\nAfter adding student inorderTravelsal method...\n");
  inorderTravelsal(students);

  updateNote(&students, 18060311, 100);
  printf("\nAfter update note number : 18060311 , note : 100 ...\n");
  inorderTravelsal(students);

  printf("\n");
}

void insertTreeNode_V2(TreeNodePointer *treeNodePointer, int number, int note)
{
  if (*treeNodePointer == NULL)
  {
    *treeNodePointer = (TreeNodePointer)malloc(sizeof(TreeNode));
    if (*treeNodePointer != NULL)
    {
      (*treeNodePointer)->number = number;
      (*treeNodePointer)->note = note;
      (*treeNodePointer)->leftTreeNode = NULL;
      (*treeNodePointer)->rightTreeNode = NULL;
    }
    else
    {
      printf("There is no memory space for for adding a new record...\n");
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    if (note > (*treeNodePointer)->note)
    {
      insertTreeNode_V2(&((*treeNodePointer)->leftTreeNode), number, note);
    }
    else if (note < (*treeNodePointer)->note)
    {
      insertTreeNode_V2(&((*treeNodePointer)->rightTreeNode), number, note);
    }
    else if (note == (*treeNodePointer)->note)
    {
      if (number < (*treeNodePointer)->number)
      {
        insertTreeNode_V2(&((*treeNodePointer)->leftTreeNode), number, note);
      }
      else
      {
        insertTreeNode_V2(&((*treeNodePointer)->rightTreeNode), number, note);
      }
    }
  }
}

void inorderTravelsal(TreeNodePointer treeNodePointer)
{
  if (treeNodePointer != NULL)
  {
    inorderTravelsal(treeNodePointer->leftTreeNode);
    printf("Number : %-5d , Note : %-5d \n", treeNodePointer->number, treeNodePointer->note);
    inorderTravelsal(treeNodePointer->rightTreeNode);
  }
}

void inorderTravelsal_V2(TreeNodePointer treeNodePointer, int note)
{
  if (treeNodePointer != NULL)
  {
    inorderTravelsal_V2(treeNodePointer->leftTreeNode, note);
    if (note < treeNodePointer->note)
    {
      printf("Number : %-5d , Note : %-5d \n", treeNodePointer->number, treeNodePointer->note);
    }
    inorderTravelsal_V2(treeNodePointer->rightTreeNode, note);
  }
}

TreeNodePointer deleteNode(TreeNodePointer treeNodePointer, int number)
{
  if (treeNodePointer == NULL)
  {
    return treeNodePointer;
  }
  if (number < treeNodePointer->number)
  {
    treeNodePointer->leftTreeNode = deleteNode(treeNodePointer->leftTreeNode, number);
  }
  else if (number > treeNodePointer->number)
  {
    treeNodePointer->rightTreeNode = deleteNode(treeNodePointer->rightTreeNode, number);
  }
  else
  {
    if (treeNodePointer->leftTreeNode == NULL)
    {
      TreeNodePointer temporaryTreeNodePointer = treeNodePointer->rightTreeNode;
      free(treeNodePointer);
      return temporaryTreeNodePointer;
    }
    else if (treeNodePointer->rightTreeNode == NULL)
    {
      TreeNodePointer temporaryTreeNodePointer = treeNodePointer->leftTreeNode;
      free(treeNodePointer);
      return temporaryTreeNodePointer;
    }
    else
    {
      TreeNodePointer temporaryTreeNodePointer = treeNodePointer->rightTreeNode;
      while (temporaryTreeNodePointer->leftTreeNode != NULL)
      {
        temporaryTreeNodePointer = temporaryTreeNodePointer->leftTreeNode;
      }
      treeNodePointer->number = temporaryTreeNodePointer->number;
      treeNodePointer->rightTreeNode = deleteNode(treeNodePointer->rightTreeNode, temporaryTreeNodePointer->number);
    }
  }
  return treeNodePointer;
}
void deleteTreeNode(TreeNodePointer *treeNodePointer, int number)
{
  if (*treeNodePointer != NULL)
  {
    TreeNodePointer currentTreeNodePointer = *treeNodePointer;
    while (currentTreeNodePointer != NULL && currentTreeNodePointer->number != number)
    {
      if (number < currentTreeNodePointer->number)
      {
        currentTreeNodePointer = currentTreeNodePointer->leftTreeNode;
      }
      else if (number > currentTreeNodePointer->number)
      {
        currentTreeNodePointer = currentTreeNodePointer->rightTreeNode;
      }
    }
    if (currentTreeNodePointer != NULL)
    {
      deleteNode(*treeNodePointer, number);
    }
    else
    {
      printf("The record with the key %d was not found...\n", number);
    }
  }
}

void updateNote(TreeNodePointer *treeNodePointer, int number, int new_note)
{
  if (*treeNodePointer != NULL)
  {
    TreeNodePointer currentTreeNodePointer = *treeNodePointer;
    while (currentTreeNodePointer != NULL && currentTreeNodePointer->number != number)
    {
      if (number > currentTreeNodePointer->number)
      {
        currentTreeNodePointer = currentTreeNodePointer->leftTreeNode;
      }
      else if (number < currentTreeNodePointer->number)
      {
        currentTreeNodePointer = currentTreeNodePointer->rightTreeNode;
      }
    }
    if (currentTreeNodePointer != NULL)
    {
      deleteTreeNode(treeNodePointer, number);
      insertTreeNode_V2(treeNodePointer, number, new_note);
    }
    else
    {
      printf("The record with the key %d was not found...\n", number);
    }
  }
}
