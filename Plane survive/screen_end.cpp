
void dead_screen()
{
	settextcolor(RED);
	settextstyle(150, 0, "黑体");
	outtextxy(WIDE / 2 - textwidth("你输了") / 2, HIGH / 2 - textheight("你输了") / 2 - 200, "你死了");

	settextcolor(BLACK);
	char c[20000];
	sprintf_s(c, "%d", leve);
	settextstyle(50, 0, "黑体");
	outtextxy(WIDE / 2 - textwidth("你输了") / 2 - 50 - 20, HIGH / 2 - textheight("你输了") / 2, "最终等级：");
	outtextxy(WIDE / 2 - textwidth("你输了") / 2 + textwidth("最终等级：") - 40 - 20, HIGH / 2 - textheight("你输了") / 2, c);

	outtextxy(WIDE / 2 - textwidth("努力达到更高等级吧") / 2, HIGH - 300, "努力达到更高等级吧");

	setlinecolor(BLACK);
	rectangle(WIDE / 2 - textwidth("按空格退出游戏") / 2 - 20, HIGH - 100 - 20, WIDE / 2 + textwidth("按空格退出游戏") / 2 + 20, HIGH - 100 + textheight("按空格退出游戏") + 20);
	settextcolor(DARKGRAY);
	outtextxy(WIDE / 2 - textwidth("按空格退出游戏") / 2, HIGH - 100, "按空格退出游戏");
	if (GetAsyncKeyState(VK_SPACE))exit(0);
}