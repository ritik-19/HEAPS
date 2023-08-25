 #include <iostream>
 #include<vector>
 #include<climits>
class minHeap{
std::vector<int> arr;
public:
	minHeap(std::vector<int> &array){
		this->arr=array;
		buildHeap();
	}
	void buildHeap(){
		for(int i=(this->arr.size()-1)/2;i>=0;i--){
			downHeapify(i);
		}
	}
	void upHeapify(int i){
     int pi=(i-1)/2;
     while(pi>=0){
     	if(arr[pi]>arr[i]){
     		std::swap(arr[pi],arr[i]);
     	}
     	else{
     		break;
     	}
     	i=pi;
     	pi=(pi-1)/2;
     }
	}
	void insert(int val){
		arr.push_back(val);
		upHeapify(arr.size()-1);
	}
	int get(){
		if(arr.size()>0) return arr[0];
		return INT_MIN;
	}
	void downHeapify(int pi){
       while(pi<arr.size()){
       	int lc=2*pi+1;
       	int rc=2*pi+2;
       	int candidate=pi;
       	if(lc<arr.size() && arr[candidate]>arr[lc]){
       		candidate=lc;
       	}
       	if(rc<arr.size() && arr[candidate]>arr[rc]){
       		candidate=rc;
       	}
        if(candidate==pi) break;
        std::swap(arr[candidate],arr[pi]);
        pi=candidate;
       }
	}
	void remove(){
		if(arr.size()>0){
		std::swap(arr[0],arr[arr.size()-1]);
		arr.pop_back();
		downHeapify(0);
	}
	}
	void print(){
		for(int i=0;i<arr.size();i++){
			std::cout<<arr[i]<<" ";
		}
		std::cout<<std::endl;
	}
};
int main(){
    int n;
    std::cin>>n;
    std::vector<int> array;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        array.push_back(x);
    }
    minHeap heap(array);
    heap.print();
    return 0;
}