#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<easyx.h>
#define LEVUP_ANIM_NUM 9
#include <iostream>
using namespace std;
int rx = 100, ry = 100, width = 62, high = 71;//ȫ�ֱ�������ҽ�ɫ��ز���
IMAGE img_levup_color[LEVUP_ANIM_NUM], img_levup_under[LEVUP_ANIM_NUM];//����ͼƬ������colorΪ��ͼ��underΪ��ͼ
void levup()
{
	
	for (int i=0;i < LEVUP_ANIM_NUM;i++)
	{
		putimage(rx, ry, &img_levup_under[i], SRCAND);//�����Ƭ
		putimage(rx, ry, &img_levup_color[i], SRCPAINT);//�����ͼ
		Sleep(50);
	}
	
}
int main()
{
	
	initgraph(520, 520);
	setbkcolor(WHITE);
	
	cleardevice();
	//�������������ĵ�ͼ�Ͳ�ͼ
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
		levup();//����ҽ�ɫ������ͼ�������Ϊȫ�ֱ�������˲��贫�ݲ���
		Sleep(1000);
	}
	
}