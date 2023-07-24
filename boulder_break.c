/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

/***********************************************************/
/***********************************************************/
/******* ADD THE REQUIRED FUNCTIONS BELOW THIS POINT *******/
/***********************************************************/
/***********************************************************/

void InitialiseStory(char* paragraph)
{
	char temp[13][60] = { {"A long time ago in a galaxy far, far away, a young Jedi\n"},
	{"was wandering the deserts of Tatooine in search of the\n"},
	{"mythical Darksaber. But, as soon as he reached Deagle\n"},
	{"Mountain, where the Darksaber was being protected by the\n"},
	{"Guardians, he got attacked by Tusken Raiders. While\n"},
	{"fighting them, he fell into a deep hole. After he stood\n"},
	{"up, he saw in front of his eyes, the Darksaber. But he\n"},
	{"also realised that he was trapped in a cave whose exit was\n"},
	{"blocked by a massive hole. The Jedi cut a huge chunk of\n"},
	{"the cave wall in the shape of a boulder. Help the young\n"},
	{"Jedi obtain the Darksaber and exit the cave by rolling the\n"},
	{"boulder into the hole\n"} };

	int i, k = 0;

	for (i = 0; i < 11; i++) {

		int j = 0;
		while (temp[i][j] != '\0') {

			paragraph[k] = temp[i][j];

			j++;
			k++;

		}

	}
	paragraph[k] = '\0';
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;

	for (i = 0; i < CAVE_SIZE; i++) {

		for (j = 0; j < CAVE_SIZE; j++) {

			if (cave[i][j] == 1) {

				//wall
				printf("%c", '#');

			}
			else if (cave[i][j] == 3) {

				//person
				printf("%c", 'X');

			}
			else if (cave[i][j] == 4) {

				//hole
				printf("%c", '*');

			}
			else if (cave[i][j] == 5) {

				//treasure
				printf("%c", '+');

			}
			else if (cave[i][j] == 6) {

				//boulder
				printf("%c", 'O');

			}
			else {

				//emptyspace
				printf("%c", ' ');

			}

		}
		printf("\n");

	}

}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout)
{
	int i = 0, j, k;

	while (layout[i] != '\0') {

		for (j = 0; j < CAVE_SIZE; j++) {

			for (k = 0; k < CAVE_SIZE; k++) {

				if (layout[i] == '1') {

					cave[j][k] = 1;

				}
				else if (layout[i] == '0') {

					cave[j][k] = 0;

				}
				else if (layout[i] == 'E') {

					cave[j][k] = 2;

				}
				i++;

			}

		}



	}
}


int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{

	int i, j;

	for (i = 0; i < CAVE_SIZE; i++) {

		if ((i == 0) || (i == CAVE_SIZE - 1)) {

			for (j = 0; j < CAVE_SIZE; j++) {

				if (cave[i][j] == 0) {

					return 0;

				}

			}

		}
		else {

			if ((cave[i][0] == 0) || (cave[i][CAVE_SIZE - 1] == 0)) {

				return 0;

			}

		}



	}
	return 1;

}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{

	int i, j, count = 0;

	for (i = 0; i < CAVE_SIZE; i++) {

		for (j = 0; j < CAVE_SIZE; j++) {

			if (cave[i][j] == 2) {

				count++;

			}

		}
	}

	if (count == 1) {

		return 1;

	}
	else {

		return 0;

	}

}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{

	int i, j, outPut = 0;

	for (i = 0; i < CAVE_SIZE; i++) {

		if ((i == 0) || (i == CAVE_SIZE - 1)) {

			for (j = 0; j < CAVE_SIZE; j++) {

				if (cave[i][j] == 2) {

					outPut = 1;

				}

			}

		}
		else {

			if ((cave[i][0] == 2) || (cave[i][CAVE_SIZE - 1] == 2)) {

				outPut = 1;

			}

		}
		if ((cave[0][0] == 2) || (cave[0][CAVE_SIZE - 1] == 2) || (cave[CAVE_SIZE - 1][CAVE_SIZE - 1] == 2) || (cave[CAVE_SIZE - 1][0] == 2)) {

			outPut = 0;

		}



	}
	return outPut;


}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char* element)
{
	if ((row >= CAVE_SIZE) || (col >= CAVE_SIZE)) {

		return;

	}
	else if (cave[row][col] == 0) {

		if (element[0] == 'p') {

			int i, j, count = 0;

			for (i = 0; i < CAVE_SIZE; i++) {

				for (j = 0; j < CAVE_SIZE; j++) {

					if (cave[i][j] == 3) {

						count++;

					}

				}
			}

			if (count == 0) {

				cave[row][col] = 3;

			}
			else {

				return;

			}

		}
		else if (element[0] == 'h') {

			cave[row][col] = 4;

		}
		else if (element[0] == 't') {

			cave[row][col] = 5;

		}
		else if (element[0] == 'b') {

			cave[row][col] = 6;

		}
		else {

			return;

		}

	}

}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{

	int temp[CAVE_SIZE][CAVE_SIZE] = { 0 };
	int i, j;

	for (i = 0; i < CAVE_SIZE; i++) {

		for (j = 0; j < CAVE_SIZE; j++) {

			temp[i][j] = cave[CAVE_SIZE - j - 1][i];

		}

	}

	for (i = 0; i < CAVE_SIZE; i++) {

		for (j = 0; j < CAVE_SIZE; j++) {

			cave[i][j] = temp[i][j];

		}

	}

}


