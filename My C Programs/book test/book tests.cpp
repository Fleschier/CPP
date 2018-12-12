//对int数组元素的求和
//#include<stdio.h>
//int sum(int *n, int length);
//int main()
//{
//	int a[] = { 2323,3242,123,54,6435,7,6578};
//	int tot = sum(a,sizeof(a)/sizeof(a[0]));		//两个sizeof相除（总字节数除以首个元素的字节数）即是数组的元素个数（仅适用于元素全为数字且没有空的位置的数组）
//	printf("the summary is %d\n", tot);
//	return 0;
//}
//
//int sum(int *n, int length)
//{
//	int summary=0;						//注意变量的初始化
//	for (int i = 0;i <= length-1;i++)		//注意此处的length比数组的最大下标大1，要减一才行，不然会出现数值的突变，最后结果会是一个越界的数
//	{
//		summary += n[i];
//		printf("%d\n", summary);
//	}
//	return summary;
//}

//求和法二（双指针法）
//#include<stdio.h>
//#define SIZE 10		//定义符号常量
//int sump(int * start, int * end);	//定义两个指针参数，指向开头和结尾
//int main()
//{
//	int marbles[SIZE] = { 20,10,4,23,54,76,5,8,9,45 };
//	long answer;
//	answer = sump(marbles, marbles + SIZE);		//赋值的两个参数即为开头和结尾的地址
//	printf("The total number of marbles is %ld\n",answer);
//
//	return 0;
//}
//
//int sump(int * start, int * end)
//{
//	int total = 0;
//	while (start < end)			//注意此处是小于号而没有等于号，因为循环到end时已经是最后一个元素的下标了，访问最后一个元素下标比end小1.
//	{
//		total += *start;		//把数组元素的值加起来
//		start++;				//让指针指向下一个元素(详解见笔记)
//		printf("%d\n", total);
//	}
//	return total;
//}

//测试a[i]与*(a+i)是否等价
//#include<stdio.h>
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int t1 = a[2];
//	int t2 = *(a + 2);
//	printf("whether %d equals %d ?\n", t1, t2);
//	return 0;
//}

//多维数组和指针(测试)
//#include<stdio.h>
//int main()
//{
//	int a[4][2] = { {2,4},{6,8},{1,3},{5,7} };
//	printf("a=%p, a+1=%p\n", a, a + 1);
//	printf("a[0]=%p,a[0]+1=%p\n", a[0], a[0] + 1);
//	printf("*a=%p, *a+1=%p\n", *a, *a + 1);
//	printf("a[0][0]=%d\n", a[0][0]);
//	printf("*a[0]=%d\n", *a[0]);
//	printf("**a=%d\n", **a);
//	printf("*(*(a+2)+1)=%d\n", *(*(a + 2) + 1));
//	printf("a[2][1]=%d\n", a[2][1]);
//	return 0;
//}

//变长数组求和通用函数
//#include<stdio.h>
//int sum(int r,int c,int var[r][c]);//r代表rows，即行；c代表cols，即列。(有些编译器不允许变长数组)
//int main()
//{
//	int a[4][2] = { { 2,4 },{ 6,8 },{ 1,3 },{ 5,7 } };
//	int n=sum(4, 2, a);
//	printf("the sum of VLA is %d\n", n);
//	return 0;
//}
//
//int sum(int rows, int cols, int var[rows][cols])
//{
//	int r, c, sum;
//	for (r = 0;r < rows;r++)
//		for (c = 0;c < cols;c++)
//			sum += var[r][c];
//	return sum;
//}

