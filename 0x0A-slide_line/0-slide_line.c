#include "slide_line.h"

/**
 * slide_line - Merge an array of ints
 * @line: The array of integers
 * @size: Size of array
 * @direction: The direction for slide the array
 * Return: 0 on failure, 1 in success
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t ref = 0, check1 = 0, check2 = 1, tam1, tam2, aux;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	check1 = (direction == SLIDE_RIGHT) ? size - 1 : check1;
	check2 = (direction == SLIDE_RIGHT) ? size - 2 : check2;

	for (tam1 = 0; tam1 < size; tam1++)
	{
        aux = check2;
		ref = 0;
		for (tam2 = tam1 + 1; tam2 < size; tam2++)
		{
			if (line[check1] != 0 && line[check2] == line[check1])
			{
                line[check1] = line[check1] * 2;
				line[check2] = 0;
				break;
            }

			if (line[check1] == 0 && line[check2] != 0)
			{
                line[check1] = line[check2];
				line[check2] = 0;
				ref = 1;
				check2 = aux;
				tam1--;
				break;
            }

			if (line[check2] != 0)
				break;

			direction == SLIDE_LEFT ? check2++ : check2--;
		}
		if (line[check1] == 0)
			break;
		if (ref == 0)
		{
            check1 = (direction == SLIDE_LEFT) ? check1 + 1 : check1;
			check1 = (direction == SLIDE_RIGHT) ? check1 - 1 : check1;
			check2 = (direction == SLIDE_LEFT) ? check1 + 1 : check2;
			check2 = (direction == SLIDE_RIGHT) ? check1 - 1 : check2;
        }
	}
	return (1);
}