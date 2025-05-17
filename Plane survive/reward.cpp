#include <easyx.h>
void leve_up()
{
	
	if (leve <= 10)//根据等级设置下一级需要的经验
	{
		rq_exp = leve + 20;
	}
	else if (leve <= 20)
	{
		rq_exp = (leve+10) * 3;
	}
	else if (leve <= 30)
	{
		rq_exp = (leve+20) * 4;
	}

	if (rw_exp >= rq_exp)//如果当前经验大于需求经验则升级
	{
		leveing = 1;
		rw_exp = 0;
		leve++;
	}
}
void summo_rwa()
{
	setfillcolor(YELLOW);

	for (int i = 0; i < num_rwa; i++)
	{
		setlinestyle(PS_SOLID);//设置线条样式
		setlinecolor(BLUE);//线条颜色

		fillcircle(rwa[i].x, rwa[i].y, rwa_shp);//绘制奖励
		
		if (rwa[i].x >= rx - GetStanWide && rwa[i].x <= rx + GetStanWide && rwa[i].y >= ry - GetStanhigh && rwa[i].y <= ry + GetStanhigh)//如果奖励和玩家位置重复
		{
			for (int j = i; j <= num_rwa - 1; j++)//移除奖励位置
			{
				rwa[j] = rwa[j + 1];
			}
			rw_exp += 1;//经验+1
			leve_up();
		}
	}
}