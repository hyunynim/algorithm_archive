#include<bits/stdc++.h>
using namespace std;
map<string, string> comp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		comp[s1] = s2;
	}
	while (m--) {
		string str; cin >> str;
		cout << comp[str] << '\n';
	}
}