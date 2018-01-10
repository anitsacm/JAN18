#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	long x;
	long a,b,c,d;

	while(t--) {
		cin >> a >> b >> c >> d;

		if ( a+b == c+d || a+c == b+d ) {
			cout << "YES";
		} else {
			cout << "NO";
		}

		cout << endl;
	}
	return 0;
}