int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{

	int i, j;

	if (move == 'w') {

		for (i = 0; i < CAVE_SIZE; i++) {

			for (j = 0; j < CAVE_SIZE; j++) {

				if (cave[i][j] == 3) {

					if (cave[i - 1][j] == 1) {

						return 0;

					}
					else if (cave[i - 1][j] == 6) {

						int k = i - 1;
						while ((cave[k - 1][j] == 0) || (cave[k - 1][j] == 4)) {

							if (cave[k - 1][j] == 4) {

								cave[k][j] = 0;
								cave[k - 1][j] = 0;

								return 0;


							}
							else {

								cave[k][j] = 0;
								cave[k - 1][j] = 6;

							}
							k--;
						}

					}
					else if (cave[i - 1][j] == 4) {

						cave[i][j] = 0;

						return 1;

					}
					else if (cave[i - 1][j] == 2) {

						cave[i][j] = 0;

						cave[i - 1][j] = 3;

						return 2;

					}
					else {

						cave[i][j] = 0;

						cave[i - 1][j] = 3;

						return 0;

					}


				}



			}

		}
		return 0;

	}
	else if (move == 'a') {

		for (i = 0; i < CAVE_SIZE; i++) {

			for (j = 0; j < CAVE_SIZE; j++) {

				if (cave[i][j] == 3) {

					if (cave[i][j - 1] == 1) {

						return 0;

					}
					else if (cave[i][j - 1] == 6) {

						int k = j - 1;
						while ((cave[i][k - 1] == 0) || (cave[i][k - 1] == 4)) {

							if (cave[i][k - 1] == 4) {

								cave[i][k] = 0;
								cave[i][k - 1] = 0;

								return 0;

							}
							else {

								cave[i][k] = 0;
								cave[i][k - 1] = 6;



							}


							k--;
						}
					}
					else if (cave[i][j - 1] == 4) {

						cave[i][j] = 0;

						return 1;

					}
					else if (cave[i][j - 1] == 2) {

						cave[i][j] = 0;

						cave[i][j - 1] = 3;

						return 2;

					}
					else {

						cave[i][j] = 0;

						cave[i][j - 1] = 3;

						return 0;

					}


				}



			}

		}
		return 0;

	}
	else if (move == 's') {

		for (i = 0; i < CAVE_SIZE; i++) {

			for (j = 0; j < CAVE_SIZE; j++) {

				if (cave[i][j] == 3) {

					if (cave[i + 1][j] == 1) {

						return 0;

					}
					else if (cave[i + 1][j] == 6) {

						int k = i + 1;
						while ((cave[k + 1][j] == 0) || (cave[k + 1][j] == 4)) {

							if (cave[k + 1][j] == 4) {

								cave[k][j] = 0;
								cave[k + 1][j] = 0;

								return 0;

							}
							else {

								cave[k][j] = 0;
								cave[k + 1][j] = 6;



							}

							k++;
						}
					}
					else if (cave[i + 1][j] == 4) {

						cave[i][j] = 0;

						return 1;

					}
					else if (cave[i + 1][j] == 2) {

						cave[i][j] = 0;

						cave[i + 1][j] = 3;

						return 2;

					}
					else {

						cave[i][j] = 0;

						cave[i + 1][j] = 3;

						return 0;

					}


				}



			}

		}
		return 0;

	}
	else if (move == 'd') {

		for (i = 0; i < CAVE_SIZE; i++) {

			for (j = 0; j < CAVE_SIZE; j++) {

				if (cave[i][j] == 3) {

					if (cave[i][j + 1] == 1) {

						return 0;

					}
					else if (cave[i][j + 1] == 6) {

						int k = j + 1;
						while ((cave[i][k + 1] == 0) || (cave[i][k + 1] == 4)) {

							if (cave[i][k + 1] == 4) {

								cave[i][k] = 0;
								cave[i][k + 1] = 0;

								return 0;

							}
							else {

								cave[i][k] = 0;
								cave[i][k + 1] = 6;



							}

							k++;
						}
					}
					else if (cave[i][j + 1] == 4) {

						cave[i][j] = 0;

						return 1;

					}
					else if (cave[i][j + 1] == 2) {

						cave[i][j] = 0;

						cave[i][j + 1] = 3;

						return 2;

					}
					else {

						cave[i][j] = 0;

						cave[i][j + 1] = 3;

						return 0;

					}


				}



			}

		}
		return 0;

	}
	else {

		return 0;

	}

}




/***********************************************************/
/***********************************************************/
/********* DO NOT MODIFY ANY CODE BELOW THIS POINT *********/
/***********************************************************/
/***********************************************************/

/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	int gameOver = 0;

	InitialiseStory(story);
	InitialiseCave(cave, layout);
	AddItem(cave, 2, 4, "boulder");
	AddItem(cave, 5, 6, "boulder");
	AddItem(cave, 4, 8, "hole");
	AddItem(cave, 1, 4, "treasure");
	AddItem(cave, 4, 5, "player");

	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}