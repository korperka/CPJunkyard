#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll gcd_ext(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = gcd_ext(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);
    return d;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll msol(ll x, ll b, ll c, ll d) {
    ll l = -1e9, r = 1e9;

    while (l <= r) {
        ll m = (l+r)/2;

        if (c/d*x + b/d*m >= 0) r = m-1;
        else l = m+1;
    }

    return l;
}

int main() {
    ll a,b,c,x,y; cin >> a >> b >> c;

    if (c % gcd(a, b) != 0) {
        cout << -1;
        return 0;
    }

    ll d = gcd_ext(a, b, x, y);
    ll t = msol(x, b, c, d);

    cout << c/d*x+b/d*t << " " << c/d*y-a/d*t << "\n";
}