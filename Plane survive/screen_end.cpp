
void dead_screen()
{
	settextcolor(RED);
	settextstyle(150, 0, "����");
	outtextxy(WIDE / 2 - textwidth("������") / 2, HIGH / 2 - textheight("������") / 2 - 200, "������");

	settextcolor(BLACK);
	char c[20000];
	sprintf_s(c, "%d", leve);
	settextstyle(50, 0, "����");
	outtextxy(WIDE / 2 - textwidth("������") / 2 - 50 - 20, HIGH / 2 - textheight("������") / 2, "���յȼ���");
	outtextxy(WIDE / 2 - textwidth("������") / 2 + textwidth("���յȼ���") - 40 - 20, HIGH / 2 - textheight("������") / 2, c);

	outtextxy(WIDE / 2 - textwidth("Ŭ���ﵽ���ߵȼ���") / 2, HIGH - 300, "Ŭ���ﵽ���ߵȼ���");

	setlinecolor(BLACK);
	rectangle(WIDE / 2 - textwidth("���ո��˳���Ϸ") / 2 - 20, HIGH - 100 - 20, WIDE / 2 + textwidth("���ո��˳���Ϸ") / 2 + 20, HIGH - 100 + textheight("���ո��˳���Ϸ") + 20);
	settextcolor(DARKGRAY);
	outtextxy(WIDE / 2 - textwidth("���ո��˳���Ϸ") / 2, HIGH - 100, "���ո��˳���Ϸ");
	if (GetAsyncKeyState(VK_SPACE))exit(0);
}