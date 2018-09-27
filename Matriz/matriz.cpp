#include<QString>
#include "matriz.h"
#include <iostream>

namespace TP2{//inicio

Matriz::Matriz(int qLinhas, int qColunas)
{
    if(qLinhas<=0) throw QString("Quantidade de Linhas somente positiva");
    if(qColunas<=0) throw QString("Quantidade de Colunas somente positiva");
    try{
        ptMatriz = new int[qLinhas*qColunas];
    }catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
    quantidadeDeLinhas = qLinhas;
    quantidadeDeColunas = qColunas;
    for(int i=0; i<quantidadeDeLinhas;i++)
    {
        for(int c=0;c<quantidadeDeColunas;c++)
        {
            setElemento(0,i,c);
        }
    }
}

void Matriz::setElemento(int elemento, int linha, int coluna)
{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    *(ptMatriz+pos) = elemento;
}

int Matriz::getElemento(int linha, int coluna)
{
    if(linha<0 || linha>=quantidadeDeLinhas)
        throw QString("Linha fora do intervalo valido");
    if(coluna<0 || coluna>=quantidadeDeColunas)
        throw QString("Coluna fora do intervalo valido");
    int pos = linha*quantidadeDeColunas+coluna;
    return *(ptMatriz+pos);
}

void Matriz:: getMatriz()
{
    std::cout<<"\n";
    for(int linha = 0; linha < getQuantidadeDeLinhas(); linha++)
    {
        for(int coluna = 0; coluna < getQuantidadeDeColunas(); coluna++)
        {
            if(coluna==getQuantidadeDeColunas()-1)
            {
               std::cout<<getElemento(linha,coluna)<<"\n";
            }
            else
            {
                std::cout<<" "<<getElemento(linha,coluna)<< " ";
            }
        }
    }
    std::cout<<"\n";
}

Matriz* Matriz::operator + (Matriz* mat)
{
    if(quantidadeDeColunas!=mat->getQuantidadeDeColunas()&&quantidadeDeLinhas!=mat->quantidadeDeLinhas)
    {
        std::cout<<"\nImpossivel realizar a soma\n";
        return nullptr;
    }
    Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
    for(int linha=0; linha<quantidadeDeLinhas; linha++)
    {
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++)
        {
            int valor = this->getElemento(linha,coluna) + mat->getElemento(linha,coluna);
            aux->setElemento(valor,linha,coluna);
        }
    }
    return aux;


}

Matriz* Matriz::operator - (Matriz*  mat)
{
    if(quantidadeDeColunas!=mat->getQuantidadeDeColunas()&&quantidadeDeLinhas!=mat->quantidadeDeLinhas)
    {
        std::cout<<"\nImpossivel realizar a subtração\n";
        return nullptr;
    }
    Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
    for(int linha=0; linha<quantidadeDeLinhas; linha++)
    {
        for(int coluna=0; coluna<quantidadeDeColunas; coluna++)
        {
            int valor = this->getElemento(linha,coluna) -
            mat->getElemento(linha,coluna);
            aux->setElemento(valor,linha,coluna);
        }
    }
    return aux;

}

Matriz* Matriz::operator * (Matriz* x)
{
    //Da definição, temos que a matriz produto A . B
    //só existe se o número de colunas de A for igual ao número de linhas de B:

    int i,j,k,valor;
    Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
    for(i=0;i<quantidadeDeLinhas;i++)
    {
        for(j=0;j<quantidadeDeColunas;j++)
        {
            valor=0;
            for(k=0;k<quantidadeDeLinhas;k++)
            {
               valor=valor+(getElemento(i,k)*x->getElemento(k,j));
            }
            aux->setElemento(valor,i,j);
        }
    }

    return aux;
}

