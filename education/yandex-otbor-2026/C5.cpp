#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t; cin >> s >> t;

    s += '#';
    t += '#';

    vector<pair<char, ll>> s1;
    ll c = 1;
    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] == s[i+1]) c++;
        else {
            s1.push_back({s[i], c});
            c = 1;
        }
    }

    vector<pair<char, ll>> t1;
    c = 1;
    for (int i = 0; i < t.size()-1; ++i) {
        if (t[i] == t[i+1]) c++;
        else {
            t1.push_back({t[i], c});
            c = 1;
        }
    }

    if (s1.size() != t1.size()) {
        cout << "NO";
        return 0;
    }
    bool f = true;
    for (int i = 0; i < s1.size(); ++i) {
        ll a = s1[i].second, b = t1[i].second;
        if ((a < 2 && b != a) || (b < a) || (s1[i].first != t1[i].first)) {
            f = false;
            break;
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
}

//aaba
//aabaa
