#include <stdio.h>
#include "dk_tool.h"
void input_size(int *row, int *column, const char *prompt);
void input_size(int *row, int *column, const char *prompt)
{
    if (NULL != promt)
    {
        printf("%s", prompt);
    }
    scanf("%d%d", row, column); //приймаємо розмір який увів користувач
}
void printf_size1 ()
{
    printf("Введіть розмір першої квадтратної матриці: дві цифри через пробіл.\n");
    scanf("%d%d", &m, &n);//приймаємо розмір який увів користувач
}
void matrix1_elements ()
{
    if( n !=m)//перевіряємо чи матриця квадратна
         printf("Ви ввели не квадратну матрицю\n");
    else
	{
 	 printf("Введіть елементи першої матриці:\n");//просимо ввести елементи першої матриці
	 for (  c = 0 ; c < m ; c++ )
    	 	for ( d = 0 ; d < n ; d++ )
      			scanf("%d", &first[c][d]); //зчитуємо ці елементи
	}
}
void printf_size2 ()
{
   	printf("Введіть розмір другої квадратної матриці: дві цифри через пробіл.\n");//запитуємо розмір другої матриці
	scanf("%d%d", &p, &q);
}
void matrix2_elements ()
{
    if(p!=q) //перевіряємо чи користувач увів квадратну матрицю
  	printf("Ви ввели не квадратну матрицю\n");
     else
	{
	if ( n != p )//перевіряємо чи матриці можна перемножити
    		printf("Матриці не можуть бути перемноженими за правилами\n");
  	else
  		{
    		printf("Введіть елементи другої матриці:\n");//запитуємо елементи другої матриці
		for ( c = 0 ; c < p ; c++ )
      			for ( d = 0 ; d < q ; d++ )
        			scanf("%d", &second[c][d]);//зчитуємо другу матрицю
    		}
	}
}
void multiple ()
{
    multiply[c][d]=0;
    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
      	{
        	for ( k = 0 ; k < p ; k++ )
        		{
			sum  +=  first[c][k]*second[k][d];//перемножуємо дві матриці
        		}
        	multiply[c][d]=sum;
    		sum = 0;

	}
    }
}
void result ()
{
    printf("Результат:\n");//виводимо результат
    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
      	printf("%d\t", multiply[c][d]);
      printf("\n");
    }
}
