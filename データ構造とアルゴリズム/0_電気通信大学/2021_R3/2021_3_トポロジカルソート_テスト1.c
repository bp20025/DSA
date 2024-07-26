#include <stdio.h>
#include <stdlib.h>

#define N 7

// 設問の有向グラフの隣接行列
int adj[N][N] = {
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};


int visited[N]; // 訪問済みの配列
int stack[N]; // トポロジカル順序のスタック
int top = -1; // スタックのトップインデックス

void dfs(int v) {
    for (int i = 0; i < N; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    visited[v] = 1;
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("トポロジカル順序: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    topologicalSort();
    return 0;
}
