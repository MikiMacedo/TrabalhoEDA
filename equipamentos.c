/*
* author: Miguel António Costa Macedo
* email: a26046@alunos.ipca.pt
* date: 15-03-2023
* desc: Trabalho Prático
* vers: Fase 1 - Equipamentos
--------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include "equipamentos.h"

int tamanho(Equipamento* inicio) //Tamanho da lista ligada
{Equipamento* aux = inicio;
 int contador = 0;
 while (aux != NULL)
 {contador++;
  aux = aux->seguinteq; // transitar para o registo seguinte
 }
 return(contador);
}

// Inserção de um novo registo no fim
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Equipamento* inserirFim(Equipamento* inicio, int ideq, char tip[], float bat, float aut, char loc[])
{Equipamento* novo = malloc(sizeof(struct registoeq));
 Equipamento* aux = inicio;
 if (novo!=NULL)
 {novo->idequipamento = ideq;
  strcpy(novo->tipo,tip);
  novo->bateria = bat;
  novo->autonomia = aut;
  strcpy(novo->localiza,loc);
  novo->seguinteq = NULL;
  if (aux==NULL) return(novo);
  else {while (aux->seguinteq!=NULL) aux = aux->seguinteq;
        aux->seguinteq = novo; 
	  // inserção do novo registo na última posição da lista
        return(inicio);
       }
 }
 else return(inicio);
}

// Função recursiva para a inserção de um novo registo no fim da lista ligada
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Equipamento* inserirFimRec(Equipamento* inicio, int ideq, char tip[], float bat, float aut, char loc[])
{if (inicio==NULL) 
	return(inserirEquipamento(NULL,ideq,tip,bat,aut,loc)); // inserção no início
 else {inicio->seguinteq=inserirFimRec(inicio->seguinteq,ideq,tip,bat,aut,loc);
       return(inicio);
      }
}

int removerTodos(Equipamento* inicio) // remover todos os registos da lista ligada
{Equipamento* aux;
 while (inicio!=NULL)
 {aux = inicio->seguinteq;
  free(inicio);
  inicio = aux;
 }
}

Equipamento* consultarEq(Equipamento* inicio, int ideq) // consultar registo a partir do código
{
 while(inicio!=NULL)
 {if (inicio->idequipamento==ideq) return(inicio);
  inicio=inicio->seguinteq;
 }
 return(NULL);
}

float mediaAutonomia(Equipamento* inicio) // cálculo da autonomia média
{int soma=0, quantidade=0;
 while(inicio!=NULL)
 {soma += inicio->autonomia;
  quantidade++;
  inicio = inicio->seguinteq;
 }
 if (quantidade!=0) return(soma/quantidade);
 else return(-1);
}

Equipamento* copiaListaLigada(Equipamento* inicio) // Criar uma cópia da lista ligada
{Equipamento* copia=NULL;
 while(inicio!=NULL)
 {copia = inserirFim(copia, inicio->idequipamento, 
		     inicio->tipo, inicio->bateria, inicio->autonomia, inicio->localiza);
  inicio = inicio->seguinteq;
 }
 return(copia);
}

int guardarEquipamentos(Equipamento* inicio)
{FILE* fp;
 fp = fopen("equipamentos.txt","w");
 if (fp!=NULL)
 {
 Equipamento* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%f;%f;%[^\n]s;%[^\n]s\n", aux->idequipamento, aux->bateria, 
	                      aux->autonomia, aux->tipo, aux->localiza);
  aux = aux->seguinteq;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Equipamento* lerEquipamentos()
{FILE* fp;
 int ideq;
 float bat, aut;
 char loc[50], tip[50];
 Equipamento* aux=NULL;
 fp = fopen("equipamentos.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%f;%f;%[^\n]s;%[^\n]s\n", &ideq, &bat, &aut, &tip, &loc);
    aux = inserirEquipamento(aux, ideq, tip, bat, aut, loc);
  }
  fclose(fp);
 }
 return(aux);
}

// Inserção de um novo registo
Equipamento* inserirEquipamento(Equipamento * inicio, int ideq, char tip[], float bat, float aut, char loc[])
{
 if (!existeEquipamento(inicio, ideq))
 {Equipamento * novo = malloc(sizeof(struct registoeq));
  if (novo != NULL)
  {novo->idequipamento = ideq;
   strcpy(novo->tipo,tip);
   novo->bateria = bat;
   novo->autonomia = aut;
   strcpy(novo->localiza,loc);
   novo->seguinteq = inicio;
   return(novo);
  }
 } else return(inicio);
}

// listar na consola o conteúdo da lista ligada
void listarEquipamentos(Equipamento * inicio)
{while (inicio != NULL)
 {printf("%d %s %.2f %.2f\n",inicio->idequipamento,inicio->tipo, 
		             inicio->bateria, inicio->autonomia, inicio->localiza);
  inicio = inicio->seguinteq;
 }
}

// Determinar existência do 'identificador' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeEquipamento(Equipamento* inicio, int ideq)
{while(inicio!=NULL)
  {if (inicio->idequipamento == ideq) return(1);
   inicio = inicio->seguinteq;
  }
 return(0);
}


// Remover um equipamento a partir do seu identificador 
Equipamento* removerEquipamento(Equipamento* inicio, int ideq) 
{
 Equipamento *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->idequipamento == ideq) // remoção do 1º registo
 {aux = atual->seguinteq;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->idequipamento!=ideq)) 
  {anterior = atual;
   atual = atual->seguinteq;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinteq = atual->seguinteq;
   free(atual);
   return(inicio);
  }
 }
}

// Alterar um Equipamento a partir do seu identificador
Equipamento* alterarEquipamento(Equipamento* inicio, int ideq, char tip[], float bat, float aut, char loc[])
{
 Equipamento *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->idequipamento == ideq) // alterar o 1º registo
 {aux = atual->seguinteq;
  {atual->idequipamento = ideq;
   strcpy(atual->tipo,tip);
   atual->bateria = bat;
   atual->autonomia = aut;
   strcpy(atual->localiza,loc);
   atual->seguinteq = inicio;
   return(aux);
  }
 }
 else
 {while ((atual!=NULL)&&(atual->idequipamento!=ideq)) 
  {anterior = atual;
   atual = atual->seguinteq;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinteq = atual->seguinteq;
  {atual->idequipamento = ideq;
   strcpy(atual->tipo,tip);
   atual->bateria = bat;
   atual->autonomia = aut;
   strcpy(atual->localiza,loc);
   atual->seguinteq = inicio;
   return(inicio);
   }
  }
 }
}

// listar na consola o conteúdo da lista por ordem decrescente da autonomia
void listarEquipamentosAutonomia(Equipamento * regequip)
{
int i, j, auttemp, ideqtemp;

for (i = 0; i < tamanho-1; i++) {
      for (j = 0; j < tamanho-i-1; j++) {
            if (regequip[j].autonomia<regequip[j+1].autonomia) {
                  auttemp = regequip[j].autonomia;
                  ideqtemp = regequip[j].idequipamento;
                  regequip[j].autonomia = regequip[j+1].autonomia;
                  regequip[j].idequipamento = regequip[j+1].idequipamento;
                  regequip[j+1].autonomia = auttemp;
                  regequip[j+1].idequipamento = ideqtemp;
            }
      }
}
{while (regequip != NULL)
 {printf("%d %s %.2f %.2f\n",regequip->idequipamento,regequip->tipo, 
		             regequip->bateria, regequip->autonomia, regequip->localiza);
  regequip = regequip->seguinteq;
 }

}
}

// listar na consola o conteúdo da lista ligada
void listarEquipamentosLocaliza(Equipamento * inicio, char localizaprocura[])
{while (inicio != NULL)
  {if (inicio->localiza == localizaprocura)
      {printf("%d %s %s %.2f %.2f\n",inicio->idequipamento,inicio->localiza, inicio->tipo,
		             inicio->bateria, inicio->autonomia, inicio->localiza);
      inicio = inicio->seguinteq;}
  else {
      inicio = inicio->seguinteq;}
}
}

