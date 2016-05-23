#ifndef _input_H
#define _input_H

//extern HANDLE hMutex1;//extern HANDLE /*hMutex1*/hMutex2;
void CreateTrain (void);//设置火车的初始信息

DWORD WINAPI ChangeInformation(LPVOID lpParameter);//修改火车的运动状态

char JudgePass(void);//优先通过的车辆

#endif // _input_H
