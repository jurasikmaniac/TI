// Zadacha_1.cpp: определяет точку входа для консольного приложения.
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

//B Visual studio 2012 нет поддержки log2
inline float log2(float n) {
  return log(n) / log(2.0);
}

//Меню программы, type - задает нужные пункты меню.
inline unsigned char Menu(unsigned char type)
{
	return 0;
} 

//Предварительные настройки приложения
inline void SetApp(void)
{
	SetConsoleCP(1251);					// Русская локаль
	SetConsoleOutputCP(1251);
}

//Оценка энтропии, одиночные символы
float entropy_1 (int *mass)
{
	return 0;
}

//Оценка энтропии, пары символов
float entropy_2 (int *mass)
{
	return 0;
}






#define AlfabetN 256					// Количество символов в алфавите
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
	/*Вывод кодов ASCII, для проверки правильности их определения
	for (int i = 0; i < AlfabetN; i++)
	{
		printf("P[%c-%3d] = %4d\n",i,i,P1[i]);
	}*/
	
	system("PAUSE");
	return 0;
}

