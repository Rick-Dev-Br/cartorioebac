#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca responsavel por cuidar das string
#include <stdbool.h> //biblioteca que manipula vari�veis IF
					
int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	int laco=1;//criar o laco para poder gerar opcao de ir e voltar 
	for (laco=1;laco=1;)//for para repetir o laco do tipo inteiro 
	{
			
		//Inicio cria��o de vari�veis/string
		char arquivo[40];
		char cpf[40]; //char representa um caractere do tipo texto
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		char resp[20]="sim";
		//Final da cria��o de vari�veis/string
	
		printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
		scanf("%s", cpf); //%s refere-se a string
	
		strcpy(arquivo, cpf); // Responsavel por copiar o valores das string
	
		FILE *file; // Cria o arquivo
		file = fopen(arquivo, "w"); // abre o arquivo e o "w"cria um novo arquivo
		fprintf(file,cpf); // Salvo o valor da vari�vel
		fclose(file); // Fecho o arquivo
		

		file = fopen(arquivo, "a"); //abre o arquivo, e o"a" atualiza o arquivo criado
		fprintf(file,"\n"); // Salva o valor da vari�vel eo "\n" pula uma linha 
		fclose(file); // Fecha o arquivo
	
		printf("Digite o nomes a ser cadastrado: "); //Coletando informa��es do usu�rio
		scanf("%s",nome); //Scanf salva a opcao do usu�rio
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo 
		fprintf(file,nome); //Salva o valor da vari�vel 
		fclose(file); // Fecha o arquivo 
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo criado 
		fprintf(file, "\n"); //Salva o valor da vari�vel, "\n" pula uma linha
		fclose(file); //Fecha o arquivo 
	
		printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
		scanf("%s",sobrenome); //Scanf salva a op��o do usu�rio
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo
		fprintf(file,sobrenome); //Salva o valor da vari�vel 
		fclose(file); //Fecha o arquivo
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo
		fprintf(file, "\n"); //Salva o valor da vari�vel, "\n" pula uma linha 
		fclose(file); //Fecha o arquivo
	
		printf("Digite o cargo a ser cadastrado: "); //Coletando irforma��es do usu�rio
		scanf("%s",cargo); //Scanf salva a op��o do usu�rio 
	
		file = fopen(arquivo, "a"); //Abre o arquivo, e o "a" atualiza o arquivo
		fprintf(file,cargo); //Salva o valor da vari�vel
		fclose(file);
	
		system("pause");
	
		int salvar =0; //criando vari�vel do tipo inteiro com o nome "salvar"
		printf("\n\n\tOs dados cadastrados est�o corretos?\n");
		printf("\t1 - Sim, os dados est�o corretos.\n");//opcao mant�m os dados salvos 
		printf("\t2 - N�o, escreva os dados novamente.\n");//opcao exclui os dados rec�m criados 
		printf("\t3 - Cadastra outro usu�rio? \n");
		printf("\t4 - Voltar para o menu principal \n ");
		printf("\tSelecione uma op��o:  ");
		scanf("%d", &salvar);//define o valor da variavel inteira salva &salvar � uma vari�vel no laco que me permite criar varias opcoes 
		
		if(salvar==1)//se for a opcao 1 faca isso 
		{
			printf("\n\tOs dados foram salvos com sucesso.\n");
			printf("\tRetornando ao menu principal.\n\t");
			system("pause");
			break;//sai do laco retorna ao menu
		}
		else if (salvar==2) //se for 2 fa�a essa opcao 
		{
			remove(arquivo);
			printf("\n\tOs dados n�o foram salvos.\n\tReiniciando o registro\n\t");
			system("pause");
			system("cls");
		}
		else if (salvar==3)//cria um novo arquivo
		{
			printf("\n\tRedirecionando para cadastrar novo usu�rio!\n\t");
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
		
		else //senao fa�a essa 
		{
			printf("\n\tOp��o inv�lida, cadastro reiniciado.\n\n");
			system("pause");
		}
		
	}
	
}

