#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (seq[i] + seq[j] == 0) {
				printf("%d %d", seq[i], seq[j]);
				return 0;
			}
		}
	}
	printf("-1");

}