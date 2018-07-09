#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;
/*
const int c_nSize = 4;
int matrix[c_nSize][c_nSize] = {};
int x = 0;
int y = 0;

void Up(void)
{
	if (0 == y)
	{
		return;
	}
	matrix[x][y] = matrix[x][y-1];
	matrix[x][y-1] = 0;
	y--;
}

void Left(void)
{
	if (0 == x)
	{
		return;
	}
	matrix[x][y] = matrix[x-1][y];
	matrix[x-1][y] = 0;
	x--;
}

void Right(void)
{
	if (c_nSize-1 == x)
	{
		return;
	}
	matrix[x][y] = matrix[x+1][y];
	matrix[x+1][y] = 0;
	x++;
}

void Down(void)
{
	if (c_nSize-1 == y)
	{
		return;
	}
	matrix[x][y] = matrix[x][y+1];
	matrix[x][y+1] = 0;
	y++;
}

void InitMatrix(void)
{
	int n = 1;
	for (int j=0; j<c_nSize; j++)
	{
		for (int i=0; i<c_nSize; i++)
		{
			matrix[i][j] = n;
			n++;
		}
	}
	matrix[c_nSize-1][c_nSize-1] = 0;
	x = c_nSize - 1;
	y = c_nSize - 1;

	// rand matrix
	srand((unsigned int)time(0));
	for (int i=0; i<100; i++)
	{
		int nRand = rand() % 4;
		switch (nRand)
		{
		case 0:
			Up();
			break;
		case 1:
			Left();
			break;
		case 2:
			Right();
			break;
		case 3:
			Down();
			break;
		default:
			Up();
			break;
		}
	}
}

void ShowMatrix(void)
{
	system("CLS");
	for (int j=0; j<c_nSize; j++)
	{
		for (int i=0; i<c_nSize; i++)
		{
			cout << matrix[i][j];
			if (i == c_nSize-1)
			{
				cout << endl;
			}
			else
			{
				cout << "\t";
			}
		}
	}
}

bool IsSuccess(void)
{
	bool bRet = true;
	int n = 1;
	for (int j=0; j<c_nSize; j++)
	{
		for (int i=0; i<c_nSize; i++)
		{
			int nVal = matrix[i][j];
			if (c_nSize-1 == i && c_nSize-1 == j)
			{
				if (nVal != 0)
				{
					bRet = false;
				}
			}
			else
			{
				if (nVal != n)
				{
					bRet = false;
					break;
				}
			}
			n++;
		}
	}
	return bRet;
}

void main(void)
{
	InitMatrix();
	ShowMatrix();
	while (true)
	{
		char key = _getch();
		if ('Q' == key || 'q' == key)
		{
			cout << "End!" << endl;
			break;
		}
		else if ('R' == key || 'r' == key)
		{
			InitMatrix();
			ShowMatrix();
		}
		else if (72 == key)
		{
			Up();
		}
		else if (75 == key)
		{
			Left();
		}
		else if (77 == key)
		{
			Right();
		}
		else if (80 == key)
		{
			Down();
		}
		else
		{
			// other
		}
		ShowMatrix();
		if (IsSuccess())
		{
			cout << "Success!" << endl;
			//break;
		}
	}
}
*/