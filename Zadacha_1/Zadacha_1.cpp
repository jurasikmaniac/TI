// Zadacha_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <ctype.h> 
#include <clocale>
#include <Windows.h>

#pragma warning (once : 4996)
#define AlfabetN 256	

//B Visual studio 2012 нет поддержки log2
inline float log2(float n) {
  return log(n) / log(2.0);
}



//Предварительные настройки приложения
inline void SetApp(void)
{
	//setlocale( LC_ALL, "ru_RU.cp1251" );

	SetConsoleCP(1251);					// Русская локаль
	SetConsoleOutputCP(1251);
}

//Оценка энтропии, одиночные символы
float entropy_1 (char *fn)
{
	FILE *fi;
	float freq[AlfabetN] = {0};
	int ch=EOF;
	long total=0;
	puts("Файл:");	
	puts(fn);
	fi = fopen(fn, "r");
	if(fi == NULL)
    {
        puts("Такой файл не найден!");
		system("Pause");
        return -1;
    }
	
	_locale_t m_locale;
	
	 m_locale =  _get_current_locale();
	 wprintf(L"%ls sdsd\n",m_locale->locinfo->locale_name);
	while((ch = fgetc(fi)) != EOF)
    {
		printf("%c", ch);
        if(_isalpha_l(ch,m_locale))
        {
            ch = _tolower_l(ch,m_locale);
            //if(ch == toascii('ё')) ch = toascii('е');
            freq[ch]++;
            total++;            
        }
        else 
        {
			if (ch == ' ')
			{
				freq[ch]++;
				total++;            
			}else
			{
				ch = '.'; // всё остальное
				freq[ch]++;
				total++;            
			}
        }
 
    }
	
	for (int i = 0; i < AlfabetN; i++)
	{
		
		if (freq[i]!=0)
		{
			freq[i] = freq[i]/total;
			printf("P[%c] = %1.3f\n",i,freq[i]);
		}
	}
	printf("я = %c", _tolower_l( 'Я',m_locale));
	
	_free_locale(m_locale);
	system("PAUSE");
	return 0;
}

//Оценка энтропии, пары символов
float entropy_2 (char *fl)
{
	puts("Файл:");	
	puts(fl);
	return 0;
}

//Меню программы, type - задает нужные пункты меню.
inline wchar_t Menu(unsigned char type)
{
	wchar_t c;
	switch (type)
	{
		case 1:	system("CLS");
				puts("########################");
				puts("1. Ввести имя файла");
				puts("2. Оценка энтропии, одиночные символы");
				puts("3. Оценка энтропии, пары символов");
				puts("4. Выход из программы");
				puts("\n########################");
				puts("Выбрать пункт меню №: ");
				c=getchar();
				fflush(stdin);
				return c;
		default:puts("Err, нет такого меню");
				system("PAUSE");
				break;
	}
	
	return 0;
} 




				// Количество символов в алфавите
int _tmain(int argc, _TCHAR* argv[])
{
	
	float freq2[AlfabetN][AlfabetN] = {0};
	char FILENAME[200];


	SetApp ();
	while (1)
	{
		switch (Menu(1))
		{
			case '1': fflush(stdin); system("DIR /a:-d"); puts("Первая буква Большая!\n"); gets(FILENAME);
				break;
			case '2': entropy_1( FILENAME);break;
			case '3': entropy_1( FILENAME);break;
			case '4': return 0;
			default:break;
		}
	}
	
	
	
	/*Вывод кодов ASCII, для проверки правильности их определения
	for (int i = 0; i < AlfabetN; i++)
	{
		puts("P[%c-%3d] = %4d\n",i,i,P1[i]);
	}*/
	
	system("PAUSE");
	return 0;
}

