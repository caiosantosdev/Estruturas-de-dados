#include<iostream>

#define T 8

void intercala(int vetor [], int inicio, int fim, int meio);
void mergesort(int vetor [ ], int inicio, int fim);
void quicksort (int vetor[ ], int inicio, int fim);
void troca(int *, int *);

using namespace std;

int main(){
    int vetor[T], x , y;
    for(int i = 0; i < T ; i++)
    {
        cout << "Insira o valor de: " << i+1 << " !" << endl;
        cin >> vetor[i];
    }
    mergesort(vetor, 0 , T-1);

    for(int i = 0 ; i < T ; i++)
    {
        cout << vetor[i] << "   ";
    }
}

void mergesort(int vetor [ ], int inicio, int fim)
{
    int meio;
    if(inicio < fim)
    {
        meio = (inicio + fim)/2;
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);
        intercala(vetor, inicio, fim, meio);
    }
}

void intercala(int vetor[], int inicio, int fim, int meio){
    int i, aux[8], posLivre = inicio, inicioA1 = inicio, inicioA2 = meio + 1;
    while(inicioA1 <= meio && inicioA2 <= fim)
    {
        if(vetor[inicioA1] > vetor[inicioA2]) 
        {
            aux[posLivre] = vetor[inicioA2];
            inicioA2++;
        } 
        else
        {
            aux[posLivre] = vetor[inicioA1];
            inicioA1++;
        }
        posLivre++;
    }
    for(i=inicioA1;i<=meio;i++)
    {
        aux[posLivre] = vetor[i];
        posLivre++;
    }
    for(i=inicioA2; i<=fim ;i++)
    {
        aux[posLivre]=vetor[i];
        posLivre++;
    }
    for(i=inicio;i<=fim;i++)
    vetor[i]=aux[i];
}
void quicksort (int vetor[ ], int inicio, int fim)  
{
    int i, j, chave;
    if (fim-inicio < 2) 
    {
        if ((fim-inicio) == 1) 
        {
            if(vetor[inicio] > vetor[fim])
            {
                troca (&vetor[inicio], &vetor[fim]);
            }
        }
    }
    else
    {
        i= inicio;j= fim;chave = vetor[inicio];
        while(j > i) 
        {
            i++;
            while(vetor[i] < chave) 
            {
                i++;
            }
            while(vetor[j] > chave) 
            {
                j --;
            }
            if(j > i) 
            { 
                troca (&vetor[i], &vetor[j]);
            }
        } 
        troca(&vetor[inicio], &vetor[j]);
        quicksort(vetor, inicio, j -1);
        quicksort(vetor, j + 1, fim);
    }
} 
void troca(int *x, int *y)
{
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}