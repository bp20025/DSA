#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5 // 頂点数

// 優先度付き待ち行列の要素を表す構造体
typedef struct {
    int vertex; // ノードの番号
    int priority; // 優先度（距離など）
} PQElement;

// 優先度付き待ち行列の定義
typedef struct {
    PQElement *elements; // 要素の配列
    int capacity; // 配列の容量
    int size; // 現在の要素数
} PriorityQueue;

// 優先度付き待ち行列の初期化
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->elements = (PQElement *)malloc(capacity * sizeof(PQElement));
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}

// 優先度付き待ち行列が空かどうかを判定する関数
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// 優先度付き待ち行列に要素を追加する関数
void enqueue(PriorityQueue *pq, int vertex, int priority) {
    if (pq->size < pq->capacity) {
        // 新しい要素を追加
        pq->elements[pq->size].vertex = vertex;
        pq->elements[pq->size].priority = priority;
        pq->size++;

        // ヒープの再構成（最小ヒープを保つ）
        int i = pq->size - 1;
        while (i > 0 && pq->elements[i].priority < pq->elements[(i - 1) / 2].priority) {
            // 親との交換
            PQElement temp = pq->elements[i];
            pq->elements[i] = pq->elements[(i - 1) / 2];
            pq->elements[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
}

// 優先度付き待ち行列から最小の要素を取り出す関数
PQElement dequeue(PriorityQueue *pq) {
    if (!isEmpty(pq)) {
        // 最小要素を取り出す
        PQElement minElement = pq->elements[0];
        // 最後の要素を先頭に移動
        pq->elements[0] = pq->elements[pq->size - 1];
        pq->size--;

        // ヒープの再構成（最小ヒープを保つ）
        int i = 0;
        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            // 左の子と比較
            if (left < pq->size && pq->elements[left].priority < pq->elements[smallest].priority) {
                smallest = left;
            }
            // 右の子と比較
            if (right < pq->size && pq->elements[right].priority < pq->elements[smallest].priority) {
                smallest = right;
            }

            // 最小ヒープの条件を満たしていれば終了
            if (smallest == i) {
                break;
            }

            // 要素の交換
            PQElement temp = pq->elements[i];
            pq->elements[i] = pq->elements[smallest];
            pq->elements[smallest] = temp;

            i = smallest;
        }

        return minElement;
    }

    // エラー処理（本来はあり得ないはず）
    PQElement errorElement = { -1, INT_MAX };
    return errorElement;
}

// メイン関数での使用例
int main() {
    int graph[V][V] = {
        {0, 3, INT_MAX, 7, INT_MAX}, // 1 -> (2: 3), (4: 7)
        {INT_MAX, 0, 4, 1, INT_MAX}, // 2 -> (3: 4), (4: 1)
        {INT_MAX, 3, 0, INT_MAX, 2}, // 3 -> (2: 3), (5: 2)
        {INT_MAX, INT_MAX, 4, 0, 2}, // 4 -> (3: 4), (5: 2)
        {INT_MAX, 1, INT_MAX, INT_MAX, 0}  // 5 -> (2: 1)
    };

    int distances[V]; // ダイクストラ法による最短距離の保持
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
    }
    distances[0] = 0; // 始点から始める

    // 優先度付き待ち行列の初期化
    PriorityQueue *pq = createPriorityQueue(V);
    enqueue(pq, 0, 0); // 始点の距離を優先度付き待ち行列に追加

    while (!isEmpty(pq)) {
        PQElement current = dequeue(pq);
        int u = current.vertex;

        // uに隣接するすべての頂点vに対して
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INT_MAX) {
                int newDistance = distances[u] + graph[u][v];
                // より短い経路が見つかれば更新
                if (newDistance < distances[v]) {
                    distances[v] = newDistance;
                    enqueue(pq, v, newDistance); // 更新した距離を優先度付き待ち行列に追加
                }
            }
        }
    }

    // 結果の出力
    printf("頂点からの最短距離:\n");
    for (int i = 0; i < V; i++) {
        printf("頂点 %d までの距離: %d\n", i, distances[i]);
    }

    return 0;
}
