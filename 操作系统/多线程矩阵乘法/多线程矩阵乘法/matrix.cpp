#include<stdio.h>
#include<time.h>
#include<windows.h>

/* Direction:
 This is a multi-Threads programe
 The Matrix size is:  	A: M*K , B: N*K
 Each time changed the M,N,K, you should change the read-in file name!
 Created by Fleschier
 10th, Oct
*/

#define M 1024
#define K 1024
#define N 1024

//declare the  Matrices as globle value to make it available to all threads
//the matrix are all double type
//initialize thr matrix
double A[M][K] = { 0 };
double B[K][N] = { 0 };
double C[M][N] = { 0 };

DWORD WINAPI readDataA(LPVOID param);
DWORD WINAPI readDataB(LPVOID param);
DWORD WINAPI calcMatrix(LPVOID param);
DWORD WINAPI writeFile(LPVOID param);
void WaitAndCloseHandle(HANDLE threadHandle);

DWORD WINAPI readDataA(LPVOID param) {
	//注意这里的LPVOID实际上也是一种指针，是指向void 类型的指针，因此可以将其赋值给任意一种类型
	FILE* f = (FILE*)param;	//win32的接口参数只能是LPVOID类型，在函数中可以将其转换为任意一种类型来使用。
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < K; ++j) {
			//因为要转换的是double类型，%f只是float类型(16位)，因此用%lf来表示32位浮点数，也就是double类型
			fscanf(f, "%lf", &A[i][j]);
		}
	return 0;
}

DWORD WINAPI readDataB(LPVOID param) {
	FILE* f = (FILE*)param;
	//**********************
	//B矩阵优化：将B矩阵的行列对调，也就是旋转90度，为下面的矩阵乘法CPU读取数据进行优化
	//************************
	for (int i = 0; i < N; ++i)			//column
		for (int j = 0; j < K; ++j) {		//row
			fscanf(f, "%lf", &B[j][i]);		//按列存储*****非常重要！直接使运行时间从25s降低到了10s
		}
	return 0;
}

//use struct to transfer multi-input-parameter to threads
//in C++, struct is almost the same as class
struct multiData{
	int begin_m;
	int end_m;
	int begin_n;
	int end_n;
	//define the constructor
	multiData() {}		//default constructor
	multiData(int bg_m,int ed_m,int bg_n, int ed_n) {
		begin_m = bg_m;
		end_m = ed_m;
		begin_n = bg_n;
		end_n = ed_n;
	}
};

DWORD WINAPI calcMatrix(LPVOID param) {		//注意LPVOID是指针类型，因此传参数的时候注意取地址符
	multiData data = *(multiData*)param;	//如果是指针则直接类型转换，是变量则还需要解引用
	//char tmpc[30];		//存储转换的值,因为存储的是双精度浮点数，这里数据的整数部分为10位，小数部分要显示11位则至少开10+1+11=22位的数组才够

	//A ;M*K   B: K*N
	for (int i = data.begin_m; i < data.end_m; ++i) {		
		for (int j = data.begin_n; j < data.end_n; ++j) {		
			for (int a = 0; a < K; ++a) {		//只有k不可以进行拆解运算
				C[i][j] += A[i][a] * B[j][a];
			}
			////使用sprintf来完成转换，打印11位小数(按要求的格式保留11位小数)
			//sprintf(tmpc, "%.11f ", C[i][j]);			//这里的数值是整数部分10位，小数点一位， 小数部分11位，末尾空格1位，结束符'\0'一位所以一共要开24位的数组才够
			//fputs(tmpc, data.fout);		//fputs的第一个参数为char*
		}
		//fputc(10, data.fout);		//写入换行符
	}

	return 0;
}

DWORD WINAPI writeFile(LPVOID param) {
	FILE* f = (FILE*)param;
	char tmpc[30];		//存储转换的值,因为存储的是双精度浮点数，这里数据的整数部分为10位，小数部分要显示11位则至少开10+1+11=22位的数组才够

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			//使用sprintf来完成转换，打印11位小数(按要求的格式保留11位小数)
			sprintf_s(tmpc, "%.11f ", C[i][j]);			//这里的数值是整数部分10位，小数点一位， 小数部分11位，末尾空格1位，结束符'\0'一位所以一共要开24位的数组才够
			fputs(tmpc, f);		//fputs的第一个参数为char*
		}
		fputc(10, f);		//写入换行符
	}
	return 0;
}

//integrate the thread-wait function and the thread-close function
void WaitAndCloseHandle(HANDLE threadHandle) {
	if (threadHandle != NULL) {
		//wait for the thread to finish
		WaitForSingleObject(threadHandle, INFINITE);

		//close the thread handle
		CloseHandle(threadHandle);
	}
	//printf("one handle is closed! \n");
}

int main() {
	//test the running time
	clock_t start_time, end_time, mid_time;
	start_time = clock();

	//write a file in C mode
	FILE *fout = fopen("1627405072.txt", "w");
	//read data into matrix A and B
	//when you changed the values of M, N and K, don't forget those read-in file names' change
	FILE *finA = fopen("M1024A.txt", "r");
	FILE *finB = fopen("M1024B.txt", "r");

	//declare thread id
	DWORD ThreadIDA;
	DWORD ThreadIDB;
	DWORD ThreadID_writeFile;
	DWORD ThreadID = 1234;

	//create readfile threads
	HANDLE readFileAHandle = CreateThread(NULL, 0, readDataA, finA, 0, &ThreadIDA);
	HANDLE readFileBHandle = CreateThread(NULL, 0, readDataB, finB, 0, &ThreadIDB);


	//create calculation threads and suspend
	HANDLE handleArr[500];
	//construct the struct for parameter of the thread
	multiData inputArr[500];

	int allThreadsNum = 0;		//store the current number of calc threads
	int step = 256;			//the step of the loop
	for (int i = 0; i <= 1024 - step; i += step) {
		for (int j = 0; j <= 1024 - step; j += step) {
			//multiData inputData(i, i + step);
			//输入数据必须存入数组而不能作为循环体临时变量。因为循环一旦结束则临时变量就会被销毁，等线程运行时就会找不到这个变量从而导致程序出错
			inputArr[allThreadsNum] = multiData(i, i + step, j, j + step);
			handleArr[allThreadsNum] = CreateThread(NULL, 0, calcMatrix, &inputArr[allThreadsNum], CREATE_SUSPENDED, &(++ThreadID));
			allThreadsNum++;
		}
	}

	HANDLE wrtFile = CreateThread(NULL, 0, writeFile, fout, CREATE_SUSPENDED, &ThreadID_writeFile);

	//wait the threads ends and close the threads
	//if forget to execute those functions the thread will only be created without running
	WaitAndCloseHandle(readFileAHandle);
	WaitAndCloseHandle(readFileBHandle);

	mid_time = clock();
	printf("The read time is %f s\n", (double)(mid_time - start_time) / CLOCKS_PER_SEC);

	//Resume the calc Threads
	for (int i = 0; i < allThreadsNum; i++) {
		ResumeThread(handleArr[i]);
		WaitAndCloseHandle(handleArr[i]);
	}

	ResumeThread(wrtFile);
	//printf("Now the write begin\n");
	WaitAndCloseHandle(wrtFile);

	//close  files
	if(finA != NULL)
		fclose(finA);
	if(finB != NULL)
		fclose(finB);
	if(fout != NULL)
		fclose(fout);

	end_time = clock();	
	printf("The total running time is %f s\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

}
