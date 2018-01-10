#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long compute(long n) {
	long long data[n][n];
	long long sum=0, prev=INT_MAX;
	long long ptr;
	for (long i=0;i<n;i++) {
		for (long j=0;j<n;j++) {
			cin >> data[i][j];
		}
		sort(data[i], data[i] + n);
	}

	for (long i=n-1;i>=0;i--) {
		ptr=n-1;

		while(ptr >= 0) {
			if (prev > data[i][ptr] || i == 2) {
				prev=data[i][ptr];
				sum+=prev;
				break;
			} else {
				ptr--;
			}
		}
	}

	return sum;
}

int main() {
	freopen("testcase", "r", stdin);
	long t;
	cin >> t;

	long n;
	while(t--) {
		cin >> n;

		long long result=compute(n);
		cout << result << endl;
	}

	return 0;
}