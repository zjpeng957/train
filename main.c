#include<windows.h>
#include<stdio.h>
#include"input.h"
#include"output.h"
#include"dataProcessor.h"
void hint(void)
{
	char idea;

	printf("用户，你好，是否使用默认参数[Y(是)/N(否)].\n");
	idea=getchar();
	while(idea!='N'&&idea!='Y')
	{
	    printf("请用户重新输入:\n");
        idea=getchar();
	}
	if(idea=='N')
		CreateTrain();
}
int main(void)
{
	HANDLE ThreadA;
	hint();
	ThreadA=CreateThread(NULL,0,ChangeInformation,NULL,0,NULL);//输入函数的线程
	run();

	return 0;
 }



