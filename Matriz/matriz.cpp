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
    x=nullptr;
    return x;
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
    puts("1- Para setar um valor na matriz");
    puts("2- Para setar um valor para a segunda matriz " );
    puts("3- Para somar a matriz criada");
    puts("4- Para subtrair a matriz");
    puts("5- Para mostrar todas as matrizes");
    puts("6- Para determinar se a matriz é triangular inferior");
    puts("7- Para determinar se a matriz é triangular superior");
    puts("8- Para determinar se a matriz é identidade");
    puts("9- Para determinar a matriz transposta");
    puts("10- Para determinar se a matriz é simetrica");
    puts("11- Para determinar se as duas matrizes são iguais ou diferentes");
    puts("12- Para determinar se a matriz é ortogonal");        //falta terminar
    puts("13- Para determinar se a matriz é de permutação");        //falta terminar
    puts("14- Para calcular a multiplicação de duas matrizes");
    puts("15- Para calcular a potenciação de uma matriz");
    puts("16- Para calcular a multiplicação de uma matriz por k");
    puts("0- Para sair do pograna ");

}

}//fim

