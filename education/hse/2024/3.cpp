#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b, p, q; cin >> a >> b >> p >> q;
    string s; cin >> s;

    vector<vector<ll>> dp(s.size(), vector<ll>(2));
    dp[0][0] = p+a; dp[0][1] = p+a;
    for (int i = 1; i < s.size(); i++) {
        ll n = dp[i-1][0], m = dp[i-1][1];

    }

    cout << dp[s.size()-1];
}