bool Matriz::trianginf()
{
    for(int i=0; i<getQuantidadeDeLinhas()-1;i++)
    {
        for(int k=1+i;k<getQuantidadeDeColunas();k++)
        {
            if(getElemento(i,k)!=0)
            {
                return false;
            }
            for(int cont=0;cont<getQuantidadeDeLinhas();cont++)
            {
                for(int conta=0;conta<cont+1;conta++)
                {
                    if(getElemento(cont,conta)==0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Matriz::triangsup()
{
    for(int i=1; i<getQuantidadeDeLinhas();i++)
    {
        for(int k=0; k<i;k++)
        {
            if(getElemento(i,k)!=0)
            {
                return false;
            }
            for(int conta=0;conta<getQuantidadeDeLinhas();conta++)
            {
                for(int conta1=conta;conta1<getQuantidadeDeColunas();conta1++)
                {
                    if(getElemento(conta,conta1)==0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Matriz::identidade()
{
    for(int i=0;i<getQuantidadeDeLinhas();)
    {
        for(int j=0;j<getQuantidadeDeColunas();j++,i++)
        {
            if(!triangsup()&&!trianginf()&&getElemento(i,j)==1)
            {
                return true;
            }      
        }
    }
    return false;
}

void Matriz::transposta(Matriz* x)
{
    for(int i=0;i<x->getQuantidadeDeColunas();i++)
    {
        for(int j=0;j<x->getQuantidadeDeLinhas();j++)
        {
            setElemento(x->getElemento(j,i),i,j);
        }
    }
}

bool Matriz::simetrica(Matriz* x)
{
        int i,j;
        for(i=0;i<getQuantidadeDeLinhas();i++)
        {
            for(j=0;j<getQuantidadeDeColunas() && getElemento(i,j)==x->getElemento(i,j);j++);
        }

        if(j==getQuantidadeDeColunas()&&i==getQuantidadeDeLinhas())
        {
            return true;
        }
        else
        {
            return false;
        }
}

bool Matriz::iguais(Matriz* x)
{
    bool valor=true;
    for(int i=0;i<quantidadeDeLinhas;i++)
    {
        for(int j=0;j<quantidadeDeColunas;j++)
        {
            if(valor==true)
            {
                if(getElemento(i,j)==x->getElemento(i,j))
                {
                    valor=true;
                }
                else
                {
                    valor=false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return valor;

}

bool Matriz::ortogonal(Matriz* x)
{
    int i;
    if(x->getQuantidadeDeColunas()!=x->getQuantidadeDeLinhas())
    {
        return false;
    }
    else
    {
        for(i=0;i<x->getQuantidadeDeLinhas()&& x->getElemento(i,i)==1; i++);

        if(i==x->getQuantidadeDeLinhas())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

Matriz* Matriz::potenssa(Matriz* x,int w)
{
    int a,b,i=0;
    Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);
    if(w==0)
    {
        std::cout<<"\nDigite um valor valido\n";
        throw("\n\tValor invalido inserido\n");
        return nullptr;
    }
    for(a=0;a<quantidadeDeLinhas;a++)
    {
        for(b=0;b<quantidadeDeColunas;b++)
        {
            aux->setElemento(x->getElemento(a,b),a,b);
        }
    }
    do
    {

        if(i==0)
        {
            aux=*x*(x);
        }
        else
        {
            aux=*x*(aux);
        }
        i++;
    }while(i!=w-1);
    return aux;
}

Matriz* Matriz::multipork(Matriz* x, int w)
{
    Matriz *aux = new Matriz(quantidadeDeLinhas,quantidadeDeColunas);

    for(int i=0;i<x->getQuantidadeDeLinhas();i++)
    {
        for(int y=0;y<x->getQuantidadeDeColunas();y++)
        {
            aux->setElemento(x->getElemento(i,y)*w,i,y);
        }
    }
    return aux;
}
void Matriz::menu()
{
    std::cout<<("\n1- Para setar um valor na matriz\n");
    std::cout<<("2- Para setar um valor para a segunda matriz \n" );
    std::cout<<("3- Para somar a matriz criada\n");
    std::cout<<("4- Para subtrair a matriz\n");
    std::cout<<("5- Para mostrar todas as matrizes\n");
    std::cout<<("6- Para determinar se a matriz é triangular inferior\n");
    std::cout<<("7- Para determinar se a matriz é triangular superior\n");
    std::cout<<("8- Para determinar se a matriz é identidade\n");
    std::cout<<("9- Para determinar a matriz transposta\n");
    std::cout<<("10- Para determinar se a matriz é simetrica\n");
    std::cout<<("11- Para determinar se as duas matrizes são iguais ou diferentes\n");
    std::cout<<("12- Para determinar se a matriz é ortogonal\n");
    std::cout<<("13- Para determinar se a matriz é de permutação\n");        //falta terminar
    std::cout<<("14- Para calcular a multiplicação de duas matrizes\n");
    std::cout<<("15- Para calcular a potenciação de uma matriz\n");
    std::cout<<("16- Para calcular a multiplicação de uma matriz por k\n");
    std::cout<<("0- Para sair do pograna\n ");

}

}//fim

