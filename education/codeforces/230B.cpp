#include<bits/stdc++.h>

using ll = long long;
using namespace std;

ll sqrtc(ll n) {
    ll l = 1, r = n;
    while (l <= r) {
        ll m = l+(r-l)/2;

        if (m <= n/m) l = m+1;
        else r = m-1;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    while (n--) {
        ll a; cin >> a;
        ll b = sqrtc(a);

        if (b*b != a || a == 1) {
            cout << "NO\n";
            continue;
        }

        bool p = true;
        for (int i = 2; i <= b/i; i++) if (b % i == 0) {p = false; break;}

        cout << (p ? "YES" : "NO") << "\n";
    }
}