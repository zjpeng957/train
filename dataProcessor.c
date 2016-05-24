#include "dataProcessor.h"
#include "input.h"
#include "output.h"
#include<stdio.h>
#include<time.h>

//extern HANDLE hMutex2,hMutex3;
Train trainA={SPEED,POSITION,TIME,CLWISE,TRACKLEN,TIME,S1,0},
      trainB={SPEED,POSITION,TIME,ANTICLWISE,TRACKLEN,TIME,S1,0},
      trainC={SPEED,POSITION,TIME,CLWISE,TRACKLEN,TIME,S1,0};


//�ֱ����������������յ�
int a1_in=7,a1_out=10,a2_in=11,a2_out=14,b_in=19,b_out=16,c_in=2,c_out=5;

//�ƶ��𳵵���һλ�ã���run������ʼʱ����
void move(Train *train)
{
    int distance;

    distance=train->position+train->direction*train->speed;

    if(distance>train->trackLen)
        train->position=distance-train->trackLen;
    else if(distance<=0)
        train->position=distance+train->trackLen;
    else
        train->position=distance;
}

//��ʱ,״̬ת�����������
void timeout(double time)
{
    clock_t start, finish;//��ʼ��ʱ�ͽ�����ʱ��ʱ��
    double duration;

    start = clock();//��ȡ��ǰʱ��
    duration=0.0;

    while(duration<time)
    {
        finish = clock();//��ȡ��ǰʱ��
        duration = (double)(finish - start) / CLOCKS_PER_SEC; //��ʱ���ת��Ϊ��
    }
}

