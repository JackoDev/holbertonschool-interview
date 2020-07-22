#!/usr/bin/python3
""""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened."""
    new_list = [0]
    for i in new_list:
        for j in boxes[i]:
            if j not in new_list:
                if j < len(boxes):
                    new_list.append(j)
    if len(new_list) == len(boxes):
        return True
    return False
    # for i in range (1, len(boxes) - 1):
    #    for j in range (0, len(boxes[i]) - 1):
    #        if boxes[i][j]  not in new_list:
    #            return False
    #        else:
    #            pass
    # return True
