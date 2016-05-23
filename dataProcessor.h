#ifndef DATAPROCESSOR_H_INCLUDED
#define DATAPROCESSOR_H_INCLUDED

#include<windows.h>
//�����õ�Ĭ�ϲ���
#define SPEED 3//��Ĭ���ٶ�
#define POSITION 0//Ĭ������λ��
#define TIME 0//Ĭ������ʱ��
#define CLWISE 1//˳ʱ�루Ĭ�ϣ�
#define ANTICLWISE -1//��ʱ��
#define TRACKLEN 24//Ĭ�Ϲ������

//��״̬
#define S1 1//����-�ǹ������
#define S2 2//����-�������
#define S3 3//��ͣ-�ǹ������
#define S4 4//ͣ��-�������
#define S5 5//��ͣ-�ȴ��������

//extern HANDLE hMutex1;

//�洢����Ϣ�Ľṹ��
typedef struct train{
    int speed;
    int position;
    int time;
    int direction;
    int trackLen;
    int restTime;
    int state;
    int detected;
} Train;

//�洢�����𳵵Ľṹ
extern Train trainA,trainB,trainC;
//�ֱ����������������յ�
extern int a1_in,a1_out,a2_in,a2_out,b_in,b_out,c_in,c_out;

//�ƶ��𳵵���һλ�ã���run������ʼʱ����
void move(Train *train);

//��ʱ,״̬ת�����������
void timeout(double time);

//ģ��𳵵�����,ʵ�ֻ𳵵�״̬Ǩ�ƣ��û��������ʼ��Ϣ�����
DWORD WINAPI run(LPVOID lpParameter);

//�ж������𳵽��빫����������г�Ҫ���빫�����ʱ����
void judge(void);

#endif // DATAPROCESSOR_H_INCLUDED
