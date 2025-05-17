#include <easyx.h>
void rw_win()
{
	
	if (leve >= 10&&win_fl==1)
	{
		HWND hud = GetHWnd();
		SetWindowText(hud,"你赢了！");
		int is = MessageBox(hud, "你成功达到了⑩级，取得了胜利，如果想要继续游戏就点“是”，如果不想玩了就点“否”", "你赢了！", MB_OKCANCEL);
		if (is == IDOK)
		{
			win_fl = 1;
		}
		else
		{
			exit(0);
		}
		

	}
}