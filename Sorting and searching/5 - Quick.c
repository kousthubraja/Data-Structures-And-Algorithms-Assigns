#include <stdio.h>
#include <stdlib.h>

void err(){
	printf("*** Error ***\n");
	exit(1);
}

long int partition(float A[], long int p, long int r){
	long int x, i, j;
	float tmp;
	
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

void quick_sort(float A[], long int p, long int r){
	long int q;
	
	if(p < r){
		q = partition(A,p,r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

int main(){
	long int n, i;
	float *a;
	time_t t;
	
	if(!scanf("%ld", &n) || n<=0)
		err();
	
	a = (float*) malloc(sizeof(float)*(n+1));
	
	for(i=1;i<=n;i++){
		if(!scanf("%f", &a[i]))
			err();
	}
	
	t = time(NULL);
	
	quick_sort(a, 1, n);
	
	t = time(NULL) - t;
	
	printf("\nSorted list :\n");
	
	for(i=1;i<=n;i++){
		printf("%f\n", a[i]);
	}
	printf("\nRunning time : %f\n", (float)t/1000.0); 
	return 0;
}


