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
     * @type {Object.<number, number>}
     */
    let indexMap = {};

    for (const [index, num] of nums.entries()) {
        let expectedNum = target - num;

        if (expectedNum in indexMap) {
            return [indexMap[expectedNum], index];
        }

        indexMap[num] = index;
    }

    return [];
};
