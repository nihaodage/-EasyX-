//初始化窗口
#include <easyx.h>
void init()
{
	initgraph(WIDE, HIGH);
	setbkcolor(WHITE);
	cleardevice();
	//读取暂停界面的图片
	loadimage(&pu[0], "./image/pause.jpg");
	loadimage(&pu[1], "./image/pause_bk.jpg");

	//读取受伤动画
	for (int i = 0; i < HURT_ANIM_NUM ; i++)//最后一个图片是底片
	{
		char path[100];//定义地址变量
		sprintf_s(path, "%s%d%s", "image/chara/pc_hurt_", i+1, ".jpg");//组合地址
		//若是后期贴图应上传pc的大小
		loadimage(&hurt_anim_p[i], path);//加载图片
	}

	//读取技能底版图片
	loadimage(&skill_bk[0], "image/skill_bk.jpg");
	loadimage(&skill_bk[1], "image/skill_bk2.jpg");
	
	//读取玩家图片
	for (int i = 0; i < PLAYER_NUM; i++)//最后一个图片是底片
	{
		char path[100];//定义地址变量
		sprintf_s(path, "%s%d%s", "image/chara/pc_left_", i+1 , ".jpg");//组合地址
		//若是后期贴图应上传pc的大小
		loadimage(&Lplayer_pic[i], path);//加载左移动图片

		sprintf_s(path, "%s%d%s", "image/chara/pc_right_", i+1 , ".jpg");
		loadimage(&Rplayer_pic[i], path);//加载右移动图片

		sprintf_s(path, "%s%d%s", "image/chara/pc_stand_", i+1 , ".jpg");
		loadimage(&Splayer_pic[i], path);//加载不动图片
	}
	for (int i = 0; i <  LVUP_IMG_NUM; i++)//读取技能动画图片
	{
		char levup_anim_color[50], levup_anim_under[50];//临时变量
		sprintf_s(levup_anim_under, "%s%d%s", "image/leveling/water4000", i + 1, "_under.jpg");
		loadimage(&img_levup_under[i], levup_anim_under, lev_size_width, lev_size_high);
		sprintf_s(levup_anim_color, "%s%d%s", "image/leveling/water4000", i + 1, ".jpg");
		loadimage(&img_levup_color[i], levup_anim_color, lev_size_width, lev_size_high);
	}


	for (int i = 0; i < ENY_NUM; i++)//读入怪物图片
	{
		char slm_move_anim[50];
		sprintf_s(slm_move_anim, "%s%d%s", "image/enemy/slime_", i + 1, ".jpg");
		loadimage(&img_slm_color[i], slm_move_anim, eny_width, eny_high);
	}

	loadimage(&g_bk, "image/bk.png");//加载游戏背景图
	loadimage(&m_bk, "image/g_bk.png");//加载主界面背景图

	mciSendString("open ./image/music/attack_2.mp3", 0, 0, 0);//攻击调用音乐

	for (int i = 1; i <= skill_num; i++)//读取所所有技能图片
	{
		char sk_img[50];
		sprintf_s(sk_img, "%s%d%s", "image/skill/skill_bk_", i, ".jpg");
		loadimage(&skillimg[i], sk_img);
		sprintf_s(sk_img, "%s%d%s", "image/skill/skill_bk2_", i, ".jpg");
		loadimage(&skillimg_bk[i], sk_img);
	}

	//读入两个技能空白占位符
	loadimage(&skill_null[0], "image/skill/skill_null_1.jpg");
	loadimage(&skill_null[1], "image/skill/skill_null_2.jpg");

} 