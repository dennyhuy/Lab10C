#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void NhapMangMotChieu( int A[],int n) {
	for(int i = 0;i<n;i++) {
		printf("\n Nhap vao so nguyen thu %d: ",i);
		scanf("%d",&A[i]);
	}
}
void NhapDuLieuVaoFile(char fileName[],int n,int A[]) {
	FILE *fp;
	fp = fopen(fileName,"w");
	for(int i = 0;i<n;i++) {
		fprintf(fp,"%d \t",A[i]);
	}
	fclose(fp);
}
void xuatMang(int A[],int n) {
	for(int  i =0;i<n;i++) {
		printf("%d \t",A[i]);
	}
}
void SapXepMang(int A[],int n) {
	int temp;
	for(int i = 0 ;i<n;i++)
		for(int j=i+1;j<n;j++) {
			if(A[i]>A[j]) {
				A[i] = temp;
				A[i] = A[j];
				A[j] = temp;
			}
		}
}
int main() {
	char fileName[] = "D:/FileTrongC/NhapMang.INP";
	char fileName2[] = "D:/FileTrongC/MangOut.OUT";
	
	int A[100];
	int n;
	printf("\n Nhap vao so phan tu can dua vao mang: ");
	scanf("%d",&n);
	NhapMangMotChieu(A,n);
	NhapDuLieuVaoFile(fileName,n,A);
	SapXepMang(A,n);
	NhapDuLieuVaoFile(fileName2,n,A);
}
