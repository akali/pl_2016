#include <iostream>

using namespace std;

int n, k;
int cur;
int a[100];

bool check(int x) {
	if (x == n)
		return (cur == k);
	cur += a[x];
	bool ok = check(x + 1);
	cur -= a[x] + a[x];
	ok |= check(x + 1);
	cur += a[x];
	return ok;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	if (check(0))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}