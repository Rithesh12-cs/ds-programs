#include <stdio.h>
int graph[5][5], visit[5], n;
void BFS(int start){
    int queue[5];
    int rear = 0, front = 0;
    queue[rear++] = start;
    visit[start] = 1;
    while (front < rear){
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n;i++){
            if(graph[v][i]==1 && !visit[i]){
                queue[rear++] = i;
                visit[i] = 1;
            }
        }
    }
}
int main(){
    printf("\nEnter the size:");
    scanf("%d", &n);
    for (int i=0; i < n;i++){
        for (int j = 0; j < n;j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n;i++){
        visit[i] = 0;
    }
    printf("\nBFS Traversals:");
    BFS(0);
    return 0;
}