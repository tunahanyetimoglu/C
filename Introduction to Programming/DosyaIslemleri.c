#include <stdio.h>
#include <stdlib.h>


int main(){
	FILE* file;
	file = fopen("yazi.txt", "a+");
	if(file == NULL){
		printf("Dosya okunamadı!\n");
		return 1;
	}
	else{
		printf("Dosya okuma BAŞARILI!\n");
		printf("Hesap numarasını, adınızı ve bakiyenizi girin:");
		char ad[30], hesap[30];
		int bakiye;
		scanf("%s%s%d",&hesap,&ad,&bakiye);
		fprintf(file, "%s %s %d\n", hesap, ad, bakiye);
		fclose(file);
	}
	return 0;
}
