#include <iostream>

using namespace std;

int n, k;
int a[150];

void gen(int i) {
	if (i < n) {
		for (int q = k; q >= 0; --q) {
			a[i] = q;
			gen(i + 1);
		}
	} else {
		for (int i = 0; i < n; ++i)
			cout << a[i];
		cout << endl;
	}
}

int main() {
	cin >> n >> k;

	gen(0);

	return 0;
}
