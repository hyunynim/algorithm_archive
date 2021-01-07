#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;

	vector<string> seq(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];

	for (int i = 1; i < n; ++i) {
		if (seq[i - 1].back() != seq[i][0]) {
			printf("0");
			return 0;
		}
	}
	printf("1");
}
