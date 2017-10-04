#include  <stdio.h>

#define INF 999999

//definições para BFS
#define maxV 21
#define START 3
#define END 20
//definições para Dijkstra
#define maxD 7
#define startD 0
#define endD 7

int matriz[maxV][maxV] = {
						{0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
						{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
						{0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
						{0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
						{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0}
						};
//int visitados[maxV] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int matrizD[maxD][maxD] = {
						{0,7,0,5,0,0,0},
						{7,0,8,9,7,0,0},
						{0,8,0,0,5,0,0},
						{5,9,0,0,15,6,0},
						{0,7,5,15,0,8,9},
						{0,0,0,6,8,0,11},
						{0,0,0,0,9,11,0},
						};
int tab[2][maxV] = {
					{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF}, //dist
					{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} //v-ant
					};
					
void bfs(int init){
	int a, fila[maxV], ini = 0, fim = 0;
	fila[++fim] = init;
	while(ini <= fim){
		init = fila[ini++];
		//printf("%d ", init);
		for (a = 0; a < maxV; a++){//percorre procurando um vertice vizinho
			if( matriz[init][a] > 0 && tab[0][a] > tab[0][init] + 1 ){//verifica se ha uma aresta ligando os vertices
				//verifica se a distancia e menor do que a existente
				tab[1][a] = init;//salva v-ant
				tab[0][a] = tab[0][init] + 1; //atualiza distancia
				//printf("atualiza distancia e v pai de %d\n",a);
				fila[++fim] = a;
			}
		}
	} 
}

void printBFS(){
	int a;
	printf(" Ditancia:\t");
	for(a = 0; a < maxV; a++) printf("%d\t",tab[0][a]);
	printf("\n V anterior:\t");
	for(a = 0; a < maxV; a++) printf("%d\t",tab[1][a]);
	printf("\n Distancia de %d ate %d e de %d\n", START, END, tab[0][END]-tab[0][START]);
	a = END;
	while(a != START){
		printf("%d ->",tab[1][a]);
		a = tab[1][a];
	}
}
void dijkstra(){
}

int main(void){
	tab[0][START] = 0;
	bfs(START);
	printBFS();
	return 0;
}

