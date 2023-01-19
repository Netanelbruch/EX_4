#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "graph.h"




void buildGraphCmd(pnode *head) 
{
    deleteGraphCmd(head);
    int num = 0;
    scanf("%d", &num);
    char node = ' ';
    scanf("%c", &node);
    for (int k = 0; k < num; ++k)
    {
        scanf("%c", &node);
        insertNodeCmd(head);
    }
}

void deleteGraphCmd(pnode* head)
{


 pnode pNonde = *head; 
 
    while (pNonde!= NULL) 
    {
        pedge pEdge = pNonde->edges;

        
        while (pEdge != NULL) 
        {
            pedge temp = pEdge;
            pEdge = pEdge->next;
            free(temp);
     
        }
        pnode temp2 = pNonde;
        pNonde = pNonde->next;
        free(temp2);
    }
    *head = NULL;
}


void printGraphCmd(pnode head) 
{
    
    pnode pNode2 = head; 
    
    while (pNode2 != NULL) 
    {
        printf("Node %d: ", pNode2->node_num); 
        pedge edg2 = pNode2->edges;
        while (edg2 != NULL)
        {
            printf("D= %d: W= %d, ", edg2->endpoint->node_num, edg2->weight); 
            edg2 = edg2->next;
        }
        printf("\n");
        pNode2 = pNode2->next;
    }
    
    
}



pnode getNode(int id_node, pnode *head) 
{
    pnode temp = *head;
    while (temp != NULL)
    {
        if (temp->node_num == id_node)
        {
            return temp;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}


void deleteNodeCmd(pnode *head){ 
    int inf;
	scanf("%d", &inf);
	pnode copy = *head;
	while (copy != NULL) 
    {
		if (copy->edges != NULL && copy->edges->endpoint->node_num == inf) 
        {
			pedge new = copy->edges;
			copy->edges = copy->edges->next;
			free(new);
		}
		copy = copy->next;
	}
	pnode temp2 = *head, next = *head;
	next = temp2->next;
	while (next) {
		if (next->node_num == inf) 
        {
			temp2->next = next->next;

            pedge deledge = next->edges;
            while (deledge != NULL)
            {
                pedge temp3 = deledge;
                deledge = deledge->next;
                free(temp3);
            }

			free(next);
			next = temp2;
		}
		else {
			temp2 = next;
			next = temp2->next;
		}
	}
}


void insertNodeCmd(pnode *head)
{
    int inf = -1;
    scanf("%d", &inf);
    pnode getNode1 = getNode(inf,head);
    if (getNode1 == NULL)
    {
        getNode1 = (pnode)malloc(sizeof(node));
        if (getNode1 == NULL)
        {
            return;
        }
        getNode1->node_num = inf;
        getNode1->next = *head;
        getNode1->edges = NULL;
        *head = getNode1;
    }
    else
    {
        pedge edge1 = getNode1->edges;
        while (edge1 != NULL)
        {
            pedge temp = edge1->next;
            free(edge1);
            edge1 = temp;
        }
        getNode1->edges = NULL;
    }
    int dest = -1;
    pedge *edge2 = &(getNode1->edges);
    int d = scanf("%d", &dest);
    while (d != 0 && d != EOF)
    {
        pnode newNode = getNode(dest,head);
        if (newNode== NULL)
	{
            newNode = (pnode)malloc(sizeof(node));
            if (newNode == NULL)
            {
                return;
            }
            newNode->node_num = dest;
            newNode->edges = NULL;
            newNode->next = *head;
            *head =newNode;
        }
        int weight = -1;
        scanf("%d", &weight);

        *edge2 = (pedge)malloc(sizeof(edge));
        if ((*edge2) == NULL)
        {
            return;
        }
        (*edge2)->weight = weight;
        (*edge2)->endpoint = newNode;
        (*edge2)->next = NULL;
        edge2 = &((*edge2)->next);
        d = scanf("%d", &dest);
    }
}