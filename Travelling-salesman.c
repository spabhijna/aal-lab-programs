#include <stdio.h>
#include <limits.h>

#define N 4
#define INF INT_MAX

int tsp(int mask, int pos, int dist[N][N], int dp[N][1 << N]) {
    if (mask == (1 << N) - 1)
        return dist[pos][0];
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    int ans = INF;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            if (newAns < ans)
                ans = newAns;
        }
    }
    return dp[pos][mask] = ans;
}

int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[N][1 << N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < (1 << N); j++)
            dp[i][j] = -1;
    int result = tsp(1, 0, dist, dp);
    printf("Minimum cost: %d\n", result);
    return 0;
}
