#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Cliente
{
    int codigo;
    char nome[100];
    char endereco[100];
    char numero[11];
};
struct Funcionarios
{
    int codigo;
    char nome[100];
    char numero[11];
    char cargo[50];
    float salario;
};
struct Estadia
{
    int codigoEstadia;
    int entrada[3];
    int saida[3];
    int diarias;
    int codigoCliente;
    int numeroQuarto;
};
struct Quarto
{
    int numeroQuarto;
    int hospedes;
    float valorDiario;
    int status;
};
void cadastraCliente ();
void cadastraEstadia ();
void cadastraFuncionario ();
void cadastroQuarto ();
void achaEstadia ();
void pesquisaPessoas ();
void finalizarEstadia ();
int main()
{
    setlocale(LC_ALL, "portuguese");
    int menu;
    do
    {
        printf("Escolha oque voce ira fazer no sistema:\n");
        printf(" 1 - Cadastras cliente \n 2 - Cadastrar funcionario \n 3 - Cadastrar Estadia\n 4 - Pesquisar por pessoas \n 5 - Baixa em Estadia \n 0 - Sair \n");
        scanf("%d", &menu);
        if(menu < 0 || menu > 5)
        {
            printf("Digite entre as opções do menu! \n");
        }
        switch(menu)
        {
        case 0:
                printf("Saindo do Programa...");
            break;
        case 1:
            cadastraCliente();
            break;
        case 2:
            cadastraFuncionario();
            break;
        case 3:
            cadastraEstadia();
            break;
        case 4:
            pesquisaPessoas();
            break;
        case 5:
            finalizarEstadia();
            break;

        }
    }
    while(menu != 0);
    return 0;
}

void cadastraCliente ()
{
    printf("entrou");

}

void cadastraFuncionario ()
{

     printf("entrou");
}
void cadastraEstadia ()
{

     printf("entrou");
}
void cadastroQuarto ()
{

}

void finalizarEstadia ()
{

    printf("entrou");
}

void pesquisaPessoas ()
{
    printf("entrou");
}
void achaEstadia ()
{

}
