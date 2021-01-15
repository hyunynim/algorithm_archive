#include<bits/stdc++.h>
using namespace std;
int rev(int num) {
	int res = 0;
	while (num) {
		res = res * 10 + num % 10;
		num /= 10;
	}
	return res;
}
int main() {
	int num;
	while (1) {
		scanf("%d", &num);
		if (num == 0) return 0;
		int mun = rev(num);
		if (mun == num)
			puts("yes");
		else
			puts("no");
	}
}