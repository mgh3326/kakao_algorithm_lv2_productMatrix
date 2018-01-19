#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >productMatrix(vector<vector<int> >A, vector<vector<int> >B)
{
	vector<vector<int> >answer;
	//cout << A.size() << endl;
	answer.resize(A.size());
	for (unsigned int i = 0; i < A.size(); i++)//�̷��� �ʱ�ȭ ���ָ� �Ǵ°ǰ� ���ߺ��� �ʹ� ��ƽ�
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
				sum += A[i][j] * B[j][k];//�� �̷��� �ؾ� ����
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

//����� ������, ���Ϸ��� �� ����� � ��� ���� ��������,
//������ ����� �ش�Ǵ� ��, ������ ����� �ش�Ǵ� ���� ������� ���� ���� ���� ���� ���ϴ�.
//����� ���ϱ� ���ؼ� ���� ����� ���� ������ ���� ����� ���� ������ ���ƾ� �մϴ�.
//���� �� �ִ� �� ��� A,B�� �־��� ��, ����� ���� ���� ����ϴ� productMatrix �Լ��� �ϼ��� ������.