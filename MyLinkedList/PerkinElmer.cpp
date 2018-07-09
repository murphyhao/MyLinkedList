#include <iostream>
#include <vector>

using namespace std;

// get and
int CalcAndValue(void)
{
	int a[] = {2, 1, 5, 6, 8, 10};
	int nRet = ~0;
	int nLen = sizeof(a)/sizeof(int);
	for (int i=0; i<nLen; i++)
	{
		nRet = nRet & a[i];
	}
	return nRet;
}

// get first unique num
typedef struct tagNodePair{
	int nValue;
	int nNumber;
	tagNodePair(int val = 0, int num = 0)
	{
		nValue = val;
		nNumber = num;
	}
}NodePair;

int GetVecNumCount(const vector<NodePair>& vec, const int nVal, int& cnt)
{
	int nNum = -1;
	vector<NodePair>::const_iterator iter;
	cnt = 0;

	for (iter=vec.begin(); iter!=vec.end(); iter++,cnt++)
	{
		if (iter->nValue == nVal)
		{
			nNum = iter->nNumber;
			break;
		}
	}
	return nNum;
}
int GetFirstUniqueNum(int a[], int nLen)
{
	int nRet = -1;
	vector<NodePair> vec;
	vector<NodePair>::iterator iter;

	for (int i=0; i<nLen; i++)
	{
		int nVal = a[i];
		int nCnt = 0;
		int nNum = GetVecNumCount(vec, nVal, nCnt);
		if (-1 == nNum)
		{
			NodePair node(nVal, 1);
			vec.push_back(node);
		}
		else
		{
			vec[nCnt].nNumber++;
		}
	}

	for (iter=vec.begin(); iter!=vec.end(); iter++)
	{
		if (1 == iter->nNumber)
		{
			nRet = iter->nValue;
			break;
		}
	}

	return nRet;
}

// get cycle points
typedef struct myCycle
{
	int x;
	int y;
	myCycle(int nx = 0, int ny = 0)
	{
		x = nx;
		y = ny;
	}
}MyCycle;

double CalcDistance(const int x, const int y)
{
	return sqrt((double)(x*x + y*y));
}

vector<MyCycle> GetCycleInfo(int radii)
{
	vector<MyCycle> vec;
	int r = abs(radii);
	int n1 = -r;
	int n2 = r;

	for (int i=n1; i<=n2; i++)
	{
		for (int j=n1; j<=n2; j++)
		{
			if (CalcDistance(i, j) <= r)
			{
				MyCycle ins(i, j);
				vec.push_back(ins);
			}
		}
	}

	// print
	vector<MyCycle>::const_iterator iter;
	for (iter=vec.begin(); iter!=vec.end(); iter++)
	{
		cout << "(" << iter->x << "," << iter->y << ")" << endl;
	}
	return vec;
}
/*
void main(void)
{
	//cout << CalcAndValue() << endl;

	//int a[] = {2, 1, 2, 8, 8, 10};
	//int b[] = {4, 4, 6, 6};
	//cout << GetFirstUniqueNum(a, sizeof(a)/sizeof(int)) << endl;
	//cout << GetFirstUniqueNum(b, sizeof(b)/sizeof(int)) << endl;

	GetCycleInfo(2);
}
*/