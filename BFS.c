#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int value) {
    if (rear < MAX - 1) {
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (front <= rear) {
        int val = queue[front];
        front++;
        return val;
    }
    return -1; 
}

int isEmpty() {
    return front > rear;
}

void bfs(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    
    enqueue(start);
    visited[start] = 1;

    printf("BFS order: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int n, start;

    printf("Enter number of nodes (max %d): ", MAX);
    scanf("%d", &n);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(graph, n, start);

    return 0;
}