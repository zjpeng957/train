#include"dataProcessor.h"
#include"input.h"
#include<stdio.h>
#include<time.h>
#include<windows.h>
#include"output.h"
//extern HANDLE hMutex3;
void Output_iformation(void)
{
    int runTime;
	//while(1)
	{
        //WaitForSingleObject(hMutex1,INFINITE);
        //WaitForSingleObject(hMutex3,INFINITE);
        FILE *output;
        runTime=clock()/CLOCKS_PER_SEC;

        output=fopen("output.txt","a+");

        fprintf(output,"��ǰ����ʱ����%ds\n",runTime);
        printf("��ǰ����ʱ����%ds,\n",runTime);

        if(trainA.direction==1)
        {
            fprintf(output,"С��A���з���Ϊ��˳ʱ��. ");
            printf("С��A���з���Ϊ��˳ʱ��. ");
        }
        else
        {
            fprintf(output,"С��A���з���Ϊ����ʱ��. ");
            printf("С��A���з���Ϊ����ʱ��. ");
        }
        fprintf(output," ����λ��Ϊ��%d. �ٶ�Ϊ��%d. ",trainA.position,trainA.speed);
        printf(" ����λ��Ϊ��%d. �ٶ�Ϊ��%d. ",trainA.position,trainA.speed);

        printf("����״̬Ϊ��");
        switch(trainA.state)
        {
            case S1:fprintf(output,"����-�ǹ������.\n");
                    printf("����-�ǹ������.\n");
                    break;
            case S2:fprintf(output,"����-�������.\n");
                    printf("����-�������.\n");
                    break;
            case S3:fprintf(output,"��ͣ-�ǹ������.\n");
                    printf("��ͣ-�ǹ������.\n");
                    break;
            case S4:fprintf(output,"ͣ��-�������.\n");
                    printf("ͣ��-�������.\n");
                    break;
            case S5:fprintf(output,"��ͣ-�ȴ��������.\n");
                    printf("��ͣ-�ȴ��������.\n");
                    break;
        }

        if(trainB.direction==1)
        {
            fprintf(output,"С��B���з���Ϊ��˳ʱ��. ");
            printf("С��B���з���Ϊ��˳ʱ��. ");
        }
        else
        {
            fprintf(output,"С��B���з���Ϊ����ʱ��. ");
            printf("С��B���з���Ϊ����ʱ��. ");
        }
        fprintf(output," ����λ��Ϊ��%d. �ٶ�Ϊ��%d. ",trainB.position,trainB.speed);
        printf(" ����λ��Ϊ��%d. �ٶ�Ϊ��%d. ",trainB.position,trainB.speed);

        printf("����״̬Ϊ��");
        switch(trainB.state)
        {
            case S1:fprintf(output,"����-�ǹ������.\n");
                    printf("����-�ǹ������.\n");
                    break;
            case S2:fprintf(output,"����-�������.\n");
                    printf("����-�������.\n");
                    break;
            case S3:fprintf(output,"��ͣ-�ǹ������.\n");
                    printf("��ͣ-�ǹ������.\n");
                    break;
            case S4:fprintf(output,"ͣ��-�������.\n");
                    printf("ͣ��-�������.\n");
                    break;
            case S5:fprintf(output,"��ͣ-�ȴ��������.\n");
                    printf("��ͣ-�ȴ��������.\n");
                    break;
        }

        if(trainC.direction==1)
        {
            fprintf(output,"С��C���з���Ϊ��˳ʱ��. ");
            printf("С��C���з���Ϊ��˳ʱ��. ");
        }
        else
        {
            fprintf(output,"С��C���з���Ϊ����ʱ��. ");
            printf("С��C���з���Ϊ����ʱ��. ");
        }
        fprintf(output," ����λ��Ϊ��%d. �ٶ�Ϊ��%d. ",trainC.position,trainC.speed);
        printf(" ����λ��Ϊ��%d. �ٶ�Ϊ��%d. ",trainC.position,trainC.speed);

        printf("����״̬Ϊ��");
        switch(trainC.state)
        {
            case S1:fprintf(output,"����-�ǹ������.\n");
                    printf("����-�ǹ������.\n");
                    break;
            case S2:fprintf(output,"����-�������.\n");
                    printf("����-�������.\n");
                    break;
            case S3:fprintf(output,"��ͣ-�ǹ������.\n");
                    printf("��ͣ-�ǹ������.\n");
                    break;
            case S4:fprintf(output,"ͣ��-�������.\n");
                    printf("ͣ��-�������.\n");
                    break;
            case S5:fprintf(output,"��ͣ-�ȴ��������.\n");
                    printf("��ͣ-�ȴ��������.\n");
                    break;
        }

        //ReleaseMutex(hMutex1);
        //ReleaseMutex(hMutex3);

        fclose(output);
        //timeout(3);

	}
    //return 0;
}



