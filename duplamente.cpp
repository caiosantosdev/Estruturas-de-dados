#include<iostream>

using namespace std;

struct no{
    int info;
    struct no * ant;
    struct no * prox;
};

typedef struct no* noPtr;


void inserir_no_inicio(noPtr *root);
void remover(noPtr *root);
void imprimir(noPtr root);

int main()
{
    noPtr topo = NULL;
    int opcao;
    do
    {
        cout << "\n\n\n\n\n\n O que deseja escolher?" << endl;
        cout << "1 - inserir na lista" << endl;
        cout << "2 - remover da lista" << endl;
        cout << "3 - imprimir a lista" << endl;
        cout << "0 - sair da lista" << endl;
        cin >> opcao;
        if(opcao == 1)
        {
            inserir_no_inicio(&topo);
        }
        else if(opcao == 2) 
        {
            remover(&topo);
        }
        else if(opcao == 3)
        {
            imprimir(topo);
        }
        else if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 0)
        {
            cout << "opcao invalida, digite novamente." << endl;
        }
    }while(opcao != 0);
}



void inserir_no_inicio(noPtr *root)
{
    noPtr p = new no;
    cout << "Qual a informacao que deseja introduzir no novo noh?" << endl;
    cin >> p->info;
    if((*root) == NULL)
    {
        p->prox = NULL;
        *root = p;
    }
    else
    {
        (*root)->ant = p;
        p->prox = *root;
        *root = p;
    }
}

void inserirNoFinal(noPtr *root)
{
    noPtr p = new no;
    cout << "Qual no deseja adicionar ?" << endl;
    cin >> p->info;
    if(*root == NULL)
    {
        *root = p;
        p->prox = NULL;
        p->ant = NULL;
    }
    else
    {
        noPtr aux = *root;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        p->ant = aux;
        aux->prox = p;
        p->prox = NULL;
    }
}


void remover(noPtr *root)
{
    int numero;
    cout << "Qual numero gostaria de remover?" << endl;
    cin >> numero;
    noPtr aux = (*root);
    if(aux == NULL)
    {
        cout << "lista vazia" << endl;
    }
    else
    {

        if(aux->info == numero)
        {
            if(aux->prox == NULL)
            {
                (*root) = NULL;
                delete(aux);
                aux = NULL;
            }
            else
            {
            *root = aux->prox;
            (*root)->ant = NULL;
            delete (aux);
            }
        }
        else
        {
            noPtr aux2 = aux->prox;
            bool ok = true;
            int achei = 0;
            while(ok)
            {
                if(aux2->info == numero)
                {
                    ok = false;
                    achei = 1;
                }
                if(aux2 == NULL && achei == 0)
                {
                    cout << "Elemento nao encontrado" << endl;
                    ok = false;
                }
                if(aux2 != NULL && achei == 0 && ok == true)
                {
                aux = aux->prox;
                aux2 = aux2->prox;
                }
            }
            //if de aux2 = numero e realizacao da remocao.
            if(aux2->info == numero) 
            {
                if(aux2->prox != NULL)
                {
                    aux->prox = aux2->prox;
                    aux = aux2->prox;
                    aux->ant = aux2->ant;
                    delete (aux2);
                }
                else
                {
                    aux->prox = NULL;
                    delete(aux2);
                    aux2 = NULL;
                }
            }
        }
    }
}


void imprimir(noPtr root)
{
    if(root == NULL)
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        cout << "\n\n\n\n\n LISTA:" << endl;
        while(root!=NULL)
        {
            cout << root->info << endl;
            root = root->prox;
        }
    }
}