/*
* author: Miguel António Costa Macedo
* email: a26046@alunos.ipca.pt
* date: 15-03-2023
* desc: Trabalho Prático
* vers: Fase 1 - Gestores
--------------------------------------------------*/


#include <stdlib.h>
#include <string.h>
#include "gestores.h"

int tamanhoGestores(Gestor* inicio) //Tamanho da lista ligada
{Gestor* aux = inicio;
 int contador = 0;
 while (aux != NULL)
 {contador++;
  aux = aux->seguinte; // transitar para o registo seguinte
 }
 return(contador);
}

// Inserção de um novo registo no fim
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Gestor* inserirFimGes(Gestor* inicio, int idges, char nomeges[])
{Gestor* novo = malloc(sizeof(struct registogestores));
 Gestor* aux = inicio;
 if (novo!=NULL)
 {novo->idgestor = idges;
  strcpy(novo->nomegestor,nomeges);
  novo->seguinte = NULL;
  if (aux==NULL) return(novo);
  else {while (aux->seguinte!=NULL) aux = aux->seguinte;
        aux->seguinte = novo; 
	  // inserção do novo registo na última posição da lista
        return(inicio);
       }
 }
 else return(inicio);
}

// Função recursiva para a inserção de um novo registo no fim da lista ligada
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Gestor* inserirFimRec(Gestor* inicio, int idges, char nomeges[])
{if (inicio==NULL) 
	return(inserirGestor(NULL,idges,nomeges)); // inserção no início
 else {inicio->seguinte=inserirFimRecGes(inicio->seguinte,idges,nomeges);
       return(inicio);
      }
}

int removerTodosGes(Gestor* inicio) // remover todos os registos da lista ligada
{Gestor* aux;
 while (inicio!=NULL)
 {aux = inicio->seguinte;
  free(inicio);
  inicio = aux;
 }
}

Gestor* consultarGes(Gestor* inicio, int idges) // consultar registo a partir do código
{
 while(inicio!=NULL)
 {if (inicio->idgestor==idges) return(inicio);
  inicio=inicio->seguinte;
 }
 return(NULL);
}

Gestor* copiaListaGesLigada(Gestor* inicio) // Criar uma cópia da lista ligada
{Gestor* copia=NULL;
 while(inicio!=NULL)
 {copia = inserirFimGes(copia, inicio->idgestor, 
		     inicio->nomegestor);
  inicio = inicio->seguinte;
 }
 return(copia);
}

int guardarGestor(Gestor* inicio)
{FILE* fp;
 fp = fopen("gestores.txt","w");
 if (fp!=NULL)
 {
 Gestor* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%f;%f;%s\n", aux->idgestor, aux->nomegestor);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Gestor* lerGestores()
{FILE* fp;
 int idges;
 char nom[60];
 Gestor* aux=NULL;
 fp = fopen("gestores.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%s\n", &idges, &nom);
    aux = inserirMeio(aux, idges, nom);
  }
  fclose(fp);
 }
 return(aux);
}

// Inserção de um novo registo
Gestor* inserirGestor(Gestor * inicio, int idges, char nomeges[])
{
 if (!existeGestor(inicio, idges))
 {Gestor * novo = malloc(sizeof(struct registogestores));
  if (novo != NULL)
  {novo->idgestor = idges;
   strcpy(novo->nomegestor,nomeges);
   novo->seguinte = inicio;
   return(novo);
  }
 } else return(inicio);
}

// listar na consola o conteúdo da lista ligada
void listarGestores(Gestor * inicio)
{while (inicio != NULL)
 {printf("%d %s\n",inicio->idgestor,inicio->nomegestor);
  inicio = inicio->seguinte;
 }
}

// Determinar existência do 'identificador do gestor' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeGestor(Gestor* inicio, int idges)
{while(inicio!=NULL)
  {if (inicio->idgestor == idges) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

// Remover um gestor a partir do seu código
Gestor* removerGestor(Gestor* inicio, int idges) 
{
 Gestor *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->idgestor == idges) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->idgestor!=idges)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}

// Alterar um gestor a partir do seu identificador
Gestor* alterarGestor(Gestor* inicio, int idges, char nomeges[]) 
{
 Gestor *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->idgestor == idges) // remoção do 1º registo
 {aux = atual->seguinte;
  {atual->idgestor = idges;
   strcpy(atual->nomegestor,nomeges);
   atual->seguinte = inicio;
   return(aux);
  }
 }
 else
 {while ((atual!=NULL)&&(atual->idgestor!=idges)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   {atual->idgestor = idges;
   strcpy(atual->nomegestor,nomeges);
   atual->seguinte = inicio;
   return(inicio);
   }
  }
 }
}