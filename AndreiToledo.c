#include  <stdio.h>

#define maxV 21
#define INF 999999
#define START 0
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
	int a;
	if(visitados[init] != 2){//verifica a cor do vertice
		visitados[init] = 1;
		for (a = 0; a < maxV; a++){
			//printf("achou um vertice entre %d %d\n",a,b);
			if( g[init][a] > 0){//verifica se há uma aresta ligando os vertices
				if(tab[0][a] == INF || tab[0][a] > tab[0][init] + 1){//verifica se a distancia é menor do que a existente
					tab[1][a] = init;//salva v-ant
					tab[0][a] = tab[0][init] + 1; //atualiza distancia
					//printf("atualiza distancia e v pai de %d\n",a);
					if(visitados[a] != 1){//verifica a cor do vertice
						bfs(g, a);
					}
				}
			}
		}
		visitados[init] = 2;
	}
}
void printBFS(){
	int a;
	printf(" Ditância:    ");
	for(a = 0; a < maxV; a++) printf(" %d ",tab[0][a]);
	printf("\n V anterior: ");
	for(a = 0; a < maxV; a++) printf(" %d ",tab[1][a]);
	printf("\n Distancia de %d até %d é de %d\n", START, END, tab[0][END]-tab[0][START]);
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

