#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct Comp {
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        return a.first*b.second > b.first*a.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k; cin >> n >> k;
    multiset<pair<ll, ll>, Comp> p;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        p.insert({a, 1});
    }

    for (int i = 0; i < k; i++) {
        pair<ll, ll> v = *p.begin();
        p.erase(v);
        v.second++;
        p.insert(v);
    }

    pair<ll, ll> v = *p.begin();
    cout << (v.first+v.second-1)/v.second;
}