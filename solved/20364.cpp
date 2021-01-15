#include<bits/stdc++.h>
using namespace std;
vector<int> p2(22);
vector<int> chk(1 << 22);
int next(int idx) {
	int tmp = idx;
	vector<int> res;
	while (idx > 1) {
		if (chk[idx])
			res.push_back(idx);
		idx >>= 1;
	}
	if (res.empty()) {
		chk[tmp] = 1;
		return 0;
	}
	return res.back();
}
int main() {
	int n, q; scanf("%d %d", &n, &q);
	p2[0] = 1;
	for (int i = 1; i < 22; ++i)
		p2[i] = p2[i - 1] * 2;
	for (int i = 0; i < q; ++i) {
		int a; scanf("%d", &a);
		printf("%d\n", next(a));
	}
}
