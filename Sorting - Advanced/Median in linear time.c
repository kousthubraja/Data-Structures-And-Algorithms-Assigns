#include<stdio.h>
#include <stdlib.h>
 
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

int selectpart(int A[], int p, int r, int i){
	int q, k;
	if( p == r)
		return A[p];
	
	q = partition(A, p, r);
	k = q - p + 1;
	
	if( i == k)
		return A[q];
	else if( i< k)
		return selectpart(A, p, q-1, i);
	else
		return selectpart(A, q+1, r, i);
}
	 
int main()
{
    int *a;
    int n, k, i;
    int x1, x2;
    float median;
    
    scanf("%d", &n);
    
    a = (int*) malloc(sizeof(int) * (n+1));
    
    for(i=1; i<=n ; i++)
    {
    	scanf("%d", &a[i]);
    }
	
	if( n%2 != 0 ){
		k = n/2+1;
		median = selectpart(a, 1, n, k);
	}
	else{
		k = n/2;
		x1 = selectpart(a, 1, n, k);
		x2 = selectpart(a, 1, n, k+1);
		median = x1 + x2;
		printf("*** %d %d %f\n", x1, x2, median);
		median = median / 2;
		
	}
	
	
	    
    printf("Median : %f\n", median);
    return 0;
}
