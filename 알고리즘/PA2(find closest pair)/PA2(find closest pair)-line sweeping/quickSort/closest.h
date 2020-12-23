#ifndef __CLOSEST_H__
#define __CLOSEST_H__

#include "point.h"

class closest{
private:
	point* pnt;
	int num;

	// If you need more member variables or member functions, declare here...

public:
	closest();
	~closest();

	void setPoints(point* p, int n);
	double getMinDist(void);
	void sort(int p,int r);
	void sort(point* arr,int p,int r);
	int partition(int p,int r);
	int partition(point* arr,int p,int r);
};

#endif
