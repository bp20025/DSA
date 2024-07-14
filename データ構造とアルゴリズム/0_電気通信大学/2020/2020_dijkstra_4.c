#include <stdio.h>
#include <stdlib.h>

#define V 5 // 頂点数
#define INFTY 999

// 優先度付き待ち行列の要素を表す構造体
typedef struct {
    int vertex; // ノードの番号
    int distance; // 優先度（距離など）
} PQElement;

// 優先度付き待ち行列の定義
typedef struct {
    PQElement *elements; // 要素の配列
    int capacity; // 配列の容量
    int last; // 最後尾の要素番号
} PriorityQueue;

// 優先度付き待ち行列の初期化
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->elements = (PQElement *)malloc(capacity * sizeof(PQElement));
    pq->capacity = capacity;
    pq->last = -1;
    return pq;
}

// 優先度付き待ち行列が空かどうかを判定する関数
int isEmpty(PriorityQueue *pq) {
    return pq->last == -1;
}

// 要素を交換する関数
void swap(PQElement *a, PQElement *b) {
    PQElement temp = *a;
    *a = *b;
    *b = temp;
}

// 優先度付き待ち行列に要素を追加する関数
void enqueue(PriorityQueue *pq, int vertex, int distance) {
    if (pq->last < pq->capacity - 1) {
        pq->last++;
        pq->elements[pq->last].vertex = vertex;
        pq->elements[pq->last].distance = distance;

        int current = pq->last;
        while (current > 0) {
            int parent = (current - 1) / 2;
            if (pq->elements[current].distance < pq->elements[parent].distance) {
                swap(&pq->elements[current], &pq->elements[parent]);
                current = parent;
            } else {
                break;
            }
        }
    }
}

// 優先度付き待ち行列から最小の要素を取り出す関数
PQElement dequeue(PriorityQueue *pq) {
    if (!isEmpty(pq)) {
        PQElement minElement = pq->elements[0];
        pq->elements[0] = pq->elements[pq->last];
        pq->last--;

        int current = 0;
        while (1) {
            int L = 2 * current + 1;
            int R = 2 * current + 2;
            int min = current;

            if (L <= pq->last && pq->elements[L].distance < pq->elements[min].distance) {
                min = L;
            }
            if (R <= pq->last && pq->elements[R].distance < pq->elements[min].distance) {
                min = R;
            }

            if (min == current) {
                break;
            }

            swap(&pq->elements[current], &pq->elements[min]);
            current = min;
        }

        return minElement;
    }

    PQElement errorElement = { -1, INFTY };
    return errorElement;
}

// メイン関数での使用例
int main() {
    int w[V][V] = {
        {0, 3, -1, 7, -1}, // 1 -> (2: 3), (4: 7)
        {-1, 0, 4, 1, -1}, // 2 -> (3: 4), (4: 1)
        {-1, 3, 0, -1, 2}, // 3 -> (2: 3), (5: 2)
        {-1, -1, 4, 0, 2}, // 4 -> (3: 4), (5: 2)
        {-1, 1, -1, -1, 0}  // 5 -> (2: 1)
    };

    int d[V]; // ダイクストラ法による最短距離の保持
    for (int i = 0; i < V; i++) {
        d[i] = INFTY;
    }
    d[0] = 0; // 始点から始める

    // 優先度付き待ち行列の初期化
    PriorityQueue *pq = createPriorityQueue(V);
    enqueue(pq, 0, 0); // 始点の距離を優先度付き待ち行列に追加

    while (!isEmpty(pq)) {
        PQElement current = dequeue(pq);
        int u = current.vertex;

        // uに隣接するすべての頂点jに対して
        for (int j = 0; j < V; j++) {
            if (w[u][j] != -1) {
                // より短い経路が見つかれば更新
                if (d[j] > d[u] + w[u][j]) {
                    d[j] = d[u] + w[u][j];
                    enqueue(pq, j, d[j]); // 更新した距離を優先度付き待ち行列に追加
                }
            }
        }
    }

    // 結果の出力
    printf("頂点からの最短距離:\n");
    for (int i = 0; i < V; i++) {
        printf("頂点 %d までの距離: %d\n", i, d[i]);
    }

    return 0;
}
