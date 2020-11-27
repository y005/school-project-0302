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
	register char* result = new char[(this->num)*100];
	register char * line = "-";
	register int i;
	//change word into "-" if i<lower(num/2)
	for(i=0;i<this->num>>1;i++){this->pa[i]= new pri(this->pa[i]->pr,line);}
	//use radixSort for stable sorting
	radixSort();
	//concatenate sorted word
	register char* idx1;
	register char* idx2;
	idx1 = result;
	for(i=0;i<this->num;i++){
		idx2 = pa[i]->word;
		while( *(idx2) != '\0'){
			*(idx1++) = *(idx2++);
		}
		*(idx1++) = ' ';
	}
	*(--idx1) = '\0';
	return result;
}

void concat::countSort(register int* prioritys,register int* tmp,register int* sortedIdx,register int i){

	//count array(0~7)
	register int* count = new int[8];
	register int k;
	for(k=0;k<8;k++){count[k] = 0;}
	//replacing divide, module operator
	//to bit operater for fast processing
	//(num>>(3*i)) == num/8^i
	//(num&7) == (num%8)
	for(k=0;k<this->num;k++){
		prioritys[k] = ((this->pa[sortedIdx[k]]->pr)>>(3*i))&7;
	}
	//to calculate count idex
	for(k=0;k<this->num;k++){
		++count[prioritys[k]];
	}
	//calculate index
	for(k=1;k<8;k++){
		count[k] += count[k-1];
	}
	for(k=this->num-1;k>-1;k--){
		tmp[--count[prioritys[k]]] = sortedIdx[k];
	}
	//copy sorted array to this->pa
	for(k=0;k<this->num;k++){
		sortedIdx[k] = tmp[k];
	}
}

void concat::radixSort(void){
	//additional array for sorting
	register int* prioritys = new int[this->num];
	register int* tmp = new int[this->num];
	//sortedIdx[i] = idx;
	//pri element in this->pa[idx] has to be sorted in i-th place
	register int* sortedIdx = new int[this->num];
	register pri* sortedPri = new pri[this->num];
	register int i;
	for(i=0;i<this->num;i++){
		sortedIdx[i] = i;
	}
	//sorting each digit by priority
	//octal count array is using to count sorting
	for(i=0;i<7;i++){
		this->countSort(prioritys,tmp,sortedIdx,i);
	}
	//copy sorted pri element to sortedPri
	for(i=0;i<this->num;i++){
		sortedPri[i] = *(this->pa[sortedIdx[i]]);
	}
	//copy sortedPri to this->pa
	//this->pa is sorted by i-th number of priority
	for(i=0;i<this->num;i++){
		*(this->pa[i]) = sortedPri[i];
	}
}

// If you declared more member functions, define here...
