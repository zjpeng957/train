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

        fprintf(output,"当前运行时间是%ds\n",runTime);
        printf("当前运行时间是%ds,\n",runTime);

        if(trainA.direction==1)
        {
            fprintf(output,"小火车A运行方向为：顺时针. ");
            printf("小火车A运行方向为：顺时针. ");
        }
        else
        {
            fprintf(output,"小火车A运行方向为：逆时针. ");
            printf("小火车A运行方向为：逆时针. ");
        }
        fprintf(output," 所处位置为：%d. 速度为：%d. ",trainA.position,trainA.speed);
        printf(" 所处位置为：%d. 速度为：%d. ",trainA.position,trainA.speed);

        printf("所处状态为：");
        switch(trainA.state)
        {
            case S1:fprintf(output,"运行-非公共轨道.\n");
                    printf("运行-非公共轨道.\n");
                    break;
            case S2:fprintf(output,"运行-公共轨道.\n");
                    printf("运行-公共轨道.\n");
                    break;
            case S3:fprintf(output,"暂停-非公共轨道.\n");
                    printf("暂停-非公共轨道.\n");
                    break;
            case S4:fprintf(output,"停靠-公共轨道.\n");
                    printf("停靠-公共轨道.\n");
                    break;
            case S5:fprintf(output,"暂停-等待公共轨道.\n");
                    printf("暂停-等待公共轨道.\n");
                    break;
        }

        if(trainB.direction==1)
        {
            fprintf(output,"小火车B运行方向为：顺时针. ");
            printf("小火车B运行方向为：顺时针. ");
        }
        else
        {
            fprintf(output,"小火车B运行方向为：逆时针. ");
            printf("小火车B运行方向为：逆时针. ");
        }
        fprintf(output," 所处位置为：%d. 速度为：%d. ",trainB.position,trainB.speed);
        printf(" 所处位置为：%d. 速度为：%d. ",trainB.position,trainB.speed);

        printf("所处状态为：");
        switch(trainB.state)
        {
            case S1:fprintf(output,"运行-非公共轨道.\n");
                    printf("运行-非公共轨道.\n");
                    break;
            case S2:fprintf(output,"运行-公共轨道.\n");
                    printf("运行-公共轨道.\n");
                    break;
            case S3:fprintf(output,"暂停-非公共轨道.\n");
                    printf("暂停-非公共轨道.\n");
                    break;
            case S4:fprintf(output,"停靠-公共轨道.\n");
                    printf("停靠-公共轨道.\n");
                    break;
            case S5:fprintf(output,"暂停-等待公共轨道.\n");
                    printf("暂停-等待公共轨道.\n");
                    break;
        }

        if(trainC.direction==1)
        {
            fprintf(output,"小火车C运行方向为：顺时针. ");
            printf("小火车C运行方向为：顺时针. ");
        }
        else
        {
            fprintf(output,"小火车C运行方向为：逆时针. ");
            printf("小火车C运行方向为：逆时针. ");
        }
        fprintf(output," 所处位置为：%d. 速度为：%d. ",trainC.position,trainC.speed);
        printf(" 所处位置为：%d. 速度为：%d. ",trainC.position,trainC.speed);

        printf("所处状态为：");
        switch(trainC.state)
        {
            case S1:fprintf(output,"运行-非公共轨道.\n");
                    printf("运行-非公共轨道.\n");
                    break;
            case S2:fprintf(output,"运行-公共轨道.\n");
                    printf("运行-公共轨道.\n");
                    break;
            case S3:fprintf(output,"暂停-非公共轨道.\n");
                    printf("暂停-非公共轨道.\n");
                    break;
            case S4:fprintf(output,"停靠-公共轨道.\n");
                    printf("停靠-公共轨道.\n");
                    break;
            case S5:fprintf(output,"暂停-等待公共轨道.\n");
                    printf("暂停-等待公共轨道.\n");
                    break;
        }

        //ReleaseMutex(hMutex1);
        //ReleaseMutex(hMutex3);

        fclose(output);
        //timeout(3);

	}
    //return 0;
}



