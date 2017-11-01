"""
Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
"""
def wave_sort(l):
    sorted_list = sorted(l)
    for i in range(1, len(sorted_list), 2):
        sorted_list[i - 1], sorted_list[i] = sorted_list[i], sorted_list[i - 1]

    return sorted_list


"""
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
"""
def diff_possible(lst, k):
    mem = {}
    for i, x in enumerate(lst):
        if x not in mem:
            mem[k + x] = i

    for i, x in enumerate(lst):
        if x in mem and mem[x] != i:
            return True

    return False

"""
Given a column title as appears in an Excel sheet, return its corresponding column number.
"""
def title_to_number(title):
    r_title = reversed(title.lower())
    col = 0
    for i, x in enumerate(r_title):
        col += (26 ** i) * (ord(x) - 96)

    return col

"""
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.
"""
def majority_element(lst):
    total = len(lst)
    majority = total // 2
    count = {}
    for x in lst:
        if x not in count:
            count[x] = 1
        else:
            count[x] += 1

    for k, v in count.items():
        if v > majority:
            return k

"""
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2...
Completing the circuit means starting at i and ending up at i again.
"""
def can_complete_circuit(gas, cost):
    length = len(gas)
    current_gas = 0
    start = 0
    for i in range(length):
        current_gas += gas[i] - cost[i]
        if current_gas < 0:
            current_gas = 0
            start = i + 1

    if start < length:
        for i in range(0, start + 1):
            current_gas += gas[i] - cost[i]
            if current_gas < 0:
                return -1

        return start
    else:
        return -1

print can_complete_circuit(
[959, 329, 987, 951, 942, 410, 282, 376, 581, 507, 546, 299, 564, 114, 474, 163, 953, 481, 337, 395, 679, 21, 335, 846, 878, 961, 663, 413, 610, 937, 32, 831, 239, 899, 659, 718, 738, 7, 209],
[862, 783, 134, 441, 177, 416, 329, 43, 997, 920, 289, 117, 573, 672, 574, 797, 512, 887, 571, 657, 420, 686, 411, 817, 185, 326, 891, 122, 496, 905, 910, 810, 226, 462, 759, 637, 517, 237, 884]
)

print can_complete_circuit([0], [0])
