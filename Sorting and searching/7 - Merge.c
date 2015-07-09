#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
#define INF 10000000

void err(){
	printf("*** Error ***\n");
	exit(1);
}


void merge(long int A[], long int p, long int q, long int r){
	long int n1, n2, i, j, k;
	n1 = q-p+1;
	n2 = r-q;
	
	long int *L;
	long int *R;
	L = (long int*) malloc((n1+1)*sizeof(long int));
	R = (long int*) malloc((n2+1)*sizeof(long int));
	
	for(i=1;i<=n1;i++){
		L[i] = A[p + i - 1];
	}
	
	for(j=1;j<=n2;j++){
		R[j] = A[q + j];
		
	}
	
	L[n1 + 1] = INF;
	R[n2 + 1] = INF;
	
	i=1;
	j=1;
	for(k=p; k<=r;k++){
		if(L[i] < R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
	}
	
	//free(L);
	//free(R);
}

void merge_sort(long int A[], long int p, long int r){
	long int q;
	if(p < r){
		q = (p + r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int main()
{
    long int i, j, n=5 ;
    long int *a;
    time_t t;
    
    if(!scanf("%ld", &n) || n<=0)
		err();
		
	a = (long int*) malloc(sizeof(long int) * (n+1));
    
    for(i=1;i<=n;i++)
        if(!scanf("%ld", &a[i]))
			err();
    
    t = time(NULL);

	merge_sort(a, 1, n);
	
	t = time(NULL) - t;
	
	printf("\nSorted list :\n");
    for(i=1;i<=n;i++)
        printf("%ld\n", a[i]);
 	
 	printf("\n #Running time : %f\n", (float)t/1000.0);
 	
 	free(a);
 			
    return 0;
}
