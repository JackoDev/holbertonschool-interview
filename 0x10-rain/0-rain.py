#!/usr/bin/python3
'''
0-rain
'''


def rain(walls):
    '''
    Calculate how much water can be retained
    '''
    left, right = 0, len(walls) - 1
    water = 0
    level = 0
    while left < right:
        if walls[left] < walls[right]:
            c_level = walls[left]
            left += 1
        else:
            c_level = walls[right]
            right -= 1
        level = max(level, c_level)
        water += level - c_level
    return water
