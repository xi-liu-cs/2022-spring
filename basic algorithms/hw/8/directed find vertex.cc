#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void add_edge(int i, int j)
{
    adj[i][j] = 1;
}

void bfs(int src_id)
{
    bool visited[adj.size()];
    memset(visited, false, sizeof(visited));
    
    vector<int> queue;
    visited[src_id] = true;
    queue.push_back(src_id);
    
    int cur_id;
    while(!queue.empty())
    {
        cur_id = queue.front();
        printf("%d ", cur_id);
        queue.erase(queue.begin());
        for(int i = 0; i < adj[cur_id].size(); ++i)
        {
            if(adj[cur_id][i] && !visited[i])
            {
                queue.push_back(i);
                visited[i] = true;
            }
        }
    }
}

bool sink(int i)
{
    for(int j = 0; j < adj.size(); ++j)
    {
        if(adj[i][j]) /* vertex has an outgoing edge*/
            return false;
        if(!adj[j][i] && j != i) /* within column j, only adj[i][i] can be 0 */
            return false;
    }
    return true;
}

bool find(int * idx)
{
    int i = 0, j = 0;
    while(i < adj.size() && j < adj.size())
    {
        if(adj[i][j])
            ++i;
        else    
            ++j;
    }
    if(i > adj.size())
        return false;
    else if(!sink(i))
        return false;
    *idx = i;
    return true;
}

int main()
{
    int v = 4;
    adj = vector<vector<int>>(v, vector<int>(v, 0));
    add_edge(0, 3);
    add_edge(1, 3);
    add_edge(2, 3);
    bfs(0);
    int idx;
    printf("\nfind = %d\n", find(&idx));
    printf("idx = %d\n", idx);
}