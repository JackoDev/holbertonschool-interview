#!/usr/bin/python3


def canUnlockAll(boxes):
    new_list = []

    for index1 in range (0, len(boxes)):
        for index2 in range (0, len(boxes[index1])):
            new_list.append(boxes[index1][index2])
    
    for i in range (1, len(boxes) - 1):
        for j in range (0, len(boxes[i]) - 1):
            if boxes[i][j]  not in new_list:
                return False
            else:
                pass
    return True

