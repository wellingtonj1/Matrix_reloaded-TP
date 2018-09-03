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

void Matriz::getMatriz()
{
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

/*Matriz* Matriz::operator * (Matriz* mat)
{

}*/

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
            if(triangsup()&&trianginf()&&getElemento(i,j)==0)
            {
                return true;
            }

        }
    }
    return false;

}
}//fim
