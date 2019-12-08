#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

bool WriteFile() 
{
	FILE *fp = NULL;
	int idx;
	int buff[100];
	fp = fopen("D:/FileTrongC/SoNguyen.INP","wb");
	if(!fp)
	{
		printf("\n Error in opening file");
		return false;
	}
	for (idx = 0;idx<100;idx++) {
		buff[idx] = rand();
	}
	
	if(fwrite(buff,sizeof(buff),1,fp) <1)
	{
		printf("\n Error in writing SONGUYEN.INP FILE");
		fclose(fp);
		return false;
	}
	fclose(fp);
	return true;
}

bool SplitFile() {
	FILE *fp;
	FILE *fpOdd, *fpEven;
	int arr[100];
	int idx;
	fp = fopen("D:/FileTrongC/SoNguyen.INP","rb");
	if (!fp) {
		printf("\n Error in opening file");
		return false;
	} 
	if(fread(arr,100*sizeof(int),1,fp)<1) {
		printf("\n Error in reading file");
		fclose(fp);
		return false;
	}
	fclose (fp);
	fpOdd = fopen("D:/FileTrongC/SoLe.OUT","w");
	if(!fpOdd) {
		printf("\n Error in opening file");
		return false;
	}
	fpEven = fopen("D:/FileTrongC/SoChan.OUT","w");
	if(!fpEven) {
		printf("\n Error in opening file");
		return false;
	}
	for (idx = 0; idx<100;idx++) {
		if(arr[idx]%2==0) {
			fprintf(fpEven,"%d \t",arr[idx]);
		}
		else 
		{
			fprintf(fpOdd,"%d \t ",arr[idx]);
		}
	}
	fclose(fpOdd);
	fclose(fpEven);
	return true;
}


int main() {
	FILE *ptr;
	int idx;
	ptr = fopen("D:/FileTrongC/SoChan.OUT","r");
	if (ptr == NULL) {
		printf("\n can not open file");
		exit(1);
	}
	fscanf(ptr,"%d",&idx);
	printf("Value of File SoChan= %d",idx);
	fclose(ptr);
	if(!WriteFile()) {
		printf("Error");
	}
	if(!SplitFile()) {
		printf("Error");
	}
	printf("\n Succsess");
	getch();
}
