#!/usr/bin/env python2

def answer(heights):
    heights_array = []
    water = 0
    max_left = 0
    max_right = 0

    for height in heights:

        next_index = heights.index(height) + 1
        before_index = heights.index(height) - 1

        if heights[before_index] <= height <= heights[next_index]:
            heights_array.append(height)

        elif heights[before_index] >= height >= heights[next_index]:
            max_left = height
            heights_array.append(height)

        elif heights[before_index] < height and heights[next_index] < height:
            max_right = height
            right_to_left = height

        elif height < heights[before_index] and height < heights[next_index]:
            if heights[before_index] > heights[next_index]:
                water += heights[before_index] - height
            else:
                water += heights[next_index] - height

    return water
