#define D_KEY(key) GetAsyncKeyState(key)//是否按下
#define U_KEY(key) !GetAsyncKeyState(key)//是否抬起
void pause()
{//未暂停->暂停
	if (D_KEY(VK_ESCAPE)&& is_pause == 0 && is_press_ESC == 0)//如果按下ESC，并且不处于暂停状态而且没有按下ESC就执行
	{
		is_pause = 1;
		is_press_ESC = 1;
	}
	if (U_KEY(VK_ESCAPE) && is_press_ESC == 1)//如果抬起了ESC并且在按下ESC的状态中
	{
		is_press_ESC =0;
	}
	
//暂停->未暂停
	if (D_KEY(VK_ESCAPE) && is_pause == 1 && is_press_ESC == 0)//如果按下ESC，并且不处于暂停状态而且没有按下ESC就执行
	{
		is_pause = 0;
		is_press_ESC = 1;
	}
	if (U_KEY(VK_ESCAPE) && is_press_ESC == 1)//如果抬起了ESC并且在按下ESC的状态中
	{
		is_press_ESC = 0;
	}

}