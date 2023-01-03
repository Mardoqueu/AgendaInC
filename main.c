#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct agenda{
	char nome[50];
	unsigned long int telefone_1, telefone_2;
	struct agenda* prox;
}Agenda;

Agenda* adicionar_contato (Agenda* primeiro);
void lista_contato (Agenda* primeiro);
Agenda* excluir_contato (Agenda* primeiro);
void alterar_contato (Agenda* primeiro);

main()
{
// Declração de variáveis

Agenda *primeiro= NULL;
char opcao;

//Repetir o programa.

while (opcao != 'e'){

//Menu de opções


    printf("      _____________________________________\n");
    printf("     |_____________________________________|\n\n");
    printf("                  |---AGENDA---|");
    printf("    \n      _____________________________________\n");
    printf("     |_____________________________________|\n\n");
    printf("      |A................Adicionar Contato|\n");
    printf("      |B................Lista de Contatos|\n");
    printf("      |C..................Excluir Contato|\n");
    printf("      |D...................Editar contato|\n");
    printf("      |E.............................Exit|\n");
    printf("      _____________________________________\n");
    printf("     |_____________________________________|\n\n");
// Leitura de opção

fflush (stdin);
    printf("  _______\n");
    printf(" |_______: ");
    opcao= getch();

//Menu de opções

switch (opcao)
		{
		case 'A':
		case 'a':
            fflush (stdin);
            system ("cls");
            printf("  ___________________________________\n");
            printf(" |___________________________________|\n\n");
            printf("          |---Novo Contato---|");
            printf("\n  ___________________________________\n");
            printf(" |___________________________________|\n\n");
            primeiro= adicionar_contato(primeiro);
            getch();
            system("cls");
            break;

        case 'B':
        case 'b':
        //Listando os restaurantes.
        system("cls");
            printf("  ___________________________________\n");
            printf(" |___________________________________|\n\n");
            printf("        |---Lista de Contatos---|");
            printf("\n  ___________________________________\n");
            printf(" |___________________________________|\n\n");
            lista_contato(primeiro);
        getch();
        system("cls");
        break;

        case 'C':
        case 'c':
            //Opção para excuir contatos.
            system("cls");
                printf("  ___________________________________\n");
                printf(" |___________________________________|\n\n");
                printf("        |---Excluir Contato---|");
                printf("\n  ___________________________________\n");
                printf(" |___________________________________|\n\n");
                primeiro= excluir_contato(primeiro);
            getch();
            system("cls");
            break;

        case 'D':
        case 'd':
            //Opção para excuir contatos.
            system("cls");
                printf("  ___________________________________\n");
                printf(" |___________________________________|\n\n");
                printf("        |---Alterar Contato---|");
                printf("\n  ___________________________________\n");
                printf(" |___________________________________|\n\n");
                alterar_contato(primeiro);
            getch();
            system("cls");
            break;

        case 'E':
        case 'e':
            opcao='e';
            break;

        default:
            system("cls");
            break;
		}
	}
}

Agenda* adicionar_contato(Agenda *primeiro){

Agenda contato;
Agenda *atual= primeiro;
char indentificador= 'F';

//Ler informações do cadastro.

printf(" Nome: ");
fflush(stdin); fgets(contato.nome, 40, stdin); printf("\n");

printf(" Telefone I: ");
scanf("%u",&contato.telefone_1);printf ("\n");

printf(" Telefone II: ");
scanf("%u",&contato.telefone_2);printf ("\n");

for (atual=primeiro; atual!=NULL; atual=atual-> prox){
    if (atual->telefone_1 == contato.telefone_1){
        indentificador= 'V';
        break;
    }
}

for (atual=primeiro; atual!=NULL; atual=atual-> prox){
    if (atual->telefone_2 == contato.telefone_2){
        indentificador= 'V';
        break;
    }
}

if (indentificador!='V' && (strlen(contato.nome) != 1)){
        //Alocando os espaços e guardando as informações do contato
        Agenda* novocontato=(Agenda*) malloc (sizeof(Agenda));
        strcpy(novocontato->nome, contato.nome);
        novocontato->telefone_1=contato.telefone_1;
        novocontato->telefone_2=contato.telefone_2;
        novocontato->prox= primeiro;
        printf("Concluido");
        printf("\n\nPressione qualquer tecla para voltar ao menu.\n\n");
        return novocontato;
        }else{
        printf("Cadastro inv%clido.", 160);
        printf("\n\nPressione qualquer tecla para voltar ao menu.\n\n");
        return primeiro;
        }
}

