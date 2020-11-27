#include <iostream>
#include <cstring>
#include "concat.h"
using namespace std;

const char *testSet[] = {"Hello", "World", "interesting", "algorithm", "Sookmyung", "Women\'s", "University", "a", "a", "I", "am", "boy", "are", "you", "girl"};
int priority[15] = {11, 10, 9, 0, 0, 4, 1, 8, 2, 1, 1, 8, 6, 4, 2};

int main(void){
	int  i=0;
	char **word = new char*[15];
	char *result = 0;

	for(i=0;i<15;i++){
		word[i] = new char[strlen(testSet[i])+1];
		strcpy(word[i], testSet[i]);
	}

	concat *con = new concat(priority, word, 15);
	cout<<(result = con->concatenate())<<endl;

	for(i=0;i<15;i++)	delete[] *(word+i);
	delete[] word;
	delete con;
	delete[] result;
	return 0;
}
