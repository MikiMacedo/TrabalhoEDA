#include <stdio.h>
#include "equipamentos.h"
#include "clientes.h"

int menu()
{int op;
 printf("M E N U\n");
 printf("1 Inserir Equipamento\n");
 printf("2 Alterar Equipamento\n");
 printf("3 Listar Equipamentos\n");
 printf("4 Listar Equipamento pela autonomia\n");
 printf("5 Listar Equipamento numa determinada localização\n");
 printf("6 Remover Equipamento\n");
 printf("7 Guardar Equipamento\n");
 printf("8 Ler Equipamentos\n");
 printf("0 Sair\n");
 printf("Opcao:\n");
 scanf("%d",&op);
 return(op);
}

int main()
{Equipamento* equipamentos = NULL; // Lista ligada vazia 
 int op, ideq;
 float bat, aut;
 char tipo[50], loc[50];
 do
 {
  op = menu();
  switch(op)
  {case 1: printf("Identificador?\n");
	   scanf("%d",&ideq);
	   scanf("%*c"); 
	   printf("Tipo\n");
	   scanf("%[^\n]s",tipo);
	   printf("Nivel da bateria?\n");
	   scanf("%f",&bat);
	   printf("Autonomia\n");
	   scanf("%f",&aut);
	   printf("Localização\n");
	   scanf("%s",&loc);
			equipamentos = inserirEquipamento(equipamentos,ideq,tipo,bat,aut,loc);
	   break;
   case 2: printf("Identificador do equipamento que quer alterar?\n");
		scanf("%d",&ideq);
		scanf("%*c"); 
		printf("Tipo\n");
		scanf("%[^\n]s",tipo);
		printf("Nivel da bateria?\n");
		scanf("%f",&bat);
		printf("Autonomia\n");
		scanf("%f",&aut);
		printf("Localização\n");
		scanf("%s",&loc);
			equipamentos = alterarEquipamento(equipamentos,ideq,tipo,bat,aut,loc);
		break;
   case 3: listarEquipamentos(equipamentos); break;
   case 4: listarEquipamentosautonomia(equipamentos); break;
   case 5: printf("Localização que pretende?\n");
		scanf("%s",&loc);
			listarEquipamentosLocaliza(equipamentos,loc);
		break;
   case 6: printf("Identificador do equipamento a remover?\n");
	   scanf("%d",&ideq);
	   equipamentos = removerEquipamento(equipamentos, ideq);
	   break;
   case 7: guardarEquipamento(equipamentos); break;
   case 8: equipamentos = lerEquipamentos(); break;
  }
 } while (op!=0);


 return(0);
}
