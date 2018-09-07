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
    Matriz* operator + (Matriz* mat);
    Matriz* operator - (Matriz* mat);
    Matriz* operator * (Matriz* );
    bool trianginf();
    bool triangsup();
    bool identidade();
    void transposta(Matriz* );
    bool simetrica(Matriz* );
    bool iguais(Matriz* );

};
}//fim


#endif // MATRIZ_H

/* to test trianginf and sup
 * 3 3 1 1 0 0 1 0 0 1 1 0 0 2 1 2 1 0 1 5 1 1 1 0 1 2 1 9 2 0 1 7 2 1 1 4 2 2 2 2 0 0 2 8 0 1 2 1 0 2 2 0 1 0 2 3 1 1 2 7 1 2 2 0 2 0 2 0 2 1 2 1 2 2
 * */
