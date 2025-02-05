#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel por cuidar das string
#include <stdbool.h> //biblioteca que manipula variáveis IF
					
int registro() // Função responsavel por cadastrar os usuários no sistema
{
	int laco=1;//criar o laco para poder gerar opcao de ir e voltar 
	for (laco=1;laco=1;)//for para repetir o laco do tipo inteiro 
	{
			
		//Inicio criação de variáveis/string
		char arquivo[40];
		char cpf[40]; //char representa um caractere do tipo texto
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		char resp[20]="sim";
		//Final da criação de variáveis/string
	
		printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
		scanf("%s", cpf); //%s refere-se a string
	
		strcpy(arquivo, cpf); // Responsavel por copiar o valores das string
	
		FILE *file; // Cria o arquivo
		file = fopen(arquivo, "w"); // abre o arquivo e o "w"cria um novo arquivo
		fprintf(file,cpf); // Salvo o valor da variável
		fclose(file); // Fecho o arquivo
		

		file = fopen(arquivo, "a"); //abre o arquivo, e o"a" atualiza o arquivo criado
		fprintf(file,"\n"); // Salva o valor da variável eo "\n" pula uma linha 
		fclose(file); // Fecha o arquivo
	
		printf("Digite o nomes a ser cadastrado: "); //Coletando informações do usuário
		scanf("%s",nome); //Scanf salva a opcao do usuário
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo 
		fprintf(file,nome); //Salva o valor da variável 
		fclose(file); // Fecha o arquivo 
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo criado 
		fprintf(file, "\n"); //Salva o valor da variável, "\n" pula uma linha
		fclose(file); //Fecha o arquivo 
	
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
		scanf("%s",sobrenome); //Scanf salva a opção do usuário
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo
		fprintf(file,sobrenome); //Salva o valor da variável 
		fclose(file); //Fecha o arquivo
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo
		fprintf(file, "\n"); //Salva o valor da variável, "\n" pula uma linha 
		fclose(file); //Fecha o arquivo
	
		printf("Digite o cargo a ser cadastrado: "); //Coletando irformações do usuário
		scanf("%s",cargo); //Scanf salva a opção do usuário 
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo
		fprintf(file,cargo); //Salva o valor da variável
		fclose(file);
	
		system("pause");
	
		int salvar =0; //criando variável do tipo inteiro com o nome "salvar"
		printf("\n\n\tOs dados cadastrados estão corretos?\n");
		printf("\t1 - Sim, os dados estão corretos.\n");//opcao mantém os dados salvos 
		printf("\t2 - Não, escreva os dados novamente.\n");//opcao exclui os dados recém criados 
		printf("\t3 - Cadastra outro usuário? \n");
		printf("\t4 - Voltar para o menu principal \n ");
		printf("\tSelecione uma opção:  ");
		scanf("%d", &salvar);//define o valor da variavel inteira salva &salvar é uma variável no laco que me permite criar varias opcoes 
		
		if(salvar==1)//se for a opcao 1 faca isso 
		{
			printf("\n\tOs dados foram salvos com sucesso.\n");
			printf("\tRetornando ao menu principal.\n\t");
			system("pause");
			break;//sai do laco retorna ao menu
		}
		else if (salvar==2) //se for 2 faça essa opcao 
		{
			remove(arquivo);
			printf("\n\tOs dados não foram salvos.\n\tReiniciando o registro\n\t");
			system("pause");
			system("cls");
		}
		else if (salvar==3)//cria um novo arquivo
		{
			printf("\n\tRedirecionando para cadastrar novo usuário!\n\t");
			system("pause");
			FILE *file;
			file = fopen(arquivo,"w");
			fprintf(file,cpf);
			fclose(file);
			system("cls");
		}
		else if (salvar==4)//volta para o menu 
		{
			printf("\n\tVoltando para o menu principal\n\t");
			system("pause");
			system("cls");
			break;
		}
		
		else //senao faça essa 
		{
			printf("\n\tOpção inválida, cadastro reiniciado.\n\n");
			system("pause");
		}
		
	}
	
}

