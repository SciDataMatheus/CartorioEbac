#include <stdio.h> //bilbioteca de comunica��o com o usuario
#include <stdlib.h>  //biblioteca de aloca��o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //fun��o responsavel por cadastrar usuarios no sistema
{
	//inicio de cria��o de variveis/string(conjunto de variveis)
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de variveis/string(conjunto de variveis)
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string, s� cria uma vez por ser o nome do arq.
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo, "w" siginifica escrever no arquivo aberto
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar e n�o criar um arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar e n�o criar um arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar e n�o criar um arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system ("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abrindo o txt CPF e l� o que t� l� dentro
	
	if (file == NULL) //se n�o existir o CPF
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto tem conteudo no arquivo, vai escrevendo, quando n�o achar ele sai.
	{
		printf("\nEssas s�o as informa��es do usu�rio\n\n");
		printf("%s", conteudo); //armazenar 
		printf("\n\n");
	}
	
	system("pause");
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do us�ario a ser deletado: ");
	scanf("%s", cpf); //%s ele vai varrer uma string digitada, vai salvar dentro da variavel cpf
	
	remove(cpf);
	
	FILE *file; //acessa a fun��o FILE e usa o parametro arquivo
	file = fopen(cpf, "r"); //fopen fun��o de abrir o arquivo (vai abrir o cpf e "r" e ler o arquivo
	
	if(file == NULL)
	{
		printf("o us�ario n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //int porque � inteiro, unica variavel que ser� usada, DEFININDO VARIAVEL
	int laco=1; //
	
	for(laco=1;laco=1;) //vai entrar na repeti��o quando x=1 e ficar repetindo enquanto x=1 , sem increm.
	{
		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); //Fim do Menu
		printf("Op��o: "); 
	
		scanf("%d", &opcao);// %d p/ armazenar variavel do tipo INT, &opcao p/ definir variavel
	
		system("cls");//comando para limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta(); 
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;	
		}//fim da sele��o
	
	}
}
