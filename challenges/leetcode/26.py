"""
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
"""

def remove_duplicates(nums):
    if not nums:
        return 0

    length = len(nums)
    count = 1
    i = 1
    current = nums[0]
    while i < length:
        if current == nums[i]:
            nums.pop(i)
            length -= 1
        else:
            current = nums[i]
            count += 1
            i += 1

    return nums

print remove_duplicates([1,1,2])
print remove_duplicates([1,1,2,2,3,4,5,6,6,7,7,8,8,9])
