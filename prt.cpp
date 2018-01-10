#include <iostream>
using namespace std;

int pattern[]={1,0,0,1};

void series(long x, long n) {
	int ptr;

	if ( (n-1)%2 == 0 ) {
		ptr = 2;
	} else {
		ptr = 1;
	}

	for (long i=1;i<=n;i++) {
		if (i==x) {
			cout << 2;
		} else {
			cout << pattern[ptr];
			ptr=(ptr+1)%4;
		}
	}
}

bool possible(long x, long n) {
	if ( n == 0 || n == 1 || n == 2 || n == 3 ) {
		return false;
	} else if ( n%4 == 0 || n%4 == 1 ) {
		if ( x == n ) {
			return true;
		} else if ( int(n/2) == x ) {
			return true;
		} else if ( int(n/2) + 1 == x ) {
			return true;
		}	return false;
	} else {
		if ( int(n/2) == x ) {
			return true;
		} else if ( int(n/2) + 1 == x ) {
			return true;
		}	return false;
	}

	return false;
}

int main() {
	freopen("testcase", "r", stdin);
	long t;
	cin >> t;

	long x, n;

	while(t--) {
		cin >> x >> n;
		if ( possible(x,n) ) {
			series(x,n);
		} else {
			cout << "impossible";
		}
		cout << endl;
	}

	return 0;
}