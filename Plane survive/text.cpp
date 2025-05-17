void ptext()
{
	setbkmode(1);
	settextstyle(30,0,0);
	settextcolor(YELLOW);
	char c1[] = "当前Leve:", c2[] = "当前Exp:";
	char c3[] = "HP:";
	outtextxy(WIDE - 300, 30, c1);//输出c1
	
	char c[100000];
	sprintf_s(c, "%d", leve);//等级转换成文本
	outtextxy(WIDE - 300 + textwidth(c1)+10, 30, c);//输出等级数值
	outtextxy(WIDE - 300, 60, c2);//输出c2

	sprintf_s(c, "%d", rw_exp);//当前经验转换成文本
	outtextxy(WIDE - 300 + textwidth(c2)+10, 60, c);//输出经验数值
	outtextxy(WIDE - 300 + textwidth(c2)+10+35, 59, "/ ");
	
	sprintf_s(c, "%d", rq_exp);//需求经验转换成文本
	outtextxy(WIDE - 300 + textwidth(c2)+10+35+20, 60,c);

	sprintf_s(c, "%d", hp);//经血量换成文本
	outtextxy(0, 30, c3);//输出c3
	outtextxy(textwidth(c3) +50, 30, c);//输出HP数值
	
}
