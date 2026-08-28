#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, y; cin >> n >> y;

    ll a = y/10000, b = y%10000/5000, c = y%10000%5000/1000;
    ll p = a+b+c;
    if (n < p) {
        cout << "-1 -1 -1\n";
        return 0;
    }

    ll k = n-p;
    while (k > 9) {
        a--;
        c += 10;
        p += 9;
        k -= 9;
    }
    while (k > 4) {
        b--;
        c += 5;
        p += 4;
        k -= 4;
    }
    while (k > 0) {
        a--;
        b += 2;
        p += 1;
        k -= 1;
    }

    if (k == 0 && a >= 0 && b >= 0 && c >= 0) cout << a << " " << b << " " << c << "\n";
    else cout << "-1 -1 -1\n";
}