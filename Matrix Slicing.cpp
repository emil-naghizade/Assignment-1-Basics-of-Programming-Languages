#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

void CreateMatrix(vector<vector<int>>& matrix, int row, int column)
{
	matrix = vector < vector<int>>(row, vector<int>(column)); // initialize the matrix
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = (rand() % 10);
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

void SliceMatrix(vector<vector<int>>& org, int srow, int erow, int scol, int ecol, vector<vector<int>>& res)
{
	int r = org.size();
	int c = org[0].size();

	if (srow > r || srow < 0 || scol > c || scol < 0)
	{
		cout << endl << "Starting point is out of range" << endl;
	}
	if (erow > r || erow < 0 || ecol > c || ecol < 0)
	{
		cout << endl << "Ending point is out of range" << endl;
	}
	if (erow < srow) // if ending row is before than start 
	{
		int t;
		t = erow;
		erow = srow;
		srow = t;
	}
	if (ecol < scol) // if ending column is before than start
	{
		int t;
		t = ecol;
		ecol = scol;
		scol = t;
	}
	else
	{
		for (int i = srow; i <= erow; i++)
		{
			vector<int> temp;
			res.push_back(temp);
			for (int j = scol; j <= ecol; j++)
			{
				res[res.size()-1].push_back(org[i][j]);
			}
		}

		PrintMatrix(res);
	}
}


int main() 
{
	time_t start = time(0);
	srand(time(NULL));

	vector<vector<int>> original, result;
	int m, n, srow, scol, erow, ecol;

	cout << "Enter the size of original matrix: ";
	cin >> m >> n;
	CreateMatrix(original, m, n);
	cout << endl << "Original matrix is:" << endl;
	PrintMatrix(original);

	cout << endl << "Enter the start point: ";
	cin >> srow >> scol;
	cout << endl << "Enter the end point: ";
	cin >> erow >> ecol;
	cout << endl << "------------------------------------------" << endl;
	cout << endl << "Result of Slicing:" << endl;
	SliceMatrix(original,srow, erow, scol, ecol, result);
	
	time_t finish = time(0);
	cout << endl << "Elapsed time: " << (finish - start) << " seconds" << endl;

	return 0;
}

