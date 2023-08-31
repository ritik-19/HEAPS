class Solution {
public:
    int kthSmallest(vector<vector<int>>& v, int k) {
        	priority_queue<int>pq;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			pq.push(v[i][j]);
			if(pq.size()>k){
				pq.pop();
			}
		}
	}
     return pq.top();

    }
};