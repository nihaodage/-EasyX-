#include "tou.cpp"
//һ����Լ790�д���
int main()
{
	init();
	srand(GetTickCount() *100);

	
	m_sc();//����������

	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			mciSendString("close ./image/music/m_bgm.mp3", 0, 0, 0);
			break;
		}
	}
	
	mciSendString("open ./image/music/g_bgm.mp3", 0, 0, 0);
	mciSendString("play ./image/music/g_bgm.mp3 repeat", 0, 0, 0);
	while (1)
	{
		Sleep(10);//��ʱ��

		if (GetAsyncKeyState('L'))rw_exp++;//��� 
		BeginBatchDraw();
		cleardevice();//������Ļ
		putimage(0, 0, &g_bk);//���ñ���ͼ
		pause();
		peekmessage(&msg, EX_MOUSE);//�����Ƿ���ͣ��Ҫpeek�����Ϣ����������ˢ��ʱ�䲻ͬ��
		
		if (is_pause == 1&& is_pause_screen==0)//������ͣģʽ����û�д���ͣ���沢�Ҳ���������������
		{
			p_screen();
		}
		else if (leveing == 1)
		{
			if (is_lv_img == 0)//���û���Ŷ���
			{
				lvimg();
				is_lv_img = 1;//�Ѿ����Ŷ�����
				//Ŀǰ���ܽ��٣����Բ��ṩ����ѡ��������ܹ��ཫ��������ע�ͽ⿪����ѡ����
				choose_skill();//�Ӽ��ܿ������ѡȡ�������ظ��ļ���
			}
			up_screen();//����������
			if(leveing==0)enable_skill();//������������Щ������Ҫ����
		}
		if (is_pause==0&&leveing==0)//û����ͣ��û������������
		{
			cout << "������";
			thread first(mmove);//��������ϵĵ�
			first.detach();

			rmove();//�����ƶ�

			if (is_move == 0)//������ƶ����Ų���ͼƬ
			{
				thread Move(stand_anim);
				Move.detach();
			}
			
			BloodBar(100, &hp, 60, 30, 30, 15, 15, 100);//���Ѫ��������1�����Ѫ����2�ǵ�ǰѪ����3��x���꣬4��y����꣬5�Ǹߣ�6��x�������̶ȣ�7��y�������̶ȣ�8��Ѫ������
			
			mouse_move();//�ӵ��ķ����ɱ������

			summo_rwa();//���ɽ���

			if (rand() % 20 == 0)//���Ƶ��˵�����
			{
				thread second(summo);
				second.detach();
			}

			emy_move();//�����ƶ� 

			if (invin == 0)//������Ǵ����޵�ʱ�����ж��ܷ�����
			{
				thread third(be_hit);//�����û����
				third.detach();
			}

			if (rw_dead == 1)break;//������˽���ѭ��

			ptext();//�������

			rw_win();
			
		}
		EndBatchDraw();
		
	}
	mciSendString("close  ./image/music/bgm.mp3 ", 0, 0, 0);
	setbkcolor(WHITE);//�����������������˫������ƣ���Ȼ�޷�������ʾ
	cleardevice();
	while (true)
	{
		BeginBatchDraw();
		dead_screen();
		EndBatchDraw();
	}
	
	
		
		
}