#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    long long a, b, x, y; cin >> a >> b >> x >> y;

    cout << min(min(abs(a-b), abs(a-x)+abs(b-y)), abs(a-y)+abs(b-x));
}