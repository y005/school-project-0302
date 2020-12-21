#include "grid.h"
#include <iostream>
using namespace std;

class Node{
    private:
        int n;
    public:
        int* next;
        int current,idx;
        //n-th vertex in num*num
        Node(int i,int n){
            this->current = i;
            this->n = n;
            this->idx = 0;
            next = new int[4];
            next[0] = i-(n+1)>-1 ? i-(n+1): -1;
            next[1] = (i%(n+1)+1)/(n+1)>0 ? -1:i+1;
            next[2] = i<(n+1)*n ? i+(n+1):-1;
            next[3] = (i%(n+1)-1)<0 ? -1:i-1;
        }
};

unsigned long long grid::numOfWays(void){
	//In N*N there are 0-th to (n+1)*(n+1)-th vertex from top-left to down-right
	//adjacent[i] = adjacent vertices of i-th vertex
	//visited[i]
	//0: not visited 1: visited
	int* visited = new int[(n+1)*(n+1)];
	for(register int i=0;i<(n+1)*(n+1);i++){
		visited[i] = 0;
	}
	result = 0;
	//start from 0-th vertex
	visited[0] = 1;
	Node** stack = new Node*[(n+1)*(n+1)];
    int stackIdx = 0;
	stack[stackIdx++] = new Node(0,n);
	while(stackIdx>0){
		Node* now = stack[stackIdx-1];
		//cout<<now->current<<" ";
		if(now->current == (n+1)*(n+1)-1){
			visited[now->current] = 0;
            delete now;
            stackIdx--;
			result++;
			//cout<<endl;
			continue;
		}
		if(now->idx == 4){
			visited[now->current] = 0;
            delete now;
			stackIdx--;
			continue;
		}
		for(int i=now->idx;i<4;i++){
			if((now->next[i]!=-1)&&(visited[now->next[i]]==0)){
				visited[now->next[i]] = 1;
				now->idx = i+1;
				stack[stackIdx++] = new Node(now->next[i],n);
				break;
			}
			now->idx = i+1;
		}
	}
	return result;
}

// Define here if you declared additional functions...
