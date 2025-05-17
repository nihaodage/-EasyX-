void hurt_anim()
{
	//最后一张为底片，先输出
	putimage(rx - GetStanWide, ry - GetStanhigh, &Splayer_pic[1], SRCAND);
	putimage(rx - GetStanWide, ry - GetStanhigh, &Splayer_pic[0], SRCPAINT);
	Sleep(200);
	//加载顺序：透明——高闪——透明
	//一共循环以上流程三次
	for (int cycle = 0; cycle < 3; cycle++)
	{
		
		for (int i = 0; i < HURT_ANIM_NUM - 1; i++)
		{
			putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[HURT_ANIM_NUM - 1], SRCAND);//输出底片
			putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[i], SRCPAINT);//依次输出透明高闪
			Sleep(50);
			if (i == HURT_ANIM_NUM - 2)//如果已经输出高闪则紧跟透明
			{
				putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[HURT_ANIM_NUM - 1], SRCAND);
				putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[0], SRCPAINT);
				Sleep(50);
			}
		}
	}
}