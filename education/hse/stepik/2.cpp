#include<bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ll n, m; cin >> n >> m;

    vector<ll> p(n);
    cin >> p[0];
    for (int i = 1; i < n; i++) {
        ll x; cin >> x;
        p[i] = p[i-1] + x;
    }

    for (int i = 0; i < m; i++) {
        ll x; cin >> x;
        ll l = 0, r = n-1;

        while (l <= r) {
            ll m = l+(r-l)/2;

            if (p[m] < x) l = m+1;
            else r = m-1;
        }

        ll a = (l == 0 ? p[l] : p[l]-p[l-1]);
        cout << l+1 << " " << a-p[l]+x << "\n";
    }
}