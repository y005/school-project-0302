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

int maxSum::max(void){
	int r=0;
	//make array to store the number of selected pockets
	r = findMax(0,num);
	return r;
}

//s에서 e-1까지의 배열 중 최대의 합을 반환하는 함수
int maxSum::findMax(int s,int e){
	if(s<e){
		int mid = (s+e)>>1;
		//left는 s에서 mid-1까지
		//right는 mid에서 e-1까지
		int a = findMax(s, mid-1);
		int b = findMax(s, mid-2);
		int c = findMax(s, mid-3);
		int d = findMax(mid+1, e);
		int e = findMax(mid+2, e);
		int f = findMax(mid+3, e);

		int val1 = a+money[mid]+money[mid+1]+f;
		int max = val1;
		int val2 = a+money[mid]+e;
		if(val2>max){max = val2;}
		int val3 = b+money[mid-1]+money[mid]+money[mid+1]+e;
		if(val3>max){max=val3;}
		int val4 = b+money[mid-1]+d;
		if(val4>max){max=val4;}
		int val5 = f+money[mid-2]+money[mid-1]+d;
		if(val5>max){max=val5;}
		return max;
	}
	return 0;
}
// Define additional functions here if you declared in maxSum.h ...
