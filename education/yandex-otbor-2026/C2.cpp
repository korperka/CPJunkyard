#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll floor_div(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ((-a + b - 1) / b);
}

ll ceil_div(ll a, ll b) {
    if (a >= 0) return (a + b - 1) / b;
    return -((-a) / b);
}

bool check(ll k, vector<ll>& c, vector<ll>& x, vector<ll>& y) {
    ll n = c.size(), l = 0, r = k;

    for (int i = 0; i < n; i++) {
        if (x[i] > y[i])
             r = min(r, floor_div((c[i]-k*y[i]), (x[i]-y[i])));
        else if (x[i] < y[i])
            l = max(l, ceil_div((k*y[i]-c[i]),(y[i]-x[i])));
        else
            if (k*y[i] > c[i]) return false;
    }

    return l <= r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> c(n), x(n), y(n);

    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    ll l = 0, r = 2*1e6+1;
    while (l <= r) {
        ll k = l+(r-l)/2;

        if (check(k,c,x,y)) l = k+1;
        else r = k-1;
    }

    cout << r << endl;
}