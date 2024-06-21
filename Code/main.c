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
    char salario[50];
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
    cadastraCliente();
    cadastraFuncionario();
    return 0;
}

void cadastraCliente()
{
    FILE *fluxo;
    fluxo = fopen("Clientes.txt", "a+");
    struct Cliente clienteatual;
    int erro = 0;
    do{
    erro = 0;
    printf("digite o nome do cliente:\n");
    gets(clienteatual.nome);
    for (int i = 0;i < strlen(clienteatual.nome);i++)
    {
        if(isalpha(clienteatual.nome[i]) == 0 && clienteatual.nome[i] != ' ')
        {
            erro++;
        }
    }
    printf("digite o endereço do cliente:\n");
    gets(clienteatual.endereco);
    printf("digite o numero do cliente:\n");
    gets(clienteatual.numero);
    for (int i = 0;i < strlen(clienteatual.numero);i++)
    {
        if(isdigit(clienteatual.numero[i]) == 0)
        {
            erro++;
        }
    }
    }while(erro != 0);
    char linha[200];
    char ultimalinha[200];
    char delimitador[] = ";";
    while(fgets(linha, sizeof(linha), fluxo) != NULL)
    {
        strcpy(ultimalinha, linha);
    }
    clienteatual.codigo = atoi(strtok(ultimalinha, delimitador));
    fprintf(fluxo, "\n%d;%s;%s;%s;", clienteatual.codigo + 1,clienteatual.nome,clienteatual.endereco,clienteatual.numero);
    fclose(fluxo);
}

void cadastraFuncionario()
{
    FILE *fluxo;
    fluxo = fopen("Funcionarios.txt", "a+");
    struct Funcionarios funcionarioatual;
    int erro = 0;
    do{
    erro = 0;
    printf("digite o nome do funcionario:\n");
    gets(funcionarioatual.nome);
    for (int i = 0;i < strlen(funcionarioatual.nome);i++)
    {
        if(isalpha(funcionarioatual.nome[i]) == 0 && funcionarioatual.nome[i] != ' ')
        {
            erro++;
        }
    }
    printf("digite o cargo do funcionario:\n");
    gets(funcionarioatual.cargo);
    for (int i = 0;i < strlen(funcionarioatual.cargo);i++)
    {
        if(isalpha(funcionarioatual.cargo[i]) == 0 && funcionarioatual.cargo[i] != ' ')
        {
            erro++;
        }
    }
    printf("digite o numero do funcionario:\n");
    gets(funcionarioatual.numero);
    for (int i = 0;i < strlen(funcionarioatual.numero);i++)
    {
        if(isdigit(funcionarioatual.numero[i]) == 0)
        {
            erro++;
        }
    }
    printf("digite o salario do funcionario:\n");
    gets(funcionarioatual.salario);
    for (int i = 0;i < strlen(funcionarioatual.salario);i++)
    {
        if(isdigit(funcionarioatual.salario[i]) == 0 && funcionarioatual.salario[i] != ',')
        {
            erro++;
        }
    }
    }while(erro != 0);
    char linha[200];
    char ultimalinha[200];
    char delimitador[] = ";";
    while(fgets(linha, sizeof(linha), fluxo) != NULL)
    {
        strcpy(ultimalinha, linha);
    }
    funcionarioatual.codigo = atoi(strtok(ultimalinha, delimitador));
    fprintf(fluxo, "\n%d;%s;%s;%s;%s;", funcionarioatual.codigo + 1,funcionarioatual.nome,funcionarioatual.cargo,funcionarioatual.numero,funcionarioatual.salario);
    fclose(fluxo);
}
void cadastraEstadia ()
{
    printf("teste git");
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
