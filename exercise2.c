#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int Array[100]; // Use rand() % 10000 for init
    int max = 0;
    int min = 100000; 
    int avg;

    #pragma omp parallel num_threads(100)
    {
        Array[omp_get_thread_num()]= rand() % 10000;
    }

    #pragma omp parallel reduction(max:max) reduction(min:min) shared(avg) num_threads(100)
    {
        max = Array[omp_get_thread_num()];
        min = Array[omp_get_thread_num()];
        #pragma omp atomic
        avg += Array[omp_get_thread_num()];
    }
    avg/=100;
    printf("Max is = %d\n",max);
    printf("Min is = %d\n",min);
    printf("Avg is = %d\n",avg);
    

    

    return 0;
}