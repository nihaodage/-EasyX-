#define SKILL_BK(x) (WIDE / 4)*x - (skill_bk[0].getwidth() / 2)//第x个技能的左上角的x坐标
void up_screen()//升级界面
{
	remain_skill = skill_num - now_skill_num;
	if ( remain_skill< 3)//如果库存技能数量不到三个
	{
		
		for (int i = 1; i <= remain_skill; i++)//遍历剩余的技能
		{
			putimage(SKILL_BK(i), HIGH / 4, &skillimg[s[i]]);//生成三个技能
		}
		if (remain_skill <= 0)//如果剩余技能数量<=0则全都放占位符
		{
			for (int i = 1; i <= 3; i++)//放置三张技能
			{
				putimage(SKILL_BK(i), HIGH / 4, &skill_null[0]);//生成三个技能
			}
		}
		else//如果剩余技能数量小于3但大于0就按需
		{
			for (int i = remain_skill+1; i <= 3; i++)
			{
				putimage(SKILL_BK(i), HIGH / 4, &skill_null[0]);//生成三个技能
			}
		}
	}else//如果剩余技能>=3就正常放置技能
	{
		for (int i = 1; i <= 3; i++)//放置三张技能
		{
			putimage(SKILL_BK(i), HIGH / 4, &skillimg[s[i]]);//生成三个技能
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		if(msg.x>= SKILL_BK(i) &&msg.x<= SKILL_BK(i) + skill_bk[0].getwidth()
			&&msg.y>= HIGH / 4&&msg.y<= HIGH / 4+ skill_bk[0].getheight())//如果鼠标放在底版1上
		{
			//如果当前图片是处于剩余图片内就正常放置，如果不是就放置占位符
			if(i<=remain_skill)putimage(SKILL_BK(i), HIGH / 4, &skillimg_bk[s[i]]);//生成底版2，但默认是底版1
			else putimage(SKILL_BK(i), HIGH / 4, &skill_null[1]);
		}
		if (msg.x >= SKILL_BK(i) && msg.x <= SKILL_BK(i) + skill_bk[0].getwidth()
			&& msg.y >= HIGH / 4 && msg.y <= HIGH / 4 + skill_bk[0].getheight()
			&& msg.lbutton == VK_LBUTTON)//如果鼠标放在底版上并且按下了左键
		{
			leveing = 0;//结束升级
			is_lv_img = 0;//可以再次播放技能动画
			//如果当前的技能处于剩余技能之中就加相应的值
			if(i<=remain_skill)skill[i==1?s[1] : (i == 2 ? s[2] : s[3])] = 1;//记录选取的技能	
			cout << "选择完毕";
			now_skill_num++;
		}
	}
	
}