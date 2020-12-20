#include<bits/stdc++.h>
using namespace std;
int adj[303][303];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	memset(adj, 0x3f, sizeof(adj));
	int answer = 1e9;
	for (int i = 0; i < fares.size(); ++i) {
		int a = fares[i][0];
		int b = fares[i][1];
		int c = fares[i][2];

		adj[a][b] = min(adj[a][b], c);
		adj[b][a] = min(adj[b][a], c);
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (adj[i][j] > 20000000 || i == j) adj[i][j] = 0;

	answer = adj[s][a] + adj[s][b];
	for (int i = 1; i <= n; ++i)
		if(adj[s][i] && adj[i][a] && adj[i][b]
			|| (adj[s][i] == 0 && s == i)
			|| (adj[i][a] == 0 && a == i)
			|| (adj[i][b] == 0 && b == i))
		answer = min(answer, adj[s][i] + adj[i][a] + adj[i][b]);
	return answer;
}
int main() {
	solution(6, 4, 5, 6, { {2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9} });
}