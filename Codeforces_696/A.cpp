#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		char str[101010]; scanf("%s", str);
		string ans = "1";
		for (int i = 1; i < n; ++i) {
			int prev = str[i - 1] + ans[i - 1] - '0' - '0';
			switch (prev) {
			case 2:
				if (str[i] == '1')
					ans.push_back('0');
				else
					ans.push_back('1');
				break;
			case 1:
				if (str[i] == '1')
					ans.push_back('1');
				else
					ans.push_back('0');
				break;
			case 0:
				ans.push_back('1');
				break;
			}
		}
		printf("%s\n", ans.c_str());
	}
}