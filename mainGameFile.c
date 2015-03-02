/*
Austin Bower
CS240
Group Project 1 - Maze
*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

void PrintMaze(char array[][22], int rows, int cols);
void StoreMaze(char array[][22], int rows, int cols, FILE *file);
int MazeTraversal(char array[][22], int rows, int cols, int timeLimit);

int main()
{
    int mazeCols = 22;
	int mazeRows = 21;
	//Open up the file, read in the text file data into an array, print the array, and close the file as we won't need it again
	FILE *file1 = fopen("maze1.txt", "r");
	char mazeOne[mazeRows][mazeCols];
	StoreMaze(mazeOne, mazeRows, mazeCols, file1);
	fclose(file1);

    FILE *file2 = fopen("maze2.txt", "r");
	char mazeTwo[mazeRows][mazeCols];
	StoreMaze(mazeTwo, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file3 = fopen("maze3.txt", "r");
	char mazeThree[mazeRows][mazeCols];
	StoreMaze(mazeThree, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file4 = fopen("maze4.txt", "r");
	char mazeFour[mazeRows][mazeCols];
	StoreMaze(mazeFour, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file5 = fopen("maze5.txt", "r");
	char mazeFive[mazeRows][mazeCols];
	StoreMaze(mazeFive, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file6 = fopen("maze6.txt", "r");
	char mazeSix[mazeRows][mazeCols];
	StoreMaze(mazeSix, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file7 = fopen("maze7.txt", "r");
	char mazeSeven[mazeRows][mazeCols];
	StoreMaze(mazeSeven, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file8 = fopen("maze8.txt", "r");
	char mazeEight[mazeRows][mazeCols];
	StoreMaze(mazeEight, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file9 = fopen("maze9.txt", "r");
	char mazeNine[mazeRows][mazeCols];
	StoreMaze(mazeNine, mazeRows, mazeCols, file2);
	fclose(file2);

    FILE *file10 = fopen("maze10.txt", "r");
	char mazeTen[mazeRows][mazeCols];
	StoreMaze(mazeTen, mazeRows, mazeCols, file2);
	fclose(file2);

    //Initialize the screen, set the cursor to invisible, auto return values with getch, allow special characters, and don't show keyboard input
	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	cbreak();

    //trying to set up a timer for the maze. once it works, set up a switch case for different time limits depending on which maze is being called
	int timeLimit = 60;
	if (MazeTraversal(mazeOne, mazeRows, mazeCols, timeLimit) != 0)
    {
        printw("You succeeded!\n");
    }

	getch();
	endwin();
	return 0;
}

void PrintMaze(char array[][22], int mazeRows, int cols)
{
	int counter1 = 0;
	while (counter1 < rows)
	{
		int counter2 = 0;
		while (counter2 < cols)
		{
			printf("%c", array[counter1][counter2]);
			counter2++;
		}
		counter1++;
	}
	printf("\n\n");
}

void StoreMaze(char array[][22], int rows, int cols, FILE *file)
{
    //go through a maze .txt file and store the values in an array
    int counter1 = 0;
    while (counter1 < rows)
	{
		int counter2 = 0;
		while (counter2 < cols)
		{
			array[counter1][counter2] = fgetc(file);
			counter2++;
		}
		counter1++;
	}
}

int MazeTraversal(char array[][22], int rows, int cols, int timeLimit)
{
    //allow the user to traverse through the maze
    int success = 0; //if zero, then the user failed. if nonzero, the user succeeded

    //Create variables for starting and ending position and then figure out what they should be set to
	int curRow;
	int curCol;
	int endRow;
	int endCol;
	int counter1 = 0;
	while (counter1 < rows)
	{
		int counter2 = 0;
		while (counter2 < cols)
		{
			if (mazeArray[counter1][counter2] == 'X')
			{
				curRow = counter1;
				curCol = counter2;
			}
			if (mazeArray[counter1][counter2] == 'O')
			{
				endRow = counter1;
				endCol = counter2;
			}

			counter2++;
		}
		counter1++;
	}
	//Run the loop that will contain the maze movement operations
	time_t startTime = time();
	while (1)
	{
		clear();
		refresh();
		printw("Use the arrow keys to navigate the X through the maze\n");
		PrintMaze(mazeArray, rows, cols);
		int input = getch();
		switch (input)
		{
			case KEY_UP:
				if (curRow > 1)
				{
					if (mazeArray[curRow-1][curCol] == ' ')
					{
						if (mazeArray[curRow-2][curCol] == ' ' || mazeArray[curRow-2][curCol] == 'O')
						{
							mazeArray[curRow][curCol] = ' ';
							mazeArray[curRow-2][curCol] = 'X';
							curRow = curRow - 2;
						}
					}
				}
				break;
			case KEY_RIGHT:
				if (curCol < 19)
				{
					if (mazeArray[curRow][curCol+1] == ' ')
					{
						if (mazeArray[curRow][curCol+2] == ' ' || mazeArray[curRow][curCol+2] == 'O')
						{
							mazeArray[curRow][curCol] = ' ';
							mazeArray[curRow][curCol+2] = 'X';
							curCol = curCol + 2;
						}
					}
				}
				break;
			case KEY_DOWN:
				if (curRow < 19)
				{
					if (mazeArray[curRow+1][curCol] == ' ')
					{
						if (mazeArray[curRow+2][curCol] == ' ' || mazeArray[curRow+2][curCol] == 'O')
						{
							mazeArray[curRow][curCol] = ' ';
							mazeArray[curRow+2][curCol] = 'X';
							curRow = curRow + 2;
						}
					}
				}
				break;
			case KEY_LEFT:
				if (curCol > 1)
				{
					if (mazeArray[curRow][curCol-1] == ' ')
					{
						if (mazeArray[curRow][curCol-2] == ' ' || mazeArray[curRow][curCol-2] == 'O')
						{
							mazeArray[curRow][curCol] = ' ';
							mazeArray[curRow][curCol-2] = 'X';
							curCol = curCol - 2;
						}
					}
				}
				break;
			default:
				break;
		}
		if (curRow == endRow)
		{
			if (curCol == endCol)
			{
			    time_t endTime = time();
				clear();
				refresh();
				PrintMaze(mazeArray, rows, cols);
				printw("GAME OVER, YOU WIN!");
				break;
			}
		}
	}
    if (startTime - endTime <= timeLimit)
    {
        success = 1;
    }
    return success;
}