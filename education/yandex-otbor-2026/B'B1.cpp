#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll MOD = 1e9+7;
const ll k = 33;

ll tohash(string s) {
    ll h = 0;

    for (int i = 0; i < s.size(); i++) {
        ll x = s[i] - 'a' + 1;
        h = (h * k + x) % MOD;
    }

    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m; cin >> n >> m;
    string s; cin >> s;

    unordered_map<ll, unordered_set<ll>> p;
    for (int i = 0; i < m; i++) {
        string t; cin >> t;

        p[tohash(t)].insert(i+1);
    }

    vector<ll> pow(n+1, 1);
    for (int i = 1; i < pow.size(); i++) {
        pow[i] = (pow[i-1]*k) % MOD;
    }

    ll h = tohash(s.substr(0, n/m));
    for (int i = n/m; i < n+1; i++) {
        if (i % (n/m) == 0 || i == n/m) {
            ll j = *p[h].begin();
            cout << j << " ";
            p[h].erase(j);
        }

        if (i == n) break;

        ll a = s[i-n/m] - 'a' + 1, b = s[i] - 'a' + 1;
        h = (k*(h - a*pow[n/m-1]) + b) % MOD;
        if (h < 0) h += MOD;
    }
}