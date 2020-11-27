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
double closest::getMinDist(void){
	register double dist = DBL_MAX;
    register int left = 0;
	register int right,i;
	register point * tmp =  new point[this->num];
	//sort by x-axis
	sort();
	for(right = 1; right< this->num; right++){
		//there is no need to search before than left point
		//because it is already longer than dist in x-axis
		//find left border whose x-axis is between [pnt[right].x-dist,pnt[right].x]
		for(i= left;i<right; i++){
			if(pnt[right].x - pnt[i].x < dist){left = i; break;}
        }
		//if there is no point than search next point
		if(i==right){continue;}
		for(i=left;i<right;i++){tmp[i-left] = pnt[i];}
		//sort by y-axis in temporary array
		sort(tmp,right-left);
		//find point whose y-axis is between [pnt[right].y-dist,pnt[right].y+dist]
		register int leftBorder,rightBorder;
		for(i=0;i<right-left;i++){
            if(abs(tmp[i].y-pnt[right].y)<dist){leftBorder = i;break;}
        }
        for(i=right-left-1;i>-1;i--){
            if(abs(tmp[i].y-pnt[right].y)<dist){rightBorder = i;break;}
        }
		//compare with current minimum distance
		for(i = leftBorder; i<rightBorder+1;i++){
			register double d = sqrt((tmp[i].x-pnt[right].x)*(tmp[i].x-pnt[right].x)+(tmp[i].y-pnt[right].y)*(tmp[i].y-pnt[right].y));
			dist = (dist<d)*dist+(!(dist<d))*d;
		}
	}
	return dist;
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
