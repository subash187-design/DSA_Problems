class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;
        while(n){
            int k=n%10;
            arr.push_back(k);
            n=n/10;
        }
        sort(arr.begin(),arr.end());
        int a=arr.size();
        return arr[a-1]*arr[a-2];

    }
};