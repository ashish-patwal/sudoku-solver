<<< Sudoku solver >>> 

<< Main technique used >> 
Recursion and backtracking techinques

<< Brief overview of functions included >> 

void print() : prints the solved matrix .

void rowcheck() : checks for the occurence of given element in same row . returns false on occurence and true on non-occurence .

void colcheck() : checks for the occurence of given element in same column . returns false on occurence and true on non-occurence .

void boxcheck() : checks for the occurence of given element in it's respective box of 9 elements . returns false on occurence and ture on non-occurence.

void solve() : solves the matrix based on backtracking and recursive techniques . used functions rowcheck , colcheck , boxcheck to find correct spaces to fill digits . 

<< Entering Matrix >>

To enter matix :
in the main() section change the matrix[N][N] value .


<< Compilation & Execution >>

platform : linux/arch

compiling command > g++ -std=c++2a sudolu_final.cpp
execution command > ./a.out

submitted by : Ashish Patwal (Section C IIIrd Sem)
