#include<windows.h>
#include<stdio.h>
#include"input.h"
#include"output.h"
#include"dataProcessor.h"
void hint(void)
{
	char idea;

	printf("�û�����ã��Ƿ�ʹ��Ĭ�ϲ���[Y(��)/N(��)].\n");
	idea=getchar();
	while(idea!='N'&&idea!='Y')
	{
	    printf("���û���������:\n");
        idea=getchar();
	}
	if(idea=='N')
		CreateTrain();
}
int main(void)
{
	HANDLE ThreadA;
	hint();
	ThreadA=CreateThread(NULL,0,ChangeInformation,NULL,0,NULL);//���뺯�����߳�
	run();

	return 0;
 }



