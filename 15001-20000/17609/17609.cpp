/*
Date : 2023-05-04
*/

#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <set>
// #include <stack>
#include <string>

int t, st, en, tempSt, tempEn;
bool deleteFlag, retireFlag;
string word;

int f(string w) {
    st = 0;
    en = w.length() - 1;

    deleteFlag = retireFlag = false;
    while (1) {
        if (st > en) break;

        if (!deleteFlag && w[st] != w[en]) {
            deleteFlag = true;

            if (!retireFlag) {
                tempSt = st;
                tempEn = en;
                ++st;
                retireFlag = true;
            } else {
                --en;
                retireFlag = false;
            }
        }

        if (!retireFlag && deleteFlag && w[st] != w[en]) break;
        if (retireFlag && deleteFlag && w[st] != w[en]) {
            st = tempSt;
            en = tempEn;
            deleteFlag = false;
            continue;
        } 

        ++st;
        --en;
    }

    if (!deleteFlag && st > en) return 0;
    else if (deleteFlag && st > en) return 1;
    else return 2;

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> word;

        cout << f(word) << "\n";
    }

    return 0;
}
