#include<bits/stdc++.h>
using namespace std;
string str, tmp;
bool go(int i1, int i2, bool r) {
	if (i2 == tmp.size())
		return r;
	if (i1 == str.size())
		return 0;
	if (str[i1] == tmp[i2]) {
		if (go(i1 + 1, i2 + 1, r)) 
			return 1;
		if (go(i1 + 1, i2, r | 1))
			return 1;
	}
	return go(i1 + 1, i2, r);
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		map<string, int> chk;
		int sum1[111] = { 0 }, sum0[111] = { 0 };
		vector<int> one, zero;
		int n, q; scanf("%d %d", &n, &q);
		vector<string> seq(n);
		char msg[111];
		scanf("%s", msg);
		str = msg;
		for (int i = 0; i < q; ++i) {
			int l, r; scanf("%d %d", &l, &r);
			tmp = str.substr(l - 1, r - l + 1);
			int res = chk[tmp];
			if (res) {
				if (~res)
					puts("YES");
				else
					puts("NO");
			}
			else {
				if (go(0, 0, 0)) {
					chk[tmp] = 1;
					puts("YES");
				}
				else {
					chk[tmp] = -1;
					puts("NO");
				}
			}
		}
		seq.clear();
	}
}