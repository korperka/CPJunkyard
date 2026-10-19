#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct Op {
    ll l, r, d;

    friend istream& operator>>(istream& in, Op& op) { return in >> op.l >> op.r >> op.d; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> p(n), ops(m + 1, 0);
    vector<Op> q(m);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> q[i];
    for (int i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        ops[a - 1]++;
        ops[b]--;
    }
    for (int i = 1; i < m; i++) ops[i] += ops[i - 1];

    vector<ll> pref(n + 1);
    for (int i = 0; i < m; i++) {
        Op op = q[i];
        ll d = op.d * ops[i];

        pref[op.l - 1] += d;
        pref[op.r] -= d;
    }

    for (int i = 1; i < n; i++) pref[i] += pref[i - 1];

    for (int i = 0; i < n; i++) {
        cout << pref[i] + p[i] << " ";
    }
    cout << "\n";
}
