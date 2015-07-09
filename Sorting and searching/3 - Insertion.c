#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long int *a, i, j, n=5, key, invcount=0;
    time_t t;
    
    if(!scanf("%ld", &n) || n<=0)
		err();
	
	a = (long int*) malloc(sizeof(long int)*n);
	
    for(i=0;i<n;i++){
		if(!scanf("%ld", &a[i]))
			err();
	}
    t = time(NULL);
    
    for(j=2;j<=n;j++){
        key = a[j];
        i = j - 1;
        while(i > 0 && a[i] > key){
            a[i + 1] = a[i];
            invcount++;
            i--;
        }
        a[i + 1] = key;
    }
    
    t = time(NULL) - t;
    
    printf("\nSorted list :\n");
    for(i=1;i<=n;i++)
        printf("%ld ", a[i]);
 	
 	printf("\nNo of inversions : %ld\n",invcount);
 	printf("Running time : %f\n", (float)t/1000.0); 
    return 0;
}
