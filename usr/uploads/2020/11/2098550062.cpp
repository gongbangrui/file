#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<time.h>
#include<string.h>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
int ghgh=true;
int sby=0,liuman=0;
int b;
int hh,cccsss=0;
bool suran;
FILE *fin;
char nammm[21],nammmm[21];
char Roman[101][10]= {"O","I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI",\
                      "XVII","XVIII","XIX","XX","XXI","XXII","XXIII","XXIV","XXV","XXVI","XXVII","XXVIII","XXIX","XXX","XXXI","XXXII",\
                      "XXXIII","XXXIV","XXXV","XXXVI","XXXVII","XXXVIII","XXXIX","XL","XLI","XLII","XLIII","XLIV","XLV","XLVI","XLVII"\
                      ,"XLVIII","XLIX","L","LI","LII","LIII","LIV","LV","LVI","LVII","LVIII","LIX","LX","LXI","LXII","LXIII","LXIV",\
                      "LXV","LXVI","LXVII","LXVIII","LXIX","LXX","LXXI","LXXII","LXXIII","LXXIV","LXXV","LXXVI","LXXVII","LXXVIII",\
                      "LXXIX","LXXX","LXXXI","LXXXII","LXXXIII","LXXXIV","LXXXV","LXXXVI","LXXXVII","LXXXVIII","LXXXIX","XC","XCI",\
                      "XCII","XCIII","XCIV","XCV","XCVI","XCVII","XCVIII","XCIX","C"
                     };
struct DGO {
	char name[21];
	char chu[51];
	char PNm[51];
	char Lvup[21];
	char XM[101];
	int Lup;
	int PN;
	int attack;
	int level;
	int baoji;
	int Hav;
	int attack_;
	int Baif;
	int Baif_;
}
xuan[38]= {{"��","��","\b\b\b\b\b\b\b                     ","","",0,0,0,0,0,0,0,0,0},
	{"����","�ס�����","���","����֮��","���ݶԵ��˽���ײ��������˺�",0,-1,50,0,17,0,50,20,0},
	{"��","�ס���","�ɱ�","��֮β","�غϴ���Խ�࣬���������ҵĹ�����Խ��",0,-2,50,0,17,0,51,0,0},
	{"�Ƶ�","�ס��Ƶ�","����","�Ƶ�֮��","ս����ʼʱ��ʹ�Է������½�",0,-3,50,0,17,0,52,0,0},
	{"�۽�","�ס��۽�","����","�۽�֮�","�ͷ��������нϴ���ʹ��������",0,-4,50,0,17,0,51,10,2},
	{"�ٸ�","�ס��ٸ�","Ͷ��","�ٸ�֮ë","Ͷ��ʯ�ӣ�������ͬʱʹ�����������½�",0,-5,50,0,17,0,53,10,2},
	{"����","�ס�����","����","����֮צ","ս����ʼʱ��ʹ���������ʽ���",0,-6,50,0,17,0,54,0,0},
	{"��β��","�ס���β��","����","��β֮Ƥ","ʹ��һָ�����HP",0,-7,50,0,17,0,55,10,2},
	{"����","�ס�����","�","����֮��","���Է�Ϊˮ���ԣ���������Է��Ĺ���",0,-8,50,0,17,0,53,10,2},
	{"����","�ס�����","����","����֮��","ս����ʼʱ��ʹ��һ������˺�����",0,-9,50,0,17,0,52,0,0},
	{"����","�ס�����","����","����֮��","�м���ʹ���˱��ι�����Ч",0,-10,50,0,17,0,49,10,2},
	{"����","�ס�����","����","����֮��","ս����ʼʱ������Ҹ�������С��������",0,-11,50,0,17,0,52,0,0},
	{"�ײ�","�ס��ײ�","����","�ײ�֮��","���HPԽ����ҹ�����Խ��",0,-12,50,0,17,0,51,0,0},
	{"����","�ס�����","����","����֮��","���HPԽ����ҷ�����Խ��",0,-13,50,0,17,0,51,0,0},
	{"����","�ס�����","����","����֮��","���ÿ�ι���,�Ե�������˺���ͬʱ�������������������",0,-14,50,0,17,0,50,0,0},
	{"�׻�","�ס��׻�","��Ծ","�׻�֮צ","��������ɽϸ��˺�",0,-15,50,0,17,0,54,20,10},
	{"��ȸ","�ס���ȸ","����","��ȸ֮��","�����ս��ʱ,�м���ʹ��Ҹ���",0,-16,50,0,17,0,48,10,1},
	{"����","�ס�����","��ڤ","����֮��","ս����ʼʱ����ҷ���������",0,-17,50,0,17,0,47,0,0},
	{"��ţ","�ס���ţ","����","��ţ֮ӡ","���֣���ʹ����˯��",0,1,50,0,17,0,49,10,2},
	{"����","�ס�����","����","����֮ӡ","ʹ���˹���������½�",0,2,50,0,17,0,46,10,2},
	{"����","�ס�����","��ս","����֮ӡ","ʹ���˷���������½�",0,3,50,0,17,0,47,10,2},
	{"����","�ס�����","����","����֮ӡ","ʹ���˹�������С���½�",0,4,50,0,17,0,49,10,2},
	{"��","�ס���","����","��֮ӡ","ʹ��һָ���������ֵ",0,5,50,0,17,0,50,10,2},
	{"����","�ס�����","����","����֮ӡ","ʹ��ұ���������",0,6,50,0,17,0,51,10,2},
	{"����","�ס�����","��Ȼ","����֮ӡ","���غϵ��˶����������˺������ʹ�����ܵ������˺�",0,7,50,0,17,0,52,15,1},
	{"����","�ס�����","˹��","����֮ӡ","�侲������ʹ������������",0,8,50,0,17,0,51,10,2},
	{"���","�ס����","����","���֮ӡ","ʹ�������˺��½�",0,9,50,0,17,0,53,10,2},
	{"����","�ס�����","����","����֮ӡ","��Χɱ��,�ض�����,ͬʱС�����������������",0,10,75,0,17,0,56,5,2},
	{"����","�ס�����","ˮ��","����֮��","ʹ�����ܵ��ϸ��˺�",0,11,50,0,17,0,53,10,1},
	{"����","�ס�����","����","����֮צ","�ͷ��������н�С����ʹ�������ˣ���Ի����",0,12,50,0,17,0,52,20,1},
	{"�ṫ��","�ס��ṫ��","а��","�ṫ֮��","����ڱ��غ��ܵ����˺���Ч��",0,13,50,0,17,0,49,10,1},
	{"��","�ס���","ʤ��","��֮��","ս����ʼʱ�����˷������������½�",0,14,50,0,17,0,50,0,0},
	{"Ӧ��","�ס�Ӧ��","����","Ӧ��֮��","ս����ʼʱ��ʹ�����������½�",0,15,50,0,17,0,51,0,0},
	{"���","�ס����","�в�","���֮ü","ս���ý����,����������",0,16,50,0,17,0,50,0,0},
	{"����","�ס�����","����","����֮��","�м����ͷ�����һ�����ӣ���ţ~��ǣ��ļ���",0,17,50,0,17,0,53,10,2},
	{"���","�ס����","����","���֮��","�ظ���Ҳ���PP",0,18,50,0,17,0,49,10,2},
	{"���","�ס����","�̾�","���֮β","�غ���Խ�࣬��ҷ�����Խǿ",0,19,50,0,17,0,51,0,0},
	{"��","��","��","��","",0,0,0,0,0,0,0,0,0}
};
struct Player {				   //��ҽṹ�壬����ʼ��player
	char name[21];
	int attack;
	int defense;
	int health;
	int max_health;
	int level;
	int exp;
	int max_exp;
	int PP;
	int max_PP;
	int miss;
	int baoji;
	int att_;
	int defen_;
	int PP_;
	int HP_;
	int att__;
	int defen__;
	int PP__;
	int HP__;
} player= {"����",190,180,100,100,1,0,100,40,40,17,15,20,10,10,175,20,20,20,50},
  battle_player= {"����",0,0,0,0,0,0,0,0,0,0,0};
struct Enemy {					//�ֵĽṹ��,����ʼ�����ֹ�
	char name[30];
	char wupin[30];
	int color;
	int attack;
	int defense;
	int health;
	int money;
	int exp;
	int wupin_sign;
	int wupinpro;
	int miss;
	int baoji;
	int boss_;
	int kind_;
	int Frr;
	int ill;
	int lft;
	char Gjn[51];
	int Gjnnum;
} strongman= {"ɭ�־���","���ʥ��",10,240,190,7500,700,300,1,2,12,15,0,0,100,90,70,"����",1},
  witch= {"ɭ��Ů��","����",10,125,90,320,50,70,2,4,15,14,0,1,70,30,35,"����",2},
  xiyi= {"ɭ�����","�ۼ�",6,90,50,180,20,35,3,6,12,13,0,1,70,50,40,"��Ծ",3},
  big_strongman= {"ɭ�־�����","����֮ľ",10,140*6,150*6,21350,400*3,100*9,4,4,0,20,1,0,200,120,20,"���",4},
  big_strongmanking= {"ɭ�־�����֮��","",10,140*10,150*10,41350,400*5,100*13,1,-1,0,25,1,0,220,80,40,"����",5},
  shark= {"�����","���",9,1150,900,8500,600,340,5,2,10,10,0,0,330,210,340,"����",6},
  jing= {"��޾�","ħ��",9,870,500,6320,450,250,6,4,12,9,0,0,210,310,480,"����",7},
  lie= {"�����","�˻�",14,520,390,3180,250,195,7,6,21,8,0,0,460,130,220,"����",8},
  fishman= {"�������","����֮��",9,140*8,150*8,27350,500*4,100*11,8,4,10,9,1,1,135,210,320,"ͻ��",9},
  fishmanking= {"�������֮��","",9,140*15,150*10,47350,400*10,100*16,1,-1,10,14,1,1,130,180,405,"ˮǹ",10},
  shouhu= {"ɳĮ�ػ�","���",12,1560,1390,15800,700,450,9,2,10,12,0,1,102,220,150,"����",11},
  duxie= {"ɳĮ��Ы","����",6,1350,1270,7790,550,420,10,4,10,14,0,0,105,130,141,"����",12},
  jumang= {"ɳĮ����","����",14,1200,1160,5960,330,380,11,6,20,15,0,0,187,147,70,"��Ƥ",13},
  falao= {"ɳĮ������","����֮��",12,350*8,170*8,32350,800*4,100*14,12,4,10,14,1,1,159,348,185,"�Ļ�",14},
  falaoking= {"ɳĮ������֮��","",12,250*20,170*10,52350,800*6,100*20,1,-1,10,20,1,1,136,403,174,"��ԭ",15},
  lion= {"��ԭ��ʨ","��������",14,2210,1650,12800,900,400,13,2,10,16,0,0,140,256,237,"˺��",16},
  horse= {"��ԭҰ��","��Ѫ��",6,1978,1320,5790,550,360,14,4,10,15,0,0,273,195,164,"����",17},
  bee= {"��ԭ�޷�","����",14,1737,1115,4960,330,350,15,6,16,13,0,0,216,139,267,"��ҧ",18},
  shitu1= {"��֮ʹͽ","",12,4000,1500,30000,7000,2900,21,-1,20,12,1,1,0,218,135,"ˮ��",19},
  shitu2= {"ˮ֮ʹͽ","",9,4600,1700,30000,7000,2900,31,-1,20,12,1,1,30,224,178,"����",20},
  shitu3= {"��֮ʹͽ","",10,5000,1500,40000,7000,2900,41,-1,20,12,1,1,394,157,0,"����",21},
  king= {"�ڰ����","",8,6600,1900,60000,9000,3300,41,-1,20,23,1,1,215,0,354,"ʧ��",22},
  lingzhu1= {"ˮ֮����","ˮ֮��",9,6600,4900,90000,10200,5300,91,11,20,12,1,1,30,226,372,"����",23},
  lingzhu2= {"��֮����","��֮��",12,7000,4700,90000,10200,5300,92,11,20,12,1,1,0,318,256,"�ҷ�",24},
  lingzhu3= {"��֮����","��֮��",6,6600,5200,160000,10200,5300,93,11,20,12,1,1,135,253,459,"����",25},
  lingzhu4= {"��֮����","��֮��",8,7600,5700,8000,10200,4800,94,11,20,12,1,1,374,274,245,"���",26},
  guai= {"\0","\0",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"",0},
