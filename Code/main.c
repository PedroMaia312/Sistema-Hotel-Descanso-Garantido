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
    int menu;
    do
    {
        printf("Escolha oque voce ira fazer no sistema:\n");
        printf(" 1 - Cadastras cliente \n 2 - Cadastrar funcionario \n 3 - Cadastrar Estadia\n 4 - Cadastrar Quarto \n 5 - Pesquisar por pessoas \n 6 -  Baixa em Estadia \n 0 - Sair \n");
        scanf("%d", &menu);
        while (getchar() != '\n'); //limpa o buffer de entrada
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

void cadastraCliente()
{
    //inicializa as variaveis
    FILE *fluxo;
    fluxo = fopen("Clientes.txt", "a+");
    struct Cliente clienteatual;
    int erro = 0;
    //preenche as variaveis
    do
    {
        erro = 0;
        printf("digite o nome do cliente:\n");
        gets(clienteatual.nome);
        //confere se o usuario digitou apenas letras em seu nome
        for (int i = 0; i < strlen(clienteatual.nome); i++)
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
        //confere se o usuario digitou apenas numeros em seu numero
        for (int i = 0; i < strlen(clienteatual.numero); i++)
        {
            if(isdigit(clienteatual.numero[i]) == 0)
            {
                erro++;
            }
        }
    }
    while(erro != 0);
    //inicializa as variaveis que irão manipular os dados do arquivo
    char linha[200];
    char ultimalinha[200];
    char delimitador[] = ";";
    //encontra a ultima linha do arquivo
    while(fgets(linha, sizeof(linha), fluxo) != NULL)
    {
        strcpy(ultimalinha, linha);
    }
    //le o codigo do ultimo cliente cadastrado e da o codigo + 1 para o proximo cliente cadastrado
    clienteatual.codigo = atoi(strtok(ultimalinha, delimitador));
    printf("seu codigo para futuras pesquisas é %d \n", clienteatual.codigo + 1);
    //coloca as infomações no arquivo txt, neste formato: codigo;nome;endereco;numero;
    fprintf(fluxo, "\n%d;%s;%s;%s;", clienteatual.codigo + 1,clienteatual.nome,clienteatual.endereco,clienteatual.numero);
    fclose(fluxo);
}

void cadastraFuncionario()
{
    //inicializa as variaveis
    FILE *fluxo;
    fluxo = fopen("Funcionarios.txt", "a+");
    struct Funcionarios funcionarioatual;
    int erro = 0;
    //preenche as variaveis
    do
    {
        erro = 0;
        printf("digite o nome do funcionario:\n");
        gets(funcionarioatual.nome);
        //confere se o usuario digitou apenas letras em seu nome
        for (int i = 0; i < strlen(funcionarioatual.nome); i++)
        {
            if(isalpha(funcionarioatual.nome[i]) == 0 && funcionarioatual.nome[i] != ' ')
            {
                erro++;
            }
        }
        printf("digite o cargo do funcionario:\n");
        gets(funcionarioatual.cargo);
        //confere se o usuario digitou apenas letras em seu cargo
        for (int i = 0; i < strlen(funcionarioatual.cargo); i++)
        {
            if(isalpha(funcionarioatual.cargo[i]) == 0 && funcionarioatual.cargo[i] != ' ')
            {
                erro++;
            }
        }
        printf("digite o numero do funcionario:\n");
        gets(funcionarioatual.numero);
        //confere se o usuario digitou apenas numeros em seu numero
        for (int i = 0; i < strlen(funcionarioatual.numero); i++)
        {
            if(isdigit(funcionarioatual.numero[i]) == 0)
            {
                erro++;
            }
        }
        printf("digite o salario do funcionario:\n");
        gets(funcionarioatual.salario);
        //confere se o usuario digitou apenas numeros ou virgulas em seu salario
        for (int i = 0; i < strlen(funcionarioatual.salario); i++)
        {
            if(isdigit(funcionarioatual.salario[i]) == 0 && funcionarioatual.salario[i] != ',')
            {
                erro++;
            }
        }
    }
    while(erro != 0);
    //inicializa as variaveis que irão manipular os dados do arquivo
    char linha[200];
    char ultimalinha[200];
    char delimitador[] = ";";
    //encontra a ultima linha do arquivo
    while(fgets(linha, sizeof(linha), fluxo) != NULL)
    {
        strcpy(ultimalinha, linha);
    }
    //le o codigo do ultimo cliente cadastrado e da o codigo + 1 para o proximo cliente cadastrado
    funcionarioatual.codigo = atoi(strtok(ultimalinha, delimitador));
    printf("seu codigo para futuras pesquisas é %d \n", funcionarioatual.codigo + 1);
    //coloca as infomações no arquivo txt, neste formato: codigo;nome;cargo;numero;salario;
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

void pesquisaPessoas()
{
    //inicializa as variaveis
    FILE *fluxo;
    int tipopessoa;
    int tipopesquisa;
    char linha[250];
    char codigo[11];
    char codigo2[11];
    char nome[100];
    char delimitador[] = ";";
    int certo = 0;
    //pergunta ao usuario em que arquivo o codigo ira pesquisar e como
    do
    {
        printf("Você deseja saber as informações de um Cliente ou de um Funcionário? Digite '1' para cliente e '2' para funcionário: ");
        scanf("%d", &tipopessoa);
        while (getchar() != '\n');
    }
    while(tipopessoa != 1 && tipopessoa != 2);

    do
    {
        printf("Você deseja pesquisar usando o seu código ou seu nome? (se lembre que o nome deve ser exatamente igual ao cadastrado) Digite '1' para código e '2' para nome: ");
        scanf("%d", &tipopesquisa);
        while (getchar() != '\n');
    }
    while(tipopesquisa != 1 && tipopesquisa != 2);
    //abre o arquivo de acordo com o que o usuario escolher
    if(tipopessoa == 1)
    {
        fluxo = fopen("Clientes.txt", "r");
    }
    else
    {
        fluxo = fopen("Funcionarios.txt", "r");
    }
    if(tipopesquisa == 1)
    {
    printf("Digite o seu código:\n");
    gets(codigo);
    }
    else
    {
    printf("Digite o seu nome:\n");
    gets(nome);
    }
    //while que confere todas as linhas
    while(fgets(linha, sizeof(linha), fluxo) != NULL)
    {
        char *campo = strtok(linha, delimitador);

        // Pesquisa cliente
        if(tipopessoa == 1)
        {
            // Pesquisa por código
            if(tipopesquisa == 1)
            {
                if(strcmp(campo, codigo) == 0)
                {
                    campo = strtok(NULL, delimitador);
                    printf("O seu nome é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu endereço é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu número é %s\n", campo);
                    certo++;
                    break;
                }
            }

            // Pesquisa por nome
            if(tipopesquisa == 2)
            {
                strcpy(codigo2, campo);
                campo = strtok(NULL, delimitador);
                if(strcmp(campo, nome) == 0)
                {
                    printf("o seu codigo é %s\n", codigo2);
                    campo = strtok(NULL, delimitador);
                    printf("O seu endereço é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu número é %s\n", campo);
                    certo++;
                    break;
                }
            }
        }

        // Pesquisa funcionário
        if(tipopessoa == 2)
        {
            // Pesquisa por código
            if(tipopesquisa == 1)
            {
                if(strcmp(campo, codigo) == 0)
                {
                    campo = strtok(NULL, delimitador);
                    printf("O seu nome é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu cargo é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu número é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu salário é %s\n", campo);
                    certo++;
                    break;
                }
            }

            // Pesquisa por nome
            if(tipopesquisa == 2)
            {
                strcpy(codigo2, campo);
                campo = strtok(NULL, delimitador);
                if(strcmp(campo, nome) == 0)
                {
                    printf("o seu codigo é %s\n", codigo2);
                    campo = strtok(NULL, delimitador);
                    printf("O seu cargo é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu número é %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu salário é %s\n", campo);
                    certo++;
                    break;
                }
            }
        }
    }

    if(certo == 0)
    {
        printf("Não foi possível encontrar nenhum Cliente/Funcionário com o Código/Nome digitado.\n");
    }

    fclose(fluxo);
}
void achaEstadia ()
{

}
