#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector a(n, vector<char>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

        string ans = "YES\n";
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-1; j++) {
                if (a[i][j] == '1' && a[i][j+1] == '0' && a[i+1][j] == '0') ans = "NO\n";
            }
        }

        cout << ans;
    }
}