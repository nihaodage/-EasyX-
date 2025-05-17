void choose_skill()
{
	if(skill_num-now_skill_num>=3)//如果剩余有>=三个技能
	{
		do
		{
			s[1] = rand() % skill_num + 1;//s[1]赋值
			srand(s[1]);//改变随机数种子
		} while (!(skill[s[1]] == 0));//直到s[1]在skill数组里没有重复的

		do
		{
			s[2] = rand() % skill_num + 1;//s[2]赋值
			srand(s[2] + 31);//改变随机数种子
		} while (!(skill[s[2]] == 0 && s[2] != s[1]));//直到s[2]在skill数组里没有重复的并且不等于s[1]

		do
		{
			s[3] = rand() % skill_num + 1;//s[3]赋值
			srand(s[3] + 51);//改变随机数种子
		} while (!(skill[s[3]] == 0 && s[3] != s[1] && s[3] != s[2]));//直到s[2]在skill数组里没有重复的并且不等于s[1]并且不等于s[2]
	}
	else//如果小于三个则将剩下的依次给s1 s2 s3
	{
		int t=1;//当前是第几个赋值的
		for (int i = 1; i <= skill_num; i++)
		{
			if (skill[i] == 0)
			{
				s[t] = i;
				t++;
			}
		}
	}
}