// Zadacha_1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>

#pragma warning (once : 4996)

float entropy_1 (int *mass);
float entropy_2 (int *mass);

//B Visual studio 2012 ��� ��������� log2
inline float log2(float n) {
  return log(n) / log(2.0);
}

//���� ���������, type - ������ ������ ������ ����.
inline unsigned char Menu(unsigned char type)
{
	return 0;
} 

//��������������� ��������� ����������
inline void SetApp(void)
{
	SetConsoleCP(1251);					// ������� ������
	SetConsoleOutputCP(1251);
}

//������ ��������, ��������� �������
float entropy_1 (int *mass)
{
	return 0;
}

//������ ��������, ���� ��������
float entropy_2 (int *mass)
{
	return 0;
}






#define AlfabetN 256					// ���������� �������� � ��������
int _tmain(int argc, _TCHAR* argv[])
{
	float freq[AlfabetN] = {0};
	float freq2[AlfabetN*AlfabetN] = {0};
	FILE *fi;
	float H=0;

	SetApp ( );
	Menu ( 1 );
	
	freq[0]=3.0;
	freq[1]=1.0;
	freq[2]=4.0;
	for (int i = 0; i < 3; i++)
	{
		H += (-1)* (freq[i]/8.0)*log2(freq[i]/8.0);
		printf("P = %f\n", freq[i]/8.0);
		printf("log = %f\n", log2(freq[i]/8.0));
	}
	printf("H = %6.3f", H);
	/*����� ����� ASCII, ��� �������� ������������ �� �����������
	for (int i = 0; i < AlfabetN; i++)
	{
		printf("P[%c-%3d] = %4d\n",i,i,P1[i]);
	}*/
	
	system("PAUSE");
	return 0;
}

