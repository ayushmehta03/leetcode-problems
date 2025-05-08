from typing import List

class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        total_sum = sum(nums)
        target = total_sum - x
        if target < 0:
            return -1

        max_len = -1
        window_sum = 0
        left = 0

        for right in range(len(nums)):
            window_sum += nums[right]

            while window_sum > target and left <= right:
                window_sum -= nums[left]
                left += 1

            if window_sum == target:
                max_len = max(max_len, right - left + 1)

        return len(nums) - max_len if max_len != -1 else -1
