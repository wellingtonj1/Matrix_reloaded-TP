#include <QCoreApplication>
#include <bits/stdc++.h>
#include "matriz.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int tamacol,tamalinha;
    int escolha,linhaimp,colunaimp;
    puts("Digite a quantidade de linhas : ");
    std::cin>>tamalinha;
    puts("Digite a quantidade de colunas : ");
    std::cin>>tamacol;
    TP2::Matriz *teste1 = new TP2::Matriz(tamalinha,tamacol);

    do
    {
        puts("1- Para setar um valor na matriz");
        puts("2- Para somar a matriz criada");
        puts("3- Para subtrair a matriz criada");
        puts("4- Para mostrar toda a matriz");
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


            break;


        case 2:



            break;

        case 3:

            break;

        case 4:

            for(linhaimp=0;linhaimp<tamalinha;linhaimp++)
            {
                for(colunaimp=0;colunaimp<tamacol;colunaimp++)
                {
                    if(colunaimp==tamacol-1)
                    {
                       std::cout<< teste1->getElemento(linhaimp,colunaimp)<<"\n";
                    }
                    else
                    {
                        std::cout<<" "<<teste1->getElemento(linhaimp,colunaimp)<< " ";
                    }
                }
            }

            break;
        default:
            break;
        }
    }while(escolha!=0);
    return 0;

    return a.exec();
}
