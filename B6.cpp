#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
void ghiDuLieu(char FileName[], char KiTu[]) {
	FILE *f;
	f = fopen(FileName,"w");
	if(f!=NULL) {
		
		fputs(KiTu,f);
		fclose(f);
	}	
	getch();
}

void soLanXuatHien(char KiTu[])  {
	int n=strlen(KiTu)-1;
	int a[10],m=0;
	for (int i = 0; i<=n;i++){
		int d =0;
		for(int j=i+1;j<=n;j++) {
			j=0;
			while(j<=n) {
				if(KiTu[i] == KiTu[j]) {
					d++;
				}
				j++;
			}
		}
		a[m] = d;
		m++;
	}
	int k;
	int maxx=a[0];
	int maxi=0;
	for(k=0;k<m;k++) {
		if(a[k]>maxx) {
			maxx = a[k];
			maxi = k+1;
		}
	}
	int l,g;
	char s1[1];
	for(l=0;l<m;l++) {
		for(g = 0;g<n;g++) {
			if(maxi==g) {
				s1[0] = KiTu[g-1];
			}
		}
	}
	printf("chu %s vi tri thu %d xuat hien nhieu nhat, %d lan",s1,maxi,maxx);
}

int main() {
	char KiTu[10];
	char FileName4[] = "D:/FileTrongC/KiTu.txt";
	printf("\n Nhap vao chuoi ki tu: ");
	gets(KiTu);
	ghiDuLieu(FileName4,KiTu);
	soLanXuatHien(KiTu);
}
