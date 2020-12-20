#include<bits/stdc++.h>
using namespace std;
string solution(string new_id) {
	string tmp = new_id;
	string ans = "";
	for (int i = 0; i < tmp.size(); ++i) {
		if ('A' <= tmp[i] && tmp[i] <= 'Z') {
			tmp[i] -= 'A';
			tmp[i] += 'a';
		}
		if (tmp[i] == '.' && ans.size() && ans.back() == '.') continue;
		if (('a' <= tmp[i] && tmp[i] <= 'z') || tmp[i] == '-' || tmp[i] == '_' || tmp[i] == '.'
			|| ('0' <= tmp[i] && tmp[i] <= '9'))
			ans.push_back(tmp[i]);

	}
	if (ans.size() && ans.back() == '.')
		ans.pop_back();
	if (ans.size() && ans[0] == '.') {
		reverse(ans.begin(), ans.end());
		ans.pop_back();
		reverse(ans.begin(), ans.end());
	}
	if (ans.empty())
		ans = "a";
	if (ans.size() > 15)
		ans = ans.substr(0, 15);
	if (ans.size() && ans.back() == '.')
		ans.pop_back();
	while (ans.size() <= 2)
		ans.push_back(ans.back());
	return ans;
}
int main() {
	cout << solution("...!@BaT#*..y.abcdefghijklm");

}