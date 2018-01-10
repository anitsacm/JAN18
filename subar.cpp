#include <iostream>
#include <limits.h>
using namespace std;
 
long max_sub_array(long n, long k) {
	long sum=0, temp;
	long prev_sum=0, pos_sum=0;
	bool flag=true;
	long neg=LONG_MIN;
	bool all_neg=true;
 
	while(n--) {
		cin >> temp;
		if (temp >= 0) {
			sum+=temp;

			if (all_neg) {
				all_neg=false;
			}

		} else {
			if (neg < temp) {
				neg=temp;
			}

			if (flag) {
				pos_sum=sum;
			}
 
			if (prev_sum < sum) {
				prev_sum=sum;
			}
			sum=0; 
			flag=false;
		}
	}
 
	if (flag) {
		return sum*k;
	}
 
 	if (all_neg) {
 		return neg;
 	}
 	
	sum+=pos_sum;
	return prev_sum > sum ? prev_sum:sum;
}
 
int main() {
	freopen("testcase", "r" , stdin);
	int t;
	cin >> t;
 
	long n, k, result;
	while(t--) {
		cin >> n;
		cin >> k;
 
		result=max_sub_array(n,k);
		cout << result << endl;
	}
 
	return 0;
} 