#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<vector<char>> a(n, vector<char>(3));
    vector<vector<ll>> dp(n, vector<ll>(3, 0));

    for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) cin >> a[i][j];

    for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) dp[i][j] = (a[i][j]=='C')-(a[i][j]=='W');
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            ll d = dp[i-1][j], b = (j > 0 ? dp[i-1][j-1] : -1), c = (j < 2 ? dp[i-1][j+1] : -1);

            dp[i][j] = a[i][j] == 'W' ? -1 : max(d, max(b, c));
            if (dp[i][j] != -1) dp[i][j] += (a[i][j] == 'C');
        }
    }

    if (dp[0][0] == -1 && dp[0][1] == -1 && dp[0][2] == -1) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (dp[i][0] == -1 && dp[i][1] == -1 && dp[i][2] == -1) {
            cout << max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
            return 0;
        }
    }
    cout << max(dp.back()[0], max(dp.back()[1], dp.back()[2]));
}
