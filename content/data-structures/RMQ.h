/**
 * Author: Simon Lindholm, chilli
 * Date: 2018-07-23
 * License: CC0
 * Source: http://codeforces.com/blog/entry/60737
 * Description: Find minimum range query 
 * Uses 1.5x memory. Initial capacity must be a power of 2 (if provided).
 */
int st[K + 1][MAXN];

std::copy(array.begin(), array.end(), st[0]);

for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);


int i = log2[R - L + 1];
int minimum = min(st[i][L], st[i][R - (1 << i) + 1]);
