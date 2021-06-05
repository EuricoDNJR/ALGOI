#include <stdio.h>
#include <stdlib.h>
#include <string.h>//Ulizei strcmp(Compara o conteúdo de duas strings), strlen(Determina o tamanho de uma string), strcpy(Realiza a cópia do conteúdo de uma variável a outra., strlwr(converte uma string para minuscula)
#include <ctype.h>//Serve para classificar caracteres ASCII, ou seja, para dizer se um dado byte representa uma letra, ou um dígito, ou um branco, etc. em código ASCII.
#include <windows.h>//Utilizei o sleep para dar alguns intervalos de tempo
#define cc 5//define o vetor da struct cliente
#define ff 5//define o vetor da struct funcionario
#define pp 5//define o vetor da struct produto
/////////////////////STRUCTS///////////////////////////
struct produto{
	char produto[200];
	char descproduto[500];
	char tipo[50];
	char marca[50];
	int quant;
	float precusto;
	float lucro;
	float prevenda;
}p[pp];

struct funcionario{
	char nome[200];
	char idade[20];
	char email[100];
	char cpf[20];
	char sexo[20];
	char endereco[100];
	char estado[4];
	char complemento[300];
	char cidade[100];
	char bairro[100];
	char estcivil[30];
	char ncasa[10];
	char celular[40];
	char cargo[100];
}f[ff];

