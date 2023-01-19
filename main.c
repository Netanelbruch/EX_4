#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include "graph.h"

int main()
{
    pnode temp1 = NULL;
    pnode *head = &temp1;
    char input1 = 'a' ;
    while (scanf("%c", &input1) != EOF)
    {
        if (input1 == 'A')
        {
            buildGraphCmd(head);
        }
        else if (input1 == 'B')
        {
            insertNodeCmd(head);
        }
        else if (input1 == 'D')
        {
            deleteNodeCmd(head);
        }
        else if (input1 == 'S')
        {
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortsPathCmd(*head, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
        }
        else if (input1 == 'T') 
        {
            TSP_cmd(*head);
        }
    }
    deleteGraphCmd(head);
    
    return 0;
}