#include <stdio.h>
#include "./../include/queue.h"

int main() {

    struct Queue* queue = BuildQueue();
    for (int i = 0; i < 10; ++i) {
        Enqueue(i,queue);
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n",queue -> buffer[i]);
    }
    for (int i = 0; i < 10; ++i) {
        Dequeue(queue);
    }
    free(queue -> buffer);
    free(queue);
    return 0;
}
