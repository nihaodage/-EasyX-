void xyval(double x, double y, int k)//�������xy�ķ���
{
	double ct = atan2(y - ry, x - rx);//���Ӧ�Ƕ�
	emy[k].direx_emy[k] = emy_speed * cos(ct);//����x�ķ���
	emy[k].direy_emy[k] = emy_speed * sin(ct);//����y�ķ���
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

			num_emy++;//����������һ
			emy[num_emy].emy_leve = 1;//Ŀǰ���˶���1�����
			int t = rand();
			emy[num_emy].x = (t % 2) ? sx : sx2;//���˳���λ��
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
		putimage(emy[i].x-eny_width/2, emy[i].y-eny_high/2, &img_slm_color[0], SRCAND);//�����Ƭ
		putimage(emy[i].x - eny_width / 2, emy[i].y - eny_high / 2, &img_slm_color[1], SRCPAINT);//�����ͼ
	}
	//BeginBatchDraw();
}