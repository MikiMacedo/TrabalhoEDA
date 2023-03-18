#include <stdio.h>

typedef struct registocliente
{int idcliente; // Identificador do Cliente de mobilidade elétrica
 char nome[60];
 int nif;
 char morada[200];
 float saldo;
 struct registocliente* seguinte;
} Cliente;

typedef struct registoaluguer
{int idequipamentoalugado; // Identificador do equipamento alugado
 int idclientealuga;
 int tempo;
 float custoaluguer;
 struct registoaluguer* seguinteal;
} Aluguer;


// Inserção de um novo registo de Cliente
Cliente* inserirCliente(Cliente* inicio, int idcl, char nom[], int nc, char mora[], float sald);

// listar na consola o conteúdo da lista ligada
void listarClientes(Cliente* inicio); 

// Determinar existência do 'identificador de cliente' na lista ligada 'inicio'
int existeCliente(Cliente* inicio, int idcliente);

// Remover um equipamento a partir do seu identificador
Cliente* removerCliente(Cliente* inicio, int idcl);

//Tamanho da lista ligada
int tamanhocl(Cliente* inicio);

// Inserção de um novo registo de cliente no fim
Cliente* inserirClFim(Cliente* inicio, int idcl, char nom[], int nc, char mora[], float sald);
// remover lista ligada
int removerTodosCl(Cliente* inicio);
// consultar registo a partir do identificador de cliente
Cliente* consultarcl(Cliente* inicio, int idcl);

// Criar uma cópia da lista ligada
Cliente* copiaListaLigadaCl(Cliente* inicio);

// Alterar dados

// Guarda a lista de Clientes
int guardarCliente(Cliente* inicio);

// Le a lista de Clientes
Cliente* lerClientes();

// Alterar um Cliente a partir do seu identificador
Cliente* alterarCliente(Cliente * inicio, int idcl, char nom[], int nc, char mora[], float sald);

// Inserção de um novo registo de aluguer
Aluguer* inserirAluguer(Aluguer* inicio, int ideqal, int idclal, int temp, float cost);

// Guardar Alugures
int guardarAlugueres(Aluguer* inicio);

// Le a lista de Alugueres
Aluguer* lerAlugueres();

