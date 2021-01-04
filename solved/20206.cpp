#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define POOR cout << "Poor"
#define LUCKY cout << "Lucky"
struct POS {
	ll x, y;
};
int leq(int a, int b, int c, int x, int y) {
	ll res = a * x + b * y + c;
	if (res > 0)
		return 1;
	else if (res < 0)
		return -1;
	else return 0;
}
int main() {
	ll a, b, c; cin >> a >> b >> c;
	ll x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;

	int c1 = leq(a, b, c, x1, y1);
	int c2 = leq(a, b, c, x1, y2);
	int c3 = leq(a, b, c, x2, y1);
	int c4 = leq(a, b, c, x2, y2);
	

	if((c1 && c2 && c1 != c2) ||
		(c1 && c3 && c1 != c3) ||
		(c1 && c4 && c1 != c4) ||
		(c2 && c3 && c2 != c3) ||
		(c2 && c4 && c2 != c4) ||
		(c3 && c4 && c3 != c4))
		POOR;
	
	else
		LUCKY;
}