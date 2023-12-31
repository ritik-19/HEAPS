class compare{
    public:
    bool operator()(string a,string b){
        if(a.size()!=b.size()) return a.size()>b.size();
        return a>b;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>, compare> pq;
        for(string s:nums){
            pq.push(s);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};