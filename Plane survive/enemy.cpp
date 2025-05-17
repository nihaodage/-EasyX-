void xyval(double x, double y, int k)//求敌人在xy的分量
{
	double ct = atan2(y - ry, x - rx);//求对应角度
	emy[k].direx_emy[k] = emy_speed * cos(ct);//求在x的分量
	emy[k].direy_emy[k] = emy_speed * sin(ct);//求在y的分量
}
void summo()
{
	srand(GetTickCount() * 14 + 1919810);

	int sx = (rand() % WIDE);
	int sy = (rand()%2)?0:HIGH;

	int sx2=(rand()%2)?0:WIDE;
	int sy2=(rand() % HIGH);
	while (1)
	{

			num_emy++;//敌人数量加一
			emy[num_emy].emy_leve = 1;//目前敌人都是1级别的
			int t = rand();
			emy[num_emy].x = (t % 2) ? sx : sx2;//敌人出生位置
			emy[num_emy].y = (t % 2) ? sy : sy2;
			Sleep(10000000000);
	}
}
void emy_move()
{
	//EndBatchDraw();
	for (int i = 0; i < num_emy; i++)
	{
		xyval(emy[i].x, emy[i].y,i);
		emy[i].x -= emy[i].direx_emy[i];
		emy[i].y -= emy[i].direy_emy[i];
		putimage(emy[i].x-eny_width/2, emy[i].y-eny_high/2, &img_slm_color[0], SRCAND);//输出底片
		putimage(emy[i].x - eny_width / 2, emy[i].y - eny_high / 2, &img_slm_color[1], SRCPAINT);//输出彩图
	}
	//BeginBatchDraw();
}