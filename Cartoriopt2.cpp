#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espe�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca resposavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/strings
	
	printf("digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s pertence as strings
	
	strcpy(arquivo, cpf); // responavel por criar os valores das string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abrir o arquivo e atualizar
	fprintf(file,","); // salvar a variavel
	fclose(file); //fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file =fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
	
	file =fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file =fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}



int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o se encontra nos sitema!.\n");
		system("pause");
	}
	
	
	
}

int main()
{

		int opcao=0; //definindo vari�veis
		int laco=1;
		
		for(laco=1;laco=1;)
		{
	
		 system("cls");
		 
		 setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		 printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	 	printf("Escolha a op��o desejada do Menu: \n\n");
	 	printf("\t1 - Registrar Nomes\n");
	 	printf("\t2 - Consultar Nomes\n");
	 	printf("\t3 - Deletar Nomes\n\n");
	 	printf("opcao "); //fim do menu
	
	 	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	 
	 	system("cls"); //responsavel por limpar a tela
	 
	 	switch (opcao) //inicio da sele��o do menu
			{
			case 1:
			registro(); //chamada de fun��es
			break;
				
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			}
	
		}
	}
