//第一个技能穿透，需要变量
//int is_penetrate = 1;//是否开启穿透技能，No.1
//int pene_num = 2;//允许穿透的敌人数量
//第二个技能，子弹体积，需要变量but+size
//第三个技能，射速,需要变量fre
//第四个技能，攻击力,需要变量,pl_damage
void enable_skill()//决定要开启的技能
{
	for(int i=1;i<=skill_num;i++)
	{
		if(skill[i]==1)
		{
			switch (i)
			{
			case 1://第一个穿透技能
				is_penetrate = 1;
				pene_num = 2;
				break;
			case 2://第二个技能，增加子弹体积
				but_size = 6;
				break;
			case 3://第三个技能，增加射速
				fre = 600;
				break;
			case 4://第四个技能,增加攻击力
				pl_damage = 20;
				break;
			}
		}
	}
}