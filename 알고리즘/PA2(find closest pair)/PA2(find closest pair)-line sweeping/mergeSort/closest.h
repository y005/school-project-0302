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
	void sort(void);
	void sort(point* arr,int heapSize);
	void buildMaxHeap(void);
	void buildMaxHeap(point* arr,int heapSize);
	void maxHeapify(int heapSize,int i);
	void maxHeapify(point* arr,int heapSize,int i);
};

#endif
