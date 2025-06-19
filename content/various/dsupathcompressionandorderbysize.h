
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

int parent[1000001], size[1000001];
void initialize(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        size[i] = 1;
    }
}
int find_set(int n)
{
    if (parent[n] == n)
        return n;
    return parent[n] = find_set(parent[n]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
