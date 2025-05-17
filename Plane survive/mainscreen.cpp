void m_sc()
{
	putimage(0, 0, &m_bk);

	mciSendString("open ./image/music/m_bgm.mp3  ", 0, 0, 0);//播放主界面音乐
	mciSendString("play  ./image/music/m_bgm.mp3 repeat ", 0, 0, 0);
	
	
	settextcolor(BLACK);//设置文字颜色
	
	settextstyle(100, 0, "黑体");//设置文字宽度和字体
	outtextxy(WIDE / 2 -textwidth("崩坏的幻想乡")/2, HIGH / 4 -textheight("崩坏的幻想乡"), "崩坏的幻想乡");//输出标题
	
	settextstyle(50, 0, "黑体");//设置文字样式

	setlinecolor(BLACK);//设置矩形边框颜色
	fillrectangle(WIDE / 2 - textwidth("按空格开始游戏") / 2-20, HIGH - HIGH / 4-20, WIDE / 2 - textwidth("按空格开始游戏") / 2+ textwidth("按空格开始游戏")+20, HIGH - HIGH / 4+textheight("按空格开始游戏")+20);//输出矩形边框

	outtextxy(WIDE / 2 - textwidth("按空格开始游戏") / 2, HIGH - HIGH / 4, "按空格开始游戏");//输出主界面下方文字
}