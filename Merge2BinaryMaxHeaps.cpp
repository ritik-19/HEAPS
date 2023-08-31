class Solution{
    public:
    void DownHeapify(vector<int> &ans,int i){
        while(i<ans.size()){
            int lc=2*i+1;
            int rc=2*i+2;
            int candidate=i;
            if(lc<ans.size() && ans[candidate]<ans[lc]){
                candidate=lc;
            }
             if(rc<ans.size() && ans[candidate]<ans[rc]){
                candidate=rc;
            }
            if(candidate==i) break;
            swap(ans[candidate],ans[i]);
            i=candidate;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(int x:a){
            ans.push_back(x);
        }
        for(int x:b){
            ans.push_back(x);
        }
        for(int i=(ans.size()-1)/2;i>=0;i--){
            DownHeapify(ans,i);
        }
        return ans;
    }
};