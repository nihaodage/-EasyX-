#include <easyx.h>
void rw_win()
{
	
	if (leve >= 10&&win_fl==1)
	{
		HWND hud = GetHWnd();
		SetWindowText(hud,"��Ӯ�ˣ�");
		int is = MessageBox(hud, "��ɹ��ﵽ�ˢ⼶��ȡ����ʤ���������Ҫ������Ϸ�͵㡰�ǡ�������������˾͵㡰��", "��Ӯ�ˣ�", MB_OKCANCEL);
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