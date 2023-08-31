class node{
    public:
    int diff;
    int idx;
};
class compare{
    public:
    bool operator()(node a,node b){
        if(a.diff!=b.diff) return a.diff<b.diff;
        return a.idx<b.idx;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<node,vector<node>, compare>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(x-arr[i]),i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(arr[pq.top().idx]);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};