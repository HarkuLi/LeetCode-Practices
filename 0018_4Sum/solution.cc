/**
 * Idea:
 * 1. Sort the input vector.
 * 2. Pick the first number iteratively and solve 3Sum sub-problems.
 * 3. Pick the second number iteratively and solve 2Sum sub-problems.
 * 4. Use two-pointer technique to solve 2Sum sub-problems.
 * 5. Take care of early break/continue conditions.
 * 6. Time complexity: O(n^3), where n is size of the input vector.
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        size_t num_cnt = nums.size();
        if (num_cnt < 4) {
            return result;
        }

        sort(nums.begin(), nums.end());

        // Iterate the indx until (num_cnt - 3) because we need 4 numbers for each answer.
        for (size_t idx1 = 0; idx1 < num_cnt - 3; ++idx1) {
            // Skip repeated first number.
            if (idx1 > 0 && nums[idx1] == nums[idx1 - 1]) {
                continue;
            }

            // Look ahead to the minimum sum consists of current number.
            if (((long) nums[idx1] + nums[idx1 + 1] + nums[idx1 + 2] + nums[idx1 + 3]) > target) {
                break;
            }

            // Look ahead to the maximum sum consists of current number.
            if (((long) nums[idx1] + nums[num_cnt - 3] + nums[num_cnt - 2] + nums[num_cnt - 1]) < target) {
                continue;
            }

            for (size_t idx2 = idx1 + 1; idx2 < num_cnt - 2; ++idx2) {
                if (idx2 > idx1 + 1 && nums[idx2] == nums[idx2 - 1]) {
                    continue;
                }

                if (((long) nums[idx1] + nums[idx2] + nums[idx2 + 1] + nums[idx2 + 2]) > target) {
                    break;
                }

                if (((long) nums[idx1] + nums[idx2] + nums[num_cnt - 2] + nums[num_cnt - 1]) < target) {
                    continue;
                }

                /**
                 * 1. Use two-pointer technique to solve 2Sum sub-problem.
                 * 2. We can do this only if the vector is sorted.
                 * 3. idx3 = idx2 + 1 < num_cnt - 1 = idx4
                 */
                size_t idx3 = idx2 + 1;
                size_t idx4 = num_cnt - 1;
                while (idx3 < idx4) {
                    long sum = (long) nums[idx1] + nums[idx2] + nums[idx3] + nums[idx4];

                    if (sum > target) {
                        --idx4;
                    } else if (sum < target) {
                        ++idx3;
                    } else {
                        result.push_back({nums[idx1], nums[idx2], nums[idx3], nums[idx4]});

                        do {
                            ++idx3;
                        } while (idx3 < idx4 && nums[idx3] == nums[idx3 - 1]);

                        do {
                            --idx4;
                        } while (idx3 < idx4 && nums[idx4] == nums[idx4 + 1]);
                    }
                }
            }
        }

        return result;
    }
};
