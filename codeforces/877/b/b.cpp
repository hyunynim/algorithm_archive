#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#include<chrono>
#include<random>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
mt19937 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());
/*Templates end*/
void solve(){
    //TODO here
    char msg[5050]; scanf("%s", msg);
    int sum[2][5050] = {0};
    for(int i = 0; msg[i]; ++i){
        sum[0][i + 1] = sum[0][i];
        sum[1][i + 1] = sum[1][i];
        msg[i] == 'w' ? ++sum[0][i + 1] : ++sum[1][i + 1];
    }
    int sz = strlen(msg);
    int ans = 0;
    for(int i = 0; i<=sz; ++i)
        for(int j = i; j<=sz; ++j)
            ans = max(ans, (sum[0][i]) + (sum[1][j] - sum[1][i]) + (sum[0][sz] - sum[0][j]));
    printf("%d", ans);
}
int main(){
#ifdef LOCAL
    //Run in local
	freopen("input.txt", "r", stdin);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
} 
