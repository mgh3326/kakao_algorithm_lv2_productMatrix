#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >productMatrix(vector<vector<int> >A, vector<vector<int> >B)
{
	vector<vector<int> >answer;
	//cout << A.size() << endl;
	answer.resize(A.size());
	for (unsigned int i = 0; i < A.size(); i++)//이렇게 초기화 해주면 되는건가 이중벡터 너무 어렵스
	{
		answer[i].resize(B[0].size());
	}
	//answer[0][0] = 0;
	int sum = 0;
	for (unsigned int i = 0; i < A.size(); i++)//1 2 2 3
	{
		//for (unsigned int i = 0; i < A.size(); i++)//1 2 2 3
		for (unsigned int k = 0; k < B[0].size(); k++)//1 2 2 3
		{
			sum = 0;
			for (unsigned int j = 0; j < A[i].size(); j++)
			{
				sum += A[i][j] * B[j][k];//왜 이렇게 해야 되지
			}
			answer[i][k] = sum;
		}

	}
	return answer;
}

int main()
{
	vector<vector<int> >A{ { 1,2 },{ 2,3 } };//(1*2 + 2*3) + (1*3 + 2*4)
	vector<vector<int> >B{ { 2,3 },{ 3,4 } };
	vector<vector<int> > testAnswer = productMatrix(A, B);

	for (int i = 0; i < testAnswer.size(); i++)
	{
		for (int j = 0; j < testAnswer[i].size(); j++)
			cout << testAnswer[i][j] << " ";
		cout << "\n";
	}
}

//행렬의 곱셈은, 곱하려는 두 행렬의 어떤 행과 열을 기준으로,
//좌측의 행렬은 해당되는 행, 우측의 행렬은 해당되는 열을 순서대로 곱한 값을 더한 값이 들어갑니다.
//행렬을 곱하기 위해선 좌측 행렬의 열의 개수와 우측 행렬의 행의 개수가 같아야 합니다.
//곱할 수 있는 두 행렬 A,B가 주어질 때, 행렬을 곱한 값을 출력하는 productMatrix 함수를 완성해 보세요.