#include  <stdio.h>
#include <string.h>

//#define INF 999999

//definições para BFS
#define maxV 21
#define START 3
#define END 20

//definições para Dijkstra
#define maxD 7
#define startD 0
#define endD 6

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

//int tab[2][maxV] = {
					//{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF}, //dist
					//{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} //v-ant
					//};
int ant[maxV];
int dist[maxV];

int matrizD[maxD][maxD] = {
						{0,7,0,5,0,0,0},
						{7,0,8,9,7,0,0},
						{0,8,0,0,5,0,0},
						{5,9,0,0,15,6,0},
						{0,7,5,15,0,8,9},
						{0,0,0,6,8,0,11},
						{0,0,0,0,9,11,0},
						};
int disD[maxD];
int antD[maxD];
					
void bfs(int i){
	int a, fila[maxV], ini = 0, fim = 0;
	memset (ant,-1,sizeof(ant));
	memset (dist,0x7f,sizeof(dist));
	dist[i] = 0;
	fila[fim++] = i;
	while(ini <= fim){
		i = fila[ini++];
		//printf("%d ", i);
		for (a = 0; a < maxV; a++){//percorre procurando um vertice vizinho
			if( matriz[i][a] > 0 && dist[a] > dist[i] + 1 ){//verifica se ha uma aresta ligando os vertices
				//verifica se a distancia e menor do que a existente
				//tab[1][a] = init;//salva v-ant
				ant[a] = i;
				dist[a] = dist[i] + 1; //atualiza distancia
				//printf("atualiza distancia e v pai de %d\n",a);
				fila[++fim] = a;
			}
		}
	} 
}

void printBFS(){
	int a;
	
	printf("BFS\n");
	printf("Ditancia:\t");
	for(a = 0; a < maxV; a++) printf("%d\t",dist[a]);
	printf("\nV anterior:\t");
	for(a = 0; a < maxV; a++) printf("%d\t",ant[a]);
	printf("\nDistância de %d ate %d é de %d\n", START, END, dist[END]-dist[START]);
	a = END;
	printf("%d ",a);
	while(a != START){
		printf("-> %d ",ant[a]);
		a = ant[a];
	}
}

void dijkstra(int ini){
	char vis[maxD];
	memset (vis,0,sizeof(vis));
	memset (disD,0x7f,sizeof(disD));
	disD[ini] = 0;
	int a, i;
	for (a = 0; a < maxD; a++){
		int v = -1;
		for (i = 0; i < maxD; i++){
			if (!vis[i] && (v < 0 || disD[i] < disD[v])){
				v = i;
			}
		}
		vis[v] = 1;
		for (i = 0; i < maxD; i++){
			if (matrizD[v][i] && disD[i] > disD[v] + matrizD[v][i]){//verifica se há aresta ligando os vértices e se a distância é menor
				disD[i] = disD[v] + matrizD[v][i];//atualiza a distância
				antD[i] = v;//define o vértice anterior
			}
		}
	}
}

void printD(){
	int i;
	printf("\n\nDijkstra\n");
	
	printf("Distância:\t");
	for(i = 0; i < maxD; i++) printf("%d\t",disD[i]);
	
	printf("\nV-anterior:\t");
	for(i = 0; i < maxD; i++) printf("%d\t",antD[i]);
	
	printf("\nDistância de %d ate %d é de %d\n", startD, endD, disD[endD]);
	i = endD;
	printf("%d ",i);
	do{
		printf("-> %d ",antD[i]);
		i = antD[i];
	}while(i != startD);
	printf("\n\n");
}

int main(void){
	
	//tab[0][START] = 0;
	bfs(START);
	printBFS();
	
	dijkstra(startD);
	printD();
	
	return 0;
}

