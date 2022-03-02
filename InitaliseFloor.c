/*
Author : Tony Yin
This function takes three inputs : a two-dimensional array that represents the floor, a character that indicates which of the four boundaries souch contain the entry and an integer
that indicates how many rows dows from the top (or columns across from the left) the entry or exit poistion should be placed on the specified wall and initializes the floor grid
with the corresponding inputs
*/

void InitialiseFloor(int floor[NUM_ROWS][NUM_COLS], char entryboundary, int index)
{
	// Declaring variables i and j
	int i, j;

	// Using a nested for loop to set all elements in the array to 0
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {

			floor[i][j] = VACANT;
		}
	}
	
	// Using a nested for loop to set all elements on the boundaries of the array to -1
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {

			floor[0][j] = BOUNDARY;
			floor[NUM_ROWS-1][j] = BOUNDARY;
			floor[i][0] = BOUNDARY;
			floor[i][NUM_COLS-1] = BOUNDARY;
		}
	}

	// Using an if statement to set entry/exit values to the corresponding index if the entry boundary is 'T'
	if (entryboundary == 'T') {
		floor[0][index] = ENTRY;
		floor[NUM_ROWS - 1][index] = EXIT;
	}

	// Using an else if statement to set entry/exit values to the corresponding index if the entry boundary is 'R'
	else if (entryboundary == 'R') {
		floor[index][NUM_COLS - 1] = ENTRY;
		floor[index][0] = EXIT;
	}

	// Using an else if statement to set entry/exit values to the corresponding index if the entry boundary is 'L'
	else if (entryboundary == 'L') {
		floor[index][0] = ENTRY;
		floor[index] [NUM_COLS - 1] = EXIT;
	}

	// Using an else if statement to set entry/exit values to the corresponding index if the entry boundary is 'B'
	else if (entryboundary == 'B') {
		floor[NUM_ROWS - 1][index] = ENTRY;
		floor[0][index] = EXIT;
	}

	return;
}
    