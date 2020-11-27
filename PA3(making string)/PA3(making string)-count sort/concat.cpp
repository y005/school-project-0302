#include <iostream>
#include <cstring>
#include "concat.h"
using namespace std;

concat::concat(void){
	this->num = 0;
	this->pa = 0;
	return;
}

concat::concat(int* priority, char **words, int n){
	int i=0;
	this->num = n;
	this->pa = new pri* [n];
	for(i=0;i<n;i++)	this->pa[i] = new pri(priority[i], words[i]);
	return;
}

concat::~concat(void){
	if(this->pa){
		int i=0, n = this->num;
		for(i=0;i<n;i++)	if(this->pa[i])		delete this->pa[i];
		delete[] this->pa;
	}
	return;
}

char* concat::concatenate(void){
	char* line = "-";
	register int i;
	int maxPr=0;
	int tmp;
	for(i=0;i<this->num;i++){
		tmp = this->pa[i]->pr;
		maxPr = (maxPr<tmp)*tmp+(!(maxPr<tmp))*maxPr;
	}
	//use count sorting for stable sorting
	register int* count = new int[maxPr+1];
	memset(count, 0, sizeof(int)*(maxPr+1));

	//change word into "-" if i<lower(num/2)
	for(i=0;i<this->num>>1;i++){
		strcpy(this->pa[i]->word,line);
	}

	register int* priority = new int[this->num];
	for(i=0;i<this->num;i++){
		priority[i] = this->pa[i]->pr;
		++count[priority[i]];
	}
	for(i=1;i<maxPr+1;i++){
		count[i] += count[i-1];
	}
	char** sorted = new char*[this->num];
	for(i=this->num-1;i>-1;i--){
		sorted[--count[priority[i]]] = new char[strlen(this->pa[i]->word)+1];
		strcpy(sorted[count[priority[i]]],this->pa[i]->word);
	}
	delete count;
	//concatenate sorted word
	register char* result = new char[(this->num)*100];
	register char* idx1 = result;
	register char* idx2;
	for(i=0;i<this->num;i++){
		idx2 = sorted[i];
		while( *(idx2) != '\0'){
			*(idx1++) = *(idx2++);
		}
		*(idx1++) = ' ';
	}
	*(--idx1) = '\0';
	return result;
}
// If you declared more member functions, define here...
