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
struct ITEM{
    int t;
    ll c;
};
void solve(){
    //TODO here
    int n; scanf("%d", &n);
    vector<ITEM> seq(n);
    for(int i = 0; i<n; ++i)
        scanf("%d %lld", &seq[i].t, &seq[i].c);
    sort(seq.begin(), seq.end(), [](ITEM i1, ITEM i2){
        return i1.c == i2.c ? i1.t > i2.t : i1.c < i2.c;
    });
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
