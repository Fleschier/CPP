//chapter 2
//E01*********************（水仙花数）
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	for (int i = 100;i <= 999;i++)
//	{
//		if ((pow(i / 100, 3) + pow(i / 10 % 10, 3) + pow(i % 10, 3)) == i)
//			printf("%d\n", i);
//	}
//	return 0;
//}

//E02******************（韩信点兵）
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	int count = 0;
//	while (scanf("%d%d%d", &a, &b, &c) !=EOF)
//	{
//		int sum = 0,flag=0;											//注意sum和flag的初始化，不然会一直重复第一次的结果
//		count++;
//		for (int i = 10;i <= 100;i++)
//		{
//			if ((i - a) % 3 == 0 && (i - b) % 5 == 0 && (i - c) % 7 == 0)
//			{
//				sum = i;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//		{
//			printf("case %d: No Answer.\n", count);
//		}
//		else
//		{
//			printf("case %d: %d\n", count, sum);
//		}
//	}
//	return 0;
//}

//E03************************(输出倒三角形)
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i <= (n-1);i++)
//	{
//		for (int t = 0;t <= i;t++)
//		{
//			printf(" ");
//		}
//		for (int j = 2*(n-i)-1;j >= 1;j--)
//		{
//			printf("#");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//E04********************（子序列的和）
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m, n;
//	float sum;
//	printf("Please input plus integer m,n (n<m<1e6):\n");
//	int count = 0;
//	while (scanf("%d%d", &n, &m)!=EOF)		//本题须将判断条件作为读入的数据的判断，否则会无限循环
//	{
//		sum = 0.0;							//注意sum的初始化一定要放在循环中
//		if (m == 0 || n == 0)  break;		//先判断是否是循环结束的标志
//		count++;
//		for (int i = n;i <= m;i++)
//		{
//			sum += 1.0 * 1 / pow(i, 2);
//		}
//		printf("case %d: %f\n",count, sum);
//	}
//
//	return 0;
//}

//E05*******************（分数化小数）
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	while (scanf("%d%d%d", &a, &b, &c) != EOF)
//	{
//		if (a == 0 || b == 0 || c == 0) break;
//		double div;
//		div = 1.0*a / b;
//		printf("%.*f\n", c,div);				//*号在printf()中的作用的体现
//	}
//	return 0;
//}

//E06**************(排列)
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}

//question 1
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 2;i <= n;i+=2)
//	{
//		printf("%d\n", i);
//	}
//	return 0;
//}

//question 2
//#include<stdio.h>
//int main()
//{
//	double i;
//	for (i = 0;i != 10;i += 0.1)
//	{
//		printf("%.1f\n", i);
//	}
//	return 0;
//}