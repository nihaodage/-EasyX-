#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<easyx.h>
#define SLM_ANIM_NUM 2//史莱姆移动图片总数（彩图和底片）
#include <iostream>
using namespace std;
int en_x = 100, en_y = 100, en_width = 22, en_high = 23;//22，23为史莱姆图片参数
IMAGE img_slm_move[2];//定义史莱姆图像变量
void en_move()
{
	putimage(en_x,en_y, &img_slm_move[0], SRCAND);//输出底片
	putimage(en_x, en_y, &img_slm_move[1], SRCPAINT);//输出彩图
	Sleep(50);
	
}
int main()
{
	initgraph(520, 520);
	setbkcolor(BLACK);
	cleardevice();
	for (int i = 0;i < SLM_ANIM_NUM;i++)
	{
		char slm_move_anim[20];
		sprintf_s(slm_move_anim, "%s%d%s", "slime_", i + 1, ".jpg");
		loadimage(&img_slm_move[i], slm_move_anim, en_width, en_high);
	}
	for (;;en_x+=50, en_y+=50)//模拟史莱姆运动
	{
		en_move();
		
	}


}