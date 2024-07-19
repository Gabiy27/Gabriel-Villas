#include <stdio.h>
/* Group 29 : ALFONSO, QUIRANTE, VILLAS */
// Divider functions
void displayDivider1() { printf("\t---------------------\n"); }
// Displays Divider
void displayDivider2() { printf("\t=====================\n"); }
void displayHeader() {
 // display heading
 displayDivider1();
 printf("\t 1v1 Magic Squares \n");
 displayDivider2();
}
// Displays Board Game
void displayBoard(char cBoardDisplay[][3]) {
 displayHeader ();
 printf("\n");
 printf("\t ___[COLUMN]___\n");
 printf("\t 1 2 3\n");
 printf("\t -------------\n");
 printf("\t | %c | %c | %c | 1| R\n", cBoardDisplay[0][0],
 cBoardDisplay[0][1], cBoardDisplay[0][2]);
 printf("\t -------------\n");
 printf("\t | %c | %c | %c | 2| O\n", cBoardDisplay[1][0],
 cBoardDisplay[1][1], cBoardDisplay[1][2]);
 printf("\t -------------\n");
 printf("\t | %c | %c | %c | 3| W\n", cBoardDisplay[2][0],
 cBoardDisplay[2][1], cBoardDisplay[2][2]);
 printf("\t -------------\n");
 printf("\n");
}
// Displays number of wins of the player
void displayScoreBoard(int *nScore1, int *nScore2) {
 displayDivider1();
 printf("\t Score Board\n");
 displayDivider2();
 printf("\n\tPlayer A \t\t [%d]\n", *nScore1);
 printf("\tPlayer B \t\t [%d]\n\n", *nScore2);
 displayDivider1();
}
// Resets the board
void resetBoardDisplay(char cBoard[][3]) {
 int i, j;
 for (i = 0; i < 3; i++) {
 for (j = 0; j < 3; j++)
 cBoard[i][j] = ' ';
 }
}
// Resets board value
void resetBoardValue(int nBoard[][3]) {
 int i, j;
 for (i = 0; i < 3; i++) {
 for (j = 0; j < 3; j++)
 nBoard[i][j] = 0;
 }
}
// Checks if the board has free space
int checkFreeSpace(char cBoardDisplay[][3]) {
 int nFreeSpaces = 9; // total no. of spaces/board tiles is 9
 int i, j;
 for (i = 0; i < 3; i++) {
 for (j = 0; j < 3; j++) {
 if (cBoardDisplay[i][j] != ' ')
 nFreeSpaces--;
 }
 }
 return nFreeSpaces;
}
// Player turn to move
void playerMove(char cBoardDisplay[][3], int nBoardValues[][3],
 int nPegValues[], int nPValSize, char cPlayer) {
 int nPeg, nPegIndex, nPegFound = 0;
 int nRow, nCol;
 int i;
 char cPeg;
 printf("\t PLAYER %c'S TURN\n\n", cPlayer);
 printf(" Pegs available: ");
 for (i = 0; i < nPValSize; i++)
 printf("%d ", nPegValues[i]);
 do {
 printf("\n\n > Select a Peg: ");
 scanf("%d", &nPeg);
 for (i = 0; i < nPValSize; i++) {
 if (nPegValues[i] == nPeg) {
 nPegIndex = i + 1;
 nPegFound = 1;
 break;
 }
 }
 if (nPegFound == 0) {
 if (nPeg >= 1 && nPeg <= 9)
 printf("\n * Peg '%d' already used. Please\n choose an "
 "available peg\n",
 nPeg);
 else
 printf("\n * Peg '%d' is not a valid peg. Please\n only "
 "choose from the given pegs.\n",
 nPeg);
 }
 } while (nPegFound != 1);
 // remove selected Peg from nPeg array
 for (i = nPegIndex - 1; i < nPValSize - 1; i++)
 nPegValues[i] = nPegValues[i + 1];
 // convert nPeg to a character
 switch (nPeg) {
 case 1:
 cPeg = '1';
 break;
 case 2:
 cPeg = '2';
 break;
 case 3:
 cPeg = '3';
 break;
 case 4:
 cPeg = '4';
 break;
 case 5:
 cPeg = '5';
 break;
 case 6:
 cPeg = '6';
 break;
 case 7:
 cPeg = '7';
 break;
 case 8:
 cPeg = '8';
 break;
 case 9:
 cPeg = '9';
 break;
 }
 do {
 printf(" > Enter row no. (1-3): ");
 scanf("%d", &nRow);
 nRow--;
 printf(" > Enter column no. (1-3): ");
 scanf("%d", &nCol);
 nCol--;
 // check if space is occupied
 if (cBoardDisplay[nRow][nCol] == ' ') {
 cBoardDisplay[nRow][nCol] = cPeg;
 nBoardValues[nRow][nCol] = nPeg;
 break;
 } else if (cBoardDisplay[nRow][nCol] != ' ') {
 if (nRow > 3 || nRow < 1 || nCol > 3 || nCol < 1)
 printf("\n * (%d, %d) is out of bounds. Please\n select a "
 "valid tile.\n\n",
 nRow + 1, nCol + 1);
 else
 printf("\n * Tile (%d, %d) already occupied. Please\n select "
 "an empty one.\n\n",
 nRow + 1, nCol + 1);
 }
 } while (cBoardDisplay[nRow][nCol] != ' ');
}
// Checks if there is a winner
char checkWinner(int nBoardValues[][3], char cPlayer) {
 int nHorSum1 = 0, nHorSum2 = 0, nHorSum3 = 0;
 int nVerSum1 = 0, nVerSum2 = 0, nVerSum3 = 0;
 int nDiaSum1 = 0, nDiaSum2 = 0;
 int i, j;
 // add row only if entire row is not empty
 if (nBoardValues[0][0] != 0 && nBoardValues[0][1] != 0 &&
 nBoardValues[0][2] != 0) {
 for (i = 0; i < 3; i++)
 nHorSum1 += nBoardValues[0][i];
 }
 if (nBoardValues[1][0] != 0 && nBoardValues[1][1] != 0 &&
 nBoardValues[1][2] != 0) {
 for (i = 0; i < 3; i++)
 nHorSum2 += nBoardValues[1][i];
 }
 if (nBoardValues[2][0] != 0 && nBoardValues[2][1] != 0 &&
 nBoardValues[2][2] != 0) {
 for (i = 0; i < 3; i++)
 nHorSum3 += nBoardValues[2][i];
 }
 // add column only if entire column is not empty
 if (nBoardValues[0][0] != 0 && nBoardValues[1][0] != 0 &&
 nBoardValues[2][0] != 0) {
 for (i = 0; i < 3; i++)
 nVerSum1 += nBoardValues[i][0];
 }
 if (nBoardValues[0][1] != 0 && nBoardValues[1][1] != 0 &&
 nBoardValues[2][1] != 0) {
 for (i = 0; i < 3; i++)
 nVerSum2 += nBoardValues[i][1];
 }
 if (nBoardValues[0][2] != 0 && nBoardValues[1][2] != 0 &&
 nBoardValues[2][2] != 0) {
 for (i = 0; i < 3; i++)
 nVerSum3 += nBoardValues[i][2];
 }
 // add diagonal only if entire diagonal is not empty
 if (nBoardValues[0][0] && nBoardValues[1][1] && nBoardValues[2][2]) {
 for (i = 0; i < 3; i++)
 nDiaSum1 += nBoardValues[i][i];
 }
 if (nBoardValues[0][2] && nBoardValues[1][1] && nBoardValues[2][0]) {
 for (i = 0; i < 3; i++) {
 for (j = 2; j >= 0; j--)
 nDiaSum2 += nBoardValues[i][j];
 }
 }
 // check rows
 if (nHorSum1 >= 15 || nHorSum2 >= 15 || nHorSum3 >= 15)
 return cPlayer;
 // check columns
 if (nVerSum1 >= 15 || nVerSum2 >= 15 || nVerSum3 >= 15)
 return cPlayer;
 // check diagonals
 if (nDiaSum1 >= 15 || nDiaSum2 >= 15)
 return cPlayer;
 return ' '; // space character represents no winner
}
// Main Menu
void mainMenu() {
 // Declaration of variables
 char cChoice, newline;
 int nScore1, nScore2;
 char cBoardDisplay[3][3];
 int nBoardValues[3][3];
 int nPegValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 int nPValSize = 9;
 char cWinner = ' '; // a space character represents no winner
 char cPlayer;
 int nTurn = 0;
 nScore1 = 0;
 nScore2 = 0;
 int c;

 // Play option
 resetBoardDisplay(cBoardDisplay);
 resetBoardValue(nBoardValues);
 while (cWinner == ' ' && checkFreeSpace(cBoardDisplay) != 0) {
 if (nTurn % 2 == 0)
 cPlayer = 'A'; // Player A makes a move every even turns
 else
 cPlayer = 'B'; // Player B makes a move every odd turns
 displayBoard(cBoardDisplay);
 playerMove(cBoardDisplay, nBoardValues, nPegValues, nPValSize, cPlayer);
 nPValSize--;
 nTurn++;
 cWinner = checkWinner(nBoardValues, cPlayer);
 if (cWinner == ' ' && checkFreeSpace(cBoardDisplay) == 0) {
 printf("\n");
 displayBoard(cBoardDisplay);
 printf("\t No Winner\n\n");
 } else if (cWinner != ' ' || checkFreeSpace(cBoardDisplay) == 0) {
 printf("\n");
 displayBoard(cBoardDisplay);
 printf("\t Player %c wins!\n\n", cPlayer);
 printf("\n\n\tThank you for playing!\n\n");
 }
 }
}
int main() {
 mainMenu();
 return 0;
}