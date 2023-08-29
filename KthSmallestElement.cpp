#include<iostream>
#include<vector>
#include<queue>
int main(){
	int n,k;
	std::cin>>n>>k;
	std::vector<int> nums;
	for(int i=0;i<n;i++){
		int x;
		std::cin>>x;
		nums.push_back(x);
	}
std::priority_queue<int> pq;
for(int i=0;i<nums.size();i++){
	pq.push(nums[i]);
	if(pq.size()>k){
		pq.pop();
	}
}
std::cout<<pq.top()<<std::endl;
					return 0;
}