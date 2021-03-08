
/* Primality test
 */

#include <iostream>

using namespace std;

bool primality_test(int n) {
	if(n == 1)
		return false;
	for(int i=2; i*i <= n; i++) {
		if(n%i == 0)
			return false;
	}
	
	return true;
}

int main(void)
{
	int tc, n;

	cin>>tc;
	while(tc--) {
		cin>>n;
		primality_test(n) ? cout<<"yes" : cout<<"no";
		cout<<endl;
	}

	return 0;
}
