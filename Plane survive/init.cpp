//��ʼ������
#include <easyx.h>
void init()
{
	initgraph(WIDE, HIGH);
	setbkcolor(WHITE);
	cleardevice();
	//��ȡ��ͣ�����ͼƬ
	loadimage(&pu[0], "./image/pause.jpg");
	loadimage(&pu[1], "./image/pause_bk.jpg");

	//��ȡ���˶���
	for (int i = 0; i < HURT_ANIM_NUM ; i++)//���һ��ͼƬ�ǵ�Ƭ
	{
		char path[100];//�����ַ����
		sprintf_s(path, "%s%d%s", "image/chara/pc_hurt_", i+1, ".jpg");//��ϵ�ַ
		//���Ǻ�����ͼӦ�ϴ�pc�Ĵ�С
		loadimage(&hurt_anim_p[i], path);//����ͼƬ
	}

	//��ȡ���ܵװ�ͼƬ
	loadimage(&skill_bk[0], "image/skill_bk.jpg");
	loadimage(&skill_bk[1], "image/skill_bk2.jpg");
	
	//��ȡ���ͼƬ
	for (int i = 0; i < PLAYER_NUM; i++)//���һ��ͼƬ�ǵ�Ƭ
	{
		char path[100];//�����ַ����
		sprintf_s(path, "%s%d%s", "image/chara/pc_left_", i+1 , ".jpg");//��ϵ�ַ
		//���Ǻ�����ͼӦ�ϴ�pc�Ĵ�С
		loadimage(&Lplayer_pic[i], path);//�������ƶ�ͼƬ

		sprintf_s(path, "%s%d%s", "image/chara/pc_right_", i+1 , ".jpg");
		loadimage(&Rplayer_pic[i], path);//�������ƶ�ͼƬ

		sprintf_s(path, "%s%d%s", "image/chara/pc_stand_", i+1 , ".jpg");
		loadimage(&Splayer_pic[i], path);//���ز���ͼƬ
	}
	for (int i = 0; i <  LVUP_IMG_NUM; i++)//��ȡ���ܶ���ͼƬ
	{
		char levup_anim_color[50], levup_anim_under[50];//��ʱ����
		sprintf_s(levup_anim_under, "%s%d%s", "image/leveling/water4000", i + 1, "_under.jpg");
		loadimage(&img_levup_under[i], levup_anim_under, lev_size_width, lev_size_high);
		sprintf_s(levup_anim_color, "%s%d%s", "image/leveling/water4000", i + 1, ".jpg");
		loadimage(&img_levup_color[i], levup_anim_color, lev_size_width, lev_size_high);
	}


	for (int i = 0; i < ENY_NUM; i++)//�������ͼƬ
	{
		char slm_move_anim[50];
		sprintf_s(slm_move_anim, "%s%d%s", "image/enemy/slime_", i + 1, ".jpg");
		loadimage(&img_slm_color[i], slm_move_anim, eny_width, eny_high);
	}

	loadimage(&g_bk, "image/bk.png");//������Ϸ����ͼ
	loadimage(&m_bk, "image/g_bk.png");//���������汳��ͼ

	mciSendString("open ./image/music/attack_2.mp3", 0, 0, 0);//������������

	for (int i = 1; i <= skill_num; i++)//��ȡ�����м���ͼƬ
	{
		char sk_img[50];
		sprintf_s(sk_img, "%s%d%s", "image/skill/skill_bk_", i, ".jpg");
		loadimage(&skillimg[i], sk_img);
		sprintf_s(sk_img, "%s%d%s", "image/skill/skill_bk2_", i, ".jpg");
		loadimage(&skillimg_bk[i], sk_img);
	}

	//�����������ܿհ�ռλ��
	loadimage(&skill_null[0], "image/skill/skill_null_1.jpg");
	loadimage(&skill_null[1], "image/skill/skill_null_2.jpg");

} 