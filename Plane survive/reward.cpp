#include <easyx.h>
void leve_up()
{
	
	if (leve <= 10)//���ݵȼ�������һ����Ҫ�ľ���
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

	if (rw_exp >= rq_exp)//�����ǰ�������������������
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
		setlinestyle(PS_SOLID);//����������ʽ
		setlinecolor(BLUE);//������ɫ

		fillcircle(rwa[i].x, rwa[i].y, rwa_shp);//���ƽ���
		
		if (rwa[i].x >= rx - GetStanWide && rwa[i].x <= rx + GetStanWide && rwa[i].y >= ry - GetStanhigh && rwa[i].y <= ry + GetStanhigh)//������������λ���ظ�
		{
			for (int j = i; j <= num_rwa - 1; j++)//�Ƴ�����λ��
			{
				rwa[j] = rwa[j + 1];
			}
			rw_exp += 1;//����+1
			leve_up();
		}
	}
}