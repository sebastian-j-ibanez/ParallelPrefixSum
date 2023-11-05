#include <iostream>
#include <cmath>
#include <omp.h>

using namespace std;

const int Num_Elements = 10;

int main()
{
    int Original_Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int Seq_Sum[10];
    int sum = 0;
    int i = 0;

    // Sequential Solution
    std::cout << "Sequential Prefix Array :- " << " ";

    while (i < 10) {
        sum += Original_Array[i];
        Seq_Sum[i] = sum;
        cout << Seq_Sum[i++] << " ";
    }
   std::cout << endl;

    // Parallel Solution
   int Par_Sum[Num_Elements] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int limit = std::log2(Num_Elements) + 1;

    for (int depth = 1; depth <= limit; depth++) {

        // Wait for each thread from last depth to finish
#pragma omp barrier
        int step = std::pow(2, depth - 1);
        int Temp_Sum[Num_Elements] = { 0 };
        
        // Calculate sums for current depth, stored in Temp_Sum
#pragma omp parallel for shared(Par_Sum, Temp_Sum)
        for (int k = step; k < Num_Elements; k++) {
            Temp_Sum[k] = Par_Sum[k - step] + Par_Sum[k];
        }

        // Update each element in Par_Sum with Temp_Sum values
#pragma omp parallel for shared (Par_Sum, Temp_Sum)
        for (int k = step; k < Num_Elements; k++) {
            Par_Sum[k] = Temp_Sum[k];
        }
    }

    // Print Par_Sum array
    std::cout << "Parallel   Prefix Array :-  ";
    for (int i = 0; i < Num_Elements; i++) 
    {
        cout << Par_Sum[i] << " ";
    }

    return 1;
}