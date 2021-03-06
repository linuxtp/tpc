
/* Codechef problem: https://www.codechef.com/problems/TEAMNAME
 */


#include <bits/stdc++.h>

using namespace std;

int _strtable[26][20005];
multimap<string, int> _suffixmap;

void _insert_to_map(string str) {
	/* insert pair to multimap
	 * <string without first char (suffix), first character>
	 */
	int fchar = str.at(0) - 97;
	str.erase(0, 1);
	_suffixmap.insert(pair<string, int> (str, fchar));
}



int _fill_strtable() {
	multimap<string, int> :: iterator itr;
	int _suffval = -1;
	string temp = "";

	/* Fill table, for each new suffix assign unique value
	 * _suffval
	 */

	for(itr = _suffixmap.begin(); itr != _suffixmap.end(); itr++) {
		if(temp.compare(itr->first) != 0) {
			_suffval += 1;
			temp = itr->first;
		}
		_strtable[itr->second][_suffval] = 1;
	}
	
	return _suffval+1;
}



int _count_goodnames(int n) {
	int count = 0;

	/* iterate over entire table, if we get (x1, y1) = 1
	 * and (x2, y2) = 1, then if (x2, y1) = 0 and (x1, y2) = 0.
	 * Then we found 2 non funny words
	 */

	for(int x1=0; x1<25; x1++) {
		for(int y1=0; y1<n; y1++) {
		
			for(int x2=x1+1; x2<26; x2++) {
				for(int y2=0; y2<n; y2++) {
					if((_strtable[x1][y1] && _strtable[x2][y2]) &&
						(!_strtable[x2][y1] && !_strtable[x1][y2])) {
							count += 2;
					}
				}
			}

		}
	}
	return count;
}



int main(void)
{
	int tc, n;
	string str;

	cin>>tc;
	while(tc--) {
		_suffixmap.clear();
		memset(_strtable, 0, sizeof(_strtable[0][0])*26*20005);
		cin>>n;

		for(int i=0; i<n; i++) {
			cin>>str;
			_insert_to_map(str);
		}

		cout<<_count_goodnames(_fill_strtable())<<endl;
	}

	return 0;
}
