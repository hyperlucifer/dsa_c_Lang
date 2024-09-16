/*
1)Adjiaceny list -> Marks the nodes with the list of its neighbors.
2)Adjiaceny matrix -> in 2d array =1 for an edge between i and j ,0 otherwise.

*  graft traversal refers to the process of visiting (checking or updating)
    each vertex (node) in a graph.

* algo of traversal
1)breath fist search ->queue DS is used

    *)method 1....

    BFS spanning tree

    1)we can start with any source node as root
    2)Lets start with 0
    3)Try to construct a tree with 0 as the root
    4)Mark all the sideways or duplicate edges as dashed
    5)This constructed tree is called BFS spanning tree
    6)Level order traversal of a BFS spanning tree is a valid
      BFS traversal of a graph

    *)method 2.....

    1)create 2 arrays
        a)visited
        b)exploration queue
    2)we can start with any source node ,in here start with 0
    3)start with 0 and insert it in the exploration queue
    4)visit all the connected vertices and insert them fron the exploration queues poped
      elements

    visited queue is the BFS traversal of a graft

    points
    1)we can start with any vertex
    2)There can be miltiple BFS results for a given graph
    3)The order of visiting vertices can be anything
*/

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
        };
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void DFS(int i){
    int j;
    printf("%d ",i);
    visited[i]=1;
    for (int j = 0; j < 7; j++)
    {
       if (a[i][j]==1&& !visited[j])
       {
         DFS(j);
       }
       
    }
    

}

int main()
{
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // for bfs
    //  BFS Implementation
    // int node;
    // int i = 1;
    
    // printf("%d", i);
    // visited[i] = 1;
    // enqueue(&q, i); // Enqueue i for exploration
    // while (!isEmpty(&q))
    // {
    //     int node = dequeue(&q);
    //     for (int j = 0; j < 7; j++)
    //     {
    //         if (a[node][j] == 1 && visited[j] == 0)
    //         {
    //             printf("%d", j);
    //             visited[j] = 1;
    //             enqueue(&q, j);
    //         }
    //     }
    // }
// 2)depth fist search -> stack DS is used
    /*
    1)start by putting any one of the ghaph's vertices 
      on top of stack.
    2)Take the top item of the stack and add it to the visited list.
    3)Create a list of that vertex's adjacent nodes.add the ones 
      which aren't in the visited list to the top of the stack.
    4)Keep repeating steps 2 and 3 until the stack is empty
    */

    DFS(0);
    return 0;
}


