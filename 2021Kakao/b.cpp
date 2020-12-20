#include<bits/stdc++.h>
using namespace std;
void chk(vector<int>& seq, int cnt, vector<int>& ans, vector<int> & tmp) {
	vector<int> p(tmp.size());
	if (tmp.size() < cnt) return;
	for (int i = 0; i < cnt; ++i)
		p.pop_back();
	for (int i = 0; i < cnt; ++i)
		p.push_back(1);
	vector<int> temp;
	int M = 2;
	do {
		int c = 0;
		for (int i = 0; i < p.size(); ++i)
			c |= (p[i] << (tmp[i]));
		int sum = 0;
		for (int i = 0; i < seq.size(); ++i)
			if ((seq[i] & c) == c)
				++sum;
		if (sum > M) {
			M = sum;
			temp.clear();
			temp.push_back(c);
		}
		else if (sum == M)
			temp.push_back(c);
	} while (next_permutation(p.begin(), p.end()));
	for (int i = 0; i < temp.size(); ++i)
		ans.push_back(temp[i]);
}
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	vector<int> seq;
	vector<int> tmp;
	for (int i = 0; i < orders.size(); ++i) {
		int s = 0;
		for (int j = 0; j < orders[i].size(); ++j) {
			s |= (1 << (orders[i][j] - 'A'));
			tmp.push_back((orders[i][j] - 'A'));
		}
		seq.push_back(s);
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	vector<int> ans;
	for (int i = 0; i < course.size(); ++i) 
		chk(seq, course[i], ans, tmp);

	sort(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); ++i) {
		string str = "";
		for (int j = 0; j < 26; ++j) {
			if (ans[i] & (1 << j)) str.push_back('A' + j);
		}
		answer.push_back(str);
	}
	sort(answer.begin(), answer.end());
	return answer;
}
int main() {
	int n; cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; ++i)
		cin >> str[i];
	int m; cin >> m;
	vector<int> seq(m);
	for (int i = 0; i < m; ++i)
		cin >> seq[i];
	vector<string> ans = solution(str, seq);
	for (auto i : ans)
		cout << i << '\n';
}