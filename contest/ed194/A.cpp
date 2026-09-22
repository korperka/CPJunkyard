#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, ans = 0, c = 0; cin >> n;
        for (int i = 0; i < n; i++) {
            int f; cin >> f;

            if (f == 0) c++;
            if ((i == 0 || i == n-1) && f == 1) ans++;
        }

        cout << (c >= 2 ? ans : -1) << "\n";
    }
}