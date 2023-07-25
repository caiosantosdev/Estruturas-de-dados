#include<iostream>

using namespace std;

struct no{
    int info;
    struct no *prox;
};
typedef struct no* noPtr;

void inserir(noPtr *final,noPtr *inicio);
void retirar(noPtr *final, noPtr *inicio);
void remover ( noPtr *final , noPtr *inicio);
void listPrint(noPtr *final, noPtr *inicio);


int main()
{
    noPtr final = NULL;
    noPtr inicio = NULL;
    int opcao;
    do
    {
        cout << "1 - inserir no" << endl;
        cout << "2 - remover no" << endl;
        cout << "3 - imprimir lista" << endl;
        cin >> opcao;
        if(opcao == 1)
        {
            inserir(&final, &inicio);
        }
        else if(opcao == 2)
        {
            remover(&final ,&inicio);
        }
        else if(opcao == 3)
        {
            listPrint(&final, &inicio);
        }

    }while(opcao != 0);
}

void inserir(noPtr *final,noPtr * inicio)
{
    int info;
    cout << "Digite a informacao contida no seu no" << endl;
    cin >> info;
    noPtr p = new no;
    p->info = info;
    if(*final == NULL)
    {
        *inicio = p;
        *final = p;
        (*final)->prox = (*inicio);
    }
    else
    {
        //p->prox = (*final)->prox;
        p->prox = (*inicio);
        (*final)->prox = p;
        *final = p; 
    }
}

void remover (noPtr *final , noPtr *inicio)
{
    int hunt;
    int found = 0;
    cout << "Qual elemento deseja retirar?" << endl;
    cin >> hunt;
    noPtr aux = *inicio;
    if(aux == NULL)
        cout << "Lista vazia" << endl;
    else
    {
        if(aux->info == hunt)
        {
            (*final)->prox = (*inicio)->prox;
            *inicio = (*inicio)->prox;
            delete aux;
            aux = NULL;
            cout << "No retirado." << endl;
        }
        else
        {
            noPtr aux2 = aux->prox;
            while(aux2 != *inicio && found == 0)
            {
                if(aux2->info == hunt)
                {
                    if(aux2 == *final)
                    {
                        *final = aux;
                        aux->prox = aux2->prox;
                        delete aux2;
                        found = 1;
                        cout << "No retirado" << endl;
                    }
                    else
                    {
                        aux->prox = aux2->prox;
                        delete aux2;
                        cout << "No retirado" << endl;
                        found = 1;
                    }
                }
                else
                {
                    aux2 = aux2->prox;
                    aux = aux->prox;
                }
            }
            if(aux2 == *inicio)
            cout << "Elemento nao encontrado" << endl;
        }
    }
}

void incluirMusica(noPtr *final, noPtr *inicio)
{
    int codigo;
    cin >> codigo;
    noPtr p = new no;
    p->info = codigo;
    if(*inicio == NULL)
    {
        *inicio = p;
        *final = p;
        (*final)->prox = (*inicio);
    }
    else
    {
        (*final)->prox = p;
        p->prox = *inicio;
        *final = p;
    }
}





void listPrint(noPtr *final, noPtr *inicio)
{
    noPtr aux = *inicio;
    cout << "\n\n\n\n\n LISTA :" << endl;
    if(aux == NULL)
    {
        cout << "Lista vazia." << endl;
    }
    else
    {
        do
        {
            cout << aux->info << endl;
            aux = aux->prox;
        }
        while(aux != *inicio);
    }
}