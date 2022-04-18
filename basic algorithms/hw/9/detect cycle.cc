#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
using namespace std;

struct graph 
{
    int n_v;
    bool * visited;
    list<int> * adj;
    graph(int n_v);
    void clear_visit();
    void add_edge(int v1, int v2);
    bool has_back_edge(int v, int parent);
    bool has_cycle();
    void dfs(int v);
};

graph::graph(int n_v)
{
    this->n_v = n_v;
    adj = new list<int>[n_v];
    visited = (bool *)malloc(n_v * sizeof(bool));
}

void graph::clear_visit()
{
    memset(visited, false, n_v * sizeof(bool));
}
 
void graph::add_edge(int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

bool graph::has_back_edge(int v, int parent)
{
    visited[v] = true;
    for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
        {
            if(has_back_edge(*i, v))
                return true;
        }
        else if(visited[*i])
        {
            if(*i != parent) /* for vertices ancestor -> descendant, 
            descendant.discovery_time < ancestor.discovery_time */
                return true;
        }
    }
    return false;
}

bool graph::has_cycle()
{
    clear_visit();
    for(int i = 0; i < n_v; ++i)
    {
        if(!visited[i])
            if(has_back_edge(i, -1))
                return true;
    }
    return false;
}
 
void graph::dfs(int v)
{
    visited[v] = true;
    printf("%d ", v);
    for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            dfs(*i);
}
 
int main()
{
    graph g1(5);
    g1.add_edge(1, 0);
    g1.add_edge(0, 2);
    g1.add_edge(2, 1);
    g1.add_edge(0, 3);
    g1.add_edge(3, 4);
    bool ret1 = g1.has_cycle();
    printf(ret1 ? "contain cycle\n" : "no cycle\n");
    g1.clear_visit();
    g1.dfs(0);
    printf("\n");

    graph g2(3);
    g2.add_edge(0, 1);
    g2.add_edge(1, 2);
    bool ret2 = g2.has_cycle();
    printf(ret2 ? "contain cycle\n" : "no cycle\n");
    g2.clear_visit();
    g2.dfs(0);
    printf("\n");
}
