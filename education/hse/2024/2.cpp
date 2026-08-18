#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    vector<ll> b(n);

    b[0] = a[0];
    for(int i = 1; i < n; i++) b[i] = b[i-1]+a[i];

    for(int i = 0; i < q; i++) {
        ll x; cin >> x;

        ll l = 1, r = 1e9+1;
        while(l <= r) {
            ll m = l+(r-l)/2;

            ll p = lower_bound(a.begin(), a.end(), m) - a.begin();
            ll c = (p == 0 ? 0 : p*m-b[p-1]);

            if(c <= x) l = m+1;
            else r = m-1;
        }

        cout << r << "\n";
    }
}