#include <stdio.h>

#define MAX_QUEUE_SIZE 5

struct Queue
{
    /* data */
    int tail, head, length;
    int memory[MAX_QUEUE_SIZE];
};

int isQueueEmpty(struct Queue *Q)
{
    if(Q->length <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isQueueFull(struct Queue *Q)
{
    if(Q->length == MAX_QUEUE_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void enqueue(struct Queue *Q, int x)
{
    //Make sure queue is not full
    if(isQueueFull(Q) == 1)
    {
        printf("Unable to add new element, Queue is full\n");
    }
    else
    {
        if(Q->tail == MAX_QUEUE_SIZE - 1)
        {
            Q->tail = 0;
        }
        else
        {
        Q->tail = Q->tail +1;
        }
        
        Q->memory[Q->tail] = x;

        Q->length = Q->length + 1;

        printf("Successfully added %d to Queue | Tail currently at: %d\n", x, Q->tail);
    }
}

int dequeue(struct Queue *Q)
{
    if (isQueueEmpty(Q) == 1)
    {
        printf("Queue is empty, unable to dequeue elements\n");    
    }
    else
    {
        int x = Q->memory[Q->head];

        Q->memory[Q->head] = -1;
        if(Q->head == MAX_QUEUE_SIZE - 1)
        {
            Q->head = 0;
        }
        else
        {
            Q->head = Q->head +1;
        }

        Q->length = Q->length - 1;

        return x;
    }
}

int main(int argc, char** argv)
{
    struct Queue Q;
    Q.tail = -1;
    Q.head = 0;
    Q.length = 0;
    
    enqueue(&Q, 7);
    enqueue(&Q, 8);
    enqueue(&Q, 9);
    enqueue(&Q, 10);
    enqueue(&Q, 11);
    printf("Element at head: %d\n", Q.memory[Q.head]);
    printf("Element at tail: %d\n", Q.memory[Q.tail]);
    
    printf("Removing %d from Queue\n", dequeue(&Q));
    printf("Element at head: %d\n", Q.memory[Q.head]);
    printf("Element at tail: %d\n", Q.memory[Q.tail]);
    
    printf("Removing %d from Queue\n", dequeue(&Q));
    printf("Element at head: %d\n", Q.memory[Q.head]);
    printf("Element at tail: %d\n", Q.memory[Q.tail]);

    printf("\n");
    return 0;
}