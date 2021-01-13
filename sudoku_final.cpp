#include <iostream>

using namespace std;

#define N 9

#define rep(i, a, b) for (int i = a; i < b; i++)

void print(int arr[N][N]) {
  rep(i, 0, N) {
    rep(j, 0, N) cout << arr[i][j] << " ";
    cout << endl;
  }
}

bool rowcheck(int matrix[N][N], int row, int num) {
  rep(i, 0, N) if (matrix[row][i] == num) return false;
  return true;
}

bool colcheck(int matrix[N][N], int col, int num) {
  rep(i, 0, N) if (matrix[i][col] == num) return false;
  return true;
}

bool boxcheck(int matrix[N][N], int row, int col, int num) {

  int boxrow = row - row % 3;
  int boxcol = col - col % 3;

  rep(i, 0, 3)
      rep(j, 0, 3) if (matrix[i + boxrow][j + boxcol] == num) return false;
  return true;
}

bool solve(int matrix[N][N], int row, int col) {

  if (row == N - 1 && col == N)
    return true;

  if (col == N) {
    row++;
    col = 0;
  }

  if (matrix[row][col] > 0)
    return solve(matrix, row, col + 1);

  for (int num = 1; num <= N; num++) {
    if (rowcheck(matrix, row, num) && colcheck(matrix, col, num) &&
        boxcheck(matrix, row, col, num)) {
      matrix[row][col] = num;

      if (solve(matrix, row, col + 1))
        return true;
    }
    matrix[row][col] = 0;
  }
  return false;
}

int main() {

  int matrix[N][N] = {{0, 0, 9, 0, 0, 0, 0, 0, 6}, {3, 4, 1, 0, 0, 8, 0, 0, 0},
                      {0, 0, 7, 0, 0, 5, 0, 0, 0}, {4, 0, 5, 2, 0, 0, 0, 8, 0},
                      {7, 0, 0, 0, 6, 0, 0, 0, 2}, {0, 6, 0, 0, 0, 3, 4, 0, 9},
                      {0, 0, 0, 3, 0, 0, 1, 0, 0}, {0, 0, 0, 5, 0, 0, 2, 6, 3},
                      {5, 0, 0, 0, 0, 0, 8, 0, 0}};

  if (solve(matrix, 0, 0))
    print(matrix);
  else
    cout << "No solution" << endl;

  return 0;
}
