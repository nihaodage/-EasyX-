#define SKILL_BK(x) (WIDE / 4)*x - (skill_bk[0].getwidth() / 2)//��x�����ܵ����Ͻǵ�x����
void up_screen()//��������
{
	remain_skill = skill_num - now_skill_num;
	if ( remain_skill< 3)//�����漼��������������
	{
		
		for (int i = 1; i <= remain_skill; i++)//����ʣ��ļ���
		{
			putimage(SKILL_BK(i), HIGH / 4, &skillimg[s[i]]);//������������
		}
		if (remain_skill <= 0)//���ʣ�༼������<=0��ȫ����ռλ��
		{
			for (int i = 1; i <= 3; i++)//�������ż���
			{
				putimage(SKILL_BK(i), HIGH / 4, &skill_null[0]);//������������
			}
		}
		else//���ʣ�༼������С��3������0�Ͱ���
		{
			for (int i = remain_skill+1; i <= 3; i++)
			{
				putimage(SKILL_BK(i), HIGH / 4, &skill_null[0]);//������������
			}
		}
	}else//���ʣ�༼��>=3���������ü���
	{
		for (int i = 1; i <= 3; i++)//�������ż���
		{
			putimage(SKILL_BK(i), HIGH / 4, &skillimg[s[i]]);//������������
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		if(msg.x>= SKILL_BK(i) &&msg.x<= SKILL_BK(i) + skill_bk[0].getwidth()
			&&msg.y>= HIGH / 4&&msg.y<= HIGH / 4+ skill_bk[0].getheight())//��������ڵװ�1��
		{
			//�����ǰͼƬ�Ǵ���ʣ��ͼƬ�ھ��������ã�������Ǿͷ���ռλ��
			if(i<=remain_skill)putimage(SKILL_BK(i), HIGH / 4, &skillimg_bk[s[i]]);//���ɵװ�2����Ĭ���ǵװ�1
			else putimage(SKILL_BK(i), HIGH / 4, &skill_null[1]);
		}
		if (msg.x >= SKILL_BK(i) && msg.x <= SKILL_BK(i) + skill_bk[0].getwidth()
			&& msg.y >= HIGH / 4 && msg.y <= HIGH / 4 + skill_bk[0].getheight()
			&& msg.lbutton == VK_LBUTTON)//��������ڵװ��ϲ��Ұ��������
		{
			leveing = 0;//��������
			is_lv_img = 0;//�����ٴβ��ż��ܶ���
			//�����ǰ�ļ��ܴ���ʣ�༼��֮�оͼ���Ӧ��ֵ
			if(i<=remain_skill)skill[i==1?s[1] : (i == 2 ? s[2] : s[3])] = 1;//��¼ѡȡ�ļ���	
			cout << "ѡ�����";
			now_skill_num++;
		}
	}
	
}