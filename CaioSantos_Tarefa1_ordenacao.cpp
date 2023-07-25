#include<iostream>


//Aluno: Caio Santos de Souza


using namespace std;

void selection(int fila[6], int qtd);
void bubble(int fila[6], int qtd);
void insertion(int fila[6], int qtd);

int main()
{
   int fila[6] = {90, 76 , 15, 23 , 56, 38};
   int qtd = 6;
   //selection(fila, qtd);
   int opcao;
   insertion(fila, qtd);
   cout << "Qual algoritmo de ordenacao deseja usar?" << endl;
   cout << "1 - selectionSort" << endl;
   cout << "2 - bubbleSort" << endl;
   cout << "3 - insertionSort" << endl;
   cin >> opcao;
   if(opcao == 1)
   selection(fila, qtd);
   else if(opcao == 2)
   bubble(fila, qtd);
   else if(opcao == 3)
   insertion(fila , qtd);
   for(int i = 0 ; i < qtd ; i++)
   {
       cout << fila[i] << endl;
   }
}


void selection(int fila[6], int qtd)
{
    int aux;
    int menor;
    for(int i = 0; i < qtd - 1 ; i++)
    {
        menor = i;
        for(int j = i+1; j < qtd ; j++)
        {
            if(fila[menor]>fila[j])
                menor = j;
        }
        aux = fila[i];
        fila[i] = fila[menor];
        fila[menor] = aux;
    }

}


void bubble(int fila[6], int qtd)
{
    int aux;

    for(int i = 0 ; i < qtd-1 ; i++)
    {
        for(int j = i+1 ; j < qtd ; j++)
        {
            if(fila[i]>fila[j])
            {
            aux = fila[j];
            fila[j] = fila[i];
            fila[i] = aux;
            }
        }
    }
}


void insertion(int fila[6], int qtd)
{
    for(int i = 1 ; i < qtd ; i++)
    {
        int chave = fila[i];
        int j = i - 1;

        while(j >=0 &&  fila[j] > chave)
        {
            fila[j+1] = fila[j];
            j--;
        }
        fila[j+1] = chave;
    }
}