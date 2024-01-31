#include <iostream>
#include <tuple>
using namespace std;
// #include <vector>
// #include <queue>
// #include <algorithm> // sort, min, max
// #include <set>
// #include <stack>
#include <cstring> // memset
// #include <fstream>
// #include <map>
// #include <deque>
// #include <cmath>

#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define MAX 1000000000

const int day_end[] = {31, 30, 28};
const int match_month[] = {-1, 0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};

string match_day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int x, y;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> x >> y;

    int diff = y - 1;
    for (int i = 1; i < x; ++i) {
        diff += day_end[match_month[i]];
    }

    cout << match_day[diff % 7];

    return 0;
}