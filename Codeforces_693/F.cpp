#include<bits/stdc++.h>
using namespace std;
int d[4][404040];
int board[404040];
int n, m;
int cnt;
bool go(int s, int stat) {
	++cnt;
	if (s == 2 * n) {
		if (stat == 0) return 1;
		else return 0;
	}
	int& res = d[stat][s];
	if (~res) return res;
	if (stat & 1 || board[s]) {
		res = go(s + 1, stat >> 1);
		if (res) return 1;
	}
	else {
		if (s % 2) {
			if (s + 2 < 2 * n && board[s + 2] == 0) {
				res = go(s + 1, (stat >> 1) | 2);
				if (res) return 1;
			}
		}
		else {
			if (s + 1 < 2 * n && board[s + 1] == 0) {
				res = go(s + 2, 0);
				if (res) return 1;
			}
			if (s + 2 < 2 * n && board[s + 2] == 0) {
				res = go(s + 1, (stat >> 1) | 2);
				if (res) return 1;
			}
		}
	}
	return 0;
}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		memset(d, -1, sizeof(d));
		memset(board, 0, sizeof(board));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; ++i) {
			int r, c; scanf("%d %d", &r, &c);
			--c;
			if (r == 2)
				board[c * 2] = 1;
			else
				board[c * 2 + 1] = 1;
		}
		if (go(0, board[0]))
			puts("YES");
		else
			puts("NO");
		printf("\t%d\n", cnt);
	}
}