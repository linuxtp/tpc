/* 01 Knapsack problem*/
/* Given a set of items with value and weight, find the
 * maximum number of items that can fit into knapsack of
 * weight W with maximum value
 */


#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

int *weight, *value;
int dptable[1000][1000];


int knapsack(int W, int item) {
	
	int included = INT_MIN, excluded;

	if(item < 0 || W <= 0)
		return 0;
	if(dptable[W][item] != -1)
		return dptable[W][item];
	
	if(W-weight[item] >= 0)	
		included = value[item] + knapsack(W-weight[item], item-1);
	excluded = knapsack(W, item-1);
	
	dptable[W][item] = included > excluded ? included : excluded;	

	return dptable[W][item];
}


int main(void)
{
	int n, W, result;

	cout<<"Enter number of items: ";
	cin>>n;

	weight = new int[n+2];
	value = new int[n+2];
	memset(dptable, -1, sizeof(dptable[0][0])*1000000);

	cout<<"Enter item values ... "<<endl;
	for(int i=0; i<n; i++)
		cin>>value[i];
	cout<<"Enter item weights ... "<<endl;
	for(int i=0; i<n; i++)
		cin>>weight[i];

	cout<<"Enter knapsack weight: ";
	cin>>W;

	result = knapsack(W, n-1);
	cout<<"Knapsack value: "<<result<<endl;

	return 0;
}
