#include<bits/stdc++.h>
using namespace std;
int main() {
	for (int i = 'C'; i <= 'Z'; ++i)
		printf("=%c28\n", i);
	for (int i = 'A'; i <= 'C'; ++i)
		for (int j = 'A'; j <= 'Z'; ++j)
			printf("=%c%c28\n", i, j);
}