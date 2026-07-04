class Solution {
public:

    bool isOk(vector<int>& nums, int target, int mid){
        return nums[mid] < target;
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while(l < r){
            int mid = (l + r) / 2;
            if(isOk(nums, target, mid)) l = mid + 1;
            else r = mid;
        }

        if(nums[l] == target) return l;
        else return -1;
    }
};
