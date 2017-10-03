#include  <stdio.h>

#define maxV 21
#define INF 999999
#define START 3
#define END 20

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
int visitados[maxV] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int tab[2][maxV] = {
					{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF}, //dist
					{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} //v-ant
					};
					
void bfs(int g[maxV][maxV], int init){
	int a, fila[maxV], ini, fim;
	ini = fim = 0;
	fila[++fim] = init;
	while(ini <= fim){
		init = fila[ini++];
		//printf("%d ", init);
		for (a = 0; a < maxV; a++){//percorre procurando um vertice vizinho
		if( g[init][a] > 0 && tab[0][a] > tab[0][init] + 1 ){//verifica se ha uma aresta ligando os vertices
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
	bfs(matriz, START);
	printBFS();
	return 0;
}

