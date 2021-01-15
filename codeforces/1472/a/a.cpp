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
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		string str = "";
		int cnt = 9;
		bool flag = 0;
		for(int i = 0; i<n; ++i){
			str.push_back('0' + cnt);
			if(flag) ++cnt;
			else --cnt;
			cnt %= 10;
			if(cnt == 0) flag = 1;
		}
	printf("%s\n", str.c_str());
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
