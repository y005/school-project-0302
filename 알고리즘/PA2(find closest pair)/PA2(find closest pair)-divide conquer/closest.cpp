#include <cmath>
#include "point.h"
#include "closest.h"
#define DBL_MAX 1.79769e+308
#if 0

DO NOT MODIFY closest(void), ~closest(void), and setPoints(point* p, int n)!

#endif
using namespace std;
closest::closest(void){
	this->pnt = NULL;
	this->num = 0;
	return;
}

closest::~closest(void){
	if(this->pnt)	delete this->pnt;
	return;
}

void closest::setPoints(point* p, int n){
	int i=0;
	if(this->pnt)	delete this->pnt;
	this->pnt = new point[n];
	this->num = n;
	for(i=0;i<n;i++)	this->pnt[i] = p[i];
	return;
}

//Input source code here...
double closest::getMin(register point* tmp,register int s,register int e){
	register double minDist;
	//if there is only one point return max value
	if(s==e){return DBL_MAX;}
	//if there are two points return those distance
	if(s+1==e){return sqrt((pnt[e].x-pnt[s].x)*(pnt[e].x-pnt[s].x)+(pnt[e].y-pnt[s].y)*(pnt[e].y-pnt[s].y));}
	//left case
	register double a = getMin(tmp,s,((s+e)>>1));
	//right case
	register double b = getMin(tmp,((s+e)>>1)+1,e);
	minDist = (a<b)*a + (!(a<b))*b;
	//there is a possible where min distance exists cross left,right area
	//find left point border where x-axis distance is less then min distance
	register int left;
	for (left = ((s+e)>>1)-1; left>s-1; left--) {
		if((pnt[((s+e)>>1)].x - pnt[left].x)>minDist){break;}
	}
	left++;
	//find right point border where x-axis distance is less then min distance
	register int right;
	for (right = ((s+e)>>1)+1; right<e+1; right++){
		if((pnt[right].x - pnt[((s+e)>>1)].x)>minDist){break;}
	}
	right--;
	//compare min distnace with distance between point
	//whose x-axis is between [point[mid]-min distance,point[mid]+min distance]
	//compare min distance with only those y-axis distance less than min distance
	//make additional array and sort by y-axis
	register int i,j;
	for(i=left;i<right+1;i++){tmp[i-left] = pnt[i];}
	sort(tmp,right-left+1);
	for(i=0;i<right-left+1;i++){
		for(j=i+1;j<right-left+1;j++){
			if(abs(tmp[j].y-tmp[i].y)>minDist){break;}
			double c = sqrt((tmp[j].x-tmp[i].x)*(tmp[j].x-tmp[i].x)+(tmp[j].y-tmp[i].y)*(tmp[j].y-tmp[i].y));
			minDist = (minDist<c)*minDist+(!(minDist<c))*c;
		}
	}
	return minDist;
}
double closest::getMinDist(void){
	sort();
	point * tmp =  new point[this->num];
	return getMin(tmp,0,this->num-1);
}
//overloading: sort by x-axis for non parameter
void closest::sort(void){
	register point tmp;
	buildMaxHeap();
	for(register int i=this->num;i>1;i--){
		tmp = pnt[0];
		pnt[0] = pnt[i-1];
		pnt[i-1] = tmp;
		maxHeapify(i-1,0);
	}
}
void closest::buildMaxHeap(void){
	for(register int i= ((this->num)>>1)-1;i>-1;i--){
		maxHeapify(this->num,i);
	}
}
void closest::maxHeapify(register int heapSize,register int i){
	register int largest=i;
	if(((i<<1)+1<heapSize)&&(pnt[i].x<pnt[(i<<1)+1].x)){largest= (i<<1)+1;}
	if(((i<<1)+2<heapSize)&&(pnt[largest].x<pnt[(i<<1)+2].x)){largest=(i<<1)+2;}
	if(largest != i){
		point tmp = pnt[i];
		pnt[i] = pnt[largest];
		pnt[largest] = tmp;
		maxHeapify(heapSize,largest);
	}
}
//overloading: sort by y-axis for two integer parameter
void closest::sort(register point* arr,register int heapSize){
	register point tmp;
	buildMaxHeap(arr,heapSize);
	for(register int i=heapSize;i>1;i--){
		tmp = arr[0];
		arr[0] = arr[i-1];
		arr[i-1] = tmp;
		maxHeapify(arr,i-1,0);
	}
}
void closest::buildMaxHeap(register point* arr,register int heapSize){
	for(register int i= ((heapSize)>>1)-1;i>-1;i--){
		maxHeapify(arr,heapSize,i);
	}
}
void closest::maxHeapify(register point* arr,register int heapSize,register int i){
	register int largest=i;
	if(((i<<1)+1<heapSize)&&(arr[i].y<arr[(i<<1)+1].y)){largest=(i<<1)+1;}
	if(((i<<1)+2<heapSize)&&(arr[largest].y<arr[(i<<1)+2].y)){largest=(i<<1)+2;}
	if(largest != i){
		point tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		maxHeapify(arr,heapSize,largest);
	}
}
// If you declared additional member functions, define here...
