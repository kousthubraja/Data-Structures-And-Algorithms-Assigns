#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1000

void radixsort(unsigned int a[], int n){
	int i, j, tmp;
	unsigned long int d;
	for(d=16;d<=0xFFFFFFFF;d*=16){
		for(i=0;i<n-1;i++){
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]%d > a[j+1]%d){
					tmp = a[j];
					a[j] = a[j+1];
					a[j+1] = tmp;
				}
			}
		}
	}
}

void err(){
	printf("*** Error ***\n");
	exit(1);
}

int main(){
	unsigned int a[SIZE];
	int n, i;
	time_t t;
		
	if(!scanf("%d", &n) || n<=0)
		err();
		
	for(i=0;i<n;i++)
		if(!scanf("%x", &a[i]))
			err();

	t = time(NULL);
	
	radixsort(a,n);
	
	t = time(NULL) - t;
	
	printf("\nSorted list :\n");
	for(i=0;i<n;i++)
		printf("%x\n",a[i]);

	printf("\n #Running time : %f\n", (float)t/1000.0);
	
	return 0;
}
