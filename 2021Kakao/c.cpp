#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<int> score[3][8];
	for (int i = 0; i < info.size(); ++i) {
		char msg[4][22];
		int sc;
		sscanf(info[i].c_str(), "%s %s %s %s %d", msg[0], msg[1], msg[2], msg[3], &sc);
		int lang, s = 0;
		int op[3] = { 0 };

		if (msg[0][0] == 'c')
			lang = 0;
		else if (msg[0][0] == 'j')
			lang = 1;
		else
			lang = 2;

		if (msg[1][0] == 'f')
			op[0] = 1;
		if (msg[2][0] == 's')
			op[1] = 1;
		if (msg[3][0] == 'p')
			op[2] = 1;
		for (int j = 0; j < 3; ++j)
			s |= (op[j] << j);
		score[lang][s].push_back(sc);
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 8; ++j)
			sort(score[i][j].begin(), score[i][j].end());
	for (int i = 0; i < query.size(); ++i) {
		char msg[4][22];
		char msgTmp[23];
		int sc;
		sscanf(query[i].c_str(), "%s %s %s %s %s %s %s %d", msg[0], msgTmp, msg[1], msgTmp, msg[2], msgTmp, msg[3], &sc);
		int lang, s = 0;
		int op[3] = { 0 };

		if (msg[0][0] == 'c')
			lang = 0;
		else if (msg[0][0] == 'j')
			lang = 1;
		else if (msg[0][0] == 'p')
			lang = 2;
		else
			lang = 3;

		if (msg[1][0] == 'f')
			op[0] = 1;
		else if (msg[1][0] == '-')
			op[0] = 2;

		if (msg[2][0] == 's')
			op[1] = 1;
		else if (msg[2][0] == '-')
			op[1] = 2;

		if (msg[3][0] == 'p')
			op[2] = 1;
		else if (msg[3][0] == '-')
			op[2] = 2;

		vector<int> temp;
		for (int j = 0; j < 8; ++j) {
			bool ok = 1;
			for (int k = 0; k < 3; ++k) {
				if (op[k] != 2 && 
					((op[k] && (j & (1 << k)) == 0)
					|| (op[k] == 0 && (j & (1 << k))))){
					ok = 0;
					break;
				}
			}
			if (ok) temp.push_back(j);
		}
		int cnt = 0;
		for (int j = 0; j < 3; ++j) {
			if (lang == j || lang == 3) {
				for (int k = 0; k < temp.size(); ++k) {
					cnt += score[j][temp[k]].end() - 
						lower_bound(score[j][temp[k]].begin(), score[j][temp[k]].end(), sc);
				}
			}
		}
		answer.push_back(cnt);
	}
	for (auto i : answer)
		cout << i << '\n';
	return answer;
}
int main() {
	vector<string> str;
	str.push_back("java backend junior pizza 150");
	str.push_back("python frontend senior chicken 210");
	str.push_back("python frontend senior chicken 150");
	str.push_back("cpp backend senior pizza 260");
	str.push_back("java backend junior chicken 80");
	str.push_back("python backend senior chicken 50");
	vector<string> q;
	q.push_back("java and backend and junior and pizza 100");
	q.push_back("python and frontend and senior and chicken 200");
	q.push_back("cpp and - and senior and pizza 250");
	q.push_back("- and backend and senior and - 150");
	q.push_back("- and - and - and chicken 100");
	q.push_back("- and - and - and - 150");
	solution(str, q);
}