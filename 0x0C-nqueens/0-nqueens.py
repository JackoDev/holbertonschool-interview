#!/usr/bin/python3

""" the problem of the nqueens
    solved with python """
import sys
from sys import argv, exit


def validator(line, col, res):
    """ validator for the position """
    trv1 = [l[0]+l[1] for l in res]
    trv2 = [l[1]-l[0] for l in res]
    columns = [l[1] for l in res]
    lines = [l[0] for l in res]
    if line in lines or col in columns or line+col in trv1 or col-line in trv2:
        return False
    return True

def position(N, line, col, res):
    """ a recursively method to position the queen(s) """
    while col < N:
        if validator(line, col, res):
            res.append([line, col])
            if line == N-1:
                print(res)
                res.pop()
            else:
                position(N, line+1, 0, res)
        col += 1
    if len(res) > 0:
        res.pop()
    return


if __name__ == "__main__":
    size = len(argv)
    if size != 2:
        print("Usage: nqueens N")
        exit(1)
    if argv[1].isdigit() is False:
        print("N must be a number")
        exit(1)
    N = int(argv[1])
    if N < 4:
        print("N must be at least 4")
        exit(1)
    res = []
    position(N, 0, 0, res)