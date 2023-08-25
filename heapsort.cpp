#include <iostream>
#include<vector>
void heapify(std::vector<int> &arr,int s,int e){
	     while(s<e){
     	int lc=2*s+1;
     	int rc=2*s+2;
     	int candidate=s;
     	if(lc<e && arr[lc]>arr[candidate]){
     		candidate=lc;
     	}
     	if(rc<e && arr[rc]>arr[candidate]){
     		candidate=rc;
     	}
if(s==candidate) break;
std::swap(arr[s],arr[candidate]);
s=candidate;
}
 }
void heapSort(std::vector<int> &arr){
	for(int i=(arr.size()-1)/2;i>=0;i--){
       heapify(arr,i,arr.size());
}
	int i=arr.size()-1;
	while(i>0){
		std::swap(arr[i],arr[0]);
		heapify(arr,0,i--);
	}
}
int main() {
	int n;
	std::cin>>n;
	std::vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		std::cin>>x;
		arr.push_back(x);
	}
	heapSort(arr);
   for(int i=0;i<arr.size();i++){
    std::cout<<arr[i]<<" ";
   }
    return 0;
}
