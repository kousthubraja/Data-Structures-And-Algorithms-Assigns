#include <stdio.h>
#include <stdlib.h>

void err(){
	printf("*** Error ***\n");
	exit(1);
}

int bsr(int A[], int k, int l, int h){
	int m;	
	if(l > h)
		return -1;
	else{
		m = (l + h) / 2;
		if(A[m] > k)
			return bsr(A, k, l, m - 1);
		else if(A[m] < k)
			return bsr(A, k, m+1, h);
		else
			return m;
	}
}

int max(int A[], int l, int h){
	int m;	
	if(l > h)
		return -1;
	else{
		m = (l + h) / 2;

		if(A[m] > A[m+1] && A[m]>A[m-1])
			return m;
		else{
			int p = max(A, l, m-1);
			if(p != -1)
				return p;
			else
				return max(A, m+1, h);
		}
	}
}


int main(){
	int mpos, n, i, k, found=0;
	int *a;
	time_t t;
	
	if(!scanf("%d", &n) || n<=0)
		err();
	
	a = (int*) malloc(sizeof(int)*n);
	
	if(!a)
		err();
	
	for(i=0;i<n;i++){
		if(!scanf("%d", &a[i]))
			err();
	}
	
	if(!scanf("%d", &k))
		err();
	t = time(NULL);
	mpos = max(a, 0, n-1);

	if(k > a[0])
		printf("%d\n", bsr(a, k, 0, mpos) );
	else
		printf("%d\n", bsr(a, k, mpos, n-1) );

	t = time(NULL) - t;
	printf("Running time : %f\n", (float)t/1000.0);
	
	
	return 0;
}


