#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long max_of(long arr[], long n) {
	long max=arr[0];

	for (long i=1;i<n;i++) {
		if ( max < arr[i] ) {
			max = arr[i];
		}
	}

	return max;
}

long max_sub(long arr[], long n, long k) {
	long prev_sum, max_sum, pos_sum, sum;
	prev_sum = max_sum = INT_MIN;
	sum = 0;
	long reg = 0;
	bool first_neg = true;

	for (long i=0;i<n;i++) {
		if ( arr[i] >= 0 ) {
			sum+=arr[i];
			if ( max_sum <= sum ) {
				max_sum = sum;
				reg=i;
			}
		} else {
			if ( first_neg ) {
				pos_sum = sum;
			}

			if ( max_sum <= sum ) {
				max_sum = sum;
				reg=i;
			}

			prev_sum = sum;
			sum = 0;
			first_neg = false;
		}
	}

	if (first_neg) {
		return max_sum*k;
	} else {
		if ( max_sum == prev_sum && reg == n-1 ) {
			return max_sum + pos_sum;
		} else {
			return max_sum;
		}
	}
}

int main() {
	freopen("testcase", "r" , stdin);
	int t;
	cin >> t;
 
	long n, k, result;
	bool all_neg = true;
	while(t--) {
		cin >> n;
		cin >> k;
 		long arr[n];

 		for (long i=0;i<n;i++) {
 			cin >> arr[i];

 			if ( arr[i] > 0 ) {
 				all_neg = false;
 			}
 		}

 		if ( all_neg ) {
 			result = max_of(arr, n);
 		} else {
 			result = max_sub(arr, n, k);
 		}

 		cout << result << endl;
 		all_neg = true;
	}
 
	return 0;
}