void hurt_anim()
{
	//���һ��Ϊ��Ƭ�������
	putimage(rx - GetStanWide, ry - GetStanhigh, &Splayer_pic[1], SRCAND);
	putimage(rx - GetStanWide, ry - GetStanhigh, &Splayer_pic[0], SRCPAINT);
	Sleep(200);
	//����˳��͸��������������͸��
	//һ��ѭ��������������
	for (int cycle = 0; cycle < 3; cycle++)
	{
		
		for (int i = 0; i < HURT_ANIM_NUM - 1; i++)
		{
			putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[HURT_ANIM_NUM - 1], SRCAND);//�����Ƭ
			putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[i], SRCPAINT);//�������͸������
			Sleep(50);
			if (i == HURT_ANIM_NUM - 2)//����Ѿ�������������͸��
			{
				putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[HURT_ANIM_NUM - 1], SRCAND);
				putimage(rx - GetStanWide, ry - GetStanhigh, &hurt_anim_p[0], SRCPAINT);
				Sleep(50);
			}
		}
	}
}