ExMessage keybd;
int stand_anim()
{
	//定义一个无限循环，如果没有键入，则一直保持不动，如果键入则用返回值打破循环跳出函数
	keybd.message = EX_KEY;

	peekmessage(&keybd,0);
	if (keybd.ch=='W'|| keybd.ch == 'w'||keybd.ch == 'a'||keybd.ch == 's'||keybd.ch == 'd'||keybd.ch == 'A'||keybd.ch == 'S'||keybd.ch == 'D')
	{
		return 0;
		}
		else
		{
			putimage(rx-GetStanWide, ry- GetStanhigh, &Splayer_pic[PLAYER_NUM - 1], SRCAND);//输出底片
			putimage(rx- GetStanWide, ry- GetStanhigh, &Splayer_pic[0], SRCPAINT);//输出移动方向的彩图
		}
	
}
void rmove_anim(int direction)//实参意为方向，1为左上，2为右下
{
	if (direction == 1)
	{
		putimage(rx - GetStanWide, ry - GetStanhigh, &Lplayer_pic[PLAYER_NUM - 1], SRCAND);//输出底片
		putimage(rx - GetStanWide, ry - GetStanhigh, &Lplayer_pic[0], SRCPAINT);//输出移动方向的彩图
	}
	if (direction == 2)
	{
		putimage(rx - GetStanWide, ry - GetStanhigh, &Rplayer_pic[PLAYER_NUM - 1], SRCAND);//输出底片
		putimage(rx - GetStanWide, ry - GetStanhigh, &Rplayer_pic[0], SRCPAINT);//输出移动方向的彩图
	}
}

void rmove()
{
	int move_num[4] = { 0 };//其中数字不仅意味是否移动，也意味着移动方向：左上1右下2
	if (GetAsyncKeyState('W')|| GetAsyncKeyState('w'))
	{
		ry = max(0+GetStanhigh, ry - speed);
		rmove_anim(move_num[0] = 1);//如果按下了值，则改变对应数组下标的值
	}
	if (GetAsyncKeyState('S') || GetAsyncKeyState('s'))
	{
		ry = min(HIGH- GetStanhigh, ry + speed);
		rmove_anim(move_num[1] = 2);
	}
	if (GetAsyncKeyState('A') || GetAsyncKeyState('a'))
	{
		rx = max(0+GetStanWide, rx - speed);
		rmove_anim(move_num[2] = 1);
	}
	if (GetAsyncKeyState('d') || GetAsyncKeyState('D'))
	{
		rx = min(WIDE- GetStanWide, rx + speed);
		rmove_anim(move_num[3] = 2);
	}
	
	is_move= move_num[0] + move_num[1] + move_num[2] + move_num[3];//如果不为0，则代表移动了
}