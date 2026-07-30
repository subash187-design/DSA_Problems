class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
       stack<int>s1;
       stack<int>s2;
       vector<int>res1(n);
       vector<int>res2(n);
       for(int i=0;i<heights.size();i++){
        while(!s1.empty() && heights[s1.top()]>=heights[i])
        s1.pop();
        if(s1.empty()) res1[i]=-1;
        else res1[i]=s1.top();
        s1.push(i);
       } 
       for(int i=heights.size()-1;i>=0;i--){
        while(!s2.empty() && heights[s2.top()]>=heights[i])
        s2.pop();
        if(s2.empty()) res2[i]=heights.size();
        else res2[i]=s2.top();
        s2.push(i);
       } 
       int ans=0;
       for(int i=0;i<heights.size();i++){
        ans=max(ans,heights[i]*(res2[i]-res1[i]-1));
       }
       return ans;
    }
};