#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, a = 0, b = 0, c = 0; cin >> n;
        for (int i = 0; i < n; i++) {
            ll k; cin >> k;
            if (k % 4 == 0) a++;
            else if (k % 2 == 0) b++;
            else c++;
        }

        cout << max(a, max(b, c)) << "\n";
    }
}