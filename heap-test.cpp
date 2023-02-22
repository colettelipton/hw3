#include <iostream>
#include "heap.h"
using namespace std;

struct Comp {
    bool operator()(int &left, int &right){
        if(left > right) return true;
        else return false;
    }
};

int main(){
	Heap<int, Comp> h;

	h.push(1);
	cout << h.top() << endl;
}