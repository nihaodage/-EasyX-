//��һ�����ܴ�͸����Ҫ����
//int is_penetrate = 1;//�Ƿ�����͸���ܣ�No.1
//int pene_num = 2;//����͸�ĵ�������
//�ڶ������ܣ��ӵ��������Ҫ����but+size
//���������ܣ�����,��Ҫ����fre
//���ĸ����ܣ�������,��Ҫ����,pl_damage
void enable_skill()//����Ҫ�����ļ���
{
	for(int i=1;i<=skill_num;i++)
	{
		if(skill[i]==1)
		{
			switch (i)
			{
			case 1://��һ����͸����
				is_penetrate = 1;
				pene_num = 2;
				break;
			case 2://�ڶ������ܣ������ӵ����
				but_size = 6;
				break;
			case 3://���������ܣ���������
				fre = 600;
				break;
			case 4://���ĸ�����,���ӹ�����
				pl_damage = 20;
				break;
			}
		}
	}
}