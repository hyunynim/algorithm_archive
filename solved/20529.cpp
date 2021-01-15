#include<bits/stdc++.h>
using namespace std;
const char* mbti[] = { "ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP" 
						,"ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ" };
int d[16][16][16];
int dist(int a, int b, int c) {
	int res = 0;
	for (int i = 0; i < 4; ++i) {
		res += (mbti[a][i] != mbti[b][i]);
		res += (mbti[b][i] != mbti[c][i]);
		res += (mbti[c][i] != mbti[a][i]);
	}
	return res;
}
map<string, int> comp;
vector<int> cnt;
int ans;
void go(int toPick, vector<int>& pick) {
	if (toPick == 0) {
		ans = min(ans, d[pick[0]][pick[1]][pick[2]]);
		return;
	}
	for (int i = 0; i < 16; ++i) {
		if (cnt[i]) {
			--cnt[i];
			pick.push_back(i);
			go(toPick - 1, pick);
			pick.pop_back();
			++cnt[i];
		}
	}
}
int main() {
	for (int i = 0; i < 16; ++i) {
		comp[mbti[i]] = i;
		for (int j = 0; j < 16; ++j)
			for (int k = 0; k < 16; ++k)
				d[i][j][k] = dist(i, j, k);
	}

	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		char msg[11];
		cnt.resize(16);
		for (int i = 0; i < n; ++i) {
			scanf("%s", msg);
			++cnt[comp[msg]];
		}
		for (int i = 0; i < 16; ++i)
			cnt[i] = min(3, cnt[i]);

		ans = 1e9;

		vector<int> tmp;
		go(3, tmp);

		printf("%d\n", ans);
		cnt.clear();

	}
}
