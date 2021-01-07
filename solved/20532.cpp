#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adj[101010];
vector<int> seq;
int n;
ll ans;
bool chk[101010];
int d1[101010], d2[101010];
bool check(int a, int b) {
	return a % b == 0 || b % a == 0;
}

vector<int> GetDiv(int num) {
	if (num == 1) return { 1 };
	vector<int> seq;
	for (int i = 1; i * i <= num; ++i)
		if (num % i == 0) seq.push_back(i);
	int st = seq.size() - (seq.back() * seq.back() == num ? 2 : 1);
	for (int i = st; i >= 0; --i) {
		seq.push_back(num / seq[i]);
	}
	return seq;
}

void go(int s) {
	auto div = GetDiv(seq[s]);
	ans += d1[seq[s]];
	for(auto i : div){
		++d1[i];
		if(seq[s] != i)
			ans += d2[i];
	}
	++d2[seq[s]];
	
	for (int i = 0; i < adj[s].size(); ++i) {
		int nx = adj[s][i];
		go(nx);
	}
	--d2[seq[s]];
	for (auto i : div)
		--d1[i];
}
; int main() {
	scanf("%d", &n);
	seq.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &seq[i]);
	for (int i = 2; i <= n; ++i) {
		int a; scanf("%d", &a);
		adj[a].push_back(i);
	}
	
	go(1);
	printf("%lld", ans);
}
