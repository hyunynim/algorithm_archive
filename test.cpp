#include <iostream>
using namespace std;

int calc(int n);

int main() {
	freopen("1.txt", "r", stdin);
	freopen("res.txt", "r", stdout);
	int i, t, n;
	cin >> t;
	for (i = 0; i < t; ++i) {
		cin >> n;
		if (calc(n) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int calc(int n) {
	int i, j, count, temp;
	count = n / 2020;
	if (count == 0) {
		return 2; // NO
	}
	for (i = 0; i <= count + 1; ++i) {
		temp = n;
		for (j = 0; j < count - i; ++j) {
			temp -= 2020;
		}
		for (j = 0; j < i; ++j) {
			temp -= 2021;
		}
		if (temp == 0) {
			return 1; // YES
		}
	}
	return 2; // NO

}