struct cliente{
	char nome[200];
	char idade[20];
	char email[100];
	char cpf[20];
	char sexo[20];
	char endereco[100];
	char estado[4];
	char complemento[300];
	char cidade[100];
	char bairro[100];
	char estcivil[30];
	char ncasa[10];
	char celular[40];
}c[cc];
//////////////////////////////////////////////////////////////////////////////
int home();
int cdcliente(int i);
void bccliente();
void lscliente();
int cdfuncionario(int j);
void bcfuncionario();
void lsfuncionario();
int cadastroproduto(int k);
void esttotal();
void atuproduto();
void removercliente();
void estoqproduto();
void removerfunc();
void custluc();
//////////////////////////////////////////////////////////////////////////////
int main()
{
	int n,o,i=0,j=0,k=0,l;
	char m[5];
	system("color 7");
	system("cls");//limpa a tela
	do{
		system("cls");
	    o=home();//chama a funcao home(Menu Principal) a qual retorna um valor n
		switch(o){
			case 1:
				do{
				for(l=0;l<cc;l++){//Achar um numero com posição vazia
					if(strlen(c[l].nome)==0){//Se a quantidade de caracteres for 0
						i=l;//joga determinado indice a variavel i
						break;//i recebe o numero encontrado
					}
				}	
				i = cdcliente(i);//repassa esse numero pra funcao OBS: A MESMA LOGICA VALE PARA AS FPROXIMAS FUNCOES QUE RETORNAM
				printf("Deseja cadastrar mais? Utilize(Sim ou Nao) \n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);//Converteu para minuscula
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){//Se for diferente de sim e diferente de nao(diferente de 0(quando sao iguais)) 
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 2:
				do{
				bccliente();
				printf("Deseja buscar mais? Utilize(Sim ou Nao) \n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 3:
				do{
				lscliente();
				printf("Deseja listar mais? Utilize(Sim ou Nao) \n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 4:
				do{
				for(l=0;l<ff;l++){
					if(strlen(f[l].nome)==0){
						j=l;
						break;
					}
				}	
				j = cdfuncionario(j);
				printf("Deseja cadastrar mais? Utilize(Sim ou Nao) \n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 5:
				do{
				bcfuncionario();
				printf("Deseja buscar mais? Utilize(Sim ou Nao) \n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 6:
				do{
				lsfuncionario();
				printf("Deseja listar novamente? Utilize(Sim ou Nao) \n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 7:
				do{
				for(l=0;l<pp;l++){
					if(strlen(p[l].produto)==0){
						k=l;
						break;
					}
				}	
				k = cadastroproduto(k);
				printf("Deseja cadastrar mais? Utilize(Sim ou Nao) \n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 8:
				do{
				esttotal();
				printf("Deseja verificar novamente? Utilize(Sim ou Nao)\n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim") && strcmp(m,"nao")){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 9:
				do{
				atuproduto();
				printf("Deseja atualizar o estoque de outro produto? Utilize(Sim ou Nao)\n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 10:
				do{
				removercliente();
				printf("Deseja remover outro cliente? Utilize(Sim ou Nao)\n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 11:
				do{
				removerfunc();
				printf("Deseja remover outro funcionario? Utilize(Sim ou Nao)\n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 12:
				do{
				custluc();
				printf("Deseja ver novamente? Utilize(Sim ou Nao)\n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				}while(strcmp(m,"nao"));
				system("cls");
				break;
			case 13:
				printf("\n--------------------------------------------------\n");
				printf("\033[1;31mSISTEMA FINALIZADO COM SUCESSO!\033[0m\n");
				printf("--------------------------------------------------\n");
				Sleep(2000);
				system("cls");
				break;
		}
    n=o;
	}while(n!=13);//enquanto n for diferente de 13
    return 0;
}
////////////////////////////////////////////////////////////////////////////
int home(){//menu principal
	int n;
	printf("\033[1;31m ________\033[0m\n");
	printf("\033[1;31m|__BEM_VINDO___|\033[0m\n");
	printf("\033[1;31m|________|\033[0m\n");
	printf("\033[1;34m\nO que deseja fazer? Insira a opcao correspondente a lista abaixo:\033[0m\n");
	printf("\n 1-Cadastrar um novo cliente\n 2-Buscar informacoes de um cliente\n 3-Listar todos os clientes cadastrados\n 4-Cadastrar um funcionario\n 5-Buscar informacoes de um funcionario\n 6-Listar funcionarios\n 7-Cadastrar produto\n 8-Listar estoque total\n 9-Atualizar estoque de um produto\n 10-Apagar um cliente\n 11-Apagar um funcionario\n 12-Total\n 13-Sair\n");
    printf("\n____________\n");
    printf("\n");
	scanf("%d",&n);
    fflush(stdin);
    return n;
}
//////////////////////////////////////////////////////////////////////////
int cdcliente(int i){//cadastro de cliente
		int tamanho,j=0;
		system("cls");
		printf("\n---------------------------------------------------------\n");
		printf("_AREA DE CADASTRO DE CLIENTE");
		printf("\n---------------------------------------------------------\n");
		fflush(stdin);
		printf("----Insira o nome do cliente---- \n");
		scanf("%[^\n]s",c[i].nome);
		fflush(stdin);
		tamanho = strlen(c[i].nome);                                                              // A função isalpha decide se o argumento representa uma letra (maiúscula ou minúscula), retorna 0 para nao ou 1 para sim .
			if(tamanho<1 || tamanho>200 || isspace(c[i].nome[j])!=0 || isalpha(c[i].nome[j])==0){ // A função isspace verifica se tem espaços, retorna 0 para nao ou 1 para sim .
				do{                                                                               //O mesmo vale para ,as mesmas, utilizadas abaixo
				    printf("ESSE CAMPO NAO PODE ESTAR VAZIO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",c[i].nome);
					fflush(stdin);	
					tamanho = strlen(c[i].nome);   	   	
				}while(tamanho<1 || tamanho>200 || isspace(c[i].nome[j])!=0 || isalpha(c[i].nome[j])==0);
			}
			tamanho=0;
		printf("----Insira a idade do cliente---- \n");
		scanf("%[^\n]s",c[i].idade);
		fflush(stdin);
		tamanho = strlen(c[i].idade);
			if(tamanho<1 || tamanho>3 || isspace(c[i].idade[j])!=0 || isalpha(c[i].idade[j])!=0){
				do{
				    printf("ESSE CAMPO PODE TER NO MAXIMO 3 E NO MINIMO 1 ALGARISMO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",c[i].idade);
					fflush(stdin);	
					tamanho = strlen(c[i].idade);   	   	
				}while(tamanho<1 || tamanho>3 || isspace(c[i].idade[j])!=0 || isalpha(c[i].idade[j])!=0);
			}
			tamanho=0;
		printf("----Insira o email do cliente---- \n");
		scanf("%[^\n]s",c[i].email);
		fflush(stdin);
		printf("----Insira o cpf do cliente---- \n");
		scanf("%[^\n]s",c[i].cpf);
		fflush(stdin);
		tamanho = strlen(c[i].cpf);
			if(tamanho>11 || tamanho<11 || isspace(c[i].cpf[j])!=0 || isalpha(c[i].cpf[j])!=0){
				do{
				    printf("NAO POSSUI 11 DIGITOS! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",c[i].cpf);
					fflush(stdin);	
					tamanho = strlen(c[i].cpf);   	   	
				}while(tamanho!=11 || isspace(c[i].cpf[j])!=0 || isalpha(c[i].cpf[j])!=0);
			}
			tamanho=0;
		fflush(stdin);
	    printf("----Insira o sexo do cliente---- \n");
	    scanf("%[^\n]s",c[i].sexo);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 8 campos serem preenchidos!! \033[0m\n\n");
	    printf("----Insira o estado civil do cliente----(Ex: Casado(a), solteiro(a)...)----: \n");
	    scanf("%[^\n]s",c[i].estcivil);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 7 campos serem preenchidos!! \033[0m\n\n");
	    printf("-----Insira o celular/telefone do cliente-----\n");
	    scanf("%[^\n]s",c[i].celular);
	    fflush(stdin);
	    tamanho = strlen(c[i].celular);
			if(tamanho>11 || tamanho<11 || isspace(c[i].celular[j])!=0 || isalpha(c[i].celular[j])!=0){
				do{
				    printf("NAO POSSUI 11 DIGITOS! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",c[i].celular);
					fflush(stdin);	
					tamanho = strlen(c[i].celular);   	   	
				}while(tamanho!=11 || isspace(c[i].celular[j])!=0 || isalpha(c[i].celular[j])!=0);
			}
			tamanho=0;
	    printf("\n \033[1;34mFaltam 6 campos serem preenchidos!! \033[0m\n\n");
	    printf("-----Insira o estado do cliente(Utilize as siglas,ex:PI,RN,SP...)----- \n");
	    scanf("%[^\n]s",c[i].estado);
	    fflush(stdin);
	    tamanho = strlen(c[i].estado);
			if(tamanho>2 || tamanho<2 || isspace(c[i].estado[j])!=0 || isalpha(c[i].estado[j])==0){
				do{
				    printf("INSIRA APENAS A SIGLA! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",c[i].estado);
					fflush(stdin);	
					tamanho = strlen(c[i].estado);   	   	
				}while(tamanho!=2 || isspace(c[i].estado[j])!=0 || isalpha(c[i].estado[j])==0);
			}
			tamanho=0;
	    printf("\n \033[1;34mFaltam 5 campos serem preenchidos!! \033[0m\n\n");
	    printf("-----Insira a cidade do cliente----- \n");
	    scanf("%[^\n]s",c[i].cidade);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 4 campos serem preenchidos!! \033[0m\n\n");
		printf("-----Insira o endereco do cliente----- \n");
	    scanf("%[^\n]s",c[i].endereco);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 3 campos serem preenchidos!! \033[0m\n\n");
	    printf("-----Insira o bairro do cliente-----\n");
	    scanf("%[^\n]s",c[i].bairro);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 2 campos serem preenchidos!! \033[0m\n\n");
	    printf("-----Insira o numero da casa do cliente----- \n");
	    scanf("%[^\n]s",c[i].ncasa);
	    fflush(stdin);
	    tamanho = strlen(c[i].ncasa);
			if(tamanho<1 || tamanho>10 || isspace(c[i].ncasa[j])!=0 || isalpha(c[i].ncasa[j])!=0){
				do{
				    printf("INSIRA APENAS DIGITOS! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",c[i].ncasa);
					fflush(stdin);	
					tamanho = strlen(c[i].ncasa);   	   	
				}while(tamanho<1 || tamanho>10 || isspace(c[i].ncasa[j])!=0 || isalpha(c[i].ncasa[j])!=0);
			}
			tamanho=0;
	    printf("\n \033[1;34mFaltam 1 campo ser preenchido!! \033[0m\n\n");
	    printf("-----Insira o complemento da rua do cliente----- \n");
	    scanf("%[^\n]s",c[i].complemento);
	    printf("\n \033[1;34mProcessando\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    fflush(stdin);
	    fflush(stdin);
	    printf("\n-------------------------------------------------------\n");
	    printf("\033[1;34mNumero correspondente a este cliente: %d\033[0m\n",i);
	    printf("---------------------------------------------------------\n");
	    printf("\n");
	    return i;
}
////////////////////////////////////////////////////////////////////////////
void bccliente(){//buscar cliente
	int i;
		system("cls");
		printf("\n-----------------------------------------------------------\n");
		printf("_AREA DE BUSCA POR CLIENTE");
		printf("\n-----------------------------------------------------------\n");
		fflush(stdin);
		printf("Insira o \033[1;34mnumero\033[0m correspondente ao cliente: \n");
		scanf("%d",&i);
		if(strlen(c[i].nome)==0){
			printf("\033[1;31m--CLIENTE NÃO ENCONTRADO!\033[0m\n");
		}else{
		printf("Nome do cliente: %s\n",c[i].nome);
		printf("Idade do cliente: %s\n",c[i].idade);
		printf("Email do cliente: %s\n",c[i].email);
		printf("CPF do cliente: %s\n",c[i].cpf);
	    printf("Sexo do cliente: %s\n",c[i].sexo);
	    printf("Estado civil do cliente(Ex: Casado(a), solteiro(a)...): %s\n",c[i].estcivil);
	    printf("Celular/telefone do cliente: %s\n",c[i].celular);
	    printf("Estado : %s\n",c[i].estado);
	    printf("Cidade : %s\n",c[i].cidade);
		printf("Endereco : %s\n",c[i].endereco);
	    printf("Bairro : %s\n",c[i].bairro);
	    printf("Numero da casa do cliente: %s\n",c[i].ncasa);
	    printf("Complemento da rua do cliente: %s\n",c[i].complemento);
	    printf("\n");
		}
}
///////////////////////////////////////////////////////////////////////////
void lscliente(){//listar clientes
	int i,cont=0;
	system("cls");
		printf("\n----------------------------------------------------------\n");
		printf("_LISTAGEM DE CLIENTES");
		printf("\n----------------------------------------------------------\n");
	for(i=0;i<cc;i++){
		if(strlen(c[i].nome)==0){//Acha as posicoes,baseado no nome, que estao vazias OBS: A mesma logica vale para proximas acoes semelhantes
			cont+=1;
		}else{
		printf("\nCodigo: %d Cliente: %s\n\n",i,c[i].nome);
		}
	}
	if(cont==cc){
			printf("\033[1;31m--NENHUM CLIENTE CADASTRADO!\033[0m\n");
	}
	
}
//////////////////////////////////////////////////////////////////////////
int cdfuncionario(int j){//cadastrar funcionario
		int tamanho,i=0;
 		system("cls");
		printf("\n----------------------------------------------------------\n");
		printf("_AREA DE CADASTRO DE FUNCIONARIO");
		printf("\n----------------------------------------------------------\n");
		fflush(stdin);
		printf("Insira o nome do funcionario: \n");
		scanf("%[^\n]s",f[j].nome);
		fflush(stdin);
		tamanho = strlen(f[j].nome);
			if(tamanho<1 || tamanho>200 || isspace(f[j].nome[i])!=0 || isalpha(f[j].nome[i])==0){
				do{
				    printf("ESSE CAMPO NAO PODE ESTAR VAZIO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",f[j].nome);
					fflush(stdin);	
					tamanho = strlen(f[j].nome);   	   	
				}while(tamanho<1 || tamanho>200 || isspace(f[j].nome[i])!=0 || isalpha(f[j].nome[i])==0);
			}
			tamanho=0;
		printf("Insira a idade do funcionario: \n");
		scanf("%[^\n]s",f[j].idade);
		fflush(stdin);
		tamanho = strlen(f[j].idade);
			if(tamanho<1 || tamanho>3 || isspace(f[j].idade[i])!=0 || isalpha(f[j].idade[i])!=0){
				do{
				    printf("ESSE CAMPO PODE TER NO MAXIMO 3 E NO MINIMO 1 ALGARISMO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",f[j].idade);
					fflush(stdin);	
					tamanho = strlen(f[j].idade);   	   	
				}while(tamanho<1 || tamanho>3 || isspace(f[j].idade[i])!=0 || isalpha(f[j].idade[i])!=0);
			}
			tamanho=0;
		printf("Insira o email do funcionario: \n");
		scanf("%[^\n]s",f[j].email);
		fflush(stdin);
		printf("Insira o cpf do funcionario: \n");
		scanf("%[^\n]s",f[j].cpf);
		fflush(stdin);
		tamanho = strlen(f[j].cpf);
			if(tamanho>11 || tamanho<11 || isspace(f[j].cpf[i])!=0 || isalpha(f[j].cpf[i])!=0){
				do{
				    printf("NAO POSSUI 11 DIGITOS! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",f[j].cpf);
					fflush(stdin);	
					tamanho = strlen(f[j].cpf);   	   	
				}while(tamanho!=11 || isspace(f[j].cpf[i])!=0 || isalpha(f[j].cpf[i])!=0);
			}
			tamanho=0;
	    printf("Insira o sexo do funcionario: \n");
	    scanf("%[^\n]s",f[j].sexo);
	    fflush(stdin);
	    printf("Insira o estado civil do funcionario(Ex: Casado(a), solteiro(a)...): \n");
	    scanf("%[^\n]s",f[j].estcivil);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 8 campos serem preenchidos!! :) \033[0m\n\n");
	    printf("Insira o celular/telefone do funcionario: \n");
	    scanf("%[^\n]s",f[j].celular);
	    fflush(stdin);
	    tamanho = strlen(f[j].celular);
			if(tamanho>11 || tamanho<11 || isspace(f[j].celular[i])!=0 || isalpha(f[j].celular[i])!=0){
				do{
				    printf("NAO POSSUI 11 DIGITOS! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",f[j].celular);
					fflush(stdin);	
					tamanho = strlen(f[j].celular);   	   	
				}while(tamanho!=11 || isspace(f[j].celular[i])!=0 || isalpha(f[j].celular[i])!=0);
			}
			tamanho=0;
	    printf("\n \033[1;34mFaltam 7 campos serem preenchidos!! :) \033[0m\n\n");
	    printf("Insira o estado do funcionario(Utilize as siglas,ex:PI,RN,SP...): \n");
	    scanf("%[^\n]s",f[j].estado);
	    fflush(stdin);
	    tamanho = strlen(f[j].estado);
			if(tamanho>2 || tamanho<2 || isspace(f[j].estado[i])!=0 || isalpha(f[j].estado[i])==0){
				do{
				    printf("INSIRA APENAS A SIGLA! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",f[j].estado);
					fflush(stdin);	
					tamanho = strlen(f[j].estado);   	   	
				}while(tamanho!=2 || isspace(f[j].estado[i])!=0 || isalpha(f[j].estado[i])==0);
			}
			tamanho=0;
	    printf("\n \033[1;34mFaltam 6 campos serem preenchidos!! :) \033[0m\n\n");
	    printf("Insira a cidade do funcionario: \n");
	    scanf("%[^\n]s",f[j].cidade);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 5 campos serem preenchidos!! :) \033[0m\n\n");
		printf("Insira o endereco do funcionario: \n");
	    scanf("%[^\n]s",f[j].endereco);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 4 campos serem preenchidos!! :) \033[0m\n\n");
	    printf("Insira o bairro do funcionario: \n");
	    scanf("%[^\n]s",f[j].bairro);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 3 campos serem preenchidos!! :) \033[0m\n\n");
	    printf("Insira o numero da casa do funcionario: \n");
	    scanf("%[^\n]s",f[j].ncasa);
	    fflush(stdin);
	    tamanho = strlen(f[j].ncasa);
			if(tamanho<1 || tamanho>10 || isspace(f[j].ncasa[i])!=0 || isalpha(f[j].ncasa[i])!=0){
				do{
				    printf("INSIRA APENAS DIGITOS! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",f[j].ncasa);
					fflush(stdin);	
					tamanho = strlen(f[j].ncasa);   	   	
				}while(tamanho<1 || tamanho>10 || isspace(f[j].ncasa[i])!=0 || isalpha(f[j].ncasa[i])!=0);
			}
			tamanho=0;
	    printf("\n \033[1;34mFaltam 2 campos serem preenchidos!! :) \033[0m\n\n");
	    printf("Insira o complemento da rua do funcionario: \n");
	    scanf("%[^\n]s",f[j].complemento);
	    fflush(stdin);
	    printf("\n \033[1;34mFaltam 1 campo ser preenchido!! :) \033[0m\n\n");
	    printf("Insira o cargo do funcionario: \n");
	    scanf("%[^\n]s",f[j].cargo);
	    fflush(stdin);
	    tamanho = strlen(f[j].cargo);
			if(tamanho<1 || tamanho>100 || isspace(f[j].cargo[i])!=0 || isalpha(f[j].cargo[i])==0){
				do{
				    printf("ESSE CAMPO NAO PODE ESTAR VAZIO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",f[j].cargo);
					fflush(stdin);	
					tamanho = strlen(f[j].cargo);   	   	
				}while(tamanho<1 || tamanho>100 || isspace(f[j].cargo[i])!=0 || isalpha(f[j].cargo[i])==0);
			}
			tamanho=0;
	    printf("\n \033[1;34mProcessando\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
		fflush(stdin);
	    fflush(stdin);
	    printf("\n-------------------------------------------------------\n");
	    printf("\033[1;34mNumero correspondente a este funcionario: %d\033[0m\n",j);
	    printf("---------------------------------------------------------\n");
	    printf("\n");
		
	    return j;
}
/////////////////////////////////////////////////////////////////////////////
void bcfuncionario(){//buscar funcionario
	int i;
		system("cls");
		printf("\n--------------------------------------------------------\n");
		printf("_AREA DE BUSCA DE FUNCIONARIOS");
		printf("\n--------------------------------------------------------\n");
		printf("Insira o numero correspondente ao funcionario: \n");
		scanf("%d",&i);
		if(strlen(f[i].nome)==0){
			printf("\033[1;31m--FUNCIONARIO NÃO ENCONTRADO!\033[0m\n");
		}else{
		printf("Nome do funcionario: %s\n",f[i].nome);
		printf("Idade do funcionario: %s\n",f[i].idade);
		printf("Email do funcionario: %s\n",f[i].email);
		printf("CPF do funcionario: %s\n",f[i].cpf);
	    printf("Sexo do funcionario: %s\n",f[i].sexo);
	    printf("Estado civil do funcionario: %s\n",f[i].estcivil);
	    printf("Celular/telefone do funcionario: %s\n",f[i].celular);
	    printf("Estado : %s\n",f[i].estado);
	    printf("Cidade : %s\n",f[i].cidade);
		printf("Endereco : %s\n",f[i].endereco);
	    printf("Bairro : %s\n",f[i].bairro);
	    printf("Numero da casa do funcionario: %s\n",f[i].ncasa);
	    printf("Complemento da rua do funcionario: %s\n",f[i].complemento);
	    printf("Cargo do funcionario: %s\n",f[i].cargo);
	    printf("\n");
		}
}
//////////////////////////////////////////////////////////////////////////////
void lsfuncionario(){//listar funcionarios
	int i,cont=0;
		system("cls");
		printf("\n----------------------------------------------\n");
		printf("_LISTAGEM DE FUNCIONARIOS");
		printf("\n----------------------------------------------\n");
	for(i=0;i<ff;i++){
		if(strlen(f[i].nome)==0){
			cont+=1;
		}else{
		printf("Codigo: %d||Funcionario: %s||Cargo: %s\n\n",i,f[i].nome,f[i].cargo);
		}
	}
	if(cont==ff){
			printf("\033[1;31m--NENHUM FUNCIONARIO CADASTRADO!\033[0m\n");
	}
}
/////////////////////////////////////////////////////////////////////////////
int cadastroproduto(int k){//cadastro de produtos
		int tamanho=0,i=0;
		system("cls");
		printf("\n---------------------------------------------------------\n");
		printf("_AREA DE CADASTRO DE PRODUTOS");
		printf("\n---------------------------------------------------------\n");
		fflush(stdin);
		fflush(stdin);
		printf("-----Insira o produto(\033[1;34mEX: COMPUTADOR, GUARDA-ROUPA, GELADEIRA... \033[0m)----- \n");
		scanf("%[^\n]s",p[k].produto);
		fflush(stdin);
		tamanho = strlen(p[k].produto);
			if(tamanho<1 || tamanho>200 || isspace(p[k].produto[i])!=0 || isalpha(p[k].produto[i])==0){
				do{
				    printf("ESSE CAMPO NAO PODE ESTAR VAZIO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",p[k].produto);
					fflush(stdin);	
					tamanho = strlen(p[k].produto);   	   	
				}while(tamanho<1 || tamanho>200 || isspace(p[k].produto[i])!=0 || isalpha(p[k].produto[i])==0);
			}
			tamanho=0;
		printf("----Insira a marca do produto(\033[1;34mEX: LENOVO, MOTOROLA, SAMSUNG... \033[0m)----- \n");
	    scanf("%[^\n]s",p[k].marca);
	    fflush(stdin);
	    tamanho = strlen(p[k].marca);
			if(tamanho<1 || tamanho>200 || isspace(p[k].marca[i])!=0 || isalpha(p[k].marca[i])==0){
				do{
				    printf("ESSE CAMPO NAO PODE ESTAR VAZIO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",p[k].marca);
					fflush(stdin);	
					tamanho = strlen(p[k].marca);   	   	
				}while(tamanho<1 || tamanho>200 || isspace(p[k].marca[i])!=0 || isalpha(p[k].marca[i])==0);
			}
			tamanho=0;
		printf("-----Insira o tipo do produto(\033[1;34mEX: ELETRODOMESTICO, ELETRONICO, AUTOMOVEL... \033[0m)----- \n");
	    scanf("%[^\n]s",p[k].tipo);
	    fflush(stdin);
	    tamanho = strlen(p[k].tipo);
			if(tamanho<1 || tamanho>200 || isspace(p[k].tipo[i])!=0 || isalpha(p[k].tipo[i])==0){
				do{
				    printf("ESSE CAMPO NAO PODE ESTAR VAZIO! POR FAVOR INSIRA NOVAMENTE\n");
					scanf("%[^\n]s",p[k].tipo);
					fflush(stdin);	
					tamanho = strlen(p[k].tipo);   	   	
				}while(tamanho<1 || tamanho>200 || isspace(p[k].tipo[i])!=0 || isalpha(p[k].tipo[i])==0);
			}
			tamanho=0;
		printf("-----Insira a descricao do produto----- \n");
		scanf("%[^\n]s",p[k].descproduto);
		fflush(stdin);
	    printf("-----Insira a quantidade do produto----- \n");
	    scanf("%d",&p[k].quant);
	    fflush(stdin);
	    printf("-----Insira o preco de custo do produto(Unitario)(\033[1;34mQuanto lhe custou?\033[0m)-----\nR$ ");
	    scanf("%f",&p[k].precusto);
	    fflush(stdin);
	    printf("-----Insira o lucro(porcento) que pretende ganhar com a venda (\033[1;34mEx: 80 , 50, 45,5\033[0m))----- \n");
	    scanf("%f",&p[k].lucro);
	    fflush(stdin);
		p[k].prevenda = ((p[k].lucro/100)*p[k].precusto)+p[k].precusto;
		printf("Preco de venda(Unitario): R$ %.2f\n",p[k].prevenda);
		printf("Preco de venda(Total): R$ %.2f\n",(p[k].prevenda*p[k].quant));
		printf("Quantia de lucro(Unitario): R$ %.2f\n",(p[k].prevenda-p[k].precusto));
		printf("Quantia de lucro(Total): R$ %.2f\n",(p[k].prevenda*p[k].quant)-(p[k].precusto*p[k].quant));
	    printf("\n \033[1;34mProcessando\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    printf("\033[1;34m.\033[0m");
	    Sleep(250);
	    printf("\n-------------------------------------------------------\n");
	    printf("\033[1;34mNumero correspondente a este produto: %d\033[0m\n",k);
	    printf("---------------------------------------------------------\n");
	    printf("\n");
	    k++;
		
	    return k;
}
/////////////////////////////////////////////////////////////////////////////////////
void esttotal(){//Funcao para listagem de estoque
	int i,cont=0;
		system("cls");
		printf("\n_________\n");
		printf("|LISTAGEM DE ESTOQUE_|");
		printf("\n|________|\n");
	for(i=0;i<pp;i++){
		if(strlen(p[i].produto)==0){
			cont+=1;
		}else{
		printf("\n\nCodigo: %d || Tipo: %s|| Nome: %s|| Preco de Custo(Unitario): %.2f|| Preco de venda(Unitario): %.2f|| Preco de Custo(Total): %.2f|| Preco de Venda(Total): %.2f|| Em Estoque(Total): %d||\n\n",i,p[i].tipo,p[i].produto,p[i].precusto,p[i].prevenda,(p[i].precusto*p[i].quant),(p[i].prevenda*p[i].quant),p[i].quant);
		}
	}
	if(cont==pp){
			printf("\033[1;31m--NENHUM PRODUTO CADASTRADO!\033[0m\n");
	}
}
/////////////////////////////////////////////////////////////////////////////////////
void atuproduto(){//Atualização de produto
	int i,cont=0;
	char m[5];
				do{
				printf("Deseja ver o estoque de algum produto antes? Utilize(Sim ou Nao)\n");
				scanf("%s",m);
				fflush(stdin);
				strlwr(m);
				if(strcmp(m,"sim")!=0 && strcmp(m,"nao")!=0){
					do{
						printf("\033[1;31mConjunto de caracteres invalidos insira novamente--Utilize(Sim ou Nao)--\033[0m\n");
						scanf("%s",m);
						strlwr(m);
						cont++;
						if(strcmp(m,"sim")==0 && cont>0){//
						estoqproduto();
					}
					}while(strcmp(m,"sim") && strcmp(m,"nao"));
				}
				if(strcmp(m,"sim")==0 && cont==0){
						estoqproduto();
					}
				}while(strcmp(m,"nao"));
				
				
	printf("Insira o codigo do produto que deseja atualizar: \n");
	scanf("%d",&i);
	fflush(stdin);
	printf("-----Insira o produto(\033[1;34mEX: COMPUTADOR, GUARDA-ROUPA, GELADEIRA... \033[0m)----- \n");
		scanf("%[^\n]s",p[i].produto);
		fflush(stdin);
		printf("----Insira a marca do produto(\033[1;34mEX: LENOVO, MOTOROLA, SAMSUNG... \033[0m)----- \n");
	    scanf("%[^\n]s",p[i].marca);
	    fflush(stdin);
		printf("-----Insira o tipo do produto(\033[1;34mEX: ELETRODOMESTICO, ELETRONICO, AUTOMOVEL... \033[0m)----- \n");
	    scanf("%[^\n]s",p[i].tipo);
	    fflush(stdin);
		printf("-----Insira a descricao do produto----- \n");
		scanf("%[^\n]s",p[i].descproduto);
		fflush(stdin);
	    printf("-----Insira a quantidade do produto(\033[1;34mQUANTOS DESSE PRODUTO EXISTEM ATUALMENTE? \033[0m)----- \n");
	    scanf("%d",&p[i].quant);
	    fflush(stdin);
	    printf("-----Insira o preco de custo do produto(Unitario)(\033[1;34mQuanto lhe custou?\033[0m)-----\nR$ ");
	    scanf("%f",&p[i].precusto);
	    fflush(stdin);
	    printf("-----Insira o lucro(porcento) que pretende ganhar com a venda (Ex: 80 , 50, 45,5)----- \n");
	    scanf("%f",&p[i].lucro);
	    fflush(stdin);
		p[i].prevenda = ((p[i].lucro/100)*p[i].precusto)+p[i].precusto;
		printf("Preco de venda(Unitario): R$ %.2f\n",p[i].prevenda);
		printf("Preco de venda(Total): R$ %.2f\n",(p[i].prevenda*p[i].quant));
		printf("Quantia de lucro(Unitario): R$ %.2f\n",(p[i].prevenda-p[i].precusto));
		printf("Quantia de lucro(Total): R$ %.2f\n",(p[i].prevenda*p[i].quant)-(p[i].precusto*p[i].quant));
	    printf("\n \033[1;34mSalvando\033[0m");
	    Sleep(500);
	    printf("\033[1;34m.\033[0m");
	    Sleep(500);
	    printf("\033[1;34m.\033[0m");
	    Sleep(500);
	    printf("\033[1;34m.\033[0m\n");
	    Sleep(500);
}
///////////////////////////////////////////////////////////////////////////////////
void removercliente(){//remover cliente
	int i;
	system("cls");
		printf("\n-----------------------------------------------------------\n");
		printf("_AREA DE REMOCAO DE CLIENTE");
		printf("\n-----------------------------------------------------------\n");
		fflush(stdin);
	printf("Digite o codigo correspondente ao cliente que voce deseja remover: \n");
	scanf("%d",&i);
	strcpy(c[i].nome,"\0");//Joga(copia) \0 para para a string fazendo com que ela fique vazia
	strcpy(c[i].idade,"\0");
	strcpy(c[i].email,"\0");
	strcpy(c[i].cpf,"\0");
	strcpy(c[i].sexo,"\0");
	strcpy(c[i].estcivil,"\0");
	strcpy(c[i].celular,"\0");
	strcpy(c[i].estado,"\0");
	strcpy(c[i].cidade,"\0");
	strcpy(c[i].endereco,"\0");
	strcpy(c[i].bairro,"\0");
	strcpy(c[i].ncasa,"\0");
	strcpy(c[i].complemento,"\0");
	printf("\n--------------------------------------------------\n");
	printf("\033[1;31mCLIENTE REMOVIDO COM SUCESSO!\033[0m\n");
	printf("\n--------------------------------------------------\n");
	Sleep(1500);
	system("cls");	
}
/////////////////////////////////////////////////////////////////////////////////
void estoqproduto(){//estoque de um produto
	int i;
	system("cls");
	printf("---------Digite o codigo correspondente ao produto------------ \n");
	scanf("%d",&i);
	printf("Exibindo informacoes para codigo %d\n",i);
	Sleep(250);
    printf("\033[1;34m.\033[0m");
	Sleep(250);
    printf("\033[1;34m.\033[0m");
    Sleep(250);
    printf("\033[1;34m.\033[0m\n");
    Sleep(250);
	printf("\n\nCodigo: %d || Tipo: %s|| Nome: %s|| Preco de Custo(Unitario): %.2f|| Preco de venda(Unitario): %.2f|| Preco de Custo(Total): %.2f|| Preco de Venda(Total): %.2f|| Em Estoque(Total): %d||\n\n\n",i,p[i].tipo,p[i].produto,p[i].precusto,p[i].prevenda,(p[i].precusto*p[i].quant),(p[i].prevenda*p[i].quant),p[i].quant);
}
/////////////////////////////////////////////////////////////////////////////////
void removerfunc(){//remover funcionario
	int i;
	system("cls");
		printf("\n-----------------------------------------------------------\n");
		printf("_AREA DE REMOCAO DE FUNCIONARIO");
		printf("\n-----------------------------------------------------------\n");
		fflush(stdin);
	printf("Digite o codigo correspondente ao funcionario que voce deseja remover: \n");
	scanf("%d",&i);
	strcpy(f[i].nome,"\0");//Joga(copia) \0 para para a string fazendo com que ela fique vazia
	strcpy(f[i].idade,"\0");
	strcpy(f[i].email,"\0");
	strcpy(f[i].cpf,"\0");
	strcpy(f[i].sexo,"\0");
	strcpy(f[i].estcivil,"\0");
	strcpy(f[i].celular,"\0");
	strcpy(f[i].estado,"\0");
	strcpy(f[i].cidade,"\0");
	strcpy(f[i].endereco,"\0");
	strcpy(f[i].bairro,"\0");
	strcpy(f[i].ncasa,"\0");
	strcpy(f[i].complemento,"\0");
	strcpy(f[i].cargo,"\0");
	printf("\n--------------------------------------------------\n");
	printf("\033[1;31mFUNCIONARIO REMOVIDO COM SUCESSO!\033[0m\n");
	printf("\n--------------------------------------------------\n");
	Sleep(1500);
	system("cls");	
}
void custluc(){//funcao total
	int i,tp=0,tf=0,tc=0;
	float pc=0,lc=0,valorvenda=0;
	system("cls");
	for(i=0;i<pp;i++){
		valorvenda+=(p[i].prevenda*p[i].quant);
		pc+=(p[i].precusto*p[i].quant);
		lc+=(p[i].prevenda*p[i].quant)-(p[i].precusto*p[i].quant);
		if(strlen(p[i].produto)!=0){//acha as posicoes q nao estao vazias
		tp+=1;
		}
	}
	for(i=0;i<cc;i++){
		if(strlen(c[i].nome)!=0){
		tc+=1;
		}
	}
	for(i=0;i<cc;i++){
		if(strlen(f[i].nome)!=0){
		tf+=1;
		}
	}
	printf("\n-------------------------------------------------------\n");
    printf("\033[1;34mTOTAL\033[0m\n");
    printf("---------------------------------------------------------\n");
    printf("\n\n");
	printf("-------------------------FINANCEIRO----------------------\n");
    printf("---------------------------------------------------------\n");
    printf("TOTAL DE GASTOS: R$ %.2f\n",pc);
    printf("---------------------------------------------------------\n");
    printf("TOTAL DE VENDA(PREVISTO): R$ %.2f\n",valorvenda);
    printf("---------------------------------------------------------\n");
    printf("TOTAL DE LUCRO(PREVISTO): R$ %.2f\n",lc);
    printf("---------------------------------------------------------\n");
    printf("-------------------------CADASTROS-----------------------\n"); 
    printf("---------------------------------------------------------\n");
    printf("TOTAL DE FUNCIONARIOS: %d\n",tf);
    printf("---------------------------------------------------------\n");
    printf("TOTAL DE CLIENTES: %d\n",tc);
    printf("---------------------------------------------------------\n");
    printf("TOTAL DE PRODUTOS: %d\n",tp);
    printf("---------------------------------------------------------\n");
}