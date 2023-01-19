#ifndef GRAPH_
#define GRAPH_


typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ 
{
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ 
{
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct Dijkstra {
    pnode node;
    int weight;
    int infor;
    struct Dijkstra *next;
} dijkstra, *dijkstra_P;

void TSP_cmd(pnode head);
void printGraphCmd(pnode head); 
void buildGraphCmd(pnode *head);
void insertNodeCmd(pnode *head);
void deleteNodeCmd(pnode *head);
void deleteGraphCmd(pnode* head);
void addEdge(pnode *head ,int i);
int shortsPathCmd(pnode head, int src, int dest);


#endif