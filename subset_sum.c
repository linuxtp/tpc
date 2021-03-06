/* Subset sum problem using dynamic programming*/

/* Set of non negative numbers is given and a value SUM.
 * Check if there is a subset that add up to SUM
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **dptable;
int *arr;

int subset_sum(int n, int sum) {
	/*base conditions start
	 */
	if(n == 0) {
		if(sum == 0) return 1;
		else return 0;
	}

	if(sum == 0) return 1;
	if(sum < 0) return 0;

	if(dptable[n][sum] != -1) return dptable[n][sum];
	/*base end*/

	/* We can either choose the element or ignore it*/
	dptable[n][sum] = subset_sum(n-1, sum-arr[n]) ||
				subset_sum(n-1, sum);

	return dptable[n][sum];

}

int main(void)
{
	int n, sum;
	char status;

	printf("Enter number of elements ... \n");
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*(n+2));
	printf("Enter set elements .. \n");
	for(int i=1; i<=n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter sum .. \n");
	scanf("%d", &sum);

	/*Initialize dp table with extra region, set to -1*/
	dptable = (int**)malloc(sizeof(int*)*(n+2));
	for(int i=0; i<n+2; i++) {
		dptable[i] = (int*)malloc(sizeof(int)*(sum+2));
		memset(dptable[i], -1, sizeof(int)*(sum+2));
	}

	status = subset_sum(n, sum);
	status ? printf("subset exist\n") : printf("no subset\n");

	return 0;
}
