#include<bits/stdc++.h>

using namespace std;
vector<int> adj[55];
int noUse[55][55];
bool chk[55];
int go(int s, int cnt){
    chk[s] = 1;
    int res = 1;
    for(int i = 0; i<adj[s].size(); ++i){
        int nx = adj[s][i];
        if(!chk[nx] && noUse[s][nx] != cnt)
            res += go(nx, cnt + 1);
    }
    return res;
}
int solution(int n, vector<vector<int>> edges) {
    int answer = 1e9;
    for(int i = 0; i<edges.size(); ++i)
        adj[edges[i][0]].push_back(edges[i][1]);
    
    for(int i = 0; i<edges.size(); ++i){
        for(int j = 0; j<edges.size(); ++j){
            for(int k = 0; k<edges.size(); ++k){
                if(i == j || j == k || k == i) continue;
                noUse[edges[i][0]][edges[i][1]] = 1;
                noUse[edges[j][0]][edges[j][1]] = 2;
                noUse[edges[k][0]][edges[k][1]] = 3;
                answer = min(answer, go(0, 1));
                noUse[edges[i][0]][edges[i][1]] = 0;
                noUse[edges[j][0]][edges[j][1]] = 0;
                noUse[edges[k][0]][edges[k][1]] = 0;
            }
        }
    }
    
    return answer;
}

int main() {
	solution(19, { {0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 7}, {3, 8}, {3, 9}, {4, 10}, {4, 11}, {5, 12}, {5, 13}, {6, 14}, {6, 15}, {6, 16}, {8, 17}, {8, 18} });
}