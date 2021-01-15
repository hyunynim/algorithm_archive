#include<bits/stdc++.h>
using namespace std;
int d[1 << 20];
int board[20][20];
bool chk[20];
int n;
int go(int s, int stat) {
	if (s == n) {
		if (stat == (1 << n) - 1) return 0;
		else return 1e9;
	}
	int& res = d[stat];
	if (~res) return res;
	res = 1e9;
	for (int i = 0; i < n; ++i) {
		if (chk[i]) continue;
		chk[i] = 1;
		res = min(res, go(s + 1, stat | (1 << i)) + board[s][i]);
		chk[i] = 0;
	}
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &board[i][j]);
	printf("%d", go(0, 0));
}
