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
	sort(0,this->num-1);
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
		sort(tmp,0,right-left-1);
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

//overloading: sort by x-axis for two parameters
//using quick sort
void closest::sort(register int p,register int r){
	register int q;
	if(p<r){
        q = partition(p,r);
        sort(p,q-1);
        sort(q+1,r);
    }
}
int closest::partition(register int p,register int r){
    register point tmp;
    register point x = pnt[r];
    register int i = p-1;
    for(register int j=p;j<r;j++){
        if(pnt[j].x<=x.x){
            i++;
            tmp = pnt[i];
            pnt[i] = pnt[j];
            pnt[j] = tmp;
        }
    }
    tmp = pnt[i+1];
    pnt[i+1] = pnt[r];
    pnt[r] = tmp;
    return i+1;
}

//overloading: sort by y-axis for three parameters
//using quick sort
void closest::sort(register point* arr,register int p,register int r){
	register int q;
	if(p<r){
        q = partition(arr,p,r);
        sort(arr,p,q-1);
        sort(arr,q+1,r);
    }
}
int closest::partition(register point* arr,register int p,register int r){
    register point tmp;
    register point x = arr[r];
    register int i = p-1;
    for(register int j=p;j<r;j++){
        if(arr[j].y<=x.y){
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = tmp;
    return i+1;
}

// If you declared additional member functions, define here...
