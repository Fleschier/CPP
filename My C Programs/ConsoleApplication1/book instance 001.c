/*******************
 *计算圆柱体表面积
 */
//#include<stdio.h>
//#include<math.h>
//
//int main()
//{
//	const double pi = acos(-1.0);
//	double r, h, s1, s2, s;
//	scanf_s("%lf%lf", &r, &h);
//	s1 = pi*pow(r, 2);//等价于s1=pi*r*r;
//	s2 = 2 * pi*r*h;
//	s = s1*2.0 + s2;
//	printf("Area=%.3f\n", s);
//	return 0;
//}

/**********************
 *三位数逆向输出（1）
 */
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf_s("%d", &n);
//	printf("%d%d%d\n", n % 10, n / 10 % 10, n / 100);
//	return 0;
//
//}

/***********************
 *三位数逆向输出（2）
 */
//#include<stdio.h>
//int main()
//{
//	int n, m;
//	scanf_s("%d", &n);
//	m = (n % 10)*100 + (n / 10 % 10)*10 + n / 100;
//	printf("%03d\n", m);
//	return 0;
//}

/***************************
 *交换变量(1)
 */
//#include<stdio.h>
//int main()
//{
//	int a, b, t;
//	scanf_s("%d%d", &a, &b);
//	t = a;
//	a = b;
//	b = t;
//	printf("%d %d\n", a, b);
//	return 0;
//}

/************************
 *交换变量(2)
 */
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	scanf_s("%d%d", &a, &b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("%d %d\n",a,b);
//	return 0;
//}
/**************************
 *交换变量（3）
 */
//#include<stdio.h>
//int main()
//{
//	int a, b;
//	scanf_s("%d%d", &a, &b);
//	printf("%d %d\n", b, a);
//	return 0;
//}
/****************************
 *鸡兔同笼
 */
//#include<stdio.h>
//int main()
//{
//	int a, b, n, m;
//	scanf_s("%d%d", &n, &m);
//	a = (4 * n - m) / 2;
//	b = n - a;
//	if (m % 2 == 1 || a < 0 || b < 0)
//		printf("NO ANSWER\n");
//	else
//		printf("%d %d\n", a, b);
//
//	return 0;
//}

/*********************
 *三整数排序
 */
//#include<stdio.h>
//int main()
//{
//	int tmp,a,b,c;
//	scanf_s("%d%d%d", &a, &b, &c);
//	if (a > b)
//	{							//若无花括号则会有错误(C是不强制缩进对齐的，这一点和Python截然不同。
								//去掉大括号以后，if语句中条件为真时，仅仅只是执行了第1条语句：tmp = a；
								//后面紧跟着的两条语句a = b;b = tmp;是不受条件控制的。)

//		tmp = a;a = b;b = tmp;
//	}
//	if (a > c)
//	{
//		tmp = a;a = c;c = tmp;
//	}
//	if (b > c)
//	{
//		tmp = b;b = c;c = tmp;
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}


//习题部分******************************
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf_s("%d%d%d", &a, &b, &c);
//	float avg;
//	avg = 1.0*(a + b + c) / 3;
//	printf("AVERAGE is:%.3f\n", avg);
//	return 0;
//}

#include<stdio.h>
