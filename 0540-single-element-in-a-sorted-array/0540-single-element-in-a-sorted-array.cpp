class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases for small arrays
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
        
        // Search space excludes boundaries already checked
        int st = 1;
        int end = n - 2;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // If mid is not equal to its left or right neighbor, it is the single element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            
            // Check if we are on the left side of the single element
            // (Even index matches next element, or Odd index matches previous element)
            if (nums[mid] == nums[mid ^ 1]) {
                st = mid + 1; // Move right
            } else {
                end = mid - 1; // Move left
            }
        }
        
        return -1;
    }
};
