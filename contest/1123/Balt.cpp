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
        unordered_set<ll> uniq;
        for (int i = 0; i < n; i++) {
            ll a; cin >> a;
            p.insert(a);
            uniq.insert(a);
        }

        unordered_map<ll, vector<ll>> anss;

        for (const ll& k : uniq) {
            ll mxc = p.count(k);
            for (const ll& c : p) {
                if (cnt[c] >= mxc) {
                    q.insert(c);
                    continue;
                }

                anss[k].push_back(c);
                cnt[c]++;
            }

            for (const ll& c : q) anss[k].push_back(c);
        }

        vector<ll> ans;
        ll maxs = 0;
        for (const auto& [k, v] : anss) {
            ll s = 0, num = v[0];
            unordered_map<ll, ll> cnt2;

            for (const auto& c : v) {
                cnt2[c]++;
                ll cntnum = count(v.begin(), v.end(), num);

                if (cnt2[c] > cntnum) {
                    num = c;
                } else if (cnt[c] == cntnum) {
                    num = max(num, c);
                }

                s += num;
            }

            if (s > maxs) {
                maxs = s;
                ans = v;
            }
        }

        for (const ll& c : ans) cout << c << " ";
        cout << "\n";
    }
}