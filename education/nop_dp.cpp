// НОП (Наибольшая Общая Подпоследовательность) - подпоследовательность максимального размера, которая есть в двух строках
// F.E: у строк 1938230004 и 12999898398784 это будет 19384

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[i].size(); j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    string lcs = "";
    int i = a.size(), j = b.size();
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcs.push_back(a[i-1]);
            --i;
            --j;
        }
        else if (dp[i-1][j] == dp[i][j]) --i;
        else --j;
    }

    reverse(lcs.begin(), lcs.end());

    cout << dp[a.size()][b.size()] << "\n";
    cout << lcs << "\n";
}