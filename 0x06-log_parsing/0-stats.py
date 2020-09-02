#!/usr/bin/python3
"""
a script that reads stdin line by line and computes metrics:
"""
import sys


status_codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,
}

def print_status_codes(codes, size):
    print('File size: {}'.format(size))
    for code, count in sorted(codes.items()):
        if count != 0:
            print('{}: {}'.format(code, count))

file_size, count = 0, 0

try:
    for line in sys.stdin:
        count += 1
        input_line = line.split()
        try:
            file_size += int(input_line[-1])
            code = input_line[-2]
            if code in status_codes:
                status_codes[code] += 1
        except Exception:
            pass
        if count % 10 == 0:
            print_status_codes(status_codes, file_size)
    print_status_codes(status_codes, file_size)
except KeyboardInterrupt:
    print_status_codes(status_codes, file_size)
    raise