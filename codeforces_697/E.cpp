#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
typedef uniform_int_distribution<int> ud;
random_device rd;
mt19937 gen(rd());
ud d1(1, 1e2);
const ll mod = 1e9 + 7;
ll d[1010][1010];
void pre(){
	d[0][0] = 1;
	for (int i = 1; i < 1010; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (0 < j)
				d[i][j] += d[i - 1][j - 1];
			d[i][j] += d[i - 1][j];
			d[i][j] %= mod;
		}
	}
}
long long memo[1010][1010];
long long comb(int n, int r)
{
	long long res = memo[n][r];
	if (n == r || r == 0 || n == 0)
		return memo[n][r] = 1;
	if (r == 1 || n - r == 1)
		return n;
	if (res == -1)
	{
		res = 0;
		res += comb(n - 1, r) % 1000000007 + comb(n - 1, r - 1) % 1000000007;
		memo[n][r] = res;
		return res;
	}
	else
		return res;
}
ll solve2(int n, int m, vector<int>& a) {
		memset(memo, -1, sizeof(memo));
		int i = 0;
		sort(a.begin(), a.end());
		int idx = n - m;
		int num = a[idx];
		int cnt = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i] == num)
				cnt++;
			if (a[i] > num)
				break;
		}
		int us = m - (n - i);
		return comb(cnt, us) % 1000000007;
}
ll solve1(int n, int k, vector<int> & seq) {
	vector<int> cnt(1010);
	for (int i = 0; i < n; ++i) 
		++cnt[seq[i]];
	
	sort(seq.begin(), seq.end());
	seq.erase(unique(seq.begin(), seq.end()), seq.end());
	reverse(seq.begin(), seq.end());

	ll res = 0;
	vector<int> tmp;
	int sum = 0;
	for (int i = 0; i < seq.size(); ++i) {
		sum += cnt[seq[i]];
		tmp.push_back(cnt[seq[i]]);
		if (sum >= k) break;
	}
	if (sum < k) {
		return 0;
	}
	else {
		if (sum == k)
			return 1;
		else {
			if (tmp.size() == 1) {
				return d[tmp[0]][k];
			}
			else {
				for (int i = 0; i < tmp.size() - 1; ++i)
					k -= tmp[i];
				return d[tmp.back()][k];
			}
		}
	}
}
int main() {
	pre();
	while (1) {
		int n = d1(gen);
		vector<int> seq(n);
		ud d2(1, n);
		for (int i = 0; i < n; ++i)
			seq[i] = d2(gen);
		int k = d2(gen);
		if (solve1(n, k, seq) != solve2(n, k, seq)) {
			printf("%d %d\n", n, k);
			for (int i = 0; i < n; ++i)
				printf("%d ", seq[i]);
			puts("");
			system("pause");
		}
	}
}