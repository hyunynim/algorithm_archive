#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, x, k; scanf("%d %d %d", &n, &x, &k);
	vector<int> seq(n + 1);
	for (int i = 0; i <= n; ++i)
		seq[i] = i;
	for (int i = 0; i < k; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		swap(seq[a], seq[b]);
	}
	for (int i = 1; i <= n; ++i) {
		if (seq[i] == x) {
			printf("%d", i); return 0;
		}
	}
}