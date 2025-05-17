#include "tou.cpp"
//一共大约790行代码
int main()
{
	init();
	srand(GetTickCount() *100);

	
	m_sc();//加载主界面

	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			mciSendString("close ./image/music/m_bgm.mp3", 0, 0, 0);
			break;
		}
	}
	
	mciSendString("open ./image/music/g_bgm.mp3", 0, 0, 0);
	mciSendString("play ./image/music/g_bgm.mp3 repeat", 0, 0, 0);
	while (1)
	{
		Sleep(10);//卡时间

		if (GetAsyncKeyState('L'))rw_exp++;//外挂 
		BeginBatchDraw();
		cleardevice();//清理屏幕
		putimage(0, 0, &g_bk);//放置背景图
		pause();
		peekmessage(&msg, EX_MOUSE);//无论是否暂停都要peek鼠标信息，否则会鼠标刷新时间不同步
		
		if (is_pause == 1&& is_pause_screen==0)//处于暂停模式并且没有打开暂停界面并且不处于升级过程中
		{
			p_screen();
		}
		else if (leveing == 1)
		{
			if (is_lv_img == 0)//如果没播放动画
			{
				lvimg();
				is_lv_img = 1;//已经播放动画了
				//目前技能较少，所以不提供技能选择，如果技能够多将下面那行注释解开可以选择技能
				choose_skill();//从技能库中随机选取三个不重复的技能
			}
			up_screen();//打开升级界面
			if(leveing==0)enable_skill();//升级完后决定哪些技能需要开启
		}
		if (is_pause==0&&leveing==0)//没有暂停或没有升级过程中
		{
			cout << "不可能";
			thread first(mmove);//绘制鼠标上的点
			first.detach();

			rmove();//人物移动

			if (is_move == 0)//如果不移动播放不动图片
			{
				thread Move(stand_anim);
				Move.detach();
			}
			
			BloodBar(100, &hp, 60, 30, 30, 15, 15, 100);//输出血条，参数1是最大血量，2是当前血量，3是x坐标，4是y坐标标，5是高，6是x的弯曲程度，7是y的弯曲程度，8是血条长度
			
			mouse_move();//子弹的发射和杀死敌人

			summo_rwa();//生成奖励

			if (rand() % 20 == 0)//控制敌人的生成
			{
				thread second(summo);
				second.detach();
			}

			emy_move();//敌人移动 

			if (invin == 0)//如果不是处于无敌时间在判断能否死亡
			{
				thread third(be_hit);//检测有没有死
				third.detach();
			}

			if (rw_dead == 1)break;//如果死了结束循环

			ptext();//输出文字

			rw_win();
			
		}
		EndBatchDraw();
		
	}
	mciSendString("close  ./image/music/bgm.mp3 ", 0, 0, 0);
	setbkcolor(WHITE);//清屏，清屏后必须用双缓冲绘制，不然无法正常显示
	cleardevice();
	while (true)
	{
		BeginBatchDraw();
		dead_screen();
		EndBatchDraw();
	}
	
	
		
		
}