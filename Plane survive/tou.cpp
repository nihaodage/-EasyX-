#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include<easyx.h>
#include <algorithm>
#include <windows.h>
#include<stdlib.h>
#include<thread>
#include <ctime>
#include<graphics.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
#define HURT_ANIM_NUM 3//受伤图片数量 
#define PLAYER_NUM 2//玩家图片数量

#define GetStanWide Splayer_pic[0].getwidth()/2//获取玩家宽度的一半
#define GetStanhigh Splayer_pic[0].getheight()/2//获取玩家高度的一半

#define WIDE 1280//窗口宽
#define HIGH 800//窗口高
int btx=0;//子弹的x位置
int bty=0;//子弹的y位置


int is_pause = 0;//是否暂停，1为暂停，0为不是
int is_press_ESC = 0;//是否按下ESC
int is_pause_screen = 0;//是否生成暂停界面 

//人物属性参数
int fre = 700;//子弹发射频率,越小发射越快
int speed = 5;//人物移动速度
int rx = WIDE / 2, ry = HIGH / 2;//人物初始位置在屏幕中间
int leve = 1;//玩家等级
int rw_exp = 0;//经验值
int rw_dead = 0;//人物是否死亡，0为否，1为是
int hp = 100;//玩家血量
int win_fl = 0;//胜利标志，0代表没赢，1代表赢了
std::atomic<int>invin(0);//玩家是否处于无敌帧时间，1为处于，0为不处于
int rq_exp = leve+10;//升级需要的经验
int leveing = 0;//是否处于升级过程中
int is_move = 0;//是否移动了
int pl_damage = 10;//玩家伤害
//

//以下是技能相关变量
int skill[30] = { 0 };//用来存放已经选过的技能，如果skill[1]=1则代表第一个技能已经被选
const int skill_num = 4;//技能总数量
int now_skill_num = 0;//当前技能数量
int remain_skill = skill_num - now_skill_num;//剩余技能数量

int s[4];//舍去零号元素，升级界面的三个技能分别是哪三个，从0-skill_num-1中选取

int is_penetrate = 0;//是否开启穿透技能，No.1
int pene_num = 2;//允许穿透的敌人数量
//

double bt_speed = 20;//子弹速度
int t1 = 0, t2;//时间变量，用来控制攻击间隔
struct
{
	double direx;//子弹在x的分量
	double direy;//子弹在y的分量
	double x;
	double y;
	int have_hit_num = 0;//已经穿透的敌人数量
	int have_hit[10000] = { 0 };//记录当前子弹已经打过的敌人，下标代表敌人编号，其值若为1则打过，0是没打过，若穿透技能没开则无视此数组
}but[1000];//子弹结构体
int numk = 0;//子弹的数量
int but_size = 3;//子弹大小(半径)



//以下是敌人的参数变量
int tm = 10000;//生成怪物的时间（毫秒）
double emy_speed = 1;//敌人移动速度
int tm1 = 0, tm2 = 0;//判断冷却的时间
struct
{
	double direx_emy[10000];//敌人在x的分量
	double direy_emy[10000];//敌人在y的分量
	int emy_leve;//此敌人的级别
	double x, y;
	int emy_hp[10] = { -1,10 };//敌人血量,抛弃零号元素，数组下标代表敌人的级别，1为最普通的敌人
}emy[10000];

int num_emy = 0;//敌人数量
int shp = 10;//敌人大小

//以上是敌人相关参数

//以下是奖励的参数
int  num_rwa = 0;//奖励的个数
struct
{
	double x, y;
}rwa[10000];//奖励的位置
int rwa_shp = 5;//奖励的大小
//奖励的参数

ExMessage msg;//获取鼠标信息用

//暂停界面
IMAGE pu[2];//暂停界面图片

IMAGE hurt_anim_p[HURT_ANIM_NUM+1];//受伤无敌帧动画图片

IMAGE skill_bk[2];//技能底版图片

IMAGE Lplayer_pic[PLAYER_NUM+1];//玩家左移动图片
IMAGE Rplayer_pic[PLAYER_NUM+1];//玩家右移动图片
IMAGE Splayer_pic[PLAYER_NUM+1];//玩家不动图片

#define LVUP_IMG_NUM 9//技能升级图片数量
IMAGE img_levup_color[LVUP_IMG_NUM];//升级图
IMAGE img_levup_under[LVUP_IMG_NUM];//升级背景图
int lev_size_width = 62;//升级动画图片宽度
int lev_size_high = 71;//升级动画图片高度
int is_lv_img = 0;//是否已经播放过图片了

const int ENY_NUM = 3;
IMAGE img_slm_color[ENY_NUM];//定义史莱姆图像变量
const int eny_width = 40,eny_high=40;//敌人大小宽和高
 
IMAGE g_bk;//游戏内背景图
IMAGE m_bk;//主界背景

IMAGE skillimg[skill_num+1];//技能图片变量
IMAGE skillimg_bk[skill_num + 1];//技能图片底片

IMAGE skill_null[2];//技能空位填充符

#include"up_screen.cpp"
#include "player_spark.cpp"  
#include "move.cpp"
#include "init.cpp"
#include "mouse.cpp"
#include "enemy.cpp"
#include "reward.cpp"
#include "dead.cpp"
#include "text.cpp"
#include "win.cpp"
#include "screen_end.cpp"
#include "Blood_screen.cpp"
#include"pause.cpp"
#include "pause_screen.cpp"
#include "skill_list.cpp"
#include "choose_skill.cpp"
#include "leveling.cpp"
#include "mainscreen.cpp"