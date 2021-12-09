// PRACTICAL 12 : Write a program to calculate sum of n numbers using thread library.
#include <iostream>
#include <pthread.h>
  
// size of array
#define MAX 16
  
// maximum number of threads
#define MAX_THREAD 4
  
using namespace std;
  
int a[] = { 4, 7, 3, 15, 11, 34, 67, 10, 20, 34, 69, 90,56, 78, 91, 730 };
int sum[4] = { 0 };
int part = 0;
  
void* sum_array(void* arg)
{
  
    // Each thread computes sum of 1/4th of array
    int thread_part = part++;
  
    for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++)
        sum[thread_part] += a[i];
}
  
// Driver Code
int main()
{
  
    pthread_t threads[MAX_THREAD];
  
    // Creating 4 threads
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
  
    // joining 4 threads i.e. waiting for all 4 threads to complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);
  
    // adding sum of all 4 parts
    int total_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
        total_sum += sum[i];
  
    cout << "THE TOTAL SUM IS: " << total_sum << endl;
  
    return 0;
}
