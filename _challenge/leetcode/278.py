"""
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
"""

def first_bad_version(n):
    beginning = 1
    end = n

    while beginning < end:
        current = (beginning + end) // 2
        if isBadVersion(current):
            end = current
        else:
            beginning = current + 1

    return end
