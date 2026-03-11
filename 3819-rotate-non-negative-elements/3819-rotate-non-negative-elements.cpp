class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        vector<int> copy = nums;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                pos.emplace_back(i);
            }
        }

        if (pos.size()) {
            if (k > pos.size()) {
                k = k % pos.size();
            }

            if (k) {
                vector<int> pos2(pos.begin() + k, pos.end());
                pos2.insert(pos2.end(), pos.begin(), pos.begin() + k);

                for (int i = 0; i < pos.size(); i++) {
                    nums[pos[i]] = copy[pos2[i]];
                }
            }
        }

        return nums;
    }
};