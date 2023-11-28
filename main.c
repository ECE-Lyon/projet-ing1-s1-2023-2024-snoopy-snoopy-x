#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(void) {
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    for(int i = 0; i < 1000000; i++){
        int a = i;
        a = i*i;
    }
    gettimeofday(&stop, NULL);
    printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
    while(1){}
    return 0;
}
