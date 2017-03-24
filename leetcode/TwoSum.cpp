/*
    Other possible solutions are:
     1) Sort the array and keep pointers to the start and the end until they cross or we find a match
     2) Traverse the array and store the values in a hash table, verifying for each entry if the complement is already into the hash table
*/
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> retval;
            for(size_t idx0 = 0; idx0 < nums.size(); idx0++){
                for(size_t idx1 = idx0 + 1; idx1 < nums.size(); idx1++){
                    if(nums[idx0] == target - nums[idx1]){
                        retval = {idx0, idx1};
                        return retval;
                    }
                }
            }
            return retval;
        }
};