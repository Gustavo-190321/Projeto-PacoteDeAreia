#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int balde;

int sortearPa(){
	srand(time(NULL));
	int i, sorteio;
	
	for(i=0;i<10;i++){
		sorteio = rand() % 3;
	}

	return sorteio;
}

void controleDoBalde(){
	int paNormal = 0, paInvertida = 0, megaPa = 0;
	
	int paSelecionada = sortearPa();


	if(paSelecionada == 0){
		paNormal = 1;

	}else if(paSelecionada == 1){
		paInvertida = 1;

	}else{
		megaPa = 1;

	}
	
	if(paNormal){
		balde += 100;
	}else if(paInvertida){
		if(balde != 0){
			balde -= 50;
		}
	}else{
		balde += 100*2;
	}
}

void jogo(){
	int vezesJogadas=0;
	char opc;
	do{
		system("cls");
		if(balde > 1000){
			break;
		}
		controleDoBalde();
		vezesJogadas++;
		
		printf("\nVale Lembrar que voce deve ficar entre 900 e 1000g\n");
		printf("Vezes jogadas: %d\n", vezesJogadas);
		printf("Digite 'C' se desejar continuar, digite qualquer outra coisa se deseja parar\n");
		fflush(stdin);
		scanf("%c", &opc);
	}while(opc=='c' || opc=='C');
	
	system("cls");
	printf("_____________________________________________________________________________________________\n");
	printf("_____________________________________Pacote de areia finalizado______________________________\n");
	printf("_____________________________________________________________________________________________\n");
	printf("\nAreia no balde: %dg", balde);
	((balde >= 900) && (balde <= 1000)) ? printf("\nJogador vitorioso, bora comemorar\n\n") : printf("\nJogador perdeu, que tristesa\n\n");
	
	system("pause");
}


int main(){
	char opt;
	
	do{
		system("cls");
		
		
		printf("_____________________________________________________________________________________________\n");
		printf("_____________________________________Pacote de areia_________________________________________\n");
		printf("_____________________________________________________________________________________________\n");
		
		
		printf("\nDigite \"S\" para iniciar o jogo,\"R\" Para acessar as regras de jogo e \"E\" para sair: ");
		fflush(stdin);
		scanf("%c", &opt);
		switch(opt){
			case 's':
			case 'S':
				balde = 0;
				jogo();
			break;
			
			case 'e':
			case 'E':
				system("cls");
				printf("_____________________________________________________________________________________________\n");
				printf("_____________________________________Pacote de areia_________________________________________\n");
				printf("_____________________________________________________________________________________________\n");
				printf("\nAte a proxima");
				return 0;
			break;
			
			case'r':
			case'R':
				printf("\nRegras: Para ganhar basta finalizar o jogo com uma quantia de 900 a 1000 gramas de areia dentro do balde, existem 3 tipos de pa: Pa normal (Adiciona 100g); Mega pa (Adiciona 200g) e Pa invertida (retira 50g)\n\n");
				system("pause");
				system("cls");
			break;
			default:
			printf("\n\n OPCAO INVALIDA\n\n");
			system("pause");
		}
	}while(opt != 'e' || opt != 'E');

	
	return 0;
}
