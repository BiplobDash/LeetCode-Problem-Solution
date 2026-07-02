// Time Complexity O(N)

class Solution {
public:
    int maxArea(vector<int>& heights) {

        int ans = 0;
        int n = heights.size();
        int l = 0, r = n - 1;
        while(l < r){
            int area = min(heights[l], heights[r]) * (r - l);
            ans = max(ans, area);
            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return ans;
    }
};


// Time Complexity O(N^2)
class Solution {
public:
    int maxArea(vector<int>& heights) {

        int ans = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int h = min(heights[i], heights[j]);
                int w = j - i;
                ans = max(ans, h * w);
            }
        }
        return ans;
    }
};
