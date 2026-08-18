#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> c(n), x(n), y(n);

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    vector<ll> c1 = vector<ll>(c);

    ll p = 1e6+1, q = 1e6+1;
    for(int i = 0; i < n; i++) {
        if(x[i] == 0) continue;

        p = min(p, c1[i]/x[i]);
    }
    for(int i = 0; i < n; i++) c1[i] -= p*x[i];
    for(int i = 0; i < n; i++) {
        if(y[i] == 0) continue;

        q = min(q, c1[i]/y[i]);
    }

    ll k = 1e6+1, m = 1e6+1;
    for(int i = 0; i < n; i++) {
        if(y[i] == 0) continue;

        k = min(k, c[i]/y[i]);
    }
    for(int i = 0; i < n; i++) c[i] -= k*y[i];
    for(int i = 0; i < n; i++) {
        if(x[i] == 0) continue;

        m = min(m, c[i]/x[i]);
    }

    cout << max(p+q, k+m);
}