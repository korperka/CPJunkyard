#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll binpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) { res *= a; res %= p; }

        a *= a; a %= p;
        b >>= 1;
    }

    return res;
}

ll find_n(ll a) {
    ll l = 1, r = 1e9+1;

    while (l <= r) {
        ll m = (l + r) / 2;

        if (binpow(m, m, a) == 0) r = m - 1;
        else l = m + 1;
    }

    return l;
}

int main() {
    ll a; cin >> a;

    cout << find_n(a) << "\n";
}