//��int����Ԫ�ص����
//#include<stdio.h>
//int sum(int *n, int length);
//int main()
//{
//	int a[] = { 2323,3242,123,54,6435,7,6578};
//	int tot = sum(a,sizeof(a)/sizeof(a[0]));		//����sizeof��������ֽ��������׸�Ԫ�ص��ֽ��������������Ԫ�ظ�������������Ԫ��ȫΪ������û�пյ�λ�õ����飩
//	printf("the summary is %d\n", tot);
//	return 0;
//}
//
//int sum(int *n, int length)
//{
//	int summary=0;						//ע������ĳ�ʼ��
//	for (int i = 0;i <= length-1;i++)		//ע��˴���length�����������±��1��Ҫ��һ���У���Ȼ�������ֵ��ͻ�䣬���������һ��Խ�����
//	{
//		summary += n[i];
//		printf("%d\n", summary);
//	}
//	return summary;
//}

//��ͷ�����˫ָ�뷨��
//#include<stdio.h>
//#define SIZE 10		//������ų���
//int sump(int * start, int * end);	//��������ָ�������ָ��ͷ�ͽ�β
//int main()
//{
//	int marbles[SIZE] = { 20,10,4,23,54,76,5,8,9,45 };
//	long answer;
//	answer = sump(marbles, marbles + SIZE);		//��ֵ������������Ϊ��ͷ�ͽ�β�ĵ�ַ
//	printf("The total number of marbles is %ld\n",answer);
//
//	return 0;
//}
//
//int sump(int * start, int * end)
//{
//	int total = 0;
//	while (start < end)			//ע��˴���С�ںŶ�û�е��ںţ���Ϊѭ����endʱ�Ѿ������һ��Ԫ�ص��±��ˣ��������һ��Ԫ���±��endС1.
//	{
//		total += *start;		//������Ԫ�ص�ֵ������
//		start++;				//��ָ��ָ����һ��Ԫ��(�����ʼ�)
//		printf("%d\n", total);
//	}
//	return total;
//}

//����a[i]��*(a+i)�Ƿ�ȼ�
//#include<stdio.h>
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	int t1 = a[2];
//	int t2 = *(a + 2);
//	printf("whether %d equals %d ?\n", t1, t2);
//	return 0;
//}

//��ά�����ָ��(����)
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

//�䳤�������ͨ�ú���
//#include<stdio.h>
//int sum(int r,int c,int var[r][c]);//r����rows�����У�c����cols�����С�(��Щ������������䳤����)
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

//ʹ��ָ��ṹ���ָ��
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
//		{{"Ewen","Villard"},		//�ṹ���һ��Ԫ�ؿ�ʼ��ֵ��������first��last�����ַ����ĸ�ֵ���������ṹ��ĵ�һ��Ԫ�أ��ṹ�壩
//		"grilled salmon",			//Ȼ����favfood�ĸ�ֵ
//		"personally coach",			//������job�ĸ�ֵ
//		68112.00},					//�����income�ĸ�ֵ����һ���ṹ�帳ֵ����
//		{{"Rodeny","Swillbelly"},	//�ڶ����ṹ�帳ֵ��ʼ����ʽ���һ���ṹ�����ƣ�ע���Ԫ��֮���ö��Ÿ���
//		"tripe",
//		"tabloid editor",
//		432400.00}
//	};								//�ṹ�帳ֵ��ɣ�ע��ֺ�
//
//	printf("address #1: %p	#2: %p\n", &fellow[0], &fellow[1]);
//	struct guy * him;				//����һ��ָ��ṹ��ָ�룬��ָ������Ϊstruct guy ����
//	him = &fellow[0];				//���߱�����ָ��ָ��δ��������鲻ͬ���ṹ������ָ��ṹ�ĵ�ַ�����Ҫ����ȡ��ַ����
//	printf("address #1: %p	#2: %p\n", him, him + 1);	//֮ǰ�ĸ�ֵʹhimָ��fellow[0],��him+1ָ��fellow[1]
//	printf("him->income is $%.2f;  (*him).income is $%.2f\n", him->income, (*him).income);	//֮�����еĸ�ֵ������->������ź͵���ŵ��໥֮����ڿ����滻�Ĺ�ϵ��
//	him++;							//ָ������fellow����һ���ṹ����
//	printf("him->favfood is %s;   him->handle.last is %s\n", him->favfood, him->handle.last);
//	return 0;
//}
//*�ܽ᣺��ָ����ʳ�Ա�����µ�him��һ��ָ�룬fellow[0]��һ���ṹ������
//
//��һ�֣�ʹ�� -> ����� �����¹�ϵ
//���him==&barney,��ô him->income ���� barney.income
//���him==&fellow,��ô him->income ���� fellow[0].income
//
//�ڶ��֣�
//���him==&fellow[0], ��ô*him==fellow[0],��fellow[0].income==(*him).income��
//�Ҵ˴���Բ���Ų���ʡ����Ϊ���������*��������ȼ���
//
//���� him==&barney ,����������ǳ�����
//barney.income==(*him).income==him->income
//*/

