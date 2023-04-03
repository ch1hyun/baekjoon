/*
Date : 2023-04-03
*/

#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <set>
// #include <stack>

int n, k, cnt = 0;
bool prime[1001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> n >> k;

    for (int i = 2; i <= n; ++i) {
        if (cnt == k) break;
        if (!prime[i]) {
            for (int j = i; j <= n; j += i) {
                if (prime[j]) continue;
                prime[j] = true;
                ++cnt;
                if (cnt == k) {cout << j;break;}
            }
        }
    }


    return 0;
}
