/*
2023. 8. 10.
ㅈ같은 문제
종주국이랑 속국 왕국 설명 좀 잘해놓지;;
*/

#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
#include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <map>
// #include <deque>
// #include <cmath>

int N, M, tmp, v1, v2, pv1, pv2, cnt, winner;
string kingdoms[500];
string word, cv1, cv2;

// disjoint
int dj[500];

int find(int v) {
    if (v == dj[v]) return v;
    else {
        return dj[v] = find(dj[v]);
    }
}

void versusTwoRoot() {
    if (winner == 1) {
        dj[pv2] = pv1;
    } else {
        dj[pv1] = pv2;
    }
    --cnt;
}

void versusOwnChildren() {
    if (v2 == pv2) {
        // swap v1, v2
        tmp = v1, v1 = v2, v2 = tmp;
        pv1 = pv2, pv2 = find(v2);

        if (winner == 1) winner = 2;
        else return;
    }

    if (winner == 2) {
        int t1, t2;
        for (int i = 1; i <= N; ++i) {
            if (find(i) == v1) {
                t1 = i;
                while (t1 != v1) {
                    t2 = dj[t1];
                    dj[t1] = v2;
                    t1 = t2;
                }
            }
        }

        dj[v1] = dj[v2]= v2;
    }
}

void f() {}

int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);

    cin >> N >> M;
    cin.ignore();
    cnt = N;

    for (int i = 0; i < N; ++i) {
        dj[i] = i;
        getline(cin, word);

        kingdoms[i] = word.substr(11, word.length());
    }
    sort(kingdoms, kingdoms + N);

    int idx;
    for (int j = 0; j < M; ++j) {
        getline(cin, word);

        cv1 = word.substr(11, word.find(',') - 11);
        cv2 = word.substr(23 + cv1.length(), word.find(',', 23 + cv1.length()) - 23 - cv1.length());
        winner = word.back() - 48;

        v1 = lower_bound(kingdoms, kingdoms + N, cv1) - kingdoms;
        v2 = lower_bound(kingdoms, kingdoms + N, cv2) - kingdoms;

        pv1 = find(v1), pv2 = find(v2);

        if (pv1 == pv2) {
            versusOwnChildren();
        } else {
            versusTwoRoot();
        }
    }

    cout << cnt << "\n";
    for (int i = 0; i < N; ++i) {
        if (dj[i] == i) cout << "Kingdom of " << kingdoms[i] << "\n";
    }

    return 0;
}