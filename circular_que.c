#include <stdio.h>

int max , front = -1 , rear = -1;
void enqueue (int item , int queue[]){
    if((rear+1)%max == front){
        printf("The Queue is full");
    } else if (rear== -1) {
        front = rear = 0;
        queue[rear] = item; 
    } else {
        rear = (rear + 1)%max;
        queue[rear] = item;
    }
}

void dequeue (int queue[]) {
    if(front == -1) {
        printf("Queue is empty");
    } else if (front == rear) {
        printf("Dequeued item is %d", queue[front]);
        front = rear =-1;
    } else {
        printf("Dequeued item is %d",queue[front]);
        front = (front + 1)%max;
    }
}

void display(int queue[]) {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int item , choice;
    printf("Enter the size of the array : ");
    scanf("%d",&max);
    int queue[max];
    while(1){
        printf("1.Enqueue \n2.Dequeue \n3.Display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d",&item);
            enqueue(item,queue);
            break;
        case 2: 
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        default:
            printf("Not a valid input");
            break;
        }
    }
}
