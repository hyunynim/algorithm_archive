#include<bits/stdc++.h>
using namespace std;
bool chk[33];
bool PrimeCheck(int num) {
	if (num < 2) return 0;
	else if (num == 2) return 1;
	for (int i = 2; i * i <= num; ++i)
		if (num % i == 0) return 0;
	return 1;
}
vector<int> adj[22];
vector<vector<int>> ans;
void go(int n, vector<int>& seq) {
	if (n == 0) {
		ans.push_back(seq);
		return;
	}
	int cur = seq.back();
	for (int i = 0; i < adj[cur].size(); ++i) {
		int nx = adj[cur][i];
		if (chk[nx]) continue;
		chk[nx] = 1;
		seq.push_back(nx);
		go(n - 1, seq);
		chk[nx] = 0;
		seq.pop_back();
	}
}
int main() {
	for (int i = 2; i < 33; ++i)
		chk[i] = PrimeCheck(i);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			if (chk[i + j])
				adj[i].push_back(j);
		}
	}
	memset(chk, 0, sizeof(chk));
	vector<int> tmp;
	chk[1] = 1;
	tmp.push_back(1);
	go(n - 1, tmp);
	for(int i = 0; i<ans.size(); ++i){
		for (int j = 0; j < ans[i].size(); ++j) 
			printf("%d%s", ans[i][j], j != ans[i].size() - 1 ? " " : "");
		
		if (i != ans.size() - 1)
			puts("");

	}
}