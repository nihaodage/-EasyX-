void ptext()
{
	setbkmode(1);
	settextstyle(30,0,0);
	settextcolor(YELLOW);
	char c1[] = "��ǰLeve:", c2[] = "��ǰExp:";
	char c3[] = "HP:";
	outtextxy(WIDE - 300, 30, c1);//���c1
	
	char c[100000];
	sprintf_s(c, "%d", leve);//�ȼ�ת�����ı�
	outtextxy(WIDE - 300 + textwidth(c1)+10, 30, c);//����ȼ���ֵ
	outtextxy(WIDE - 300, 60, c2);//���c2

	sprintf_s(c, "%d", rw_exp);//��ǰ����ת�����ı�
	outtextxy(WIDE - 300 + textwidth(c2)+10, 60, c);//���������ֵ
	outtextxy(WIDE - 300 + textwidth(c2)+10+35, 59, "/ ");
	
	sprintf_s(c, "%d", rq_exp);//������ת�����ı�
	outtextxy(WIDE - 300 + textwidth(c2)+10+35+20, 60,c);

	sprintf_s(c, "%d", hp);//��Ѫ�������ı�
	outtextxy(0, 30, c3);//���c3
	outtextxy(textwidth(c3) +50, 30, c);//���HP��ֵ
	
}
