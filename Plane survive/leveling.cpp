void lvimg()//�������̶���
{
	EndBatchDraw();
	for (int i = 0; i < LVUP_IMG_NUM; i++)
	{
		Sleep(100);
		putimage(rx-GetStanWide, ry-GetStanhigh, &img_levup_under[i], SRCAND);//�����Ƭ
		putimage(rx - GetStanWide, ry - GetStanhigh, &img_levup_color[i], SRCPAINT);//�����ͼ
	}
	BeginBatchDraw();
}