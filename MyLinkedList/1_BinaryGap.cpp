int nBinary[32] = {};

int HexToBinary(const int nNum)
{
	int n = nNum;
	int a[32] = {};
	int i = 0;

	while (n > 0)
	{
		a[i] = n % 2;
		n = n / 2;
		i++;
	}
	int nLen = i;
	for (int j=0; j<nLen; j++)
	{
		nBinary[j] = a[i-1];
		i--;
	}
	return nLen;
}

int solution(int N)
{
	// write your code in C99 (gcc 6.2.0)
	int nLen = HexToBinary(N);
	int nFlag = -1;
	int nMax = 0;
	for (int i=0; i<nLen; i++)
	{
		if (1 == nBinary[i])
		{
			if (-1 != nFlag)
			{
				int nTmp = i - nFlag - 1;
				if (nTmp > nMax)
				{
					nMax = nTmp;
				}
			}
			nFlag = i;
		}
	}

	return nMax;
}
