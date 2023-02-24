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
	Comp c;
	Heap<int, Comp> h(2, c);

	h.push(1);
	h.push(6);
	h.push(4);
  h.push(5);
  h.push(8);
	h.print();
	h.pop();
  /* 
	h.push(9);
	h.push(11);
	h.push(12);
	h.push(3);
	h.push(5);
	h.push(17);
	h.push(16);
	h.push(18);
	h.push(10); */

  h.print();

	
}