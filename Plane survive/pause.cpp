#define D_KEY(key) GetAsyncKeyState(key)//�Ƿ���
#define U_KEY(key) !GetAsyncKeyState(key)//�Ƿ�̧��
void pause()
{//δ��ͣ->��ͣ
	if (D_KEY(VK_ESCAPE)&& is_pause == 0 && is_press_ESC == 0)//�������ESC�����Ҳ�������ͣ״̬����û�а���ESC��ִ��
	{
		is_pause = 1;
		is_press_ESC = 1;
	}
	if (U_KEY(VK_ESCAPE) && is_press_ESC == 1)//���̧����ESC�����ڰ���ESC��״̬��
	{
		is_press_ESC =0;
	}
	
//��ͣ->δ��ͣ
	if (D_KEY(VK_ESCAPE) && is_pause == 1 && is_press_ESC == 0)//�������ESC�����Ҳ�������ͣ״̬����û�а���ESC��ִ��
	{
		is_pause = 0;
		is_press_ESC = 1;
	}
	if (U_KEY(VK_ESCAPE) && is_press_ESC == 1)//���̧����ESC�����ڰ���ESC��״̬��
	{
		is_press_ESC = 0;
	}

}