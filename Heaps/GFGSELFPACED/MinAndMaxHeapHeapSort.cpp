#include <iostream>

using namespace std;

struct minheap{
  int arr[];
  int size;
  int cap;
  minheap(int c){
      arr[]=new int[c];
      size=0;
      cap=c;
  }
  int left(int i){
      return (2*i+1);
  }
  int rightChild(int i){
      return (2*i+2);
  }
  int parent(int i){
      return (i-1)/2;
  }
  void insert(int k){
      if(size!=cap){
          size++;
          arr[size-1]=k;
          for(int i=size-1;i>=0 && arr[parent(i)]>arr[i]){
              swap(arr[parent(i)],arr[i]);
              i=parent(i);
          }
      }
      else{ 
          return;
      }
  }
  void minHeapify(int i){
      int minimum=i;
      if(left(i)<size && arr[left(i)]<arr[i]){
          minimum=left(i);
      }
      if(rightChild(i)<size && arr[rightChild(i)]<arr[i]){
          minimum=rightChild(i);
      }
      if(minimum!=i){
          swap(arr[minimum],arr[i]);
          minHeapify(minimum);
      }
  }
  void fixminHeap(){
      for(int i=0;i<size;i++){
          minHeapify(i);
      }
  }
  int ExtractMinFromMinHeap(){
      if(size==0){
          return INT_MAX;
      }
      if(size==1){
          size--;
          return arr[0];
      }
      int ans=arr[0];
      swap(arr[0],arr[size-1]);
      size--;
      minHeapify(0);
      return ans;
  }
  void DecreaseKey(int i,int k){
      arr[i]=k;
      for(int j=i;j>=0 && arr[parent(j)]>arr[j]){
          swap(arr[parent],arr[j]);
          j=parent(i);
      }
  }
  void DeleteKey(int i){
      DecreaseKey(i,INT_MIN);
      ExtractMinFromMinHeap();
  }
};


//BuildHeap fnctn: WE select the last non leaf internal node i=(size-2)/2 and call Heapify function on it and keep calling till
//i>=0 and keep decrementing i 

void BuildHeap(int arr[],int size){
    for(int i=(size-2)/2;i>=0;i--){
        minHeapify(i);
    }
}

//For Heap sort: First convert a given array into maxheap


void MaxHeapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        MaxHeapify(arr,n,largest);
    }
}

void BuildMaxHeap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        MaxHeapify(i);
        //Now we'll write the MaxHeapify function
    }
}

void HeapSort(int arr[],int n){
    BuildMaxHeap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]); //Just Like selection sort, keeps the maximum element to the rightmost
        MaxHeapify(arr,n,0); //Heapify works best when all nodes are at correct place except the root node 
    }
}
int main()
{
    //Implement your own minheap struct 
    //Implement insert function in a minheap 
    //Heapify: Given a minheap in which one node violates the property of minheap, fix the complete heap 
    //Extract min element from minheap (that is, top of the minheap)
    //Implement DecreaseKey operation in minheap, that is if we update some node with some value, the heap should 
    //automatically fix itself,into a new minheap that is correct version 
    //Implement a function to DeleteKey From minheap
    //Implement a function that converts a given array into minheap. That is build heap 
    
    //Now, Implement Heap sort 
    
    return 0;
}
