bool BloodBar(int TotalBlood, int* NowBlood, int x, int y, int hight, int ellipsewidh, int ellipseheight, int BloodBarLenth)
{
	int* nowblood = NowBlood;
	//printf("��ǰѪ��:%d\n", *nowblood);
	//����Ѫ������Ѫ����ֵ
	float BloodRate = *nowblood  * 1.0 / TotalBlood;
	//printf("Ѫ����ֵ��%.2f\n", BloodRate);
	//ʵ��Ѫ������
	int EndBloodBarLenth = BloodBarLenth * BloodRate;
	//�߿���ɫ�������ɫ
	setcolor(BLACK);
	setfillcolor(WHITE);
	//����Ѫ��
	fillroundrect(
		x, y, x + BloodBarLenth, y + hight, ellipsewidh, ellipseheight
	);
	//����Ѫ��
	//Ѫ��������>60%)
	if (BloodRate >= 0.6)
	{
		setfillcolor(GREEN);
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + hight, ellipsewidh, ellipseheight
		);
		//����Ѫ���ۼ�
		*nowblood = *nowblood;
	}
	//Ѫ��Σ�գ�>30%��
	else if (BloodRate >= 0.3)
	{
		setfillcolor(RGB(255, 165, 0));
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + hight, ellipsewidh, ellipseheight
		);
		//����Ѫ���ۼ�
		*nowblood = *nowblood;
	}
	//Ѫ��������>0%��
	else if (BloodRate >= 0)
	{
		setfillcolor(RED);
		fillroundrect(
			x, y, x + EndBloodBarLenth, y + hight, ellipsewidh, ellipseheight
		);
		//����Ѫ���ۼ�
		*nowblood = *nowblood;
	}
	//�����򷵻�false��ֹѭ��
	else {
		return false;
	}
	//δ������ѭ��
	return true;

}