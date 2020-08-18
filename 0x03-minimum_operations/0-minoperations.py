#!/usr/bin/python3
"""In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n, write a method that
calculates the fewest number of operations  needed to result
in exactly n H characters in the file."""


def minOperations(n):
    """ Calculates the fewest number of operations needed """
    toPrint = ""
    endPrint = "H"
    movCount = 0

    while len(endPrint) < n:

        if len(endPrint) * 2 <= n and n % len(endPrint) == 0:
            toPrint = endPrint
            movCount += 1

        endPrint += toPrint
        movCount += 1

    if len(endPrint) != n:
        return 0
    return movCount
