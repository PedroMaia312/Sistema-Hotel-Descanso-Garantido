#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    char salario[50];
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
    char status[3];
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
    int menu;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        printf("Escolha oque voce ira fazer no sistema:\n");
        printf(" 1 - Cadastras cliente \n 2 - Cadastrar funcionario \n 3 - Cadastrar Estadia\n 4 - Cadastrar Quarto \n 5 - Pesquisar por pessoas \n 6 - Baixa em Estadia \n 7 - Pesquisar Estadia \n 0 - Sair \n");
        scanf("%d", &menu);
        while (getchar() != '\n');
        if(menu < 0 || menu > 7)
        {
            printf("Digite entre as opçoes do menu! \n");
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
        case 7:
            achaEstadia();
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
        printf("digite o endereco do cliente:\n");
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
    printf("seu codigo para futuras pesquisas e %d \n", clienteatual.codigo + 1);
    //coloca as infomações no arquivo txt, neste formato: codigo;nome;endereco;numero;
    fflush(fluxo);
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
    printf("seu codigo para futuras pesquisas e %d \n", funcionarioatual.codigo + 1);
    //coloca as infomações no arquivo txt, neste formato: codigo;nome;cargo;numero;salario;
    fflush(fluxo);
    fprintf(fluxo, "\n%d;%s;%s;%s;%s;", funcionarioatual.codigo + 1,funcionarioatual.nome,funcionarioatual.cargo,funcionarioatual.numero,funcionarioatual.salario);
    fclose(fluxo);
}
void cadastraEstadia ()
{
    char estadia2;
    FILE *estadia, *quarto, *cliente;
    estadia = fopen("Estadia.txt", "a+");
    quarto = fopen("Quartos.txt", "r+");
    cliente = fopen("Clientes.txt", "r");
    int hospedes, certo = 0;
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
            printf("Digite o codigo do Cliente que deseja se hospedar:\n");
            scanf("%d", &registro.codigoCliente);
        }while(registro.codigoCliente < 1);
        while(fgets(linha, sizeof(linha), cliente) != NULL)
        {
            char*campo = strtok(linha, delimitador);
            int compcodigo = atoi(campo);
            if(compcodigo == registro.codigoCliente)
            {
                certo++;
            }
        }
        if(certo == 0)
            {
                printf("\nNenhum cliente tem esse codigo");
                break;
            }
        do
        {
            printf("Digite o dia de entrada do cliente:\n");
            scanf("%d", &registro.entrada[0]);
        }
        while(registro.entrada[0] < 1 || registro.entrada[0] > 31);
        do
        {
            printf("Digite o mes de entrada do cliente:\n");
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
            printf("Digite o dia de saida do cliente:\n");
            scanf("%d", &registro.saida[0]);
        }
        while(registro.saida[0] < 1 || registro.saida[0] > 31);
        do
        {
            printf("Digite o mws de saida do cliente:\n");
            scanf("%d", &registro.saida[1]);
        }
        while(registro.saida[1] < 1 || registro.saida[1] > 12);
        do
        {
            printf("Digite o ano de saida do cliente:\n");
            scanf("%d", &registro.saida[2]);
        }
        while(registro.saida[2] < registro.entrada[2]);
        do
        {
            printf("Digite quantos hospedes iram ser hospedados:");
            scanf("%d", &hospedes);
        } while (hospedes < 1);
        certo = 0;
        int certo2 = 0;
        while (getchar() != '\n');
        while(fgets(linha, sizeof(linha), quarto) != NULL)
        {
            pos = ftell(quarto) - strlen(linha);
            char *campo = strtok(linha, delimitador);
            registro.numeroQuarto = atoi(campo);
            campo = strtok(NULL, delimitador);
            comphospedes = atoi(campo);
            if(hospedes == comphospedes)
            {
                campo = strtok(NULL, delimitador);
                registro.diarias = atoi(campo);
                campo = strtok(NULL, delimitador);
                certo++;
                if(strcmp(campo, "des") == 0)
                {
                    fseek(quarto, pos, SEEK_SET);
                    fflush(quarto);
                    fprintf(quarto, "%d;%d;%.2f;ocu;", registro.numeroQuarto, hospedes, registro.diarias);
                    certo2++;
                    break;
                }
            }
        }
        if(certo == 0)
        {
            printf("Nao existe um quarto com esse numero de hospedes.\n");
            break;
        }
        if(certo2 == 0)
        {
            printf("Nao existe um quarto disponivel com esse numero de hospedes.\n");
            break;
        }
        int dias = 0;
        dias = registro.saida[0] - registro.entrada[0];
        dias = dias + (30 * (registro.saida[1] - registro.entrada[1]));
        dias = dias + (365 * (registro.saida[2] - registro.entrada[2]));
        registro.diarias = registro.diarias * dias;
        fflush(estadia);
        fprintf(estadia, "\n%d;%d;", registro.codigoEstadia + 1, registro.codigoCliente);
        fflush(estadia);
        fprintf(estadia, "%d;%d;%d;",registro.entrada[0], registro.entrada[1], registro.entrada[2]);
        fflush(estadia);
        fprintf(estadia, "%d;%d;%d;", registro.saida[0], registro.saida[1], registro.saida[2]);
        fprintf(estadia, "%.2f;%d;", registro.diarias, registro.numeroQuarto);
        fflush(estadia);
        printf("Deseja cadastrar mais alguma estadia('s' para sim e 'n' para não):\n");
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
    quarto = fopen("Quartos.txt", "a+");
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
            printf("Qual o numero do quarto que voce deseja registrar:\n");
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
            printf("Quanto e a diaria deste quarto:\n");
            scanf("%f", &registro.valorDiario);
        }
        while(registro.valorDiario < 0.01);
        do
        {
            while (getchar() != '\n');
            printf("Qual o status do quarto ele esta (des = desocupado ou ocu = ocupado):\n");
            gets(registro.status);
        }
        while((strcmp(registro.status, "des") != 0 && strcmp(registro.status, "ocu") != 0));
        fprintf(quarto, "\n%d;%d;%.2f;%s;", registro.numeroQuarto, registro.hospedes, registro.valorDiario, registro.status);
        printf("Voce deseja cadastrar mais um quarto('s' para sim e 'n' para nao):\n");
        scanf(" %c", &quarto2);
    }
    while(quarto2 != 'n');
    fclose (quarto);
}
void finalizarEstadia ()
{
    int codigo, numQuarto, comparar;
    int compararQuarto, hospedes;
    float custos, diaria;
    char linha[200];
    char delimitador[] = ";";
    long pos;
    FILE *estadia, *quarto, *temp;
    temp = fopen("Temp.txt", "w");
    estadia = fopen("Estadia.txt", "r");
    quarto = fopen("Quartos.txt", "r+");
     if(!estadia)
    {
        printf("Ocorreu um error ao abrir um arquivo");
        fclose(estadia);
        return;
    }
    if(!quarto)
    {
        printf("Ocorreu um error ao abrir um arquivo");
        fclose(quarto);
        return;
    }
    if(!temp)
    {
        printf("Ocorreu um error ao abrir um arquivo");
        fclose(temp);
        return;
    }
    do{
        printf("Digite o codigo da estadia que o cliente deseja dar baixa:\n");
        scanf("%d", &codigo);
    }while(codigo < 1);
     while(fgets(linha, sizeof(linha), estadia) != NULL)//Preencher o txt temp
     {
        char *campo = strtok(linha, delimitador);
        comparar = atoi(campo);
        if(comparar == codigo)
         {
            campo = strtok(NULL, delimitador);
            campo = strtok(NULL, delimitador);
            campo = strtok(NULL, delimitador);
            campo = strtok(NULL, delimitador);
            campo = strtok(NULL, delimitador);
            campo = strtok(NULL, delimitador);
            campo = strtok(NULL, delimitador);
            campo = strtok(NULL, delimitador);
            custos = atof(campo);
            campo = strtok(NULL, delimitador);
            numQuarto = atoi(campo);
            printf("%d\n", numQuarto);
         }
        if(comparar != codigo)
        {
            campo = strtok(NULL, delimitador);
            int cliente = atoi(campo);
            campo = strtok(NULL, delimitador);
            int diaen = atoi(campo);
            campo = strtok(NULL, delimitador);
            int mesen = atoi(campo);
            campo = strtok(NULL, delimitador);
            int anoen = atoi(campo);
            campo = strtok(NULL, delimitador);
            int diasa = atoi(campo);
            campo = strtok(NULL, delimitador);
            int mesai = atoi(campo);
            campo = strtok(NULL, delimitador);
            int anosa = atoi(campo);
            campo = strtok(NULL, delimitador);
            float preco = atof(campo);
            campo = strtok(NULL, delimitador);
            int numQuarto2 = atoi(campo);
            fprintf(temp, "%d;%d;", comparar, cliente);
            fflush(temp);
            fprintf(temp, "%d;%d;%d;",diaen, mesen, anoen);
            fflush(temp);
            fprintf(temp, "%d;%d;%d;", diasa, mesai, anosa);
            fprintf(temp, "%.2f;%d;\n", preco, numQuarto2);
            fflush(temp);
        }
     }
    fclose(temp);
    fclose(estadia);
    while(fgets(linha, sizeof(linha), quarto) != NULL)//Mudar de ocupado para desocupado.
     {
        pos = ftell(quarto) - strlen(linha);
        char *campo = strtok(linha, delimitador);
        compararQuarto = atoi(campo);
        if(numQuarto == compararQuarto)
        {
            campo = strtok(NULL, delimitador);
            hospedes = atoi(campo);
            campo = strtok(NULL, delimitador);
            diaria = atof(campo);
            fseek(quarto, pos, SEEK_SET);
            fflush(quarto);
            fprintf(quarto, "%d;%d;%.2f;des;", numQuarto, hospedes, diaria);
            break;
        }
     }
    fclose(quarto);
    temp = fopen("Temp.txt", "r");
    estadia = fopen("Estadia.txt", "w");
     if (!estadia || !temp)
    {
        printf("Ocorreu um erro ao reabrir os arquivos");
        if (estadia) fclose(estadia);
        if (temp) fclose(temp);
        return;
    }
     while (fgets(linha, sizeof(linha), temp) != NULL)//reescrever o arquivo estadia com os dados de temp
    {
        fprintf(estadia,"%s", linha);
    }
    fclose(estadia);
    fclose(temp);
    printf("Pronto! A estadia acabou de ser finalizada o cliente agora deve pagar: %.2f\n", custos);
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
        printf("Voce deseja saber as informacoes de um Cliente ou de um Funcionario? Digite '1' para cliente e '2' para funcionario: ");
        scanf("%d", &tipopessoa);
        while (getchar() != '\n');
    }
    while(tipopessoa != 1 && tipopessoa != 2);

    do
    {
        printf("Você deseja pesquisar usando o seu codigo ou seu nome? (se lembre que o nome deve ser exatamente igual ao cadastrado) Digite '1' para codigo e '2' para nome: ");
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
    printf("Digite o seu codigo:\n");
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
                    printf("O seu nome e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu endereco e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu numero e %s\n", campo);
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
                    printf("o seu codigo e %s\n", codigo2);
                    campo = strtok(NULL, delimitador);
                    printf("O seu endereco e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu numero e %s\n", campo);
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
                    printf("O seu nome e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu cargo e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu numero e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu salario e %s\n", campo);
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
                    printf("o seu codigo e %s\n", codigo2);
                    campo = strtok(NULL, delimitador);
                    printf("O seu cargo e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu numero e %s\n", campo);
                    campo = strtok(NULL, delimitador);
                    printf("O seu salario e %s\n", campo);
                    certo++;
                    break;
                }
            }
        }
    }

    if(certo == 0)
    {
        printf("Não foi possivel encontrar nenhum Cliente/Funcionario com o Codigo/Nome digitado.\n");
    }
    fflush(fluxo);
    fclose(fluxo);
}
void achaEstadia ()
{
    FILE *estadia;
    int cliente;
    int compCliente;
    char delimitador[] = ";";
    char linha[200];
    int codigo, numeroQuarto;
    int diaEntrada, mesEntrada, anoEntrada;
    int diaSaida, mesSaida, anoSaida;
    float valor;
    estadia = fopen("Estadia.txt", "r");
     if (estadia == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        }
    do{
    printf("digite o codigo do cliente que deseja realizar as buscas das estadias:\n");
    scanf("%d", &cliente);
    }while(cliente < 1);
     while(fgets(linha, sizeof(linha), estadia) != NULL)
        {
            char *campo = strtok(linha, delimitador);
            codigo = atoi(campo);
            campo = strtok(NULL, delimitador);
            compCliente = atoi(campo);
            if(cliente == compCliente)
            {
                printf("Estas sao as informacoes da Estadia:\n");
                printf("Codigo Estadia: %d\n", codigo);
                campo = strtok(NULL, delimitador);
                diaEntrada = atoi(campo);
                campo = strtok(NULL, delimitador);
                mesEntrada = atoi(campo);
                campo = strtok(NULL, delimitador);
                anoEntrada = atoi(campo);
                printf("Este foi o dia de entrada: %d/%d/%d\n", diaEntrada, mesEntrada, anoEntrada);
                campo = strtok(NULL, delimitador);
                diaSaida = atoi(campo);
                campo = strtok(NULL, delimitador);
                mesSaida = atoi(campo);
                campo = strtok(NULL, delimitador);
                anoSaida = atoi(campo);
                printf("Este foi o dia de saida: %d/%d/%d\n", diaSaida, mesSaida, anoSaida);
                campo = strtok(NULL, delimitador);
                valor = atoi(campo);
                printf("Este e o valor a ser pago: %.2f\n", valor);
                campo = strtok(NULL, delimitador);
                numeroQuarto = atoi(campo);
                printf("Este e o numero do quarto: %d\n\n", numeroQuarto);
            }
        }
    fflush(estadia);
    fclose(estadia);
}
