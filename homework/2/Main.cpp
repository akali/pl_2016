#include <iostream>
#include <vector>

using namespace std;

int n, k;
int cur;
int a[100];

vector <char> v;

bool printed;

bool check(int x) {
	if (x == n) {
		// cerr << cur << " ";
		if (cur == k) {
			if (!printed)
				cout << "YES\n";
			printed = true;
			for (int i = 0; i < (int)v.size(); ++i)
				if (i == 0 && v[i] == '+') {
					cout << a[i];
				} else
					cout << v[i] << a[i];
			cout << endl;
		}
		return cur == k;
	}
	v.push_back('+');
	cur += a[x];
	bool ok = check(x + 1);
	cur -= a[x];
	v.back() = '-';
	cur -= a[x];
	ok |= check(x + 1);
	cur += a[x];
	v.pop_back();
	return ok;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	if (!check(0))
		cout << "NO\n";

	return 0;
}
