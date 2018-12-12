//sizeof()内置函数和库函数strlen()的区别测试**********************
//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char name[20];//注意输入的最大字符长度为19，最后一个编译器默认加上 \0
//	int size;
//	int rsize;
//	scanf("%s", name);
//	size = sizeof (name);
//	rsize = strlen(name);
//	printf("%s %zd %zd\n", name,size,rsize);//此处的%zd为给sizeof和strlen的格式化符，也可换为%d
//	return 0;
//}

//scanf()和printf（）中*修饰符的用法
//#include<stdio.h>
//int main()
//{
//	float n;
//	printf("Please input three float numbers(the third number would be assigned):\n");
//	int width, precision;
//	scanf("%*f %*f %f",&n);
//	printf("please input two integers:");
//	scanf("%d %d", &width, &precision);
//	printf("the assigned number is %*.*f\n", width,precision,n);
//}

//chpter 1****************************************************
//E01***************
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d",&a,&b,&c);
//	float avg;
//	avg = 1.0*(a + b + c) / 3;
//	printf("the average is:%.3f", avg);
//  return 0;
//}

//E02**************
//#include<stdio.h>
//int main()
//{
//	float f;
//	scanf("%f", &f);
//	float c;
//	c = 5 * (f - 32) / 9;
//	printf("%.3f 度\n", c);
//	return 0;
//}

//E03****************
//#include<stdio.h>
//int main()
//{
//	int n,sum;
//	scanf("%d", &n);
//	sum = 1.0*n*(1 + n) / 2;
//	printf("%d\n", sum);
//	return 0;
//}

//E04********************
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	float a, b;
//	int n;
//	scanf("%d", &n);
//	a = sin(n);
//	b = cos(n);
//	printf("%f %f\n", a, b);
//}

//E05*******************
//#include<stdio.h>
//#define PRICE 95
//int main()
//{
//	int n;
//	float money;
//	scanf("%d", &n);
//	money = n*PRICE;
//	if (money >= 300)
//		money *= 0.85;
//	printf("%.2f\n", money);
//  return 0;
//}

//E06*************************
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	if ((a - b) < c && c< (a + b))
//		printf("this is a triangle\n");
//	else
//		printf("this isn't a triangle\n");
//	return 0;
//}

//E07******************************
//#include<stdio.h>
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		printf("%d is a leap year\n", year);
//	else
//		printf("%d isn't a leap year\n");
//	return 0;
//}

//question 1*******************************
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	a = 1;
//	b = 1;
//	c = 0;
//	if (a&&b || c)
//		printf("True\n");
//	return 0;
//}