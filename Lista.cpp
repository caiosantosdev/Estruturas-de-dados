#include<iostream>

using namespace std;


struct lista{
    int num;
    struct lista *prox;
}; 

typedef struct lista NO;

NO* inserir_no_inicio(NO* topo, int dado);
NO* inserir_no_fim(NO* topo, int dado);
void imprimirLista(NO* topo);

int main()
{
    NO *topo = NULL;
    topo = inserir_no_inicio(topo, 10);
    topo = inserir_no_inicio(topo, 20);
    topo = inserir_no_fim(topo, 5);
    imprimirLista(topo);
    return 0;
}


NO* criarno()
{
    NO *novo = (NO*)malloc(sizeof(lista*));
    return novo;
}

NO* inserir_no_inicio(NO* topo, int dado)
{
    NO* novo_no = criarno();
    novo_no->num= dado;
    //CASO de primeiro elemento da Lista
    if(topo == NULL)
    {
        topo = novo_no;
        novo_no->prox = NULL;
    }
    //Caso já tenham elementos na lista
    else
    {
        novo_no->prox = topo;
        topo = novo_no;
    }
    return topo;
}


NO* inserir_no_fim(NO* topo, int dado)
{
    NO* no = criarno();
    no->num = dado;
    if(topo == NULL)
    {
        topo = no;
        no->prox = NULL;
    }
    else
    {
    NO* aux = topo;
    //Loop para saber qual eh o ultimo elemento da lista
    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = no;
    no->prox = NULL;
    }
    return topo;
}


void imprimirLista(NO* topo)
{
    NO* aux = topo;
    while(aux != NULL)
    {
        cout << aux->num << endl;
        aux = aux->prox;
    }
}