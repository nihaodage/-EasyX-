int win()
{
	if (leve == 10)
	{
		return 1;
	}
	return 0;
}

int be_hit()
{
	int d = 4;//敌人受击范围
	int pl_d = 19;//玩家受击范围
	int gsw = GetStanWide;
	int gsh = GetStanhigh;
	for (int i = rx - gsw + pl_d; i <= rx + gsw - pl_d; i++)
	{
		for (int j = ry - gsh + pl_d; j <= ry + gsh - pl_d; j++)
		{
			for (int k = 0; k < num_emy; k++)
			{
				for (int n = emy[k].x - shp+d; n <= emy[k].x + shp-d; n++)
				{
					for (int m = emy[k].y - shp+d; m <= emy[k].y + shp-d; m++)
					{
						if (i == n && j == m)
						{
							hp -= 10;//如果在被打则扣10点血
							if (hp > 0)//如果被打中后还有血的话就执行无敌帧动画
							{
								thread first(hurt_anim);
								first.detach();
								invin = 1;//如果被打中就开始无敌帧时间
								Sleep(1000);//无敌帧1s
								//执行闪烁动画
								invin = 0;//结束无敌时间
								return 0;
							}
							if (hp <= 0) { rw_dead = 1; return 0; }//如果血<=0立马返回死亡
						}
					}
				}
			}
		}
	}
}