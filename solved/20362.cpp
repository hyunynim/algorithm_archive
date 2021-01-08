#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; string str; cin >> n >> str;
	vector<vector<string>> seq(n);
	int idx = 0;
	string ansStr = "";
	for (int i = 0; i < n; ++i) {
		string s1, s2; cin >> s1 >> s2;
		seq[i].push_back(s1);
		seq[i].push_back(s2);
		if (s1 == str) {
			idx = i;
			ansStr = s2;
		}
	}
	int ans = 0;
	for (int i = 0; i < idx; ++i)
		if (ansStr == seq[i][1]) ++ans;
	cout << ans;
}
