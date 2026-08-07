#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int mod1 = 1e9 + 7, mod2 = 1e9 + 9, koef = 32;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t; cin >> s >> t;
    ll k; cin >> k;

    vector<bool> g(26);
    for(int i = 0; i < g.size(); i++) g[i] = (t[i] == '1');

    ll c = 0;
    vector<ll> p(s.size(), 0);
    for(int i = 0; i < p.size(); i++) {
        if(!g[s[i]-'a']) c++;
        p[i] = c;
    }

    vector<ll> pw1(1e5 + 5);
    pw1[0] = 1;
    for(int i = 1; i < pw1.size(); i++)
        pw1[i] = (1ll * pw1[i - 1] * koef) % mod1;

    vector<ll> pw2(1e5 + 5);
    pw2[0] = 1;
    for(int i = 1; i < pw2.size(); i++)
        pw2[i] = (1ll * pw2[i - 1] * koef) % mod2;

    set<pair<ll, ll>> ans;
    for(int i = 0; i < s.size(); i++) {
        ll h1 = 0, h2 = 0, pow = 0;
        for(int j = i; j < s.size(); j++) {
            h1 = (h1 + 1LL * (s[j] - 'a' + 1) * pw1[pow]) % mod1;
            h2 = (h2 + 1LL * (s[j] - 'a' + 1) * pw2[pow]) % mod2;
            pow++;

            ll n = (i == 0 ? p[j] : p[j]-p[i-1]);
            if(n <= k) ans.insert({h1, h2});
        }
    }

    cout << ans.size() << "\n";
}