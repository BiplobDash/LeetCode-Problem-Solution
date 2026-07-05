class Solution {
public:
    bool isOk(vector<int>& piles, int mid, int h){
        int sum = 0;
        for(auto p : piles){
            sum += (p + mid - 1) / mid;
        }
        return (sum > h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int l = 1, r = max(mx, 1000005);

        while(l < r){
            int mid = (l + r) / 2;
            if(isOk(piles, mid, h)) l = mid + 1;
            else r = mid;
        }

        return l;
    }
};
