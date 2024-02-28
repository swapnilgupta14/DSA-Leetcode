class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int st = i + 1;
            int en = nums.size() - 1;

            while (st < en) {
                int sum = nums[i] + nums[st] + nums[en];

                if (sum == 0) {
                    result.push_back({nums[i], nums[st], nums[en]});
                    st++;
                    en--;

                    while (st < en && nums[st] == nums[st - 1]) {
                        st++;
                    }

                    while (st < en && nums[en] == nums[en + 1]) {
                        en--;
                    }
                } else if (sum < 0) {
                    st++;
                } else {
                    en--;
                }
            }
        }

        return result;
    }
};