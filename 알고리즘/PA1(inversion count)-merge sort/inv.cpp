#include <iostream>
#include "inv.h"

#define MODE 0

using namespace std;
inv::inv(){
	this->array = NULL;
	this->size = 0;
}
inv::~inv(){
	if(this->array)	delete this->array;
	return;
}
void inv::reset(register int *a,register int s){
	register int i;
	if(this->array)	delete this->array;
	this->array = new int[s];
	this->size = s;
	for(i=0;i<s;i++)	array[i] = a[i];
	return;
}
void inv::printArray(void){
	register int i = 0;
	for(i=0;i<size;i++)	cout<<array[i]<<" ";
	cout<<endl;
}
int inv::numOfInv(void){
	inversion = 0;
	this->tmp = new int[this->size];
	mergeSort(this->array,0,(this->size)-1);
	return inversion;
}
//mergeSort를 사용하여 카운트를 n번 안에 구할 수 있도록 합니다.
//반복문의 iter변수를 register에 저장하여 빠른 속도로 read가 가능하도록 합니다.
//조건문 분기보다는 일반적으로 적용되는 연산으로 변경하여 빠른 속도를 내도록 합니다.
void inv::merge(register int* A, int s,register int m,register int e){
		register int arrayIdx = s,leftIdx,rightIdx = m+1;
		for(leftIdx=s;leftIdx<e+1;leftIdx++){tmp[leftIdx] = A[leftIdx];}
		leftIdx = s;
		register int result;
		//정렬된 왼쪽 배열과 오른쪽 배열을 비교하면 병합하는 과정에서
		//오른쪽 배열의 원소가 왼쪽 배열보다 먼저 삽입되는 경우에는
		//왼쪽 배열의 남아있는 원소들은 삽입되는 오른쪽 배열의 원소와
		//inversion 관계이기 때문에 남아있는 왼쪽 배열의 원소개수를
		//전체 inversion count에 추가 시켜줍니다.
		while((leftIdx<m+1)&&(rightIdx<e+1)){
				result = (tmp[leftIdx]>tmp[rightIdx]);
				A[arrayIdx++] = !result*tmp[leftIdx]+result*tmp[rightIdx];
				inversion  +=  result*(m-leftIdx+1);
				leftIdx += (!result);
				rightIdx += result;
		}
		//남은 배열의 원소는 일단 나머지 보다 크고 배열의 인덱스를 늘립니다
		//남은 한쪽의 배열의 원소를 모두 삽입시킵니다.
		while((leftIdx<m+1)||(rightIdx<e+1)){
				A[arrayIdx++] = (rightIdx<e+1)*tmp[rightIdx++]+(leftIdx<m+1)*tmp[leftIdx++];
		}
}
//mid값을 구할 때 비트연산을 이용하여 빠르게 나누기를 수행하도록 합니다.
void inv::mergeSort(int* A, register int left, register int right){
		int mid;
		if(left<right){
				mid = (left+right)>>1;
				mergeSort(A,left,mid);
				mergeSort(A,mid+1,right);
				merge(A,left,mid,right);
		}
}
