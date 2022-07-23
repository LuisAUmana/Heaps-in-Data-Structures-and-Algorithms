#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// Helper function to print queue for debugging 

template<typename T> void printQueue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        cout << q_copy.top() << " ";
        q_copy.pop();
    }
    cout << endl;
}
 

vector<int> findMedian(vector<int>& data) {
    priority_queue<int> max_heap; // STL Max-heap
    priority_queue<int, vector<int>, greater<int> > min_heap; // STL Min-heap
    
    vector<int> res;
    
    // Your code here 
    // Please comment out any debugging print outs
    
      int med=data[0];



    for(int i=0; i<data.size(); i++){
        int L=data[i];
        if(max_heap.size()>min_heap.size()){
            if(L<med){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(L);
                
            }
    else{
        min_heap.push(L);
        
    }
    med = (max_heap.top() + min_heap.top())/2;
            
        }

    else if(max_heap.size()<min_heap.size()){
    if(L<=med){
        max_heap.push(L);
        
    }

    else{
        max_heap.push(min_heap.top());
        min_heap.pop();
        min_heap.push(L);
        
    }
    med = (max_heap.top() + min_heap.top())/2;
    }
    else{
        if(L<med){
            max_heap.push(L);
            med = max_heap.top();
            }
    else{
        min_heap.push(L);
        med=min_heap.top();
        
    }
    }
    res.push_back(med);

    }

    

    return res;

}