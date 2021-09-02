#include "serial.h" //eratostenes
#include "openMP.h" //eratostenesOpenMP
#include "MPI.h" //eratostenesMPI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tempo(double t_serial, double inicio, double fim){

    double t_paralelo = fim - inicio;
    double speedup = t_serial/t_paralelo;

    printf("Execucao paralela(s): %f\n", t_paralelo);
    printf("Speedup: %.4f\n", speedup);
	printf("Eficiencia: %.4f\n",speedup/4.0);

}

int main(){
    clock_t t; //variável para armazenar tempo
    int ultimoNumero;
    int result;
    double inicio;
    double fim;
    double t_serial;
    int escolha

    
    printf("Selecione: \n 
                1 -> Serial \n
                2 -> Paralelização com openMP \n
                2 -> Paralelização com MPI \n");
        scanf("%d", &escolha);

    if(escolha == 1){
        printf("Solução Serial! \n");

        printf("Qual o ultimo valor do intervalo desejado: ");
        scanf("%d", &ultimoNumero);

        printf("\n Resultado: ");

        inicio = clock(); //armazena tempo
        result = eratostenes(ultimoNumero);
        fim = clock() - t; //tempo final - tempo inicial

        t_serial = fim - inicio; 
        
        printf("%d \n", result);     
        printf("Tempo de execucao Serial: %lf ms \n", ((double)t_serial)/((CLOCKS_PER_SEC/1000))); //milissegundos

    }

    if(escolha == 2){

        printf("Solução com OpenMP! \n");
      
        printf("Qual o ultimo valor do intervalo desejado: ");
        scanf("%d", &ultimoNumero);

        printf("Resultado: ");

        inicio = clock(); //armazena tempo
        result = eratostenesOpenMP(ultimoNumero);
        fim = clock() - t; //tempo final - tempo inicial
      
        printf("%d \n", result);
       
        tempo(t_serial, inicio, fim)
    }

    if(escolha == 3){

        printf("Solução com MPI! \n");
      
        printf("Resultado: ");

        inicio = clock(); //armazena tempo
        result = eratostenesMPI();
        fim = clock() - t; //tempo final - tempo inicial
      
        printf("%d \n", result);

        printf("Analise do Tempo: \n");
        tempo(t_serial, inicio, fim)
       
    }
    return ("\n FIM!");
}