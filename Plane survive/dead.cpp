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
	int d = 4;//�����ܻ���Χ
	int pl_d = 19;//����ܻ���Χ
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
							hp -= 10;//����ڱ������10��Ѫ
							if (hp > 0)//��������к���Ѫ�Ļ���ִ���޵�֡����
							{
								thread first(hurt_anim);
								first.detach();
								invin = 1;//��������оͿ�ʼ�޵�֡ʱ��
								Sleep(1000);//�޵�֡1s
								//ִ����˸����
								invin = 0;//�����޵�ʱ��
								return 0;
							}
							if (hp <= 0) { rw_dead = 1; return 0; }//���Ѫ<=0����������
						}
					}
				}
			}
		}
	}
}