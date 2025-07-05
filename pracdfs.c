#include <stdio.h>
int graph[5][5],visit[5],n;
void DFS(int v){
    printf("%d ", v);
    visit[v] = 1;
    for (int i = 0; i < n;i++){
        if(graph[v][i]==1 && !visit[i]){
            DFS(i);
        }
    }
}

int main(){
    printf("\nEnter the size:");
    scanf("%d",&n);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < n;i++){
        visit[i] = 0;
    }
    printf("\nDFS Traversal starting from 0:");
    DFS(0);
    return 0;
}