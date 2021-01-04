#include<bits/stdc++.h>
using namespace std;
vector<pair<vector<int>, int>> numbers;
map<char, int> comp;
vector<int> s2v(string& str) {
	vector<int> res;
	vector<int> tmp;
	for (int i = 0; i < str.size(); ++i) {
		if ('0' <= str[i] && str[i] <= '9') 
			tmp.push_back(str[i] - '0');
		else {
			if (tmp.size()) {
				res.push_back(-numbers.size());
				numbers.push_back({ tmp, numbers.size() });
				tmp.clear();
			}
			res.push_back(comp[str[i]]);
		}
	}
	if (tmp.size()) {
		res.push_back(-numbers.size());
		numbers.push_back({ tmp, numbers.size() });
		tmp.clear();
	}
	return res;
}
int main() {
	int cnt = 1000000;
	for (int i = 'A'; i <= 'Z'; ++i) {
		comp[i] = cnt++;
		comp[i - 'A' + 'a'] = cnt++;
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<string> seq(n);
	vector<pair<vector<int>, int>> cmp;
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
		cmp.push_back({ s2v(seq[i]), i });
	}
	sort(numbers.begin(), numbers.end(), [](pair<vector<int>, int> v1, pair<vector<int>, int> v2) {
		if (v1.first.size() != v2.first.size()) return v1.first.size() < v2.first.size();
		for (int i = 0; i < v1.first.size(); ++i) {
			if (v1.first[i] > v2.first[i])
				return false;
		}
			return true;
		});
	vector<int> numbersComp(numbers.size());
	for (int i = 0; i < numbers.size(); ++i) 
		numbersComp[numbers[i].second] = i;
	for (int i = 0; i < cmp.size(); ++i)
		for (int j = 0; j < cmp[i].first.size(); ++j)
			if (cmp[i].first[j] <= 0)
				cmp[i].first[j] = numbersComp[-cmp[i].first[j]];
	sort(cmp.begin(), cmp.end());
	for (auto i : cmp)
		cout << seq[i.second] << '\n';

}