int consultar() //Fun��o responsavel por fazer consultas dos usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguage
	
	char cpf[40];
	char conteudo[200]; //char conteudo[200] s�o as informa��es do usu�rio 
	
	printf("Digite o CPF a ser consultado: "); //Pesquisando informa��es no banco de dados 
	scanf("%s",cpf); //Salva o valor da vari�vel
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo, e o "r" � para ler o arquivo 
	

	if(file == NULL) // Null significa nulo e serve para uma op��o nao exixtente 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Mensagem ao usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL) //While significa enquanto 
	{
		printf("\nEssa s�o as informa��es do usu�rio: "); //Mensagem ao usu�rio
		printf("%s", conteudo); //Salva o valor da vari�vel
		printf("\n\n"); //Diz para o sistema pular 2 linha
	}
	
	system("pause"); //Pausa o sistema at� o usu�rio continuar 
	fclose(file); // caso n�o feche o arquivo nao sera possivel deletar

}
 void fechar() //void pode ser usado para a funcao exit
{
    printf("O programa ser� encerrado.\n");
    exit(0);//funcao que encerra o programa (0) importante ter o 0
}

int deletar() //Fun��o responsavel por deletar usu�rios
{
	char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado: "); //Mensagem ao usu�rio
	scanf("%s",cpf); // CPF e o ponto chave do nosso cart�rio 
	 
	FILE *file; //Cria o arquivo 
	file = fopen(cpf,"r"); //Abre o arquivo, e o "r" � para ler o arquivo 
	fclose(file); // Obs: fechar arquivos
	
	if(file == NULL) // "E SE" o arquivo n�o for encontrado
	{
		printf("\nO usu�rio n�o se encontra no sistema!.\n"); //Mensagem ao usu�rio 
		system("pause"); //Pausa o sistema at� o usu�rio continuar 
	}
	
	remove(cpf); // Opcao que apaga arquivos
	
	if(file != NULL) // != significa "se for diferente de a coloque b"
	{
		printf("\nO usu�rio foi deletado com sucesso!\n\n"); //Mensagem ao usu�rio
		system("pause"); //Pausa o sitema at� o usu�rio continuar 
	}
	
}

int main() //Int main � a fun��o principal do programa  
{ 
    int opcao=0; //Definindo vari�veis
   	int laco=1; //Um la�o de repeti��o 
   	char senhadigitada[]="a";
   	int comparacao;
   		
   	printf("### Cart�rio da EBAC ###\n\n");
   	printf("Login de administrador!\n\nDigite a sua senha: ");
   	scanf("%s",senhadigitada);	
   	
   	comparacao = strcmp(senhadigitada, "admin");
   	
   	if(comparacao ==0)
   	{
	   		system("cls");
   			for(laco=1;laco=1;) //for uma estrutura de repeti��o
   			{
	     
			system("cls"); //limpa a tela do usu�rio	                                                         
    	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
			printf("### Cart�rio da EBAC ###\n\n"); //Inicil do menu	
			printf("Escolha a op��o desejada do menu:\n\n"); //Falando com o usu�rio
			printf("\t1 - Registrar nomes\n"); //\t Deixa uma paragrafo 
			printf("\t2 - Consultar nomes\n"); // Falando com usu�rio
			printf("\t3 - Deletar nomes\n"); //Fim do menu
			printf("\t4 - Fechar o programa\n\n");
			printf("Op��o:");
	
			scanf("%d", &opcao); //Armezenando a escolha do usu�rio
	
			system("cls"); //Limpa a tela do usu�rio
	
			switch(opcao) //Switch � muito pratico, inicio da sele��o do menu
			{
				case 1: //Diz ao switch oque ele deve fazer caso seja op��o 1
				registro(); //Chamada de fun��es
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
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;	 
				//Fim da sele��o
			
			}
		}
	}
	
else 
	printf("Senha incorreta!");
	

} 
	
	

