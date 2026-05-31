#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll binpow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

ll find(ll a) {
    ll l = 1, r = 10;

    while (l <= r) {
        ll m = (l+r)/2;

        if (binpow(m, m) % a != 0) r = m-1;
        else l = m+1;
    }

    return l;
}

int main() {
    ll a; cin >> a;

    cout << find(a) << "\n";
}