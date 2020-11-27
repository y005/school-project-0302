#ifndef __INV_H__
#define __INV_H__

class inv{
private:
	int* array;
	int* tmp;
	int size;
	int inversion;
// If you need more attributes or methods, declare here...


public:
	inv(void);
	~inv();
	void reset(int* a, int s);
	void printArray(void);
	int numOfInv(void);
	void merge(int* A,int s,int m,int e);
	void mergeSort(int* A, int left,int right);
};

#endif
