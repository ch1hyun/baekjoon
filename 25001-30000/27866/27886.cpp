/*
Date : 2023-03-10
*/

#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	int i;
	cin >> str >> i;

	cout << str.at(i - 1);

	return 0;
}
