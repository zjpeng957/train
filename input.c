#include<stdio.h>
#include "dataProcessor.h"
#include "input.h"
#include<string.h>
#include<windows.h>
void CreateTrain (void)//设置火车的初始信息
{
    FILE *fp;
    //A火车
    if((fp=fopen("A火车信息.txt","w"))==NULL)
    {
        printf("当前无法设置A火车信息。");
        exit(1);
    }
    printf("请输入A火车的信息\n");
    printf("火车速度（m/s）:");scanf("%d",&trainA.speed);
    printf("方向（顺时针为1，逆时针为-1）：");scanf("%d",&trainA.direction);
    printf("轨道长度（m）:");scanf("%d",&trainA.trackLen);
    printf("初始位置(0至轨道长度)：");scanf("%d",&trainA.position);
    printf("启动时间（从程序开始运行起/s）：");scanf("%d",&trainA.time);
    printf("公共轨道停留时间：");scanf("%d",&trainA.restTime);
    trainA.state=S1;
    if(trainA.direction==1)//顺时针
        fprintf(fp,"火车速度：%d\n方向：%s\n轨道长度：%d\n初始位置：%d\n启动时间：%d\n"
                "公共轨道停留时间：%d\n火车状态：%s",trainA.speed,"顺时针",trainA.trackLen,trainA.position,trainA.time,trainA.restTime,"运行—公共轨道");
    else//逆时针
        fprintf(fp,"火车速度：%d\n方向：%s\n轨道长度：%d\n初始位置：%d\n启动时间：%d\n"
                "公共轨道停留时间：%d\n火车状态：%s",trainA.speed,"逆时针",trainA.trackLen,trainA.position,trainA.time,trainA.restTime,"运行—公共轨道");
    fclose(fp);

	//B火车
    if((fp=fopen("B火车信息.txt","w"))==NULL)
    {
        printf("当前无法设置B火车信息。");
        exit(1);
    }
    printf("请输入B火车的信息\n");
    printf("火车速度（m/s）:");scanf("%d",&trainB.speed);
    printf("方向（顺时针为1，逆时针为-1）：");scanf("%d",&trainB.direction);
    printf("轨道长度（m）:");scanf("%d",&trainB.trackLen);
    printf("初始位置(0至轨道长度)：");scanf("%d",&trainB.position);
    printf("启动时间（从程序开始运行起/s）：");scanf("%d",&trainB.time);
    printf("公共轨道停留时间：");scanf("%d",&trainB.restTime);
    trainB.state=S1;
    if(trainB.direction==1)//顺时针
        fprintf(fp,"火车速度：%d\n方向：%s\n轨道长度：%d\n初始位置：%d\n启动时间：%d\n"
                "公共轨道停留时间：%d\n火车状态：%s",trainB.speed,"顺时针",trainB.trackLen,trainB.position,trainB.time,trainB.restTime,"运行—公共轨道");
    else//逆时针
        fprintf(fp,"火车速度：%d\n方向：%s\n轨道长度：%d\n初始位置：%d\n启动时间：%d\n"
                "公共轨道停留时间：%d\n火车状态：%s",trainB.speed,"逆时针",trainB.trackLen,trainB.position,trainB.time,trainB.restTime,"运行—公共轨道");
    fclose(fp);


    //C火车
    if((fp=fopen("C火车信息.txt","w"))==NULL)
    {
        printf("当前无法设置C火车信息。");
        exit(1);
    }
    printf("请输入C火车的信息\n");
    printf("火车速度（m/s）:");scanf("%d",&trainC.speed);
    printf("方向（顺时针为1，逆时针为-1）：");scanf("%d",&trainC.direction);
    printf("轨道长度（m）:");scanf("%d",&trainC.trackLen);
    printf("初始位置(0至轨道长度)：");scanf("%d",&trainC.position);
    printf("启动时间（从程序开始运行起/s）：");scanf("%d",&trainC.time);
    printf("公共轨道停留时间：");scanf("%d",&trainC.restTime);
    trainC.state=S1;
    if(trainC.direction==1)//顺时针
        fprintf(fp,"火车速度：%d\n方向：%s\n轨道长度：%d\n初始位置：%d\n启动时间：%d\n"
                "公共轨道停留时间：%d\n火车状态：%s",trainC.speed,"顺时针",trainC.trackLen,trainC.position,trainC.time,trainC.restTime,"运行—公共轨道");
    else//逆时针
        fprintf(fp,"火车速度：%d\n方向：%s\n轨道长度：%d\n初始位置：%d\n启动时间：%d\n"
                "公共轨道停留时间：%d\n火车状态：%s",trainC.speed,"逆时针",trainC.trackLen,trainC.position,trainC.time,trainC.restTime,"运行—公共轨道");
    fclose(fp);

}


DWORD WINAPI ChangeInformation(LPVOID lpParameter)
{
    char string1[100];
    while(1)
    {
        //WaitForSingleObject(hMutex1,INFINITE);
        //WaitForSingleObject(hMutex2,INFINITE);

        printf("输入”PA“让小火车暂停，输入”SA“让火车再次启动\n");
        printf("输入”PB“让小火车暂停，输入”SB“让火车再次启动\n");
        printf("输入”PC“让小火车暂停，输入”SC“让火车再次启动\n");
        scanf("%s",string1);
        if(strcmp(string1,"PA")==0)
            trainA.state=3;
        else if(strcmp(string1,"PB")==0)
            trainB.state=3;
        else if(strcmp(string1,"PC")==0)
            trainC.state=3;
        else if(strcmp(string1,"SA")==0)
            trainA.state=1;
        else if(strcmp(string1,"SB")==0)
            trainB.state=1;
        else if(strcmp(string1,"SC")==0)
            trainC.state=1;
        else printf("输入的是非法信息");
        //ReleaseMutex(hMutex1);
        //ReleaseMutex(hMutex2);
    }
}

char JudgePass(void)
{
    printf("请输入优先通过的小火车：");
    char trainNum;
    scanf("%c",&trainNum);
    getchar();
    return trainNum;
}












