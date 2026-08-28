#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    ll score = 0;
    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;

        if (s == t) {
            score += 10;
            continue;
        }

        int a = s.size(), b = t.size();
        if (abs(a-b) > 1) continue;

        if (a > b) {
            int j = a-1;
            for (int i = 0; i < b; i++) if (s[i] != t[i]) { j = i; break; }
            if (s.substr(0, j) + s.substr(j+1) == t) score += 9;
        }
        else if (a < b) {
            int j = b-1;
            for (int i = 0; i < a; i++) if (s[i] != t[i]) { j = i; break; }
            if (s == t.substr(0, j) + t.substr(j+1)) score += 9;
        }
        else {
            int j = a-1;
            for (int i = 0; i < b; i++) if (s[i] != t[i]) { j = i; break; }
            s[j] = '#'; t[j] = '#';
            if (s == t) score += 9;
        }
    }

    cout << score;
}
