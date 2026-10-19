#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;

        vector<ll> mem;
        unordered_set<ll> p;
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '1') {
                mem.push_back(i);
            } else if (s[i-1] == '3' || (s[i-1] == '2' && mem.empty())) {
                p.insert(i);
            } else if (s[i-1] == '2') {
                p.insert(mem.back());
                mem.pop_back();
            }
        }

        set<ll> up;
        for (int i = 1; i <= n; i++) {
            if (p.contains(i)) continue;

            up.insert(i);
        }

        cout << up.size() << "\n";
        for (const auto &c : up) cout << c << " ";
        cout << "\n";
    }
}