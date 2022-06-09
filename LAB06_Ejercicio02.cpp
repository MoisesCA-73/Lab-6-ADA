#include <iostream>
#include <algorithm>

bool is_sorted(int * A, int n, bool ord = true)
{
    for (int i = 1; i < n; ++i)
    {
        if (A[i] < A[i - 1] == ord)
            return false;
    }
    return true;
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
void quicksort(int * A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

void quicksort_opt(int * A, int p, int r)
{
    if (is_sorted(A,r+1)) return;
    if (is_sorted(A,r+1,false))
    {
        int tmp;
        for (int i = 1; i < r/2 + 1; ++i)
        {
            tmp = A[i];
            A[i] = A[r - i];
            A[r - i] = tmp;
        }
        return;
    }
    quicksort(A,p,r);
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

    quicksort_opt(A,0,9);
    
    for (int i = 0; i < 10; i++)
    {

        std::cout << A[i] << ' ';
    }

    return 0;
}