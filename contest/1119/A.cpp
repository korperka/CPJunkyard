#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, k, c = 0, ans = 0; cin >> n >> k;
        string s; cin >> s;

        // c = (s[0] == '1');
        for (int i = 0; i <= n; i++) {
            if (i % k == 0) {
                ans += (c == k);
                c = 0;
            }
            if (i < n) c += (s[i] == '1');
        }

        cout << ans << "\n";
    }
}