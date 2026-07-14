    #include<bits/stdc++.h>

    using ll = long long;

    using namespace std;

    int main() {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll dx = abs(c-a), dy = abs(d-b);
        cout << dx+dy-gcd(dx,dy) << "\n";
    }