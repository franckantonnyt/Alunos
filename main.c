#include <stdio.h>
#include <stdlib.h>
#define MAX 45
/*Gerenciador de Disciplina:
-Criação de Lista(Estatica de 45 posições)
-Adicionar Aluno
-Remover Aluno
-Buscar Aluno(Matricula,nome,posição)
-verificar se oaluno esta aprovado
-trazer qts aluno aprovados/reprovados e Média da Sala(Aprovado >= 60)
-Lista todos Alunos com soma total das notas.
*/
typedef struct{
	int matricula;
	char nome[30];
	float nota;	
}Alunos;
Alunos *nota;
//Menu
int menu(){
	int op = 0;
	do{
		printf("1 - Adicionar Aluno\n2 - Remover Aluno\n3 - Buscar Aluno\n4 - Verificar se o Aluno esta aprovado\n5 - Quantidade de Alunos Aprovados e Reprovados e Media da Sala\n6 - Listar Alunos e Soma total das notas\n7 - Sair\n");
		scanf("%i",&op);
		if(op < 1 || op > 7)
		{
			printf("Opçao Invalida\n");
		}
		system("pause");
		system("cls");
	}while(op != 7);
	return op;
}
//adicionar aluno
int main(int argc, char *argv[]) {
	int op,op1,i=0,x,matricula,j=0,qtd_a=0,qtd_r=0;
	float media = 0;
	char nome[30];
	nota = (Alunos*) calloc(MAX,sizeof(Alunos));
	do
	{
	op = menu();
	switch (op){
	 case 1:
	 	printf("- Adicionar Aluno -\nNome - ");
	 	scanf(" %[^\n]s", nota[i].nome);
	 	printf("Matricula - ");
	 	scanf("%i",&nota[i].matricula);
	 	printf("Nota - ");
	 	scanf("%f",&nota[i].nota);
	 	i++;
	 	break;
	 case 2:
	 	printf("- Remover Aluno -");
	 	printf("Digite a Matricula do aluno");
	 	scanf("%i",&matricula);
	 	for(x = 0; x < i; x++)
	 	{
	 		if(matricula != nota[x].matricula)
			 {
			 	nota[j].matricula = nota[x].matricula;
			 	strcpy(nota[i].nome,nota[x].nome);
			 	nota[j].nota = nota[x].nota;
			 	j++;
			 }	
		}
		break;
	 case 3:
	 	printf("1 - Matricula\n2 - Nome\n3 - Posicao\n");
	 	scanf("%i",&op1);
	 	switch (op1){
	 		case 1:
	 			printf("- Matricula -\n");
	 			printf("Matricula - ");
	 			scanf("%i",matricula);
	 			for(x = 0; x < i; x++)
	 			{
	 				if(matricula == nota[x].matricula)
					{	
						printf("- Aluno - \nNome - %s\n",nota[x].nome);
						printf("Matricula - %i\n",nota[x].matricula);
						printf("Nota - %i\n",nota[x].nota);
						break;
				 	}		
				}
	 			break;
	 		case 2:
	 			printf("- Nome -\n");
	 			printf("Nome - ");
	 			scanf(" %[^\n]s", nome);
	 			for(x = 0; x < i; x++)
	 			{
	 				if(strcmp(nome,nota[x].nome) == 0)
					{	
						printf("- Aluno - \nNome - %s\n",nota[x].nome);
						printf("Matricula - %i\n",nota[x].matricula);
						printf("Nota - %i\n",nota[x].nota);
						break;
				 	}		
				}
	 			break;
	 		case 3:
	 			printf("- Posicao -\n");
	 			printf("Posicao - ");
	 			scanf("%i",matricula);
	 			printf("- Aluno - \nNome - %s\n",nota[matricula].nome);
				printf("Matricula - %i\n",nota[matricula].matricula);
				printf("Nota - %i\n",nota[matricula].nota);
	 			break;
		 }
	 	break;
	 case 4:
	 	printf("- Matricula -\n");
	 	printf("Matricula - ");
	 	scanf("%i",matricula);
	 	for(x = 0; x < i; x++)
	 	{
	 		if(matricula == nota[x].matricula)
			{	
				printf("- Aluno - \nNome - %s\n",nota[x].nome);
				printf("Matricula - %i\n",nota[x].matricula);
				printf("Nota - %i\n",nota[x].nota);
				if(nota[x].nota >= 60)
				{
					printf("Aluno esta Aprovado!");
				}else
				{
					printf("Aluno esta reprovado!");
				}
				break;
			}		
		}
	 	break;
	 case 5:
	 	for(x = 0; x < i; x++)
	 	{
	 		if(nota[x].nota >= 60)
	 		{
	 			qtd_a++;
			}else
			{
				qtd_r++;
			}
			media = media + nota[x].nota;
		}
		media = media / x;
		printf("Quantidade de Aprovados - %i\n",qtd_a);
		printf("Quantidade de Reprovados - %i\n",qtd_r);
		printf("Media - %f \n",media);
	 	break;
	 case 6:
	 	printf("Nome | Matricula | Nota \n");
	 	media = 0;
		for(x = 0; x < i; x++)
	 	{
	 		printf("%s | %i | %f \n",nota[x].nome,nota[x].matricula,nota[x].nota);
			media = media + nota[x].nota;	
		}
		printf("Soma das Notas - %f",media);
	 	break;
	}
	}while(op != 7);
	free(nota);
	return 0;
}
