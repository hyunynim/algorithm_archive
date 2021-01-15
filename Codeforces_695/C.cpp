#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n1, n2, n3; scanf("%d %d %d", &n1, &n2, &n3);
	vector<ll> s1(n1), s2(n2), s3(n3);
	for (int i = 0; i < n1; ++i)
		scanf("%lld", &s1[i]);
	for (int i = 0; i < n2; ++i)
		scanf("%lld", &s2[i]);
	for (int i = 0; i < n3; ++i)
		scanf("%lld", &s3[i]);
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	sort(s3.begin(), s3.end());
	deque<int> q[3];
		for (auto i : s1)
			q[0].push_back(i);
	for (auto i : s2)
		q[1].push_back(i);
	for (auto i : s3)
		q[2].push_back(i);
	bool flag = 0;
	ll ans = 0;
	while (q[0].size() || q[1].size() || q[2].size()) {
		int c = 0, ci = 0, cm = 1e9, cmi = 0, cM = -1e9, cMi = 0, idx = 0;
		for (int i = 0; i < 3; ++i) {
			c += (!q[i].empty());
			if (q[i].size()) ci = i;
			if (q[i].size() && q[i].front() < cm) {
				cm = q[i].front();
				cmi = i;
			}
			if (q[i].back() && q[i].back() > cM) {
				cM = q[i].back();
				cMi = i;
			}
		}
		if (c == 1) {
			for (int i = 0; i < 3; ++i) {
				if (q[i].size()) {
					idx = i; break;
				}
			}
			if(q[idx].size() == 1)
				printf("%d", q[ci].front());

			return 0;
		}
		if (!flag) {
			ans += (cm - cM);
			q[cmi].pop_front();
			q[cMi].pop_back();
		}
		else {
			ans = cM - ans;
			q[cMi].pop_back();
		}
		flag ^= 1;
	}
}
