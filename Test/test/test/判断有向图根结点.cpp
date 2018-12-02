#include <iostream>

using namespace std;

enum ResultCode { Underflow, Overflow, Success, Duplicate, NotPresent, Failure };

template <class T>
class Graph
{
protected:
	int n, e;

public:
	virtual ResultCode Insert(int u, int v, T & w) = 0;
	virtual ResultCode Remove(int u, int v) = 0;
	virtual bool Exist(int u, int v) = 0;
	virtual int display() = 0;
	virtual void xianshi() = 0;

	
};

template<class T>
class MGraph :public Graph<T>

{
protected:
	T **a;
	T noEdge;
public:
	MGraph(int mSize, T& noedg);
	~MGraph();
	ResultCode Insert(int u, int v, T &  w);
	ResultCode Remove(int u, int v);
	bool Exist(int u, int v);
	int display();
	int zuomian();
	void xianshi();

};

template<class T>
MGraph<T>::MGraph(int mSize, T & noedge)
{

	n = mSize;   e = 0; noEdge = noedge;
	a = new T*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new T[n];
		for (int j = 0; j < n; j++)
			a[i][j] = noEdge;
		a[i][i] = 0;
	}
}

template<class T>
MGraph<T>::~MGraph()
{

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[]a;
}

template<class T>
bool MGraph<T>::Exist(int u, int v)
{
	//�����noEdge��Ϊ��ʼ����ֵ˵��û������ߣ�����u,v֮�䲻�ܵ���
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v || a[u][v] == noEdge)
		return false;
	return true;
}

template<class T>
ResultCode MGraph<T>::Insert(int u, int v, T & w)
{
	if (u<0 || v<0 || u>n - 1 || v>n - 1 || u == v)
		return Failure;
	if (a[u][v] != noEdge)
		return Duplicate;
	a[u][v] = w;
	e++;
	return Success;
}

template<class T>
ResultCode MGraph<T>::Remove(int u, int v)
{
	if (u<0 || v<0 || u>n - 1 || v> n - 1 || u == v)
		return Failure;
	if (a[u][v] == noEdge)
		return NotPresent;
	a[u][v] = noEdge;
	e--;
	return Success;
}

template<class T>
void MGraph<T>::xianshi()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

template<class T>
int MGraph<T>::display()
{
	//count���ڶ����������п���
	int count = 0;
	//һάָ�룬���ڼ�¼����ÿ��1�ĸ�������ͨ·�ĸ���
	int *b;
	b = new int[n];
	//��ʼ��Ϊ0
	for (int k = 0; k < n; k++)
	{
		b[k] = 0;

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//��a[i][j]==1����ʾi,j֮����ͨ·����b[i]++;
			if (a[i][j] == 1)
			{
				b[i]++;
				//���������Ϊ�˽���ӵ�����һ���ڵ��ͨ·
				for (int x = 0; x < n; x++)
				{
					//���j���������нڵ㣬������һ��i�������ڵ�ĸ���
					if (a[j][x] == 1)
						b[i]++;
				}
			}

		}
	}

	printf("\n");
	//����������ڵ�
	for (int r = 0; r < n; r++)
	{
		if (b[r] == n - 1)
		{
			printf("ͼ�ĸ��ڵ�Ϊ:%d\n", r);
		}
		if (b[r] != n - 1)
		{
			count++;
		}
		if (count == n)
		{
			printf("û�и��ڵ㣡\n");
		}

	}
	return 0;

}

int main()
{
	do
	{
		int m = 0, k = 1, d, p, c;
		int n;
		printf("����ڵ���n:\n");
		scanf("%d", &n);
		MGraph <int> g(n, m);
		printf("����һ����������:\n");
		scanf("%d", &c);
		printf("����%d����\n", c);
		for (int b = 0; b < c; b++)
		{
			scanf("%d", &p);

			scanf("%d", &d);

			g.Insert(p, d, k);
		}
		g.xianshi();
		g.display();
	} while (1);
	return 0;
}