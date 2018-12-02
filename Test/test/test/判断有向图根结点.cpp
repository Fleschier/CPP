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
	//这里的noEdge若为初始化的值说明没有这个边，就是u,v之间不能到达
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
	//count用于对输出结果进行控制
	int count = 0;
	//一维指针，用于记录矩阵每行1的个数，即通路的个数
	int *b;
	b = new int[n];
	//初始化为0
	for (int k = 0; k < n; k++)
	{
		b[k] = 0;

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//若a[i][j]==1即表示i,j之间有通路，将b[i]++;
			if (a[i][j] == 1)
			{
				b[i]++;
				//这个遍历是为了将间接到达另一个节点的通路
				for (int x = 0; x < n; x++)
				{
					//如果j到其他还有节点，则将增加一条i到其他节点的个数
					if (a[j][x] == 1)
						b[i]++;
				}
			}

		}
	}

	printf("\n");
	//遍历输出根节点
	for (int r = 0; r < n; r++)
	{
		if (b[r] == n - 1)
		{
			printf("图的根节点为:%d\n", r);
		}
		if (b[r] != n - 1)
		{
			count++;
		}
		if (count == n)
		{
			printf("没有根节点！\n");
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
		printf("输入节点数n:\n");
		scanf("%d", &n);
		MGraph <int> g(n, m);
		printf("输入一个整数条边:\n");
		scanf("%d", &c);
		printf("输入%d条边\n", c);
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