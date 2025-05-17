bool BloodBar(int TotalBlood, int* NowBlood, int x, int y, int hight, int ellipsewidh, int ellipseheight, int BloodBarLenth)
{
	int* nowblood = NowBlood;
	//printf("当前血量:%d\n", *nowblood);
	//计算血量与总血量比值
	float BloodRate = *nowblood  * 1.0 / TotalBlood;
	//printf("血量比值：%.2f\n", BloodRate);
	//实际血量长度
	int EndBloodBarLenth = BloodBarLenth * BloodRate;
	//边框颜色及其填充色
	setcolor(BLACK);
	setfillcolor(WHITE);
	//绘制血框
	fillroundrect(
		x, y, x + BloodBarLenth, y + hight, ellipsewidh, ellipseheight
	);
	//绘制血量
	//血量健康（>60%)
	if (BloodRate >= 0.6)
	{
		setfillcolor(GREEN);
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + hight, ellipsewidh, ellipseheight
		);
		//结算血量扣减
		*nowblood = *nowblood;
	}
	//血量危险（>30%）
	else if (BloodRate >= 0.3)
	{
		setfillcolor(RGB(255, 165, 0));
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + hight, ellipsewidh, ellipseheight
		);
		//结算血量扣减
		*nowblood = *nowblood;
	}
	//血量濒死（>0%）
	else if (BloodRate >= 0)
	{
		setfillcolor(RED);
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + hight, ellipsewidh, ellipseheight
		);
		//结算血量扣减
		*nowblood = *nowblood;
	}
	//死亡则返回false终止循环
	else {
		return false;
	}
	//未死继续循环
	return true;

}