int consultar() //Função responsavel por fazer consultas dos usuários
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguage
	
	char cpf[40];
	char conteudo[200]; //char conteudo[200] são as informações do usuário 
	
	printf("Digite o CPF a ser consultado: "); //Pesquisando informações no banco de dados 
	scanf("%s",cpf); //Salva o valor da variável
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo, e o "r" é para ler o arquivo 
	

	if(file == NULL) // Null significa nulo e serve para uma opção nao exixtente 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Mensagem ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //While significa enquanto 
	{
		printf("\nEssa são as informações do usuário: "); //Mensagem ao usuário
		printf("%s", conteudo); //Salva o valor da variável
		printf("\n\n"); //Diz para o sistema pular 2 linha
	}
	
	system("pause"); //Pausa o sistema até o usuário continuar 
	fclose(file); // caso não feche o arquivo nao sera possivel deletar

}
 void fechar() //void pode ser usado para a funcao exit
{
    printf("O programa será encerrado.\n");
    exit(0);//funcao que encerra o programa (0) importante ter o 0
}

int deletar() //Função responsavel por deletar usuários
{
	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: "); //Mensagem ao usuário
	scanf("%s",cpf); // CPF e o ponto chave do nosso cartório 
	 
	FILE *file; //Cria o arquivo 
	file = fopen(cpf,"r"); //Abre o arquivo, e o "r" é para ler o arquivo 
	fclose(file); // Obs: fechar arquivos
	
	if(file == NULL) // "E SE" o arquivo não for encontrado
	{
		printf("\nO usuário não se encontra no sistema!.\n"); //Mensagem ao usuário 
		system("pause"); //Pausa o sistema até o usuário continuar 
	}
	
	remove(cpf); // Opcao que apaga arquivos
	
	if(file != NULL) // != significa "se for diferente de a coloque b"
	{
		printf("\nO usuário foi deletado com sucesso!\n\n"); //Mensagem ao usuário
		system("pause"); //Pausa o sitema até o usuário continuar 
	}
	
}

int main() //Int main é a função principal do programa  
{ 
    int opcao=0; //Definindo variáveis
   	int laco=1; //Um laço de repetição 
   	char senhadigitada[]="a";
   	int comparacao;
   		
   	printf("### Cartório da EBAC ###\n\n");
   	printf("Login de administrador!\n\nDigite a sua senha: ");
   	scanf("%s",senhadigitada);	
   	
   	comparacao = strcmp(senhadigitada, "admin");
   	
   	if(comparacao ==0)
   	{
	   		system("cls");
   			for(laco=1;laco=1;) //for uma estrutura de repetição
   			{
	     
			system("cls"); //limpa a tela do usuário	                                                         
    	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
			printf("### Cartório da EBAC ###\n\n"); //Inicil do menu	
			printf("Escolha a opção desejada do menu:\n\n"); //Falando com o usuário
			printf("\t1 - Registrar nomes\n"); //\t Deixa uma paragrafo 
			printf("\t2 - Consultar nomes\n"); // Falando com usuário
			printf("\t3 - Deletar nomes\n"); //Fim do menu
			printf("\t4 - Fechar o programa\n\n");
			printf("Opção:");
	
			scanf("%d", &opcao); //Armezenando a escolha do usuário
	
			system("cls"); //Limpa a tela do usuário
	
			switch(opcao) //Switch é muito pratico, inicio da seleção do menu
			{
				case 1: //Diz ao switch oque ele deve fazer caso seja opção 1
				registro(); //Chamada de funções
				break;
			
				case 2:
				consultar();
    			break;
					
				case 3:
				deletar();
    			break;
    			
    			case 4:
    			fechar();
    			break;
				
 				default:		
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;	 
				//Fim da seleção
			
			}
		}
	}
	
else 
	printf("Senha incorreta!");
	

} 
	
	

