#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int k; scanf("%d", &k);
		map<int, queue<int>> chk;
		priority_queue<pair<int, int>> l, h;
		char op[3]; int num;
		int cnt = 1;
		for (int i = 0; i < k; ++i) {
			scanf("%s %d", op, &num);
			if (op[0] == 'I') {
				chk[num].push(cnt);
				l.push({ -num, -cnt });
				h.push({ num, -cnt });
				++cnt;
			}
			else {
				if (~num) { 
					while (h.size() && chk[h.top().first].front() != -h.top().second)
						h.pop();
					if (h.empty()) continue;
					if (chk[h.top().first].front() == -h.top().second) {
						h.pop();
						chk[h.top().first].pop();
					}
				}
				else {
					if (l.size())
						printf("%d %d\n", -l.top().first, chk[-l.top().first].front());
					while (l.size() && chk[-l.top().first].front() != -l.top().second)
						l.pop();
					if (l.empty()) continue;
					if (chk[-l.top().first].front() == -l.top().second) {
						l.pop();
						chk[-l.top().first].pop();
					}
				}
			}
		}

		while (h.size() && chk[h.top().first].front() != -h.top().second)
			h.pop();
		while (l.size() && chk[-l.top().first].front() != -l.top().second)
			l.pop();
		if (l.empty() || h.empty())
			puts("EMPTY");
		else
			printf("%d %d\n", -l.top().first, h.top().first);
	}
}