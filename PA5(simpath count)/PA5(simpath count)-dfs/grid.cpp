#include "grid.h"

unsigned long long grid::numOfWays(void){
	//In N*N there are 0-th to (n+1)*(n+1)-th vertex from top-left to down-right
	//adjacent[i] = adjacent vertices of i-th vertex
	int** adjacent = new int*[(n+1)*(n+1)];
	for(register int i=0;i<(n+1)*(n+1);i++){
		adjacent[i] = new int[4];
		//i-th vertex locate at i/(n+1) row, i%(n+1) column
		adjacent[i][0] = i-(n+1)>-1 ? i-(n+1):-1;
		adjacent[i][1] = (i%(n+1)+1)/(n+1)>0 ? -1:i+1;
		adjacent[i][2] = i<(n+1)*n ? i+(n+1):-1;
		adjacent[i][3] = (i%(n+1)-1)<0 ? -1:i-1;
	}
	//visited[i]
	//0: not visited 1: visited
	int* visited = new int[(n+1)*(n+1)];
	for(register int i=0;i<(n+1)*(n+1);i++){
		visited[i] = 0;
	}
	result = 0;
	//start from 0-th vertex
	visited[0] = 1;
	findWays(adjacent,visited,0);
	return result;
}

void grid::findWays(register int**adjacent,register int* visited,register int current){
	//if current is the destination add simpath count
	if(current==(n+1)*(n+1)-1){result++;return;}
	for(register int i=0;i<4;i++){
		register int next = adjacent[current][i];
		//If the adjacent vertex is a vertex that has never been visited
		//visited that vertex
		if((next!=-1)&&(!visited[next])){
			visited[next] = 1;
			findWays(adjacent,visited,next);
			visited[next] = 0;
		}
	}
	return;
}


// Define here if you declared additional functions...
