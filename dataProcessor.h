#ifndef DATAPROCESSOR_H_INCLUDED
#define DATAPROCESSOR_H_INCLUDED

#include<windows.h>
//火车配置的默认参数
#define SPEED 1//火车默认速度
#define POSITION 1//默认启动位置
#define TIME 0//默认启动时间
#define CLWISE 1//顺时针（默认）
#define ANTICLWISE -1//逆时针
#define TRACKLEN 24//默认轨道长度
#define FAST 1
#define SLOW 2

//火车状态
#define S1 1//运行-非公共轨道
#define S2 2//运行-公共轨道
#define S3 3//暂停-非公共轨道
#define S4 4//停靠-公共轨道
#define S5 5//暂停-等待公共轨道

//extern HANDLE hMutex1;

//存储火车信息的结构体
typedef struct train{
    int speed;
    int position;
    int time;
    int direction;
    int trackLen;
    int restTime;
    int state;
    int detected;
    int type;
} Train;

//存储三辆火车的结构
extern Train trainA,trainB,trainC;
//分别代表公共轨道的起点和终点
extern int a1_in,a1_out,a2_in,a2_out,b_in,b_out,c_in,c_out;

//移动火车到下一位置，在run函数开始时调用
void move(Train *train);

//计时,状态转换结束后调用
void timeout(double time);

//模拟火车的运行,实现火车的状态迁移，用户设置完初始信息后调用
void run(void);

//判断哪辆火车进入公共轨道，当有车要进入公共轨道时调用
void judge(void);

#endif // DATAPROCESSOR_H_INCLUDED
