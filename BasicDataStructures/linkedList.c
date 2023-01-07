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

struct linkedList
{
    int val;
    struct linkedList* next;
};

int listSearch(struct linkedList **L, int k)
{
    /*
    x <- head[L]
    while x != NIL and key[x] != k
       do x <- next[x]
    return x
    */
}

void listInsert(struct linkedList **L, int x)
{
    struct linkedList *New = (struct linkedList*)malloc(sizeof(struct linkedList)); //Allocate in memory the new element to insert

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

void listDelete(struct linkedList **L, int x)
{
    /*
    if prev[x] != NIL
       then next[prev[x]] <- next[x]
       else head[L] <- next[x]
    if next[x] != NIL
       then prev[next[x]] <- prev[x]
    */

}

int main(int argc, char** argv)
{
    struct linkedList *L;
    L->next = NULL;

    listInsert(&L, 5);
    listInsert(&L, 8);
    listInsert(&L, 7);
    listInsert(&L, 15);
    listInsert(&L, 9);

    if(L)
    {
        while(1==1)
        {
            printf("DEBUGGING LINKED LIST: %d\n", L->val);
            if(L->next)
                L = L->next;
            else
                break;
        }
    }
    else
    {
        printf("LIST IS NULL, PLEASE ADD VALUES BEFORE CONTINUING\n");
    }
    
    return 0;
}