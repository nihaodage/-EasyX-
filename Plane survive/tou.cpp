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
#define HURT_ANIM_NUM 3//����ͼƬ���� 
#define PLAYER_NUM 2//���ͼƬ����

#define GetStanWide Splayer_pic[0].getwidth()/2//��ȡ��ҿ�ȵ�һ��
#define GetStanhigh Splayer_pic[0].getheight()/2//��ȡ��Ҹ߶ȵ�һ��

#define WIDE 1280//���ڿ�
#define HIGH 800//���ڸ�
int btx=0;//�ӵ���xλ��
int bty=0;//�ӵ���yλ��


int is_pause = 0;//�Ƿ���ͣ��1Ϊ��ͣ��0Ϊ����
int is_press_ESC = 0;//�Ƿ���ESC
int is_pause_screen = 0;//�Ƿ�������ͣ���� 

//�������Բ���
int fre = 700;//�ӵ�����Ƶ��,ԽС����Խ��
int speed = 5;//�����ƶ��ٶ�
int rx = WIDE / 2, ry = HIGH / 2;//�����ʼλ������Ļ�м�
int leve = 1;//��ҵȼ�
int rw_exp = 0;//����ֵ
int rw_dead = 0;//�����Ƿ�������0Ϊ��1Ϊ��
int hp = 100;//���Ѫ��
int win_fl = 0;//ʤ����־��0����ûӮ��1����Ӯ��
std::atomic<int>invin(0);//����Ƿ����޵�֡ʱ�䣬1Ϊ���ڣ�0Ϊ������
int rq_exp = leve+10;//������Ҫ�ľ���
int leveing = 0;//�Ƿ�������������
int is_move = 0;//�Ƿ��ƶ���
int pl_damage = 10;//����˺�
//

//�����Ǽ�����ر���
int skill[30] = { 0 };//��������Ѿ�ѡ���ļ��ܣ����skill[1]=1������һ�������Ѿ���ѡ
const int skill_num = 4;//����������
int now_skill_num = 0;//��ǰ��������
int remain_skill = skill_num - now_skill_num;//ʣ�༼������

int s[4];//��ȥ���Ԫ�أ�����������������ֱܷ�������������0-skill_num-1��ѡȡ

int is_penetrate = 0;//�Ƿ�����͸���ܣ�No.1
int pene_num = 2;//����͸�ĵ�������
//

double bt_speed = 20;//�ӵ��ٶ�
int t1 = 0, t2;//ʱ��������������ƹ������
struct
{
	double direx;//�ӵ���x�ķ���
	double direy;//�ӵ���y�ķ���
	double x;
	double y;
	int have_hit_num = 0;//�Ѿ���͸�ĵ�������
	int have_hit[10000] = { 0 };//��¼��ǰ�ӵ��Ѿ�����ĵ��ˣ��±������˱�ţ���ֵ��Ϊ1������0��û���������͸����û�������Ӵ�����
}but[1000];//�ӵ��ṹ��
int numk = 0;//�ӵ�������
int but_size = 3;//�ӵ���С(�뾶)



//�����ǵ��˵Ĳ�������
int tm = 10000;//���ɹ����ʱ�䣨���룩
double emy_speed = 1;//�����ƶ��ٶ�
int tm1 = 0, tm2 = 0;//�ж���ȴ��ʱ��
struct
{
	double direx_emy[10000];//������x�ķ���
	double direy_emy[10000];//������y�ķ���
	int emy_leve;//�˵��˵ļ���
	double x, y;
	int emy_hp[10] = { -1,10 };//����Ѫ��,�������Ԫ�أ������±������˵ļ���1Ϊ����ͨ�ĵ���
}emy[10000];

int num_emy = 0;//��������
int shp = 10;//���˴�С

//�����ǵ�����ز���

//�����ǽ����Ĳ���
int  num_rwa = 0;//�����ĸ���
struct
{
	double x, y;
}rwa[10000];//������λ��
int rwa_shp = 5;//�����Ĵ�С
//�����Ĳ���

ExMessage msg;//��ȡ�����Ϣ��

//��ͣ����
IMAGE pu[2];//��ͣ����ͼƬ

IMAGE hurt_anim_p[HURT_ANIM_NUM+1];//�����޵�֡����ͼƬ

IMAGE skill_bk[2];//���ܵװ�ͼƬ

IMAGE Lplayer_pic[PLAYER_NUM+1];//������ƶ�ͼƬ
IMAGE Rplayer_pic[PLAYER_NUM+1];//������ƶ�ͼƬ
IMAGE Splayer_pic[PLAYER_NUM+1];//��Ҳ���ͼƬ

#define LVUP_IMG_NUM 9//��������ͼƬ����
IMAGE img_levup_color[LVUP_IMG_NUM];//����ͼ
IMAGE img_levup_under[LVUP_IMG_NUM];//��������ͼ
int lev_size_width = 62;//��������ͼƬ���
int lev_size_high = 71;//��������ͼƬ�߶�
int is_lv_img = 0;//�Ƿ��Ѿ����Ź�ͼƬ��

const int ENY_NUM = 3;
IMAGE img_slm_color[ENY_NUM];//����ʷ��ķͼ�����
const int eny_width = 40,eny_high=40;//���˴�С��͸�
 
IMAGE g_bk;//��Ϸ�ڱ���ͼ
IMAGE m_bk;//���米��

IMAGE skillimg[skill_num+1];//����ͼƬ����
IMAGE skillimg_bk[skill_num + 1];//����ͼƬ��Ƭ

IMAGE skill_null[2];//���ܿ�λ����

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