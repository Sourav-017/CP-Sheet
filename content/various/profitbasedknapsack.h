/**
 * Author: Null
 * Date: Happy new Year 2025
 * License: CC0
 * Source: Conversation with Håkan and Ulf.
 * Description: Example structures and functions that doesn't really do
 *  anything. Latex commands are supported here, though! Like this: $2^2=3$

 */


const int infinity = 1e9 + 1;
void solve() {
    int n, w, sum = 0; cin >> n >> w;
    int weight[n], value[n];
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
        sum += value[i];
    }
    vector<int> dp(sum + 1, infinity);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= value[i]; --j) {
            int temp = dp[j - value[i]] + weight[i];
            if ((temp <= w) && (temp < dp[j]))
                dp[j] = temp;
        }
    }
    for (int i = sum; i >= 0; --i) {
        if (dp[i] != infinity) {
            cout << i;
            return;
        }
    }
}
