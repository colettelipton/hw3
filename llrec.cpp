#include "llrec.h"

using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
		Node* small = nullptr;
		Node* large = nullptr;
		smaller = nullptr;
		larger = nullptr;
		if(head == nullptr) return;
		llpivotHelp(head, smaller, larger, small, large, pivot);
}

void llpivotHelp(Node *&head, Node *&small, Node *&large, Node *&smaller, Node *& larger, int pivot){
	if(head == nullptr){
		if(!(smaller == nullptr)){
			smaller->next = nullptr;
		}
		if(!(larger == nullptr)){
			larger->next = nullptr;
		}
		return;
	}
	if(small == nullptr && head->val <= pivot){
		smaller = head;
		small = head;
	}

	else if(large == nullptr && head->val > pivot){
		larger = head;
		large = head;
	}
		
	else if(head->val <= pivot){
		smaller->next = head;
		smaller = smaller->next;
	}
			
	else if(head->val > pivot){
		larger->next = head;
		larger = larger->next;
	}
	head = head->next;
	llpivotHelp(head, small, large, smaller, larger, pivot);
}


