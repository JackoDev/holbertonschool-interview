#!/usr/bin/python3
"""
a script that reads stdin line by line and computes metrics:
"""
import sys


i = 0
total_size = 0
status_code = {'200': 0,
               '301': 0,
               '400': 0,
               '401': 0,
               '403': 0,
               '404': 0,
               '405': 0,
               '500': 0}

try:
    for line in sys.stdin:
        args = line.split(' ')
        if len(args) > 2:
            stat = args[-2]
            file_size = args[-1]
            if stat in status_code:
                status_code[stat] += 1
            total_size += int(file_size)
            i += 1
            if i == 10:
                print('File size: {:d}'.format(total_size))
                ordered = sorted(status_code.keys())
                for key in ordered:
                    value = status_code[key]
                    if value != 0:
                        print('{}: {}'.format(key, value))
                i = 0
except Exception:
    pass
finally:
    print('File size: {:d}'.format(total_size))
    ordered = sorted(status_code.keys())
    for key in ordered:
        value = status_code[key]
        if value != 0:
            print('{}: {}'.format(key, value))