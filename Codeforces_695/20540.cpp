#include<bits/stdc++.h>
using namespace std;
char mbti[2525];
int main() {
	mbti['E'] = 'I';
	mbti['I'] = 'E';
	mbti['S'] = 'N';
	mbti['N'] = 'S';
	mbti['T'] = 'F';
	mbti['F'] = 'T';
	mbti['P'] = 'J';
	mbti['J'] = 'P';
	char msg[25];
	scanf("%s", msg);
	for (int i = 0; i < 4; ++i)
		putchar(mbti[msg[i]]);
}