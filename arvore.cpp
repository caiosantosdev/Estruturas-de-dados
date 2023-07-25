#include<iostream>

using namespace std;

struct no{
    int info;
    struct no *esq;
    struct no *dir;
};

typedef struct no* noPtr;

int menu();
int listarNos();
bool enderecoVazio(noPtr root);
void listarEmOrdem(noPtr root);
void listarPreOrdem(noPtr root);
void listarPosOrdem(noPtr root);
void inserir(noPtr *root, int value);
void remover(noPtr *root, int value);
noPtr buscar(noPtr root, int value);
noPtr maior(noPtr *root);
void grau2(noPtr *root, int level);

int main()
{
    int op1, op2, value;
    bool achei;
    noPtr raiz = NULL;

    do{
        op1 = menu();
        switch(op1)
        {
            case 1: cout << "Digite o elemento a inserir" << endl;
                    cin >> value;
                    inserir(&raiz, value);
                    break;
            case 2: cout << "Digite o elemento que deseja remover" << endl;
                    cin >> value;
                    remover(&raiz, value);
                    break;
            case 3: op2 = listarNos();
                    if(op2 == 1)
                    listarEmOrdem(raiz);
                    if(op2 == 2)
                    listarPreOrdem(raiz);
                    if(op2 == 3)
                    listarPosOrdem(raiz);
                    break;
            case 4: cout << "Digite o elemento que deseja buscar" << endl;
                    cin >> value;
                    achei = buscar(raiz,value);
                    if(!achei)
                        cout << "Elemento nao encontrado" << endl;
        }
    }while(op1!=0);
}


int menu()
{
    int opcao;
    cout << endl << endl << endl << "---MENU PRINCIPAL ---" << endl << endl
        << "1 - inserir no na arvore" << endl
        << "2 - remover no na arvore" << endl
        << "3 - listar todos os nos da arvore" << endl
        << "4 - buscar no na arvore" << endl
        << "0 - sair" << endl
        << "Digite uma opcao" << endl;
    cin >> opcao;
    return opcao;
}

int listarNos()
{
    int opcao;
    cout << endl << endl << "Tipos de listagem:" << endl
        << "1 - Em Ordem" << endl
        << "2 - Pre Ordem" << endl
        << "3 - POs Ordem" << endl
        << "Escolha o tipo de listagem" << endl;
        cin >> opcao;
        return opcao;
}

bool enderecoVazio(noPtr root)
{
    if(root)
    return false;
    else
    return true;
}

void listarEmOrdem(noPtr root)
{
    if(!enderecoVazio(root))
    {
        listarEmOrdem(root->esq);
        cout << "\t" << root->info;
        listarEmOrdem(root->dir);
    }
}

void listarPreOrdem(noPtr root)
{
    if(!enderecoVazio(root))
    {
        cout << "\t" << root->info;
        listarPreOrdem(root->esq);
        listarPreOrdem(root->dir);
    }
}

void listarPosOrdem(noPtr root)
{
    if(!enderecoVazio(root))
    {
        listarPosOrdem(root->esq);
        listarPosOrdem(root->dir);
        cout << "\t" << root->info;
    }
}

void inserir(noPtr *root, int value)
{
    if(enderecoVazio(*root))
    {
        *root = new no;
        (*root)->info = value;
        (*root)->esq = NULL;
        (*root)->dir = NULL;
    }
    else
    {
        if(value < ((*root)->info))
        inserir(&((*root)->esq), value);
        else
        inserir(&((*root)->dir), value);
    }
}

void remover(noPtr *root, int value)
{
    noPtr aux;
    if(!enderecoVazio(*root))
    {
        if(value == (*root)->info)
        {

            aux = *root;
            if(((*root)->esq) == NULL)
                *root = (*root)->dir;
            else 
            {
                if(((*root)->dir) == NULL)
                    *root = (*root)->esq;
                else
                {
                    aux = maior(&((*root)->esq));
                    (*root)->info = aux->info;
                }
                delete(aux);
                cout << "Elemento foi removido" << endl;
            }
        }
        else
            if(value < ((*root)->info))
                remover(&((*root)->esq), value);
            else   
                remover(&((*root)->dir), value);
    }
}

noPtr buscar(noPtr root, int value)
{
    if(root == NULL)
    return NULL;
    if(value == (root->info))
    return root;
    if( value < root->info)
        return buscar((root->esq), value);
    else
        return buscar((root->dir), value);
}

noPtr maior(noPtr *root)
{
    noPtr t;
    t = *root;
    if((t->dir) == NULL)
    {
        *root = (*root)->esq;
        return(t);
    }
    else
        return (maior(&((*root)->dir)));
}


void grau2(noPtr *root, int level = 0)
{
    if(*root != NULL)
    {
        if((*root)->esq != NULL && (*root)->dir != NULL)
        {
            cout << (*root)->info;
        }
        grau2(&(*root)->esq , level + 1);
        grau2(&(*root)->dir , level + 1);
    }
}
