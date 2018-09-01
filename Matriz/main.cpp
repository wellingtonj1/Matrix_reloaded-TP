#include <QCoreApplication>
#include <bits/stdc++.h>
#include "matriz.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int tamacol,tamalinha;
    int escolha;
    puts("Digite a quantidade de linhas : ");
    std::cin>>tamalinha;
    puts("Digite a quantidade de colunas : ");
    std::cin>>tamacol;
    TP2::Matriz *teste1 = new TP2::Matriz(tamalinha,tamacol);
    TP2::Matriz *teste2= new TP2::Matriz(tamalinha,tamacol);
    TP2::Matriz *auxtest= new TP2::Matriz(tamalinha,tamacol);


    do
    {
        puts("1- Para setar um valor na matriz");
        puts("2- Para setar um valor para a segunda matriz criada");
        puts("3- Para somar a matriz criada");
        puts("4- Para subtrair a matriz");
        puts("5- Para mostrar todas as matrizes");
        puts("0- Para sair do pograna ");
        std::cin>>escolha;

        switch (escolha) {
        case 1:

            int colocael,line,col;
            puts("Digite o valor que você quer inserir");
            std::cin>>colocael;
            puts("Digite a linha em que quer colocar o elemento");
            std::cin>>line;
            puts("Digite a coluna em que deseja colocar o elemento");
            std::cin>>col;
            teste1->setElemento(colocael,line,col);
            auxtest->setElemento(colocael,line,col);
            break;


        case 2:

            std::cout<<"\nDigite o valor da segunda matriz para realizar a soma \n";
            int colocaelaux,lineaux,colaux;
            puts("Digite o valor que você quer inserir\n");
            std::cin>>colocaelaux;
            puts("Digite a linha em que quer colocar o elemento\n");
            std::cin>>lineaux;
            puts("Digite a coluna em que deseja colocar o elemento\n");
            std::cin>>colaux;
            teste2->setElemento(colocaelaux,lineaux,colaux);

            break;

        case 3:

            auxtest=*teste1+(teste2);
            auxtest->getMatriz();
            break;

        case 4:

            auxtest=*teste1-(teste2);
            auxtest->getMatriz();
            break;

        case 5:

            std::cout<<"\nPrimeira matriz \n";
            teste1->getMatriz();
            std::cout<<"\n\nSegunda matriz \n";
            teste2->getMatriz();
            std::cout<<"\n\nAuxiliar matriz \n";
            auxtest->getMatriz();
            puts("");
            break;
        default:
            break;
        }
    }while(escolha!=0);
    return 0;

    return a.exec();
}
