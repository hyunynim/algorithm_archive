#include<bits/stdc++.h>
using namespace std;
int d[4][1010];
int n;
int cnt = 0;
void go(int toPick, vector<int>& p) {
	if (toPick == 0) {
		bool chk = 0;
		for (int i = 1; i < p.size(); ++i) {
			if (p[i] == 2) {
				chk = 1;
				break;
			}
		}
		for (int i = 1; i < p.size(); ++i) {
			if (p[i - 1] == 2 && p[i] == 2) {
				chk = 0;
				break;
			}
		}
		for (int i = 2; i < p.size(); ++i) {
			if (p[i - 2] && p[i - 1] && p[i]) {
				chk = 0;
				break;
			}
		}
		if (chk) {
			++cnt;
			for (auto i : p)
				printf("%d ", i);
			puts("");
		}
		return;
	}
	if (p.empty()) {
		p.push_back(0);
		go(toPick - 1, p);
	}
	else {
		for (int i = 0; i < 3; ++i) {
			p.push_back(i);
			go(toPick - 1, p);
			p.pop_back();
		}

	}
}
int main() {
	vector<int> tmp;
	go(7, tmp);
	printf("%d", cnt);
}