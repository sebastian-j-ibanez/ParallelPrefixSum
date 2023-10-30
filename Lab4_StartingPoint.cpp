#include <iostream>
#include <cmath>
using namespace std;

#include <omp.h>

const int Num_Elements = 10;

int main()
{
    int Original_Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int Prefix_Array[10];
    int sum = 0;
    int i = 0;

    // Sequential
    cout << "Sequential Prefix Array :- " << " ";
    i = 0;

    while (i < 10)
    {
        sum += Original_Array[i];
        Prefix_Array[i] = sum;
        cout << Prefix_Array[i++] << " ";
    }
    cout << endl;

    // Parallel
    cout << "Parallel Prefix Array :- " << " ";
    
    //  parallel for block
    //      for (elements of array)
    //      sum block
    //      add sum to array
    //          

    return 1;
}