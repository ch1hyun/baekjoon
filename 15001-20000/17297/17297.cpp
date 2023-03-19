/*
Date : 2023-03-19
Comment : 문자열을 직접 구하는게 아닌, 길이로 피보나치 수열의 하단부까지 파고들어 위치를 구하는게 핵심인 문제
*/

#include <iostream>
using namespace std;
#include <string>

string messi[2] = {"Messi", "Messi Gimossi"};
int fibo[200] = {0};
int M, D = 0;
char tmp;

char getWord(int N) {
    if (N == 1) {return messi[0][M - 1];}
    else if (N == 2) {return messi[1][M - 1];}
    else {
        if (M > fibo[N - 2] + 1) {
            M -= (fibo[N - 2] + 1);
            return getWord(N - 2);
        }
        else if (M > fibo[N - 2]) {
            return ' ';
        }
        else {
            return getWord(N - 1);
        }
    }
}

int f(int N) {
    if (fibo[N - 1] == 0) fibo[N - 1] = f(N - 1) + f(N - 2) + 1;
    return fibo[N - 1];
}

int main(int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

    fibo[0] = messi[0].length();
    fibo[1] = messi[1].length();

    cin >> M;

    while (M > f(++D)) {}

    tmp = getWord(D);
    if (tmp == ' ') cout << "Messi Messi Gimossi";
    else cout << tmp;

	return 0;
}
