#include <stdio.h> //bilbioteca de comunicação com o usuario
#include <stdlib.h>  //biblioteca de alocação de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //função responsavel por cadastrar usuarios no sistema
{
	//inicio de criação de variveis/string(conjunto de variveis)
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variveis/string(conjunto de variveis)
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string, só cria uma vez por ser o nome do arq.
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo, "w" siginifica escrever no arquivo aberto
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizar e não criar um arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar e não criar um arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizar e não criar um arquivo
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
	file = fopen(cpf, "r"); //abrindo o txt CPF e lê o que tá lá dentro
	
	if (file == NULL) //se não existir o CPF
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto tem conteudo no arquivo, vai escrevendo, quando não achar ele sai.
	{
		printf("\nEssas são as informações do usuário\n\n");
		printf("%s", conteudo); //armazenar 
		printf("\n\n");
	}
	
	system("pause");
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usúario a ser deletado: ");
	scanf("%s", cpf); //%s ele vai varrer uma string digitada, vai salvar dentro da variavel cpf
	
	remove(cpf);
	
	FILE *file; //acessa a função FILE e usa o parametro arquivo
	file = fopen(cpf, "r"); //fopen função de abrir o arquivo (vai abrir o cpf e "r" e ler o arquivo
	
	if(file == NULL)
	{
		printf("o usúario não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //int porque é inteiro, unica variavel que será usada, DEFININDO VARIAVEL
	int laco=1; //
	
	for(laco=1;laco=1;) //vai entrar na repetição quando x=1 e ficar repetindo enquanto x=1 , sem increm.
	{
		system("cls"); //responsavel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); //Fim do Menu
		printf("Opção: "); 
	
		scanf("%d", &opcao);// %d p/ armazenar variavel do tipo INT, &opcao p/ definir variavel
	
		system("cls");//comando para limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
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
			printf("Essa opção não está disponível\n");
			system("pause");
			break;	
		}//fim da seleção
	
	}
}
