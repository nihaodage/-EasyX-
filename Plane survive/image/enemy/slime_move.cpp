#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<easyx.h>
#define SLM_ANIM_NUM 2//ʷ��ķ�ƶ�ͼƬ��������ͼ�͵�Ƭ��
#include <iostream>
using namespace std;
int en_x = 100, en_y = 100, en_width = 22, en_high = 23;//22��23Ϊʷ��ķͼƬ����
IMAGE img_slm_move[2];//����ʷ��ķͼ�����
void en_move()
{
	putimage(en_x,en_y, &img_slm_move[0], SRCAND);//�����Ƭ
	putimage(en_x, en_y, &img_slm_move[1], SRCPAINT);//�����ͼ
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
	for (;;en_x+=50, en_y+=50)//ģ��ʷ��ķ�˶�
	{
		en_move();
		
	}


}