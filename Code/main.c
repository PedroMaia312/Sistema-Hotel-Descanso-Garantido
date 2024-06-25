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
    setlocale(LC_ALL, "portuguese");
    int menu;
    do
    {
        printf("Escolha oque voce ira fazer no sistema:\n");
        printf(" 1 - Cadastras cliente \n 2 - Cadastrar funcionario \n 3 - Cadastrar Estadia\n 4 - Cadastrar Quarto \n 5 - Pesquisar por pessoas \n 6 - Baixa em Estadia \n 7 - Pesquisar Estadia \n 0 - Sair \n");
        scanf("%d", &menu);
        if(menu < 0 || menu > 7)
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
        case 7:
            achaEstadia();
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
    estadia = fopen("Estadia.txt", "a+");
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
            printf("Digite quantos hospedes iram ser hospedados:");
            scanf("%d", &hospedes);
        }
        while (hospedes < 1);
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

                if(strcmp(campo, "des") == 0)
                {
                    fseek(quarto, pos, SEEK_SET);
                    fflush(quarto);
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
            while (getchar() != '\n');
            printf("Qual o status do quarto ele esta (des para desocupado ou ocu para ocupado):\n");
            gets(registro.status);
        }
        while((strcmp(registro.status, "des") != 0 && strcmp(registro.status, "ocu") != 0));
        fprintf(quarto, "\n%d;%d;%.2f;%s;", registro.numeroQuarto, registro.hospedes, registro.valorDiario, registro.status);
        printf("Você deseja cadastrar mais um quarto('s' para sim e 'n' para não):\n");
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
            numQuarto = atoi(campo);
            fprintf(temp, "%d;%d;", comparar, cliente);
            fflush(temp);
            fprintf(temp, "%d;%d;%d;",diaen, mesen, anoen);
            fflush(temp);
            fprintf(temp, "%d;%d;%d;", diasa, mesai, anosa);
            fprintf(temp, "%.2f;%d;\n", preco, numQuarto);
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

void pesquisaPessoas ()
{

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
                printf("Estas são as informações da Estadia:\n");
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
                printf("Este é o valor a ser pago: %.2f\n", valor);
                campo = strtok(NULL, delimitador);
                numeroQuarto = atoi(campo);
                printf("Este é o numero do quarto: %d\n\n", numeroQuarto);
            }
        }

}
