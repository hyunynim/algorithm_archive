#include<bits/stdc++.h>
using namespace std;
int main() {
	while (1) {
		int n = (rand() % 100 + 1) * 2 - 1;
		vector<int> seq(n);
		for (int i = 0; i < n; ++i)
			seq.push_back(rand() % 10000 + 1);
		vector<int> tmp = seq;
		sort(seq.begin(), seq.end());
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (tmp[i] < tmp[j]) continue;
				else
					swap(tmp[i], tmp[j]);
			}
		}

		if (seq != tmp).
			puts("111111111");
	}
}