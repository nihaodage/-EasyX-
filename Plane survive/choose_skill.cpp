void choose_skill()
{
	if(skill_num-now_skill_num>=3)//���ʣ����>=��������
	{
		do
		{
			s[1] = rand() % skill_num + 1;//s[1]��ֵ
			srand(s[1]);//�ı����������
		} while (!(skill[s[1]] == 0));//ֱ��s[1]��skill������û���ظ���

		do
		{
			s[2] = rand() % skill_num + 1;//s[2]��ֵ
			srand(s[2] + 31);//�ı����������
		} while (!(skill[s[2]] == 0 && s[2] != s[1]));//ֱ��s[2]��skill������û���ظ��Ĳ��Ҳ�����s[1]

		do
		{
			s[3] = rand() % skill_num + 1;//s[3]��ֵ
			srand(s[3] + 51);//�ı����������
		} while (!(skill[s[3]] == 0 && s[3] != s[1] && s[3] != s[2]));//ֱ��s[2]��skill������û���ظ��Ĳ��Ҳ�����s[1]���Ҳ�����s[2]
	}
	else//���С��������ʣ�µ����θ�s1 s2 s3
	{
		int t=1;//��ǰ�ǵڼ�����ֵ��
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