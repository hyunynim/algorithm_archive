#include<bits/stdc++.h>
using namespace std;
struct POS {
	int x, y;
};
bool chk[22];
vector<POS> seq;
POS s;
int ans, n, m, hh;
int dist(POS p1, POS p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
void go(int cur, int cnt, int h) {
	if(dist(seq[cur], seq.back()) <= h)
		ans = max(ans, cnt);

	for (int i = 0; i < seq.size() - 1; ++i) {
		if (!chk[i] && h - dist(seq[cur], seq[i]) >= 0) {
			chk[i] = 1;
			go(i, cnt + 1, h - dist(seq[cur], seq[i]) + hh);
			chk[i] = 0;
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &hh);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int num; scanf("%d", &num);
			if (num == 1) 
				s.x = i, s.y = j;
			if (num == 2) 
				seq.push_back({ i, j });
			
		}
	}
	seq.push_back({ s.x, s.y });
	go(seq.size() - 1, 0, m);

	printf("%d", ans);
}