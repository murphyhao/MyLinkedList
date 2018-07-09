#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

const int nSize = 3;
int matrix[nSize][nSize] = {};
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
	if (nSize-1 == x)
	{
		return;
	}
	matrix[x][y] = matrix[x+1][y];
	matrix[x+1][y] = 0;
	x++;
}

void Down(void)
{
	if (nSize-1 == y)
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
	for (int j=0; j<nSize; j++)
	{
		for (int i=0; i<nSize; i++)
		{
			matrix[i][j] = n;
			n++;
		}
	}
	matrix[nSize-1][nSize-1] = 0;
	x = nSize -1;
	y = nSize -1;

	// random
	srand((unsigned int)time(0));
	for (int i=0; i<100; i++)
	{
		int nVal = rand() % 4;
		switch (nVal)
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
	for (int j=0; j<nSize; j++)
	{
		for (int i=0; i<nSize; i++)
		{
			cout << matrix[i][j];
			if (nSize-1 == i)
			{
				cout << endl;
			}
			else
			{
				cout << '\t';
			}
		}
	}
}

bool IsSuccess(void)
{
	bool bRet = true;
	int n = 1;
	for (int j=0; j<nSize; j++)
	{
		for (int i=0; i<nSize; i++)
		{
			int nVal = matrix[i][j];
			if (i == nSize-1 && j == nSize-1)
			{
				if (0 != nVal)
				{
					bRet = false;
					break;
				}
			}
			else
			{
				if (n != nVal)
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
			// others
		}
		ShowMatrix();
		if (IsSuccess())
		{
			cout << "Success!" << endl;
			break;
		}
	}
}