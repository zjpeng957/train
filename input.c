#include<stdio.h>
#include "dataProcessor.h"
#include "input.h"
#include<string.h>
#include<windows.h>
void CreateTrain (void)//���û𳵵ĳ�ʼ��Ϣ
{
    FILE *fp;
    //A��
    if((fp=fopen("A����Ϣ.txt","w"))==NULL)
    {
        printf("��ǰ�޷�����A����Ϣ��");
        exit(1);
    }
    printf("������A�𳵵���Ϣ\n");
    printf("���ٶȣ�m/s��:");scanf("%d",&trainA.speed);
    printf("����˳ʱ��Ϊ1����ʱ��Ϊ-1����");scanf("%d",&trainA.direction);
    printf("������ȣ�m��:");scanf("%d",&trainA.trackLen);
    printf("��ʼλ��(0���������)��");scanf("%d",&trainA.position);
    printf("����ʱ�䣨�ӳ���ʼ������/s����");scanf("%d",&trainA.time);
    printf("�������ͣ��ʱ�䣺");scanf("%d",&trainA.restTime);
    trainA.state=S1;
    if(trainA.direction==1)//˳ʱ��
        fprintf(fp,"���ٶȣ�%d\n����%s\n������ȣ�%d\n��ʼλ�ã�%d\n����ʱ�䣺%d\n"
                "�������ͣ��ʱ�䣺%d\n��״̬��%s",trainA.speed,"˳ʱ��",trainA.trackLen,trainA.position,trainA.time,trainA.restTime,"���С��������");
    else//��ʱ��
        fprintf(fp,"���ٶȣ�%d\n����%s\n������ȣ�%d\n��ʼλ�ã�%d\n����ʱ�䣺%d\n"
                "�������ͣ��ʱ�䣺%d\n��״̬��%s",trainA.speed,"��ʱ��",trainA.trackLen,trainA.position,trainA.time,trainA.restTime,"���С��������");
    fclose(fp);

	//B��
    if((fp=fopen("B����Ϣ.txt","w"))==NULL)
    {
        printf("��ǰ�޷�����B����Ϣ��");
        exit(1);
    }
    printf("������B�𳵵���Ϣ\n");
    printf("���ٶȣ�m/s��:");scanf("%d",&trainB.speed);
    printf("����˳ʱ��Ϊ1����ʱ��Ϊ-1����");scanf("%d",&trainB.direction);
    printf("������ȣ�m��:");scanf("%d",&trainB.trackLen);
    printf("��ʼλ��(0���������)��");scanf("%d",&trainB.position);
    printf("����ʱ�䣨�ӳ���ʼ������/s����");scanf("%d",&trainB.time);
    printf("�������ͣ��ʱ�䣺");scanf("%d",&trainB.restTime);
    trainB.state=S1;
    if(trainB.direction==1)//˳ʱ��
        fprintf(fp,"���ٶȣ�%d\n����%s\n������ȣ�%d\n��ʼλ�ã�%d\n����ʱ�䣺%d\n"
                "�������ͣ��ʱ�䣺%d\n��״̬��%s",trainB.speed,"˳ʱ��",trainB.trackLen,trainB.position,trainB.time,trainB.restTime,"���С��������");
    else//��ʱ��
        fprintf(fp,"���ٶȣ�%d\n����%s\n������ȣ�%d\n��ʼλ�ã�%d\n����ʱ�䣺%d\n"
                "�������ͣ��ʱ�䣺%d\n��״̬��%s",trainB.speed,"��ʱ��",trainB.trackLen,trainB.position,trainB.time,trainB.restTime,"���С��������");
    fclose(fp);


    //C��
    if((fp=fopen("C����Ϣ.txt","w"))==NULL)
    {
        printf("��ǰ�޷�����C����Ϣ��");
        exit(1);
    }
    printf("������C�𳵵���Ϣ\n");
    printf("���ٶȣ�m/s��:");scanf("%d",&trainC.speed);
    printf("����˳ʱ��Ϊ1����ʱ��Ϊ-1����");scanf("%d",&trainC.direction);
    printf("������ȣ�m��:");scanf("%d",&trainC.trackLen);
    printf("��ʼλ��(0���������)��");scanf("%d",&trainC.position);
    printf("����ʱ�䣨�ӳ���ʼ������/s����");scanf("%d",&trainC.time);
    printf("�������ͣ��ʱ�䣺");scanf("%d",&trainC.restTime);
    trainC.state=S1;
    if(trainC.direction==1)//˳ʱ��
        fprintf(fp,"���ٶȣ�%d\n����%s\n������ȣ�%d\n��ʼλ�ã�%d\n����ʱ�䣺%d\n"
                "�������ͣ��ʱ�䣺%d\n��״̬��%s",trainC.speed,"˳ʱ��",trainC.trackLen,trainC.position,trainC.time,trainC.restTime,"���С��������");
    else//��ʱ��
        fprintf(fp,"���ٶȣ�%d\n����%s\n������ȣ�%d\n��ʼλ�ã�%d\n����ʱ�䣺%d\n"
                "�������ͣ��ʱ�䣺%d\n��״̬��%s",trainC.speed,"��ʱ��",trainC.trackLen,trainC.position,trainC.time,trainC.restTime,"���С��������");
    fclose(fp);

}


DWORD WINAPI ChangeInformation(LPVOID lpParameter)
{
    char string1[100];
    while(1)
    {
        //WaitForSingleObject(hMutex1,INFINITE);
        //WaitForSingleObject(hMutex2,INFINITE);

        printf("���롱PA����С����ͣ�����롱SA���û��ٴ�����\n");
        printf("���롱PB����С����ͣ�����롱SB���û��ٴ�����\n");
        printf("���롱PC����С����ͣ�����롱SC���û��ٴ�����\n");
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
        else printf("������ǷǷ���Ϣ");
        //ReleaseMutex(hMutex1);
        //ReleaseMutex(hMutex2);
    }
}

char JudgePass(void)
{
    printf("����������ͨ����С�𳵣�");
    char trainNum;
    scanf("%c",&trainNum);
    getchar();
    return trainNum;
}












