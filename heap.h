#ifndef HEAP_H
#define HEAP_H
#include <functional>
// QUESTION: can i include this?
#include <cmath>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
	 void push(T item);


  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	int m;
  std::vector<T> data;
  PComparator c;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
	this->m = m;
  this->c = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return data.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return data.size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error: heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Error: heap is empty");
  }

	std::swap(data[0], data[data.size() - 1]);
	data.pop_back();
    
	unsigned parent = 0;
  unsigned priority = 1;

	while(true){
		// iterates through each layer of the tree
		// iterate through all of the children and use the max element (for example if max heap) to swap
    // left child = 2i + 1, right child = 2i + 2
    // m-ary tree = m * i + 1... m * i + m
		for(int i = 0; i < m; i++){
			if((m * parent + i + 1 < data.size() && c(data[priority], data[m * parent + i]))){
				priority = m * parent + i;
			}
		}
		if(c(data[priority], data[parent])){
      std::swap(data[parent], data[priority]);
		  parent = priority;
    }
    else break;
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(T item){
	data.push_back(item);
	unsigned last = data.size() - 1;
	unsigned parent = (last - 1) / m;
	while(c(data[last], data[parent])){
		std::swap(data[last], data[parent]);
		last = parent;
		parent = (last - 1) / m;
	}
}



#endif

