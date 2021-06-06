#include <iostream>
#include <cstring>
using namespace std;

// N x N chessboard
int N = 0;
// Function that checks if two queens are under attack
bool isSafe(char **match, int rows, int cols) 
{
    // return false if two queens are in the same col
    for (int i = 0; i < rows; i++)
        if (match[i][cols] == 'Q')
            return false;

    // return false if two queens are in same \ diagonal
    for (int i = rows, j = cols; i >= 0 && j >= 0; i--, j--)
        if (match[i][j] == 'Q')
            return false;

    // return false if two queens are in same / diagonal
    for (int i = rows, j = cols; i >= 0 && j < N; i--, j++)
        if (match[i][j] == 'Q')
            return false;

    return true;
}
//initializing count to print total number of possible solutions
int count=0;
void nQueen(char **match, int rows)
{
    // if N queens are placed, print solution
    if (rows == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << match[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        count++;
        return;
    }
	//BACKTRACKING PROCESS
    // place Queen at every square in current row 
    // and recur for each valid movement
    for (int i = 0; i < N; i++)
    {
        // checking if no two queens are under attack
        if (isSafe(match, rows, i))
        {
            // if condition is satisfied,place queen on current square
            match[rows][i] = 'Q';

            // recur for next row
            nQueen(match, rows + 1);
			
			//if two queens are under attack then,
            //backtrack and remove queen from current square, replace with '-'
            match[rows][i] = '-';
        }
    }
}

int main()
{
    // **match keeps track of position of Queens.
    cout<<"ENTER NUMBER OF QUEENS \n";
    cin>>N;
    // Create a 2D char array using pointer (match is pointer of pointer)
    char **match;
    //allocating memory to N.
    match = new char *[N];
    for (int i = 0; i < N; i++)
    {
        match[i] = new char[N];
    }
    
    // filling all the leftover spaces with '-'
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            match[i][j] = '-';
        }
        
    }
 
    nQueen(match, 0);
    cout<<"TOTAL NUMBER OF POSSIBLE ARRANGEMENTS ARE : ";
    cout<<count<<endl;
    return 0;
}
