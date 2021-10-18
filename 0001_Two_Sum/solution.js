/**
 * https://leetcode.com/problems/two-sum/
 */

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    /**
     * Number to index map.
     *
     * @type {Map<number, number>}
     */
    const indexMap = new Map();

    for (let index = 0; index < nums.length; ++index) {
        const num = nums[index];
        const expectedNum = target - num;

        if (indexMap.has(expectedNum)) {
            return [indexMap.get(expectedNum), index];
        }

        indexMap.set(num, index);
    }

    return [];
};
