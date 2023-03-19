/*
Date : 2023-03-20
*/

#include <iostream>
using namespace std;
#include <string>

int N, cnt, num[10] = {0};
int words[12][9],wordsIdx;
int powFormat[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
string tmp, alphabet;
bool cFlag, chk[10] = {false};

void formatWord(string t) {
    for (int j = 0; j < t.length(); ++j) {
        if (alphabet.find(t[j]) == string::npos) alphabet += t[j];
        words[wordsIdx][j] = alphabet.find(t[j]);
    }
    words[wordsIdx][8] = t.length();
    ++wordsIdx;
}

void operationWord(int idx = 0) {
    if (idx == alphabet.length()) {
        int temp, sum = 0;
        for (int k = 0; k < N; ++k) {
            temp = 0;
            for (int q = 0; q < words[k][8]; ++q) {
                temp += num[words[k][q]] * powFormat[words[k][8] - q - 1];
            }

            if (k != N - 1) sum += temp;
        }

        if (sum == temp) ++cnt;
    } else {
        for (int i = 0; i < 10; ++i) {
            if (chk[i]) continue;
            if (i == 0) {
                cFlag = false;
                for (int j = 0; j < N; ++j) {
                    if (words[j][8] == 1) continue;
                    if (words[j][0] == idx) {cFlag = true; break;}
                }
                if (cFlag) continue;
            }

            chk[i] = true; num[idx] = i;
            operationWord(idx + 1);
            chk[i] = false;
        }
    }
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    while (true) {
        cin >> N;
        if (N == 0) break;

        /* Initial */
        wordsIdx = 0;
        cnt = 0;
        alphabet = "";

        for (int i = 0; i < N; ++i) {
            cin >> tmp;
            formatWord(tmp);
        }

        operationWord();

        cout << cnt << "\n";
    }
	return 0;
}
