#include<bits/stdc++.h>
using namespace std;
int board[120][101];
int chk[5][101][101];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int ff[] = { 0, 0, 2, 1, 3 };
struct POS {
	int x, y, f;
};
int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &board[i][j]);
	int sx, sy, sf;	scanf("%d %d %d", &sx, &sy, &sf);
	int ex, ey, ef; scanf("%d %d %d", &ex, &ey, &ef);
	--sx, --sy, --ex, --ey;
	sf = ff[sf];
	ef = ff[ef];
	queue<POS> q;
	q.push({ sx, sy, sf });
	chk[sf][sx][sy] = 1;
	while (q.size()) {
		auto cur = q.front(); q.pop();
		int x = cur.x, y = cur.y, f = cur.f;
		if (x == ex && y == ey && f == ef) {
			printf("%d", chk[f][x][y] - 1);
			return 0;
		}
		for (int i = 0; i < 4; ++i) {
			if (i == f) {
				for (int j = 1; j <= 3; ++j) {
					int nx = x + dx[i] * j;
					int ny = y + dy[i] * j;
					if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] == 0 && chk[f][nx][ny] == 0) {
						chk[f][nx][ny] = chk[f][x][y] + 1;
						q.push({ nx, ny, f });
					}
					else if (board[nx][ny]) break;
				}
			}
			else {
				if ((abs(i - f) == 1 || abs(i - f) == 3) && chk[i][x][y] == 0) {
					chk[i][x][y] = chk[f][x][y] + 1;
					q.push({ x, y, i });
				}
			}
		}
	}
	printf("-1");
}