#include<bits/stdc++.h>
using namespace std;
int chk[2525][2525];
vector<int> adj[2525];
char msg[2525];
int d[2525];
int c = 0;
void printChk(int sz) {
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j)
			printf("%d ", chk[i][j]);
		puts("");
	}
}
bool pal(int l, int r) {
	if (l >= r) return 1;
	int& res = chk[l][r];
	if (~res) return res;
	res = 0;
	res = pal(l + 1, r - 1) && msg[l] == msg[r];
	if (res)
		adj[l].push_back(r + 1);

	pal(l + 1, r);
	pal(l, r - 1);
	return res;
}
void makeTest() {
	freopen("1.in", "w", stdout);
	for (int i = 0; i < 2500; ++i)
		printf("%c", 'a' + (rand() % 26));
}
int main() {
	//makeTest(); return 0;
	//freopen("1.in", "r", stdin);

	memset(chk, -1, sizeof(chk));
	scanf("%s", msg);
	int sz = 0;
	for (; msg[sz]; ++sz) {
		chk[sz][sz] = 1;
		adj[sz].push_back(sz);
	}
	pal(0, sz - 1);
	queue<int> q;
	q.push(0);
	d[0] = 1;
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (cur == sz) {
			printf("%d", d[cur] - 1);
			return 0;
		}
		for (int i = 0; i < adj[cur].size(); ++i) {
			int nx = adj[cur][i];
			if (d[nx] == 0) {
				d[nx] = d[cur] + 1;
				q.push(nx);
			}
		}
	}
}