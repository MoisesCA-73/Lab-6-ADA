#include <iostream>
#include <algorithm>

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
void quicksort(int * A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }

}

int main()
{
    int * A = new int [10];

    A[0]=9;
    A[1]=4;
    A[2]=2;
    A[3]=3;
    A[4]=1;
    A[5]=8;
    A[6]=19;
    A[7]=7;
    A[8]=4;
    A[9]=12;

    quicksort(A,0,9);
    
    for (int i = 0; i < 10; i++)
    {

        std::cout << A[i] << ' ';
    }

    return 0;
}