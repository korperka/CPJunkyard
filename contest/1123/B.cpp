#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        unordered_map<ll, ll> cnt;
        multiset<ll, greater<>> p, q;
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            p.insert(a);
        }

        ll mxc = p.count(*p.begin());
        for (const ll& c : p) {
            if (cnt[c] >= mxc) {
                q.insert(c);
                continue;
            }

            cout << c << " ";
            cnt[c]++;
        }

        for (const ll& c : q) cout << c << " ";
        cout << "\n";
    }
}