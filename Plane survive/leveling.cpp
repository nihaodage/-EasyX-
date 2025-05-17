void lvimg()//升级过程动画
{
	EndBatchDraw();
	for (int i = 0; i < LVUP_IMG_NUM; i++)
	{
		Sleep(100);
		putimage(rx-GetStanWide, ry-GetStanhigh, &img_levup_under[i], SRCAND);//输出底片
		putimage(rx - GetStanWide, ry - GetStanhigh, &img_levup_color[i], SRCPAINT);//输出彩图
	}
	BeginBatchDraw();
}