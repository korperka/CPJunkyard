#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = max(1000 - a[i], 1);
    }

    ll s = 0, c = 0;
    while (true) {
        ll mi = 0, mv = 1e9;
        for (int i = 0; i < n; i++) {
            if (b[i] < mv) {
                mv = b[i];
                mi = i;
            }
        }

        if (mv - s >= abs(mi - c)) {
            s += abs(mi - c);
            c = mi;

            if (s <= mv) s = mv;

            a[mi]++;
            b[mi] = s + max(1000 - a[mi], 1);
        } else {
            cout << mv << "\n";
            return 0;
        }
    }
}
