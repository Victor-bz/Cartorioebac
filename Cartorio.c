#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro()	// função para registro de alunos no banco de dados do programa
{
	// inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); // responsável por copiar valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); // salva o valor da variável 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" adiciona algo no arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()	// função para conulta de alunos no banco de dados do programa
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" serve para ler o que está no arquivo.

	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar() // função para deletar alunos no banco de dados do programa
{
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	remove(cpf);
	
	if(file == NULL)
	{
	printf("Usuário não se encontra no sistema!.\n");
	system("pause");
	}else 
	{
		printf("Usuário deletado com sucesso!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; // Definindo variáveis
	int x=1; // variavel laço
	
	for(x=1;x=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // inicio do menu 
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("Opção:"); // fim do menu 
	
		scanf("%d",&opcao); // Armazenando a escolha do usuário
	
		system("cls");// responsavel por limpar a tela

		switch(opcao)// inicio da seleção
		{
			case 1:
			registro();  	
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível\n");
    		system("pause");
    		break;
		}// final da seleção 
	}			
}