void lista_contato (Agenda* primeiro){
Agenda* atual;//Ponteiro para percorrer a lsta sem perder a referência do primeiro elemento da lista.

//Imprimindo os contatos.
for (atual= primeiro; atual != NULL; atual= atual->prox){
    printf("\n Nome: ");
    printf("%s", atual->nome);
    printf("\n Telefone I: ", 162);
    printf("%u", atual->telefone_1);
    printf("\n Telefone II: ", 162);
    printf("%u", atual->telefone_2);
    printf("\n\n");
    }

    if (primeiro==NULL)
        printf(" Nenhum contato adicionado");
    printf("\n\n Pressione qualquer tecla para voltar para o menu.");

}


Agenda* excluir_contato(Agenda *primeiro){
    Agenda *anterior= NULL; //Ponteiro para saber o elemento anterior e atual da lista.
    Agenda *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemnto da lista;
    unsigned long int telefone_1=0, telefone_2=0;
    int escolher;

    printf("\n\nEscolha o contato que dejesa procurar: ");
    printf ("\n|Telefone...............1|");
    printf("\n |Telefone...............2|");
    printf("\n\n");
    printf("  _______\n");
    printf(" |_______: ");
    scanf("%d", &escolher);
    if (escolher == 1){
            //Requerindo e lendo número de telefone para ser excluído.
            printf("Digite o telefone I: ");
            fflush(stdin);
            scanf("%u", &telefone_1);

            //Procurar o telefone.
            while (atual != NULL && atual->telefone_1!=telefone_1){
                anterior= atual;
                atual= atual->prox;
            }


        //Mensagem caso o número seja inexistente.
        if (atual==NULL){
            printf("\n Telefone inexistente");
            printf("\n\n Pressione qualquer tecla para voltar to o menu.");
            return primeiro;
        }
        //Exluindo o primeiro telefone dos contatos.
        if (anterior==NULL){
            printf("Contato excluido com sucesso.");
            primeiro= atual->prox;
            //Excluindo nome do meio da lista.
        }else{
            printf("\n Contato exluido");
            primeiro= atual->prox;
            }

            //Descalocando o espaço.
            free(atual);
            printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
            return primeiro;


    }else if (escolher == 2){
           //Requerindo e lendo número de telefone para ser excluído.
            printf("Digite o telefone I: ");
            fflush(stdin);
            scanf("%u", &telefone_2);

            //Procurar o telefone.
            while (atual != NULL && atual->telefone_2!=telefone_2){
                anterior= atual;
                atual= atual->prox;
            }


        //Mensagem caso o número seja inexistente.
        if (atual==NULL){
            printf("\n Telefone inexistente");
            printf("\n\n Pressione qualquer tecla para voltar to o menu.");
            return primeiro;
        }
        //Exluindo o primeiro telefone dos contatos.
        if (anterior==NULL){
            printf("Contato excluido com sucesso.");
            primeiro= atual->prox;
            //Excluindo nome do meio da lista.
        }else{
            printf("\n Contato exluido");
            primeiro= atual->prox;
            }

            //Descalocando o espaço.
            free(atual);
            printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
            return primeiro;
    }else{
    printf("\n\nTelefone Inexistente");
            free(atual);
            printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
            return primeiro;
    }
}

void alterar_contato(Agenda* primeiro){
char nome_substituto[50];
unsigned long int telefone_1, telefone_2;
Agenda* atual=primeiro;
int escolher;

//lendo o telefone

printf("\n\nEscolha o contato que dejesa editar: ");
    printf("\n| Telefone...............1 |");
    printf("\n| Telefone...............2 |");
    printf("\n\n");
    printf("  _______\n");
    printf(" |_______: ");
    scanf("%d", &escolher);


    if (escolher == 1){
        printf("Digite o telefone I que deseja alterar o nome: ");
        fflush(stdin);
        scanf("%u", &telefone_1);

        //Procurar
        while (atual != NULL && atual->telefone_1!=telefone_1){
            atual=atual->prox;
        }
        //Alterando os dados
        if (atual != NULL){
            printf("\n Novo nome: ");
            fflush(stdin); fgets(nome_substituto, 40, stdin);
            strcpy(atual->nome, nome_substituto);
            //---------------------------------------

        }else{
            printf("\n Contato inexistente");
        }
        printf("\n\n\n Pressione qulquer tecla para voltar ao menu");

    }else if (escolher == 2){

        printf("Digite o telefone I que deseja alterar o nome");
        fflush(stdin);
        scanf("%u", &telefone_2);

        //Procurar
        while (atual != NULL && atual->telefone_2!=telefone_2){
            atual=atual->prox;
        }
        //Alterando os dados
        if (atual != NULL){
            printf("\n Novo nome: ");
            fflush(stdin); fgets(nome_substituto, 40, stdin);
            strcpy(atual->nome, nome_substituto);
            printf("\nNome auterado com sucesso");
        }else{
            printf("\n Contato inexistente");
        }
        printf("\n\n\n Pressione qulquer tecla para voltar ao menu");

    }else{
    printf("\n\nTelefone Inexistente");
            free(atual);
            printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
            return primeiro;
    }
}