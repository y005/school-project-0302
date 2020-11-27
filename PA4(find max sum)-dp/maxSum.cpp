#include "maxSum.h"
// DO NOT modify constuctor and distructor...
maxSum::maxSum(int n, int* m){
	int i=0;
	if(!m)	return;

	num = n;
	money = new int[n];

	for(i=0;i<n;i++){
		money[i] = m[i];
	}
	return;
}

maxSum::~maxSum(){
	if(money){
		delete[] money;
	}
	return;
}

//using memoization for dynamic programming
int maxSum::max(void){
	int* m = new int[num];
	for(register int i=0;i<num;i++){m[i] =-1;}
	m[num-1] = money[num-1];
	//make array to store the maxSum of pockets
	//m[i] == findMax(0,m)
	//max sum of choosing from [i,n-1] pockets
	return findMax(0,m);
}

int maxSum::findMax(register int i,register int* m){
	if(i>num-1){return 0;}
	int& val = m[i];
	if(val != -1){return val;}
	int a= findMax(i+1,m);
	int b=0;
	int c=0;
	if(i<num){b = money[i]+findMax(i+2,m);}
	if(i<num-1){c = money[i]+money[i+1]+findMax(i+3,m);}
	if((a>=b)&&(a>=c)){val = a;}
	if((b>=a)&&(b>=c)){val = b;}
	if((c>=a)&&(c>=b)){val = c;}
	return val;
}
// Define additional functions here if you declared in maxSum.h....
