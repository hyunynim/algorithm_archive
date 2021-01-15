#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	for (int i = 0; i < m; ++i) {
		int d; scanf("%d", &d);
		auto idx = lower_bound(seq.begin(), seq.end(), d);
		if (idx == seq.end())
			puts("-1");
		else {
			if (*idx == d)
				printf("%d\n", idx - seq.begin());
			else
				puts("-1");
		}


	}
}