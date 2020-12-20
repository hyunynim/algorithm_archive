#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#include<chrono>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
mt19937 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());
/*Templates end*/
char board[1010][1010];
int d[1010][1010];
int sum[2][1010][1010];
set<int> chk[2][1010];
struct POS{
    int x, y;
};
void visit(int x, int y){
    chk[0][x].erase(y);
    chk[1][y].erase(x);
}
void solve(){
    //TODO here
	memset(d, 0x3f, sizeof(d));
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			chk[0][i].insert(j);
			chk[1][j].insert(i);
		}
	}
	for (int i = 0; i < n; ++i)
		scanf("%s", board[i]);
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			sum[1][i + 1][j + 1] = sum[1][i + 1][j] + (board[i][j] == '#');
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			sum[0][j + 1][i + 1] = sum[0][j][i + 1] + (board[j][i] == '#');

	int sx, sy, ex, ey;
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	queue<POS> q;
	q.push({ sx, sy });
	visit(sx, sy);
	d[sx][sy] = 0;
	while (q.size()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		if (x == ex && y == ey) {
			printf("%d", d[x][y]);
			return;
		}
		while (1) {
			auto it = chk[0][x].lower_bound(y);
			auto& cur = chk[0][x];
			if (it == cur.end()) break;
			int ny = *it;
			if (ny - y > k) break;
			if (sum[1][x][ny] - sum[1][x][y - 1]) break;
			visit(x, ny);
			if (d[x][ny] > d[x][y] + 1) {
				d[x][ny] = d[x][y] + 1;
				q.push({ x, ny });
			}
		}
		while (1) {
			auto it = chk[0][x].lower_bound(y);
			auto& cur = chk[0][x];
			if (it == cur.begin()) break;
			--it;
			int ny = *it;
			if (y - ny > k) break;
			if (sum[1][x][y] - sum[1][x][ny - 1]) break;
			visit(x, ny);
			if (d[x][ny] > d[x][y] + 1) {
				d[x][ny] = d[x][y] + 1;
				q.push({ x, ny });
			}
		}
		while (1) {
			auto it = chk[1][y].lower_bound(x);
			auto& cur = chk[1][y];
			if (it == cur.end()) break;
			int nx = *it;
			if (nx - x > k) break;
			if (sum[0][nx][y] - sum[0][x - 1][y]) break;
			visit(nx, y);
			if (d[nx][y] > d[x][y] + 1) {
				d[nx][y] = d[x][y] + 1;
				q.push({ nx, y });
			}
		}
		while (1) {
			auto it = chk[1][y].lower_bound(x);
			auto& cur = chk[1][y];
			if (it == cur.begin()) break;
			--it;
			int nx = *it;
			if (x - nx > k) break;
			if (sum[0][x][y] - sum[0][nx - 1][y]) break;
			visit(nx, y);
			if (d[nx][y] > d[x][y] + 1) {
				d[nx][y] = d[x][y] + 1;
				q.push({ nx, y });
			}
		}
	}
	printf("-1");
}
int main(){
#ifdef LOCAL
    //Run in local
	freopen("input.txt", "r", stdin);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
} 