//ģ��𳵵�����,ʵ�ֻ𳵵�״̬Ǩ�ƣ��û��������ʼ��Ϣ�����
DWORD WINAPI run(LPVOID lpParameter)
{
    int ai=0,bi=0,ci=0,i=0;
    while(1)
    {
        //WaitForSingleObject(hMutex1,INFINITE);
        if(trainA.time!=0)
            trainA.time--;
        else
        {
            switch(trainA.state)
            {
                case S1:move(&trainA);
                        if((trainA.direction*(a1_in-trainA.position)+24)%24<=trainA.speed)
                                trainA.detected=1,trainA.state=S2;
                        else if((trainA.direction*(a2_in-trainA.position)+24)%24<=trainA.speed)
                                trainA.detected=2,trainA.state=S2;
                        //if(trainA.position-(a1_in-trainA.direction*trainA.speed)<=0) trainA.detected=1,trainA.state=S2;
                        //else if(trainA.position-(a2_in-trainA.direction*trainA.speed)<=0) trainA.detected=2,trainA.state=S2;
                        break;
                case S2:move(&trainA);
                        if(trainA.direction==CLWISE)
                            {
                                if(trainA.detected==1)
                                    {
                                        if(trainA.position>(a1_in+a1_out)/2&&ai==0) trainA.position=(a1_in+a1_out)/2,trainA.state=S4;
                                        else if(trainA.position>=a1_out&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1;
                                    }
                                else if(trainA.detected==2)
                                    {
                                        if(trainA.position>(a2_in+a2_out)/2&&ai==0) trainA.position=(a2_in+a2_out)/2,trainA.state=S4;
                                        else if(trainA.position>=a2_out&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1;
                                    }
                            }
                        if(trainA.direction==ANTICLWISE)
                            {
                                if(trainA.detected==1)
                                    {
                                        if(trainA.position<(a1_in+a1_out)/2&&ai==0) trainA.position=(a1_in+a1_out)/2,trainA.state=S4;
                                        else if(trainA.position<=a1_out&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1;
                                    }
                                if(trainA.detected==2)
                                    {
                                        if(trainA.position<(a1_in+a1_out)/2&&ai==0) trainA.position=(a1_in+a1_out)/2,trainA.state=S4;
                                        else if(trainA.position<=a2_out&&ai!=0) trainA.detected=0,ai=0,trainA.state=S1;
                                    }
                            }

                        break;
                case S3:break;
                case S4:ai++;
                        if(ai>=trainA.restTime) trainA.state=S2;
                        break;
                case S5:if(trainA.detected==1)
                            if(trainB.state!=S2&&trainB.state!=S4) trainA.state=S2;
                        if(trainA.detected==2)
                            if(trainC.state!=S2&&trainC.state!=S4) trainA.state=S2;
                        break;
            }
        }
        if(trainB.time!=0)
            trainB.time--;
        else
        {
            switch(trainB.state)
            {
                case S1:move(&trainB);
                        if((trainB.direction*(b_in-trainB.position)+24)%24<=trainB.speed)
                                trainB.detected=1,trainB.state=S2;
                        break;
                case S2:move(&trainB);
                        if(trainB.direction==CLWISE)
                                {
                                    if(trainB.position>(b_in+b_out)/2&&bi==0) trainB.position=(b_in+b_out)/2,trainB.state=S4;
                                    else if(trainB.position>=b_out&&bi!=0) trainB.detected=0,bi=0,trainB.state=S1;
                                }
                        else
                                {
                                    if(trainB.position<(b_in+b_out)/2&&bi==0) trainB.position=(b_in+b_out)/2,trainB.state=S4;
                                    else if(trainB.position<=b_out&&bi!=0) trainB.detected=0,bi=0,trainB.state=S1;
                                }
                        break;
                case S3:break;
                case S4:bi++;
                        if(bi>=trainB.restTime) trainB.state=S2;
                        break;
                case S5:if(trainA.state!=S2&&trainA.state!=S4) trainB.state=S2;
                        break;
            }
        }
        if(trainC.time!=0)
            trainC.time--;
        else
        {
            switch(trainC.state)
            {
                case S1:move(&trainC);
                        if((trainC.direction*(c_in-trainC.position)+24)%24<=trainC.speed)
                                trainC.detected=1,trainC.state=S2;
                        break;
                case S2:move(&trainC);
                        if(trainC.direction==CLWISE)
                                {
                                    if(trainC.position>(c_in+c_out)/2&&ci==0) trainC.position=(c_in+c_out)/2,trainC.state=S4;
                                    else if(trainC.position>=c_out&&ci!=0) trainC.detected=0,ci=0,trainC.state=S1;
                                }
                        else
                                {
                                    if(trainC.position<(c_in+c_out)/2&&ci==0) trainC.position=(c_in+c_out)/2,trainC.state=S4;
                                    else if(trainC.position<=c_out&&ci!=0) trainC.detected=0,ci=0,trainC.state=S1;
                                }
                        break;
                case S3:break;
                case S4:ci++;
                        if(ci>=trainC.restTime) trainC.state=S2;
                        break;
                case S5:if(trainA.state!=S2&&trainA.state!=S4) trainC.state=S2;
                        break;
            }
        }
        timeout(1);
        /*if(++i%3==0)*/ Output_information();
        judge();
        //ReleaseMutex(hMutex1);
    }
    return 0;
}

//�ж������𳵽��빫����������г�Ҫ���빫�����ʱ����
void judge(void)
{
    char train;
   // while(1)
    {

        if(trainA.detected==1&&trainB.detected)
        {

            printf("С��A��B�������빫�������");
            //WaitForSingleObject(hMutex3,INFINITE);
            //WaitForSingleObject(hMutex2,INFINITE);
            train=JudgePass();
            //ReleaseMutex(hMutex2);
            //ReleaseMutex(hMutex3);

            if(train=='A')
            {
                trainA.state=S2;
                trainB.state=S5;
            }
            else if(train=='B')
            {
                trainA.state=S5;
                trainB.state=S2;
            }
            else if(train=='\n')
            {
                trainA.state=trainA.speed>=trainB.speed?S2:S5;
                trainB.state=trainA.speed>=trainB.speed?S5:S2;
            }
            trainB.detected=0;
        }
        else if(trainA.detected==2&&trainC.detected)
        {
            printf("С��A��C�������빫�������");
            //WaitForSingleObject(hMutex3,INFINITE);
            //WaitForSingleObject(hMutex2,INFINITE);
            train=JudgePass();
            //ReleaseMutex(hMutex2);
            //ReleaseMutex(hMutex3);

            if(train=='A')
            {
                trainA.state=S2;
                trainC.state=S5;
            }
            else if(train=='C')
            {
                trainA.state=S5;
                trainC.state=S2;
            }
            else if(train=='\n')
            {
                trainA.state=trainA.speed>=trainC.speed?S2:S5;
                trainC.state=trainA.speed>=trainC.speed?S5:S2;
            }
            trainC.detected=0;
        }
        else if((trainA.detected==1&&!trainB.detected)||(trainA.detected==2&&!trainC.detected)) trainA.state=S2;
        else if(!trainA.detected==1&&trainB.detected) trainB.state=S2;
        else if(!trainA.detected==2&&trainC.detected) trainC.state=S2;

    }
    //return 0;
}
