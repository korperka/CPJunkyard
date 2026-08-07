#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    if(n <= 1) {
        cout << s[0];
        return 0;
    }

    string ans = s[0];
    for(int i = 1; i < n; i++) {
        string suf = ans.substr(max(0LL, (ll)ans.size() - (ll)s[i].size()));
        string t = s[i] + "#" + suf;
        vector<ll> p(t.size()+1);
        p[0] = -1;

        for(int j = 1; j <= t.size(); j++) {
            ll k = p[j - 1];
            while(k != -1 && t[k] != t[j - 1])
                k = p[k];

            p[j] = k + 1;
        }

        ans += s[i].substr(p.back());
    }

    cout << ans;
}