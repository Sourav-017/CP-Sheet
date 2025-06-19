
/**
 * Author: Nill
 * Date: 2025(Happy New Year)
 * License: LOL
 * Source: Hello @everyone.
 * Description: Example structures and functions that doesn't really do
 *  anything. Latex commands are supported here, though! Like this: $2^2=3$
 * Usage:
 * Status: Untested
 */
const int mod = 100000007;
int coin[50], amount[50], dp[51][1001];
int coinChange(int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    dp[n][sum] = 0;
    for (int i = 0; i <= amount[n - 1] && i * coin[n - 1] <= sum; i++)
        dp[n][sum] += (coinChange(n - 1, sum - i * coin[n - 1]) % mod);
    return (dp[n][sum] % mod);
}
void solve()
{
    int n, sum;
    cin >> n >> sum;
    for (int i = 0; i < n; ++i)
        cin >> coin[i];
    for (int i = 0; i < n; ++i)
        cin >> amount[i];
    int bottom_up_dp[n + 1][sum + 1];
    for (int i = 0; i <= sum; ++i)
        bottom_up_dp[0][i] = 0;
    for (int i = 0; i <= n; ++i)
        bottom_up_dp[i][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            bottom_up_dp[i][j] = 0;
            for (int k = 0; (k <= amount[i - 1]) && ((k * coin[i - 1]) <= j); ++k)
            {
                bottom_up_dp[i][j] += (bottom_up_dp[i - 1][j - k * coin[i - 1]]);
                bottom_up_dp[i][j] %= mod;
            }
        }
    }
    cout << bottom_up_dp[n][sum] << '\n';
    memset(dp, -1, sizeof(dp));
    cout << coinChange(n, sum) << '\n';
}
