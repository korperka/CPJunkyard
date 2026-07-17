#include<bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int streak = 1, maxstreak = 1   ;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) streak++;
        else streak = 1;

        maxstreak = max(maxstreak, streak);
    }

    cout << maxstreak << "\n";
}