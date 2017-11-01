"""
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
"""
from leetcode import Interval


def merge(intervals):
    solution = []

    first_key_sorted = sorted(intervals, key=lambda x: x.start)
    for x in first_key_sorted:
        x_start = x.start
        x_end = x.end

        if not solution:
            solution.append(x)
        else:
            prev = solution[-1]
            prev_start = prev.start
            prev_end = prev.end
            if x_start <= prev_end:
                prev.start = min(x_start, prev_start)
                prev.end = max(x_end, prev_end)
            else:
                solution.append(x)

    return solution

a = merge([Interval(0, 0), Interval(1, 4)])
for x in a:
    print(x.start, x.end)
