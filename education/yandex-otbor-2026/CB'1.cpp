#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll hh = 0, mm = 0, ss = 0;
    ll n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        mm += stoi(s.substr(0, 2));
        ss += stoi(s.substr(3, 2));
    }

    mm += ss/60;
    ss %= 60;
    hh += mm/60;
    mm %= 60;

    cout << (hh < 10 ? "0" : "") << hh << ":" << (mm < 10 ? "0" : "") << mm << ":" << (ss < 10 ? "0" : "") << ss;
}