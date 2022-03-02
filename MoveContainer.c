/*
Author: Tony Yin
This function takes six inputs : the two-dimensional array representing the floor, four integer values representing the position of the container to move and one integer value representing whether the container
is blocked from both front and back (length-wise) and updates the position of a container that moves.
*/

// Function prototype declaration;
int CanPlace(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction);
void PlaceContainer(int floor[NUM_ROWS][NUM_COLS], int place, char letter, int direction, int size, int position);
char CurrentLetter(int floor[NUM_ROWS][NUM_COLS]);
void InitialiseFloor(int floor[NUM_ROWS][NUM_COLS], char entryboundary, int index);
void PrintFloor(int floor[NUM_ROWS][NUM_COLS]);
void AddContainer(int floor[NUM_ROWS][NUM_COLS], int position, int size, int direction);
int LocateContainer(int floor[NUM_ROWS][NUM_COLS], char move, int* rowStart, int* colStart, int* rowEnd, int* colEnd);
int MoveContainer(int floor[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1, int isBlocked);
int IfHorizontal(int r0, int r1);
int IfVertical(int c0, int c1);

int MoveContainer(int floor[NUM_ROWS][NUM_COLS], int r0, int c0, int r1, int c1, int isBlocked)
{

	// Declaring and initialising variables
	int i = 1;
	int j = 1;
	int k = 0;
	int l = 0;
	int blockedBy = 0;
	char letter = floor[r0][c0];

	// If container is not blocked
	if (isBlocked == 1) {

		// If the container is horizontal
		if (IfHorizontal(r0, r1)) {

			// If the horizontal container can move left - move the container as far as possible towards the left 
			if (floor[r0][c0 - 1] == 0) {
				while (floor[r0][c0 - i] == 0) {
					floor[r0][c0 - i] = letter;
					floor[r0][c1 - k] = VACANT;
					i++;
					k++;
				}

				if (floor[r0][c0 - (k + 1)] == ENTRY) {
					blockedBy = 1;
				}
				else if (floor[r0][c0 - (k + 1)] == EXIT) {
					blockedBy = 2;
				}
			}

			// Else if the horizontal container can only move right - move the container as far as possible towards the right 
			else {
				while (floor[r0][c1 + i] == 0) {
					floor[r0][c1 + i] = letter;
					floor[r0][c0 + k] = VACANT;
					i++;
					k++;
				}

				if (floor[r0][c1 + (k + 1)] == ENTRY) {
					blockedBy = 1;
				}
				else if (floor[r0][c1 + (k + 1)] == EXIT) {
					blockedBy = 2;
				}
			}
		}

		// Else if the container is vertical
		else if (IfVertical(c0, c1)) {

			// If the vertical container can move up - move the container as far as possibles upwards
			if (floor[r0 - 1][c0] == 0) {
				while (floor[r0 - j][c0] == 0) {
					floor[r0 - j][c0] = letter;
					floor[r1 - l][c0] = VACANT;
					j++;
					l++;
				}

				if (floor[r0 - (l + 1)][c0] == ENTRY) {
					blockedBy = 1;
				}
				else if (floor[r0 - (l + 1)][c0] == EXIT) {
					blockedBy = 2;
				}
			}

			// Else if the vertical container can only move down - move the container as far as possibles downwards
			else {
				while (floor[r1 + j][c1] == 0) {
					floor[r1 + j][c0] = letter;
					floor[r0 + l][c0] = VACANT;
					j++;
					l++;
				}

				if (floor[r1 + (l + 1)][c0] == ENTRY) {
					blockedBy = 1;
				}
				else if (floor[r1 + (l + 1)][c0] == EXIT) {
					blockedBy = 2;
				}
			}
		}
	}

	// Else if the container is blocked
	else {

		// If container is horizontal
		if (IfHorizontal(r0, r1)) {

			// Return 2 if blocked horizontal container is next an exit
			if ((floor[r0][c0 - 1] == EXIT) || (floor[r1][c1 + 1] == EXIT)) {
				blockedBy = 2;
			}

			// Return 1 if blocked horizontal container is next an entry
			else if ((floor[r0][c0 - 1] == ENTRY) || (floor[r1][c1 + 1] == ENTRY)) {
				blockedBy = 1;
			}

			// Else return -1
			else {
				blockedBy = -1;
			}
		}

		// If container is vertical
		else if (IfVertical(c0, c1)) {

			// Return 2 if blocked vertical container is next an exit
			if ((floor[r0 - 1][c0] == EXIT) || (floor[r1 + 1][c1] == EXIT)) {
				blockedBy = 2;
			}

			// Return 1 if blocked vertical container is next an entry
			else if ((floor[r0 - 1][c0] == ENTRY) || (floor[r1 + 1][c1] == ENTRY)) {
				blockedBy = 1;
			}

			// Else return -1
			else {
				blockedBy = -1;
			}
		}

	}
	return blockedBy;

}


// Helper functtion to check if container is horizontal
int IfHorizontal(int r0, int r1)
{
	int IsHorizontal = 0;
	if (r0 == r1) {
		IsHorizontal = 1;
	}
	return IsHorizontal;
}


// Helper functtion to check if container is vertical
int IfVertical(int c0, int c1)
{
	int IsVertical = 0;
	if (c0 == c1) {
		IsVertical = 1;
	}
	return IsVertical;
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

/*
Author : Tony Yin
This function takes four inputs : the two-dimensional array representing the floor grid, the position or location of the container, the size of the container and the direction of the container
and adds containers to the floor grid depending on the corresponding inputs
*/

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

		// Checking if vertical horizontal can be placed
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
This function takes six inputs: the two dimensional array representing the yard floor, the letter representing the container being searched for (e.g. 'A' or 'C') and four pointer variables
which will be used to store the result of the function call and locates the position of any container and checks if the container can move at least once in the direction along the alignment
of the container
*/

int LocateContainer(int floor[NUM_ROWS][NUM_COLS], char move, int* rowStart, int* colStart, int* rowEnd, int* colEnd)
{
	// Declaring and intialising variables
	int CanMove = 0;
	int i;
	int j;
	int position = 0;
	int position_row = 0;
	int position_col = 0;
	int stop = 1;

	// Using nested for loop to find position of container
	for (i = 0; (i < NUM_ROWS) && stop; i++) {
		for (j = 0; j < (NUM_COLS) && stop; j++) {
			if (floor[i][j] == move) {
				stop = 0;
			}
			position++;
		}
	}

	position--;

	// Using while loop to find position row and position column
	while (position - NUM_ROWS >= 0) {
		position_row++;
		position = position - NUM_ROWS;
		position_col = position;

	}

	// Initialisating pointer variables
	*rowStart = position_row;
	*colStart = position_col;
	*rowEnd = position_row;
	*colEnd = position_col;

	// Using while loop to find column end of a container
	while (floor[position_row][position_col + 1] == move) {
		*colEnd = *colEnd + 1;
		position_col++;

	}

	// Using while loop to find row end of a container
	while (floor[position_row + 1][position_col] == move) {
		*rowEnd = *rowEnd + 1;
		position_row++;
	}

	// Using if statement to determine if horizontal container can move at least once in the horizontal direction
	if (*rowStart == *rowEnd) {
		if ((floor[*rowStart][*colStart - 1] == 0) || (floor[*rowEnd][*colEnd + 1] == 0)) {
			CanMove = 1;
		}
	}

	// Using if statement to determine if vertical container can move at least once in the vertical direction
	if (*colStart == *colEnd) {
		if ((floor[*rowStart - 1][*colStart] == 0) || (floor[*rowEnd + 1][*colEnd] == 0)) {
			CanMove = 1;
		}
	}
	return CanMove;
}


