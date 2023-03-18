/*
* author: Miguel António Costa Macedo
* email: a26046@alunos.ipca.pt
* date: 15-03-2023
* desc: Trabalho Prático
* vers: Fase 1 - Clientes
--------------------------------------------------*/
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

int tamanhocl(Cliente* inicio) //Tamanho da lista ligada
{Cliente* aux = inicio;
 int contador = 0;
 while (aux != NULL)
 {contador++;
  aux = aux->seguinte; // transitar para o registo seguinte
 }
 return(contador);
}

// Inserção de um novo registo de cliente no fim
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Cliente* inserirClFim(Cliente* inicio, int idcl, char nom[], int nc, char mora[], float sald)
{Cliente* novo = malloc(sizeof(struct registocliente));
 Cliente* aux = inicio;
 if (novo!=NULL)
 {novo->idcliente = idcl;
  strcpy(novo->nome,nom);
  novo->nif = nc;
  strcpy(novo->morada,mora);
  novo->saldo = sald;
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

// Função recursiva para a inserção de um novo registo de cliente no fim da lista ligada
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Cliente* inserirClFimRec(Cliente* inicio, int idcl, char nom[], int nc, char mora[], float sald)
{if (inicio==NULL) 
	return(inserirCliente(NULL,idcl,nom,nc,mora,sald)); // inserção no início
 else {inicio->seguinte=inserirClFimRec(inicio->seguinte,idcl,nom,nc,mora,sald);
       return(inicio);
      }
}

int removerTodosCl(Cliente* inicio) // remover todos os registos de Clientes da lista ligada
{Cliente* aux;
 while (inicio!=NULL)
 {aux = inicio->seguinte;
  free(inicio);
  inicio = aux;
 }
}

Cliente* consultarCl(Cliente* inicio, int idcl) // consultar registo a partir do identificador
{
 while(inicio!=NULL)
 {if (inicio->idcliente==idcl) return(inicio);
  inicio=inicio->seguinte;
 }
 return(NULL);
}


Cliente* copiaListaLigadaCl(Cliente* inicio) // Criar uma cópia da lista ligada
{Cliente* copia=NULL;
 while(inicio!=NULL)
 {copia = inserirFimCl(copia, inicio->idcliente, 
		     inicio->nome, inicio->nif, inicio->morada, inicio->saldo);
  inicio = inicio->seguinte;
 }
 return(copia);
}

int guardarClientes(Cliente* inicio)
{FILE* fp;
 fp = fopen("clientes.txt","w");
 if (fp!=NULL)
 {
 Cliente* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%[^\n]s;%d;%[^\n]s;%2.f\n", aux->idcliente, aux->nome, 
	                      aux->nif, aux->morada, aux->saldo);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Cliente* lerClientes()
{FILE* fp;
 int idcl, nc;
 float sald;
 char nom[60], mora[200];
 Cliente* aux=NULL;
 fp = fopen("clientes.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%[^\n]s;%d;%[^\n]s;%2.f\n", &idcl, &nom, &nc, &mora, &sald);
    aux = inserirCliente(aux, idcl, nom, nc, mora, sald);
  }
  fclose(fp);
 }
 return(aux);
}

// Inserção de um novo registo de cliente
Cliente* inserirCliente(Cliente * inicio, int idcl, char nom[], int nc, char mora[], float sald)
{
 if (!existeCliente(inicio, idcl))
 {Cliente * novo = malloc(sizeof(struct registocliente));
  if (novo != NULL)
  {novo->idcliente = idcl;
   strcpy(novo->nome,nom);
   novo->nif = nc;
   strcpy(novo->morada,mora);
   novo->saldo = sald;
   novo->seguinte = inicio;
   return(novo);
  }
 } else return(inicio);
}

// Determinar existência do 'identificador de cliente' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeCliente(Cliente* inicio, int idcl)
{while(inicio!=NULL)
  {if (inicio->idcliente == idcl) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

// listar na consola o conteúdo da lista ligada
void listarClientes(Cliente * inicio)
{while (inicio != NULL)
 {printf("%d %s %d %s %.2f\n",inicio->idcliente,inicio->nome, 
		             inicio->nif, inicio->morada, inicio->saldo);
  inicio = inicio->seguinte;
 }
}

// Remover um Cliente a partir do seu código{
Cliente* removerCliente(Cliente* inicio, int idcl) 
{
 Cliente *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->idcliente == idcl) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->idcliente!=idcl)) 
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

// Alterar um Cliente a partir do seu identificador
Cliente* alterarCliente(Cliente * inicio, int idcl, char nom[], int nc, char mora[], float sald)
{
 Cliente *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->idcliente == idcl) // remoção do 1º registo
 {aux = atual->seguinte;
  {atual->idcliente = idcl;
   strcpy(atual->nome,nom);
   atual->nif = nc;
   strcpy(atual->morada,mora);
   atual->saldo = sald;
   atual->seguinte = inicio;
   return(aux);
  }
 }
 else
 {while ((atual!=NULL)&&(atual->idcliente!=idcl)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
  {atual->idcliente = idcl;
   strcpy(atual->nome,nom);
   atual->nif = nc;
   strcpy(atual->morada,mora);
   atual->saldo = sald;
   atual->seguinte = inicio;
   return(inicio);
   }
  }
 }
}

int tamanhoal(Aluguer* inicio) //Tamanho da lista ligada
{Aluguer* aux = inicio;
 int contador = 0;
 while (aux != NULL)
 {contador++;
  aux = aux->seguinteal; // transitar para o registo seguinte
 }
 return(contador);
}

// Inserção de um novo registo de cliente no fim
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Aluguer* inserirAluguer(Aluguer* inicio, int ideqal, int idclal, int temp, float cost)
{Aluguer* novo = malloc(sizeof(struct registoaluguer));
 Aluguer* aux = inicio;
 if (novo!=NULL)
 {novo->idequipamentoalugado = ideqal;
  novo->idclientealuga = idclal;
  novo->tempo = temp;
  novo->custoaluguer = cost;
  novo->seguinteal = NULL;
  if (aux==NULL) return(novo);
  else {while (aux->seguinteal!=NULL) aux = aux->seguinteal;
        aux->seguinteal = novo; 
	  // inserção do novo registo na última posição da lista
        return(inicio);
       }
 }
 else return(inicio);
}

int guardarAlugueres(Aluguer* inicio)
{FILE* fp;
 fp = fopen("alugueres.txt","w");
 if (fp!=NULL)
 {
 Aluguer* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%d;%d;%2.f\n", aux->idequipamentoalugado, aux->idclientealuga, 
	                      aux->tempo, aux->custoaluguer);
  aux = aux->seguinteal;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Aluguer* lerAlugueres()
{FILE* fp;
 int ideqal, idclal, temp;
 float cost;
 Aluguer* aux=NULL;
 fp = fopen("alugueres.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%d;%d;%2.f\n", &ideqal, &idclal, &temp, &cost);
    aux = inserirAluguer(aux, ideqal, idclal, temp, cost);
  }
  fclose(fp);
 }
 return(aux);
}





