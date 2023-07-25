#include<iostream>

#define T 8

void buscabinaria(int vetor[] , int N , int inicio, int fim);
void buscasequencial(int vetor[T]);
void mergesort(int vetor [ ], int inicio, int fim);
void quicksort (int vetor[ ], int inicio, int fim);
void intercala(int vetor [], int inicio, int fim, int meio);
void troca (int *, int *);

using namespace std;

int main(){
    int vetor[T] = {6, 2, 4, 2, 8, 0, 1, 5};
    //ordenacao do vetor 
    quicksort(vetor, 0, T-1);
    //Loop que mostra o vetor
    for(int i = 0;  i < T ; i++)
    {
     cout << vetor[i] << "   ";   
    }
    cout << endl;
    // busca de um numero no vetor
    cout << "Qual numero deseja buscar? " << endl;
    int N;
    cin >> N;
    // algoritmo de busca que deseja usar
    buscabinaria(vetor, N, 0, T);
}



void buscabinaria(int vetor[] , int N , int inicio, int fim)
{
  int meio = (inicio + fim) / 2;
  if(N == vetor[meio])
    cout << "Esta na posicao " << meio << endl;
  else
  {
    if(N < vetor[meio])
    {
      buscabinaria(vetor, N, inicio, meio);
    }
    else
      buscabinaria(vetor, N, meio+1, fim);
  }
}



void buscasequencial(int vetor[T])
{
  int N;
  int achados = 0;
  cout << "Qual numero deseja buscar? " << endl;
  cin >> N;
  for(int i = 0 ; i < T ; i++)
  {
    if(vetor[i] == N)
    {
      cout << "Achamos o numero " << N << " no endereco " << i << endl;
      achados++;
    }
  }
      
  if(achados!=0)
    cout << "Achamos " << achados << " numeros na busca" << endl;
  else
  {
    cout << "Nao foi achado nesse vetor." << endl;
  }
  
}



void mergesort(int vetor [ ], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergesort(vetor, inicio, meio);
        mergesort(vetor, meio + 1, fim);
        intercala(vetor, inicio, fim, meio);
    }
}



void intercala(int vetor[], int inicio, int fim, int meio)
{
    int i; 
    int aux[8]; 
    int posLivre = inicio;
    int inicioA1 = inicio; 
    int inicioA2 = meio + 1;
    while(inicioA1 <= meio && inicioA2 <= fim)
    {
        if(vetor[inicioA1] > vetor[inicioA2])
        {
            aux[posLivre] = vetor[inicioA2];inicioA2++;
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
        aux[posLivre] = vetor[i];posLivre++;
    }
    for(i=inicioA2; i<=fim ;i++)
    {
        aux[posLivre]=vetor[i];posLivre++;
    }
    for(i=inicio;i<=fim;i++)
    vetor[i]=aux[i];
}



void quicksort (int vetor[ ], int inicio, int fim)
{
    int i, j, chave;
    if ((fim - inicio) < 2) 
    {
        if (fim - inicio == 1) 
        {
            if(vetor[inicio] > vetor[fim])
            {
                troca (&vetor[inicio], &vetor[fim]);
            }
        }
    }
    else
    {
        i= inicio;
        j= fim;
        chave = vetor[inicio];
        while(j > i) 
        {
            i++;
            while(vetor[i] < chave) 
            {
                i++;
            }
            while(vetor[j] > chave) 
            {
                j--;
            }
            if(j > i)
            { 
                troca (&vetor[i], &vetor[j]);
            }
        } 
        troca (&vetor[inicio], &vetor[j]);
        quicksort(vetor, inicio, j -1);
        quicksort(vetor, j + 1, fim);
    }
} 



void troca (int *a , int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}