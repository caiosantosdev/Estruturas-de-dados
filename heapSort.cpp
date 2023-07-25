#include<iostream>
#define T 10

using namespace std;

void heap(int A[], int t);
void heapSort(int A[], int n);
void descer(int A[], int i, int q);
void troca(int *a, int *b);



int main()
{
    int A[T] = { 50 , 2 , 75, 8, 10, 6, 15, 4, 9, 3 };
    int i;
    heapSort(A, T);
    for(int i = 0 ; i < T ; i++)
    {
        cout << A[i]  << "   ";
    }
}

void heap(int A[], int t)
{
    for(int i = (t/2) ; i >= 0 ; i--)
        descer(A, i, t-1);
}

void heapSort(int A[], int n)
{
    int i;
    heap(A, T);
    for(i = n-1; i >= 1; i--)
    {
        troca(&A[0], &A[i]);
        descer(A, 0, i-1);
    }
}

void descer(int A[], int i, int q)
{
    int d = 2* i + 2;
    int e = 2 * i + 1;
    int maior = i;

    if(d <= q && A[d] > A[i])
        maior = d;
    if(e <= q && A[e] > A[maior])
        maior = e;
    if(maior != i)
    {
        troca(&A[i], &A[maior]);
        descer(A , maior, q);        
    }
}

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

