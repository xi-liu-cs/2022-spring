#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void add_edge(int i, int j)
{
    adj[i][j] = 1;
    adj[j][i] = 1;
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

int main()
{
    int v = 5;
    adj = vector<vector<int>>(v, vector<int>(v, 0));
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    bfs(0);
}