class NumArray {
public:
    int n;
    vector<int>fenwick;
    vector<int>orig;
    NumArray(vector<int>& nums) {
      n = nums.size();
      orig = nums;
      fenwick.resize(n+1,0);
      build();
    }
    
    void build(){
        for(int i = 1; i <= n ; i++){
            fenwick[i] += orig[i-1];
            int k = i + (i & -i);
            if(k <= n) 
            fenwick[k] += fenwick[i];
         }
    }
    void update(int index, int val) {
        int rem = orig[index];
        orig[index] = val;
        index = index + 1;
        for(int i = index; i <= n; ){
            fenwick[i] -= rem;
            fenwick[i] += val;
            i += (i & -i);
        }
    }
    
    int query(int index){
        int res = 0;
        for(int i = index + 1; i > 0 ; ){
            res += fenwick[i];
            i -= (i & -i); 
        }
        return res;
    }
    int sumRange(int left, int right) {
        return query(right) - query(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */