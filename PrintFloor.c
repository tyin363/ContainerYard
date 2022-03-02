/*
Author : Tony Yin
This function takes one input which is the two-dimensional array containing the data for the floor and prints the floor grid
*/

void PrintFloor(int floor[NUM_ROWS][NUM_COLS])
{
	// Declaring variables i and j
	int i, j;

	// Using a nested for loop to print each value in the array with their corresponding character
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {

			// Using an if statement to print the ' ' character if the element is 0 (i.e. vacant)
			if (floor[i][j] == VACANT) {
				printf(" ");
			}

			// Using an else if statement to print the '@' character if the element is -1 (i.e. boundary)
			else if (floor[i][j] == BOUNDARY) {
				printf("@");
			}

			// Using an else if statement to print the 'U' character if the element is -2 (i.e. entry)
			else if (floor[i][j] == ENTRY) {
				printf("U");
			}

			// Using an else if statement to print the 'X' character if the element is -3 (i.e. exit)
			else if (floor[i][j] == EXIT) {
				printf("X");
			}
		}

		// Adding a new line at the end of each row
		printf("\n");
	}

	return;
}