#include <QCoreApplication>
#include <bits/stdc++.h>
#include "matriz.h"

int main()
{
    int tamacol,tamalinha,escolha,qualmat,vlr;
    puts("Digite a quantidade de linhas da primeira matriz : ");
    std::cin>>tamalinha;
    puts("Digite a quantidade de colunas da primeira matriz : ");
    std::cin>>tamacol;
    TP2::Matriz *teste1 = new TP2::Matriz(tamalinha,tamacol);
    TP2::Matriz *auxtest= new TP2::Matriz(tamalinha,tamacol);
    puts("Digite a quantidade de linhas da segunda matriz : ");
    std::cin>>tamalinha;
    puts("Digite a quantidade de colunas da segunda matriz : ");
    std::cin>>tamacol;
    TP2::Matriz *teste2 = new TP2::Matriz(tamalinha,tamacol);
    system("clear");

    do
    {
        teste1->menu();
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
            /*std::cout<<"\n\nAuxiliar matriz \n";
            auxtest->getMatriz();*/
            puts("");
            break;

        case 6:

            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                    if(teste1->trianginf())
                        std::cout<<"\nA matriz é triangular inferior\n";
                    else
                        std::cout<<"\nA matriz não é triangular inferior\n";
                }
                if(qualmat==2)
                {
                    if(teste2->trianginf())
                        std::cout<<"\nA matriz é triangular inferior\n\n";
                    else
                        std::cout<<"\nA matriz não é triangular inferior\n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);

           break;

        case 7:


            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                    if(teste1->triangsup())
                        std::cout<<"\nA matriz é triangular superior\n\n";
                    else
                        std::cout<<"\nA matriz não é triangular superior\n\n";
                }
                if(qualmat==2)
                {
                    if(teste2->triangsup())
                        std::cout<<"\nA matriz é triangular superior\n\n";
                    else
                        std::cout<<"\nA matriz não é triangular superior\n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);

           break;
        case 8:

            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                    if(teste1->identidade())
                        std::cout<<"\nA matriz é identidade \n\n";
                    else
                        std::cout<<"\nA matriz não é identidade \n\n";
                }
                if(qualmat==2)
                {
                    if(teste2->identidade())
                        std::cout<<"\nA matriz é identidade \n\n";
                    else
                        std::cout<<"\nA matriz não é identidade \n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);

           break;

        case 9:
           std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
           do
           {
               std::cin>>qualmat;
               if(qualmat==1)
               {
                    auxtest->transposta(teste1);
                    auxtest->getMatriz();
               }
               if(qualmat==2)
               {
                   auxtest->transposta(teste2);
                   auxtest->getMatriz();
               }
               if(qualmat!=1&&qualmat!=2)
                   std::cout<<"\nDigite um numero valido!\n";

           }while(qualmat!=1&&qualmat!=2);
            break;

        case 10:

            std::cout<<"\nEm qual matriz você quer determinar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                     auxtest->transposta(teste1);
                     if(teste1->simetrica(auxtest))
                     {
                         std::cout<<"\n A matriz é simétrica ! \n\n";
                     }
                     else
                         std::cout<<"\n A matriz não é simétrica ! \n\n";
                }
                if(qualmat==2)
                {
                    auxtest->transposta(teste2);
                    if(teste2->simetrica(auxtest))
                    {
                        std::cout<<"\n A matriz é simétrica ! \n\n";
                    }
                    else
                        std::cout<<"\n A matriz não é simétrica ! \n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);
            break;

        case 11:

            if(teste1->iguais(teste2))
            {
                std::cout<<"\n A matrizes são iguais \n\n";
            }
            else
            {
                std::cout<<"\n A matrizes são diferentes \n\n";
            }
            break;

        case 12:
        //ortogonal
            std::cout<<"\nEm qual matriz você quer verificar ? { 1 ou 2 }\n\n";
            do
            {
                std::cin>>qualmat;
                if(qualmat==1)
                {
                     if(auxtest->ortogonal(teste1))
                     {
                         std::cout<<"\n A matriz é ortogonal ! \n\n";
                     }
                     else
                         std::cout<<"\n A matriz não é ortogonal ! \n\n";
                }
                if(qualmat==2)
                {
                    if(auxtest->ortogonal(teste2))
                    {
                        std::cout<<"\n A matriz é ortogonal ! \n\n";
                    }
                    else
                        std::cout<<"\n A matriz não é ortogonal ! \n\n";
                }
                if(qualmat!=1&&qualmat!=2)
                    std::cout<<"\nDigite um numero valido!\n";

            }while(qualmat!=1&&qualmat!=2);
            break;

            break;

        case 13:

            break;

        case 14:

            auxtest=*teste1*(teste2);
            auxtest->getMatriz();
            break;

        case 15:

        do
        {
            std::cout<<"\nQual matriz você quer potenciar ? { 1 ou 2 }\n\n";
            std::cin>>qualmat;
            if(qualmat==1)
            {
                std::cout<<"\nDigite a qual valor, desejas elevar tal matriz : ";
                std::cin>>vlr;
                auxtest=teste1->potenssa(teste1,vlr);
                auxtest->getMatriz();
            }
            if(qualmat==2)
            {
                std::cout<<"\nDigite a qual valor, desejas elevar tal matriz : ";
                std::cin>>vlr;
                auxtest->potenssa(teste2,vlr);
                auxtest->getMatriz();

            }
            if(qualmat!=1&&qualmat!=2)
                std::cout<<"\nDigite um numero valido!\n";

        }while(qualmat!=1&&qualmat!=2);

        break;

        case 16:

        do
        {
            std::cout<<"\nQual matriz você quer multiplicar ? { 1 ou 2 }\n\n";
            std::cin>>qualmat;
            if(qualmat==1)
            {
                std::cout<<"\nDigite a qual valor, desejas multiplicar tal matriz : ";
                std::cin>>vlr;
                auxtest=teste1->multipork(teste1,vlr);
                auxtest->getMatriz();
            }
            if(qualmat==2)
            {
                std::cout<<"\nDigite a qual valor, desejas multiplicar tal matriz : ";
                std::cin>>vlr;
                auxtest->multipork(teste2,vlr);
                auxtest->getMatriz();

            }
            if(qualmat!=1&&qualmat!=2)
                std::cout<<"\nDigite um numero valido!\n";

        }while(qualmat!=1&&qualmat!=2);

        break;

        default:
            break;
        }
    }while(escolha!=0);

    return 0;

}
