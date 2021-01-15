#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		string str = "";
		int cnt = 9;
		bool flag = 0;
		for (int i = 0; i < n; ++i) {
			str.push_back('0' + cnt);
			if (flag) ++cnt;
			else --cnt;
			cnt %= 10;
			if (cnt == 8) flag = 1;
		}
		printf("%s\n", str.c_str());
	}
}