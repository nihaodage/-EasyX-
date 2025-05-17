#include <easyx.h>
#include <math.h>
void music_play()
{
	mciSendString("close ./image/music/attack_2.mp3  ", 0, 0, 0);//调用音乐
	mciSendString("play  ./image/music/attack_2.mp3  ", 0, 0, 0);//播放音乐
}
void shoot(double x,double y,double mx,double my)//创建一个子弹和他的相关参数
{
	thread ms(music_play);//播放攻击音效
	ms.detach();
	numk++;
	but[numk].x = x;//子弹的位置，默认在人物身上
	but[numk].y = y;
	double ct = atan2(my-y, mx - x);//求对应角度
	but[numk].direx = bt_speed * cos(ct);//求在x的分量
	but[numk].direy = bt_speed * sin(ct);//求在y的分量
}

void mouse_move()//鼠标移动
{
	setfillcolor(YELLOW);//设置子弹颜色
	for (int i = 1; i <= numk; i++)//枚举子弹
	{
		fillcircle(but[i].x += but[i].direx, but[i].y += but[i].direy, but_size);//加上对应的值并且绘制
		if (but[i].x > WIDE || but[i].x<0 || but[i].y>HIGH || but[i].y < 0)//如果离开了地图就删除
		{
			for (int j = i; j <= numk - 1; j++)
			{
				but[j] = but[j + 1];
			}
			numk--;//子弹数量减少
		}

		//以下是判断子弹杀死敌人
			for (int j = 0; j < num_emy; j++)//子弹已经枚举了，所以现在枚举敌人
			{
				for(int lb= - but_size;lb<=but_size;lb++)//遍历子弹的[-r,r]用来遍历边上所有的点
				{
					double x=but[i].x+lb, y=but[i].y+sqrt(but_size*but_size-lb*lb);//根据圆的方程得出对应的x和y的坐标
					if (x >= emy[j].x - shp && x <= emy[j].x + shp && y >= emy[j].y - shp && y <= emy[j].y + shp)//如果子弹和敌人的位置重合就执行
					{
						if (is_penetrate == 1)//如果允许穿透
						{
							if (but[i].have_hit_num == pene_num)//如果已经达到最大穿透数，则移除子弹
							{
								if (numk == 1)//如果只存在一颗子弹特判
								{
									memset(but[i].have_hit, 0, sizeof(but[i].have_hit));//将他的打过的敌人数组重置为0
									but[i].have_hit_num = 0;//将已经穿透的敌人重置为0
									numk--;//数量-1
								}
								else//否则考虑多颗子弹的情况
									for (int k = i; k <= numk - 1; k++)//移除子弹
									{
										but[k] = but[k + 1];
									}
								numk = max(0, numk - 1);//子弹数量减一，但最少为0
							}
							if (but[i].have_hit[j] == 0)//如果该敌人没被打过
							{
								emy[j].emy_hp[emy[j].emy_leve] -= pl_damage;//对应敌人以他的级别为最大生命值扣除玩家伤害血量
								but[i].have_hit[j] = 1;//该敌人被设为已经被打过
								++but[i].have_hit_num;//增加已穿透敌人数量
							}
						}
						else//不允许穿透则正常消失
						{
							for (int k = i; k <= numk - 1; k++)//移除子弹
							{
								but[k] = but[k + 1];
							}
							numk = max(0, numk - 1);//子弹数量减一，但最少为0
							emy[j].emy_hp[emy[j].emy_leve] -= pl_damage;//对应敌人以他的级别为最大生命值扣除玩家伤害血量
						}
						//以下是子弹杀敌人




						if (emy[j].emy_hp[emy[j].emy_leve] <= 0)//如果成功击杀
						{
							//以下是奖励的添加
							rwa[num_rwa].x = emy[j].x;//奖励位置为敌人的死亡位置
							rwa[num_rwa].y = emy[j].y;
							num_rwa++;//奖励数量++s

							for (int k = j; k < num_emy - 1; k++)//移除敌人
							{
								emy[k] = emy[k + 1];
							}
							num_emy = max(0, num_emy - 1);//敌人数量减一但最少是0

						}
						//以上为敌人的死亡
					}
				}
			}
			//以上是判断子弹杀死敌人
		
	}

		t2 = GetTickCount();//获取当前
		if (t2 - t1 > fre)//如果这次的时间减去上次发射的时间大于设定的频率才发射
		{

			shoot(rx,ry,msg.x, msg.y);//发生
			t1 = t2;//将上次的时间几下
			msg.message = EX_MOUSE;//发生了一次后将msg重置
		}
	
}
void mmove()//绘制鼠标的点
{
	peekmessage(&msg, EX_MOUSE);//无论是否暂停都要peek鼠标信息，否则会鼠标刷新时间不同步
	setfillcolor(DARKGRAY);
	fillcircle(msg.x, msg.y, 5);
}