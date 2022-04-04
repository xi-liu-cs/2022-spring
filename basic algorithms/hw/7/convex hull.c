#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int block = 128;

typedef struct point
{ int x, y; } point;

point p0;

void print_stack(point * s, int top)
{
    for(int i = top - 1; i >= 0; --i)
        printf("{%d, %d}\n", s[i].x, s[i].y);
    printf("\n");
}

void print(point * p, int n)
{
    for(int i = 0; i < n; ++i)
        printf("{%d, %d}\n", p[i].x, p[i].y);
    printf("\n");
}

void swap(point * p, int i, int j)
{
    point t = p[i];
    p[i] = p[j];
    p[j] = t;
}

/* distance squared 
= (sqrt{(x2 - x1)^2 + (y2 - y1)^2})^2 */
int dist_sq(point a, point b)
{
    return (b.x - a.x) * (b.x - a.x)
         + (b.y - a.y) * (b.y - a.y);
}

/* return 1 iff b is on 
the segement a to c*/
int on_segment(point a, point b, point c)
{
    return b.x <= fmax(a.x, c.x) 
        && b.x >= fmin(a.x, c.x)
        && b.y <= fmax(a.y, c.y)
        && b.y >= fmin(a.y, c.y);
}

point recv_point(point * input, int i)
{
    return input[i];
}

/* slope1 = (y2 - y1) / (x2 - x1)
slope2 = (y3 - y2) / (x3 - x2)
if(slope1 == slope2)
    collinear
else if(slope1 < slope2)
    slope1 - slope2 < 0
    orientation is counterclockwise
else if(slope1 > slope2)
    slope1 - slope2 > 0
    orientation is clockwise
    
slope1 - slope2 will have
the same sign with 
(x2 - x1)(x3 - x2)(slope1 - slope2)
= (y2 - y1)(x3 - x2) - (y3 - y2)(x2 - x1) 

orient() returns an integer indicating
the orientation of points (a, b, c):
    0, if a, b, and c are collinear
    a negative value if orientation is counterclockwise
    a positive value if orientation is clockwise */
int orient(point a, point b, point c)
{
    return (b.y - a.y) * (c.x - b.x)
         - (c.y - b.y) * (b.x - a.x);
}

/* compare distance to p0 */
int cmp(const void * a1, const void * a2)
{
    point * p1 = (point *)a1;
    point * p2 = (point *)a2;
    int ori;
    if(!(ori = orient(p0, *p1, *p2)))
        return dist_sq(p0, *p1) - dist_sq(p0, *p2);
    return ori;
}

point * graham_scan(point * p, int n, int * top)
{
    int y_min = (*p).y, min_i = 0;
    for(int i = 1; i < n; ++i)
    {
        int y = p[i].y;
        if((y < y_min) 
        || (y == y_min && p[i].x < p[min_i].x))
        {
            y_min = p[i].y;
            min_i = i;
        }
    }
    swap(p, 0, min_i);
    p0 = *p;
    
    qsort(p + 1, n - 1, sizeof(point), cmp);
    int sz = 1;
    for(int i = 1; i < n; ++i)
    {
        while(i < n - 1 && !orient(p0, p[i], p[i + 1]))
            ++i;
        p[sz++] = p[i];
    }
    if(sz < 3) return 0;
    
    point * s = malloc(sz * sizeof(point));
    *top = 0;
    s[(*top)++] = *p;
    s[(*top)++] = p[1];
    s[(*top)++] = p[2];
    
    for(int i = 3; i < sz; ++i)
    {
        while(*top && orient(s[*top - 2], s[*top - 1], p[i]) >= 0)
            --(*top);
        s[(*top)++] = p[i];
    }
    return s;
}

point * jarvis_march(point * p, int n, int * ret_sz)
{
    if(n < 3) return 0;
    point * ret = malloc(n * sizeof(point));
    *ret_sz = 0;
    
    int left_i = 0;
    for(int i = 1; i < n; ++i)
        if(p[i].x < p[left_i].x)
            left_i = i;
    
    int cur_p = left_i, c;
    while(1)
    {
        ret[(*ret_sz)++] = p[cur_p];
        c = (cur_p + 1) % n;
        for(int i = 0; i < n; ++i)
            if(orient(p[cur_p], p[i], p[c]) < 0)
                c = i;
        cur_p = c;
        if(cur_p == left_i)
            break;
    }
    return ret;
}

point * convex_hull_jarvis_march(point * p, int n, int * ret_sz)
{
    if(n < 3) return 0;
    point * ret = malloc(n * sizeof(point));
    *ret_sz = 0;
    
    int left_i = 0;
    
    int cur_p = left_i, c, recv_i = -1;
    while(1)
    {
        ++recv_i;
        p[recv_i] = recv_point(p, recv_i);
        if(p[recv_i].x < p[left_i].x)
            left_i = recv_i;
        ret[(*ret_sz)++] = p[cur_p];
        c = (cur_p + 1) % n;
        for(int i = 0; i < n; ++i)
            if(orient(p[cur_p], p[i], p[c]) < 0)
                c = i;
        cur_p = c;
        printf("after receive point {%d, %d}, convex hull is\n", ret[recv_i].x, ret[recv_i].y);
        print(ret, recv_i + 1);
        if(cur_p == left_i)
            break;
    }
    return ret;
}

void convex_hull_graham_scan(point * input, int n)
{
    int cur_sz = block;
    point * p = malloc(cur_sz * sizeof(point));
    for(int i = 0; i < n; ++i)
    {
        if(i >= cur_sz)
        {
            cur_sz += block;
            p = realloc(p, cur_sz * sizeof(point));
        }
        p[i] = recv_point(input, i); /* receive a point */
        int top = 0;
        point * s = graham_scan(p, i + 1, &top);
        printf("after receive point {%d, %d}, convex hull is\n", p[i].x, p[i].y);
        print_stack(s, top);
    }
}

int main()
{
    printf("graham_scan:\n");
    point p[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
             {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(p) / sizeof(*p);
    int top;
    point * s = graham_scan(p, n, &top);
    print_stack(s, top);
    convex_hull_graham_scan(p, n);
    
    printf("jarvis_march:\n");
    int ret_sz;
    point * s2 = jarvis_march(p, n, &ret_sz);
    print(s2, ret_sz);
    convex_hull_jarvis_march(p, n, &ret_sz);
}