#include<bits/stdc++.h>
using namespace std;
int chk[222];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<char> str(n);
	char msg[10];
	int cur = 0;
	for (int i = 0; i < k; ++i) {
		int num; scanf("%d %s", &num, msg);
		cur += num;
		cur %= n;
		if (str[cur] != msg[0] && (str[cur] || chk[msg[0]])) {
			printf("!"); return 0;
		}
		str[cur] = msg[0];
		chk[msg[0]] = 1;
	}
	for (int i = cur; i >= 0; --i)
		printf("%c", str[i] ? str[i] : '?');
	for (int i = n - 1; i > cur; --i)
		printf("%c", str[i] ? str[i] : '?');
}