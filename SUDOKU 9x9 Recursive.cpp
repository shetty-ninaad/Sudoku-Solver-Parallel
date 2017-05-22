#include <stdio.h>
 
int grid[9][9];
int count=0;
void print_solution(void)
{
  static int nsol = 0;
  int r, c;
 
  printf("\n   * SOLUTION %d *\n\n\t", ++nsol);
  for (r = 0; r < 9; r++)
  {
    for (c = 0; c < 9; c++)
    {
      printf("%d", grid[r][c]);
      if (c % 3 == 2) printf("  ");
    }
    printf("\n\t");
    if (r % 3 == 2) printf("\n\t");
  }
 
}
 
int safe(int row, int col, int n)
{
  int r, c, br, bc;
 count ++;
  if (grid[row][col] == n) return 1;
  if (grid[row][col] != 0) return 0;
  for (c = 0; c < 9; c++)
    if (grid[row][c] == n) return 0;
  for (r = 0; r < 9; r++)
    if (grid[r][col] == n) return 0;
  br = row / 3;
  bc = col / 3;
  for (r = br * 3; r < (br + 1) * 3; r++)
    for (c = bc * 3; c < (bc + 1) * 3; c++)
      if (grid[r][c] == n) return 0;
 
  return 1;
}
 
void solve(int row, int col)
{
  int n, t;
 
  if (row == 9)
    print_solution();
  else
    for (n = 1; n <= 9; n++)
      if (safe(row, col, n)) {
	t = grid[row][col];
	grid[row][col] = n;
	if (col == 8)
	  solve(row + 1, 0);
	else
	  solve(row, col + 1);
 
	grid[row][col] = t;
      }
}
 
int
main()
{
  int i, j;
 
  printf("\n   Enter the SUDOKU INPUT (9x9): \n\n");
  for(i=0;i<9;i++)
    for(j=0;j<9;j++)
    {
      scanf("%d", &grid[i][j]);
    }
  solve(0,0);
  printf("\n\n Count : %d",count);
  return 0;
}
/* 
QUESTION 1

9 0 0 0 0 7 1 0 0
0 0 0 8 0 2 0 7 0
5 7 0 1 6 3 0 0 0
0 0 5 4 0 0 9 3 6
0 0 1 0 0 0 2 0 0
3 2 6 0 0 9 8 0 0
0 0 0 9 1 6 0 8 3
0 6 0 3 0 5 0 0 0
0 0 3 2 0 0 0 0 1

QUESTON 2

0 0 0 0 0 0 0 0 0
0 0 0 0 0 3 0 8 5
0 0 1 0 2 0 0 0 0
0 0 0 5 0 7 0 0 0
0 0 4 0 0 0 1 0 0
0 9 0 0 0 0 0 0 0
5 0 0 0 0 0 0 7 3
0 0 2 0 1 0 0 0 0
0 0 0 0 4 0 0 0 9
*/
