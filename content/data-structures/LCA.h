/**
 * Author: Simon Lindholm, chilli
 * Date: 2018-07-23
 * License: CC0
 * Source: http://codeforces.com/blog/entry/60737
 * Description: LEAST COMMON ANCESTOR
 * Uses 1.5x memory. Initial capacity must be a power of 2 (if provided).
 */
#define mx 100002
int L[mx]; // Level of each node
int P[mx][22]; // Sparse table
int T[mx]; // Parent array
vector<int> g[mx];

void dfs(int from, int u, int dep) {
    T[u] = from;
    L[u] = dep;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == from) continue;
        dfs(u, v, dep + 1);
    }
}

int lca_query(int N, int p, int q) { // N = number of nodes
    int tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > L[p]) break;
        log++;
    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

void lca_init(int N) {
    memset(P, -1, sizeof(P)); // Initialize all values to -1
    int i, j;
    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    for (j = 1; (1 << j) < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int main(void) {
    g[0].push_back(1);
    g[0].push_back(2);
    g[2].push_back(3);
    g[2].push_back(4);
    dfs(0, 0, 0);
    lca_init(5);
    printf("%d\n", lca_query(5, 3, 4));
    return 0;
}

