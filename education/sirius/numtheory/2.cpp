#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll binpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a; res %= p;
        }
        a *= a; a %= p;
        b >>= 1;
    }

    return res % p;
}

int main() {
    int t; cin >> t;

    while (t--) {
        ll p, a; cin >> p >> a;
        cout << binpow(a, p-2, p) << "\n";
    }
}