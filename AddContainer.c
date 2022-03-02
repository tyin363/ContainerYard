/*
Author : Tony Yin
This function takes four inputs : the two-dimensional array representing the floor grid, the position or location of the container, the size of the container and the direction of the container
and adds containers to the floor grid depending on the corresponding inputs
*/

// Function prototype declaration
int CanPlace(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction);
void PlaceContainer(int floor[NUM_ROWS][NUM_COLS], int place, char letter, int direction, int size, int position);
char CurrentLetter(int floor[NUM_ROWS][NUM_COLS]);
void InitialiseFloor(int floor[NUM_ROWS][NUM_COLS], char entryboundary, int index);
void PrintFloor(int floor[NUM_ROWS][NUM_COLS]);
void AddContainer(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction);

void AddContainer(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction)
{
	// Declaring and initialising variables letter and place to the output of the corresponding helper functions 
	char letter = CurrentLetter(floor);
	int place = CanPlace(floor, position, size, direction);

	// Adding container to the floor grid
	PlaceContainer(floor, place, letter, direction, size, position);
	return;
}

// Helper function to place the container
void PlaceContainer(int floor[NUM_ROWS][NUM_COLS], int place, char letter, int direction, int size, int position)
{
	// Delcaring and intialising variables
	int position_row = 0;
	int position_col = 0;
	int i = 0;
	int j = 0;

	// Using while loop to determine position row and column
	while (position - NUM_ROWS >= 0) {
		position_row++;
		position = position - NUM_ROWS;
		position_col = position;

	}

	if (place) {
		// Placing container in the vertical direction 
		if (direction) {
			while (i < size) {
				floor[position_row][position_col] = letter;
				position_row++;
				i++;
			}
		}
		// Placing container in the horizontal direction
		else {
			while (j < size) {
				floor[position_row][position_col] = letter;
				position_col++;
				j++;
			}

		}
	}

}

// Helper funciton to determine letter of the current container
char CurrentLetter(int floor[NUM_ROWS][NUM_COLS])
{
	// Declaring and initialising variables
	int i, j;
	char letter = 'A';

	// Using nested for loop to determine current letter 
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {
			if ((floor[i][j] >= letter) && (floor[i][j] != 0)) {
				letter = floor[i][j] + 1;
			}
		}
	}
	return letter;
}

// Helper function to determine whether current container can be placed
int CanPlace(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction)
{
	// Declaring and intialising variables
	int place = 1;
	int position_row = 0;
	int position_col = 0;
	int i = 0;
	int j = 0;

	// Using while loop to determine position row and column
	while (position - NUM_ROWS >= 0) {
		position_row++;
		position = position - NUM_ROWS;
		position_col = position;

	}

	// Changing boolean variable place to false if position row or column is outside of floor grid
	if ((position_row < 0) || (position_row >= NUM_ROWS) || (position_col < 0) || (position_col >= NUM_COLS) || (size == 1)) {
		place = 0;
	}

	if (place) {
		// Checking if vertical container can be placed
		if (direction) {
			while (i < size) {
				if (floor[position_row][position_col] != 0) {
					place = 0;
				}
				position_row++;
				i++;
			}
		}

		// Checking if horizontal container can be placed
		else {
			while (j < size) {
				if (floor[position_row][position_col] != 0) {
					place = 0;
				}
				position_col++;
				j++;
			}

		}
	}

	return place;
}

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

	// Using a nested for loop to set all elements on the boundary of the array to -1
	for (i = 0; i < NUM_ROWS; i++) {
		for (j = 0; j < NUM_COLS; j++) {

			floor[0][j] = BOUNDARY;
			floor[NUM_ROWS - 1][j] = BOUNDARY;
			floor[i][0] = BOUNDARY;
			floor[i][NUM_COLS - 1] = BOUNDARY;
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
		floor[index][NUM_COLS - 1] = EXIT;
	}

	// Using an else if statement to set entry/exit values to the corresponding index if the entry boundary is 'B'
	else if (entryboundary == 'B') {
		floor[NUM_ROWS - 1][index] = ENTRY;
		floor[0][index] = EXIT;
	}

	return;
}

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
			else {
				printf("%c", floor[i][j]);
			}
		}

		// Adding a new line at the end of each row
		printf("\n");
	}

	return;
}