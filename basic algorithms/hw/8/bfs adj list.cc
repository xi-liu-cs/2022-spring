#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
using namespace std;

/* dist_src: distance from the source s to this node */
struct node
{
    int node_id;
};

/* adj: pointer to an array containing adjacency lists */
struct graph
{
    int num_node;
    list<node *> * adj;
};

node * malloc_node(int node_id)
{
    node * n = (node *)malloc(sizeof(node));
    n->node_id = node_id;
    return n;
}

graph * malloc_graph(int num_node)
{
    graph * g = (graph *)malloc(sizeof(graph));
    list<node *> * adj = new list<node *>[num_node];
    g->num_node = num_node;
    g->adj = adj;
    return g;
}

void add_edge(graph * g, int node_id, node * n)
{
    g->adj[node_id].push_back(n);   
}

void bfs(graph * g, int src_id, bool ** visited)
{
    *visited = (bool *)malloc(g->num_node * sizeof(node));
    memset(*visited, false, g->num_node * sizeof(node));
    
    list<int> queue;
    (*visited)[src_id] = true;
    queue.push_back(src_id);
    
    list<node *>::iterator i;
    while(!queue.empty())
    {
        int cur_id = queue.front();
        printf("%d ", cur_id);
        queue.pop_front();
        for(i = g->adj[cur_id].begin(); i != g->adj[cur_id].end(); ++i)
        {
            if(!(*visited)[(*i)->node_id])
            {
                queue.push_back((*i)->node_id);
                (*visited)[(*i)->node_id] = true;
            }
        }
    }
}

bool check_connect(graph * g)
{
    bool * visited;
    bfs(g, 0, &visited);
    for(int i = 0; i < g->num_node; ++i)
        if(!visited[i])
            return false;
    return true;
}

int main()
{
    graph * g = (graph *)malloc_graph(4);
    node * n0 = malloc_node(0);
    node * n1 = malloc_node(1);
    node * n2 = malloc_node(2);
    node * n3 = malloc_node(3);
    add_edge(g, 0, n1);
    add_edge(g, 0, n2);
    add_edge(g, 1, n2);
    add_edge(g, 2, n0);
    add_edge(g, 2, n3);
    add_edge(g, 3, n3);
    bool * visited;
    bfs(g, 2, &visited);
    printf("\n");
    printf("\ncheck_connect(g) = %d\n", check_connect(g));
}