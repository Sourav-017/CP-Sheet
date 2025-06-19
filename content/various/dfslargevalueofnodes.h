
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

#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
set<int> visited;
void dfs(int n)
{
    if (visited.find(n) != visited.end())
        return;
    visited.insert(n);
    for (auto i : adj[n])
        dfs(i);
}
void solve(int testCaseNo)
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(n);
    cout << *visited.rbegin() << nl;
}