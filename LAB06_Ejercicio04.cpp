#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <chrono>

void insertion_sort(int * arr, int size)
{
    int key {};
    for(int j = 1; j < size; j++)
    {
        key = arr[j];
        int i {j - 1};
        while(i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}


int partition(int * A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            std::swap(A[i],A[j]);
        }

    }
    std::swap(A[i + 1],A[r]);
    return i + 1;
}
void quicksort(int * A, int p, int r, int m)
{   
    if (r - p + 1 <= m && p < r) insertion_sort(A,r - p + 1);
    else if (p < r)
    {
        int q = partition(A,p,r);
        quicksort(A,p,q-1,m);
        quicksort(A,q+1,r,m);
    }

}

int main()
{
    std::ofstream file;

    file.open("comparaciones.txt");
    file << "M/N 1000 10000 1000000\n";
    srand(time(0));
    for (int M = 0; M <= 30; M++)
    {
        int * A = new int[1000];
        for (int i = 0; i < 1000; i++)
        {
            A[i] = rand() % 1000;
        }
        auto start1 = std::chrono::steady_clock::now();
        quicksort(A,0,999,M);
        auto end1 = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
        file << M << ' ' << elapsed_seconds1.count() * 1000 << ' ';
        delete [] A;

        int * B = new int[10000];
        
        for (int i = 0; i < 10000; i++)
        {
            B[i] = rand() % 10000;
        }

        auto start2 = std::chrono::steady_clock::now();
        quicksort(B,0,9999,M);
        auto end2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
        file << elapsed_seconds2.count() * 1000 << ' ';
        delete [] B;


        int * C = new int[1000000];
        for (int i = 0; i < 1000000; i++)
        {
            C[i] = rand() % 1000000;
        }
        auto start3 = std::chrono::steady_clock::now();
        quicksort(C,0,999999,M);
        auto end3 = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds3 = end3 - start3;
        file << elapsed_seconds3.count() * 1000 << '\n';
        delete [] C;
    }
    
    

    return 0;
}   