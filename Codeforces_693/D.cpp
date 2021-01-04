#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> seq(n);
		priority_queue<int> even, odd;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &seq[i]);
			if (seq[i] % 2)
				odd.push(seq[i]);
			else
				even.push(seq[i]);
		}
		int cnt = 0;
		ll scoreA = 0, scoreB = 0;
		while (even.size() || odd.size()) {
			if (cnt % 2 == 0) {
				if (even.empty()) 
					odd.pop();
				else if (odd.empty()) {
					scoreA += even.top();
					even.pop();
				}
				else {
					if (even.top() > odd.top()) {
						scoreA += even.top();
						even.pop();
					}
					else
						odd.pop();
				}
			}
			else {
				if (odd.empty()) 
					even.pop();
				else if (even.empty()) {
					scoreB += odd.top();
					odd.pop();
				}
				else {
					if (odd.top() > even.top()) {
						scoreB += odd.top();
						odd.pop();
					}
					else
						even.pop();
				}				
			}
			++cnt;
		}
		if (scoreA > scoreB)
			puts("Alice");
		else if (scoreA < scoreB)
			puts("Bob");
		else
			puts("Tie");
	}
}