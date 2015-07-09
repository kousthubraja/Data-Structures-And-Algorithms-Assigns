#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000

int partition(int A[], int p, int r){
	int x, i, j;
	int tmp;
	
	x = A[r];
	i = p - 1;
	
	for(j=p; j<=r-1; j++){
		if(A[j] <= x){
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;
	return i+1;
}

void quick_sort(int A[], int p, int r){
	int q;
	
	if(p < r){
		q = partition(A,p,r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

void makeBigFile(){
	FILE *fp = fopen("BigFile", "w+b");
	int n, size;
	//fseek(fp, 0, SEEK_END);
	printf("Creating BigFile...\n");
	while(size <= 64 * 1024 * 1024){
		n = rand()%1000;
		fwrite(&n, sizeof(int), 1, fp);
		size ++;
	}
	
	printf("Created\n");
	close(fp);
}

void printFile(char fn[]){
	FILE *fp = fopen(fn, "r+b");
	int n, size;
	fseek(fp, 0, SEEK_SET);
	while(size <=  1024 * 1024){
		if(!fread(&n, sizeof(int), 1, fp))
			break;
		printf("%d\n", n);
		size ++;
	}
	
	close(fp);
}


void splitIntoFiles(){
	FILE *fp = fopen("BigFile", "r+b");
	FILE *fout;
	int i, n;
	char fn[20];
	int size=0;
	for(i=1; i<=64; i++){
		printf("File : %d\n", i);
		sprintf(fn, "%d", i);
		FILE *fout = fopen(fn, "w+b");
		size = 0;
		int A[1024*1024];
		while(size <= 1024 * 1024){
			fread(&n, sizeof(int), 1, fp);
			//printf("%d\n", n);
			A[size] = n;
//			fwrite(&n, sizeof(int), 1, fout);
			size ++;
		}

		quick_sort(A, 0, 1024*1024);
		
		size = 0;
		while(size <= 1024 * 1024){
			n = A[size];
			fwrite(&n, sizeof(int), 1, fout);
			size ++;
		}
		fclose(fout);
	}
	fclose(fp);
}

void merge64(){
	FILE *fin[10], *fout;
	int n, i, size, j;
	char fn[20], tmp[5];
	int min=INF;
	int minpos;
	int pos;
	int num[10];
	int empty, fval;


	for(j = 1; j <= 8; j++)
	{
		strcpy(fn, "part");
		sprintf(tmp, "%d", j);
		strcat(fn, tmp);
		fout = fopen(fn, "w+b");

		for(i=1;i<=8;i++){
			sprintf(fn, "%d", i*j);
			fin[i] = fopen(fn, "r");
		}
	
		do{
			min = 10000;
			empty = 1;
			
			for(i=1;i<=8;i++){

				if(!fread(&n, sizeof(int), 1, fin[i]))
					continue;
				else
					empty = 0;
				
				fseek(fin[i], -sizeof(int), SEEK_CUR);
				//printf("--- %d %d\n",i, n);
				if(n < min)
				{
					pos = i;
					min = n;
				}	
			}
		
			//printf("<< %d %d\n", pos, min);
			fwrite(&min, sizeof(int), 1, fout);
			fseek(fin[pos], sizeof(int), SEEK_CUR);
		
		}
		while(empty == 0);
		
		printf("Created : part%d\n", j);
	}

}

void merge8(){
	FILE *fin[10], *fout;
	int n, i, size, j;
	char fn[20], tmp[5];
	int min=INF;
	int minpos;
	int pos;
	int num[10];
	int empty, fval;


	for(i=1;i<=4;i++){
			strcpy(fn, "part");
			sprintf(tmp, "%d", i);
			strcat(fn, tmp);
			printf("%s\n", fn);
			fin[i] = fopen(fn, "r");
		}
		fout = fopen("BigP1", "wb");
	
		do{
			min = 100000;
			empty = 1;
			
			for(i=1;i<=4;i++){

				if(!fread(&n, sizeof(int), 1, fin[i]))
					continue;
				else
					empty = 0;
				
				fseek(fin[i], -sizeof(int), SEEK_CUR);
				//printf("--- %d %d\n",i, n);
				if(n < min)
				{
					pos = i;
					min = n;
				}	
			}
		
			//printf("<< %d %d\n", pos, min);
			fwrite(&min, sizeof(int), 1, fout);
			fseek(fin[pos], sizeof(int), SEEK_CUR);
		
		}
		while(empty == 0);
		
		printf("BigP1 created\n");
		
		for(i=1;i<=4;i++){
			strcpy(fn, "part");
			sprintf(tmp, "%d", i+4);
			strcat(fn, tmp);
			printf("%s\n", fn);
			fin[i] = fopen(fn, "r");
		}
		fout = fopen("BigP2", "wb");
	
		do{
			min = 100000;
			empty = 1;
			
			for(i=1;i<=4;i++){

				if(!fread(&n, sizeof(int), 1, fin[i]))
					continue;
				else
					empty = 0;
				
				fseek(fin[i], -sizeof(int), SEEK_CUR);
				//printf("--- %d %d\n",i, n);
				if(n < min)
				{
					pos = i;
					min = n;
				}	
			}
		
			//printf("<< %d %d\n", pos, min);
			fwrite(&min, sizeof(int), 1, fout);
			fseek(fin[pos], sizeof(int), SEEK_CUR);
		
		}
		while(empty == 0);
		
		printf("BigP1 created\n");

}

void merge2(){
	FILE *fin[5], *fout;
	int n, i, size, j;
	char fn[20], tmp[5];
	int min=INF;
	int minpos;
	int pos;
	int num[10];
	int empty, fval;
	int a, b;


	fout = fopen("SortedFile", "wb");
	
	for(i=1;i<=2;i++){
		strcpy(fn, "BigP");
		sprintf(tmp, "%d", i);
		strcat(fn, tmp);
		printf("%s\n", fn);
		fin[i] = fopen(fn, "r");
	}
	fout = fopen("SortedFile", "wb");

	do{
		min = 1000000;
		empty = 1;
		
		for(i=1;i<=2;i++){

			if(!fread(&n, sizeof(int), 1, fin[i]))
				continue;
			else
				empty = 0;
			
			fseek(fin[i], -sizeof(int), SEEK_CUR);
			//printf("--- %d %d\n",i, n);
			if(n < min)
			{
				pos = i;
				min = n;
			}	
		}
	
		//printf("<< %d %d\n", pos, min);
		fwrite(&min, sizeof(int), 1, fout);
		fseek(fin[pos], sizeof(int), SEEK_CUR);
	
	}
	while(empty == 0);
/*

	while(1){
		if( !fread(&a, sizeof(int), 1, fa) || !fread(&b, sizeof(int), 1, fa) ){
			break;
		}
		else{
			
			fseek(fa, -sizeof(int), SEEK_CUR);
			fseek(fb, -sizeof(int), SEEK_CUR);
			if( a < b){
				fwrite(&a, sizeof(int), 1, fout);
				fseek(fa, sizeof(int), SEEK_CUR);
			}
			else{
				fwrite(&b, sizeof(int), 1, fout);
				fseek(fb, sizeof(int), SEEK_CUR);
			}
		}
	}
	*/
}

int main(){
	
	makeBigFile();

	printf("Splitting into 64 files and sorting...\n");
	splitIntoFiles();
	
	printf("Doing 8 way merge on 64 files to make 8 files...\n");
	merge64();
	
	printf("Doing 4 way merge on 8 files to make 2 files...\n");
	merge8();
	
	printf("Merging two files to make final sorted file...\n");
	merge2();
	
	return 0;
}
