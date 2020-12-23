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
	int** m = new int*[num];
	for(register int i=0;i<num;i++){
		m[i] = new int[num];
	}
	for(register int i=0;i<num;i++){
		for(register int j=0;j<num;j++){
			m[i][j] = (i==j)*money[i]+(i!=j)*-1;
		}
	}
	//0~num-1 pockets num
	//make array to store the maxSum of pockets
	//m[i][j] == findMax(i,j,m)
	//max sum of choosing from [i,j] pockets
	return findMax(0,num-1,m);
}

int maxSum::findMax(register int l,register int r,register int** m){
	if(l>r){return 0;}
	if(m[l][r]!= -1){return m[l][r];}
	int& val = m[l][r];
	register int mid = (l+r)>>1;
	register int a = findMax(l,mid-1,m)+findMax(mid+1,r,m);
	register int b = findMax(l,mid,m)+findMax(mid+2,r,m);
	register int c = findMax(l,mid-2,m)+findMax(mid+3,r,m)+money[mid]+money[mid+1];
	if((a>b-1)&&(a>c-1)){return val = a; }
	if((b>a-1)&&(b>c-1)){return val = b; }
	if((c>a-1)&&(c>b-1)){return val = c; }
}

// Define additional functions here if you declared in maxSum.h....
