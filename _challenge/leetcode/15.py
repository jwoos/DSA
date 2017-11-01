"""
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.
"""

def three_sum(nums):
    solution = []

    sorted_nums = sorted(nums)
    for i in range(len(sorted_nums) - 2):
        # same number as before, we don't care
        if i > 0 and sorted_nums[i] == sorted_nums[i - 1]:
            continue

        left = i + 1
        right = len(sorted_nums) - 1
        # shrink the window from i + 1
        while left < right:
            current = sorted_nums[i] + sorted_nums[left] + sorted_nums[right]

            if current < 0:
                left += 1
            elif current > 0:
                right -= 1
            else:
                solution.append((sorted_nums[i], sorted_nums[left], sorted_nums[right]))

                while left < right and sorted_nums[left] == sorted_nums[left + 1]:
                    left += 1

                while left < right and sorted_nums[right] == sorted_nums[right - 1]:
                    right -= 1

                left += 1
                right -= 1

    return solution
