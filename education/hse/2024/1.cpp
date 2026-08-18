#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y, z, s1, c1, s2, c2, a, b; cin >> x >> y >> z >> s1 >> c1 >> s2 >> c2 >> a >> b;

    ll k1 = (c1 < c2 ? s1 : s2), k2 = (c1 < c2 ? s2 : s1), m1 = min(c1, c2), m2 = max(c1, c2), p1 = min(x, y) * z, p2 = max(x, y) * z, q1 = min(x, y), q2 = max(x, y);

    if(b > z) cout << -1;
    else if(2*p2+2*p1-a*b <= k1 && (a <= x || a <= y)) cout << (2*p2+2*p1-a*b)*m1;
    else if(2*p2 <= k1 && 2*p1-a*b <= k2 && a <= q1) cout << 2*p2*m1+(2*p1-a*b)*m2;
    else if(2*p2-a*b <= k1 && 2*p1 <= k2 && a <= q2) cout << 2*p1*m2+(2*p2-a*b)*m1;
    else if(2*p2-a*b <= k2 && 2*p1 <= k1 && a <= q2) cout << 2*p1*m1+(2*p2-a*b)*m2;
    else if(2*p2 <= k2 && 2*p1-a*b <= k1 && a <= q1) cout << 2*p2*m2+(2*p1-a*b)*m1;
    else if(2*p2+2*p1-a*b <= k2 && (a <= x || a <= y)) cout << (2*p2+2*p1-a*b)*m2;
    else cout << -1;
}