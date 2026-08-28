#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll d(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1-x2)+abs(y1-y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2) cout << 0;
    else if (abs(x1-x2)+abs(y1-y2) <= 3 || (x1+y1==x2+y2 || x1-y1==x2-y2)) cout << 1;
    else if (abs(x1-x2)+abs(y1-y2) <= 6 || (abs(y1-y2) % 2 == 0 && x1%2==x2%2) || (abs(y1-y2) % 2 == 1 && x1%2!=x2%2) || min(abs(abs(x1-x2)+abs(y1-y2)), abs(abs(x1-x2)-abs(y1-y2))) <= 3) cout << 2;
    else cout << 3;
}