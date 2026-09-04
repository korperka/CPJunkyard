#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll l = 1, r = a.back();
    while (l <= r) {
        ll m = l+(r-l)/2;
        ll p = 0;

        for (int i = 0; i < n; i++) p += (a[i]-1)/m;

        if (p > k) l = m+1;
        else r = m-1;
    }

    cout << l;
}