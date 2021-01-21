#include<bits/stdc++.h>
using namespace std;
char msg[101010];
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		scanf("%s", msg);

		string str = msg;
		int l = 0;
		for (; l < str.size(); ++l) {
			if (str[l] == '0');
			else 
				break;
		}
		int r = str.size() - 1;
		while (str.size()) {
			if (str.back() == '1') 
				--r;
			else 
				break;
			str.pop_back();
		}
		for (int i = 0; i < l; ++i)
			printf("0");
		if (r - l > 0)
			printf("0");
		for (int i = r; i < n - 1; ++i)
			printf("1");
		puts("");
	}
}