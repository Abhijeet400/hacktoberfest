#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

bool isEmpty(struct Queue *);
bool isFull(struct Queue *);
void enqueue(struct Queue *);
void dequeue(struct Queue *);
void front(struct Queue *);
void rear(struct Queue *);

int main() {
    struct Queue *queue=(struct Queue *)malloc(sizeof(struct Queue));
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &queue->size);
    queue->arr=(int *)malloc(queue->size*sizeof(int));
    queue->front=queue->rear=-1;
    int ch;
    while(1){
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Front Value\n");
        printf("4.Last value\n");
        printf("5.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(queue);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            front(queue);
            break;
        case 4:
            rear(queue);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}

bool isEmpty(struct Queue *ptr) {
    return ptr->front==-1;
}

bool isFull(struct Queue *ptr) {
    return ((ptr->rear+1)%ptr->size == ptr->front) || (ptr->rear == ptr->size-1 && ptr->front==-1);
}

void enqueue(struct Queue *ptr) {
    if(isFull(ptr)) {
        printf("OVERFLOW\n");
    }
    else {
        if(ptr->front==-1) 
            ptr->front=0;
        printf("Enter the value to be inserted: ");
        ptr->rear=(ptr->rear+1)%ptr->size;
        scanf("%d", &ptr->arr[ptr->rear]);
    }
}

void dequeue(struct Queue *ptr) {
    if(isEmpty(ptr)) {
        printf("UNDERFLOW\n");
    }
    else{
        if(ptr->front==ptr->rear) {
            ptr->front=ptr->rear=-1;
        }
        else {
            ptr->front=(ptr->front+1)%ptr->size;
        }
    }
}

void front(struct Queue *ptr) {
    if(!isEmpty(ptr))
        printf("The frontmost value is: %d\n", ptr->arr[ptr->front]);
    else
        printf("404 NOT FOUND\n");
}

void rear(struct Queue *ptr){
    if(!isEmpty(ptr))
        printf("The rearmost value is: %d\n", ptr->arr[ptr->rear]);
    else
        printf("404 NOT FOUND\n");
}
