/*---------------------------------------------------------------------
Uninorte
Sistemas de Informação 2o periodo
Equipe: Denis, Wylkson M. Barbosa, Stanley, Rodrigo
Data início:04/11/2017
Data modificação 1: 05/11/2017
Data modificação 2: 06/11/2017
Matricula: 17181500
------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------
Descricao: Utilize as informações a seguir para criar um controle automatizado de uma clínica média.
Sabe-se que essa clínica deseja ter um controle semanal (2a a 6a feira) das consultas realizadas. A cada
dia podem ser realizadas no máximo duas consultas para cada médico. Considere que são cadastrados
apenas 3 médicos e 5 pacientes.
------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//-------------VARIAVEIS GLOBAIS-------------------
int num=0;  //para cadastro paciente
int num2=0; //para cadastro consulta
int num3=0; //para cadastro medico
int i;//contadora for
int j;//contadora for
#define tam_vetor 3 //variavel definida = constante = não alterável

//-------------VARIAVEIS DE CONT DOS VETORES DA STRUCT DIAS{seg,ter,qua,qui,sex}------------

int cont_dia1 = 1; //contador dia segunda
int cont_dia2 = 1; //contador dia terca
int cont_dia3 = 1; //contador dia quarta
int cont_dia4 = 1; //contador dia quinta
int cont_dia5 = 1; //contador dia sexta

//--------------------------------------------------
//------------------STRUCTS-------------------------
//--------------------------------------------------

//-------------REGISTRO DE DIAS---------------------
struct DIAS
{
    int seg[tam_vetor], ter[tam_vetor], qua[tam_vetor], qui[tam_vetor], sex[tam_vetor];
};
//-------------REGISTRO DE CLIENTE---------------------
struct PACIENTE
{
    int cod_cliente,telefone;
    char nome[60], endereco[60];
};

//-------------REGISTRO DE MEDICO---------------------
struct MEDICO
{
    int cod_medico, telefone;
    char nome[60];
    struct DIAS consulta;
};

//-------------REGISTRO DE CONSULTA------------------
struct CONSULTA
{
    int num_consulta, dia_semana, cod_medico, cod_paciente;
    float hora;
};

struct PACIENTE paciente[5];
struct MEDICO medico[5];
struct CONSULTA consulta[30];

//-----------------------------------------------------------
//-----------FUNCAO CADASTRA PACIENTE NOVO
void cadastro_paciente()
{
    paciente[num].cod_cliente = num; //Recebe código atual
    //-----------LEITURA DO NOME DO PACIENTE-------------
    puts("\nDigite o nome do cliente a ser cadastrado: ");
    fgets(paciente[num].nome,60, stdin);
    fflush(stdin);

//leitura do telefone do paciente
    puts("\nDigite o telefone: ");
    scanf("%d",&paciente[num].telefone);
    fflush(stdin);

//leituta do endereco do paciente
    puts("\nDigite o endereço do paciente: ");
    gets(paciente[num].endereco);
    num++;
    fflush(stdin);
    puts("\nCadastrado com sucesso");
    //entrada pra saida e retorno ao menu
    puts("\n\nTecle enter para sair...");
    fflush(stdin);
    system("pause>>null");//congela
    system("cls");
    return main();//Volta menu
}//Fim Funcao Cadastrar paciente

//--------------------------------------------------------------------------
//-----------FUNCAO CADASTRA MEDICO NOVO----------
void cadastra_medico ()
{
    medico[num3].cod_medico = num3;
    //Entrada nome do medico
    puts("\nDigite o nome do medico:");
    gets(medico[num3].nome);
    fflush(stdin);

    //Entrada telefone do medico
    puts("\nDigite o telefone do medico: ");
    scanf("%d",&medico[num3].telefone);
    fflush(stdin);

    //incremento
    num3++;
    puts("\nCadastrado com sucesso");
    //entrada pra saida e retorno ao menu
    puts("\n\nTecle enter para sair...");
    fflush(stdin);
    system("pause>>null");//congela
    system("cls");
    return main();//Volta menu
}

//-----------------------------------------------------------------------------
//---------------FUNCAO CADASTRA CONSULTA NOVA
void cadastro_consulta()
{
    int existe_pac=0; //Verifica se paciente existe
    int existe_med=0; //Verifica se medico existe
    int continua = 1;//controlador (do)
    int aux_cod_medico;//Var auxiliar para receber codigo de medico.(facilitador de algoritmo)
    do  //REPETE
    {
        system("cls");//Limpa tela
        puts("\nDigite o codigo do paciente");
        scanf("%d",&consulta[num2].cod_paciente);//Guarda codigo do paciente na consulta
        fflush(stdin);//Limpa Buffer do teclado
        for (i=0; i<num; i++)     //pode dar errado
        {
            if (consulta[num2].cod_paciente==paciente[i].cod_cliente) //Verifica se codigo informado pelo usuario é existente nos cadastrados atualmente
            {
                existe_pac=1;//se for existe_pac recebe 1 e sai do laço
                break;
            }
        }//Fim for
        if(existe_pac==0)
        {
            printf("Este paciente ainda nao foi cadastrado! Deseja tentar novamente?S=0/N=2");
            scanf("%d",&existe_pac);//rebebe a escolha do usuario Sim = 0 (continua) / Não = 2 (sai)
            fflush(stdin);
            if(existe_pac == 2) //verifica se é 2 pra sair da funcao
            {
                system("cls");
                return main();//volta pra funcao principal *menu*
            }//Fim if
        }//Fim if
        system("cls");//limpa tela
        system("pause>>null");// congela
    }
    while(existe_pac!=1);  //(ATÉ) existe_pac ser diferente de 1 para sair do laço while

    system("cls");// limpa tela
    puts("Digite o codigo do medico:");
    scanf("%d",&consulta[num2].cod_medico);//Entrada do codigo do medico que fará a consulta
    fflush(stdin);//Limpa buffer do teclado

    //-----------LAÇO PARA VERIFICAR SE O CODIGO DO MEDICO INFORMADO EXISTE NOS CADASTRADOS ATUALMENTE----------------
    do
    {
        //pode dar errado
        for (i=0; i<=num3; i++)
        {
            if (consulta[num2].cod_medico==medico[i].cod_medico)
            {
                existe_med = 1;
            }	//fim if
        }	//fim for
        if(existe_med==0) 	//O existe_med serve para verificar se foi encontrado o médico informado, se sim, ele então sairá do DOWhile.
        {
            puts("\nCodigo do medico invalido");
            puts("\nDigite o codigo do medico com quem sera feito a consulta: ");
            scanf("%d",&consulta[num2].cod_medico);	//Captura codigo do medico
            fflush(stdin);
        }	//fim if
    }
    while(existe_med!=1); //fim do while
    aux_cod_medico = consulta[num2].cod_medico; //Recebe codigo do medico escolhido pelo usuario(variável Auxiliar)
    system("cls");//Limpa tela

    //-----------MENU DE ESCOLHA DE DIA PARA CONSULTA-----------------

    puts("\nDigite o dia da consulta");
    puts("\n2- para segunda");
    puts("\n3- para terca");
    puts("\n4- para quarta");
    puts("\n5- para quinta");
    puts("\n6- para sexta");
    scanf("%d",&consulta[num2].dia_semana);//recebe o dia de consulta desejado
    fflush(stdin);
    if(consulta[num2].dia_semana<2 || consulta[num2].dia_semana>6) //Verifica se o dia informado é menor que 2, ou maior que 6. Se não for ele executa o processamento dentro do if
    {
        system("cls");
        puts("\nDigite o dia da consulta");
        puts("\n2- para segunda");
        puts("\n3- para terca");
        puts("\n4- para quarta");
        puts("\n5- para quinta");
        puts("\n6- para sexta");
        scanf("%d",&consulta[num2].dia_semana);//recebe o dia
        fflush(stdin);
    }
    int dia_escolhido = consulta[num2].dia_semana;//recebe dia da semana escolhido - serve como variavel auxiliar
    //--------------FILTRO DE DIA ESCOLHIDOS, E QUAL AÇÃO DEVERÁ SER TOMADA PARA CADA CASO-----------
    //--------------DENTRO DOS IFs ELE VERIFICA DENTRO DA STRUCT DIAS OS DIAS (SEG,TER,QUA,QUI,SEX)SÃO MAIORES QUE 2
    //--------------SE SIM É MOSTRADA A MENSAGEM DE ERRO (Nao pode existir dois pacientes para o mesmo medico) E RETORNADA AO MENU.
    switch(dia_escolhido)
    {
    case 2://segunda
        if(((medico[aux_cod_medico].consulta.seg[0] != 1) && (medico[aux_cod_medico].consulta.seg[1] != 1)) || (medico[aux_cod_medico].consulta.seg[2] == 0)) //Verifica se vetor 0 e 1 é diferente de 1. E se vetor 2 é igual a 0 para uma terceira verificação que vai ser a do erro
        {
            if(medico[aux_cod_medico].consulta.seg[0] == 0)  //Se medico[posicao].consulta.seg[0] == 0
            {
                medico[aux_cod_medico].consulta.seg[0] = 1;//recebe
            }
            else if(medico[aux_cod_medico].consulta.seg[1] == 0)  //Se medico[posicao].consulta.seg[1] == 0
            {
                medico[aux_cod_medico].consulta.seg[1] = 1;//recebe
                medico[aux_cod_medico].consulta.seg[2] = 1;//recebe
            }//fim elseif
        }
        else
        {
            puts("\nNao pode existir dois pacientes para o mesmo medico");
            consulta[num2].dia_semana = 0;//dia zerado
            system("pause>>null");
            system("cls");
            return main();//retorna menu
        }//fim else
        break;

    case 3://terca
        if(((medico[aux_cod_medico].consulta.ter[0] != 1) && (medico[aux_cod_medico].consulta.ter[1] != 1)) || (medico[aux_cod_medico].consulta.ter[2] == 0)) //Verifica se vetor 0 e 1 é diferente de 1. E se vetor 2 é igual a 0 para uma terceira verificação que vai ser a do erro
        {
            if(medico[aux_cod_medico].consulta.ter[0] == 0) //Se medico[posicao].consulta.ter[0] == 0
            {
                medico[aux_cod_medico].consulta.ter[0] = 1;//recebe
            }
            else if(medico[aux_cod_medico].consulta.ter[1] == 0)  //Se medico[posicao].consulta.ter[1] == 0
            {
                medico[aux_cod_medico].consulta.ter[1] = 1;//recebe
                medico[aux_cod_medico].consulta.ter[2] = 1;//recebe
            }//fim elseif
        }
        else
        {
            puts("\nNao pode existir dois pacientes para o mesmo medico");
            consulta[num2].dia_semana = 0;//dia zerado
            system("pause>>null");
            system("cls");
            return main();//retorna menu
        }//fim else
        break;

    case 4://quarta
        if(((medico[aux_cod_medico].consulta.qua[0] != 1) && (medico[aux_cod_medico].consulta.qua[1] != 1)) || (medico[aux_cod_medico].consulta.qua[2] == 0)) //Verifica se vetor 0 e 1 é diferente de 1. E se vetor 2 é igual a 0 para uma terceira verificação que vai ser a do erro
        {
            if(medico[aux_cod_medico].consulta.qua[0] == 0) //Se medico[posicao].consulta.qua[0] == 0
            {
                medico[aux_cod_medico].consulta.qua[0] = 1;//recebe
            }
            else if(medico[aux_cod_medico].consulta.qua[1] == 0)  //Se medico[posicao].consulta.ter[1] == 0
            {
                medico[aux_cod_medico].consulta.qua[1] = 1;//recebe
                medico[aux_cod_medico].consulta.qua[2] = 1;//recebe
            }//fim elseif
        }
        else
        {
            puts("\nNao pode existir dois pacientes para o mesmo medico");
            consulta[num2].dia_semana = 0;//dia zerado
            system("pause>>null");
            system("cls");
            return main();//retorna menu
        }//fim else
        break;

    case 5://quinta
        if(((medico[aux_cod_medico].consulta.qui[0] != 1) && (medico[aux_cod_medico].consulta.qui[1] != 1)) || (medico[aux_cod_medico].consulta.qui[2] == 0)) //Verifica se vetor 0 e 1 é diferente de 1. E se vetor 2 é igual a 0 para uma terceira verificação que vai ser a do erro
        {
            if(medico[aux_cod_medico].consulta.qui[0] == 0) //Se medico[posicao].consulta.qua[0] == 0
            {
                medico[aux_cod_medico].consulta.qui[0] = 1;//recebe
            }
            else if(medico[aux_cod_medico].consulta.qui[1] == 0)  //Se medico[posicao].consulta.qua[1] == 0
            {
                medico[aux_cod_medico].consulta.qui[1] = 1;//recebe
                medico[aux_cod_medico].consulta.qui[2] = 1;//recebe
            }//fim else
        }
        else
        {
            puts("\nNao pode existir dois pacientes para o mesmo medico");
            consulta[num2].dia_semana = 0;//dia zerado
            system("pause>>null");
            system("cls");
            return main();//retorna menu
        }//fim else
        break;

    case 6://sexta
        if(((medico[aux_cod_medico].consulta.sex[0] != 1) && (medico[aux_cod_medico].consulta.sex[1] != 1)) || (medico[aux_cod_medico].consulta.sex[2] == 0)) //Verifica se vetor 0 e 1 é diferente de 1. E se vetor 2 é igual a 0 para uma terceira verificação que vai ser a do erro
        {
            if(medico[aux_cod_medico].consulta.sex[0] == 0) //Se medico[posicao].consulta.qua[0] == 0
            {
                medico[aux_cod_medico].consulta.sex[0] = 1;//recebe
            }
            else if(medico[aux_cod_medico].consulta.sex[1] == 0)  //Se medico[posicao].consulta.qua[1] == 0
            {
                medico[aux_cod_medico].consulta.sex[1] = 1;//recebe
                medico[aux_cod_medico].consulta.sex[2] = 1;//recebe
            }//fim elseif
        }
        else
        {
            puts("\nNao pode existir dois pacientes para o mesmo medico");//Mensagem de erro
            consulta[num2].dia_semana = 0;//dia zerado
            system("pause>>null");
            system("cls");
            return main();//retorna menu
        }//fim else
        break;
    default://padrão diferente dos anteriores
        puts("O dia escolhido esta incorreto");
    }//fim switch

    //------------PEGA A HORA DA CONSULTA PARA CADASTRO DE UMA NOVA CONSULTA---------------
    system("cls");
    puts("\nDigite a hora da consulta(1-24hrs): ");
    scanf("%f",&consulta[num2].hora);//Guarda dentro do registro consulta
    fflush(stdin);//limpa buffer teclado
    //Verifica se a hora informado está entre 0 e 24hrs, se não for, não é executado o processamento dentro de if.
    do
    {
        if (consulta[num2].hora<1 || consulta[num2].hora>24)
        {
            puts("\nHora invalida");
            puts("\nDigite a hora da consulta: ");
            scanf("%f",&consulta[num2].hora);//guarda hora
            fflush(stdin);//Limpar buffer teclado
        }
        else
        {
            continua = 0;
        }//fim elseif
    }
    while(continua != 0);
    system("cls");//Limpa tela
    consulta[num2].num_consulta = num2;
    num2++;//incremento automático
    puts("\nCadastrado com sucesso");
    //entrada pra saida e retorno ao menu
    puts("\n\nTecle enter para sair...");
    fflush(stdin);
    system("pause>>null");//congela
    system("cls");
    return main();//Volta menu
}//Fim função cadastrar_consulta();

//---------------------------------------------------------------------------
//-------------FUNÇÃO PARA LER MÉDICO E DIA DA SEMANA, E IMPRIMIR QUANTAS CONSULTAS EXISTEM PARA ESTE MÉDICO, NO DIA DA SEMANA.
void consulta_medico()
{

    int cont=0, dia;//cont = quantidade de consultas acumuladas, dia = seg,ter,qua,qui,sex
    int continua = 1;//controlador (do)
    int aux_cod_medico;//var auxiliar

    //laço verificado para inserção de dia, nome do medico
    do  //REPITA
    {
        puts("\nDigite o codigo do medico: ");
        scanf("%d",&aux_cod_medico);
        fflush(stdin);//Limpa buffer
        system("cls");//Limpa tela
        puts("\nDigite o dia da consulta");
        puts("\n2- para segunda");
        puts("\n3- para terca");
        puts("\n4- para quarta");
        puts("\n5- para quinta");
        puts("\n6- para sexta");
        scanf("%d",&dia);//Guarda dia escolhido
        fflush(stdin);//Limpa buffer
        //Verifica se dia está entre 1 e 6
        if(dia > 1 && dia <7)
        {
            //laco para comparar strings(nome do medico inserido acima, com cadastrado na consulta) + dia.
            for (i=0; i<=num2; i++)
            {
                if((aux_cod_medico == consulta[i].cod_medico) && (dia == consulta[i].dia_semana))
                    cont = cont + 1;//incremento
            }//Fim for
            system("cls");//Limpa tela
            printf("O médico tem %d consulta(s) no dia %d da semana.",cont,dia);//Apresenta quantidade de consultas em tal dia
            puts("\n\nTecle enter para sair...");//entrada pra saida e retor ao menu
            fflush(stdin);
            system("pause>>null");//congela
            system("cls");
            return main();//Volta menu
        }
        else
        {
            continua = 1;//continua no laço while
            printf("Digite uma opcao valida.");
            system("pause>>null");//congela
            system("cls");
        }//Fim else
    }
    while(continua = 1); //Até
}

//-------------------------------------------------------------------------
//-------------MOSTRA NA TELA TODAS AS CONSULTAS DAQUELE DIA.
void consulta_dia()
{
    int continua = 1;//controlador (do)
    int dia_escolhido;//variavel para colher dia
    int sem_consulta = 0;
    puts("\nDigite o dia da consulta");
    puts("\n2- para segunda");
    puts("\n3- para terca");
    puts("\n4- para quarta");
    puts("\n5- para quinta");
    puts("\n6- para sexta");
    scanf("%d",&dia_escolhido);
    fflush(stdin);
    if(dia_escolhido > 1 && dia_escolhido <7)
    {
        //Verifica se dia escolhido existe nos dias cadastrados em consulta
        for(i=0; i<=num2; i++)
        {
            if(dia_escolhido==consulta[i].dia_semana)
            {
                printf("\n-----------------------------Consultas por dia------------------------------- ");
                printf("\n Codigo do paciente: %d",consulta[i].cod_paciente, i);//mostra codigo paciente
                printf("\n Codigo do medico: %d",consulta[i].cod_medico, i);//mostra codigo medico
                printf("\n A hora: %.2f hrs %d",consulta[i].hora, i);//mostra hora
                sem_consulta = 1;
            }
            else if(sem_consulta == 0)
            {
                puts("\nNao ha consultas para esses dias");
                puts("\n\nTecle enter para sair...");//entrada pra saida e retor ao menu
                fflush(stdin);
                system("pause>>null");//congela
                system("cls");
                return main();//Volta menu
            }//Fim Else
        }//fechamento do for

        puts("\n\nTecle enter para sair...");//entrada pra saida e retor ao menu
        fflush(stdin);
        system("pause>>null");//congela
        system("cls");
        return main();//Volta menu
    }
    else
    {
        printf("Digite uma opcao valida.");
        system("pause>>null");//congela
        system("cls");
        return main();//Volta menu
    }//Fim else
}//fechamento do void

//-------------------------------------------------------------------------
//----------FUNÇÃO PARA ALTERAR CADASTRO DE PACIENTES-------------
void altera_paciente()
{
    int existe_pac=0;
    int aux_cod_paciente;
    do  //REPETE
    {
        puts("Digite o codigo do paciente: ");
        scanf("%d",&aux_cod_paciente);
        fflush(stdin);//Limpa Buffer do teclado
        for (i=0; i<num; i++)   //pode dar errado
        {
            if (aux_cod_paciente==paciente[i].cod_cliente) //Verifica se codigo informado pelo usuario é existente nos cadastrados atualmente
            {
                existe_pac=1;//se for existe_pac recebe 1 e sai do laço
                break;
            }
        }//Fim for
        if(existe_pac==0)
        {
            printf("Este paciente ainda nao foi cadastrado! Deseja tentar novamente?S=0/N=2");
            scanf("%d",&existe_pac);//rebebe a escolha do usuario Sim = 0 (continua) / Não = 2 (sai)
            fflush(stdin);
            if(existe_pac == 2) //verifica se é 2 pra sair da funcao
            {
                system("cls");
                return main();//volta pra funcao principal *menu*
            }
        }//Fim if
    }
    while(existe_pac!=1);  //ATÉ existe_pac ser diferente de 1 para sair do laço while
    //Mostra dados do paciente com o codigo
    system("cls");
    printf("\n Codigo: %d",paciente[aux_cod_paciente].cod_cliente); //mostra codigo paciente
    printf("\n Nome: %s",paciente[aux_cod_paciente].nome); //mostra nome
    printf("\n Endereco: %s",paciente[aux_cod_paciente].endereco); //mostra endereco
    printf("\n Telefone: %d",paciente[aux_cod_paciente].telefone); //mostra telefone

    //Altera dados do paciente
    puts("\nAlterar nome: ");
    gets(paciente[aux_cod_paciente].nome); //altera nome
    fflush(stdin);
    puts("\nAlterar endereco: ");
    gets(paciente[aux_cod_paciente].endereco); //altera endereco
    fflush(stdin);
    puts("\nAlterar telefone: ");
    scanf("%d",&paciente[aux_cod_paciente].telefone); //altera telefone
    fflush(stdin);
    puts("Dados alterados com sucesso");
    //entrada pra saida e retorno ao menu
    puts("\n\nTecle enter para sair...");
    fflush(stdin);
    system("pause>>null");//congela
    system("cls");
    return main();//Volta menu
}

//-------------------------------------------------------------------------
//-------------FUNÇÃO PARA ALTERAR CADASTROS DE MÉDICOS--------------------
void altera_medico()
{
    int existe_med=0; //variavel de verificação de laço Do-While
    int aux_cod_medico; //var auxilia para receber codigo digitado pelo usuario
    do  //REPETE
    {
        puts("Digite o codigo do medico: ");
        scanf("%d",&aux_cod_medico);
        fflush(stdin);//Limpa Buffer do teclado
        for (i=0; i<num; i++)   //pode dar errado
        {
            if (aux_cod_medico==medico[i].cod_medico) //Verifica se codigo informado pelo usuario é existente nos cadastrados atualmente
            {
                existe_med=1;//se for existe_pac recebe 1 e sai do laço
                break;
            }
        }//Fim for
        if(existe_med==0)
        {
            printf("Este medico ainda nao foi cadastrado! Deseja tentar novamente?S=0/N=2");
            scanf("%d",&existe_med);//rebebe a escolha do usuario Sim = 0 (continua) / Não = 2 (sai)
            fflush(stdin);
            if(existe_med == 2) //verifica se é 2 pra sair da funcao
            {
                system("cls");
                return main();//volta pra funcao principal *menu*
            }
        }//Fim if
    }
    while(existe_med!=1);  //ATÉ existe_pac ser diferente de 1 para sair do laço while
    //Mostra dados do paciente com o codigo
    system("cls");
    printf("\n Codigo: %d",medico[aux_cod_medico].cod_medico); //mostra codigo do medico
    printf("\n Nome: %s",medico[aux_cod_medico].nome); // mostra nome
    printf("\n Telefone: %d",medico[aux_cod_medico].telefone);	//mostra telefone

    //Altera
    puts("\nAlterar nome: ");
    gets(medico[aux_cod_medico].nome); //altera nome
    fflush(stdin);
    puts("\nAlterar telefone: ");
    scanf("%d",&medico[aux_cod_medico].telefone); //altera telefone
    fflush(stdin);
    puts("Dados alterados com sucesso");
    //entrada pra saida e retorno ao menu
    puts("\n\nTecle enter para sair...");
    fflush(stdin);
    system("pause>>null");//congela
    system("cls");
    return main();//Volta menu
}

//--------------------------------------------------------------------------
//----------------ALTERA CONSULTA CADASTRADA-----------------
void altera_consulta()
{
    int continua = 1;	//Variável controladora DoWhile
    int escolha_consulta;	//recebe a primeira entrada em relação ao numero da consulta à ser alterada
    float guarda_num_consulta; 	//Guarda o novo horário à ser adicionado ao registro (consulta[num_consulta].hora).
    int num_consulta;	//Recebe a posição [i] do laço FOR onde (escolha_consulta == consulta[i].num_consulta) foi encontrada.
    for (i=0; i<=num2; i++)
    {
        //Mostra uma lista com todas as consultas já criadas
        printf("\n------------------------%da Consulta------------------------\n",i+1);
        printf("\nnumero consulta: %d | dia: %d | cod_med: %d | cod_pac: %d | hora: %.2f",consulta[i].num_consulta, consulta[i].dia_semana, consulta[i].cod_medico, consulta[i].cod_paciente, consulta[i].hora);
        system("pause>>null");
    }//fim for
    puts("\nVoce so podera alterar a hora de atendimento.");
    puts("\nQual consulta deseja alterar. 666 p/ retornar ao menu: ");
    scanf("%d",&escolha_consulta);	//entrada do numero da consulta à ser alterada.

    if(escolha_consulta == 666) 	//Verifica se o usuário decidiu sair da função
    {
        return main();	//retorna menu
    }
    //---------------TROCA DE HORA--------------------
    for (i=0; i<=num2; i++)
    {
        if(escolha_consulta == consulta[i].num_consulta) //Se numero de consulta escolhida for igual à consulta[posição].num
        {

            num_consulta = i;
            puts("Qual o novo horario de sua consulta: ");
            scanf("%f",&guarda_num_consulta);
            do
            {
                if (guarda_num_consulta<1 || guarda_num_consulta>24)
                {
                    puts("\nHora invalida");
                    puts("\nDigite a hora da consulta: ");
                    scanf("%f",&guarda_num_consulta);//guarda hora
                    fflush(stdin);//Limpar buffer teclado
                }
                else
                {
                    continua = 0;
                    consulta[num_consulta].hora = guarda_num_consulta;
                }//fim else
            }
            while(continua != 0);	//ATÉ que variável continua seja diferente de 0.
            printf("\nAlterado com sucesso!\n");
            //entrada pra saida e retorno ao menu
            puts("\n\nTecle enter para sair...");
            fflush(stdin);
            system("pause>>null");//congela
            system("cls");
            return main();//Volta menu
        }//fim if
    }//fim for

}//fim alterar consulta

//--------------------------------------------------------------------------
//---------------MENU DE NAVEGAÇÃO-------------
int menu()
{
    system("cls");
    int escolha;//Var decisão de opção no menu
    puts("-----------------------------BEM VINDO--------------------------------");
    puts("O que voce deseja fazer?");
    puts("1- Para cadastrar novo paciente");
    puts("2- Para cadastrar novo medico");
    puts("3- Para cadastrar consulta");
    puts("4- Para consultar consultas por dia");
    puts("5- Para ver consultas agendadas para um medico");
    puts("6- Para alterar paciente");
    puts("7- Para alterar medico");
    puts("8- Para alterar consulta");
    puts("----------------------------------------------------------------------");
    scanf("%d",&escolha);
    fflush(stdin);
    return escolha;//retorna a escolha do usuario
}

//-------------------------------------------------------------------------
//--------------FUNCAO PRINCIPAL------------------
main ()
{
    int escolha;
    while(1)
    {
        int escolha = menu();
        switch(escolha)
        {
        case 1:  //Cadastra novo paciente
            system("cls");
            cadastro_paciente();
            system("pause>>null");//congela
            break;
        case 2: //Cadastra novo medico
            system("cls");
            cadastra_medico();
            system("pause>>null");
            break;
        case 3: //Consultar consulta de paciente por dia
            system("cls");
            cadastro_consulta();
            system("pause>>null");
            break;
        case 4: //Consulta Consultas por médico
            system("cls");
            consulta_dia();
            system("pause>>null");
            break;
        case 5: //Cadastra nova consulta
            system("cls");
            consulta_medico();
            system("pause>>null");
            break;
        case 6://alterar paciente
            system("cls");
            altera_paciente();
            system("pause>>null");
            break;
        case 7://alterar medico
            system("cls");
            altera_medico();
            system("pause>>null");
            break;
        case 8://alterar consulta
            system("cls");
            altera_consulta();
            system("pause>>null");
            break;
        case 9://CASO PRA TESTE
            for(i=0; i<=4; i++)
            {
                printf("\n\n------------------------Dados------------------------\n\n");
                printf("\nPaciente: %d ,",paciente[i].cod_cliente);	 //codigo paciente
                printf("nome: %s",paciente[i].nome);	//nome paciente
                printf("\nMedicos %d: ,", medico[i].cod_medico); //codigo medico
                printf("nome: %s", medico[i].nome);	 //nome medico
                printf("\nSegunda: c1=%d | c2=%d",medico[i].consulta.seg[i],medico[i].consulta.seg[i+1]); //vetor segunda para consulta até 2
                printf("\nTerca: c1=%d | c2=%d",medico[i].consulta.ter[i],medico[i].consulta.ter[i+1]);//vetor terca para consulta até 2
                printf("\nQuarta: c1=%d | c2=%d",medico[i].consulta.qua[i],medico[i].consulta.qua[i+1]);//vetor quarta para consulta até 2
                printf("\nQuinta: c1=%d | c2=%d",medico[i].consulta.qui[i],medico[i].consulta.qui[i+1]);//vetor quinta para consulta até 2
                printf("\nSexta: c1=%d | c2=%d",medico[i].consulta.sex[i],medico[i].consulta.sex[i+1]);//vetor sexta para consulta até 2
                //Lista de consultas até 3
                printf("\n------------------------Consultas------------------------\n");
                printf("\nnumero consulta: %d | dia: %d | cod_med: %d | cod_pac: %d | hora: %.2f",consulta[i].num_consulta, consulta[i].dia_semana, consulta[i].cod_medico, consulta[i].cod_paciente, consulta[i].hora);
                system("pause>>null");
            }
            break;
        default://PADRÃO DE OPÇÃO INVÁLIDA
            system("cls");
            puts("Digite uma opcao valida!!");
            puts("\n\nTecle enter para sair...");
            fflush(stdin);
            system("pause>>null");
        }
        system("cls");//limpa tela
    }
}
