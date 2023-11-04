#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

const int Num_Elements = 10;
const int MAX_THREADS = 2;

int main()
{
    int Original_Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int Seq_Sum[10];
    int sum = 0;
    int i = 0;

    // Sequential
    std::cout << "Sequential Prefix Array :- " << " ";

    while (i < 10)
    {
        sum += Original_Array[i];
        Seq_Sum[i] = sum;
        cout << Seq_Sum[i++] << " ";
    }
   std::cout << endl;

    // Parallel
    
    //  parallel for 
    //      for (i = 0; i < log(elements of array - 1); i++)
    //          for (k = 0; k < elements of array 
    //      add sum to array

    std::cout << "Parallel Prefix Array :- ";
    
    int Par_Sum[10];
    sum = 0;
    i = 0;
    int chunk_size = Num_Elements / MAX_THREADS;

#pragma omp parallel for num_threads(MAX_THREADS) schedule(static, chunk_size)
    for (i = 0; i < Num_Elements; i++)
    {
        cout << omp_get_thread_num() << " ";
        sum += Original_Array[i];
        Par_Sum[i] = sum;
        cout << Par_Sum[i] << "\n";
    }

    return 1;
}