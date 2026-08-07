#include<bits/stdc++.h>

using ll = long long;
using namespace std;

const ll k = 33, p = 1e9+7, maxn = 1e5+5;
ll tohash(string s) {
    ll h = 0;
    for(int i = 0; i < s.size(); i++) {
        ll x = s[i] - 'a' + 1;
        h = (h * k + x) % p;
    }

    return h;
}



int main() {
    string a, b; cin >> a >> b;

    vector<ll> pw(maxn);
    pw[0] = 1;
    for(int i = 1; i < pw.size(); i++) {
        pw[i] = (1ll * pw[i-1] * k) % p;
    }

    ll m = b.size();
    ll h = tohash(a.substr(0, m)), hs = tohash(b);
    for(int i = 0; i <= a.size() - m; i++) {
        if(h == hs) {
            if(a.substr(i, m) == b) {
                cout << i << "\n";
                break;
            }
        }

        if (i == a.size() - m) break;

        ll x = a[i] - 'a' + 1, y = a[i+m] - 'a' + 1;
        h = ((h - x*pw[m-1])*k+y) % p;
    }
}