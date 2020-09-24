#include <stdio.h>
#include "../libs/queue/include/queue.h"
int main() {

    struct Queue* queue = BuildQueue();
    for (int i = 0; i < 10; ++i) {
        Enqueue(i,queue);
    }
    free(queue -> buffer);
    free(queue);
    return 0;
}
