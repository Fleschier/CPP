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
	//ע�������LPVOIDʵ����Ҳ��һ��ָ�룬��ָ��void ���͵�ָ�룬��˿��Խ��丳ֵ������һ������
	FILE* f = (FILE*)param;	//win32�Ľӿڲ���ֻ����LPVOID���ͣ��ں����п��Խ���ת��Ϊ����һ��������ʹ�á�
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < K; ++j) {
			//��ΪҪת������double���ͣ�%fֻ��float����(16λ)�������%lf����ʾ32λ��������Ҳ����double����
			fscanf(f, "%lf", &A[i][j]);
		}
	return 0;
}

DWORD WINAPI readDataB(LPVOID param) {
	FILE* f = (FILE*)param;
	//**********************
	//B�����Ż�����B��������жԵ���Ҳ������ת90�ȣ�Ϊ����ľ���˷�CPU��ȡ���ݽ����Ż�
	//************************
	for (int i = 0; i < N; ++i)			//column
		for (int j = 0; j < K; ++j) {		//row
			fscanf(f, "%lf", &B[j][i]);		//���д洢*****�ǳ���Ҫ��ֱ��ʹ����ʱ���25s���͵���10s
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

DWORD WINAPI calcMatrix(LPVOID param) {		//ע��LPVOID��ָ�����ͣ���˴�������ʱ��ע��ȡ��ַ��
	multiData data = *(multiData*)param;	//�����ָ����ֱ������ת�����Ǳ�������Ҫ������
	//char tmpc[30];		//�洢ת����ֵ,��Ϊ�洢����˫���ȸ��������������ݵ���������Ϊ10λ��С������Ҫ��ʾ11λ�����ٿ�10+1+11=22λ������Ź�

	//A ;M*K   B: K*N
	for (int i = data.begin_m; i < data.end_m; ++i) {		
		for (int j = data.begin_n; j < data.end_n; ++j) {		
			for (int a = 0; a < K; ++a) {		//ֻ��k�����Խ��в������
				C[i][j] += A[i][a] * B[j][a];
			}
			////ʹ��sprintf�����ת������ӡ11λС��(��Ҫ��ĸ�ʽ����11λС��)
			//sprintf(tmpc, "%.11f ", C[i][j]);			//�������ֵ����������10λ��С����һλ�� С������11λ��ĩβ�ո�1λ��������'\0'һλ����һ��Ҫ��24λ������Ź�
			//fputs(tmpc, data.fout);		//fputs�ĵ�һ������Ϊchar*
		}
		//fputc(10, data.fout);		//д�뻻�з�
	}

	return 0;
}

DWORD WINAPI writeFile(LPVOID param) {
	FILE* f = (FILE*)param;
	char tmpc[30];		//�洢ת����ֵ,��Ϊ�洢����˫���ȸ��������������ݵ���������Ϊ10λ��С������Ҫ��ʾ11λ�����ٿ�10+1+11=22λ������Ź�

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			//ʹ��sprintf�����ת������ӡ11λС��(��Ҫ��ĸ�ʽ����11λС��)
			sprintf_s(tmpc, "%.11f ", C[i][j]);			//�������ֵ����������10λ��С����һλ�� С������11λ��ĩβ�ո�1λ��������'\0'һλ����һ��Ҫ��24λ������Ź�
			fputs(tmpc, f);		//fputs�ĵ�һ������Ϊchar*
		}
		fputc(10, f);		//д�뻻�з�
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
			//�������ݱ�����������������Ϊѭ������ʱ��������Ϊѭ��һ����������ʱ�����ͻᱻ���٣����߳�����ʱ�ͻ��Ҳ�����������Ӷ����³������
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
