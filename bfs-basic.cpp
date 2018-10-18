#include<stdio.h>
#include<vector>
using namespace std;

vector<int> vec[10005];

int q[10005];
int visited[10005];
int dist[10005];
int t, n, m ,s,i,u,v,front,rear,poppedNode;
int main() {

    scanf("%d",&t);

    while(t--) {

        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++) {
            scanf("%d %d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        for(i=0;i<=n;i++) {
            dist[i]=-1;
        }

        s = 1;
        front=0;
        rear=0;
        q[rear++]=s;
        visited[s]=1;
        dist[s]=0;

        while(front<rear) {
            poppedNode = q[front];
            front++;
            //printf("front =%d  rear=%d %d\n",front, rear, poppedNode);
            for(i=0;i<vec[poppedNode].size();i++){

                if(visited[vec[poppedNode][i]] == 0) {

                    q[rear++]=vec[poppedNode][i];
                    dist[vec[poppedNode][i]]= dist[poppedNode]+1;
                    visited[vec[poppedNode][i]]=1;
                }

            }

        }
        //printf("\n");
        printf("%d\n",dist[n]);

         for(i=0;i<=n;i++) {
            //printf("%d ",dist[i]);
            dist[i]=0;
            visited[i]=0;
            vec[i].clear();
         }

         //printf("\n");

    }
    return 0;
}
