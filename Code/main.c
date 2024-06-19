#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int cE = 1;
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
    int codigoCliente;
    int entrada[3];
    int saida[3];
    int diarias;
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
int calculaDiarias ();
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
    FILE *estadia;
    estadia = fopen("C:\\Github\\Sistema-Hotel-Descanso-Garantido\\Code\\Txt\\Estadia.txt", "r+");
    if(!estadia)
    {
        printf("Ocorreu um error ao abrir um arquivo");
        fclose(estadia);
    }
    do
    {
        struct Estadia registro;
        registro.codigoEstadia = cE;
        fprintf(estadia,"Estadia: %d {\n", registro.codigoEstadia);
        do
        {
            printf("Digite o código do Cliente que deseja se hospedar:\n");
            scanf("%d", &registro.codigoCliente);
        }while(registro.codigoCliente < 1);

        do
        {
            printf("Digite o dia de entrada do cliente:\n");
            scanf("%d", &registro.entrada[1]);
        }while(registro.entrada[1] < 1 || registro.entrada[1] > 31);
        do
        {
            printf("Digite o mês de entrada do cliente:\n");
            scanf("%d", &registro.entrada[2]);
        }while(registro.entrada[2] < 1 || registro.entrada[1] > 12);
        do
        {
            printf("Digite o ano de entrada do cliente:\n");
            scanf("%d", &registro.entrada[3]);
        }while(registro.entrada[3] < 2024);
        fprintf(estadia, "Data da entrada: %d/%d/%d", registro.entrada[1],registro.entrada[2],registro.entrada[3]);
        do
        {
            printf("Digite o dia de saída do cliente:\n");
            scanf("%d", &registro.saida[1]);
        }while(registro.saida[1] < 1 || registro.saida[1] > 31);
        do
        {
            printf("Digite o mês de saída do cliente:\n");
            scanf("%d", &registro.saida[2]);
        }while(registro.saida[2] < 1 || registro.saida[2] > 12);
        do
        {
            printf("Digite o ano de saída do cliente:\n");
            scanf("%d", &registro.saida[3]);
        }while(registro.saida[3] < registro.entrada[3]);
        fprintf(estadia, "Data da saída: %d/%d/%d", registro.saida[1],registro.saida[2],registro.saida[3]);


        int dias = calculaDiarias (registro.entrada[3], registro.saida[3]);


        printf("Deseja cadastrar mais alguma estadia('s' para sim e 'n' para não):\n");
        scanf(" %c", &estadia2);
    }
    while(estadia2 != 'n');
    fclose(estadia);
    cE++;
}
void cadastroQuarto ()
{
    char quarto2;
    FILE *quarto;
    quarto = fopen("C:\\Github\\Sistema-Hotel-Descanso-Garantido\\Code\\Txt\\Quartos.txt", "r+");
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
        fprintf(quarto, "Quarto %d \n{\n", registro.numeroQuarto);
        do
        {
            printf("Quantos hospestes cabem dentro deste quarto:\n");
            scanf("%d", &registro.hospedes);
        }
        while(registro.hospedes < 0);
        fprintf(quarto, "Quantos hospedes cabem: %d \n", registro.hospedes);
        do
        {
            printf("Quanto é a diaria deste quarto:\n");
            scanf("%f", &registro.valorDiario);
        }
        while(registro.valorDiario < 0.01);
        fprintf(quarto,"Valor da diaria: %.2f \n", registro.valorDiario);
        do
        {
            printf("Qual o status do quarto ele esta desocupado ou ocupado:\n");
            gets(registro.status);
        }
        while((strcmp(registro.status, "desocupado") != 0 && strcmp(registro.status, "ocupado") != 0));
        fprintf(quarto, "Status do quarto: %s \n}\n", registro.status);
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
int calculaDiarias (int entrada[3], int saida[3])
{
    int dias = 0;
    if(entrada[2] < saida[2])
    {
        dias = 31 * (saida[2] - entrada[2]);
    }
    if(entrada[3] < saida[3])
    {
        if(dias == 0)
        {
            dias = 365 * (saida[3] - entrada[3]);
        }
        else
        {
            dias = dias + 365 * (saida[3] - entrada[3]);
        }
    }
    if(dias == 0)
    {
        dias = saida[1] - entrada [1];
    }
    else
    {
        dias = dias + (saida[1] - entrada [1]);
    }
    return dias;
}
