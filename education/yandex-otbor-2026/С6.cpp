#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q; cin >> n >> q;
    string s; cin >> s;

    ll p = 0;
    for (int i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;

        if (a == 1) {
            p += b;
            p %= n;
        }
        else {
            ll j = (b-p-1)%n;
            if (j < 0) j += n;
            cout << s[j] << "\n";
        }
    }
}