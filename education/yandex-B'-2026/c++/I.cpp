#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Block {
    ll a, b;

    Block(ll a, ll b) {
        this->a = a;
        this->b = b;
    }

    bool operator<(const Block& snd) const { return (a == snd.a ? b < snd.b : a < snd.a); }
};

int main() {
    ll n, w;
    cin >> n >> w;
    vector<pair<Block, ll>> p;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        p.push_back({Block(a, b), i});
    }

    sort(p.begin(), p.end());

    set<pair<ll, ll>> q;
    vector<vector<ll>> a(1, vector<ll>());
    q.insert({-1, 0});
    ll c = 0;
    for (int i = 0; i < n; i++) {
        auto k = *q.begin();

        if (p[i].first.a >= k.first) {
            a[k.second].push_back(p[i].second);
            q.erase(q.begin());
            q.insert({p[i].first.a + p[i].first.b, k.second});
        } else {
            a.push_back({});
            q.insert({p[i].first.a + p[i].first.b, ++c});
            a[c].push_back(p[i].second);
        }
    }

    cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] + 1 << " ";
        }
    }

    cout << "\n";
}
