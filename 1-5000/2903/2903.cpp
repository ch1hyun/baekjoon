/*
2023. 7. 13.
*/

#include <iostream>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort
// #include <set>
// #include <stack>
// #include <cstring> // memset

int n, cur, sum;

void f() {
    int tmp = cur;
    cur *= 2;

    sum += 5;
    if (--tmp == 0) return;

    sum += tmp * (8 + tmp * 3);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cur = 1;
    sum = 4;

    while (n-- != 0) {
        f();
    }

    cout << sum;

    return 0;
}