#ifndef MATRIZ_H
#define MATRIZ_H
#include<QString>

namespace TP2{//inicio

class Matriz
{
private:
    int quantidadeDeColunas,quantidadeDeLinhas;
    int *ptMatriz;
public:
    Matriz(int,int);
    ~Matriz(){if(ptMatriz) delete[] ptMatriz;}
    int getQuantidadeDeLinhas(){return quantidadeDeLinhas;}
    int getQuantidadeDeColunas(){return quantidadeDeColunas;}

    void setElemento(int elemento, int linha, int coluna);
    int getElemento(int linha, int coluna);
    void getMatriz();
    Matriz* operator + (Matriz*  mat);
    Matriz* operator - (Matriz*  mat);
};
}//fim


#endif // MATRIZ_H
