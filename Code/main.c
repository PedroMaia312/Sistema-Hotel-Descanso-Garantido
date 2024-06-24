#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

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
    int codigoCliente;
    int entrada[3];
    int saida[3];
    float diarias;
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
    char estadia2;
    FILE *estadia, *quarto;
    estadia = fopen("Estadia.txt", "r+");
    quarto = fopen("Quartos.txt", "r+");
    int hospedes;
    int comphospedes;
    long pos;
    struct Estadia registro;
    char linha[200];
    char ultimalinha[200];
    char delimitador[] = ";";
    if(!estadia)
    {
        printf("Ocorreu um error ao abrir um arquivo");
        fclose(estadia);
    }
    if(!quarto)
    {
        printf("Ocorreu um error ao abrir um arquivo");
        fclose(quarto);
    }
    do
    {
        while(fgets(linha, sizeof(linha), estadia) != NULL)
        {
            strcpy(ultimalinha, linha);
        }
        registro.codigoEstadia = atoi(strtok(ultimalinha, delimitador));
        do
        {
            printf("Digite o código do Cliente que deseja se hospedar:\n");
            scanf("%d", &registro.codigoCliente);
        }while(registro.codigoCliente < 1);

        do
        {
            printf("Digite o dia de entrada do cliente:\n");
            scanf("%d", &registro.entrada[0]);
        }
        while(registro.entrada[0] < 1 || registro.entrada[0] > 31);
        do
        {
            printf("Digite o mês de entrada do cliente:\n");
            scanf("%d", &registro.entrada[1]);
        }
        while(registro.entrada[1] < 1 && registro.entrada[1] > 12);
        do
        {
            printf("Digite o ano de entrada do cliente:\n");
            scanf("%d", &registro.entrada[2]);
        }
        while(registro.entrada[2] < 2024);
        do
        {
            printf("Digite o dia de saída do cliente:\n");
            scanf("%d", &registro.saida[0]);
        }
        while(registro.saida[0] < 1 || registro.saida[0] > 31);
        do
        {
            printf("Digite o mês de saída do cliente:\n");
            scanf("%d", &registro.saida[1]);
        }
        while(registro.saida[1] < 1 || registro.saida[1] > 12);
        do
        {
            printf("Digite o ano de saída do cliente:\n");
            scanf("%d", &registro.saida[2]);
        }
        while(registro.saida[2] < registro.entrada[2]);
        do
        {
            printf("Digite quantos hospedes iram ser hospedados:\n");
            scanf("%d", &hospedes);
        }
        while (hospedes < 1);
        while(fgets(linha, sizeof(linha), quarto) != NULL)
        {
            pos = ftell(quarto) - strlen(linha);
            char *campo = strtok(linha, delimitador);
            campo = strtok(NULL, delimitador);
            comphospedes = atoi(campo);
            if(hospedes == comphospedes)
            {
                campo = strtok(NULL, delimitador);
                registro.diarias = atoi(campo);
                campo = strtok(NULL, delimitador);

                if(strcmp(campo, "des") == 0)
                {
                    char *campo2 = strtok(linha, delimitador);
                    registro.numeroQuarto = atoi(campo2);
                    fseek(quarto, pos, SEEK_SET);
                    fprintf(quarto, "%d;%d;%.2f;ocu;", registro.numeroQuarto, hospedes, registro.diarias);
                    break;
                }
            }
        }
        int dias = 0;
        dias = registro.saida[0] - registro.entrada[0];
        dias = dias + (30 * (registro.saida[1] - registro.entrada[1]));
        dias = dias + (365 * (registro.saida[2] - registro.entrada[2]));
        registro.diarias = registro.diarias * dias;
        fprintf(estadia, "\n%d;%d;", registro.codigoEstadia + 1, registro.codigoCliente);
        fprintf(estadia, "%d;%d;%d;",registro.entrada[0], registro.entrada[1], registro.entrada[2]);
        fprintf(estadia, "%d;%d;%d;", registro.saida[0], registro.saida[1], registro.saida[2]);
        fprintf(estadia, "%.2f;%d;", registro.diarias, registro.numeroQuarto);
        printf("\nDeseja cadastrar mais alguma estadia('s' para sim e 'n' para não):\n");
        scanf(" %c", &estadia2);
    }
    while(estadia2 != 'n');
    fclose(estadia);
    fclose(quarto);

}
void cadastroQuarto ()
{
    char quarto2;
    FILE *quarto;
    quarto = fopen("Quartos.txt", "r+");
    struct Quarto registro;
    if(!quarto)
    {
        printf("Ocorreu um error ao abrir um arquivo");
        exit(1);
    }
    do
    {
        do
        {
            printf("Qual o numero do quarto que você deseja registrar:\n");
            scanf("%d", &registro.numeroQuarto);
        }
        while(registro.numeroQuarto < 100);
        do
        {
            printf("Quantos hospestes cabem dentro deste quarto:\n");
            scanf("%d", &registro.hospedes);
        }
        while(registro.hospedes < 0);
        do
        {
            printf("Quanto é a diaria deste quarto:\n");
            scanf("%f", &registro.valorDiario);
        }
        while(registro.valorDiario < 0.01);
        do
        {
            printf("Qual o status do quarto ele esta (des para desocupado ou ocu para ocupado):\n");
            gets(registro.status);
        }
        while((strcmp(registro.status, "des") != 0 && strcmp(registro.status, "ocu") != 0));
        fprintf(quarto, "%d;%d;%.2f;%s;\n", registro.numeroQuarto, registro.hospedes, registro.valorDiario, registro.status);
        printf("Você deseja cadastrar mais um quarto('s' para sim e 'n' para não):\n");
        scanf(" %c", &quarto2);
    }
    while(quarto2 != 'n');
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
