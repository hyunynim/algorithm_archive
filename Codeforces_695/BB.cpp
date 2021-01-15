#include<bits/stdc++.h>
#include<random>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 10);

using namespace std;
int cchk(vector<int> & seq, int s) {
	if (s > 0 && s < seq.size() - 1)
		return (seq[s - 1] < seq[s] && seq[s] > seq[s + 1]) || (seq[s - 1] > seq[s] && seq[s] < seq[s + 1]);
	else
		return 0;
}
int chchk(vector<int>& seq) {
	int res = 0;
	for (int i = 1; i < seq.size(); ++i)
		res += cchk(seq, i);
	return res;
}
pair<int, int> solve2(vector<int>& seq) {
	int n = seq.size();
	int ans = 1e9;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = seq[i];
		for (int j = 1; j < 12; ++j) {
			seq[i] = j;
			if (ans > chchk(seq)) {
				ans = chchk(seq);
				idx = i;
			}
			seq[i] = tmp;
		}
		if (i) {
			seq[i] = seq[i - 1];
			if (ans > chchk(seq)) {
				ans = chchk(seq);
				idx = i;
			}
			seq[i] = tmp;
		}
		if (i < n - 1) {
			seq[i] = seq[i + 1];
			if (ans > chchk(seq)) {
				ans = chchk(seq);
				idx = i;
			}
			seq[i] = tmp;
		}
	}
	return { ans, idx };
}
bool check(int a, int b, int c) {
	if (a < b && b > c) {
		return true;
	}
	return a > b && b < c;
}
int solve1(vector<int> & s) {
	int size = s.size();
		std::vector<int> a(size);
		for (int i = 0; i < size; ++i) {
			a[i] = s[i];
		}
		int ans = 0;
		for (int i = 1; i < size - 1; ++i) {
			ans += check(a[i - 1], a[i], a[i + 1]);
		}
		int max_delta = 0;
		for (int i = 1; i < size - 1; ++i) {
			// case 1
			int case1 = check(a[i - 1], a[i], a[i + 1]);
			if (i - 2 >= 0 && check(a[i - 2], a[i - 1], a[i])) {
				++case1;
			}
			if (i + 2 < size) {
				bool before = check(a[i], a[i + 1], a[i + 2]);
				bool after = check(a[i - 1], a[i + 1], a[i + 2]);
				if (before && !after) {
					++case1;
				}
				if (!before && after) {
					--case1;
				}
			}
			// case 2
			int case2 = check(a[i - 1], a[i], a[i + 1]);
			if (i - 2 >= 0) {
				bool before = check(a[i - 2], a[i - 1], a[i]);
				bool after = check(a[i - 2], a[i - 1], a[i + 1]);
				if (before && !after) {
					++case2;
				}
				if (!before && after) {
					--case2;
				}
			}
			if (i + 2 < size && check(a[i], a[i + 1], a[i + 2])) {
				++case2;
			}
			case1 = std::max(case1, case2);

			max_delta = std::max(max_delta, case1);
		}

	return ans - max_delta;
}

int main() {
	while (1) {
		vector<int> seq(6);
		for (int i = 0; i < 12; ++i)
			seq[i] = d1(gen);
		//seq[0] = 10;
		//seq[1] = 7;
		//seq[2] = 2;
		//seq[3] = 6;
		//seq[4] = 1;
		//seq[5] = 4;
		int ans1 = solve1(seq);
		auto ans2 = solve2(seq);
		//printf("\n\n%d %d\n\n", ans2.first, ans2.second);
		if (ans1 != ans2.first) {
			puts("");
			for (auto i : seq)
				printf("%d ", i);
			printf("\n%d %d\n", ans1, ans2);
			printf("%d\n", ans2.second);
			puts("");
			system("pause");
		}
		seq.clear();
	}
}