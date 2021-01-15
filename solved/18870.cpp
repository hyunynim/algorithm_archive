#include<bits/stdc++.h>
using namespace std;
map<int, int> comp;
int main() {
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	vector<int> tmp = seq;
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for (int i = 0; i < tmp.size(); ++i)
		comp[tmp[i]] = i;
	for (auto i : seq)
		printf("%d ", comp[i]);
}