//使用指向结构体的指针
//#include<stdio.h>
//#define LEN 20
//struct names {
//	char first[LEN];
//	char last[LEN];
//};
//
//struct guy {
//	struct names handle;
//	char favfood[LEN];
//	char job[LEN];
//	float income;
//};
//int main()
//{
//	struct guy fellow[2] = {
//		{{"Ewen","Villard"},		//结构体第一个元素开始赋值，首先是first和last两个字符串的赋值，这是外层结构体的第一个元素（结构体）
//		"grilled salmon",			//然后是favfood的赋值
//		"personally coach",			//接着是job的赋值
//		68112.00},					//最后是income的赋值，第一个结构体赋值结束
//		{{"Rodeny","Swillbelly"},	//第二个结构体赋值开始，方式与第一个结构体类似，注意各元素之间用逗号隔开
//		"tripe",
//		"tabloid editor",
//		432400.00}
//	};								//结构体赋值完成，注意分号
//
//	printf("address #1: %p	#2: %p\n", &fellow[0], &fellow[1]);
//	struct guy * him;				//声明一个指向结构的指针，其指向类型为struct guy 类型
//	him = &fellow[0];				//告诉编译器指针指向何处（和数组不同，结构名并不指向结构的地址，因此要加上取地址符）
//	printf("address #1: %p	#2: %p\n", him, him + 1);	//之前的赋值使him指向fellow[0],则him+1指向fellow[1]
//	printf("him->income is $%.2f;  (*him).income is $%.2f\n", him->income, (*him).income);	//之下两行的赋值表明了->这个符号和点符号的相互之间存在可以替换的关系。
//	him++;							//指向数组fellow中下一个结构变量
//	printf("him->favfood is %s;   him->handle.last is %s\n", him->favfood, him->handle.last);
//	return 0;
//}
//*总结：用指针访问成员（以下的him是一个指针，fellow[0]是一个结构变量）
//
//第一种：使用 -> 运算符 有如下关系
//如果him==&barney,那么 him->income 即是 barney.income
//如果him==&fellow,那么 him->income 即是 fellow[0].income
//
//第二种：
//如果him==&fellow[0], 那么*him==fellow[0],即fellow[0].income==(*him).income，
//且此处的圆括号不可省，因为点运算符比*运算符优先级高
//
//假设 him==&barney ,则下面的总是成立：
//barney.income==(*him).income==him->income
//*/

//向函数传递结构的信息*************************
//(1),传递结构地址
//#include<stdio.h>
//#define FUNDLEN 50
//struct funds {
//	char bank[FUNDLEN];
//	double bankfund;
//	char save[FUNDLEN];
//	double savefund;
//};
//
//double sum(const struct funds* money); //函数原形，参数是一个固定的struct funds的指针
//int main()
//{
//	struct funds stan = {				//定义一个struct funds类型的变量，名称为stan
//		"Garlic-Melon bank",
//		4032.27,
//		"Lucky's Savings and Loan",
//		8543.94
//	};
//
//	printf("Stan has a total of $ %.2f.\n", sum(&stan));	//将stan的地址传给函数
//	return 0;
//}
//
//double sum(const struct funds * money)
//{
//	//return (money->bankfund + money->savefund);
//	return ((*money).bankfund + (*money).savefund);		//此语句与上面注释掉的语句的效果相同，
														//因为这里传给money形参的实参就是&stan,即stan的地址
//}
//（2）传递结构
//#include<stdio.h>
//#define FUNDLEN 50
//struct funds {
//	char bank[FUNDLEN];
//	double bankfund;
//	char save[FUNDLEN];
//	double savefund;
//};
//
//double sum(struct funds moolah);			//形式参数是一个结构体，形参名称为moolah
//
//int main()
//{
//	struct funds stan = {
//		"Garlic-Melon bank",
//		4032.27,
//		"Lucky's Savings and Loan",
//		8543.94
//	};
//	printf("Stan has a total of $ %.2f.\n", sum(stan));	//与上个程序相比较，这里的实参为一个结构体的名称
//														//（注意结构体的名称不是其地址，这与数组不同）
//	
//	return 0;
//}
//
//double sum(struct funds moolah)
//{
//	return (moolah.bankfund + moolah.savefund);
//}

//链表示例（储存电影的信息）
#include<stdio.h>
#include<stdlib.h>							//提供malloc()函数原型
#include<string.h>							//提供strcpy()函数原型
#define TSIZE 45							//设置数组大小的字符常量

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;						//指向链表中下一个结构
};

char * s_gets(char * st, int n);

int main()
{
	struct film * head = NULL;
	struct film * prev, *current;			//定义两个struct film类型的指针
	char input[TSIZE];	

	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')		//收集并储存信息
	{
		current = (struct film*) malloc(sizeof(struct film));		//malloc()函数用来为结构分配足够的空间
		if (head == NULL)											//第一个结构
			head = current;
		else														//后续结构
			prev->next = current;
		current->next = NULL;
		strcpy(current->title,input);
		puts("Enter your rating <0-10>(Empty line to stop):");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter the next movie title(empty line to stop):");
		prev = current;
	}

	if (head == NULL)								//显示电影列表
		printf("No data entered.\n");
	else
		printf("Here is the movie list:\n");
	current = head;
	while (current != NULL)
	{
		printf("Movie : %s Rating : %d\n", current->title, current->rating);
		current = current->next;
	}												
	current = head;
	while (current != NULL)
	{
		current = head;
		head = current->next;
		free(current);						//完成任务，释放已分配的内存
	}
	printf("Bye!\n");

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');		//查找换行符
		if (find)						//如果地址不是NULL
			* find = '\0';				//在此处放置一个空字符
		else
			while (getchar() != '\n')
				continue;				//处理剩余输入行
	}
	return ret_val;
}