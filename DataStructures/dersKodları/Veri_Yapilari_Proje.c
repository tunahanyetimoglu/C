#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define maxN 30

struct nodeLink{ // Baþlangýç ve Bitiþ noktalarýný tutan yapý
    char node1;
    char node2;
};

struct  stack{  // Stack yapýsý
    int sp;
    char node[maxN];
};

char pathString[255]; 
char longestWays[255][255];

void initStk(stk) // Stack'in içinde olup olmadýðý sp bool deðeriyle kontrol eder
struct stack *stk;
{
    int i;
    for (i = 0; i < maxN; i++)
        stk -> node[i] = ' ';
    stk -> sp = -1;
}

void push(struct stack *stk, char node) // Push : Ekleme
{
    stk -> sp++;
    stk -> node[stk -> sp] = node;
}


bool InStack(struct stack *stk, char InterN){
    int i, stkN = stk -> sp;
    bool rtn = false;

    for (i = 0; i < stkN; i++){
        if (stk -> node[i] == InterN) {
            rtn = true;
            break;
        }
    }
    return rtn;
}

char otherNode(char targetNode, struct nodeLink *lnkNode){
    return (lnkNode -> node1 == targetNode) ? lnkNode -> node2 : lnkNode -> node1; // Ulaþýlmaya çalýþan düðüm ilki mi?
}

int entries = 28;
struct nodeLink topo[maxN] = // topo: aðaç
    {
        {'A', 'B'}, {'A', 'D'}, {'A', 'F'}, {'A', 'H'},
        {'B', 'C'}, {'B', 'R'}, {'B', 'J'}, {'B', 'I'},
		{'C', 'R'}, {'C', 'Q'}, {'C', 'D'},
        {'D', 'P'}, {'D', 'Q'}, {'D', 'E'},
        {'E', 'P'}, {'E', 'N'}, {'E', 'F'},
		{'F', 'N'}, {'F', 'M'}, {'F', 'G'},
        {'G', 'M'}, {'G', 'L'}, {'G', 'H'},
        {'H', 'L'}, {'H', 'K'}, {'H', 'I'},
        {'I', 'K'}, {'I', 'J'}
    };

char sourceNode = 'D', destinationN = 'A';

int reachTime;

void findLongestPaths(){
	if(strlen(pathString) > strlen(longestWays[0])){
		strcpy(longestWays[0],pathString);strcpy(longestWays[1],"");
	}else if(strlen(pathString) == strlen(longestWays[0])){
		int i = 0;for(; strlen(longestWays[i]); i++);
		strcpy(longestWays[i],pathString);strcpy(longestWays[i+1],"");
	}
}

void printLongestPaths(){
	int i = 0;
	printf("En uzun yollar:\n");
	for(; strlen(longestWays[i]); i++){
		int j;
		for(j = 0; j < strlen(longestWays[i])-1 ; j++)printf("%c-->",longestWays[i][j]);
		printf("%c\n",longestWays[i][j]);
	}
}


void pop(struct stack *stk) // Pop : Çýkartma
{
	char node;
    int i, stkN = stk->sp;
	pathString[0] = '\0';
	printf("Path:%d ", reachTime+1);
    for (i = 0; i<=stkN; i++) {
        node = stk -> node[i];
        pathString[i] = node;
        if (i == 0){
            printf("%c", node);
    	}
        else if (i == stkN){
            printf("-->%c\n", node);
        }
        else{
			printf("-->%c", node);
	    }
    }
    pathString[i] = '\0';
    findLongestPaths();
}

void InterNode(char interN, struct stack *stk)
{
    char otherInterN;
    int i, numInterN = 0;
    static  int entryTime = 0;
	entryTime++ ;

    for (i = 0; i < entries; i++){

        if (topo[i].node1 != interN  && topo[i].node2 != interN){
            continue;
        }

        otherInterN = otherNode(interN, &topo[i]);
		numInterN++ ;

        if (otherInterN == stk -> node[stk -> sp-1]){
            continue;
        }

        if (InStack(stk, otherInterN) == true){
            continue;
        }

        push(stk, otherInterN);
        if (otherInterN == destinationN){
            pop(stk);
            reachTime++ ;
            stk -> sp-- ;
            continue;
        }
        else
            InterNode(otherInterN, stk);

    }
        stk -> sp-- ;
}


int main(){
	int sp;
    struct  stack stk;
    struct stack list;
    initStk(&stk);
    push(&stk, sourceNode);
    reachTime = 0;
    InterNode(sourceNode, &stk);
	int i;
    printf("\nTum olasi yollarin sayisi = %d\n", reachTime);
    printLongestPaths();
}
