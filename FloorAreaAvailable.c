/*
Author : Tony Yin
This function takes three inputs: the two-dimensional array containing the data for the yard floor, cell length, and cell width that returns the
usable floor area that is not currently occupied by any container
*/

double FloorAreaAvailable(int floor[NUM_ROWS][NUM_COLS], double length, double width)
{
	// Declaring variables
	double free;
	double cellArea;
	int gridcell = 0;
	int i, j;

	// Using nested for loop to count number of grid cells in the array
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {
			if (floor[i][j] == VACANT) {
				gridcell++;
			}
		}
	}

	// Calculating cell area
	cellArea = length * width;

	// Calculating usable floor area
	free = gridcell * cellArea;

	return free;
}