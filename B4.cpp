#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //Khai bao mot cau truc
struct SoNguyen {
	int k;
};

//Ham nhap du lieu cho day so
void nhapDuLieuChoDaySo(SoNguyen A[],int n) {
	for(int i = 0 ; i<n;i++) {
		printf("\n Nhap vao so thu %d: ",i);
		scanf("%d",&A[i].k);
	}
}

 //Ham xuat du lieu 
void xuatDuLieu(SoNguyen A[],int n) {
	for(int i = 0;i<n;i++) {
		printf("\n Cac so cua day la: %d \t",A[i].k);
	}
}

 //Ham sap xep day so
void sapXepDaySo(SoNguyen A[],int n) {
	int temp;
	for(int i = 0;i<n;i++)
		for(int j=i+1;j<n;j++) {
			if(A[i].k > A[j].k) {
			A[i].k = temp;
			A[i].k = A[j].k;
			A[j].k = temp;
			}
		}
}

 //Ham dua du lieu vao file
void NhapDuLieuVaoFile(char FileName[],int n,SoNguyen A[]) {
	FILE *ptr;
	ptr = fopen(FileName,"w");
	for (int i = 0;i<n;i++) {
		fprintf(ptr,"%d",A[i].k);
	}
	fclose(ptr);
}

 //Ham Cong hai day so trong hai day so khac nhau
void congHaiDaySo(SoNguyen A[],int n,SoNguyen A2[],int m,SoNguyen A3[],int &p) {
	p = n+m;
	for(int i = 0 ; i<p ; i++) {
		if(i<n) {
			A3[i] = A[i];
		} else A3[i] = A2[i-n];
	}
} 

//Ham doc du lieu tu file
void docDuLieu(char FileName[],int n,SoNguyen A[]) {
	FILE *fptr;
	fptr = fopen(FileName,"r");
	for(int i = 0;i< n;i++) {
		fscanf(fptr,"%d",&A[i].k);
		printf("\n Gia Tri cua hai day so la: %d \t",A[i].k);
	}
	fclose(fptr);
}

int main() {
	//Khai bao cac file 
	char FileName[] = "D:/FileTrongC/DaySoNguyenThu1.txt";
	char FileName2[] = "D:/FileTrongC/DaySoNguyenThu2.txt";
	char FileName3[] = "D:/FileTrongC/DaySoNguyenThu3.txt";
	
	//Khai bao cac bien cau truc
	SoNguyen A[50];
	SoNguyen A2[50];
	SoNguyen A3[50];
	
	//Khai bao cac bien dem
	int n;
	int m;
	int p;
	
	//Xu ly file dau tien
	printf("\n Nhap vao cac so can them vao cua Day So dau: ");
	scanf("%d",&n);
	nhapDuLieuChoDaySo(A,n);
	sapXepDaySo(A,n); 
	xuatDuLieu(A,n); 
	NhapDuLieuVaoFile(FileName,n,A);
	
	//Xu ly file thu hai
	printf("\n Nhap vao cac so can them vao cua day so thu hai: ");
	scanf("%d",&m);
	nhapDuLieuChoDaySo(A2,m);
	sapXepDaySo(A2,m); 
	xuatDuLieu(A,m);
	NhapDuLieuVaoFile(FileName2,m,A2);
	
	//Xu ly file thu ba
	congHaiDaySo(A,n,A2,m,A3,p);
	sapXepDaySo(A3,p);
	NhapDuLieuVaoFile(FileName3,p,A3);
	//Doc du lieu cua file
	docDuLieu(FileName3,n,A3);
	
}

