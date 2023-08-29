#include<iostream>
#include<vector>
#include<queue>
class compare{
public:
	bool operator()(int a,int b){
		return a>b;
	}
};
int main(){
	int n,k;
	std::cin>>n>>k;
	std::vector<int> nums;
	for(int i=0;i<n;i++){
		int x;
		std::cin>>x;
		nums.push_back(x);
	}
std::priority_queue<int,std::vector<int>, compare> pq;
for(int i=0;i<nums.size();i++){
	pq.push(nums[i]);
	if(pq.size()>k){
		pq.pop();
	}
}
std::cout<<pq.top()<<std::endl;
					return 0;
}