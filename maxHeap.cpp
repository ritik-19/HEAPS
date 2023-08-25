 #include <iostream>
 #include<vector>
 #include<climits>
class maxHeap{
	std::vector<int> arr;
public:
	maxHeap(std::vector<int> &array){
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
			if(this->arr[i]>this->arr[pi]){
				std::swap(this->arr[i],this->arr[pi]);
			}
			else{
				break;
			}
			i=pi;
			pi=(pi-1)/2;
		}
	}
	void insert(int data){
     this->arr.push_back(data);
     this->upHeapify(this->arr.size()-1);
	}
	int get(){
		if(this->arr.size()>0) return this->arr[0];
		return INT_MIN;
	}
	void downHeapify(int i){
     while(i<this->arr.size()){
     	int lc=2*i+1;
     	int rc=2*i+2;
     	int candidate=i;
     	if(lc<this->arr.size() && this->arr[lc]>this->arr[candidate]){
     		candidate=lc;
     	}
     	if(rc<this->arr.size() && this->arr[rc]>this->arr[candidate]){
     		candidate=rc;
     	}
if(i==candidate) break;
std::swap(this->arr[i],this->arr[candidate]);
i=candidate;
     }
	}
	void remove(){
		if(this->arr.size()>0){
       std::swap(this->arr[0],this->arr[arr.size()-1]);
       this->arr.pop_back();
       downHeapify(0);
	}
}
void print(){
	for(int i=0;i<this->arr.size();i++){
		std::cout<<arr[i]<<" ";
	}
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
    maxHeap heap(array);
    heap.print();
    return 0;
}