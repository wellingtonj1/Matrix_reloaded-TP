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



}//fim
