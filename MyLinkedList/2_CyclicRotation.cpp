#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K)
{
	vector<int> B(A);
	int nLen = A.size();
	for (int i=0; i<nLen; i++)
	{
		A[(i+K)%nLen] = B[i];
	}
	return A;
}

//void main(void)
//{
//	vector<int> vec;
//	vec.push_back(1);
//	vec.push_back(2);
//	vec.push_back(3);
//	vec.push_back(4);
//	int k = 2;
//	solution(vec, k);
//}
