//chapter 2
//E01*********************��ˮ�ɻ�����
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

//E02******************�����ŵ����
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	int count = 0;
//	while (scanf("%d%d%d", &a, &b, &c) !=EOF)
//	{
//		int sum = 0,flag=0;											//ע��sum��flag�ĳ�ʼ������Ȼ��һֱ�ظ���һ�εĽ��
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

//E03************************(�����������)
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

//E04********************�������еĺͣ�
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int m, n;
//	float sum;
//	printf("Please input plus integer m,n (n<m<1e6):\n");
//	int count = 0;
//	while (scanf("%d%d", &n, &m)!=EOF)		//�����뽫�ж�������Ϊ��������ݵ��жϣ����������ѭ��
//	{
//		sum = 0.0;							//ע��sum�ĳ�ʼ��һ��Ҫ����ѭ����
//		if (m == 0 || n == 0)  break;		//���ж��Ƿ���ѭ�������ı�־
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

//E05*******************��������С����
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	while (scanf("%d%d%d", &a, &b, &c) != EOF)
//	{
//		if (a == 0 || b == 0 || c == 0) break;
//		double div;
//		div = 1.0*a / b;
//		printf("%.*f\n", c,div);				//*����printf()�е����õ�����
//	}
//	return 0;
//}

//E06**************(����)
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