#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int codigoEstadia = 1;
int codigoQuarto = 1;
int codigoFuncionario = 1;
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
    char status[10];
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
        printf(" 1 - Cadastras cliente \n 2 - Cadastrar funcionario \n 3 - Cadastrar Estadia\n 4 - Cadastrar Quarto \n 5 - Pesquisar por pessoas \n 6 -  Baixa em Estadia \n 0 - Sair \n");
        scanf("%d", &menu);
        if(menu < 0 || menu > 6)
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
            cadastroQuarto();
            break;
        case 5:
            pesquisaPessoas();
            break;
        case 6:
            finalizarEstadia();
            break;
        }
    }
    while(menu != 0);
    return 0;
}

void cadastraCliente ()
{

}

void cadastraFuncionario ()
{

}
void cadastraEstadia ()
{
    FILE *estadia;
    estadia = fopen("C:\\Github\\Sistema-Hotel-Descanso-Garantido\\Code\\Txt\\Estadia.txt", "r+");

    fclose(estadia);
}
void cadastroQuarto ()
{
    char quarto2;
    FILE *quarto;
    quarto = fopen("C:\\Github\\Sistema-Hotel-Descanso-Garantido\\Code\\Txt\\Quartos.txt", "r+");
    do{
    if(!quarto)
    {
        printf("Deu algo errado em abrir o codigo");
        exit(1);
    }
    struct Quarto registro;
    printf("Qual o numero do quarto que você deseja registrar:\n");
    scanf("%d", &registro.numeroQuarto);
    printf("Quantos hospestes cabem dentro deste quarto:\n");
    scanf("%d", &registro.hospedes);
    printf("Quanto é a diaria deste quarto:\n");
    scanf("%f", &registro.valorDiario);
    do
    {
    printf("Qual o status do quarto ele esta desocupado ou ocupado:\n");
    gets(registro.status);
    }while((strcmp(registro.status, "desocupado") != 0 && strcmp(registro.status, "ocupado") != 0));
    fprintf(quarto, "%d, %d, %.2f, %s\n", registro.numeroQuarto, registro.hospedes, registro.valorDiario, registro.status);
    printf("Você deseja cadastrar mais um quarto('s' para sim e 'n' para não):\n");
    scanf(" %c", &quarto2);
    }while(quarto2 != 'n');
    fclose (quarto);
}

void finalizarEstadia ()
{

}

void pesquisaPessoas ()
{

}
void achaEstadia ()
{

}
