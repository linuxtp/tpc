
#include <iostream>

using namespace std;
#define PLISTSIZE 16000000

bool isprime[PLISTSIZE];
int prime_list[1000002];

void populate_plist() {
	unsigned long long itr = 2;
	
	while(itr < PLISTSIZE) {
		while(isprime[itr] == true)
			itr++;

		for(unsigned long long i=itr*itr; i<PLISTSIZE; i+=itr)
			isprime[i] = true;

		itr++;	
	}

	for(int itr=2, i=1; itr<PLISTSIZE && i<1000001; itr++) {
		if(!isprime[itr]) {
			prime_list[i++] = itr;
		}	
	}

}

int main(void)
{
	int tc, k;

	//true means not prime, false means prime
	isprime[0] = isprime[1] = true;
	populate_plist();

	cin>>tc;
	while(tc--) {
		cin>>k;
		cout<<prime_list[k]<<endl;
	}

	return 0;
}
