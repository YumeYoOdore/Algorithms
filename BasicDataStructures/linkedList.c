#include <stdio.h>
#include <stdlib.h>

/**
 * Algorithms note:
 * From the book Introduction to Algorithms, pseudocode is presented
 * for a doubly linked list, currently doing this as a single linked list
 * will add more complexity as the code advances
*/

/**
 * Compiler Notes:
 * This doesn't seem to be working on Windows (compiled through minGW)
 * but is working correctly on linux (compiled through gcc)
 * need to look further into this issue, but since this is only a personal
 * exercise I'm pushing in it's current state
*/

struct Node
{
    int val;
    struct Node* next;
};

int listSearch(struct Node **L, int k)
{
    if(!*L)
    {
        printf("LIST CANNOT BE EMPTY\n");
        return -1;
    }

    int currentVal = (*L)->val;
    
    while(*L && currentVal != k)
    {
        currentVal = (*L)->val;
        (*L) = (*L)->next;
    }
    
    if(!currentVal)
    {
        printf("No values found (encountered NULL), returning.\n");
        return -1;
    }

    if(currentVal == k)
    {
        printf("Value found!\n");
        return currentVal;
    }
    else
    {
        printf("Value not found\n");
        return -1;
    }
}

void listInsert(struct Node **L, int x)
{
    struct Node *New = (struct Node*)malloc(sizeof(struct Node)); //Allocate in memory the new element to insert

    //Initialize new element values
    New->val = x;
    New->next = (*L);

    (*L) = New;
    /*
    next[x] <- head[L]
    if head[L] != NIL
       then prev[head[L]] <- x
    head[L] <- x
    prev[x] <- NIL
    */
}

void listDelete(struct Node **L, int x)
{
    if(!*L)
    {
        printf("LIST IS EMPTY, UNABLE TO DELETE\n");
        return;
    }

    struct Node* currentPTR = *L;
    struct Node* Temp;

    //Check first if the node to delete is the node at the start
    if(currentPTR->val == x)
    {
        Temp = currentPTR->next;

        *currentPTR = *Temp;
        return;
    }

    while(currentPTR->next)
    {
        if (currentPTR->next->val == x)
        {
            Temp = currentPTR->next;
            currentPTR->next = Temp->next;
            break;
        }
        currentPTR = currentPTR->next;
    }
}

void debugList(struct Node **L)
{
    struct Node* debugNode = *L;

    if(debugNode)
    {
        while (1 == 1)
        {
            printf("DEBUGGING LINKED LIST: %d\n", debugNode->val);
            if(debugNode->next)
                debugNode = debugNode->next;
            else
                break;
        }
    }
    else
    {
        printf("UNABLE TO DEBUG LIST: LIST IS EMPTY\n");
        return;
    }
    
}

int main(int argc, char** argv)
{
    struct Node *L;

    listInsert(&L, 5);
    listInsert(&L, 8);
    listInsert(&L, 7);
    listInsert(&L, 15);
    listInsert(&L, 9);

    int searchQuery = 9;
    int queryResult = listSearch(&L, searchQuery);

    debugList(&L);
    printf("#####################\n");
    listDelete(&L, 15);

    debugList(&L);
    printf("#####################\n");

    listDelete(&L, 9);

    debugList(&L);
    printf("#####################\n");

    listDelete(&L, 8);

    debugList(&L);
    printf("#####################\n");
    
    return 0;
}