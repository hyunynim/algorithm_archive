#include<bits/stdc++.h>
using namespace std;
vector<int> pre(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else {
			pi[i] = 0;
		}
	}
	return pi;
}
vector<int> kmp(string s, string p) {
	auto pi = pre(p);
	vector<int> ans;
	int n = s.size();
	int m = p.size();
	int i = 0;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j += 1;
			}
		}
	}
	return ans;
}
int main() {
	int n, m; scanf("%d %d", &n, &m);
	string s1 = "", s2;
	cin >> s2;
	for (int i = 0; i < n; ++i)
		s1 += "IO";
	s1.push_back('I');
	auto res = kmp(s2, s1);
	printf("%d", res.size());
}