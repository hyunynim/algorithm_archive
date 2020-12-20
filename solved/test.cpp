#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P {
	int s, e;
};
bool cmp1(P p1, P p2) {
	return p1.e == p2.e ? p1.s < p2.s : p1.e < p2.e;
}
void solve() {
	int n; scanf("%d", &n);
	vector<P> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &seq[i].s, &seq[i].e);
	sort(seq.begin(), seq.end(), cmp1);
	int ans = 0, e = 0;
	for (int i = 0; i < n; ++i) {
		if (seq[i].s >= e) {
			e = seq[i].e;
			++ans;
		}
	}
	printf("%d", ans);
}
int main() {
	solve();
	return 0;
}