#include<iostream>
#include<vector>
#include<queue>
class node{
public:
	int distance;
	int first;
	int second;
};
class compare{
public:
	bool operator()(node a,node b){
		return a.distance<b.distance;
	}
};
int main(){
	int n,k;
	std::cin>>n>>k;
	std::vector<std::vector<int> > nums;
	for(int i=0;i<n;i++){
		int x,y;
		std::cin>>x>>y;
		std::vector<int> temp;
		temp.push_back(x);
		temp.push_back(y);
		nums.push_back(temp);
	}
std::priority_queue<node,std::vector<node>, compare> pq;
std::vector<std::vector<int> > ans;
for(int i=0;i<nums.size();i++){
	int firstElement=nums[i][0];
	int secondElement=nums[i][1];
		int tempDistance=firstElement*firstElement+secondElement*secondElement;
		node a={tempDistance,firstElement,secondElement};
		pq.push(a);
	if(pq.size()>k){
		pq.pop();
	}
}
while(!pq.empty()){
	std::vector<int> temp;
	temp.push_back(pq.top().first);
	temp.push_back(pq.top().second);
	ans.push_back(temp);
	pq.pop();
}
for(int i=0;i<ans.size();i++){
	std::cout<<ans[i][0]<<" "<<ans[i][1]<<std::endl;
}
					return 0;
}