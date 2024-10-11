#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

void CreateMatrix(vector<vector<int>>& matrix, int row, int column)
{
	matrix = vector < vector<int>>(row, vector<int>(column)); // initialize the matrix
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j]=(rand() % 50);
		}
	}
}

void PrintMatrix(vector<vector<int>>& matrix)
{
	int r = matrix.size();
	int c = matrix[0].size();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void MultiplyMatrix(vector<vector<int>>& mat1, vector<vector<int>>& mat2, vector<vector<int>>& res)
{
	int r1 = mat1.size();
	int c1 = mat1[0].size();

	int r2 = mat2.size();
	int c2 = mat2[0].size();

	if (c1 != r2)
	{
		cout << "Matrices are not the same size. Multiplication is not possible"<<endl;
		res = vector < vector<int>>(r1, vector<int>(c2, -1)); // for returning the matrix r1xc2 with -1
		PrintMatrix(res);
	}
	else
	{
		res = vector < vector<int>>(r1, vector<int>(c2, 0)); // initialize the result matrix

		for (int i = 0; i < r1; i++) // for taking the rows of first matrix and constructing the rows of result matrix 
		{
			for (int j = 0; j < c2; j++) // for taking the column of second matrix and constructing the columns of result matrix
			{
				for (int k = 0; k < c1; k++) /* for calculating the sumproduct of corresponding elements */  /* since c1=r2, any of them can be used */
				{
					res[i][j] += mat1[i][k] * mat2[k][j];
				}
			}
		}
		PrintMatrix(res);
	}	
}

int main()
{
	time_t start = time(0);
	srand(time(NULL));

	vector<vector<int>> matrix1 = { {7,8,9 }, {4, 5, 6}, {1, 2, 3}, {9, 6, 3}, {8, 5, 2}};
	vector<vector<int>> matrix2 = { {10, 1, 4, 7 }, {20, 2, 5, 8}, {30, 3, 6, 9}};
	vector<vector<int>> matrix3, matrix4, result;
	int m, n, s, t;
	
	cout << "Test case with given input" << endl;
	cout << endl << "First Matrix:" << endl;
	PrintMatrix(matrix1);
	cout << endl << "Second Matrix:" << endl;
	PrintMatrix(matrix2);

	cout << endl << "Matrix 1 * Matrix 2:" << endl;
	MultiplyMatrix(matrix1, matrix2, result);
	/* Result should be as follows:
	[500, 50, 122, 194]
	[320, 32, 77, 122]
	[140, 14, 32, 50]
	[300, 30, 84, 138]
	[240, 24, 69, 114]
	*/
	cout << endl << "Matrix 2 * Matrix 1:" << endl;
	MultiplyMatrix(matrix2, matrix1, result);


	cout << endl << "Test case with user input" << endl;
	cout << "Enter the size for first matrix: ";
	cin >> m >> n;
	cout << endl << "First Matrix:" << endl;
	CreateMatrix(matrix3, m, n);
	PrintMatrix(matrix3);

	cout << endl << "Enter the size for second matrix: ";
	cin >> s >> t;
	cout << endl << "Second Matrix:" << endl;
	CreateMatrix(matrix4, s, t);
	PrintMatrix(matrix4);

	cout << endl << "Matrix 1 * Matrix 2:" << endl;
	MultiplyMatrix(matrix3, matrix4, result);
	cout << endl << "Matrix 2 * Matrix 1:" << endl;
	MultiplyMatrix(matrix4, matrix3, result);


	time_t finish = time(0);

	cout << endl << "Running time in seconds is: " << (finish - start) << endl;

	return 0;
}

