#include<windows.h>
#include"input.h"
#include"output.h"
#include"dataProcessor.h"
//HANDLE hMutex1;
HANDLE ThreadA,ThreadB;
int main(void)
{
	//HANDLE ThreadA,ThreadB;
	//hMutex1=CreateMutex(NULL,FALSE,"run1");
	//hMutex2=CreateMutex(NULL,FALSE,"run2");
	//hMutex3=CreateMutex(NULL,FALSE,"run3");
	CreateTrain();
	ThreadB=CreateThread(NULL,0,run,NULL,0,NULL);

	//ThreadC=CreateThread(NULL,0,judge,NULL,0,NULL);
	//ThreadD=CreateThread(NULL,0,Output_formation,NULL,0,NULL);//输出函数的线程
	ThreadA=CreateThread(NULL,0,ChangeInformation,NULL,CREATE_SUSPENDED,NULL);//输入函数的线程
	ResumeThread(ThreadA);

	CloseHandle(ThreadB);
	CloseHandle(ThreadA);
	//CloseHandle(ThreadC);
	//CloseHandle(ThreadD);
	Sleep(500000);
	return 0;
 }