xian[37]= {{"\0","\0",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"",0},
	{"�桤����","����",14,140*10,150*10,41350,0,0,-37,0,11,20,2,0,295,175,154,"���",-1},
	{"�桤��","��",9,140*10,150*10,41350,0,0,-38,0,11,20,2,0,295,175,154,"�ɱ�",-2},
	{"�桤�Ƶ�","�Ƶ�",14,140*10,150*10,41350,0,0,-39,0,11,20,2,0,195,175,254,"����",-3},
	{"�桤�۽�","�۽�",12,140*10,150*10,41350,0,0,-40,0,11,20,2,1,195,275,154,"����",-4},
	{"�桤�ٸ�","�ٸ�",10,140*10,150*10,41350,0,0,-41,0,11,20,2,0,295,175,20,"Ͷ��",-5},
	{"�桤����","����",6,140*10,150*10,41350,0,0,-42,0,11,20,2,0,295,175,154,"����",-6},
	{"�桤��β��","��β��",8,140*10,150*10,41350,0,0,-43,0,11,20,2,1,195,275,154,"����",-7},
	{"�桤����","����",9,140*10,150*10,41350,0,0,-44,0,11,20,2,0,195,275,154,"�",-8},
	{"�桤����","����",12,140*10,150*10,41350,0,0,-45,0,11,20,2,1,195,275,154,"����",-9},
	{"�桤����","����",14,140*10,150*10,41350,0,0,-46,0,11,20,2,1,195,175,154,"����",-10},
	{"�桤����","����",6,140*10,150*10,41350,0,0,-47,0,11,20,2,1,195,175,154,"����",-11},
	{"�桤�ײ�","�ײ�",8,140*10,150*10,41350,0,0,-48,0,11,20,2,1,195,145,154,"����",-12},
	{"�桤����","����",8,140*10,150*10,41350,0,0,-49,0,11,20,2,1,195,145,154,"����",-13},
	{"�桤����","����",10,140*10,150*10,41350,0,0,-50,0,11,20,2,0,195,175,20,"����",-14},
	{"�桤�׻�","�׻�",14,140*10,150*10,41350,0,0,-51,0,11,20,2,0,195,175,154,"��Ծ",-15},
	{"�桤��ȸ","��ȸ",12,140*10,150*10,41350,0,0,-52,0,11,20,2,1,45,175,154,"����",-16},
	{"�桤����","����",9,140*10,150*10,41350,0,0,-53,0,11,20,2,1,155,275,154,"��ڤ",-17},
	{"�桤��ţ","��ţ",8,140*10,150*10,41350,0,0,-35,0,11,20,2,1,195,275,154,"����",-18},
	{"�桤����","����",8,140*10,150*10,41350,0,0,-34,0,11,20,2,0,195,275,154,"����",-19},
	{"�桤����","����",8,140*10,150*10,41350,0,0,-33,0,11,20,2,0,195,275,154,"��ս",-20},
	{"�桤����","����",8,140*10,150*10,41350,0,0,-32,0,11,20,2,0,195,275,154,"����",-21},
	{"�桤��","��",8,140*10,150*10,41350,0,0,-31,0,11,20,2,1,195,275,154,"����",-22},
	{"�桤����","����",8,140*10,150*10,41350,0,0,-30,0,11,20,2,0,195,275,154,"����",-23},
	{"�桤����","����",8,140*10,150*10,41350,0,0,-29,0,11,20,2,0,195,275,154,"��Ȼ",-24},
	{"�桤����","����",8,140*10,150*10,41350,0,0,-28,0,11,20,2,0,195,275,154,"˹��",-25},
	{"�桤���","���",8,140*10,150*10,41350,0,0,-27,0,11,20,2,1,100,275,154,"����",-26},
	{"�桤����","����",8,3200,1600,27483,0,0,-26,0,11,20,2,1,100,275,154,"����",-27},
	{"�桤����","����",9,140*10,150*10,41350,0,0,-25,0,11,20,2,1,155,275,154,"ˮ��",-28},
	{"�桤����","����",12,140*10,150*10,41350,0,0,-24,0,11,20,2,1,45,175,154,"����",-29},
	{"�桤�ṫ��","�ṫ��",14,140*10,150*10,41350,0,0,-23,0,11,20,2,1,295,45,154,"а��",-30},
	{"�桤��","��",6,140*10,150*10,41350,0,0,-22,0,11,20,2,1,175,175,154,"ʤ��",-31},
	{"�桤Ӧ��","Ӧ��",9,140*10,150*10,41350,0,0,-21,0,11,20,2,1,175,175,154,"����",-32},
	{"�桤���","���",6,140*10,150*10,41350,0,0,-20,0,11,20,2,0,175,175,154,"�в�",-33},
	{"�桤����","����",9,140*10,150*10,41350,0,0,-19,0,11,20,2,1,175,225,224,"����",-34},
	{"�桤���","���",14,140*10,150*10,41350,0,0,-18,0,11,20,2,1,175,275,154,"����",-35},
	{"�桤���","���",9,140*10,150*10,41350,0,0,-17,0,11,20,2,1,175,175,154,"�̾�",-36}
};
struct jn__ {					//�ֵĽṹ��,����ʼ�����ֹ�
	char name[111];
	char xxx[1000];
	bool hadd;
	bool haddd;
	int num;
	int pp;
	int attack_jc;//�����ӳ�
	int fang_jc;//�����ӳ�
	int baoji_jc;//�б�����
	int miss_jc;//�����ܽ�
	int jc_miss;//��������
	int jc_baoji;//��������
	int zhongdu;//�ж�
	int mihuo;//�Ի�
	int shaoshang;//����
	int mabi;//���
	int hunluan;//����
	int dongjie;//����
	int cuimian;//����
	int jisheng;//����
	int jupao;//����
	int xixe;//��Ѫ
	int huimie;//����
	int fajian;//ħ���˼���
	int wujian;//�����˼���
	int fantan;//����
	int PP_back;//����
	int HP_back;//��Ѫ
} jn_= {"��","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_0= {"��ͨ����","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_1= {"��","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_2= {"��","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_3= {"��","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_4= {"��","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_jszz= {"��������","Ͷ��������������",0,0,1,25,50,0,0,0,0,100,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
  jn_mtdz= {"���춾��","ʹ�Է��ж�",0,0,2,25,50,0,0,0,0,100,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_mhsx= {"�Ի�����","ʹ�Է��Ի�",0,0,3,25,50,0,0,0,0,100,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_xhly= {"�ǻ���ԭ","ʹ�Է�����",0,0,4,25,50,0,0,0,0,100,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_nljt= {"ŭ�׾���","ʹ�Է����",0,0,5,25,50,0,0,0,0,100,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_phsg= {"�ƻ�����","ʹ�Է�����",0,0,6,25,50,0,0,0,0,100,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
  jn_hdjt= {"��������","ʹ�Է�����",0,0,7,25,50,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
  jn_kghw= {"�ݹǺ���","ʹ�Է�����",0,0,8,25,50,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
  jn_jpzs= {"����֮��","�޷����ܣ��ض�����",0,0,9,50,100,0,0,0,0,100,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
  jn_getb= {"��Ѫ����","��ȡ����һ��HP",0,0,10,40,90,0,0,0,0,100,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
  jn_htmd= {"�������","�㾡ȫ������ɼ�����˺�����һ��������ɱ����BOSS��Ч��",0,0,11,800,5000,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
  jn_lpjq= {"���̾���","�ܹ��ظ�����PP",0,0,12,0,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,400,0},
  jn_lztx= {"��֮��Ϣ","�ܹ��ظ�����PP",0,0,13,0,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,800,0},
  jn_zszs= {"����֮��","�ܹ��ظ�����HP",0,0,14,40,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,500},
  jn_hgfz= {"�عⷵ��","�ܹ��ظ�����HP",0,0,15,60,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
  jn_xjzq= {"Ѫ��֮��","�ܹ�����PP,����Ҫһ����HP��Ϊ����"	,0,0,16,0,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,999999,-200},
  jn_gzpz= {"��֮����","3�غ��ڣ�����һ��ħ���˺�"	,0,0,17,50,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
  jn_tqtb= {"ͭǽ����","3�غ��ڣ�����һ�������˺�"	,0,0,18,50,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
  jn_jjcj= {"�������","ɱ�������ߣ�������Ҳ���ܵ�һ�����˺�",0,0,19,100,600,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-100},
  jn_jmfs= {"���淴��","�ܽ��Է����غ϶�����˺������ص�������",0,0,20,75,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
  jn_scfs= {"˫�ط���","�ܽ��Է����غ϶�����˺�˫�������ص�������",0,0,21,100,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0},
  jn_xhys= {"�黯����","2�غ��ڵ��������ʽ���90%��������Ҳ����˼������",0,0,22,140,0,0,1,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
struct Place {
	int bar,hotel,bank,forest1,forest2,forest3,sea1,sea2,sea3,sha1,sha2,sha3,grass1,grass2,grass3,jitan1,jitan2,jitan3,jitan4;
} place= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
int max_exp=0,kingdie=0,xiangcun=0,mony=0,js=0;
int choose_number=0,s=0,strongman_arm=0,fishman_tail=0,falao_fire=0,battle=0,money=500,place_sign=1,huoling=0,shuiling=0,tuling=0,fengling=0;
int cao=3,jijiubao=2,baiyao=2,superbaiyao=1,boom=3,dubiao=2,atom_boom=1,hlbyr=0,dan=3,xiancao=2,xlsoup=2,superxlsoup=1;
int fang=0,fang1=100,fang1n=0,fang2=500,fang2n=0,fang3=1000,fang3n=0,fang4=2500,fang4n=0,fang5=5000,fang5n=0;
int gong=0,gong1=100,gong1n=0,gong2=500,gong2n=0,gong3=1000,gong3n=0,gong4=2500,gong4n=0,gong5=5000,gong5n=0;
int hun=0,hun1=210,hun1n=0,hun2=505,hun2n=0,hun3=1550,hun3n=0,hun4=3000,hun4n=0;
int yan=0,yann=0,yan1=200,yan1n=0,yan2=500,yan2n=0,yan3=1200,yan3n=0,yan4=2000,yan4n=0;
int BrBow,BrMis,Kill,Wory,Fire,Elec,Sick,Ice,Slp,Squid,Gun,Blood,Death,MgcHalf,PhyHalf,Bkll;
int HUOL=1,SHUIL=1,FENGL=1,TUL=1,TTDIE=1,FMDIE=1,FODIE=1,xuanz=1,liux=1,das=1,DJz=1;
float maybe=0;
int DIII=0,Hpet=0;
string st;
char player_name[21];
char gongname[101],fangname[101],hunname[101],yanname[101];
char proof;
void AddWupin(int);
int AttackResult();
void BattleAct();
void ChooseWupin();
void jn_gai();
void DisplayState();
void OrdinaryAct();
int SuiJi();
void changejn();
int SuiJi100();
void WhetherLevelUp();
void SlowDisplay(const char *);
void choose_jn();
void fsave();
void fsavein();
void xuanzong();
void liuxing();
void dashi();
void PetsTeach();
void setjindutiao(int);
int opw(string);
void little_game();
void stay__gj(long long,long long);
void color(int a) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void first() {
	if(battle==0)
		fsave();
}
int massbox(const char *p,string fs,int WHICH) {
	char hgkufd[1001];
	int i=0;
	while(1) {
		if(*p!=0)
			hgkufd[i++]=*p++;
		else
			break;
	}
	switch(WHICH) {
		case 1:
			return MessageBox(NULL,fs.c_str(),hgkufd,MB_OK|MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_ICONSTOP);
		case 2:
			return MessageBox(NULL,fs.c_str(),hgkufd,MB_YESNO|MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_ICONSTOP);
		case 3:
			return MessageBox(NULL,fs.c_str(),hgkufd,MB_ABORTRETRYIGNORE|MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_ICONSTOP);
		case 4:
			return MessageBox(NULL,fs.c_str(),hgkufd,MB_YESNOCANCEL|MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_ICONSTOP);
		case 5:
			return MessageBox(NULL,fs.c_str(),hgkufd,MB_RETRYCANCEL|MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_ICONSTOP);
		case 6:
			return MessageBox(NULL,fs.c_str(),hgkufd,MB_OKCANCEL|MB_ICONINFORMATION|MB_SYSTEMMODAL|MB_ICONSTOP);
	}
}
char* chh(string st) {
	static char cha[1001];
	int i;
	for(i=0; i<st.size(); i++)
		cha[i]=st[i];
	cha[i]='\0';
	return cha;
}
string stt(const char *ch) {
	string strr;
	int i=0;
	while(*ch!=0) {
		strr+=*ch++;
	}
	return strr;
}
void Chooshong() {
	printf("����ӵ�ж�δЯ���ĳ����У�(��ɫΪ��ѡ����ɫΪ����ѡ)\n\n����Я����ֻ��\n\n");
	color(8);
	for(int i=1; i<=36; i++) {
		if(xuan[i].Hav==1&&xuan[0].PN!=xuan[i].PN) {
			color(14);
			printf("%2d,%s:%s(%s)\n",i,xuan[i].chu,xuan[i].PNm,xuan[i].XM);
		} else printf("%2d,%s\n",i,xuan[i].name);
		color(8);
	}
	printf("0,����\n\n");
	color(11);
	puts("===================================================================================");
	cin>>st;
	if(opw(st)==0)return;
	if(xuan[opw(st)].Hav==1&&xuan[0].PN!=xuan[opw(st)].PN) {
		SlowDisplay("Я���ɹ���\n\n");
		xuan[0]=xuan[opw(st)];
		return;
	} else {
		SlowDisplay("�㻹û��");
		SlowDisplay(xuan[opw(st)].name);
		SlowDisplay("\n\n");
		return;
	}
}
void help() {
	printf("����һ�����ߵ����磬G����������ˣ����������ǽ�G������ȫ�ؾȳ���\n\n");
	Sleep(100);
	printf("����ϷΪGBR��������ַ: http://gbrblog.ga, QQ :3552526022����������ѧϰʹ��\n\n");
	Sleep(100);
	printf("������\n\n   ������\n     �̵꣺�ṩ�Ի������׵�\n     �õ꣺�ṩ���䣬������Ϣ\n     ���У�����ʹ��ATM��ȡ������������ʧ\n     �����������Լ�̽��\n");
	Sleep(100);
	printf("\n\n   �������\n     ������Ϸʱ��Ҫ����������浵�н�ɫ���ƣ�����е��������¿�ʼ�Ļ����浵�Ḳ��\n     ��Ϸ���Զ��浵����������ս���йرմ��ڣ���������δ֪����\n");
	Sleep(100);
	printf("\n\n   ����ϵͳ��\n     ������ս���в����ˣ��������ҽ��й������ظ������\n     �����Ϊʮ����̬���ף��飬��(����һ��ʡ��)���棬���ã�ʥ���ۣ��棬ʼԴ\n");
	printf("     ������;��?(��������)�й�ȥ����С��������������Σ����м��ʼ�ʰ������׵���.��Ȼ,��ĳһ��NPC����Ҳ��õ�һֻ�������һ����ϲ!��������������Ҫ���������Ӻ���ĳ��NPC�Ի������ٻ�\n\n");
//	Sleep(100);
//	printf("\n\nע�������������Ա��ɫ����,���ƻᱻ�����޸�\n\n");
	Sleep(100);
	printf("Ϊ��Ϸ��Ȥ��ƽ�⣬����ʹ�����������\n\n");
	Sleep(100);
	printf("ף��Ϸ��졭��\n\n���һ�䣺����Windows��Ĭ�Ͽ�ݼ�������Ctrl+��ĸ�Ⱦ�������\n\n");
}
int opw(string st) {
	int i,o,n,ans=0,t=1;
	for(i=0; i<st.size(); i++) {
		if(st[i]=='-'&&i==0)t=-1;
		else if(st[i]=='+'&&i==0)t=1;
		else if(st[i]>='0'&&st[i]<='9') {
			if(ans==-1)ans=0;
			ans=ans*10+st[i]-'0';
		} else {
			printf("�����������������\n");
			string st1;
			cin>>st1;
			return opw(st1);
		}
	}
	return t*ans;
}
int main() {
	atexit(first);
	srand((unsigned)time(NULL));
	cout<<"��Ϸ�����С���\n\n";
	SetConsoleTitle("��ʿ֮սV3.5.3");
	setjindutiao(101);
	system("mode con cols=83 lines=999");
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	COORD size= {83, 25};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut,&bInfo);
	SMALL_RECT rc = {0,0, 83-1, 25-1};
	SetConsoleWindowInfo(hOut,true ,&rc);
	system("cls");
	int i=0,j=0,k=0;
	color(4);
	SlowDisplay("����һ�����ߵ�����!����ǰG�����������!\n\n�¸ҵ�սʿ��~�����������,Ӫ��G����!\n\n\n�����������(��Ҫ����20���ֽ�):\n\n\n");
	color(7);
	strcpy(player_name,"");
	char dfg[21];
	while(strcmp(player_name,"")==0) {
		gets(dfg);
		strcpy(player_name,dfg);
		strcpy(player.name,dfg);
	}
	int dfgi,dfgo;
	int dfga[21];
	for(dfgi=0; dfgi<strlen(dfg); dfgi++)
		dfga[dfgi]=dfg[dfgi];
	int len=strlen(dfg)-1;
	for(dfgi=len; dfgi>=0; dfgi--) {
		dfga[dfgi+1]=abs(dfga[dfgi]);
	}
	dfga[0]=len+1;
	len++;
	for(dfgi=0; dfgi<=len; dfgi++) {
		while(dfga[dfgi]>=10) {
			for(dfgo=len; dfgo>=dfgi+1; dfgo--)
				dfga[dfgo+1]=dfga[dfgo];
			dfga[dfgi+1]=dfga[dfgi]%10;
			len++;
			dfga[dfgi]/=10;
		}
	}
	for(dfgi=0; dfgi<=len; dfgi++) {
		nammm[dfgi]=dfga[dfgi]+'0';
	}
	nammm[dfgi]='\0';
	strcat(nammm,".Natsu");
	fin=fopen(nammm,"r");
	int huihiuh=0;
	fscanf(fin, "%d",&huihiuh);
	if(huihiuh==1) {
		while(huihiuh!=6&&huihiuh!=7) {
			huihiuh=massbox("�Ƿ�����浵","��⵽��ͬ���浵���Ƿ�����?\n",2);
		}
		if(huihiuh==6) {
			fsavein();
			system("CLS");
			OrdinaryAct();
		} else SlowDisplay("��ʼ����Ϸ\n\n\n");
		Sleep(200);
		system("CLS");
	}
	system("cls");
	strcpy(yanname,"��");
	system("pause");
	strcpy(gongname,"��");
	system("cls");
	strcpy(hunname,"��");
	strcpy(fangname,"��");
	strncpy(player.name,player_name,20);
	player.attack+=rand()%40-20;
	player.defense+=rand()%40-20;
	player.max_health+=rand()%20-10;
	player.health=player.max_health;
	player.max_PP+=rand()%10-5;
	player.PP=player.max_PP;
	player.max_exp+=rand()%40-20;
	if(strcmp(player.name,"gbr")==0) {
		color(12);
		printf("���������룺");
		cin>>st;
		if(st!="gbr666") {
			printf("������󣬷�GBR");
			Sleep(1000);
			player.name[4]='\0';
			goto here;
		}
		cccsss=1;
		player.name[4]='\0';
		system("cls");
		SlowDisplay("��������99999\n��������99999\nHP���ޣ�999999\nPP���ޣ�999999\n\n\n");
		player.attack=99999;
		player.defense=99999;
		player.health=999999;
		player.PP=999999;
		player.max_health=999999;
		player.max_PP=999999;
		color(11);
		Sleep(1000);
		system("cls");
		OrdinaryAct();
		return 0;
	}
	if(strcmp(player.name,"��ʿ@����")==0) {
		color(12);
		printf("���������Ա���룺");
		cin>>st;
		if(st!="354260554") {
			printf("������󣬷ǲ�������");
			Sleep(1000);
			player.name[4]='\0';
			goto here;
		}
		cccsss=2;
		player.name[4]='\0';
		system("cls");
		SlowDisplay("��������999\n��������999\nHP���ޣ�9999\nPP���ޣ�9999\n���м��ܽ���\n\n\n");
		player.attack=999;
		player.defense=999;
		player.health=9999;
		player.PP=9999;
		player.max_health=9999;
		player.max_PP=9999;
		jn_jszz.hadd=1;
		jn_jmfs.hadd=1;
		jn_mtdz.hadd=1;
		jn_xhly.hadd=1;
		jn_mhsx.hadd=1;
		jn_nljt.hadd=1;
		jn_phsg.hadd=1;
		jn_hdjt.hadd=1;
		jn_kghw.hadd=1;
		jn_jpzs.hadd=1;
		jn_getb.hadd=1;
		jn_htmd.hadd=1;
		jn_lpjq.hadd=1;
		jn_lztx.hadd=1;
		jn_zszs.hadd=1;
		jn_hgfz.hadd=1;
		jn_xjzq.hadd=1;
		jn_gzpz.hadd=1;
		jn_tqtb.hadd=1;
		jn_jjcj.hadd=1;
		jn_scfs.hadd=1;
		jn_xhys.hadd=1;
		color(11);
		Sleep(1000);
		system("cls");
		OrdinaryAct();
		return 0;
	}
	if(strcmp(player.name,"���Ƽ�@����")==0) {
		color(12);
		printf("���������Ա���룺");
		cin>>st;
		if(st!="354260554") {
			printf("������󣬷ǲ�������");
			Sleep(1000);
			player.name[6]='\0';
			goto here;
		}
		cccsss=3;
		player.name[6]='\0';
		system("cls");
		SlowDisplay("��������999\n��������999\nHP���ޣ�9999\nPP���ޣ�9999\n��ң���\n\n\n");
		player.attack=999;
		player.defense=999;
		player.health=9999;
		player.PP=9999;
		player.max_health=9999;
		player.max_PP=9999;
		money=999999999;
		color(11);
		Sleep(1000);
		system("cls");
		OrdinaryAct();
		return 0;
	}
	if(strcmp(player.name,"ѱ��ʦ@����")==0) {
		color(12);
		printf("���������Ա���룺");
		cin>>st;
		if(st!="354260554") {
			printf("������󣬷ǲ�������");
			Sleep(1000);
			player.name[6]='\0';
			goto here;
		}
		cccsss=4;
		player.name[6]='\0';
		system("cls");
		SlowDisplay("��������999\n��������999\nHP���ޣ�9999\nPP���ޣ�9999\n���г����������������㹻\n\n\n");
		player.attack=999;
		player.defense=999;
		player.health=9999;
		player.PP=9999;
		player.max_health=9999;
		player.max_PP=9999;
		for(i=1; i<=36; i++) {
			xuan[i].Hav=1;
			xuan[i].level=1;
			xuan[i].Lup=99;
			xuan[i].attack+=(rand()%10-5);
		}
		Hpet=1;
		color(11);
		Sleep(1000);
		system("cls");
		OrdinaryAct();
		return 0;
	}
here:
	system("CLS");
	printf("����ѡʲôְҵ��ְҵ�뼼�ܵ��޹أ�ֻ�ǻ������Ĺ�������HP��PP������\n\n");
	printf("1,ս  ʿ(�߹�,��PP)\n2,��  ʿ(�߷�,�Ե͹���PP)\n3,��  ��(��HP,�Ը߷�,�Ե͹���PP)\n4,��  ʦ(��PP,�Ը߹�,�Ե�HP)\n5,��  ��(������,�Ը߹�,��HP)\n6,��  ��(�߱���,�Ը߹��ͷ�,�Ե�HP)\n7,��ͨ��(���ⷢչ)\n");
	cin>>st;
	while(opw(st)<1||opw(st)>7)
		cin>>st;
	switch(opw(st)) {
		case 1:
			player.att_=30;
			player.att__=30;
			player.HP_=175;
			player.HP__=50;
			player.defen_=10;
			player.defen__=20;
			player.PP_=5;
			player.PP__=10;
			break;
		case 2:
			player.att_=15;
			player.att__=19;
			player.HP_=185;
			player.HP__=49;
			player.defen_=20;
			player.defen__=15;
			player.PP_=8;
			player.PP__=17;
			break;
		case 3:
			player.att_=17;
			player.att__=19;
			player.HP_=225;
			player.HP__=50;
			player.defen_=17;
			player.defen__=25;
			player.PP_=8;
			player.PP__=18;
			break;
		case 4:
			player.att_=25;
			player.att__=18;
			player.HP_=159;
			player.HP__=60;
			player.defen_=10;
			player.defen__=20;
			player.PP_=20;
			player.PP__=20;
			player.miss=25;
			break;
		case 5:
			player.att_=25;
			player.att__=19;
			player.HP_=148;
			player.HP__=39;
			player.defen_=10;
			player.defen__=20;
			player.PP_=10;
			player.PP__=20;
			break;
		case 6:
			player.att_=25;
			player.att__=18;
			player.HP_=165;
			player.HP__=40;
			player.defen_=14;
			player.defen__=19;
			player.PP_=10;
			player.PP__=20;
			player.baoji=23;
			break;
		case 7:
			player.att_=20;
			player.att__=20;
			player.HP_=175;
			player.HP__=50;
			player.defen_=10;
			player.defen__=20;
			player.PP_=10;
			player.PP__=20;
			break;
	}
	Sleep(1000);
	system("cls");
	OrdinaryAct();
	exit(0);
}
int SuiJi() {
	srand((unsigned)time(NULL));
	return rand()%10;
}
int SuiJi100() {
	srand((unsigned)time(NULL));
	return rand()%100;
}
void ChooseWupin() {					 //ѡ����Ʒ ��ʹ��
	if(battle) color(12);
	else color(11);
	printf("��Ʒ: \n\
1,ֹѪ��%d��	2,���Ȱ�%d��	3,���ϰ�ҩ%d��		4,�������ϰ�ҩ%d�� \n\
5,Ԫ����%d��	6,���ɲ�%d��	7,������%d��		8,����������%d��\n\
9,��  ǹ%d��	10,�� ��%d��	11,�������｣%d��	12,����������%d��\n\
0,����\n\n\n",cao,jijiubao,baiyao,superbaiyao,dan,xiancao,xlsoup,superxlsoup,boom,dubiao,atom_boom,hlbyr);
	cin>>st;
	switch(opw(st)) {
		case 1:
			if(cao>0) {
				SlowDisplay("ʹ��ֹѪ��,HP����200\n\n\n");
				cao--;
				if(battle==0) {
					if(player.health+200>player.max_health)player.health=player.max_health;
					else player.health+=200;
				} else if(battle_player.health+200>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=200;
				if(battle)AttackResult();
			} else SlowDisplay("û��ֹѪ����\n\n\n");
			break;
		case 2:
			if(jijiubao>0) {
				SlowDisplay("ʹ�ü��Ȱ�,HP����500\n\n\n");
				jijiubao--;
				if(battle==0) {
					if(player.health+500>player.max_health)player.health=player.max_health;
					else player.health+=500;
				} else if(battle_player.health+500>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=500;
				if(battle)AttackResult();
			} else SlowDisplay("û�м��Ȱ���\n\n\n");
			break;
		case 3:
			if(baiyao>0) {
				SlowDisplay("ʹ�����ϰ�ҩ,HP����1000\n\n\n");
				baiyao--;
				if(battle==0) {
					if(player.health+1000>player.max_health)player.health=player.max_health;
					else player.health+=1000;
				} else if(battle_player.health+1000>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=1000;
				if(battle)AttackResult();
			} else SlowDisplay("û�����ϰ�ҩ��\n\n\n");
			break;
		case 4:
			if(superbaiyao>0) {
				SlowDisplay("ʹ�ó������ϰ�ҩ,HP����2000\n\n\n");
				superbaiyao--;
				if(battle==0) {
					if(player.health+2000>player.max_health)player.health=player.max_health;
					else player.health+=2000;
				} else if(battle_player.health+2000>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=2000;
				if(battle)AttackResult();
			} else SlowDisplay("û�г������ϰ�ҩ��\n\n\n");
			break;
		case 5:
			if(dan>0) {
				SlowDisplay("ʹ��Ԫ����,PP����50\n\n\n");
				dan--;
				if(battle==0) {
					if(player.PP+50>player.max_PP)player.PP=player.max_PP;
					else player.PP+=50;
				} else if(battle_player.PP+50>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=50;
				if(battle)AttackResult();
			} else SlowDisplay("û��Ԫ������\n\n\n");
			break;
		case 6:
			if(xiancao>0) {
				SlowDisplay("ʹ�����ɲ�,PP����100\n\n\n");
				xiancao--;
				if(battle==0) {
					if(player.PP+100>player.max_PP)player.PP=player.max_PP;
					else player.PP+=100;
				} else if(battle_player.PP+100>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=100;
				if(battle)AttackResult();
			} else SlowDisplay("û�����ɲ���\n\n\n");
			break;
		case 7:
			if(xlsoup>0) {
				SlowDisplay("ʹ��������,PP����300\n\n\n");
				xlsoup--;
				if(battle==0) {
					if(player.PP+300>player.max_PP)player.PP=player.max_PP;
					else player.PP+=300;
				} else if(battle_player.PP+300>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=300;
				if(battle)AttackResult();
			} else SlowDisplay("û����������\n\n\n");
			break;
		case 8:
			if(superxlsoup>0) {
				SlowDisplay("ʹ�ó���������,PP����500\n\n\n");
				superxlsoup--;
				if(battle==0) {
					if(player.PP+500>player.max_PP)player.PP=player.max_PP;
					else player.PP+=500;
				} else if(battle_player.PP+500>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=500;
				if(battle)AttackResult();
			} else SlowDisplay("û�г�����������\n\n\n");
			break;
		case 9:
			if(battle) {			   //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
				if(boom>0) {
					SlowDisplay("ʹ�ñ�ǹ,����HP����500\n\n\n");
					boom--;
					guai.health-=500;
					AttackResult();
				} else SlowDisplay("û�б�ǹ��\n\n\n");
			} else SlowDisplay("��ս��״̬,����ʹ�ñ�ǹ!\n\n\n");
			break;
		case 10:
			if(battle) {			   //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
				if(dubiao>0) {
					SlowDisplay("ʹ�ö���,����HP����1200\n\n\n");
					dubiao--;
					guai.health-=1200;
					AttackResult();
				} else SlowDisplay("û�ж�����\n\n\n");
			} else SlowDisplay("��ս��״̬,����ʹ�ö���!\n\n\n");
			break;
		case 11:
			if(battle) {			   //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
				if(atom_boom>0) {
					SlowDisplay("ʹ���������｣,����HP����5500\n\n\n");
					atom_boom--;
					guai.health-=5500;
					AttackResult();
				} else SlowDisplay("û���������｣��\n\n\n");
			} else SlowDisplay("��ս��״̬,����ʹ���������｣!\n\n\n");
			break;
		case 12:
			if(battle) {			   //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
				if(hlbyr>0) {
					SlowDisplay("ʹ�ú���������,����HP����10000\n\n\n");
					hlbyr--;
					guai.health-=10000;
					AttackResult();
				} else SlowDisplay("û�к�����������\n\n\n");
			} else SlowDisplay("��ս��״̬,����ʹ�ú���������!\n\n\n");
			break;
		case 0:
			break;
		default:
			printf("�������\n\n\n");
	}
}
int AttackResult() {			  //�������:�ж��Ƿ��ʤ �Ƿ�����Ʒ �� �Ƿ�����
	if(guai.health<=0) {
		battle=0;
		color(14);
		printf("ս��ʤ��!\n\n");
		int D=rand()%40+20;
		int MMM=rand()%40-20;
		if(guai.boss_!=2) {
			if(xuan[0].PN!=16) {
				printf("��ý��%d,����%d\n\n\n",guai.money+MMM,guai.exp+D);
				player.exp+=guai.exp+D;
				money+=guai.money+MMM;
			} else {
				printf("��ý��%d,����%d\n\n\n",(guai.money+MMM)*2,(guai.exp+D)*2);
				player.exp+=(guai.exp+D)*2;
				money+=(guai.money+MMM)*2;
			}
		}
		player.health=battle_player.health;
		player.PP=battle_player.PP;
		s=SuiJi();
		if(guai.wupin_sign<0) {
			color(14);
			SlowDisplay("��ӵ��˵Ļ��з����ס�");
			printf("%s\n\n\n",guai.wupin);
			AddWupin(guai.wupin_sign);
		} else if(s<=guai.wupinpro&&guai.wupin_sign>0) {
			color(14);
			SlowDisplay("�ӵ���ʬ���з���");
			printf("%s\n\n\n",guai.wupin);
			AddWupin(guai.wupin_sign);
		}
		WhetherLevelUp();
		if(strcmp(guai.name,"�ڰ����")==0) {
			color(14);
			SlowDisplay("�ڰ���ۣ�   ����ҵ��ţ��һ�����ģ�����\n\n    �����˾���֮ľ������֮��ͷ���֮��,�ȳ�����乫��\n\n\
	�����������������Բ���\n\n    �㽫�����͵����õ�\n\n�õ��ϰ壺\
			\n\n    ��˵�ü�̳����֮�������԰����˿��ٻָ�������\n\n\n");
			place_sign=place.hotel;
			printf("%s",player.name);
			SlowDisplay("ʹ���˾���֮ľ������֮��ͷ���֮�棬������+1000��������+1000��HP+1500,PP+100\n\n");
			gong+=1000;
			fang+=1000;
			player.max_health+=1500;
			player.max_PP+=100;
			player.health=player.max_health;
			player.PP=player.max_PP;
			kingdie=1;
		}
		return 1;				 //�����н���˷���1,���򷵻�0,�����ж��Ƿ������ս����Ϊ
	} else {
		int HHHP=battle_player.health;
		color(12);
		if(guai.kind_==0&&PhyHalf==3)battle_player.defense*=2;
		if(PhyHalf==1)battle_player.defense/=2;
		if(PhyHalf)PhyHalf--;
		if(guai.kind_==1&&MgcHalf==3)battle_player.defense*=2;
		if(MgcHalf==1)battle_player.defense/=2;
		if(MgcHalf)MgcHalf--;
		int sik=SuiJi();
		if(Slp) {
			if(sik<=2) {
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("%s������\n\n");
				Slp=0;
			} else {
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("���ڳ�˯\n\n");
				sik=11;
			}
		} else if(Ice) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("��δ�ⶳ\n\n");
			sik=11;
		} else if(Elec&&sik<=4) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("���,�޷��ƶ�\n\n");
			sik=11;
		} else if(Wory&&sik<=4) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("�Ի���,�޷��ж�\n\n");
			sik=11;
		} else if(Sick&&sik<=2) {
			sik=11;
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("����,�������Լ�\n\n");
			if(guai.attack+s-guai.defense/3>1) {
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("��HP������%d\n\n",min(guai.health,guai.attack+s-guai.defense/3));
				guai.health-=min(guai.health,guai.attack+s-guai.defense/3);
			} else {
				guai.health-=1;
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("��HP������1\n\n");
			}
		} else if(BrBow) {
			if(sik<9) {
				sik=11;
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("���� %s����\n\n",player.name);
			} else {
				if(guai.attack*10-battle_player.defense>0) {
					int hiuuthug=guai.attack*10-battle_player.defense;
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("���� %s���黯�ܵ�����,�������%d���˺�\n\n",player.name,min(battle_player.health,hiuuthug));
					battle_player.health-=min(battle_player.health,hiuuthug);
					if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
						SlowDisplay("�ṫ�㷢��<а��>,���غϵ����˺���Ч��\n\n");
						battle_player.health=HHHP;
					} else if(rand()%100<xuan[37].Baif&&xuan[37].PN==-10) {
						SlowDisplay("���󷢶�<����>,���غϵ����˺���Ч��\n\n");
						battle_player.health=HHHP;
					}
				} else {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("���� %s���黯�ܵ�����,�������%d���˺�\n\n",player.name,min(battle_player.health,(sik+1)));
					battle_player.health-=min(battle_player.health,(sik+1));
					if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
						SlowDisplay("�ṫ�㷢��<а��>,���غϵ����˺���Ч��\n\n");
						battle_player.health=HHHP;
					} else if(rand()%100<xuan[37].Baif&&xuan[37].PN==-10) {
						SlowDisplay("���󷢶�<����>,���غϵ����˺���Ч��\n\n");
						battle_player.health=HHHP;
					}
				}
				sik=11;
				if(battle_player.health<=0) {
					if(xuan[37].PN==-16&&rand()%200<xuan[37].Baif) {
						SlowDisplay("��ս����\n\n����ȸ����<����>,��ص���HP����PP\n\n");
						battle_player.health=battle_player.max_health;
						battle_player.PP=battle_player.max_PP;
					} else {
						battle=0;
						xuan[37]=xuan[0];
						printf("%sս��!��ҵ���%d\n\n\n",player.name,money);
						money=0;
						player.health=player.max_health/5;
						player.PP=player.max_PP/5;
						if(cccsss==3)money=999999999;
						OrdinaryAct();
						return 1;
					}
				}
			}
		}
		int SSick=0,EElec=0,WWory=0,IIce=0;
		if(Sick&&rand()%5==0)SSick=1;
		if(Elec&&rand()%5==0)EElec=1;
		if(Wory&&rand()%5==0)WWory=1;
		if(Ice&&rand()%5==0)IIce=1;
		if(Sick==1||SSick==1) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("�Ļ��ҽ����\n");
		}
		if(Elec==1||EElec==1) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("����Խ����\n");
		}
		if(Ice==1||IIce==1) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("�ı��������\n");
		}
		if(Wory==1||WWory==1) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("���Ի�����\n");
		}
		if(Sick)Sick--;
		if(Elec)Elec--;
		if(BrBow)BrBow--;
		if(Ice)Ice--;
		if(Wory)Wory--;
		if(SSick)Sick=0;
		if(EElec)Elec=0;
		if(IIce)Ice=0;
		if(WWory)Wory=0;
		int s=SuiJi();
		if(sik!=11) {
			if(rand()%100>battle_player.miss) {
				if((guai.attack+s-battle_player.defense/3)<0) {
					if(Bkll) {
						guai.health-=min(Bkll,guai.health);
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("����,�˺�������");
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("���%d���˺�\n\n\n",min(Bkll,guai.health));
						Bkll=0;
					} else {
						battle_player.health-=1;
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("����,���HP������1\n\n");
					}
				} else {
					if(rand()%100<guai.baoji) {
						if(Bkll) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("����,�˺�������%s���%d���˺�\n\n\n",guai.name,min((guai.attack+s-battle_player.defense/3)*Bkll*9/5,guai.health));
							guai.health-=min((guai.attack+s-battle_player.defense/3)*Bkll*9/5,guai.health);
							Bkll=suran=0;
						} else if(suran) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("����,���HP������%d\n\n",min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health));
							printf("ͬʱ,��<��Ȼ>��%s���%d���˺�\n\n\n",guai.name,min((guai.attack+s-battle_player.defense/3)*9/5,guai.health));
							guai.health-=min((guai.attack+s-battle_player.defense/3)*9/5,guai.health);
							battle_player.health-=min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health);
							suran=0;
						} else {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("����,���HP������%d\n\n",min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health));
							battle_player.health-=min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health);
						}
					} else {
						if(Bkll) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("����,�˺�������");
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("���%d���˺�\n\n\n",min((guai.attack+s-battle_player.defense/3)*Bkll,guai.health));
							guai.health-=min((guai.attack+s-battle_player.defense/3)*Bkll,guai.health);
							Bkll=suran=0;
						} else if(suran) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("����,���HP������%d\n\n",min(guai.attack+s-battle_player.defense/3,guai.health));
							printf("ͬʱ,��<��Ȼ>��");
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("���%d���˺�\n\n\n",(guai.attack+s-battle_player.defense/3));
							guai.health-=min(guai.attack+s-battle_player.defense/3,guai.health);
							battle_player.health-=min(guai.attack+s-battle_player.defense/3,battle_player.health);
							suran=0;
						} else {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("����,���HP������%d\n\n",min(battle_player.health,guai.attack+s-battle_player.defense/3));
							battle_player.health-=min(battle_player.health,guai.attack+s-battle_player.defense/3);
						}
					}
				}
				if(yan>0) {
					int UHGRUhgtR=rand()%(yann/2)+1,r=rand()%2-1;
					if(r==0)UHGRUhgtR=-UHGRUhgtR;
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("��������,����%dHP\n\n",min(guai.health,yann+UHGRUhgtR));
					guai.health-=min(guai.health,yann+UHGRUhgtR);
				}
				s=rand()%60+1-30;
				if(Fire&&guai.Frr>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("����,ʧȥ%dHP\n\n",min(guai.health,guai.Frr+s));
					guai.health-=min(guai.health,guai.Frr+s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("���ϵĻ�Ϩ����\n\n");
					}
				}
				if(Fire&&guai.Frr<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�������ܵ��Ļ����˺�,�ָ�%dHP\n\n",-(guai.Frr+s));
					guai.health-=(guai.Frr-s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("���ϵĻ�Ϩ����\n\n");
					}
				}
				if(Kill) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�ж�,ʧȥ%dHP\n\n",min(guai.health,guai.ill+s));
					guai.health-=min(guai.health,guai.ill+s);
					Kill--;
					if(Kill==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("�Ķ������\n\n");
					}
				}
				if(Squid&&guai.lft+s>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�򱻼���,ʧȥ%dHP,%s�ָ�%dHP\n\n",min(guai.health,guai.lft+s),player.name,min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s)));
					guai.health-=min(guai.health,guai.lft+s);
					battle_player.health+=min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s));
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("�ļ��������\n\n");
					}
				} else if(Squid&&guai.lft+s<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�򱻼����ܵ���ľ�˺�,�ָ�%dHP\n\n",0-(guai.lft+s));
					guai.health+=-(guai.lft+s);
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("�ļ��������\n\n");
					}
				}
				Bkll=0;
				if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
					SlowDisplay("�ṫ�㷢��<а��>,���غϵ����˺���Ч��\n\n");
					battle_player.health=HHHP;
				} else if(rand()%100<xuan[37].Baif&&xuan[37].PN==-10) {
					SlowDisplay("���󷢶�<����>,���غϵ����˺���Ч��\n\n");
					battle_player.health=HHHP;
				}
				if(battle_player.health<=0) {
					if(xuan[37].PN==-16&&rand()%200<xuan[37].Baif) {
						SlowDisplay("��ս����\n\n����ȸ����<����>,��ص���HP����PP\n\n");
						battle_player.health=battle_player.max_health;
						battle_player.PP=battle_player.max_PP;
					} else {
						battle=0;
						xuan[37]=xuan[0];
						printf("%sս��!��ҵ���%d\n\n\n",player.name,money);
						money=0;
						player.health=player.max_health/5;
						player.PP=player.max_PP/5;
						if(cccsss==3)money=999999999;
						OrdinaryAct();
						return 1;
					}
				}
			} else {
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("���� %s����\n\n",player.name);
				s=rand()%60+1-30;
				if(Fire&&guai.Frr>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("����,ʧȥ%dHP\n\n",min(guai.health,guai.Frr+s));
					guai.health-=min(guai.health,guai.Frr+s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("���ϵĻ�Ϩ����\n\n");
					}
				}
				if(Fire&&guai.Frr<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�������ܵ��Ļ����˺�,�ָ�%dHP\n\n",-(guai.Frr+s));
					guai.health-=(guai.Frr-s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("���ϵĻ�Ϩ����\n\n");
					}
				}
				if(Kill) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�ж�,ʧȥ%dHP\n\n",min(guai.health,guai.ill+s));
					guai.health-=min(guai.health,guai.ill+s);
					Kill--;
					if(Kill==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("�Ķ������\n\n");
					}
				}
				if(Squid&&guai.lft+s>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�򱻼���,ʧȥ%dHP,%s�ָ�%dHP\n\n",min(guai.health,guai.lft+s),player.name,min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s)));
					guai.health-=min(guai.health,guai.lft+s);
					battle_player.health+=min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s));
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("�ļ��������\n\n");
					}
				} else if(Squid&&guai.lft+s<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("�򱻼����ܵ���ľ�˺�,�ָ�%dHP\n\n",0-(guai.lft+s));
					guai.health+=-(guai.lft+s);
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("�ļ��������\n\n");
					}
				}
				Bkll=0;
			}
		}
		if(guai.health<=0) {
			battle=0;
			color(14);
			xuan[37]=xuan[0];
			printf("ս��ʤ��!\n\n");
			int D=rand()%40+20;
			int MMM=rand()%40-20;
			if(guai.boss_!=2) {
				printf("��ý��%d,����%d\n\n\n",guai.money+MMM,guai.exp+D);
				player.exp+=guai.exp+D;
				money+=guai.money+MMM;
			}
			player.health=battle_player.health;
			player.PP=battle_player.PP;
			s=SuiJi();
			if(guai.wupin_sign<0) {
				color(14);
				SlowDisplay("��ӵ��˵Ļ��з����ס�");
				printf("%s\n\n\n",guai.wupin);
				AddWupin(guai.wupin_sign);
			}
			if(s<=guai.wupinpro&&guai.wupin_sign>0) {
				color(14);
				SlowDisplay("�ӵ���ʬ���з���");
				printf("%s\n\n\n",guai.wupin);
				AddWupin(guai.wupin_sign);
			}
			WhetherLevelUp();
			if(strcmp(guai.name,"�ڰ����")==0) {
				color(14);
				SlowDisplay("�ڰ���ۣ�   ����ҵ��ţ��һ�����ģ�����\n\n    �����˾���֮ľ������֮��ͷ���֮��,�ȳ�����乫��\n\n\
	�����������������Բ���\n\n    �㽫�����͵����õ�\n\n�õ��ϰ壺\
			\n\n    ��˵�ü�̳����֮�������԰����˿��ٻָ�������\n\n\n");
				place_sign=place.hotel;
				printf("%s",player.name);
				SlowDisplay("ʹ���˾���֮ľ������֮��ͷ���֮�棬������+1000��������+1000��HP+1500,PP+100\n\n");
				gong+=1000;
				fang+=1000;
				player.max_health+=1500;
				player.max_PP+=100;
				player.health=player.max_health;
				player.PP=player.max_PP;
				kingdie=1;
			}
			return 1;
		}
	}
	return 0;
}
void AddWupin(int wupin_sign) {
	if(wupin_sign<0) {
		wupin_sign+=36;
		for(int i=1; i<=36; i++)
			if(xuan[i].PN==wupin_sign) {
				xuan[i].Hav=1;
				break;
			}
	} else switch(wupin_sign) {
			case 1 :
				fang4n++;
				break;
			case 2 :
				fang3n++;
				break;
			case 3 :
				fang2n++;
				break;
			case 4 :
				strongman_arm=1;
				TTDIE=0;
				break;
			case 5 :
				hun3n++;
				break;
			case 6 :
				hun2n++;
				break;
			case 7 :
				hun1n++;
				break;
			case 8 :
				fishman_tail=1;
				FMDIE=0;
				break;
			case 9 :
				yan3n++;
				break;
			case 10:
				yan2n++;
				break;
			case 11:
				yan1n++;
				break;
			case 12:
				falao_fire=1;
				FODIE=0;
				break;
			case 13:
				gong4n++;
				break;
			case 14:
				gong3n++;
				break;
			case 15:
				gong2n++;
				break;
			case 91:
				shuiling=1;
				SHUIL=0;
				break;
			case 92:
				huoling=1;
				HUOL=0;
				break;
			case 93:
				tuling=1;
				TUL=0;
				break;
			case 94:
				fengling=1;
				FENGL=0;
				break;
			default:
				printf("\r                       \n\n\n");
		}
}
void WhetherLevelUp() {
	int i=0,j=0,lv_=player.level,Gong,Fang,h_p,may=0;
	for(Gong=0,Fang=0,h_p=0; player.exp>=player.max_exp&&player.level<100; player.max_exp+=(100+rand()%40-20)) {
		j++;
		player.level++;
		player.exp=player.exp-player.max_exp;
		player=player;
		may+=rand()%player.PP__+player.PP_;
		Gong+=rand()%player.att__+player.att_,Fang+=rand()%player.defen__+player.defen_,h_p+=rand()%player.HP__+player.HP_;
	}
	if(j>=1) {
		if(player.level==100)player.max_exp=0;
		color(14);
		printf("   %s����%3d��!\n\n\n   ������+%3d, ������+%3d, HP����+%3d PP����+%3d\n\n\n",player.name,j,Gong,Fang,h_p,may);
		player.max_health+=h_p;
		player.defense+=Fang;
		player.attack+=Gong;
		player.max_PP+=may;
		player.health=player.max_health;
		player.PP=player.max_PP;
	}
}
void OrdinaryAct() {			//������Ϊ�˵�(�ƶ�,��Ʒ,�Ի�,�鿴״̬,װ��,�˳���Ϸ)
	while(1) {
		fsave();
		if(cccsss==3)money=999999999;
		if(place_sign!=place.bank&&place_sign!=place.bar&&place_sign!=place.hotel) {
			color(11);
			puts("===================================================================================");
			printf("Ҫ��ʲô?\n\n\n1,��  �� 2,��  �� 3,��  �� 4,״  ̬ 5,װ  �� 6,��  �� 7,��  �� 8,��  Ϣ 0,��  ��\n\n\n");
			puts("===================================================================================");
		} else if(place_sign!=place.bank) {
			color(11);
			puts("===================================================================================");
			printf("Ҫ��ʲô?\n\n\n1,��  �� 2,��  �� 3,��  �� 4,״  ̬ 5,װ  �� 6,��  �� 7,��  �� 8,��  Ϣ 0,��  ��\n\n\n");
			puts("===================================================================================");
		} else if(place_sign!=place.jitan4&&place_sign!=place.jitan3&&place_sign!=place.jitan2&&place_sign!=place.jitan1) {
			color(11);
			puts("===================================================================================");
			printf("Ҫ��ʲô?\n\n\n1,��  �� 2,��  �� 3,��ȡ�� 4,״  ̬ 5,װ  �� 6,��  �� 7,��  �� 8,��  Ϣ 0,��  ��\n\n\n");
			puts("===================================================================================");
		}
		cin>>st;
		switch(opw(st)) {
				color(11);
			case 6:
				jn_gai();
				break;
			case 7:
				Chooshong();
				break;
			case 8:
				printf(" 1, ��  ��  2,�ر���л  3,��  ֵ   0,��  ��\n\n");
				cin>>st;
				if(opw(st)==1) {
					help();
					break;
				} else if(opw(st)==2) {
					printf("�ر���лBoss_Xuan,������,Monkey���˵İ�����֧��\n\n");
				} else if(opw(st)==3){
					system("start https://www.baidu.com");
					massbox("��ֵ?","��һC++С��Ϸ�����㲻�����뻨Ǯ��Ը��",1);
				}
				break;
			case 1:									//��ʾ�ƶ��˵�
				SlowDisplay("Ҫȥ����?\n\n\n");
				printf(" 1,����  2,�ù�  3,����");
				printf("\n 4,ɭ��һ��  5,ɭ�ֶ���  6,ɭ������ ");
				printf("\n 7,�һ��  8,�����  9,����� ");
				printf("\n10,ɳĮһ�� 11,ɳĮ���� 12,ɳĮ���� ");
				printf("\n13,��ԭһ�� 14,��ԭ���� 15,��ԭ���� ");
				printf("\n16,ˮ֮��̳ 17,��֮��̳ 18,��֮��̳ 19,��֮��̳\n\n\n");
				battle_player=player;
				cin>>st;
				switch(opw(st)) {
						case 1:
							place_sign=place.bar;
							break;
						case 2:
							place_sign=place.hotel;
							if((shuiling==1)&&(huoling==1)&&(tuling==1)&&(fengling==1)) {
								color(14);
								SlowDisplay("ˮ֮�飬��֮�飬��֮�飬��֮����������乫������\n\n��乫����\n\n   лл\n\n��ɹ��ؾȳ��˹���\n\n");
								system("pause");
								MessageBox(NULL,st.c_str(),"ʤ��",MB_OK);
								exit(0);
							} else
								color(8);
							SlowDisplay("Ҫס����? 200����� 1,��  0,��\n\n\n");
							st="1";
							cin>>st;
							switch(opw(st)) {
								case 1:
									if(money-200<0)SlowDisplay("Sorry,���Ǯ����~\n\n\n");
									else {
										SlowDisplay("�ú���Ϣ\n\tHP��  PP��\n\t\t�ڶ�����\n\n");
										money-=200;
										player.health=player.max_health;	//������
										player.PP=player.max_PP;
										if(cccsss==3)money=999999999;
									}
									break;
								case 0:
									SlowDisplay("�´�����!\n\n\n");
									break;
								default:
									printf("�������!\n\n\n");
							}
							break;
						case 3:
							place_sign=place.bank;
							break;
						case 4:
							place_sign=place.forest1;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=xiyi;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=witch;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 5:
							place_sign=place.forest2;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=witch;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=strongman;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 6:
							place_sign=place.forest3;
							s=SuiJi();
							color(12);
							battle=1;
							if(TTDIE==1)guai=big_strongman;
							else guai=big_strongmanking;
							{
								color(guai.color);
								printf("%s",guai.name);
								color(12);
								printf("���˹���!\n\n\n");
							}
							if(strongman_arm==0&&TTDIE==1)SlowDisplay("ɭ�־�������   �������������ǵ�ʥ��\n\n\n");
							else SlowDisplay("ɭ�־�����֮�棺   ��ʥ�ݻ�������\n\n\n");
							battle_player=player;
							BattleAct();
							break;
						case 7:
							place_sign=place.sea1;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=lie;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=jing;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 8:
							place_sign=place.sea2;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=jing;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=shark;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 9:
							place_sign=place.sea3;
							s=SuiJi();
							color(12);
							battle=1;
							if(FMDIE==1)guai=fishman;
							else guai=fishmanking;
							{
								color(guai.color);
								printf("%s",guai.name);
								color(12);
								printf("���˹���!\n\n\n");
							}
							if(fishman_tail==0&&FMDIE==1)SlowDisplay("�������:   �������������ǵ�ʥˮ\n\n\n");
							else SlowDisplay("�������֮�棺   ��ʥˮ��������\n\n\n");
							battle_player=player;
							BattleAct();
							break;
						case 10:
							place_sign=place.sha1;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=jumang;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=duxie;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 11:
							place_sign=place.sha2;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=duxie;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=shouhu;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 12:
							place_sign=place.sha3;
							s=SuiJi();
							color(12);
							battle=1;
							if(FODIE==1) guai=falao;
							else guai=falaoking;
							{
								color(guai.color);
								printf("%s",guai.name);
								color(12);
								printf("���˹���!\n\n\n");
							}
							if(falao_fire==0&&FODIE==1)SlowDisplay("ɳĮ������:   �������������ǵ�ʥ��\n\n\n");
							else SlowDisplay ("ɳĮ������֮��:   ��ʥ�𻹸�����\n\n\n");
							battle_player=player;
							BattleAct();
							break;
						case 13:
							place_sign=place.grass1;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=bee;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=horse;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 14:
							place_sign=place.grass2;
							s=SuiJi();
							if(s<7) {
								color(12);
								battle=1;
								guai=horse;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else if(s<9) {
								color(12);
								battle=1;
								guai=lion;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 15:
							place_sign=place.grass3;
							if(((strongman_arm)&&(fishman_tail)&&(falao_fire))||DIII) {
								if(kingdie==0) {
									battle=1;
									battle_player=player;
									color(12);
									strongman_arm=0,fishman_tail=0,falao_fire=0;
									if(DIII==1)SlowDisplay("��������:\n\n\n���ֻ����ˣ�\n\n�Ǿ���׼�������ˣ�����\n\n\n");
									else SlowDisplay("��������:\n\n\n    ����,������,���Ĳ���\n\n    ����...\n\n    �ٺ�,���ϵ���!����֮ľ������֮��ͷ���֮����Ҫ��,�����Ҳ�������!\n\n\n");
									guai=shitu1;
									DIII=1;
									color(12);
									{
										color(guai.color);
										printf("%s",guai.name);
										color(12);
										printf("���˹���!\n\n\n");
									}
									BattleAct();
									if(strcmp(guai.name,"��֮ʹͽ")==0) {
										guai=shitu2;
										battle_player=player;
										color(12);
										battle=1;
										{
											color(guai.color);
											printf("%s",guai.name);
											color(12);
											printf("���˹���!\n\n\n");
										}
										BattleAct();
										if(strcmp(guai.name,"ˮ֮ʹͽ")==0) {
											guai=shitu3;
											battle_player=player;
											color(12);
											battle=1;
											{
												color(guai.color);
												printf("%s",guai.name);
												color(12);
												printf("���˹���!\n\n\n");
											}
											BattleAct();
											if(strcmp(guai.name,"��֮ʹͽ")==0) {
												guai=king;
												battle_player=player;
												battle=1;
												color(12);
												SlowDisplay("�ڰ����:\n\n\n    ʲô�������㾹Ȼ�ܻ����ҵ�ʹͽ������\n\n\n\r   \r   \r   \r 	  ������������Ҿ����Ὣ��佻����ģ�����\n\n\n");
												BattleAct();
											}
										}
									}
								}
							}
							s=SuiJi();
							if(s<13) {
								color(12);
								battle=1;
								guai=lion;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("���ﰲȫ\n\n\n");
							}
							break;
						case 16:
							place_sign=place.jitan1;
							if(kingdie==1&&SHUIL==1) {
								SlowDisplay("ˮ֮���������Ǹ����ĺڰ���۷�ӡ����ô�ã��������ֳ�����\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu1;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("����ʲôҲû��\n\n\n");
							}
							break;
						case 17:
							place_sign=place.jitan2;
							if(kingdie==1&&HUOL==1) {
								SlowDisplay("��֮���������Ǹ����ĺڰ���۷�ӡ����ô�ã��������ֳ�����\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu2;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("����ʲôҲû��\n\n\n");
							}
							break;
						case 18:
							place_sign=place.jitan3;
							if(kingdie==1&&TUL==1) {
								SlowDisplay("��֮�������Ǹ����ĺڰ���۷�ӡ����ô�ã��������ֳ�����\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu3;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("����ʲôҲû��\n\n\n");
							}
							break;
						case 19:
							place_sign=place.jitan4;
							if(kingdie==1&&FENGL==1) {
								SlowDisplay("��֮�������Ǹ����ĺڰ���۷�ӡ����ô�ã��������ֳ�����\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu4;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("����ʲôҲû��\n\n\n");
							}
							break;
						default:
							printf("�������!\n\n\n");
					}
				break;
			case 2:
				ChooseWupin();
				break;
			case 3:
				if(place_sign==place.bar) {
					color(11);
					if(ghgh==false)SlowDisplay("Ҫ��˭˵��?\n\n\n1,�췢Ů�� 2,�ͽ����� 3,���ߵ� 4,����С�� 5,������ 6,ѱ�޴�ʦ 7,����\n\n\n");
					if(ghgh==true)SlowDisplay("Ҫ��˭˵��?\n\n\n0,�������� 1,�췢Ů�� 2,�ͽ����� 3,���ߵ� 4.����С�� 5,������ 6,ѱ�޴�ʦ 7,����\n\n\n");	 //��ʾ�Ի�����
					cin>>st;
					switch(opw(st)) {
						case 0: {
							if(ghgh==true) {
								color(5);
								SlowDisplay("��������:\n\n\n    ������,��ð�.������о���֮ľ������֮��ͷ���֮��,�ҿ��Ը�������������Ŷ~\n\n\n");
								printf("%s:лл\n\n\n",player.name);
								ghgh=false;
								SlowDisplay("��������:\n\n\n    �����ȹ������ʹ��ö�������ԭ����Ŷ����\n\n����������ʧ��~\n\n\n");
								break;
							} else SlowDisplay("�������\n\n\n");
						}
						color(11);
						break;
						case 1:
							color(4);
							if(sby==0) {
								SlowDisplay("�췢Ů��:\n\n\n    ��˵�㾭���������,�����·��Ӧ�ú���Ϥ��!\n\n    ������С��Ϊ�ã�����2ƿ�������ϰ�ҩ���������°�\n\n\n");
								printf("%s:лл\n\n\n",player.name);
								superbaiyao+=2;
								sby=1;
								break;
							} else SlowDisplay("�췢Ů��:\n\n\n    �ܶ���,����!\n\n\n    ��Ҫ����籩���ŵ�!\n\n\n");
							color(11);
							break;
						case 2:
							color(6);
							if(liuman==0) {
								SlowDisplay("�ͽ�����:\n\n\n    ��Ҫ����䰡!�õ���!\n\n\n    ��������Ĵ��ֺͲ�ԭ���ն�,����Խ��ԽΣ��,����ذ�׺Ͳ���,�������Щ������,��ȥ��!\n\n\n");
								printf("%s:лл\n\n\n",player.name);
								gong1n++;
								fang1n++;
								liuman=1;
							} else SlowDisplay("�ͽ�����:\n\n\n    ���Ͱ�,������!\n\n\n    ��Ҫ��������ֺͲ�ԭ���ŵ�!\n\n\n");
							color(11);
							break;
						case 3:
							color(15);
							printf("Ҫ���ʲô?\n\n\n   1,ֹѪ��250���  2,���Ȱ�500���  3,���ϰ�ҩ750���  4,�������ϰ�ҩ1550���\n\
					\n   5,Ԫ����250���  6,���ɲ�500���  7,������750���  8,����������1550���\n\
					\n   9,��ǹ400��� 10,����900��� 11,�������｣1500��� 12,����������4500���  0,����\n\n\n");
							st="1";
							while(opw(st)) {
								cin>>st;
								switch(opw(st)) {
									case 1:
										if(money<250)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ��ֹѪ��\n");
											money=money-250;
											if(cccsss==3)money=999999999;
											cao++;
										}
										break;
									case 2:
										if(money<500)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ�����Ȱ�\n");
											money=money-500;
											if(cccsss==3)money=999999999;
											jijiubao++;
										}
										break;
									case 3:
										if(money<750)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ�����ϰ�ҩ\n");
											money=money-750;
											if(cccsss==3)money=999999999;
											baiyao++;
										}
										break;
									case 4:
										if(money<1550)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ���������ϰ�ҩ\n");
											money=money-1550;
											if(cccsss==3)money=999999999;
											superbaiyao++;
										}
										break;
									case 5:
										if(money<250)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ��Ԫ����\n");
											money=money-250;
											if(cccsss==3)money=999999999;
											dan++;
										}
										break;
									case 6:
										if(money<500)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ�����ɲ�\n");
											money=money-500;
											if(cccsss==3)money=999999999;
											xiancao++;
										}
										break;
									case 7:
										if(money<750)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ��������\n");
											money=money-750;
											if(cccsss==3)money=999999999;
											xlsoup++;
										}
										break;
									case 8:
										if(money<1550)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ������������\n");
											money=money-1550;
											if(cccsss==3)money=999999999;
											xlsoup++;
										}
										break;
									case 9:
										if(money<400)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ����ǹ\n");
											money=money-400;
											if(cccsss==3)money=999999999;
											boom++;
										}
										break;
									case 10:
										if(money<900)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ������\n");
											money=money-900;
											if(cccsss==3)money=999999999;
											dubiao++;
										}
										break;
									case 11:
										if(money<1500)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ���������｣\n");
											money=money-1500;
											if(cccsss==3)money=999999999;
											atom_boom++;
										}
										break;
									case 12:
										if(money<4500)SlowDisplay("Ǯ����!\n");
										else {
											printf("�㹺����һ������������\n");
											money=money-4500;
											if(cccsss==3)money=999999999;
											hlbyr++;
										}
										break;
									case 0:
										SlowDisplay("�´�����!\n");
										break;
									default:
										SlowDisplay("�������\n\n\n");
								}
							}
							color(11);
							break;
						case 4:
							color(13);
							printf("С���ӣ���Ҫ��ʲô?�¼��ܣ����������С���\n\n\n 1,��������10000���  2,���춾��10000���  3,�Ի�����10000���  4,�ǻ���ԭ10000���\
\n 5,ŭ�׾���10000���  6,�ƻ�����10000���  7,��������10000���  8,�ݹǺ���10000���\
\n 9,����֮��12000��� 10,��Ѫ����15000��� 11,�������40000��� 12,���̾���12000���\
\n13,��֮��Ϣ18000��� 14,����֮��12000��� 15,�عⷵ��18000��� 16,Ѫ��֮��20000���\
\n17,��֮����12000��� 18,ͭǽ����12000��� 19,�������18000��� 20,���淴��12000���\n21,˫�ط���18000��� 22,�黯����15000��� 0,����\n\n\n");
							st="1";
							while(opw(st)) {
								cin>>st;
								switch(opw(st)) {
									case 1:
										SlowDisplay("��������:Ͷ��������������\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_jszz.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˼�������\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_jszz.hadd++;
										}
										break;
									case 2:
										SlowDisplay("���춾��:ʹ�Է��ж�\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_mtdz.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺�������춾��\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_mtdz.hadd++;
										}
										break;
									case 3:
										SlowDisplay("�Ի�����:ʹ�Է��Ի�\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_mhsx.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺�����Ի�����\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_mhsx.hadd++;
										}
										break;
									case 4:
										SlowDisplay("�ǻ���ԭ:ʹ�Է�����\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_xhly.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺�����ǻ���ԭ\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_xhly.hadd++;
										}
										break;
									case 5:
										SlowDisplay("ŭ�׾���:ʹ�Է����\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_nljt.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺����ŭ�׾���\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_nljt.hadd++;
										}
										break;
									case 6:
										SlowDisplay("�ƻ�����:ʹ�Է�����\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_phsg.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺�����ƻ�����\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_phsg.hadd++;
										}
										break;
									case 7:
										SlowDisplay("��������:ʹ�Է�����\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_hdjt.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˺�������\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_hdjt.hadd++;
										}
										break;
									case 8:
										SlowDisplay("�ݹǺ���:ʹ�Է�����\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<10000)SlowDisplay("Ǯ����!\n");
										else if(jn_kghw.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˿ݹǺ���\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_kghw.hadd++;
										}
										break;
									case 9:
										SlowDisplay("����֮��:�޷����ܣ��ض�����\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<12000)SlowDisplay("Ǯ����!\n");
										else if(jn_jpzs.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˾���֮��\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_jpzs.hadd++;
										}
										break;
									case 10:
										SlowDisplay("��Ѫ����:�������˲���ȡ����һ��HP\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<15000)SlowDisplay("Ǯ����!\n");
										else if(jn_getb.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺������Ѫ����\n");
											money=money-15000;
											if(cccsss==3)money=999999999;
											jn_getb.hadd++;
										}
										break;
									case 11:
										SlowDisplay("�������:�㾡ȫ������ɼ�����˺�����һ��������ɱ����BOSS��Ч��\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<40000)SlowDisplay("Ǯ����!\n");
										else if(jn_htmd.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˻������\n");
											money=money-40000;
											if(cccsss==3)money=999999999;
											jn_htmd.hadd++;
										}
										break;
									case 12:
										SlowDisplay("���̾���:�ܹ��ظ�����PP\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<12000)SlowDisplay("Ǯ����!\n");
										else if(jn_lpjq.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺�������̾���\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_lpjq.hadd++;
										}
										break;
									case 13:
										SlowDisplay("��֮��Ϣ:�ܹ��ظ�����PP\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<18000)SlowDisplay("Ǯ����!\n");
										else if(jn_lztx.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺������֮��Ϣ\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_lztx.hadd++;
										}
										break;
									case 14:
										SlowDisplay("����֮��:�ܹ��ظ�����HP\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<12000)SlowDisplay("Ǯ����!\n");
										else if(jn_zszs.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺��������֮��\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_zszs.hadd++;
										}
										break;
									case 15:
										SlowDisplay("�عⷵ��:�ܹ��ظ�����HP\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<18000)SlowDisplay("Ǯ����!\n");
										else if(jn_hgfz.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˻عⷵ��\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_hgfz.hadd++;
										}
										break;
									case 16:
										SlowDisplay("Ѫ��֮��:�ܹ�����PP,����Ҫһ����HP��Ϊ����\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<20000)SlowDisplay("Ǯ����!\n");
										else if(jn_xjzq.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺����Ѫ��֮��\n");
											money=money-20000;
											if(cccsss==3)money=999999999;
											jn_xjzq.hadd++;
										}
										break;
									case 17:
										SlowDisplay("��֮����:3�غ��ڣ�����һ��ħ���˺�\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<12000)SlowDisplay("Ǯ����!\n");
										else if(jn_gzpz.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˹�֮����\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_gzpz.hadd++;
										}
										break;
									case 18:
										SlowDisplay("ͭǽ����:3�غ��ڣ�����һ�������˺�\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<12000)SlowDisplay("Ǯ����!\n");
										else if(jn_tqtb.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺����ͭǽ����\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_tqtb.hadd++;
										}
										break;
									case 19:
										SlowDisplay("�������:ɱ�������ߣ�������Ҳ���ܵ�һ�����˺�\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<18000)SlowDisplay("Ǯ����!\n");
										else if(jn_jjcj.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˾������\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_jjcj.hadd++;
										}
										break;
									case 20:
										SlowDisplay("���淴��:�ܽ��Է����غ϶�����˺������ص�������\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<12000)SlowDisplay("Ǯ����!\n");
										else if(jn_jmfs.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺���˾��淴��\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_jmfs.hadd++;
										}
										break;
									case 21:
										SlowDisplay("˫�ط���:�ܽ��Է����غ϶�����˺�˫�������ص�������\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<18000)SlowDisplay("Ǯ����!\n");
										else if(jn_scfs.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺����˫�ط���\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_scfs.hadd++;
										}
										break;
									case 22:
										SlowDisplay("�黯����:2�غ��ڵ��������ʽ���90%��������Ҳ����˼������\n\n\nС���ӣ������Ҫ��?\n\n1,���� 0,ȡ�����ν���\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("С���ӣ���ӭ�´ι��١���\n\n");
											break;
										} else if(money<15000)SlowDisplay("Ǯ����!\n");
										else if(jn_xhys.hadd==1)SlowDisplay("���ѹ������!\n");
										else {
											printf("�㹺�����黯����\n");
											money=money-15000;
											if(cccsss==3)money=999999999;
											jn_xhys.hadd++;
										}
										break;
									case 0:
										SlowDisplay("�´�����!\n");
										break;
									default:
										SlowDisplay("�������\n\n\n");
								}
								break;
							}
							color(11);
							break;
						case 5:
							color(7);
							printf("��װ������һ�����������ͬ����װ����δװ���ģ�:(0,����)\n");
							printf("��������ʲô��\n1.����=>��Ѫ��(500���)2.��Ѫ��=>��������(2000���)3.��������=>����ǧ�Ž�(5000���)\n");
							printf("4.�ۼ�=>����(500���)  5.����=>���ʥ��(2000���)  6.���ʥ��=>����ս���(5000���)\n");
							printf("7.�˻�=>ħ��(500���)  8.ħ��=> ��� (2000���)    9.���=>ڤ�ŲԻ�(5000���)\n\n");
							printf("10.����=>����(500���)11.����=> ��� (2000���)   12.���=>����ʥ��(5000���)\n");
							cin>>st;
							switch(opw(st)) {
								case 1:
									if(money<500)SlowDisplay("Ǯ����!\n");
									else if(gong2n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ��������棬����ʧ��\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										gong2n-=5;
									} else {
										printf("��ʧȥ��������棬�������һ�ѱ�Ѫ��\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										gong2n-=5;
										gong3n++;
									}
									break;
								case 2:
									if(money<2000)SlowDisplay("Ǯ����!\n");
									else if(gong3n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ����ѱ�Ѫ��������ʧ��\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										gong3n-=5;
									} else {
										printf("��ʧȥ����ѱ�Ѫ�����������һ�Ѿ�������\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										gong3n-=5;
										gong4n++;
									}
									break;
								case 3:
									if(money<5000)SlowDisplay("Ǯ����!\n");
									else if(gong4n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ����Ѿ�������������ʧ��\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										gong4n-=5;
									} else {
										printf("��ʧȥ����Ѿ����������������һ������ǧ�Ž�\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										gong4n-=5;
										gong5n++;
									}
									break;
								case 4:
									if(money<500)SlowDisplay("Ǯ����!\n");
									else if(fang2n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ������ۼף�����ʧ��\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										fang2n-=5;
									} else {
										printf("��ʧȥ������ۼף��������һ������\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										fang2n-=5;
										fang3n++;
									}
									break;
								case 5:
									if(money<2000)SlowDisplay("Ǯ����!\n");
									else if(fang3n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ��������ף�����ʧ��\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										fang3n-=5;
									} else {
										printf("��ʧȥ��������ף��������һ�����ʥ��\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										fang3n-=5;
										fang4n++;
									}
									break;
								case 6:
									if(money<5000)SlowDisplay("Ǯ����!\n");
									else if(fang4n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ��������ʥ�£�����ʧ��\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										fang4n-=5;
									} else {
										printf("��ʧȥ��������ʥ�£��������һ������ս���\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										fang4n-=5;
										fang5n++;
									}
									break;
								case 7:
									if(money<500)SlowDisplay("Ǯ����!\n");
									else if(hun1n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ������˻꣬����ʧ��\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										hun1n-=5;
									} else {
										printf("��ʧȥ������˻꣬�������һ��ħ��\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										hun1n-=5;
										hun2n++;
									}
									break;
								case 8:
									if(money<500)SlowDisplay("Ǯ����!\n");
									else if(hun2n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ�����ħ�꣬����ʧ��\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										hun2n-=5;
									} else {
										printf("��ʧȥ�����ħ�꣬�������һ�����\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										hun2n-=5;
										hun3n++;
									}
									break;
								case 9:
									if(money<5000)SlowDisplay("Ǯ����!\n");
									else if(hun3n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ�������꣬����ʧ��\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										hun3n-=5;
									} else {
										printf("��ʧȥ�������꣬�������һ��ڤ�ŲԻ�\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										hun3n-=5;
										hun4n++;
									}
									break;
								case 10:
									if(money<500)SlowDisplay("Ǯ����!\n");
									else if(yan1n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ��������棬����ʧ��\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										yan1n-=5;
									} else {
										printf("��ʧȥ��������棬�������һ������\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										yan1n-=5;
										yan2n++;
									}
									break;
								case 11:
									if(money<2000)SlowDisplay("Ǯ����!\n");
									else if(yan2n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ��������棬����ʧ��\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										yan2n-=5;
									} else {
										printf("��ʧȥ��������棬�������һ�����\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										yan2n-=5;
										yan3n++;
									}
									break;
								case 12:
									if(money<5000)SlowDisplay("Ǯ����!\n");
									else if(yan3n<5)SlowDisplay("���ϲ���!\n");
									else if(rand()%100<5) {
										printf("��ʧȥ�������𣬶���ʧ��\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										yan3n-=5;
									} else {
										printf("��ʧȥ�������𣬶������һ������ʥ��\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										yan3n-=5;
										yan4n++;
									}
									break;
								case 0:
									SlowDisplay("�´�����!\n");
									break;
								default:
									SlowDisplay("�������\n\n\n");
									break;
							}
							color(11);
							break;
						case 6:
							PetsTeach();
							break;
						case 7:
							SlowDisplay("������������Ϸ��������һ���\n\n");
							printf("1,���̿��� 2,ʯͷ������ 3,Ͷɫ�� 4,�һ��� 0,����\n\n");
							cin>>st;
							while(opw(st)>5||opw(st)<1)
								cin>>st;
							switch(opw(st)) {
								case 1:
									printf("���򣺽���50Ԫ�볡�Ѻ�5��ʱ���ھ����ܶ�ĵ�����̣�ÿ���һ�»��1Ԫ���볡�Ѳ��˻����Ƿ������1��������0������\n\n");
									cin>>st;
									if(opw(st)!=1)break;
									else if(money<50) {
										cout<<"Ǯ����\n\n";
										break;
									} else {
										money-=50;
										if(cccsss==3)money=999999999;
										little_game();
									}
									break;
								case 2:
									printf("���򣺷���100ԪѺ��������ʯͷ����������ʤ��һ����ó�������Ǯ,�Ƿ������1��������0������\n\n");
									cin>>st;
									if(opw(st)!=1)break;
									else if(money<100) {
										cout<<"Ǯ����\n\n";
										break;
									} else {
										money-=100;
										if(cccsss==3)money=999999999;
										int ko=rand()%3,ok;
										printf("���ʲô��\n1,ʯͷ 2,���� 3,��\n\n");
										cin>>st;
										while(opw(st)>3||opw(st)<1)
											cin>>st;
										ok=opw(st);
										ok--;
										if(ok==ko) {
											if(ok==2)
												SlowDisplay("����˲�������Ҳ���˲���ƽ�֣�Ѻ���˻�\n\n");
											else if(ok==0)
												SlowDisplay("�����ʯͷ������Ҳ����ʯͷ��ƽ�֣�Ѻ���˻�\n\n");
											else if(ok==1)
												SlowDisplay("����˼���������Ҳ���˼�����ƽ�֣�Ѻ���˻�\n\n");
											money+=100;
											if(cccsss==3)money=999999999;
										} else if((ok==1&&ko==0)||(ok==2&&ko==1)||(ok==0&&ko==2)) {
											if(ok==1) {
												SlowDisplay("����˼��������������ʯͷ������Ӯ�������Ѻ��\n\n");
											} else if(ok==2) {
												SlowDisplay("����˲�����������˼���������Ӯ�������Ѻ��\n\n");
											} else if(ok==0) {
												SlowDisplay("�����ʯͷ����������˲�������Ӯ�������Ѻ��\n\n");
											}
										} else if((ok==2&&ko==0)||(ok==0&&ko==1)||(ok==1&&ko==2)) {
											if(ok==1) {
												SlowDisplay("����˼�������������˲�����Ӯ���˶����Ѻ��\n\n");
											} else if(ok==2) {
												SlowDisplay("����˲������������ʯͷ����Ӯ���˶����Ѻ��\n\n");
											} else if(ok==0) {
												SlowDisplay("�����ʯͷ����������˼�������Ӯ���˶����Ѻ��\n\n");
											}
											money+=200;
											if(cccsss==3)money=999999999;
										}
										break;
									}
								case 3:
									printf("���򣺷���100ԪѺ��������Ͷɫ�ӣ���ʤ��һ����ó�������Ǯ,�Ƿ������1��������0������\n\n");
									cin>>st;
									if(opw(st)!=1)break;
									else if(money<100) {
										cout<<"Ǯ����\n\n";
										break;
									} else {
										money-=100;
										if(cccsss==3)money=999999999;
										int Sez=rand()%6+1,hux[7]= {0,0,0,0,0,0,0};
										printf("�������������(1,2,3or4,5,6)\n\n");
										printf("ѡǰ������������1����������2\n\n");
										cin>>st;
										while(opw(st)>2||opw(st)<1)
											cin>>st;
										if(opw(st)==2)hux[4]=hux[5]=hux[6]=1;
										else hux[1]=hux[2]=hux[3]=1;
										printf("�������С���\n\n");
										Sleep(700);
										SlowDisplay("����ͣ���ˣ�����Ϊ");
										cout<<Sez<<endl<<endl;
										if(hux[Sez]==1) {
											SlowDisplay("���ʤ��Ӯ��200Ԫ\n\n");
											money+=200;
											if(cccsss==3)money=999999999;
										} else {
											SlowDisplay("�����ˣ�����Ӯ�������Ѻ��\n\n");
										}
										break;
									}
								case 4:
									SlowDisplay("�һ�Ҳ��׬Ǯ��\n\n \r \r \rYes\n\n");
									printf("��ѡ��һ��ء���\n\n");
									printf("1,�����һ���(30min,���3000Ԫ��500Ԫ�볡) \n2,ũ��һ���(60min,���30000Ԫ��5000Ԫ�볡) \n3,����һ���(90min,���90000Ԫ��10000Ԫ�볡) \n0,����\n\n");
									cin>>st;
									int spend,time,speed;
									if(opw(st)>3||opw(st)<1)break;
									else {
										if(opw(st)==1) {
											if(money<500)
												printf("���Ǯ����\n\n");
											else money-=500,stay__gj(30,5);
											break;
										} else if(opw(st)==2) {
											if(money<5000)
												printf("���Ǯ����\n\n");
											else money-=5000,stay__gj(60,5);
											break;
										} else if(opw(st)==3) {
											if(money<10000)
												printf("���Ǯ����\n\n");
											else money-=10000,stay__gj(90,50);
											break;
										}
									}
								case 0:
									SlowDisplay("�´�����!\n");
									break;
								default:
									SlowDisplay("�������\n\n\n");
									break;
							}
							break;
						default:
							SlowDisplay("�������\n\n\n");
							break;
					}
					break;
				} else if(place_sign==place.hotel) {
					SlowDisplay("���ϰ���!��...��\n\n\n����æ���أ�û������~��\n\n\n");
					break;
				} else if(place_sign==place.bank) {
					SlowDisplay("������ʲô��\n\n1.��Ǯ    2.ȡǮ    0.����\n\n\n");
					cin>>st;
					switch(opw(st)) {
						case 1: {
							if(cccsss==3)money=999999999;
							printf("��������%dԪ�������ִ�%dԪ,�������٣�\n(���������1000000000��ң����������Ͻ�����)\n\n\n",money,mony);
							cin>>st;
							xiangcun=opw(st);
							if(xiangcun<0)SlowDisplay("�������\n\n");
							else if(xiangcun<=money) {
								SlowDisplay("���Ժ�   \n   \n   \n");
								if(mony+xiangcun>=1000000000)mony=1000000000;
								else mony=mony+xiangcun;
								money=money-xiangcun;
								printf("�����%dԪ\n",xiangcun);
							} else SlowDisplay("��û����ô��Ǯ��\n\n\n");
							break;
						}
						case 2: {
							if(cccsss==3)money=999999999;
							printf("��������%dԪ�������ִ�%dԪ,����ȡ���٣�\n\n\n",money,mony);
							cin>>st;
							xiangcun=opw(st);
							if(xiangcun<0)SlowDisplay("�������\n\n");
							else if(xiangcun<=mony) {
								SlowDisplay("���Ժ�   \n   \n   \n");
								money=money+xiangcun;
								mony=mony-xiangcun;
								printf("��ȡ��%dԪ\n",xiangcun);
							} else SlowDisplay("��û����ô��Ǯ��\n\n\n");
							break;
						}
					}
					break;
				} else {
					int a=rand()%100;
					if(a<=3) {
						b=rand()%100+51;
						money+=b;
						printf("�����%d���\n\n",b);
					} else if(a<=7) {
						b=rand()%11+1;
						switch(b) {
							case 1:
								SlowDisplay("�����һ��ֹѪ��\n\n");
								cao++;
								break;
							case 2:
								SlowDisplay("�����һ�����Ȱ�\n\n");
								jijiubao++;
								break;
							case 3:
								SlowDisplay("�����һ�����ϰ�ҩ\n\n");
								baiyao++;
								break;
							case 4:
								SlowDisplay("�����һ���������ϰ�ҩ\n\n");
								superbaiyao++;
								break;
							case 5:
								SlowDisplay("�����һ��Ԫ����\n\n");
								dan++;
								break;
							case 6:
								SlowDisplay("�����һ�����ɲ�\n\n");
								xiancao++;
								break;
							case 7:
								SlowDisplay("�����һ��������\n\n");
								xlsoup++;
								break;
							case 8:
								SlowDisplay("�����һ������������\n\n");
								superxlsoup++;
								break;
							case 9:
								SlowDisplay("�����һ����ǹ\n\n");
								boom++;
								break;
							case 10:
								SlowDisplay("�����һ������\n\n");
								dubiao++;
								break;
							case 11:
								SlowDisplay("�����һ���������｣\n\n");
								atom_boom++;
								break;
							case 12:
								SlowDisplay("�����һ������������\n\n");
								hlbyr++;
								break;
						}
					} else if(a<=17) {
						int b=rand()%35+1,c=rand()%15+5;
						SlowDisplay("�����");
						cout<<c;
						SlowDisplay("��");
						SlowDisplay(xuan[b].Lvup);
						cout<<endl<<endl;
						xuan[b].Lup+=c;
					} else if(a<=20) {
						int b=rand()%35+1,nu=0;
						for(int i=1; i<=36; i++) {
							if(xuan[i].PN==10)continue;
							if(xuan[i].Hav)nu++;
						}
						if(nu<35) {
							while(xuan[b].Hav) {
								b=rand()%35+1;
								if(xuan[b].PN>=10)b++;
							}
							guai=xian[b];
							color(15);
							printf("�桤%s",xuan[b].name);
							color(12);
							printf("���˳���!\n\n\n");
							battle=1;
							battle_player=player;
							BattleAct();
						} else goto here;
					} else {
here:
						if(place_sign==place.forest1) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=xiyi;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=witch;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.forest2) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=witch;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=strongman;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.forest3) {
							s=SuiJi();
							color(12);
							battle=1;
							if(TTDIE==1)guai=big_strongman;
							else guai=big_strongmanking;
							{
								color(guai.color);
								printf("%s",guai.name);
								color(12);
								printf("���˹���!\n\n\n");
							}
							if(strongman_arm==0&&TTDIE==1)SlowDisplay("ɭ�־�������   �������������ǵ�ʥ��\n\n\n");
							else SlowDisplay("ɭ�־�����֮�棺   ��ʥ�ݻ�������\n\n\n");
							battle_player=player;
							BattleAct();
						} else if(place_sign==place.sea1) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=lie;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=jing;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.sea2) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=jing;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=shark;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.sea3) {
							s=SuiJi();
							color(12);
							battle=1;
							if(FMDIE==1)guai=fishman;
							else guai=fishmanking;
							{
								color(guai.color);
								printf("%s",guai.name);
								color(12);
								printf("���˹���!\n\n\n");
							}
							if(fishman_tail==0&&FMDIE==1)SlowDisplay("�������:   �������������ǵ�ʥˮ\n\n\n");
							else SlowDisplay("�������֮�棺   ��ʥˮ��������\n\n\n");
							battle_player=player;
							BattleAct();
						} else if(place_sign==place.sha1) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=jumang;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=duxie;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.sha2) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=duxie;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=shouhu;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.sha3) {
							s=SuiJi();
							color(12);
							battle=1;
							if(FODIE==1) guai=falao;
							else guai=falaoking;
							{
								color(guai.color);
								printf("%s",guai.name);
								color(12);
								printf("���˹���!\n\n\n");
							}
							if(falao_fire==0&&FODIE==1)SlowDisplay("ɳĮ������:   �������������ǵ�ʥ��\n\n\n");
							else SlowDisplay ("ɳĮ������֮��:   ��ʥ�𻹸�����\n\n\n");
							battle_player=player;
							BattleAct();
						} else if(place_sign==place.grass1) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=bee;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=horse;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.grass2) {
							s=SuiJi();
							if(s<9) {
								color(12);
								battle=1;
								guai=horse;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(12);
								battle=1;
								guai=lion;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else if(place_sign==place.grass3) {
							if((strongman_arm&&fishman_tail&&falao_fire)||DIII) {
								if(kingdie==0) {
									battle=1;
									battle_player=player;
									color(12);
									strongman_arm=0,fishman_tail=0,falao_fire=0;
									if(DIII==1)SlowDisplay("��������:\n\n\n���ֻ����ˣ�\n\n�Ǿ���׼�������ˣ�����\n\n\n");
									else SlowDisplay("��������:\n\n\n    ����,������,���Ĳ���\n\n    ����...\n\n    �ٺ�,���ϵ���!����֮ľ������֮��ͷ���֮����Ҫ��,�����Ҳ�������!\n\n\n");
									guai=shitu1;
									DIII=1;
									color(12);
									{
										color(guai.color);
										printf("%s",guai.name);
										color(12);
										printf("���˹���!\n\n\n");
									}
									BattleAct();
									if(strcmp(guai.name,"��֮ʹͽ")==0) {
										guai=shitu2;
										battle_player=player;
										color(12);
										battle=1;
										{
											color(guai.color);
											printf("%s",guai.name);
											color(12);
											printf("���˹���!\n\n\n");
										}
										BattleAct();
										if(strcmp(guai.name,"ˮ֮ʹͽ")==0) {
											guai=shitu3;
											battle_player=player;
											color(12);
											battle=1;
											printf("%s���˹���!\n\n\n",guai.name);
											BattleAct();
											if(strcmp(guai.name,"��֮ʹͽ")==0) {
												guai=king;
												battle_player=player;
												battle=1;
												color(12);
												SlowDisplay("�ڰ����:\n\n\n    ʲô�������㾹Ȼ�ܻ����ҵ�ʹͽ������\n\n\n\r   \r   \r   \r 	  ������������Ҿ����Ὣ��佻����ģ�����\n\n\n");
												BattleAct();
											}
										}
									}
								}
							} else {
								color(12);
								battle=1;
								guai=lion;
								{
									color(guai.color);
									printf("%s",guai.name);
									color(12);
									printf("���˹���!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else {
							color(10);
							SlowDisplay("����ʲôҲû�С���\n\n");
						}
					}
					break;
				}
			case 4:
				color(11);
				DisplayState();
				break;
			case 5:
				color(11);
				printf("��װ: 1,ذ��:%d��  2,����:%d��  3,��Ѫ��:%d��4,��������:%d��  5,����ǧ�Ž�:%d��\n\n\n",gong1n,gong2n,gong3n,gong4n,gong5n);
				printf("��װ: 6,����:%d��  7,�ۼ�:%d��  8,����:%d��  9,���ʥ��:%d�� 10,����ս���:%d��\n\n\n",fang1n,fang2n,fang3n,fang4n,fang5n);
				printf(" �� :11,�˻�:%d�� 12,ħ��:%d�� 13,���:%d�� 14,ڤ�ŲԻ�:%d��\n\n\n",hun1n,hun2n,hun3n,hun4n);
				printf(" �� :15,����:%d�� 16,����:%d�� 17,���:%d�� 18,����ʥ��:%d��  0,����\n\n\n\n\n\n",yan1n,yan2n,yan3n,yan4n);
				SlowDisplay("ѡ��Ҫװ������۵�װ��:\n\n\n");
				cin>>st;
				switch(opw(st)) {
					case 1:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong1n>=1) {
								SlowDisplay("������ذ��\n\n\n");
								if(strcmp(gongname,"ذ��")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"����")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"��Ѫ��")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"��������")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"����ǧ�Ž�")==0)
									gong5n++,gong-=gong5;
								gong+=gong1;
								gong1n--;
								strcpy(gongname,"ذ��");
							} else SlowDisplay("��û��ذ�׿���װ��\n\n\n");
						} else if(choose_number==0) {
							if(gong1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ��ذ�ף��õ���20���\n\n\n");
									money+=20;
								} else SlowDisplay("��������ǿ������������һ��ذ��\n\n\n");
								gong1n--;
							} else SlowDisplay("��û��ذ�׿��Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 2:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong2n>=1) {
								SlowDisplay("����������\n\n\n");
								if(strcmp(gongname,"ذ��")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"����")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"��Ѫ��")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"��������")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"����ǧ�Ž�")==0)
									gong5n++,gong-=gong5;
								gong+=gong2;
								gong2n--;
								strcpy(gongname,"����");
							} else SlowDisplay("��û���������װ��\n\n\n");
						} else if(choose_number==0) {
							if(gong2n>=js) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�����棬�õ���100���\n\n\n");
									money+=100;
								} else SlowDisplay("��������ǿ������������һ������\n\n\n");
								gong2n--;
							} else SlowDisplay("��û��������Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 3:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong3n>=1) {
								SlowDisplay("�����˱�Ѫ��\n\n\n");
								if(strcmp(gongname,"ذ��")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"����")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"��Ѫ��")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"��������")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"����ǧ�Ž�")==0)
									gong5n++,gong-=gong5;
								gong+=gong3;
								gong3n--;
								strcpy(gongname,"��Ѫ��");
							} else SlowDisplay("��û�б�Ѫ������װ��\n\n\n");
						} else if(choose_number==0) {
							if(gong3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�ѱ�Ѫ�����õ���200���\n\n\n");
									money+=200;
								} else SlowDisplay("��������ǿ������������һ�ѱ�Ѫ��\n\n\n");
								gong3n--;
							} else SlowDisplay("��û�б�Ѫ�����Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 4:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong4n>=1) {
								SlowDisplay("�����˾�������\n\n\n");
								if(strcmp(gongname,"ذ��")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"����")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"��Ѫ��")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"��������")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"����ǧ�Ž�")==0)
									gong5n++,gong-=gong5;
								gong+=gong4;
								gong4n--;
								strcpy(gongname,"��������");
							} else SlowDisplay("��û�о�����������װ��\n\n\n");
						} else if(choose_number==0) {
							if(gong4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�Ѿ����������õ���500���\n\n\n");
									money+=500;
								} else SlowDisplay("��������ǿ������������һ�Ѿ�������\n\n\n");
								gong4n--;
							} else SlowDisplay("��û�о����������Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 5:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong5n>=1) {
								SlowDisplay("����������ǧ�Ž�\n\n\n");
								if(strcmp(gongname,"ذ��")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"����")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"��Ѫ��")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"��������")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"����ǧ�Ž�")==0)
									gong5n++,gong-=gong5;
								gong+=gong5;
								gong5n--;
								strcpy(gongname,"����ǧ�Ž�");
							} else SlowDisplay("��û������ǧ�Ž�����װ��\n\n\n");
						} else if(choose_number==0) {
							if(gong5n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ������ǧ�Ž����õ���1000���\n\n\n");
									money+=1000;
								} else
									SlowDisplay("��������ǿ������������һ������ǧ�Ž�\n\n\n");
								gong5n--;
							} else SlowDisplay("��û������ǧ�Ž����Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 6:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang1n>=1) {
								SlowDisplay("�����˲���\n\n\n");
								if(strcmp(fangname,"����")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"�ۼ�")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"����")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"���ʥ��")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"����ս���")==0)
									fang5n++,fang-=fang5;
								fang+=fang1;
								fang1n--;
								strcpy(fangname,"����");
							} else SlowDisplay("��û�в��¿���װ��\n\n\n");
						} else if(choose_number==0) {
							if(fang1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�����£��õ���20���\n\n\n");
									money+=20;
								} else SlowDisplay("��������ǿ������������һ������\n\n\n");
								fang1n--;
							} else SlowDisplay("��û�в��¿��Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 7:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang2n>=1) {
								SlowDisplay("�������ۼ�\n\n\n");
								if(strcmp(fangname,"����")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"�ۼ�")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"����")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"���ʥ��")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"����ս���")==0)
									fang5n++,fang-=fang5;
								fang+=fang2;
								fang2n--;
								strcpy(fangname,"�ۼ�");
							} else SlowDisplay("��û���ۼ׿���װ��\n\n\n");
						} else if(choose_number==0) {
							if(fang2n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ���ۼף��õ���100���\n\n\n");
									money+=100;
								} else SlowDisplay("��������ǿ������������һ���ۼ�\n\n\n");
								fang2n--;
							} else SlowDisplay("��û���ۼ׿��Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 8:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang3n>=1) {
								SlowDisplay("����������\n\n\n");
								if(strcmp(fangname,"����")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"�ۼ�")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"����")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"���ʥ��")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"����ս���")==0)
									fang5n++,fang-=fang5;
								fang+=fang3;
								fang3n--;
								strcpy(fangname,"����");
							} else SlowDisplay("��û�����׿���װ��\n\n\n");
						} else if(choose_number==0) {
							if(fang3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�����ף��õ���200���\n\n\n");
									money+=200;
								} else SlowDisplay("��������ǿ������������һ������\n\n\n");
								fang3n--;
							} else SlowDisplay("��û�����׿��Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 9:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang4n>=1) {
								SlowDisplay("�����˽��ʥ��\n\n\n");
								if(strcmp(fangname,"����")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"�ۼ�")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"����")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"���ʥ��")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"����ս���")==0)
									fang5n++,fang-=fang5;
								fang+=fang4;
								fang4n--;
								strcpy(fangname,"���ʥ��");
							} else SlowDisplay("��û�н��ʥ�¿���װ��\n\n\n");
						} else if(choose_number==0) {
							if(fang4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�����ʥ�£��õ���500���\n\n\n");
									money+=500;
								} else SlowDisplay("��������ǿ������������һ�����ʥ��\n\n\n");
								fang4n--;
							} else SlowDisplay("��û�н��ʥ�¿��Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 10:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang5n>=1) {
								SlowDisplay("�����˾���ս���\n\n\n");
								if(strcmp(fangname,"����")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"�ۼ�")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"����")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"���ʥ��")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"����ս���")==0)
									fang5n++,fang-=fang5;
								fang+=fang5;
								fang5n--;
								strcpy(fangname,"����ս���");
							} else SlowDisplay("��û�о���ս��׿���װ��\n\n\n");
						} else if(choose_number==0) {
							if(fang5n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ������ս��ף��õ���1000���\n\n\n");
									money+=1000;
								} else
									SlowDisplay("��������ǿ������������һ������ս���\n\n\n");
								fang5n--;
							} else SlowDisplay("��û�о���ս��׿��Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 11:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun1n>=1) {
								SlowDisplay("�������˻�\n\n\n");
								if(strcmp(hunname,"�˻�")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"ħ��")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"���")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"ڤ�ŲԻ�")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun1+gong;
								fang=fang+hun1;
								hun1n--;
								strcpy(hunname,"�˻�");
							} else SlowDisplay("��û���˻����װ��\n\n\n");
						} else if(choose_number==0) {
							if(hun1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ���˻꣬�õ���50���\n\n\n");
									money+=50;
								} else SlowDisplay("��������ǿ������������һ���˻�\n\n\n");
								hun1n--;
							} else SlowDisplay("��û���˻���Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 12:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun2n>=1) {
								SlowDisplay("������ħ��\n\n\n");
								if(strcmp(hunname,"�˻�")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"ħ��")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"���")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"ڤ�ŲԻ�")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun2+gong;
								fang=fang+hun2;
								hun2n--;
								strcpy(hunname,"ħ��");
							} else SlowDisplay("��û��ħ�����װ��\n\n\n");
						} else if(choose_number==0) {
							if(hun2n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ��ħ�꣬�õ���100���\n\n\n");
									money+=100;
								} else SlowDisplay("��������ǿ������������һ��ħ��\n\n\n");
								hun2n--;
							} else SlowDisplay("��û��ħ����Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 13:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun3n>=1) {
								SlowDisplay("���������\n\n\n");
								if(strcmp(hunname,"�˻�")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"ħ��")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"���")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"ڤ�ŲԻ�")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun3+gong;
								fang=fang+hun3;
								hun3n--;
								strcpy(hunname,"���");
							} else SlowDisplay("��û��������װ��\n\n\n");
						} else if(choose_number==0) {
							if(hun3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ����꣬�õ���200���\n\n\n");
									money+=200;
								} else SlowDisplay("��������ǿ������������һ�����\n\n\n");
								hun3n--;
							} else SlowDisplay("��û�������Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 14:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun4n>=1) {
								SlowDisplay("������ڤ�ŲԻ�\n\n\n");
								if(strcmp(hunname,"�˻�")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"ħ��")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"���")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"ڤ�ŲԻ�")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun4+gong;
								fang=fang+hun4;
								hun4n--;
								strcpy(hunname,"ڤ�ŲԻ�");
							} else SlowDisplay("��û��ڤ�ŲԻ����װ��\n\n\n");
						} else if(choose_number==0) {
							if(hun4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ��ڤ�ŲԻ꣬�õ���1000���\n\n\n");
									money+=1000;
								} else
									SlowDisplay("��������ǿ������������һ��ڤ�ŲԻ�\n\n\n");
								hun4n--;
							} else SlowDisplay("��û��ڤ�ŲԻ���Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 15:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan1n>=1) {
								SlowDisplay("�����˺���\n\n\n");
								if(strcmp(yanname,"����")==0)
									yan1n++;
								else if(strcmp(yanname,"����")==0)
									yan2n++;
								else if(strcmp(yanname,"���")==0)
									yan3n++;
								else if(strcmp(yanname,"����ʥ��")==0)
									yan4n++;
								yan=yan1n;
								yann=yan1;
								yan1n--;
								strcpy(yanname,"����");
							} else SlowDisplay("��û�к������װ��\n\n\n");
						} else if(choose_number==0) {
							if(yan1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�����棬�õ���50���\n\n\n");
									money+=50;
								} else SlowDisplay("��������ǿ������������һ������\n\n\n");
								yan1n--;
							} else SlowDisplay("��û�к�����Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 16:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan2n>=1) {
								SlowDisplay("����������\n\n\n");
								if(strcmp(yanname,"����")==0)
									yan1n++;
								else if(strcmp(yanname,"����")==0)
									yan2n++;
								else if(strcmp(yanname,"���")==0)
									yan3n++;
								else if(strcmp(yanname,"����ʥ��")==0)
									yan4n++;
								yan=yan2n;
								yann=yan2;
								yan2n--;
								strcpy(yanname,"����");
							} else SlowDisplay("��û���������װ��\n\n\n");
						} else if(choose_number==0) {
							if(yan2n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ�����棬�õ���100���\n\n\n");
									money+=100;
								} else
									SlowDisplay("��������ǿ������������һ������\n\n\n");
								yan2n--;
							} else SlowDisplay("��û��������Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 17:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan3n>=1) {
								SlowDisplay("�����˹��\n\n\n");
								if(strcmp(yanname,"����")==0)
									yan1n++;
								else if(strcmp(yanname,"����")==0)
									yan2n++;
								else if(strcmp(yanname,"���")==0)
									yan3n++;
								else if(strcmp(yanname,"����ʥ��")==0)
									yan4n++;
								yan=yan3n;
								yann=yan3;
								yan3n--;
								strcpy(yanname,"���");
							} else SlowDisplay("��û�й�����װ��\n\n\n");
						} else if(choose_number==0) {
							if(yan3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ����𣬵õ���200���\n\n\n");
									money+=200;
								} else SlowDisplay("��������ǿ������������һ�����\n\n\n");
								yan3n--;
							} else SlowDisplay("��û�й����Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 18:
						cout<<"������ʲô��\n0.����   1.װ��   2.����\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan4n>=1) {
								SlowDisplay("����������ʥ��\n\n\n");
								if(strcmp(yanname,"����")==0)
									yan1n++;
								else if(strcmp(yanname,"����")==0)
									yan2n++;
								else if(strcmp(yanname,"���")==0)
									yan3n++;
								else if(strcmp(yanname,"����ʥ��")==0)
									yan4n++;
								yan=yan4n;
								yann=yan4;
								yan4n--;
								strcpy(yanname,"����ʥ��");
							} else SlowDisplay("��û������ʥ�����װ��\n\n\n");
						} else if(choose_number==0) {
							if(yan4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("�������һ������ʥ�𣬵õ���1000���\n\n\n");
									money+=1000;
								} else
									SlowDisplay("��������ǿ������������һ������ʥ��\n\n\n");
								yan4n--;
							} else SlowDisplay("��û������ʥ����Գ���\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 0:
						SlowDisplay("δ���в���\n\n\n");
						break;
					default:
						printf("�������!\n");
				}
				break;
			case 0:
				color(6);
				SlowDisplay("ȷ���˳���Ϸ?(Y/N)\n\n\n");
				getchar();
				proof=getchar();
				if(proof=='y'||proof=='Y') {
					char dfg[21];
					strcpy(dfg,player.name);
					int dfgi,dfgo;
					int dfga[21];
					for(dfgi=0; dfgi<strlen(dfg); dfgi++)
						dfga[dfgi]=dfg[dfgi];
					int len=strlen(dfg)-1;
					for(dfgi=len; dfgi>=0; dfgi--)
						dfga[dfgi+1]=abs(dfga[dfgi]);
					dfga[0]=len+1;
					len++;
					for(dfgi=0; dfgi<=len; dfgi++)
						while(dfga[dfgi]>=10) {
							for(dfgo=len; dfgo>=dfgi+1; dfgo--)
								dfga[dfgo+1]=dfga[dfgo];
							dfga[dfgi+1]=dfga[dfgi]%10;
							len++;
							dfga[dfgi]/=10;
						}
					for(dfgi=0; dfgi<=len; dfgi++)
						nammm[dfgi]=dfga[dfgi]+'0';
					nammm[dfgi]='\0';
					strcat(nammm,".Natsu");
					fsave();
					SlowDisplay("���ݴ洢��...");
					Sleep(100);
					massbox("��ʾ","���ݴ洢���",1);
					exit(0);
					return;
				} else if(proof=='n'||proof=='N')printf("������Ϸ!\n\n\n");
				else SlowDisplay("����!\n\n\n");
				break;
			default:
				SlowDisplay("�������!\n\n\n");
		}
	}
}
void DisplayState() {
	if(battle) {
		char Cle[101]="\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                     ";
		if(xuan[0].PN!=0)Cle[0]='\0';
		color(12);
		printf("%s ������:%d+%d=%d  ������:%d+%d=%d  HP:%d/%d PP:%d/%d \n\n\n",battle_player.name,battle_player.attack,gong,battle_player.attack+gong,battle_player.defense,fang,battle_player.defense+fang,battle_player.health,battle_player.max_health,battle_player.PP,battle_player.max_PP);
		printf("�ȼ�:%d  ����:%d/%d ����Ҫ%d�������� ���:%d \n\n\n",battle_player.level,battle_player.exp,battle_player.max_exp,battle_player.max_exp-battle_player.exp,money);
		cout<<"��װ:"<<gongname<<"  ��װ:"<<fangname<<"  �� :"<<hunname<<"  �� :"<<yanname<<" \n\n\n";
		printf("�������:����֮ľ*%d������֮��*%d������֮��*%d��\n\n\n",strongman_arm,fishman_tail,falao_fire);
		printf("�������:ˮ֮��*%d����֮��*%d����֮��*%d����֮��*%d��\n\n\n",shuiling,huoling,tuling,fengling);
		printf("Я������:%s��Lv.%d�����ܣ�%s%s������%d.%s\n\n\n",xuan[0].chu,xuan[0].level,xuan[0].PNm,Roman[(xuan[0].level+9)/10],xuan[0].attack,Cle);
	} else {
		char Cle[101]="\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                     ";
		if(xuan[0].PN!=0)Cle[0]='\0';
		color(11);
		printf("%s ������:%d+%d=%d  ������:%d+%d=%d  HP:%d/%d PP:%d/%d \n\n\n",player.name,player.attack,gong,player.attack+gong,player.defense,fang,player.defense+fang,player.health,player.max_health,player.PP,player.max_PP);
		printf("�ȼ�:%d  ����:%d/%d ����Ҫ%d�������� ���:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money);
		cout<<"��װ:"<<gongname<<"  ��װ:"<<fangname<<"  �� :"<<hunname<<"  �� :"<<yanname<<" \n\n\n";
		printf("�������:����֮ľ*%d������֮��*%d������֮��*%d��\n\n\n",strongman_arm,fishman_tail,falao_fire);
		printf("�������:ˮ֮��*%d����֮��*%d����֮��*%d����֮��*%d��\n\n\n",shuiling,huoling,tuling,fengling);
		printf("����:%s��%s��%s��%s��\n\n\n",jn_1.name,jn_2.name,jn_3.name,jn_4.name);
		printf("Я������:%s��Lv.%d�����ܣ�%s%s������%d.%s\n\n\n",xuan[0].chu,xuan[0].level,xuan[0].PNm,Roman[(xuan[0].level+9)/10],xuan[0].attack,Cle);
	}
}
void BattleAct() {
	hh=6;
	xuan[37]=xuan[0];
	suran=0;
	guai.attack=guai.attack+rand()%(guai.attack/5)-guai.attack/10;
	guai.defense=guai.defense+rand()%(guai.defense/5)-guai.defense/10;
	guai.health=guai.health+rand()%(guai.health/5)-guai.health/10;
	if(guai.exp>5)
		guai.exp=guai.exp+rand()%(guai.exp/5)-guai.exp/10;
	BrBow=BrMis=Kill=Wory=Fire=Elec=Sick=Ice=Slp=Squid=Gun=Blood=Death=MgcHalf=PhyHalf=Bkll=0;
	if(xuan[37].PN==-3) {
		guai.defense*=6;
		guai.defense/=5;
	} else if(xuan[37].PN==-6) {
		battle_player.miss*=6;
		battle_player.miss/=5;
	} else if(xuan[37].PN==-11) {
		player.defense*=8;
		player.defense/=7;
		player.attack*=8;
		player.attack/=7;
	} else if(xuan[37].PN==-17) {
		player.defense*=5;
		player.defense/=4;
	} else if(xuan[37].PN==14) {
		guai.defense*=6;
		guai.defense/=5;
		guai.miss*=8;
		guai.miss/=7;
	} else if(xuan[37].PN==15) {
		battle_player.miss*=8;
		battle_player.miss/=7;
	} else if(xuan[37].PN==-9) {
		guai.Frr*=7;
		guai.Frr/=5;
	}
	int Lg=0,Lf=0;
	while(battle) {
		if(xuan[37].PN==-12) {
			battle_player.attack-=Lg;
			Lg=(battle_player.max_health-battle_player.health)*3;
			battle_player.attack+=Lg*5;
		} else if(xuan[37].PN==-13) {
			battle_player.defense-=Lf;
			Lf=(battle_player.max_health-battle_player.health)*3;
			battle_player.defense+=Lf*5;
		} else if(xuan[37].PN==-14) {
			battle_player.attack*=(hh-1);
			battle_player.attack/=(hh-2);
			battle_player.attack*=hh;
			battle_player.attack/=(hh-1);
		} else if(xuan[37].PN==-2) {
			xuan[37].attack*=(hh-1);
			xuan[37].attack/=(hh-2);
			xuan[37].attack*=hh;
			xuan[37].attack/=(hh-1);
			battle_player.attack*=(hh-1);
			battle_player.attack/=(hh-2);
			battle_player.attack*=hh;
			battle_player.attack/=(hh-1);
		} else if(xuan[37].PN==19) {
			battle_player.defense*=(hh-1);
			battle_player.defense/=(hh-2);
			battle_player.defense*=hh;
			battle_player.defense/=(hh-1);
		}
		color(12);
		puts("===================================================================================");
		printf("Ҫ��ô��?\n\n\n    1,���� 2,��Ʒ 3,�鿴״̬ 4,����\n\n\n");
		cin>>st;
		switch(opw(st)) {
			case 1:
				printf("===================================================================================");
				printf("\n\nѡ���ܷ���\n\n1,%s :%s\n\n2,%s :%s(PP��%d)\n\n3,%s :%s(PP��%d)\n\n4,%s :%s(PP��%d)\n\n5,%s :%s(PP��%d)\n\n0,����\n",jn_0.name,jn_0.xxx,jn_1.name,jn_1.xxx,jn_1.pp,jn_2.name,jn_2.xxx,jn_2.pp,jn_3.name,jn_3.xxx,jn_3.pp,jn_4.name,jn_4.xxx,jn_4.pp);
				printf("===================================================================================");
				cin>>st;
				if(opw(st)==0)break;
				choose_jn();
				if(AttackResult())return;
				else continue;
			case 2:
				ChooseWupin();
				break;
			case 3:
				DisplayState();
				break;
			case 4:
				if(guai.boss_)
					SlowDisplay("BOSS��ս��������\n\n\n");
				else {
					s=SuiJi();
					if(s<4) {
						printf("%s������~\n\n\n",player.name);
						player.health=battle_player.health;
						player.PP=battle_player.PP;
						battle=0;
						return;
					} else {
						printf("%s����ʧ��!\n\n\n",player.name);
						AttackResult();
					}
				}
				break;
			default:
				SlowDisplay("�������,��������!\n\n\n");
		}
	}
}
void SlowDisplay(const char *p) {
	while(1) {
		if(*p!=0)
			printf("%c",*p++);
		else break;
		Sleep(30);
	}
}
void choose_jn() {
	cout<<endl;
	choose_number=opw(st);
	if(choose_number==1) {
		hh++;
		maybe=rand()%100;
		if(maybe<guai.miss)
			printf("%s����!\n\n\n",guai.name);
		else {
			maybe=rand()%100;
			if(maybe<battle_player.baoji) {
				maybe=(rand()%100+100)/100;
				if((battle_player.attack+gong-guai.defense/3)*1.8<=0||(battle_player.attack+gong-guai.defense)/3*18/10<=0) {
					printf("%s����! %s����1HP\n\n\n",player.name,guai.name);
					guai.health-=1;
					if(guai.health>=1)
						printf("%s����%dHP\n\n",guai.name,guai.health);
				} else if((battle_player.attack+gong-guai.defense)/3*9/5>0) {
					printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,min((battle_player.attack+gong-guai.defense/3)*9/5,guai.health));
					guai.health-=min((battle_player.attack+gong-guai.defense/3)*9/5,guai.health);
					if(guai.health>0)printf("%s����%dHP\n\n",guai.name,guai.health);
				}
			} else {
				s=SuiJi();
				if(battle_player.attack+s+gong-guai.defense/3<=0) {
					printf("%s����! %s����1HP\n\n\n",player.name,guai.name);
					guai.health-=1;
					if(guai.health>=1)
						printf("%s����%dHP\n\n",guai.name,guai.health);
				} else {
					printf("%s����! %s����%dHP\n\n\n",player.name,guai.name,min(guai.health,battle_player.attack+s+gong-guai.defense/3));
					guai.health-=min(guai.health,battle_player.attack+s+gong-guai.defense/3);
					if(guai.health>0)printf("%s����%dHP\n\n",guai.name,guai.health);
				}
			}
		}
	} else {
		switch(choose_number) {
			case 2:
				if(jn_1.num&&battle_player.PP>=jn_1.pp)jn_=jn_1;
				else if(battle_player.PP<=jn_1.pp) {
					printf("PP����,������ѡ��");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("������ѡ��");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			case 3:
				if(jn_2.num&&battle_player.PP>=jn_2.pp)jn_=jn_2;
				else if(battle_player.PP<=jn_2.pp) {
					printf("PP����,������ѡ��");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("������ѡ��");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			case 4:
				if(jn_3.num&&battle_player.PP>=jn_3.pp)jn_=jn_3;
				else if(battle_player.PP<=jn_3.pp) {
					printf("PP����,������ѡ��");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("������ѡ��");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			case 5:
				if(jn_4.num&&battle_player.PP>=jn_4.pp)jn_=jn_4;
				else if(battle_player.PP<=jn_4.pp) {
					printf("PP����,������ѡ��");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("������ѡ��");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			default:
				printf("������ѡ��");
				cin>>st;
				choose_jn();
				return;
		}
		printf("%s�����˼���%s\n\n",player.name,jn_.name);
		hh++;
		int aggg=0,dgggg=0;
		battle_player.PP-=jn_.pp;
		if(jn_.PP_back!=0) {
			aggg=rand()%101-50;
			battle_player.PP+=min(battle_player.max_PP-battle_player.PP,jn_.PP_back+aggg);
		}
		if(jn_.HP_back!=0) {
			dgggg=rand()%201-100;
			battle_player.health+=min(battle_player.max_health-battle_player.health,jn_.HP_back+dgggg);
		}
		if(battle_player.PP>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
		if(battle_player.health>battle_player.max_health)battle_player.health=battle_player.max_health;
		if(jn_.baoji_jc)BrBow=2;
		if(jn_.jupao) {
			printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,min((battle_player.attack+gong-guai.defense/3)*18/5,guai.health));
			guai.health-=min((battle_player.attack+gong-guai.defense/3)*18/5,guai.health);
			if(guai.health>=1)printf("%s����%dHP\n\n",guai.name,guai.health);
		}
		if(jn_.xixe) {
			int b=rand()%100-50;
			printf("%s������%s%dHP��������ȡ��%dHP\n\n\n",player.name,guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health),min(battle_player.max_health-battle_player.health,(min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health)/2+b)));
			guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health);
			battle_player.health+=min(battle_player.max_health-battle_player.health,(min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health)/2+b));
			if(guai.health>=1)printf("%s����%dHP\n\n",guai.name,guai.health);
		}
		if(jn_.huimie) {
			if(rand()%10<3&&guai.boss_==0) {
				guai.health=0;
				printf("%s����ɱ\n\n\n",guai.name);
			} else {
				printf("%s����HP%d\n\n\n",guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*18/5,guai.health));
				guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*18/5,guai.health);
			}
			if(guai.health>=1)printf("%s����%dHP\n\n",guai.name,guai.health);
		}
		if(jn_.num==19) {
			printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health));
			guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health);
			if(dgggg<0) {
				printf("%s�����ܵ�%6d���˺�\n\n\n",player.name,0-dgggg);
				battle_player.health+=dgggg;
				if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
					SlowDisplay("�ṫ�㷢��<а��>,�����ܵ��˺���Ч��\n\n");
					battle_player.health==dgggg;
				}
				dgggg=0;
			}
			if(guai.health>=1)printf("%s����%dHP\n\n",guai.name,guai.health);
		}
		if(jn_.fajian) {
			MgcHalf=3;
		} else if(jn_.wujian) {
			PhyHalf=3;
		} else if(jn_.fantan) {
			Bkll=jn_.fantan;
		} else if(jn_.baoji_jc) {
			BrBow=2;
		} else if(jn_.num<9) {
			{
				maybe=rand()%100;
				if(maybe<battle_player.baoji) {
					maybe=(rand()%100+100)/100;
					if((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*1.4<=0) {
						printf("%s����! %s����1HP\n\n\n",player.name,guai.name);
						guai.health-=1;
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s��������\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s������\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s���ж���\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s�ж���\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s���Ի���\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s�Ի���\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s��������\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s��˯����\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s˯����\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s��������\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s�������\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s�����\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s�ֻ�����\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s������\n\n",guai.name);
							Sick=3;
						}
						if(guai.health>=1)printf("%s����%6dHP\n\n",guai.name,guai.health);
					} else {
						printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health));
						guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health);
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s��������\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s������\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s���ж���\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s�ж���\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s���Ի���\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s�Ի���\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s��������\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s��˯����\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s˯����\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s��������\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s�������\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s�����\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s�ֻ�����\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s������\n\n",guai.name);
							Sick=3;
						}
						if(guai.health>0)printf("%s����%6dHP\n\n",guai.name,guai.health);
					}
				} else {
					s=SuiJi();
					if(battle_player.attack+jn_.attack_jc+s+gong-guai.defense/3<=0) {
						printf("%s����! %s����1HP\n\n\n",player.name,guai.name);
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s��������\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s������\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s���ж���\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s�ж���\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s���Ի���\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s�Ի���\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s��������\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s��˯����\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s˯����\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s��������\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s�������\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s�����\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s�ֻ�����\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s������\n\n",guai.name);
							Sick=3;
						}
						guai.health-=1;
						if(guai.health>=1)printf("%s����%6dHP\n\n",guai.name,guai.health);
					} else {
						int a=min(guai.health,battle_player.attack+jn_.attack_jc+gong-guai.defense/3);
						printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,a);
						guai.health-=a;
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s��������\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s������\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s���ж���\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s�ж���\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s���Ի���\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s�Ի���\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s��������\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s��˯����\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s˯����\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s�ֱ�������\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s��������\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s�������\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s�����\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s�ֻ�����\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s������\n\n",guai.name);
							Sick=3;
						}
						if(guai.health>=0)printf("%s����%6dHP\n\n",guai.name,guai.health);
					}
				}
			}
		}
	}
	if(xuan[0].PN!=0&&guai.health>0) {
		if(rand()%100+1<=xuan[37].Baif) {
			int mum=xuan[0].PN;
			if(xuan[0].PN==17)mum=rand()%9+1;
			switch(mum) {
				case -1: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<���>���Ե��������");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)/3+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)/3+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("���˺�\n\n");
					break;
				}
				break;
				case -4: {
					int agn=rand()%40+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>���Ե��������");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)/3+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)/3+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("���˺�\n\n");
					agn=rand()%50;
					if(agn<30) {
						SlowDisplay(",����ɵ�������\n\n");
						Fire+=2;
					}
					break;
				}
				break;
				case -5: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<Ͷ��>���Ե��������");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)/3+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)/3+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("���˺�\n\n");
					if(battle_player.miss<=86)
						battle_player.miss+=4;
					else battle_player.miss=90;
					break;
				}
				case -7: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>����ظ���");
					cout<<min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					battle_player.health+=min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					SlowDisplay("��HP\n\n");
					break;
				}
				case -8:
					printf("%s",xuan[0].name);
					SlowDisplay("����<�>");
					if(guai.color==9) {
						cout<<"������ͶԷ��Ĺ���������\n\n";
						guai.attack*=4;
						guai.attack/=7;
						guai.defense*=4;
						guai.defense/=7;
					} else cout<<"ȴ��û��ʲô��\n\n";
					break;
				case -15: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<��Ծ>���Ե��������");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min(guai.health,(xuan[37].attack-guai.defense)/4*3+agn);
						guai.health-=min(guai.health,(xuan[37].attack-guai.defense)/4*3+agn);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("���˺�\n\n");
					break;
				}
				case 1:
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>������˯����\n\n");
					Slp+=2;
					break;
				case 2:
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>�����˹����½���\n\n");
					guai.attack*=5;
					guai.attack/=7;
					break;
				case 3:
					printf("%s",xuan[0].name);
					SlowDisplay("����<��ս>�����˷����½���\n\n");
					guai.defense*=5;
					guai.defense/=7;
					break;
				case 4:
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>�����˹����ͷ����½���\n\n");
					guai.defense*=6;
					guai.defense/=7;
					guai.attack*=6;
					guai.attack/=7;
					break;
				case 5: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>����ظ���");
					cout<<min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					battle_player.health+=min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					SlowDisplay("��HP\n\n");
					break;
				}
				break;
				case 6:
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>����ұ�����������\n\n");
					if(battle_player.baoji<=86)
						battle_player.baoji+=4;
					else battle_player.baoji=90;
					break;
				case 7:
					printf("%s",xuan[0].name);
					SlowDisplay("����<��Ȼ>\n\n");
					suran=1;
					break;
				case 8:
					printf("%s",xuan[0].name);
					SlowDisplay("����<˹��>����ҹ���������\n\n");
					battle_player.baoji*=5;
					battle_player.attack/=4;
					break;
				case 9:
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>");
					if(guai.color==12) {
						cout<<"������ͶԷ��Ĺ���\n\n";
						guai.attack*=4;
						guai.attack/=7;
					} else cout<<"ȴ��û��ʲô��\n\n";
					break;
				case 10: {
					int agn=rand()%40+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>�������Ե��������");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)*3/2+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)*3/2+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("���˺�,����������ҵĹ���������\n\n");
					battle_player.attack=battle_player.attack*11/10;
					battle_player.defense=battle_player.defense*11/10;
					break;
				}
				case 11: {
					int agn=rand()%40+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<ˮ��>���Ե��������");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)*5/4+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)*5/4+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("���˺�\n\n");
					break;
				}
				case 12: {
					int agn=rand()%5+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>\n\n");
					if(agn<3)cout<<"ȴʲôҲû�з���\n\n";
					else if(agn<4) {
						Fire+=2;
						cout<<"����������\n\n";
					} else if(agn<5) {
						Elec+=2;
						cout<<"���������\n\n";
					} else if(agn<6) {
						Ice+=2;
						cout<<"���˱�������\n\n";
					}
					break;
				}
				case 18: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("����<����>����ظ���");
					cout<<min(xuan[37].attack/10+agn,battle_player.max_PP-battle_player.PP);
					battle_player.health+=min(xuan[37].attack/10+agn,battle_player.max_PP-battle_player.PP);
					SlowDisplay("��PP\n\n");
					break;
				}
				break;
				default:
					if(xuan[37].Hav!=0) {
						int agn=rand()%50;
						SlowDisplay(xuan[37].name);
						if(rand()%100>=xuan[37].baoji) {
							SlowDisplay("���������������");
							cout<<min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
							guai.health-=min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
							SlowDisplay("�㹥��\n\n");
						} else {
							SlowDisplay("���������������");
							cout<<min(guai.health,(abs(xuan[37].attack-guai.defense)/3+agn)*9/5);
							guai.health-=min(guai.health,(abs(xuan[37].attack-guai.defense)/3+agn)*9/5);
							SlowDisplay("�㹥��\n\n");
						}
					}
					break;
			}
		} else {
			if(xuan[37].Hav!=0) {
				int agn=rand()%50;
				SlowDisplay(xuan[37].name);
				if(rand()%100>=xuan[37].baoji) {
					SlowDisplay("���������������");
					cout<<min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
					guai.health-=min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
					SlowDisplay("�㹥��\n\n");
				} else {
					SlowDisplay("���������������");
					cout<<min((abs(xuan[37].attack-guai.defense)/3+agn)*9/5,guai.health);
					guai.health-=min((abs(xuan[37].attack-guai.defense)/3+agn)*9/5,guai.health);
					SlowDisplay("�㹥��\n\n");
				}
			}
		}
	}
}
void jn_gai() {
	int i=0;
	printf("===================================================================================\n");
	if(jn_jszz.hadd==1&&jn_jszz.haddd==0)i++;
	if(jn_mtdz.hadd==1&&jn_mtdz.haddd==0)i++;
	if(jn_mhsx.hadd==1&&jn_mhsx.haddd==0)i++;
	if(jn_xhly.hadd==1&&jn_xhly.haddd==0)i++;
	if(jn_nljt.hadd==1&&jn_nljt.haddd==0)i++;
	if(jn_phsg.hadd==1&&jn_phsg.haddd==0)i++;
	if(jn_hdjt.hadd==1&&jn_hdjt.haddd==0)i++;
	if(jn_kghw.hadd==1&&jn_kghw.haddd==0)i++;
	if(jn_jpzs.hadd==1&&jn_jpzs.haddd==0)i++;
	if(jn_getb.hadd==1&&jn_getb.haddd==0)i++;
	if(jn_htmd.hadd==1&&jn_htmd.haddd==0)i++;
	if(jn_lpjq.hadd==1&&jn_lpjq.haddd==0)i++;
	if(jn_lztx.hadd==1&&jn_lztx.haddd==0)i++;
	if(jn_zszs.hadd==1&&jn_zszs.haddd==0)i++;
	if(jn_hgfz.hadd==1&&jn_hgfz.haddd==0)i++;
	if(jn_xjzq.hadd==1&&jn_xjzq.haddd==0)i++;
	if(jn_gzpz.hadd==1&&jn_gzpz.haddd==0)i++;
	if(jn_tqtb.hadd==1&&jn_tqtb.haddd==0)i++;
	if(jn_jjcj.hadd==1&&jn_jjcj.haddd==0)i++;
	if(jn_jmfs.hadd==1&&jn_jmfs.haddd==0)i++;
	if(jn_scfs.hadd==1&&jn_scfs.haddd==0)i++;
	if(jn_xhys.hadd==1&&jn_xhys.haddd==0)i++;
	printf("\n��ɫ����Ϊ����ӵ�ж�δѧ���������˵ļ��ܣ������뼼��������ѧϰ��\n");
	color(8);
	if(jn_jszz.hadd==1&&jn_jszz.haddd==0)color(14);
	printf("1,��������:Ͷ��������������\n");
	color(8);
	if(jn_mtdz.hadd==1&&jn_mtdz.haddd==0)color(14);
	printf("2,���춾��:ʹ�Է��ж�\n");
	color(8);
	if(jn_mhsx.hadd==1&&jn_mhsx.haddd==0)color(14);
	printf("3,�Ի�����:ʹ�Է��Ի�\n");
	color(8);
	if(jn_xhly.hadd==1&&jn_xhly.haddd==0)color(14);
	printf("4,�ǻ���ԭ:ʹ�Է�����\n");
	color(8);
	if(jn_nljt.hadd==1&&jn_nljt.haddd==0)color(14);
	printf("5,ŭ�׾���:ʹ�Է����\n");
	color(8);
	if(jn_phsg.hadd==1&&jn_phsg.haddd==0)color(14);
	printf("6,�ƻ�����:ʹ�Է�����\n");
	color(8);
	if(jn_hdjt.hadd==1&&jn_hdjt.haddd==0)color(14);
	printf("7,��������:ʹ�Է�����\n");
	color(8);
	if(jn_kghw.hadd==1&&jn_kghw.haddd==0)color(14);
	printf("8,�ݹǺ���:ʹ�Է�����\n");
	color(8);
	if(jn_jpzs.hadd==1&&jn_jpzs.haddd==0)color(14);
	printf("9,����֮��:�޷����ܣ��ض�����\n");
	color(8);
	if(jn_getb.hadd==1&&jn_getb.haddd==0)color(14);
	printf("10,��Ѫ����:�������˲���ȡ����һ��HP\n");
	color(8);
	if(jn_htmd.hadd==1&&jn_htmd.haddd==0)color(14);
	printf("11,�������:�㾡ȫ������ɼ�����˺�����һ��������ɱ����BOSS��Ч��\n");
	color(8);
	if(jn_lpjq.hadd==1&&jn_lpjq.haddd==0)color(14);
	printf("12,���̾���:�ܹ��ظ�����PP\n");
	color(8);
	if(jn_lztx.hadd==1&&jn_lztx.haddd==0)color(14);
	printf("13,��֮��Ϣ:�ܹ��ظ�����PP\n");
	color(8);
	if(jn_zszs.hadd==1&&jn_zszs.haddd==0)color(14);
	printf("14,����֮��:�ܹ��ظ�����HP\n");
	color(8);
	if(jn_hgfz.hadd==1&&jn_hgfz.haddd==0)color(14);
	printf("15,�عⷵ��:�ܹ��ظ�����HP\n");
	color(8);
	if(jn_xjzq.hadd==1&&jn_xjzq.haddd==0)color(14);
	printf("16,Ѫ��֮��:�ܹ�����PP,����Ҫһ����HP��Ϊ����\n");
	color(8);
	if(jn_gzpz.hadd==1&&jn_gzpz.haddd==0)color(14);
	printf("17,��֮����:3�غ��ڣ�����һ��ħ���˺�\n");
	color(8);
	if(jn_tqtb.hadd==1&&jn_tqtb.haddd==0)color(14);
	printf("18,ͭǽ����:3�غ��ڣ�����һ�������˺�\n");
	color(8);
	if(jn_jjcj.hadd==1&&jn_jjcj.haddd==0)color(14);
	printf("19,�������:ɱ�������ߣ�������Ҳ���ܵ�һ�����˺�\n");
	color(8);
	if(jn_jmfs.hadd==1&&jn_jmfs.haddd==0)color(14);
	printf("20,���淴��:�ܽ��Է����غ϶�����˺������ص�������\n");
	color(8);
	if(jn_scfs.hadd==1&&jn_scfs.haddd==0)color(14);
	printf("21,˫�ط���:�ܽ��Է����غ϶�����˺�˫�������ص�������\n");
	color(8);
	if(jn_xhys.hadd==1&&jn_xhys.haddd==0)color(14);
	printf("22,�黯����:2�غ��ڵ��������ʽ���90%��������Ҳ����˼������\n");
	color(8);
	printf("0,����");
	color(11);
	printf("\n===================================================================================\n");
	cin>>st;
	choose_number=opw(st);
	switch(choose_number) {
		case 0:
			return;
		case 1:
			if(jn_jszz.hadd==1&&jn_jszz.haddd==0) {
				jn_=jn_jszz;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 2:
			if(jn_mtdz.hadd==1&&jn_mtdz.haddd==0) {
				jn_=jn_mtdz;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 3:
			if(jn_mhsx.hadd==1&&jn_mhsx.haddd==0) {
				jn_=jn_mhsx;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 4:
			if(jn_xhly.hadd==1&&jn_xhly.haddd==0) {
				jn_=jn_xhly;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 5:
			if(jn_nljt.hadd==1&&jn_nljt.haddd==0) {
				jn_=jn_nljt;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 6:
			if(jn_phsg.hadd==1&&jn_phsg.haddd==0) {
				jn_=jn_phsg;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 7:
			if(jn_hdjt.hadd==1&&jn_hdjt.haddd==0) {
				jn_=jn_hdjt;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 8:
			if(jn_kghw.hadd==1&&jn_kghw.haddd==0) {
				jn_=jn_kghw;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 9:
			if(jn_jpzs.hadd==1&&jn_jpzs.haddd==0) {
				jn_=jn_jpzs;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 10:
			if(jn_getb.hadd==1&&jn_getb.haddd==0) {
				jn_=jn_getb;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 11:
			if(jn_htmd.hadd==1&&jn_htmd.haddd==0) {
				jn_=jn_htmd;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 12:
			if(jn_lpjq.hadd==1&&jn_lpjq.haddd==0) {
				jn_=jn_lpjq;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 13:
			if(jn_lztx.hadd==1&&jn_lztx.haddd==0) {
				jn_=jn_lztx;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 14:
			if(jn_zszs.hadd==1&&jn_zszs.haddd==0) {
				jn_=jn_zszs;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 15:
			if(jn_hgfz.hadd==1&&jn_hgfz.haddd==0) {
				jn_=jn_hgfz;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 16:
			if(jn_xjzq.hadd==1&&jn_xjzq.haddd==0) {
				jn_=jn_xjzq;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 17:
			if(jn_gzpz.hadd==1&&jn_gzpz.haddd==0) {
				jn_=jn_gzpz;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 18:
			if(jn_tqtb.hadd==1&&jn_tqtb.haddd==0) {
				jn_=jn_tqtb;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 19:
			if(jn_jjcj.hadd==1&&jn_jjcj.haddd==0) {
				jn_=jn_jjcj;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 20:
			if(jn_jmfs.hadd==1&&jn_jmfs.haddd==0) {
				jn_=jn_jmfs;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 21:
			if(jn_scfs.hadd==1&&jn_scfs.haddd==0) {
				jn_=jn_scfs;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
		case 22:
			if(jn_xhys.hadd==1&&jn_xhys.haddd==0) {
				jn_=jn_xhys;
				changejn();
			} else printf("��û��������ܡ���\n\n");
			break;
	}
}
void changejn() {
	printf("\n===================================================================================\n");
	printf("��ѡ��һ�������滻:\n");
	printf("1:%s:%s\n",jn_1.name,jn_1.xxx);
	printf("2:%s:%s\n",jn_2.name,jn_2.xxx);
	printf("3:%s:%s\n",jn_3.name,jn_3.xxx);
	printf("4:%s:%s\n",jn_4.name,jn_4.xxx);
	printf("0:����\n");
	int chose;
	cin>>st;
	chose=opw(st);
	if(chose==0)return;
	switch(choose_number) {
		case 1:
			jn_jszz.haddd=1;
			break;
		case 2:
			jn_mtdz.haddd=1;
			break;
		case 3:
			jn_mhsx.haddd=1;
			break;
		case 4:
			jn_xhly.haddd=1;
			break;
		case 5:
			jn_nljt.haddd=1;
			break;
		case 6:
			jn_phsg.haddd=1;
			break;
		case 7:
			jn_hdjt.haddd=1;
			break;
		case 8:
			jn_kghw.haddd=1;
			break;
		case 9:
			jn_jpzs.haddd=1;
			break;
		case 10:
			jn_getb.haddd=1;
			break;
		case 11:
			jn_htmd.haddd=1;
			break;
		case 12:
			jn_lpjq.haddd=1;
			break;
		case 13:
			jn_lztx.haddd=1;
			break;
		case 14:
			jn_zszs.haddd=1;
			break;
		case 15:
			jn_hgfz.haddd=1;
			break;
		case 16:
			jn_xjzq.haddd=1;
			break;
		case 17:
			jn_gzpz.haddd=1;
			break;
		case 18:
			jn_tqtb.haddd=1;
			break;
		case 19:
			jn_jjcj.haddd=1;
			break;
		case 20:
			jn_jmfs.haddd=1;
			break;
		case 21:
			jn_scfs.haddd=1;
			break;
		case 22:
			jn_xhys.haddd=1;
			break;
	}
	switch(chose) {
		case 1:
			choose_number=jn_1.num;
			jn_1=jn_;
			break;
		case 2:
			choose_number=jn_2.num;
			jn_2=jn_;
			break;
		case 3:
			choose_number=jn_3.num;
			jn_3=jn_;
			break;
		case 4:
			choose_number=jn_4.num;
			jn_4=jn_;
			break;
		default:
			SlowDisplay("�������\n\n\n");
	}
	switch(choose_number) {
		case 1:
			jn_jszz.haddd=0;
			break;
		case 2:
			jn_mtdz.haddd=0;
			break;
		case 3:
			jn_mhsx.haddd=0;
			break;
		case 4:
			jn_xhly.haddd=0;
			break;
		case 5:
			jn_nljt.haddd=0;
			break;
		case 6:
			jn_phsg.haddd=0;
			break;
		case 7:
			jn_hdjt.haddd=0;
			break;
		case 8:
			jn_kghw.haddd=0;
			break;
		case 9:
			jn_jpzs.haddd=0;
			break;
		case 10:
			jn_getb.haddd=0;
			break;
		case 11:
			jn_htmd.haddd=0;
			break;
		case 12:
			jn_lpjq.haddd=0;
			break;
		case 13:
			jn_lztx.haddd=0;
			break;
		case 14:
			jn_zszs.haddd=0;
			break;
		case 15:
			jn_hgfz.haddd=0;
			break;
		case 16:
			jn_xjzq.haddd=0;
			break;
		case 17:
			jn_gzpz.haddd=0;
			break;
		case 18:
			jn_tqtb.haddd=0;
			break;
		case 19:
			jn_jjcj.haddd=0;
			break;
		case 20:
			jn_jmfs.haddd=0;
			break;
		case 21:
			jn_scfs.haddd=0;
			break;
		case 22:
			jn_xhys.haddd=0;
			break;
	}
	OrdinaryAct();
}
void PetsTeach() {
	if(Hpet==0) {
		SlowDisplay("ѱ�޴�ʦ�����������̸�����Ǹ���ʿ��\n\n");
		SlowDisplay(player.name);
		SlowDisplay("���ǵ�\n\nѱ�޴�ʦ��Ŷ���������ʵ����Ҫ�������Ҳ��Ҫ�����ɣ��ǳ�����Ǹ��������ˣ��ҿ�������һֻ\n\n");
		SlowDisplay("��������ĳ�������ѡһֻ��\n\n");
		int t=0;
		Hpet=1;
		for(int i=1; i<=36; i++) {
			if(xuan[i].PN==10) {
				t=1;
				continue;
			}
			printf("%d,%s��%s(%s)\n",i-t,xuan[i].name,xuan[i].PNm,xuan[i].XM);
			xuan[i].Lup+=20;
		}
		xuan[27].Lup+=20;
		cin>>st;
		while(opw(st)>=36||opw(st)<=0) {
			printf("����˵ɶ��\n\n");
			cin>>st;
		}
		t=opw(st);
		if(xuan[t].PN>=10)t++;
		xuan[t].Hav=1;
		xuan[t].level=1;
		SlowDisplay("������");
		SlowDisplay(xuan[t].name);
		SlowDisplay("\nѱ�޴�ʦ���������������ǵĽ��׵��ߣ��ú�\n\n���⣬������׵���Ҳ��������ѯ��Ŷ\n\n");
	} else {
		while(1) {
			int an=0;
			for(int i=18; i<=26; i++) {
				an+=xuan[i].Hav;
			}
			if(an>=3&&xuan[27].Hav==0) {
				SlowDisplay("ѱ�޴�ʦ��С�û�����������㾹Ȼ����˾������������\n\n");
				SlowDisplay("ѱ�޴�ʦ��������,���Ҫ������׼����\n\n");
				SlowDisplay("��������һ����̳ǰ");
				for(int i=18; i<=26; i++) {
					SlowDisplay(",");
					SlowDisplay(xuan[i].name);
				}
				SlowDisplay("������ӹ��������̳\n\n");
				SlowDisplay("��һ��ǿ���У�һ����Ӱ������\n\n");
				guai=xian[27];
				SlowDisplay("��Ӱ������󣬱�������һ���������������ǰ\n\n");
				SlowDisplay("��������!!!\n\n");
				color(15);
				SlowDisplay("����");
				color(12);
				SlowDisplay("���˳���\n\n");
				battle=1;
				BattleAct();
			} else {
				printf("������ʲô��\n\n");
				printf("1,������� 2,һ������ 0,����");
				printf("\n===================================================================================\n");
				cin>>st;
				switch(opw(st)) {
					case 1: {
						for(int i=1; i<=36; i++)
							printf("%d,%s(%d��)%s*%d\n",i,xuan[i].chu,xuan[i].level,xuan[i].Lvup,xuan[i].Lup);
						cin>>st;
						while(opw(st)>36||opw(st)<0) {
							cout<<"�������\n\n";
							cin>>st;
						}
						if(opw(st)==0)break;
						if(xuan[opw(st)].Hav==0) {
							SlowDisplay("�㻹û��");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("\n\n");
						} else if(xuan[opw(st)].level==100) {
							SlowDisplay("���");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("�Ѿ�������\n\n");
						} else {
							xuan[opw(st)].Lup--;
							xuan[opw(st)].level++;
							xuan[opw(st)].attack+=(xuan[opw(st)].attack_+rand()%5-2);
							if(xuan[opw(st)].level%10==1) {
								if(xuan[opw(st)].level==11) {
									char cs[3]="��";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==21) {
									xuan[opw(st)].chu[0]='b';
									xuan[opw(st)].chu[1]='\b';
									xuan[opw(st)].chu[2]='b';
									xuan[opw(st)].chu[3]='\b';
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==31) {
									char cs[5]="�桤";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].chu[2]=cs[2];
									xuan[opw(st)].chu[3]=cs[3];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==41) {
									char cs[3]="��";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==51) {
									char cs[3]="��";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==61) {
									char cs[3]="ʥ";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==71) {
									char cs[3]="��";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==81) {
									char cs[3]="��";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==91) {
									char cs[5]="ʼԴ";
									xuan[opw(st)].chu[11]=xuan[opw(st)].chu[9];
									xuan[opw(st)].chu[10]=xuan[opw(st)].chu[8];
									xuan[opw(st)].chu[9]=xuan[opw(st)].chu[7];
									xuan[opw(st)].chu[8]=xuan[opw(st)].chu[6];
									xuan[opw(st)].chu[7]=xuan[opw(st)].chu[5];
									xuan[opw(st)].chu[6]=xuan[opw(st)].chu[4];
									xuan[opw(st)].chu[5]=xuan[opw(st)].chu[3];
									xuan[opw(st)].chu[4]=xuan[opw(st)].chu[2];
									xuan[opw(st)].chu[3]=cs[3];
									xuan[opw(st)].chu[2]=cs[2];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								}
							}
							if(xuan[opw(st)].PN==xuan[0].PN)xuan[0]=xuan[opw(st)];
						}
						break;
					}
					case 2: {
						for(int i=1; i<=36; i++)
							printf("%d,%s(%d��)%s*%d\n",i,xuan[i].chu,xuan[i].level,xuan[i].Lvup,xuan[i].Lup);
						cin>>st;
						while(opw(st)>36||opw(st)<0) {
							cout<<"�������\n\n";
							cin>>st;
						}
						if(opw(st)==0)break;
						if(xuan[opw(st)].Hav==0) {
							SlowDisplay("�㻹û��");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("\n\n");
						} else if(xuan[opw(st)].level==100) {
							SlowDisplay("���");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("�Ѿ�������\n\n");
						} else {
							while(xuan[opw(st)].Lup>0&&xuan[opw(st)].level!=100) {
								xuan[opw(st)].Lup--;
								xuan[opw(st)].level++;
								xuan[opw(st)].attack+=(xuan[opw(st)].attack_+rand()%5-2);
								if(xuan[opw(st)].level%10==1) {
									if(xuan[opw(st)].level==11) {
										char cs[3]="��";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==21) {
										xuan[opw(st)].chu[0]='b';
										xuan[opw(st)].chu[1]='\b';
										xuan[opw(st)].chu[2]='b';
										xuan[opw(st)].chu[3]='\b';
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==31) {
										char cs[5]="�桤";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].chu[2]=cs[2];
										xuan[opw(st)].chu[3]=cs[3];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==41) {
										char cs[3]="��";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==51) {
										char cs[3]="��";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==61) {
										char cs[3]="ʥ";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==71) {
										char cs[3]="��";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==81) {
										char cs[3]="��";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==91) {
										char cs[5]="ʼԴ";
										xuan[opw(st)].chu[11]=xuan[opw(st)].chu[9];
										xuan[opw(st)].chu[10]=xuan[opw(st)].chu[8];
										xuan[opw(st)].chu[9]=xuan[opw(st)].chu[7];
										xuan[opw(st)].chu[8]=xuan[opw(st)].chu[6];
										xuan[opw(st)].chu[7]=xuan[opw(st)].chu[5];
										xuan[opw(st)].chu[6]=xuan[opw(st)].chu[4];
										xuan[opw(st)].chu[5]=xuan[opw(st)].chu[3];
										xuan[opw(st)].chu[4]=xuan[opw(st)].chu[2];
										xuan[opw(st)].chu[3]=cs[3];
										xuan[opw(st)].chu[2]=cs[2];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									}
								}
							}
							if(xuan[opw(st)].PN==xuan[0].PN)xuan[0]=xuan[opw(st)];
						}
						break;
					}
					default:
						return;
				}
			}
		}
	}
}
void fsave() {
	ofstream fout;
	fout.open(nammm);
	fout<<"1 "<<cccsss<<endl;
	fout<<player.att_<<" "<<player.att__<<" "<<player.defen_<<" "<<player.defen__<<" "<<player.HP_<<" "<<player.HP__<<" "<<player.PP_<<" "<<player.PP__;
	fout<<"\n"<<player.attack<<" "<<player.defense<<" "<<player.health<<" "<<player.max_health<<" "<<player.level<<" "<<player.exp<<" "<<player.max_exp<<" "<<player.PP<<" "<<player.max_PP<<" "<<player.miss<<" "<<player.baoji;
	fout<<"\n"<<ghgh<<" "<<sby<<" "<<liuman;
	fout<<"\n"<<max_exp<<" "<<kingdie<<" "<<xiangcun<<" "<<mony<<" "<<js<<" "<<choose_number<<" "<<s<<" "<<strongman_arm<<" "<<fishman_tail<<" "<<falao_fire<<" "<<battle<<" "<<money<<" "<<place_sign<<" "<<huoling<<" "<<shuiling<<" "<<tuling<<" "<<fengling<<" "<<DIII;
	fout<<"\n"<<jn_1.name<<" "<<jn_1.xxx<<" "<<jn_1.hadd<<" "<<jn_1.haddd<<" "<<jn_1.num<<" "<<jn_1.pp<<" "<<jn_1.attack_jc<<" "<<jn_1.fang_jc<<" "<<jn_1.baoji_jc<<" "<<jn_1.miss_jc<<" "<<jn_1.jc_miss<<" "<<jn_1.jc_baoji<<" "<<\
	    jn_1.zhongdu<<" "<<jn_1.mihuo<<" "<<jn_1.shaoshang<<" "<<jn_1.mabi<<" "<<jn_1.hunluan<<" "<<jn_1.dongjie<<" "<<jn_1.cuimian<<" "<<jn_1.jisheng<<" "<<jn_1.jupao<<" "<<jn_1.xixe<<" "<<jn_1.huimie<<" "<<jn_1.fajian<<" "<<jn_1.wujian<<" "<<jn_1.fantan<<" "<<jn_1.PP_back<<" "<<jn_1.HP_back;
	fout<<"\n"<<jn_2.name<<" "<<jn_2.xxx<<" "<<jn_2.hadd<<" "<<jn_2.haddd<<" "<<jn_2.num<<" "<<jn_2.pp<<" "<<jn_2.attack_jc<<" "<<jn_2.fang_jc<<" "<<jn_2.baoji_jc<<" "<<jn_2.miss_jc<<" "<<jn_2.jc_miss<<" "<<jn_2.jc_baoji<<" "<<\
	    jn_2.zhongdu<<" "<<jn_2.mihuo<<" "<<jn_2.shaoshang<<" "<<jn_2.mabi<<" "<<jn_2.hunluan<<" "<<jn_2.dongjie<<" "<<jn_2.cuimian<<" "<<jn_2.jisheng<<" "<<jn_2.jupao<<" "<<jn_2.xixe<<" "<<jn_2.huimie<<" "<<jn_2.fajian<<" "<<jn_2.wujian<<" "<<jn_2.fantan<<" "<<jn_2.PP_back<<" "<<jn_2.HP_back;
	fout<<"\n"<<jn_3.name<<" "<<jn_3.xxx<<" "<<jn_3.hadd<<" "<<jn_3.haddd<<" "<<jn_3.num<<" "<<jn_3.pp<<" "<<jn_3.attack_jc<<" "<<jn_3.fang_jc<<" "<<jn_3.baoji_jc<<" "<<jn_3.miss_jc<<" "<<jn_3.jc_miss<<" "<<jn_3.jc_baoji<<" "<<\
	    jn_3.zhongdu<<" "<<jn_3.mihuo<<" "<<jn_3.shaoshang<<" "<<jn_3.mabi<<" "<<jn_3.hunluan<<" "<<jn_3.dongjie<<" "<<jn_3.cuimian<<" "<<jn_3.jisheng<<" "<<jn_3.jupao<<" "<<jn_3.xixe<<" "<<jn_3.huimie<<" "<<jn_3.fajian<<" "<<jn_3.wujian<<" "<<jn_3.fantan<<" "<<jn_3.PP_back<<" "<<jn_3.HP_back;
	fout<<"\n"<<jn_4.name<<" "<<jn_4.xxx<<" "<<jn_4.hadd<<" "<<jn_4.haddd<<" "<<jn_4.num<<" "<<jn_4.pp<<" "<<jn_4.attack_jc<<" "<<jn_4.fang_jc<<" "<<jn_4.baoji_jc<<" "<<jn_4.miss_jc<<" "<<jn_4.jc_miss<<" "<<jn_4.jc_baoji<<" "<<\
	    jn_4.zhongdu<<" "<<jn_4.mihuo<<" "<<jn_4.shaoshang<<" "<<jn_4.mabi<<" "<<jn_4.hunluan<<" "<<jn_4.dongjie<<" "<<jn_4.cuimian<<" "<<jn_4.jisheng<<" "<<jn_4.jupao<<" "<<jn_4.xixe<<" "<<jn_4.huimie<<" "<<jn_4.fajian<<" "<<jn_4.wujian<<" "<<jn_4.fantan<<" "<<jn_4.PP_back<<" "<<jn_4.HP_back;
	fout<<"\n"<<jn_jszz.hadd<<" "<<jn_mtdz.hadd<<" "<<jn_mhsx.hadd<<" "<<jn_xhly.hadd<<" "<<jn_nljt.hadd<<" "<<jn_phsg.hadd<<" "<<jn_hdjt.hadd<<" "<<jn_kghw.hadd<<" "<<jn_jpzs.hadd<<" "<<jn_getb.hadd<<" "<<jn_htmd.hadd<<" "<<jn_lpjq.hadd<<" "<<\
	    jn_lztx.hadd<<" "<<jn_zszs.hadd<<" "<<jn_hgfz.hadd<<" "<<jn_xjzq.hadd<<" "<<jn_gzpz.hadd<<" "<<jn_tqtb.hadd<<" "<<jn_jjcj.hadd<<" "<<jn_jmfs.hadd<<" "<<jn_scfs.hadd<<" "<<jn_xhys.hadd;
	fout<<"\n"<<jn_jszz.haddd<<" "<<jn_mtdz.haddd<<" "<<jn_mhsx.haddd<<" "<<jn_xhly.haddd<<" "<<jn_nljt.haddd<<" "<<jn_phsg.haddd<<" "<<jn_hdjt.haddd<<" "<<jn_kghw.haddd<<" "<<jn_jpzs.haddd<<" "<<jn_getb.haddd<<" "<<jn_htmd.haddd<<" "<<\
	    jn_lpjq.haddd<<" "<<jn_lztx.haddd<<" "<<jn_zszs.haddd<<" "<<jn_hgfz.haddd<<" "<<jn_xjzq.haddd<<" "<<jn_gzpz.haddd<<" "<<jn_tqtb.haddd<<" "<<jn_jjcj.haddd<<" "<<jn_jmfs.haddd<<" "<<jn_scfs.haddd<<" "<<jn_xhys.haddd;
	fout<<"\n"<<cao<<" "<<jijiubao<<" "<<baiyao<<" "<<superbaiyao<<" "<<boom<<" "<<dubiao<<" "<<atom_boom<<" "<<hlbyr<<" "<<dan<<" "<<xiancao<<" "<<xlsoup<<" "<<superxlsoup<<" "<<xuanz<<" "<<liux<<" "<<das<<" "<<DJz;
	fout<<"\n"<<fang<<" "<<fang1<<" "<<fang1n<<" "<<fang2<<" "<<fang2n<<" "<<fang3<<" "<<fang3n<<" "<<fang4<<" "<<fang4n<<" "<<fang5<<" "<<fang5n<<" "<<\
	    gong<<" "<<gong1<<" "<<gong1n<<" "<<gong2<<" "<<gong2n<<" "<<gong3<<" "<<gong3n<<" "<<gong4<<" "<<gong4n<<" "<<gong5<<" "<<gong5n<<" "<<hun<<" "<<hun1<<" "<<hun1n<<" "<<hun2<<" "<<hun2n<<" "<<hun3<<" "<<hun3n<<" "<<hun4<<" "<<hun4n<<" "<<yan<<" "<<yann<<" "<<yan1<<" "<<yan1n<<" "<<yan2<<" "<<yan2n<<" "<<yan3<<" "<<yan3n<<" "<<yan4<<" "<<yan4n;
	fout<<"\n"<<gongname<<" "<<fangname<<" "<<hunname<<" "<<yanname;
	fout<<"\n"<<HUOL<<" "<<SHUIL<<" "<<FENGL<<" "<<TUL<<" "<<TTDIE<<" "<<FMDIE<<" "<<FODIE<<" "<<Hpet;
	fout<<"\n"<<xuan[0].XM<<endl;
	for(int i=0; i<=36; i++)
		fout<<xuan[i].name<<" "<<xuan[i].chu<<" "<<xuan[i].Lvup<<" "<<xuan[i].PNm<<" "<<xuan[i].level<<" "<<xuan[i].Hav<<" "<<xuan[i].attack<<" "<<xuan[i].baoji<<" "<<xuan[i].Lup<<" "<<xuan[i].PN<<" "<<xuan[i].attack_<<" "<<xuan[i].Baif<<" "<<xuan[i].Baif_<<endl;
	return;
}
void fsavein() {
	system("CLS");
	cout<<"�����С���\n\n";
	setjindutiao(101);
	fscanf(fin,"%d",&cccsss);
	fscanf(fin,"%d%d%d%d%d%d%d%d",&player.att_,&player.att__,&player.defen_,&player.defen__,&player.HP_,&player.HP__,&player.PP_,&player.PP__);
	fscanf(fin,"%d%d%d%d%d%d%d%d%d%d%d\n",&player.attack,&player.defense,&player.health,&player.max_health,&player.level,&player.exp,&player.max_exp,&player.PP,&player.max_PP,&player.miss,&player.baoji);
	fscanf(fin,"%d%d%d\n",&ghgh,&sby,&liuman);
	fscanf(fin,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",&max_exp,&kingdie,&xiangcun,&mony,&js,&choose_number,&s,&strongman_arm,&fishman_tail,&falao_fire,&battle,&money,&place_sign,&huoling,&shuiling,&tuling,&fengling,&DIII);
	fscanf(fin,"%s%s%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",jn_1.name,jn_1.xxx,&jn_1.hadd,&jn_1.haddd,&jn_1.num,&jn_1.pp,&jn_1.attack_jc,&jn_1.fang_jc,&jn_1.baoji_jc,&jn_1.miss_jc,&jn_1.jc_miss,&jn_1.jc_baoji,\
	       &jn_1.zhongdu,&jn_1.mihuo,&jn_1.shaoshang,&jn_1.mabi,&jn_1.hunluan,&jn_1.dongjie,&jn_1.cuimian,&jn_1.jisheng,&jn_1.jupao,&jn_1.xixe,&jn_1.huimie,&jn_1.fajian,&jn_1.wujian,&jn_1.fantan,&jn_1.PP_back,&jn_1.HP_back);
	fscanf(fin,"%s%s%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",jn_2.name,jn_2.xxx,&jn_2.hadd,&jn_2.haddd,&jn_2.num,&jn_2.pp,&jn_2.attack_jc,&jn_2.fang_jc,&jn_2.baoji_jc,&jn_2.miss_jc,&jn_2.jc_miss,&jn_2.jc_baoji,\
	       &jn_2.zhongdu,&jn_2.mihuo,&jn_2.shaoshang,&jn_2.mabi,&jn_2.hunluan,&jn_2.dongjie,&jn_2.cuimian,&jn_2.jisheng,&jn_2.jupao,&jn_2.xixe,&jn_2.huimie,&jn_2.fajian,&jn_2.wujian,&jn_2.fantan,&jn_2.PP_back,&jn_2.HP_back);
	fscanf(fin,"%s%s%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",jn_3.name,jn_3.xxx,&jn_3.hadd,&jn_3.haddd,&jn_3.num,&jn_3.pp,&jn_3.attack_jc,&jn_3.fang_jc,&jn_3.baoji_jc,&jn_3.miss_jc,&jn_3.jc_miss,&jn_3.jc_baoji,\
	       &jn_3.zhongdu,&jn_3.mihuo,&jn_3.shaoshang,&jn_3.mabi,&jn_3.hunluan,&jn_3.dongjie,&jn_3.cuimian,&jn_3.jisheng,&jn_3.jupao,&jn_3.xixe,&jn_3.huimie,&jn_3.fajian,&jn_3.wujian,&jn_3.fantan,&jn_3.PP_back,&jn_3.HP_back);
	fscanf(fin,"%s%s%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",jn_4.name,jn_4.xxx,&jn_4.hadd,&jn_4.haddd,&jn_4.num,&jn_4.pp,&jn_4.attack_jc,&jn_4.fang_jc,&jn_4.baoji_jc,&jn_4.miss_jc,&jn_4.jc_miss,&jn_4.jc_baoji,\
	       &jn_4.zhongdu,&jn_4.mihuo,&jn_4.shaoshang,&jn_4.mabi,&jn_4.hunluan,&jn_4.dongjie,&jn_4.cuimian,&jn_4.jisheng,&jn_4.jupao,&jn_4.xixe,&jn_4.huimie,&jn_4.fajian,&jn_4.wujian,&jn_4.fantan,&jn_4.PP_back,&jn_4.HP_back);
	fscanf(fin,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",&jn_jszz.hadd,&jn_mtdz.hadd,&jn_mhsx.hadd,&jn_xhly.hadd,&jn_nljt.hadd,&jn_phsg.hadd,&jn_hdjt.hadd,&jn_kghw.hadd,&jn_jpzs.hadd,&jn_getb.hadd,&jn_htmd.hadd,&jn_lpjq.hadd,\
	       &jn_lztx.hadd,&jn_zszs.hadd,&jn_hgfz.hadd,&jn_xjzq.hadd,&jn_gzpz.hadd,&jn_tqtb.hadd,&jn_jjcj.hadd,&jn_jmfs.hadd,&jn_scfs.hadd,&jn_xhys.hadd);
	fscanf(fin,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",&jn_jszz.haddd,&jn_mtdz.haddd,&jn_mhsx.haddd,&jn_xhly.haddd,&jn_nljt.haddd,&jn_phsg.haddd,&jn_hdjt.haddd,&jn_kghw.haddd,&jn_jpzs.haddd,&jn_getb.haddd,&jn_htmd.haddd,&jn_lpjq.haddd,\
	       &jn_lztx.haddd,&jn_zszs.haddd,&jn_hgfz.haddd,&jn_xjzq.haddd,&jn_gzpz.haddd,&jn_tqtb.haddd,&jn_jjcj.haddd,&jn_jmfs.haddd,&jn_scfs.haddd,&jn_xhys.haddd);
	fscanf(fin,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",&cao,&jijiubao,&baiyao,&superbaiyao,&boom,&dubiao,&atom_boom,&hlbyr,&dan,&xiancao,&xlsoup,&superxlsoup,&xuanz,&liux,&das,&DJz);
	fscanf(fin,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",&fang,&fang1,&fang1n,&fang2,&fang2n,&fang3,&fang3n,&fang4,&fang4n,&fang5,&fang5n,\
	       &gong,&gong1,&gong1n,&gong2,&gong2n,&gong3,&gong3n,&gong4,&gong4n,&gong5,&gong5n,&hun,&hun1,&hun1n,&hun2,&hun2n,&hun3,&hun3n,&hun4,&hun4n,&yan,&yann,&yan1,&yan1n,&yan2,&yan2n,&yan3,&yan3n,&yan4,&yan4n);
	fscanf(fin,"%s%s%s%s\n",gongname,fangname,hunname,yanname);
	fscanf(fin,"%d%d%d%d%d%d%d%d",&HUOL,&SHUIL,&FENGL,&TUL,&TTDIE,&FMDIE,&FODIE,&Hpet);
	fscanf(fin,"%s",xuan[0].XM);
	for(int i=0; i<=36; i++)
		fscanf(fin,"%s%s%s%s%d%d%d%d%d%d%d%d%d\n",xuan[i].name,xuan[i].chu,xuan[i].Lvup,xuan[i].PNm,&xuan[i].level,&xuan[i].Hav,&xuan[i].attack,&xuan[i].baoji,&xuan[i].Lup,&xuan[i].PN,&xuan[i].attack_,&xuan[i].Baif,&xuan[i].Baif_);
	cout<<"����ɹ���\n\n";
	return;
}
void little_game() {
	long long a_,a1_,b_,c_,d_,num_=0,first_=unsigned(time(NULL));
	while(1) {
		a_=unsigned(time(NULL));
		if(a_==first_+1) {
			first_++;
			break;
		}
	}
	while(1) {
		if(kbhit()) {
			char ch_=getch();
			if(ch_==' ')num_++;
		} else {
			a_=unsigned(time(NULL));
			if(a_>a1_) {
				system("CLS");
				printf("��ʱ��\n");
				b_=(a_/3600+8)%24;
				c_=(a_/60)%60;
				d_=a_%60;
				printf("%02d:%02d:%02d\n",b_,c_,d_);
			}
			a1_=a_;
			if(a_==first_+5)break;
		}
	}
	cout<<"��һ�������"<<num_<<"��\n\n";
	cout<<"������"<<num_<<"Ԫ\n\n";
	Sleep(100);
	money+=num_;
	if(cccsss==3)money=999999999;
	return;
}
void stay__gj(long long time_,long long stay) {
	long long a_,b_,c_;
	a_=b_=unsigned(time(NULL));
	c_=0;
	while(!kbhit()&&a_<time_*60+b_) {
		a_=unsigned(time(NULL));
		if(a_>c_) {
			system("CLS");
			cout<<"�һ��У�����������˳�����\n\n(���ѹһ�"<<(a_-b_)/60<<"min"<<(a_-b_)%60<<"s)";
		}
		c_=a_;
		cout<<" \b";
	}
	system("CLS");
	char ch_=getch();
	cout<<"���ڹһ����д���"<<(a_-b_)/60<<"min"<<(a_-b_)%60<<"s,���"<<(a_-b_)*stay/3<<"Ԫ\n";
	money+=(a_-b_)*stay/3;
	if(cccsss==3)money=999999999;
	return;
}
void setjindutiao(int p)
{
	srand(unsigned(time(NULL)));
	COORD pos;
	pos.X=2;
	pos.Y=3;
	cout<<"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�["<<endl;
	cout<<"�U                                           �U"<<endl;
	cout<<"�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a"<<endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	color(11);
	for(int i=0;i<21;i++)
	{
		Sleep(rand()%2*p);
		cout<<"��";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	Sleep(1000);
}
