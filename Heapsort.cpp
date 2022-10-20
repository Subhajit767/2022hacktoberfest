
#include 
  using namespace std;
  
  void heapify(int array[], int sizeHeap, int parentIndex) 
  {
    // Establishing a relationship between indices of a node and indices of 
    // its left and right children 
    int larger = parentIndex;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    
    // Making sure the parent is greater than or equal to its left and right 
    // children
    if (leftChildIndex < sizeHeap && array[leftChildIndex] > array[larger])
      larger = leftChildIndex;
  
    if (rightChildIndex < sizeHeap && array[rightChildIndex] > array[larger])
      larger = rightChildIndex;
  
    // Swap and heapify if parent/root is not the largest
    if (larger != parentIndex) 
    {
      swap(array[parentIndex], array[larger]);
      heapify(array, sizeHeap, larger);
    }
  }
  
 
  void heapSort(int array[], int sizeArray) 
  {
  	
    // Creating max  heap, iterating for all  non=leaf indices, since leaf 
    // indices don't have children to check for

    for (int nonleafNodeIndex = sizeArray / 2 - 1; nonleafNodeIndex >= 0; nonleafNodeIndex--)
      heapify(array, sizeArray, nonleafNodeIndex);
  
    // Swap the root element of the heap with the last heap index, the 
    // Reduce heap size till it becomes 2 (last heap index 
    // is 1)

    for (int lastHeapIndex = sizeArray - 1; lastHeapIndex >= 1; lastHeapIndex--) 
    {
      swap(array[0], array[lastHeapIndex]);
  
     // Heapifying root element so that the highest element is again at the 
     // root
      heapify(array, lastHeapIndex, 0);
    }
    
  }
  
 
  int main() 
  {
    int array[] = {77, 15, 91, 21, 6, 46};
    
    int sizeArray = sizeof(array) / sizeof(array[0]);
    
    heapSort(array, sizeArray);
  
    for (int i = 0; i < sizeArray; ++i)
      cout << array[i] << " ";
  }