//�������ݽṹ����Ϣ*************************
//(1),���ݽṹ��ַ
//#include<stdio.h>
//#define FUNDLEN 50
//struct funds {
//	char bank[FUNDLEN];
//	double bankfund;
//	char save[FUNDLEN];
//	double savefund;
//};
//
//double sum(const struct funds* money); //����ԭ�Σ�������һ���̶���struct funds��ָ��
//int main()
//{
//	struct funds stan = {				//����һ��struct funds���͵ı���������Ϊstan
//		"Garlic-Melon bank",
//		4032.27,
//		"Lucky's Savings and Loan",
//		8543.94
//	};
//
//	printf("Stan has a total of $ %.2f.\n", sum(&stan));	//��stan�ĵ�ַ��������
//	return 0;
//}
//
//double sum(const struct funds * money)
//{
//	//return (money->bankfund + money->savefund);
//	return ((*money).bankfund + (*money).savefund);		//�����������ע�͵�������Ч����ͬ��
														//��Ϊ���ﴫ��money�βε�ʵ�ξ���&stan,��stan�ĵ�ַ
//}
//��2�����ݽṹ
//#include<stdio.h>
//#define FUNDLEN 50
//struct funds {
//	char bank[FUNDLEN];
//	double bankfund;
//	char save[FUNDLEN];
//	double savefund;
//};
//
//double sum(struct funds moolah);			//��ʽ������һ���ṹ�壬�β�����Ϊmoolah
//
//int main()
//{
//	struct funds stan = {
//		"Garlic-Melon bank",
//		4032.27,
//		"Lucky's Savings and Loan",
//		8543.94
//	};
//	printf("Stan has a total of $ %.2f.\n", sum(stan));	//���ϸ�������Ƚϣ������ʵ��Ϊһ���ṹ�������
//														//��ע��ṹ������Ʋ������ַ���������鲻ͬ��
//	
//	return 0;
//}
//
//double sum(struct funds moolah)
//{
//	return (moolah.bankfund + moolah.savefund);
//}

//����ʾ���������Ӱ����Ϣ��
#include<stdio.h>
#include<stdlib.h>							//�ṩmalloc()����ԭ��
#include<string.h>							//�ṩstrcpy()����ԭ��
#define TSIZE 45							//���������С���ַ�����

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;						//ָ����������һ���ṹ
};

char * s_gets(char * st, int n);

int main()
{
	struct film * head = NULL;
	struct film * prev, *current;			//��������struct film���͵�ָ��
	char input[TSIZE];	

	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')		//�ռ���������Ϣ
	{
		current = (struct film*) malloc(sizeof(struct film));		//malloc()��������Ϊ�ṹ�����㹻�Ŀռ�
		if (head == NULL)											//��һ���ṹ
			head = current;
		else														//�����ṹ
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

	if (head == NULL)								//��ʾ��Ӱ�б�
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
		free(current);						//��������ͷ��ѷ�����ڴ�
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
		find = strchr(st, '\n');		//���һ��з�
		if (find)						//�����ַ����NULL
			* find = '\0';				//�ڴ˴�����һ�����ַ�
		else
			while (getchar() != '\n')
				continue;				//����ʣ��������
	}
	return ret_val;
}