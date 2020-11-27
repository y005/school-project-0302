#include <iostream>
#include "closest.h"
using namespace std;

int main(void){
	int i=0;
	int x[10] = {4, 10, 5, -2, -1, 6, 3, 6, -9, 5};
	int y[10] = {9, 3, 10, 5, -9, -3, 10, -10, 4, 2};
	closest *clo = new closest();
	point *p = new point[10];
	for(i=0;i<10;i++){
		(p+i)->x = x[i];
		(p+i)->y = y[i];
	}
	clo->setPoints(p, 10);
	cout<<"Minimum distance: "<<clo->getMinDist()<<endl;
	delete clo, p;
	return 0;
}

