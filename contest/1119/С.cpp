#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, l = -1, r = -1; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < n; i++) {
            if (a[i] == -1 || a[i] == 1) {
                a[i] = 1;
                l = i;
                break;
            }
        }

        for (int i = n-1; i >= 0; i--) {
            if (a[i] == -1 || a[i] == 1) {
                a[i] = 1;
                r = i;
                break;
            }
        }

        if (l == r) {
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << "\n";
            continue;
        }

        for (int i = l; i < r; i++) if (a[i] == -1) a[i] = 0;

        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}