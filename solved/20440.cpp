#include<bits/stdc++.h>
using namespace std;
int sum[2020202];
struct TIME {
	int s, e;
};
void test() {
	freopen("1.txt", "w", stdout);
	int n = 1000000;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		if (i >= n - 2)
			printf("2000000000 2100000000\n");
		else
			printf("%d %d\n", (i * 2), (i * 2) + 1);
			
	}
}
int main() {
	//test(); return 0;
	freopen("1.txt", "r", stdin);
	int n; scanf("%d", &n);
	vector<TIME> seq(n);
	vector<int> comp;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &seq[i].s, &seq[i].e);
		comp.push_back(seq[i].s);
		comp.push_back(seq[i].e);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	
	for (int i = 0; i < n; ++i) {
		int idx = lower_bound(comp.begin(), comp.end(), seq[i].s) - comp.begin();
		++sum[idx];
		idx = lower_bound(comp.begin(), comp.end(), seq[i].e) - comp.begin();
		--sum[idx];
	}
	for (int i = 1; i < 2020202; ++i) 
		sum[i] += sum[i - 1];
	
	int m = sum[0], s = 0, e = 0;
	for (int i = 1; i < 2020202; ++i) {
		if (sum[i] > m) {
			m = sum[i];
			s = e = i;
		}
		else if (sum[i] == m && e == i - 1) {
			e = i;
		}
	}
	printf("%d\n%d %d", sum[s], comp[s], comp[e + 1]);
}
