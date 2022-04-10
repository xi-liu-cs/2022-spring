#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;

enum color{white, gray, black};

struct vtex
{
    int id, color, dist;
    vtex * parent;
};

struct node
{
    vtex * v;
    node * next;
};

struct link
{
    node * head, * tail;
    int sz;
};

struct graph
{
    int num_vtex;
    link ** adj;
};

vtex * malloc_vtex(int id)
{
    vtex * v = (vtex *)malloc(sizeof(vtex));
    v->id = id;
    v->color = white;
    v->dist = ((unsigned int)1 << 31) - 1;
    v->parent = 0;
    return v;
}

node * malloc_node(vtex * v)
{
    node * n = (node *)malloc(sizeof(node));
    n->v = v;
    n->next = 0;
    return n;
}

link * malloc_link(node * n)
{
    link * l = (link *)malloc(sizeof(link));
    l->head = n;
    l->tail = n;
    l->sz = 0;
    return l;
}

graph * malloc_graph(int num_vtex)
{
    graph * g = (graph *)malloc(sizeof(graph));
    link ** adj = (link **)malloc(num_vtex * sizeof(link *));
    for(int i = 0; i < num_vtex; ++i)
        adj[i] = malloc_link(0);
    g->num_vtex = num_vtex;
    g->adj = adj;
    return g;
}

void add_edge(graph * g, node * a, node * b)
{
    node * temp;
    link * l = g->adj[a->v->id];
    if(!l->head || !l->tail)
        l->head = l->tail = b;
    else
    {
        temp = l->tail;
        l->tail = b;
        temp->next = b; /* a -> b */
    }

    l = g->adj[b->v->id];
    if(!l->head || !l->tail)
        l->head = l->tail = a;
    else
    {
        temp = l->tail;
        l->tail = a;
        temp->next = a; /* b -> a */
    }
}

void enqueue(link * l, node * n)
{
    if(!l->head || !l->tail)
        l->head = l->tail = n;
    else
    {
        node * temp = l->tail;
        l->tail = n;
        temp->next = n;
    }
    ++(l->sz);
}

node * dequeue(link * l)
{
    node * temp;
    if(!l->sz)
        return 0;
    if(l->sz == 1)
    {
        temp = l->head;
        l->head = l->tail = 0;
        l->sz = 0;
        return temp;
    }
    temp = l->head;
    l->head = l->head->next;
    --(l->sz);
    return temp;
}

// void bfs(graph * g, node * src)
// {
//     vtex * s = src->v;
//     s->color = gray;
//     s->dist = 0;
//     s->parent = 0;
//     link * q = malloc_link(0);
//     enqueue(q, src);
//     while(q->sz)
//     {
//         node * deq = dequeue(q);
//         for(node * cur_n = g->adj[deq->v->id]->head; cur_n; cur_n = cur_n->next)
//         {
//             vtex * cur_v = cur_n->v;
//             if(cur_v->color == white)
//             {
//                 printf("%d ", cur_v->id);
//                 cur_v->color = gray;
//                 cur_v->dist = deq->v->dist + 1;
//                 cur_v->parent = deq->v;
//                 enqueue(q, cur_n);
//             }
//         }
//         deq->v->color = black;
//     }
// }

void bfs(graph * g, node * src)
{
    vtex * s = src->v;
    s->color = gray;
    s->dist = 0;
    s->parent = 0;
    queue<node *> q;
    q.emplace(src);
    while(!q.empty())
    {
        node * deq = q.front();
        q.pop();
        int cnt = 0;
        for(node * cur_n = g->adj[deq->v->id]->head; cur_n; cur_n = cur_n->next)
        {
            vtex * cur_v = cur_n->v;
            if(cur_v->color == white)
            {
                printf("%d ", cur_v->id);
                cur_v->color = gray;
                cur_v->dist = deq->v->dist + 1;
                cur_v->parent = deq->v;
                q.emplace(cur_n);
            }
        }
        deq->v->color = black;
    }
}

int main()
{
    vtex * v0 = malloc_vtex(0);
    vtex * v1 = malloc_vtex(1);
    vtex * v2 = malloc_vtex(2);
    vtex * v3 = malloc_vtex(3);
    node * n0 = malloc_node(v0);
    node * n1 = malloc_node(v1);
    node * n2 = malloc_node(v2);
    node * n3 = malloc_node(v3);
    graph * g = (graph *)malloc_graph(4);
    add_edge(g, n0, n1);
    add_edge(g, n0, n2);
    add_edge(g, n1, n2);
    add_edge(g, n2, n0);
    add_edge(g, n2, n3);
    add_edge(g, n3, n3);
    bfs(g, n2);
}