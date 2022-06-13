#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define capacidade 10	// capacidade máxima da geladeira

int geladeira =3;	// começa de 3 

void * Consumidor (void *arg);		// prototipo para função de consumidor	
void * Obeservador (void *arg);		// prototipo para função de observador

void main(){

	pthread_t consumidor, pai, mae, tio;	// cria varivéis para as threads
	
	int id1=1,id2=2,id3=3;		// ids dos observadores
	
	//cria consumidor
	pthread_create(&consumidor, NULL, Consumidor, NULL);
	// cria observadores

	pthread_create(&pai, NULL, Obeservador, ((void*)id1));
	pthread_create(&mae, NULL, Obeservador, ((void*)id2));
	pthread_create(&tio, NULL, Obeservador, (void*)id3);
	
	/* executa até que o programa seja encerrado*/
	for(;;){
		
		printf("Estado atual geladeira[%d]\n",geladeira);	//exibe estado atual da geladeira
		
		if(geladeira > capacidade)									// se estorou o limite
			printf("violação da capacidade Maxima da geladeira");   // avisa da violação
		sleep(1); // atualiza em 1 segundo
		
	}
}
/*
|	Consumidor dorme por 3 segundos e depois consome 1 litro de leite da geladeira
*/
void * Consumidor (void *arg) {
	while(1){			// executa sempre
		sleep(3);		// dorme por 3 segundos
		geladeira--;	// consome 1 litro de leite
		printf("1 - Leite consumido\n");	
	}
}

/*
|	Observador está sempre ativo e verifica se a geladeira não está com capacidade maxima
|	Quando a geladeira não estiver com capacidade maxima o Observador compra 1 litro de leite
*/
void * Obeservador (void *arg) {
	int id =(int) arg;	// id do observador
	
	while(1){
		if (geladeira < capacidade){	// se não estiver com capacidade maxima
			geladeira++;				// compra leite 
			if(id == 1)
				printf(" Pai Comprou Leite\n");
			else if(id ==2)
				printf(" Mae Comprou Leite\n");
			else
				printf(" Tio Comprou Leite\n");
		}
	}
}
