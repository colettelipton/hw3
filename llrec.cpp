#include "llrec.h"
#include <iostream>

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
		Node* small;
		Node* large;
		smaller = nullptr;
		larger = nullptr;
		llpivotHelp(head, small, large, smaller, larger, pivot);
}

void llpivotHelp(Node *&head, Node *&small, Node *&large, Node *&smaller, Node *& larger, int pivot){
	if(head == nullptr){
		if(!(small == nullptr) && small->next != nullptr) small->next = nullptr;
		if(!(large == nullptr) && large->next != nullptr) large->next = nullptr;
		small = nullptr;
		large = nullptr;
		return;
	}

	if(smaller == nullptr && head->val <= pivot){
		smaller = head;
		small = head;
	}

	else if(larger == nullptr && head->val > pivot){
		larger = head;
		large = head;
	}
		
	else if(head->val <= pivot){
		small->next = head;
		small = small->next;
	}
			
	else if(head->val > pivot){
		large->next = head;
		large = large->next;
	}
	
	llpivotHelp(head->next, small, large, smaller, larger, pivot);
}


