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
    int t; cin >> t;
	while (t--) {
		ll w, h, n; cin >> w >> h >> n;
		ll count = 1;
		while (w % 2 == 0 || h % 2 == 0) {
			if (w % 2 == 0) {
				w /= 2;
				count *= 2;
			}
			if (h % 2 == 0) {
				h /= 2;
				count *= 2;
			}
		}
		if (count >= n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
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
