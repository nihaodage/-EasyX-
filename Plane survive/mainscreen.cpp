void m_sc()
{
	putimage(0, 0, &m_bk);

	mciSendString("open ./image/music/m_bgm.mp3  ", 0, 0, 0);//��������������
	mciSendString("play  ./image/music/m_bgm.mp3 repeat ", 0, 0, 0);
	
	
	settextcolor(BLACK);//����������ɫ
	
	settextstyle(100, 0, "����");//�������ֿ�Ⱥ�����
	outtextxy(WIDE / 2 -textwidth("�����Ļ�����")/2, HIGH / 4 -textheight("�����Ļ�����"), "�����Ļ�����");//�������
	
	settextstyle(50, 0, "����");//����������ʽ

	setlinecolor(BLACK);//���þ��α߿���ɫ
	fillrectangle(WIDE / 2 - textwidth("���ո�ʼ��Ϸ") / 2-20, HIGH - HIGH / 4-20, WIDE / 2 - textwidth("���ո�ʼ��Ϸ") / 2+ textwidth("���ո�ʼ��Ϸ")+20, HIGH - HIGH / 4+textheight("���ո�ʼ��Ϸ")+20);//������α߿�

	outtextxy(WIDE / 2 - textwidth("���ո�ʼ��Ϸ") / 2, HIGH - HIGH / 4, "���ո�ʼ��Ϸ");//����������·�����
}