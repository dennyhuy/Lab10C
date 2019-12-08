#include <stdio.h>
#include <stdlib.h>
//Ham ghi file
void GhiFile(char FileName[],int num) {
	FILE *ptr;
	ptr = fopen(FileName,"w");
	fprintf(ptr,"%d",num);
	fclose(ptr);
}

int main() {
	char FileName[] ="D:/FileTrongC/NhapVaoSoNguyen.INP";
	int num;
	printf("\n Nhap vao so can dua vao file: ");
	scanf("%d",&num);
	GhiFile(FileName,num);
	
}
