"""
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
"""

def rotate(nums, k):
    while k:
        a = nums.pop()
        nums.insert(0, a)
        k -= 1
    return nums
