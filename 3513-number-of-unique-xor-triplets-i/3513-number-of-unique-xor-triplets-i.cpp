class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       int n=nums.size();
       if(n==1 || n==2) return n;
       unsigned int a=*max_element(nums.begin(),nums.end());
       int k=bit_width(a);

       return pow(2,k); 
    }
};