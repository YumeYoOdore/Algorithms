#include <stdio.h>

#define MAX_MEMORY_SIZE 5000

struct Stack
{
    /* data */
    int top;
    int memory[MAX_MEMORY_SIZE];
};

int stackEmpty(struct Stack *S)
{
    /*
    if top[S] = 0
        then return TRUE
        else return FALSE
    */
   if(S->top < 0)
   {
        return 1;
   }
   else
   {
        return 0;
   }
}

void push(struct Stack *S, int x)
{
    if(S->top == MAX_MEMORY_SIZE)
    {
        printf("Unable to push element, max stack size reached\n");
    }
    else
    {

        S->top = S->top + 1;
        S->memory[S->top] = x;
    }
}

void pop(struct Stack *S)
{
    if(stackEmpty(S) == 1)
    {
        printf("Stack is already empty, cannot pop elements\n");
    }
    else
    {
        S->top = S->top -1;
    }
}

int main(int argc, char** argv)
{
    struct Stack S;

    S.top = -1;

    push(&S, 9);
    push(&S, 17);
    push(&S, 5);
    push(&S, 4);
    push(&S, 20);

    printf("TOP OF Stack: %d\n", S.memory[S.top]);
    pop(&S);
    printf("TOP OF Stack: %d\n", S.memory[S.top]);
    pop(&S);
    printf("TOP OF Stack: %d\n", S.memory[S.top]);
    pop(&S);
    printf("TOP OF Stack: %d\n", S.memory[S.top]);
    pop(&S);
    printf("TOP OF Stack: %d\n", S.memory[S.top]);
    
    return 0;
}