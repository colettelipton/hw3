#include "stack.h"
#include <iostream>
using namespace std;

int main(){
	Stack<int> s;
	cout << "expected: 1, actual: " << s.empty() << endl;
	s.push(8);
	cout << "expected: 8, actual: " << s.top() << endl;
	cout << "expected: 0, actual: " << s.empty() << endl;
	s.push(9);
	cout << "expected: 9, actual: " << s.top() << endl;
	s.push(18);
	s.push(7);
	cout << "expected: 7, actual: " << s.top() << endl;
	cout << "expected: 4, actual: " << s.size() << endl;
	s.pop();
	cout << "expected: 3, actual: " << s.size() << endl;
	cout << "expected: 18, actual: " << s.top() << endl;

	try{
		Stack<int> i;
		i.pop();
	} catch(underflow_error e){
		cout << "error caught" << endl;
	}

	try{
		Stack<int> i;
		i.top();
	} catch(underflow_error e){
		cout << "error caught" << endl;
	}
}