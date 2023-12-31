#include <stdio.h>
#include <malloc.h>

typedef struct queue{
int data; struct queue* next}queue_t;

queue_t * head = NULL;

void print_list(queue_t * head) {
    queue_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

void push(queue_t * head, int val) {
    queue_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (queue_t *) malloc(sizeof(queue_t));
    current->next->data = val;
    current->next->next = NULL;
}

int pop(queue_t ** head) {
    int retval = -1;
    queue_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->data;
    free(*head);
    *head = next_node;

    return retval;
}

int main(){
}





/*    Queue* queue=create_queue(3);
    assert(is_empty(queue));

    append(queue,1);//queue->append(1);
    append(queue,2);
    append(queue,3);
    assert(is_full(queue));

    int x=pop(queue);
    assert(x==1);
    assert(pop(queue)==2);//queue->pop()==2
    assert(pop(queue)==3);

    assert(is_empty(queue));
    return 0;
}*/