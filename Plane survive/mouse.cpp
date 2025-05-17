#include <easyx.h>
#include <math.h>
void music_play()
{
	mciSendString("close ./image/music/attack_2.mp3  ", 0, 0, 0);//��������
	mciSendString("play  ./image/music/attack_2.mp3  ", 0, 0, 0);//��������
}
void shoot(double x,double y,double mx,double my)//����һ���ӵ���������ز���
{
	thread ms(music_play);//���Ź�����Ч
	ms.detach();
	numk++;
	but[numk].x = x;//�ӵ���λ�ã�Ĭ������������
	but[numk].y = y;
	double ct = atan2(my-y, mx - x);//���Ӧ�Ƕ�
	but[numk].direx = bt_speed * cos(ct);//����x�ķ���
	but[numk].direy = bt_speed * sin(ct);//����y�ķ���
}

void mouse_move()//����ƶ�
{
	setfillcolor(YELLOW);//�����ӵ���ɫ
	for (int i = 1; i <= numk; i++)//ö���ӵ�
	{
		fillcircle(but[i].x += but[i].direx, but[i].y += but[i].direy, but_size);//���϶�Ӧ��ֵ���һ���
		if (but[i].x > WIDE || but[i].x<0 || but[i].y>HIGH || but[i].y < 0)//����뿪�˵�ͼ��ɾ��
		{
			for (int j = i; j <= numk - 1; j++)
			{
				but[j] = but[j + 1];
			}
			numk--;//�ӵ���������
		}

		//�������ж��ӵ�ɱ������
			for (int j = 0; j < num_emy; j++)//�ӵ��Ѿ�ö���ˣ���������ö�ٵ���
			{
				for(int lb= - but_size;lb<=but_size;lb++)//�����ӵ���[-r,r]���������������еĵ�
				{
					double x=but[i].x+lb, y=but[i].y+sqrt(but_size*but_size-lb*lb);//����Բ�ķ��̵ó���Ӧ��x��y������
					if (x >= emy[j].x - shp && x <= emy[j].x + shp && y >= emy[j].y - shp && y <= emy[j].y + shp)//����ӵ��͵��˵�λ���غϾ�ִ��
					{
						if (is_penetrate == 1)//�������͸
						{
							if (but[i].have_hit_num == pene_num)//����Ѿ��ﵽ���͸�������Ƴ��ӵ�
							{
								if (numk == 1)//���ֻ����һ���ӵ�����
								{
									memset(but[i].have_hit, 0, sizeof(but[i].have_hit));//�����Ĵ���ĵ�����������Ϊ0
									but[i].have_hit_num = 0;//���Ѿ���͸�ĵ�������Ϊ0
									numk--;//����-1
								}
								else//�����Ƕ���ӵ������
									for (int k = i; k <= numk - 1; k++)//�Ƴ��ӵ�
									{
										but[k] = but[k + 1];
									}
								numk = max(0, numk - 1);//�ӵ�������һ��������Ϊ0
							}
							if (but[i].have_hit[j] == 0)//����õ���û�����
							{
								emy[j].emy_hp[emy[j].emy_leve] -= pl_damage;//��Ӧ���������ļ���Ϊ�������ֵ�۳�����˺�Ѫ��
								but[i].have_hit[j] = 1;//�õ��˱���Ϊ�Ѿ������
								++but[i].have_hit_num;//�����Ѵ�͸��������
							}
						}
						else//������͸��������ʧ
						{
							for (int k = i; k <= numk - 1; k++)//�Ƴ��ӵ�
							{
								but[k] = but[k + 1];
							}
							numk = max(0, numk - 1);//�ӵ�������һ��������Ϊ0
							emy[j].emy_hp[emy[j].emy_leve] -= pl_damage;//��Ӧ���������ļ���Ϊ�������ֵ�۳�����˺�Ѫ��
						}
						//�������ӵ�ɱ����




						if (emy[j].emy_hp[emy[j].emy_leve] <= 0)//����ɹ���ɱ
						{
							//�����ǽ��������
							rwa[num_rwa].x = emy[j].x;//����λ��Ϊ���˵�����λ��
							rwa[num_rwa].y = emy[j].y;
							num_rwa++;//��������++s

							for (int k = j; k < num_emy - 1; k++)//�Ƴ�����
							{
								emy[k] = emy[k + 1];
							}
							num_emy = max(0, num_emy - 1);//����������һ��������0

						}
						//����Ϊ���˵�����
					}
				}
			}
			//�������ж��ӵ�ɱ������
		
	}

		t2 = GetTickCount();//��ȡ��ǰ
		if (t2 - t1 > fre)//�����ε�ʱ���ȥ�ϴη����ʱ������趨��Ƶ�ʲŷ���
		{

			shoot(rx,ry,msg.x, msg.y);//����
			t1 = t2;//���ϴε�ʱ�伸��
			msg.message = EX_MOUSE;//������һ�κ�msg����
		}
	
}
void mmove()//�������ĵ�
{
	peekmessage(&msg, EX_MOUSE);//�����Ƿ���ͣ��Ҫpeek�����Ϣ����������ˢ��ʱ�䲻ͬ��
	setfillcolor(DARKGRAY);
	fillcircle(msg.x, msg.y, 5);
}