#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<easyx.h>
#define LEVUP_ANIM_NUM 9
#include <iostream>
using namespace std;
int rx = 100, ry = 100, width = 62, high = 71;//全局变量，玩家角色相关参数
IMAGE img_levup_color[LEVUP_ANIM_NUM], img_levup_under[LEVUP_ANIM_NUM];//定义图片变量，color为彩图，under为底图
void levup()
{
	
	for (int i=0;i < LEVUP_ANIM_NUM;i++)
	{
		putimage(rx, ry, &img_levup_under[i], SRCAND);//输出底片
		putimage(rx, ry, &img_levup_color[i], SRCPAINT);//输出彩图
		Sleep(50);
	}
	
}
int main()
{
	
	initgraph(520, 520);
	setbkcolor(WHITE);
	
	cleardevice();
	//加载升级动画的底图和彩图
	for (int i = 0;i < LEVUP_ANIM_NUM;i++)
	{
		char levup_anim_color[30],levup_anim_under[30];
		sprintf_s(levup_anim_under, "%s%d%s", "water4000", i + 1, "_under.jpg");
		loadimage(&img_levup_under[i], levup_anim_under, width, high);
		sprintf_s(levup_anim_color, "%s%d%s", "water4000", i + 1, ".jpg");
		loadimage(&img_levup_color[i], levup_anim_color, width, high);
	}
	
	while (1)
	{
		levup();//将玩家角色参数和图像变量设为全局变量，因此不需传递参数
		Sleep(1000);
	}
	
}