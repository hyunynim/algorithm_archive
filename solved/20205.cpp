#include<bits/stdc++.h>
using namespace std;
int board[55][55];
int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			scanf("%d", &board[i][j]);
	for (int i = 0; i < n; ++i) {
		for (int q2 = 0; q2 < k; ++q2) {
			for (int j = 0; j < n; ++j) {
				for (int q1 = 0; q1 < k; ++q1)
					printf("%d ", board[i][j]);
			}
			puts("");
		}
	}
}