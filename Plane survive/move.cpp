ExMessage keybd;
int stand_anim()
{
	//����һ������ѭ�������û�м��룬��һֱ���ֲ���������������÷���ֵ����ѭ����������
	keybd.message = EX_KEY;

	peekmessage(&keybd,0);
	if (keybd.ch=='W'|| keybd.ch == 'w'||keybd.ch == 'a'||keybd.ch == 's'||keybd.ch == 'd'||keybd.ch == 'A'||keybd.ch == 'S'||keybd.ch == 'D')
	{
		return 0;
		}
		else
		{
			putimage(rx-GetStanWide, ry- GetStanhigh, &Splayer_pic[PLAYER_NUM - 1], SRCAND);//�����Ƭ
			putimage(rx- GetStanWide, ry- GetStanhigh, &Splayer_pic[0], SRCPAINT);//����ƶ�����Ĳ�ͼ
		}
	
}
void rmove_anim(int direction)//ʵ����Ϊ����1Ϊ���ϣ�2Ϊ����
{
	if (direction == 1)
	{
		putimage(rx - GetStanWide, ry - GetStanhigh, &Lplayer_pic[PLAYER_NUM - 1], SRCAND);//�����Ƭ
		putimage(rx - GetStanWide, ry - GetStanhigh, &Lplayer_pic[0], SRCPAINT);//����ƶ�����Ĳ�ͼ
	}
	if (direction == 2)
	{
		putimage(rx - GetStanWide, ry - GetStanhigh, &Rplayer_pic[PLAYER_NUM - 1], SRCAND);//�����Ƭ
		putimage(rx - GetStanWide, ry - GetStanhigh, &Rplayer_pic[0], SRCPAINT);//����ƶ�����Ĳ�ͼ
	}
}

void rmove()
{
	int move_num[4] = { 0 };//�������ֲ�����ζ�Ƿ��ƶ���Ҳ��ζ���ƶ���������1����2
	if (GetAsyncKeyState('W')|| GetAsyncKeyState('w'))
	{
		ry = max(0+GetStanhigh, ry - speed);
		rmove_anim(move_num[0] = 1);//���������ֵ����ı��Ӧ�����±��ֵ
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
	
	is_move= move_num[0] + move_num[1] + move_num[2] + move_num[3];//�����Ϊ0��������ƶ���
}