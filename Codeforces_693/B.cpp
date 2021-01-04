#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> seq(n);
		int one = 0, two = 0, sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &seq[i]);
			sum += seq[i];
			if (seq[i] == 1)
				++one;
			else
				++two;
		}
		if (sum % 2 || (one == 0 && two % 2))
			puts("NO");
		else
			puts("YES");
	}
}