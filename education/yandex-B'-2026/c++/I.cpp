#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ll n, w;
    cin >> n >> w;

    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());

    priority_queue<pair<ll, ll>> q;
    priority_queue<ll> c;
    for (const auto& [a, b] : p) {
        ll r = q.top().first;

        if (r < a) {
            
        }
    }
}
