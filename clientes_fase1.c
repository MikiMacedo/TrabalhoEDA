#include <stdio.h>
#include "clientes.h"

int menu()
{int op;
 printf("M E N U\n");
 printf("1 Inserir Cliente\n");
 printf("2 Alterar Cliente\n");
 printf("3 Listar Clientes\n");
 printf("4 Consultar Cliente\n");
 printf("5 Remover Cliente\n");
 printf("6 Guardar Clientes\n");
 printf("7 Ler Clientes\n");
 printf("8 Ler Alugueres\n");
 printf("9 Inserir Aluguer\n");
 printf("0 Sair\n");
 printf("Opcao:\n");
 scanf("%d",&op);
 return(op);
}

int main()
{Cliente* clientes = NULL; // Lista ligada vazia 
 Aluguer* alugueres = NULL;
 int op, idcl, nc, ideqal, idclal, temp;
 float sald, cost;
 char nom[50], mora[200];
 do
 {
  op = menu();
  switch(op)
  {case 1: printf("Identificador do Cliente?\n");
	   scanf("%d",&idcl);
	   scanf("%*c"); 
	   printf("Nome\n");
	   scanf("%[^\n]s",&nom);
	   printf("NIF?\n");
	   scanf("%d",&nc);
	   printf("Morada\n");
	   scanf("%[^\n]s",&mora);
	   printf("Saldo\n");
	   scanf("%f",&sald);
			clientes = inserirCliente(clientes,idcl,nom,nc,mora,sald);
	   break;
   case 2: printf("Identificador do cliente que quer alterar?\n");
	   scanf("%d",&idcl);
	   scanf("%*c"); 
	   printf("Nome\n");
	   scanf("%[^\n]s",&nom);
	   printf("NIF?\n");
	   scanf("%d",&nc);
	   printf("Morada\n");
	   scanf("%[^\n]s",&mora);
	   printf("Saldo\n");
	   scanf("%f",&sald);
			clientes = alterarCliente(clientes,idcl,nom,nc,mora,sald);
		break;
   case 3: listarClientes(clientes); break;
   case 4: printf("Identificador do Cliente a consultar?\n");
	   scanf("%d",&idcl);
	   consultarCliente(clientes, idcl);
	   break;
   case 5: printf("Identificador do Cliente a remover?\n");
	   scanf("%d",&idcl);
	   clientes = removerCliente(clientes, idcl);
	   break;
   case 6: guardarClientes(clientes); break;
   case 7: clientes = lerClientes(); break;
   case 8: alugueres = lerAlugueres(); break;
   case 9: printf("Identificador do Equipamento a ser alugado?\n");
	   scanf("%d",&ideqal);
	   printf("Identificador do Cliente que vai alugar?\n");
	   scanf("%d",&nc);
	   printf("Tempo de aluguer (em minutos)\n");
	   scanf("%d",&temp);
	   cost = temp * 0,1;
	   	alugueres = inserirAluguer(alugueres,ideqal,idclal,temp,cost);
		guardarAlugueres(alugueres);
	break;
  }
 } while (op!=0);


 return(0);
}
