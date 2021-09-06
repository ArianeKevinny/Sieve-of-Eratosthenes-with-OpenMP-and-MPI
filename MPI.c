#include "MPI.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h> 
#include <time.h>

int erastotenesMPI(int argc, char** argv) {
    //Iniciando MPI
    MPI_Init(NULL, NULL);
    int ncpus;
    MPI_Comm_size(MPI_COMM_WORLD, &ncpus);
    int meu_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);

    double inicio;
    double fim;
    long int i, j;
    int *vetor = NULL;
    int *subvetor = NULL;
    int lastNumber;
    long int count = 0;

        printf("Qual o ultimo valor do intervalo desejado: ");
        scanf("%d", &ultimoNumero);

        //Alocando o vetor que estara setado (1) ou não (0)
    
        if (rank == 0){ //identificando o primeiro processo
        vetor = (int *)malloc(lastNumber*sizeof(int));
        for(i = 0; i < lastNumber; i++){
            vetor[i] = 1;

            inicio = MPI_Wtime();  //Inciamos a conometragem 

        }

        subvetor = (int *)malloc(lastNumber * sizeof(int));
        MPI_Scatter(&vetor, lastNumber, MPI_INT, &subvetor, lastNumber, MPI_INT, 0, MPI_COMM_WORLD);


        //CORRENDO O VETOR EM BUSCA DOS MULTIPLOS (NÃO PRIMOS)
        for (int i = 2; i*i <= lastNumber; i++){
        if (subvetor[i]);
            for (int j = i*i; j <= lastNumber; j += i){
                subvetor[j] = 0;
            }
        }

        int *listaFinal = (int *)malloc(lastNumber*sizeof(int));
        MPI_Gather(&subvetor,1,MPI_INT,&listaFinal,1,MPI_INT,0,MPI_COMM_WORLD);

        
        if (rank == 0){
            fim = MPI_Wtime();
            for(i = 2; i < lastNumber; i++){
                if(listaFinal[i]){
                    count++;
                }
            }
        }
        printf("Tempo de processamento: %f\n", (fim -inicio));

    MPI_Finalize();
    return count;
}
