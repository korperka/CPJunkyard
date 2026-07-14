#include<bits/stdc++.h>

using ll = long long;

using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll a, b; cin >> a >> b;
    ll d = gcd(a,b);
    if (d < 0) d = -d;

    cout << a/d << " " << b/d << "\n";
}