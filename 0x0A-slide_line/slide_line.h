#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

int slide_line(int *line, size_t size, int direction);

#endif