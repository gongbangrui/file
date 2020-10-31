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
xuan[38]= {{"无","无","\b\b\b\b\b\b\b                     ","","",0,0,0,0,0,0,0,0,0},
	{"獓狠","幼·獓狠","冲击","獓狠之角","獓狠对敌人进行撞击，造成伤害",0,-1,50,0,17,0,50,20,0},
	{"狰","幼·狰","噬豹","狰之尾","回合次数越多，狰自身和玩家的攻击力越高",0,-2,50,0,17,0,51,0,0},
	{"蛊雕","幼·蛊雕","鸟泣","蛊雕之羽","战斗开始时，使对方防御下降",0,-3,50,0,17,0,52,0,0},
	{"帝江","幼·帝江","天阳","帝江之喙","释放天阳火，有较大几率使敌人烧伤",0,-4,50,0,17,0,51,10,2},
	{"举父","幼·举父","投掷","举父之毛","投掷石子，攻击的同时使敌人命中率下降",0,-5,50,0,17,0,53,10,2},
	{"狸力","幼·狸力","掘土","狸力之爪","战斗开始时，使敌人闪避率降低",0,-6,50,0,17,0,54,0,0},
	{"九尾狐","幼·九尾狐","祥瑞","九尾之皮","使玩家恢复部分HP",0,-7,50,0,17,0,55,10,2},
	{"精卫","幼·精卫","填海","精卫之翼","若对方为水属性，大幅削弱对方的攻防",0,-8,50,0,17,0,53,10,2},
	{"烛阴","幼·烛阴","生风","烛阴之烛","战斗开始时，使玩家火属性伤害提升",0,-9,50,0,17,0,52,0,0},
	{"白泽","幼·白泽","化吉","白泽之须","有几率使敌人本次攻击无效",0,-10,50,0,17,0,49,10,2},
	{"麒麟","幼·麒麟","杰瑞","麒麟之角","战斗开始时，将玩家各个属性小幅度提升",0,-11,50,0,17,0,52,0,0},
	{"白矖","幼·白矖","忠随","白矖之鳞","玩家HP越低玩家攻击力越高",0,-12,50,0,17,0,51,0,0},
	{"腾蛇","幼·腾蛇","诚随","腾蛇之翅","玩家HP越低玩家防御力越高",0,-13,50,0,17,0,51,0,0},
	{"青龙","幼·青龙","龙腾","青龙之鳞","玩家每次攻击,对敌人造成伤害的同时玩家与青龙自身攻击上升",0,-14,50,0,17,0,50,0,0},
	{"白虎","幼·白虎","虎跃","白虎之爪","给敌人造成较高伤害",0,-15,50,0,17,0,54,20,10},
	{"朱雀","幼·朱雀","重生","朱雀之羽","在玩家战败时,有几率使玩家复活",0,-16,50,0,17,0,48,10,1},
	{"玄武","幼·玄武","玄冥","玄武之甲","战斗开始时，玩家防御会上升",0,-17,50,0,17,0,47,0,0},
	{"囚牛","幼·囚牛","催眠","囚牛之印","奏乐，可使敌人睡着",0,1,50,0,17,0,49,10,2},
	{"睚毗","幼·睚毗","震慑","睚毗之印","使敌人攻击力大幅下降",0,2,50,0,17,0,46,10,2},
	{"嘲风","幼·嘲风","奋战","嘲风之印","使敌人防御力大幅下降",0,3,50,0,17,0,47,10,2},
	{"蒲牢","幼·蒲牢","吼退","蒲牢之印","使敌人攻击防御小幅下降",0,4,50,0,17,0,49,10,2},
	{"狻猊","幼·狻猊","佛香","狻猊之印","使玩家恢复部分生命值",0,5,50,0,17,0,50,10,2},
	{"霸下","幼·霸下","坚稳","霸下之印","使玩家暴击率上升",0,6,50,0,17,0,51,10,2},
	{"狴犴","幼·狴犴","肃然","狴犴之印","本回合敌人对玩家造成了伤害，亦会使敌人受到等量伤害",0,7,50,0,17,0,52,15,1},
	{"负屃","幼·负屃","斯文","负屃之印","冷静分析，使自身攻击力上升",0,8,50,0,17,0,51,10,2},
	{"螭吻","幼·螭吻","消火","螭吻之印","使火属性伤害下降",0,9,50,0,17,0,53,10,2},
	{"龙王","幼·龙王","兴雨","龙王之印","大范围杀伤,必定暴击,同时小幅度提升攻击与防御",0,10,75,0,17,0,56,5,2},
	{"陵鱼","幼·陵鱼","水起","陵鱼之鳞","使敌人受到较高伤害",0,11,50,0,17,0,53,10,1},
	{"肥遗","幼·肥遗","青阳","肥遗之爪","释放青阳火，有较小几率使敌人烧伤，麻痹或冰冻",0,12,50,0,17,0,52,20,1},
	{"横公鱼","幼·横公鱼","邪病","横公之鳞","玩家在本回合受到的伤害无效化",0,13,50,0,17,0,49,10,1},
	{"犼","幼·犼","胜龙","犼之角","战斗开始时，敌人防御力和闪避下降",0,14,50,0,17,0,50,0,0},
	{"应龙","幼·应龙","兴云","应龙之翼","战斗开始时，使敌人命中率下降",0,15,50,0,17,0,51,0,0},
	{"螭龙","幼·螭龙","招财","螭龙之眉","战后获得金币量,经验量增加",0,16,50,0,17,0,50,0,0},
	{"蛟龙","幼·蛟龙","化龙","蛟龙之牙","有几率释放任意一个龙子（囚牛~螭吻）的技能",0,17,50,0,17,0,53,10,2},
	{"虬龙","幼·虬龙","龙马","虬龙之珠","回复玩家部分PP",0,18,50,0,17,0,49,10,2},
	{"蟠龙","幼·蟠龙","盘踞","蟠龙之尾","回合数越多，玩家防御力越强",0,19,50,0,17,0,51,0,0},
	{"无","无","无","无","",0,0,0,0,0,0,0,0,0}
};
struct Player {				   //玩家结构体，并初始化player
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
} player= {"勇者",190,180,100,100,1,0,100,40,40,17,15,20,10,10,175,20,20,20,50},
  battle_player= {"勇者",0,0,0,0,0,0,0,0,0,0,0};
struct Enemy {					//怪的结构体,并初始化各种怪
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
} strongman= {"森林巨人","金甲圣衣",10,240,190,7500,700,300,1,2,12,15,0,0,100,90,70,"生长",1},
  witch= {"森林女巫","银甲",10,125,90,320,50,70,2,4,15,14,0,1,70,30,35,"溅毒",2},
  xiyi= {"森林蟾蜍","鳞甲",6,90,50,180,20,35,3,6,12,13,0,1,70,50,40,"溅跃",3},
  big_strongman= {"森林巨人王","巨人之木",10,140*6,150*6,21350,400*3,100*9,4,4,0,20,1,0,200,120,20,"光合",4},
  big_strongmanking= {"森林巨人王之祖","",10,140*10,150*10,41350,400*5,100*13,1,-1,0,25,1,0,220,80,40,"吸收",5},
  shark= {"深海狂鲨","神魂",9,1150,900,8500,600,340,5,2,10,10,0,0,330,210,340,"利牙",6},
  jing= {"深海巨鲸","魔魂",9,870,500,6320,450,250,6,4,12,9,0,0,210,310,480,"鲸吼",7},
  lie= {"深海猎人","人魂",14,520,390,3180,250,195,7,6,21,8,0,0,460,130,220,"逃跑",8},
  fishman= {"深海人鱼王","人鱼之泪",9,140*8,150*8,27350,500*4,100*11,8,4,10,9,1,1,135,210,320,"突刺",9},
  fishmanking= {"深海人鱼王之祖","",9,140*15,150*10,47350,400*10,100*16,1,-1,10,14,1,1,130,180,405,"水枪",10},
  shouhu= {"沙漠守护","鬼火",12,1560,1390,15800,700,450,9,2,10,12,0,1,102,220,150,"锤炼",11},
  duxie= {"沙漠毒蝎","蓝焰",6,1350,1270,7790,550,420,10,4,10,14,0,0,105,130,141,"毒掷",12},
  jumang= {"沙漠巨蟒","红焰",14,1200,1160,5960,330,380,11,6,20,15,0,0,187,147,70,"脱皮",13},
  falao= {"沙漠法老王","法老之焰",12,350*8,170*8,32350,800*4,100*14,12,4,10,14,1,1,159,348,185,"幽火",14},
  falaoking= {"沙漠法老王之祖","",12,250*20,170*10,52350,800*6,100*20,1,-1,10,20,1,1,136,403,174,"复原",15},
  lion= {"荒原雄狮","绝世宝剑",14,2210,1650,12800,900,400,13,2,10,16,0,0,140,256,237,"撕裂",16},
  horse= {"荒原野马","碧血剑",6,1978,1320,5790,550,360,14,4,10,15,0,0,273,195,164,"飞踢",17},
  bee= {"荒原巨蜂","利锋",14,1737,1115,4960,330,350,15,6,16,13,0,0,216,139,267,"蛰咬",18},
  shitu1= {"火之使徒","",12,4000,1500,30000,7000,2900,21,-1,20,12,1,1,0,218,135,"水炮",19},
  shitu2= {"水之使徒","",9,4600,1700,30000,7000,2900,31,-1,20,12,1,1,30,224,178,"火球",20},
  shitu3= {"草之使徒","",10,5000,1500,40000,7000,2900,41,-1,20,12,1,1,394,157,0,"缠绕",21},
  king= {"黑暗大帝","",8,6600,1900,60000,9000,3300,41,-1,20,23,1,1,215,0,354,"失明",22},
  lingzhu1= {"水之灵主","水之灵",9,6600,4900,90000,10200,5300,91,11,20,12,1,1,30,226,372,"汪洋",23},
  lingzhu2= {"火之灵主","火之灵",12,7000,4700,90000,10200,5300,92,11,20,12,1,1,0,318,256,"烈焚",24},
  lingzhu3= {"土之灵主","土之灵",6,6600,5200,160000,10200,5300,93,11,20,12,1,1,135,253,459,"地裂",25},
  lingzhu4= {"风之灵主","风之灵",8,7600,5700,8000,10200,4800,94,11,20,12,1,1,374,274,245,"狂风",26},
  guai= {"\0","\0",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"",0},
xian[37]= {{"\0","\0",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"",0},
	{"祖·獓狠","獓狠",14,140*10,150*10,41350,0,0,-37,0,11,20,2,0,295,175,154,"冲击",-1},
	{"祖·狰","狰",9,140*10,150*10,41350,0,0,-38,0,11,20,2,0,295,175,154,"噬豹",-2},
	{"祖·蛊雕","蛊雕",14,140*10,150*10,41350,0,0,-39,0,11,20,2,0,195,175,254,"鸟泣",-3},
	{"祖·帝江","帝江",12,140*10,150*10,41350,0,0,-40,0,11,20,2,1,195,275,154,"天阳",-4},
	{"祖·举父","举父",10,140*10,150*10,41350,0,0,-41,0,11,20,2,0,295,175,20,"投掷",-5},
	{"祖·狸力","狸力",6,140*10,150*10,41350,0,0,-42,0,11,20,2,0,295,175,154,"掘土",-6},
	{"祖·九尾狐","九尾狐",8,140*10,150*10,41350,0,0,-43,0,11,20,2,1,195,275,154,"祥瑞",-7},
	{"祖·精卫","精卫",9,140*10,150*10,41350,0,0,-44,0,11,20,2,0,195,275,154,"填海",-8},
	{"祖·烛阴","烛阴",12,140*10,150*10,41350,0,0,-45,0,11,20,2,1,195,275,154,"生风",-9},
	{"祖·白泽","白泽",14,140*10,150*10,41350,0,0,-46,0,11,20,2,1,195,175,154,"化吉",-10},
	{"祖·麒麟","麒麟",6,140*10,150*10,41350,0,0,-47,0,11,20,2,1,195,175,154,"杰瑞",-11},
	{"祖·白矖","白矖",8,140*10,150*10,41350,0,0,-48,0,11,20,2,1,195,145,154,"忠随",-12},
	{"祖·腾蛇","腾蛇",8,140*10,150*10,41350,0,0,-49,0,11,20,2,1,195,145,154,"诚随",-13},
	{"祖·青龙","青龙",10,140*10,150*10,41350,0,0,-50,0,11,20,2,0,195,175,20,"龙腾",-14},
	{"祖·白虎","白虎",14,140*10,150*10,41350,0,0,-51,0,11,20,2,0,195,175,154,"虎跃",-15},
	{"祖·朱雀","朱雀",12,140*10,150*10,41350,0,0,-52,0,11,20,2,1,45,175,154,"重生",-16},
	{"祖·玄武","玄武",9,140*10,150*10,41350,0,0,-53,0,11,20,2,1,155,275,154,"玄冥",-17},
	{"祖·囚牛","囚牛",8,140*10,150*10,41350,0,0,-35,0,11,20,2,1,195,275,154,"催眠",-18},
	{"祖·睚毗","睚毗",8,140*10,150*10,41350,0,0,-34,0,11,20,2,0,195,275,154,"震慑",-19},
	{"祖·嘲风","嘲风",8,140*10,150*10,41350,0,0,-33,0,11,20,2,0,195,275,154,"奋战",-20},
	{"祖·蒲牢","蒲牢",8,140*10,150*10,41350,0,0,-32,0,11,20,2,0,195,275,154,"吼退",-21},
	{"祖·狻猊","狻猊",8,140*10,150*10,41350,0,0,-31,0,11,20,2,1,195,275,154,"佛香",-22},
	{"祖·霸下","霸下",8,140*10,150*10,41350,0,0,-30,0,11,20,2,0,195,275,154,"坚稳",-23},
	{"祖·狴犴","狴犴",8,140*10,150*10,41350,0,0,-29,0,11,20,2,0,195,275,154,"肃然",-24},
	{"祖·负屃","负屃",8,140*10,150*10,41350,0,0,-28,0,11,20,2,0,195,275,154,"斯文",-25},
	{"祖·螭吻","螭吻",8,140*10,150*10,41350,0,0,-27,0,11,20,2,1,100,275,154,"消火",-26},
	{"祖·龙王","龙王",8,3200,1600,27483,0,0,-26,0,11,20,2,1,100,275,154,"兴雨",-27},
	{"祖·陵鱼","陵鱼",9,140*10,150*10,41350,0,0,-25,0,11,20,2,1,155,275,154,"水起",-28},
	{"祖·肥遗","肥遗",12,140*10,150*10,41350,0,0,-24,0,11,20,2,1,45,175,154,"青阳",-29},
	{"祖·横公鱼","横公鱼",14,140*10,150*10,41350,0,0,-23,0,11,20,2,1,295,45,154,"邪病",-30},
	{"祖·犼","犼",6,140*10,150*10,41350,0,0,-22,0,11,20,2,1,175,175,154,"胜龙",-31},
	{"祖·应龙","应龙",9,140*10,150*10,41350,0,0,-21,0,11,20,2,1,175,175,154,"兴云",-32},
	{"祖·螭龙","螭龙",6,140*10,150*10,41350,0,0,-20,0,11,20,2,0,175,175,154,"招财",-33},
	{"祖·蛟龙","蛟龙",9,140*10,150*10,41350,0,0,-19,0,11,20,2,1,175,225,224,"化龙",-34},
	{"祖·虬龙","虬龙",14,140*10,150*10,41350,0,0,-18,0,11,20,2,1,175,275,154,"龙马",-35},
	{"祖·蟠龙","蟠龙",9,140*10,150*10,41350,0,0,-17,0,11,20,2,1,175,175,154,"盘踞",-36}
};
struct jn__ {					//怪的结构体,并初始化各种怪
	char name[111];
	char xxx[1000];
	bool hadd;
	bool haddd;
	int num;
	int pp;
	int attack_jc;//攻击加成
	int fang_jc;//防御加成
	int baoji_jc;//敌暴击降
	int miss_jc;//敌闪避降
	int jc_miss;//己闪避升
	int jc_baoji;//己暴击升
	int zhongdu;//中毒
	int mihuo;//迷惑
	int shaoshang;//烧伤
	int mabi;//麻痹
	int hunluan;//混乱
	int dongjie;//冻结
	int cuimian;//催眠
	int jisheng;//寄生
	int jupao;//巨炮
	int xixe;//吸血
	int huimie;//毁灭
	int fajian;//魔法伤减半
	int wujian;//物理伤减半
	int fantan;//反弹
	int PP_back;//回蓝
	int HP_back;//回血
} jn_= {"无","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_0= {"普通攻击","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_1= {"无","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_2= {"无","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_3= {"无","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_4= {"无","\b  ",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_jszz= {"寄生种子","投掷苞弹寄生敌人",0,0,1,25,50,0,0,0,0,100,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
  jn_mtdz= {"漫天毒针","使对方中毒",0,0,2,25,50,0,0,0,0,100,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_mhsx= {"迷惑射线","使对方迷惑",0,0,3,25,50,0,0,0,0,100,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_xhly= {"星火燎原","使对方烧伤",0,0,4,25,50,0,0,0,0,100,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_nljt= {"怒雷九天","使对方麻痹",0,0,5,25,50,0,0,0,0,100,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
  jn_phsg= {"破坏死光","使对方混乱",0,0,6,25,50,0,0,0,0,100,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
  jn_hdjt= {"寒冻九天","使对方冻结",0,0,7,25,50,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
  jn_kghw= {"枯骨黑雾","使对方昏迷",0,0,8,25,50,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
  jn_jpzs= {"巨炮之术","无法闪避，必定暴击",0,0,9,50,100,0,0,0,0,100,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
  jn_getb= {"噬血狂术","吸取敌人一定HP",0,0,10,40,90,0,0,0,0,100,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
  jn_htmd= {"毁天灭地","倾尽全力，造成极大的伤害，有一定几率秒杀（对BOSS无效）",0,0,11,800,5000,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
  jn_lpjq= {"龙盘聚气","能够回复少量PP",0,0,12,0,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,400,0},
  jn_lztx= {"龙之吐息","能够回复大量PP",0,0,13,0,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,800,0},
  jn_zszs= {"再生之术","能够回复少量HP",0,0,14,40,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,500},
  jn_hgfz= {"回光返照","能够回复大量HP",0,0,15,60,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1000},
  jn_xjzq= {"血祭之气","能够回满PP,但需要一定的HP作为代价"	,0,0,16,0,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,999999,-200},
  jn_gzpz= {"光之屏障","3回合内，抵御一半魔法伤害"	,0,0,17,50,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
  jn_tqtb= {"铜墙铁壁","3回合内，抵御一半物理伤害"	,0,0,18,50,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
  jn_jjcj= {"究极冲击","杀伤力极高，但自身也会受到一定的伤害",0,0,19,100,600,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-100},
  jn_jmfs= {"镜面反射","能将对方本回合对你的伤害反弹回敌人身上",0,0,20,75,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
  jn_scfs= {"双重反射","能将对方本回合对你的伤害双倍反弹回敌人身上",0,0,21,100,0,0,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0},
  jn_xhys= {"虚化隐术","2回合内敌人命中率降低90%，但自身也会因此极其脆弱",0,0,22,140,0,0,1,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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
	printf("你所拥有而未携带的宠物有：(金色为可选，灰色为不可选)\n\n你想携带哪只？\n\n");
	color(8);
	for(int i=1; i<=36; i++) {
		if(xuan[i].Hav==1&&xuan[0].PN!=xuan[i].PN) {
			color(14);
			printf("%2d,%s:%s(%s)\n",i,xuan[i].chu,xuan[i].PNm,xuan[i].XM);
		} else printf("%2d,%s\n",i,xuan[i].name);
		color(8);
	}
	printf("0,返回\n\n");
	color(11);
	puts("===================================================================================");
	cin>>st;
	if(opw(st)==0)return;
	if(xuan[opw(st)].Hav==1&&xuan[0].PN!=xuan[opw(st)].PN) {
		SlowDisplay("携带成功！\n\n");
		xuan[0]=xuan[opw(st)];
		return;
	} else {
		SlowDisplay("你还没有");
		SlowDisplay(xuan[opw(st)].name);
		SlowDisplay("\n\n");
		return;
	}
}
void help() {
	printf("这是一个勇者的世界，G公主被绑架了，你的任务就是将G公主安全地救出来\n\n");
	Sleep(100);
	printf("本游戏为GBR所作，网址: http://gbrblog.ga, QQ :3552526022，仅供娱乐学习使用\n\n");
	Sleep(100);
	printf("帮助：\n\n   地区：\n     商店：提供对话，交易等\n     旅店：提供房间，进行休息\n     银行：可以使用ATM存取款，存款死亡不遗失\n     其他地区请自己探索\n");
	Sleep(100);
	printf("\n\n   存读档：\n     进入游戏时若要读档请输入存档中角色名称，如果有档不读重新开始的话，存档会覆盖\n     游戏会自动存档，但请勿在战斗中关闭窗口，否则会出现未知错误\n");
	Sleep(100);
	printf("\n\n   宠物系统：\n     宠物在战斗中不受伤，会帮助玩家进行攻击，回复或防御\n     宠物分为十种形态：幼，虚，常(此字一般省略)，真，绊，幻，圣，帝，祖，始源\n");
	printf("     宠物获得途径?(除了龙王)闲逛去，有小概率随机遇见祖形，亦有几率捡拾到其进阶道具.当然,与某一个NPC初见也会得到一只宠物和另一个惊喜!至于龙王，则需要集齐龙九子后与某个NPC对话进行召唤\n\n");
//	Sleep(100);
//	printf("\n\n注：若名字与测试员角色重名,名称会被进行修改\n\n");
	Sleep(100);
	printf("为游戏乐趣与平衡，请勿使用作弊性软件\n\n");
	Sleep(100);
	printf("祝游戏愉快……\n\n最后一句：别用Windows的默认快捷键，比如Ctrl+字母等均不可用\n\n");
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
			printf("输入错误，请重新输入\n");
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
	cout<<"游戏载入中……\n\n";
	SetConsoleTitle("勇士之战V3.5.3");
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
	SlowDisplay("这是一个勇者的世界!三天前G公主被绑架了!\n\n勇敢的战士啊~拿起你的武器,营救G公主!\n\n\n输入你的名字(不要超过20个字节):\n\n\n");
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
			huihiuh=massbox("是否载入存档","检测到有同名存档，是否载入?\n",2);
		}
		if(huihiuh==6) {
			fsavein();
			system("CLS");
			OrdinaryAct();
		} else SlowDisplay("开始新游戏\n\n\n");
		Sleep(200);
		system("CLS");
	}
	system("cls");
	strcpy(yanname,"无");
	system("pause");
	strcpy(gongname,"无");
	system("cls");
	strcpy(hunname,"无");
	strcpy(fangname,"无");
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
		printf("请输入密码：");
		cin>>st;
		if(st!="gbr666") {
			printf("密码错误，非GBR");
			Sleep(1000);
			player.name[4]='\0';
			goto here;
		}
		cccsss=1;
		player.name[4]='\0';
		system("cls");
		SlowDisplay("攻击力：99999\n防御力：99999\nHP上限：999999\nPP上限：999999\n\n\n");
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
	if(strcmp(player.name,"勇士@测试")==0) {
		color(12);
		printf("请输入测试员密码：");
		cin>>st;
		if(st!="354260554") {
			printf("密码错误，非测试人物");
			Sleep(1000);
			player.name[4]='\0';
			goto here;
		}
		cccsss=2;
		player.name[4]='\0';
		system("cls");
		SlowDisplay("攻击力：999\n防御力：999\nHP上限：9999\nPP上限：9999\n所有技能解锁\n\n\n");
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
	if(strcmp(player.name,"慈善家@测试")==0) {
		color(12);
		printf("请输入测试员密码：");
		cin>>st;
		if(st!="354260554") {
			printf("密码错误，非测试人物");
			Sleep(1000);
			player.name[6]='\0';
			goto here;
		}
		cccsss=3;
		player.name[6]='\0';
		system("cls");
		SlowDisplay("攻击力：999\n防御力：999\nHP上限：9999\nPP上限：9999\n金币：∞\n\n\n");
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
	if(strcmp(player.name,"驯兽师@测试")==0) {
		color(12);
		printf("请输入测试员密码：");
		cin>>st;
		if(st!="354260554") {
			printf("密码错误，非测试人物");
			Sleep(1000);
			player.name[6]='\0';
			goto here;
		}
		cccsss=4;
		player.name[6]='\0';
		system("cls");
		SlowDisplay("攻击力：999\n防御力：999\nHP上限：9999\nPP上限：9999\n所有宠物解锁，宠物道具足够\n\n\n");
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
	printf("你想选什么职业（职业与技能等无关，只是会决定你的攻击防御HP和PP的量）\n\n");
	printf("1,战  士(高攻,低PP)\n2,骑  士(高防,略低攻和PP)\n3,炮  灰(高HP,略高防,略低攻和PP)\n4,法  师(高PP,略高攻,略低HP)\n5,弓  手(高闪避,略高攻,低HP)\n6,炮  手(高暴击,略高攻和防,略低HP)\n7,普通人(均衡发展)\n");
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
void ChooseWupin() {					 //选择物品 并使用
	if(battle) color(12);
	else color(11);
	printf("物品: \n\
1,止血草%d个	2,急救包%d个	3,云南白药%d个		4,超级云南白药%d个 \n\
5,元气丹%d个	6,神仙草%d个	7,修罗汤%d个		8,超级修罗汤%d个\n\
9,标  枪%d个	10,毒 镖%d个	11,螺旋手里剑%d个	12,红莲爆炎刃%d个\n\
0,返回\n\n\n",cao,jijiubao,baiyao,superbaiyao,dan,xiancao,xlsoup,superxlsoup,boom,dubiao,atom_boom,hlbyr);
	cin>>st;
	switch(opw(st)) {
		case 1:
			if(cao>0) {
				SlowDisplay("使用止血草,HP增加200\n\n\n");
				cao--;
				if(battle==0) {
					if(player.health+200>player.max_health)player.health=player.max_health;
					else player.health+=200;
				} else if(battle_player.health+200>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=200;
				if(battle)AttackResult();
			} else SlowDisplay("没有止血草了\n\n\n");
			break;
		case 2:
			if(jijiubao>0) {
				SlowDisplay("使用急救包,HP增加500\n\n\n");
				jijiubao--;
				if(battle==0) {
					if(player.health+500>player.max_health)player.health=player.max_health;
					else player.health+=500;
				} else if(battle_player.health+500>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=500;
				if(battle)AttackResult();
			} else SlowDisplay("没有急救包了\n\n\n");
			break;
		case 3:
			if(baiyao>0) {
				SlowDisplay("使用云南白药,HP增加1000\n\n\n");
				baiyao--;
				if(battle==0) {
					if(player.health+1000>player.max_health)player.health=player.max_health;
					else player.health+=1000;
				} else if(battle_player.health+1000>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=1000;
				if(battle)AttackResult();
			} else SlowDisplay("没有云南白药了\n\n\n");
			break;
		case 4:
			if(superbaiyao>0) {
				SlowDisplay("使用超级云南白药,HP增加2000\n\n\n");
				superbaiyao--;
				if(battle==0) {
					if(player.health+2000>player.max_health)player.health=player.max_health;
					else player.health+=2000;
				} else if(battle_player.health+2000>battle_player.max_health)battle_player.health=battle_player.max_health;
				else battle_player.health+=2000;
				if(battle)AttackResult();
			} else SlowDisplay("没有超级云南白药了\n\n\n");
			break;
		case 5:
			if(dan>0) {
				SlowDisplay("使用元气丹,PP增加50\n\n\n");
				dan--;
				if(battle==0) {
					if(player.PP+50>player.max_PP)player.PP=player.max_PP;
					else player.PP+=50;
				} else if(battle_player.PP+50>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=50;
				if(battle)AttackResult();
			} else SlowDisplay("没有元气丹了\n\n\n");
			break;
		case 6:
			if(xiancao>0) {
				SlowDisplay("使用神仙草,PP增加100\n\n\n");
				xiancao--;
				if(battle==0) {
					if(player.PP+100>player.max_PP)player.PP=player.max_PP;
					else player.PP+=100;
				} else if(battle_player.PP+100>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=100;
				if(battle)AttackResult();
			} else SlowDisplay("没有神仙草了\n\n\n");
			break;
		case 7:
			if(xlsoup>0) {
				SlowDisplay("使用修罗汤,PP增加300\n\n\n");
				xlsoup--;
				if(battle==0) {
					if(player.PP+300>player.max_PP)player.PP=player.max_PP;
					else player.PP+=300;
				} else if(battle_player.PP+300>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=300;
				if(battle)AttackResult();
			} else SlowDisplay("没有修罗汤了\n\n\n");
			break;
		case 8:
			if(superxlsoup>0) {
				SlowDisplay("使用超级修罗汤,PP增加500\n\n\n");
				superxlsoup--;
				if(battle==0) {
					if(player.PP+500>player.max_PP)player.PP=player.max_PP;
					else player.PP+=500;
				} else if(battle_player.PP+500>battle_player.max_PP)battle_player.PP=battle_player.max_PP;
				else battle_player.PP+=500;
				if(battle)AttackResult();
			} else SlowDisplay("没有超级修罗汤了\n\n\n");
			break;
		case 9:
			if(battle) {			   //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
				if(boom>0) {
					SlowDisplay("使用标枪,敌人HP减少500\n\n\n");
					boom--;
					guai.health-=500;
					AttackResult();
				} else SlowDisplay("没有标枪了\n\n\n");
			} else SlowDisplay("非战斗状态,不能使用标枪!\n\n\n");
			break;
		case 10:
			if(battle) {			   //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
				if(dubiao>0) {
					SlowDisplay("使用毒镖,敌人HP减少1200\n\n\n");
					dubiao--;
					guai.health-=1200;
					AttackResult();
				} else SlowDisplay("没有毒镖了\n\n\n");
			} else SlowDisplay("非战斗状态,不能使用毒镖!\n\n\n");
			break;
		case 11:
			if(battle) {			   //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
				if(atom_boom>0) {
					SlowDisplay("使用螺旋手里剑,敌人HP减少5500\n\n\n");
					atom_boom--;
					guai.health-=5500;
					AttackResult();
				} else SlowDisplay("没有螺旋手里剑了\n\n\n");
			} else SlowDisplay("非战斗状态,不能使用螺旋手里剑!\n\n\n");
			break;
		case 12:
			if(battle) {			   //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
				if(hlbyr>0) {
					SlowDisplay("使用红莲爆炎刃,敌人HP减少10000\n\n\n");
					hlbyr--;
					guai.health-=10000;
					AttackResult();
				} else SlowDisplay("没有红莲爆炎刃了\n\n\n");
			} else SlowDisplay("非战斗状态,不能使用红莲爆炎刃!\n\n\n");
			break;
		case 0:
			break;
		default:
			printf("输入错误\n\n\n");
	}
}
int AttackResult() {			  //攻击结果:判断是否获胜 是否获得物品 和 是否升级
	if(guai.health<=0) {
		battle=0;
		color(14);
		printf("战斗胜利!\n\n");
		int D=rand()%40+20;
		int MMM=rand()%40-20;
		if(guai.boss_!=2) {
			if(xuan[0].PN!=16) {
				printf("获得金币%d,经验%d\n\n\n",guai.money+MMM,guai.exp+D);
				player.exp+=guai.exp+D;
				money+=guai.money+MMM;
			} else {
				printf("获得金币%d,经验%d\n\n\n",(guai.money+MMM)*2,(guai.exp+D)*2);
				player.exp+=(guai.exp+D)*2;
				money+=(guai.money+MMM)*2;
			}
		}
		player.health=battle_player.health;
		player.PP=battle_player.PP;
		s=SuiJi();
		if(guai.wupin_sign<0) {
			color(14);
			SlowDisplay("你从敌人的怀中发现幼·");
			printf("%s\n\n\n",guai.wupin);
			AddWupin(guai.wupin_sign);
		} else if(s<=guai.wupinpro&&guai.wupin_sign>0) {
			color(14);
			SlowDisplay("从敌人尸骸中发现");
			printf("%s\n\n\n",guai.wupin);
			AddWupin(guai.wupin_sign);
		}
		WhetherLevelUp();
		if(strcmp(guai.name,"黑暗大帝")==0) {
			color(14);
			SlowDisplay("黑暗大帝：   你给我等着，我会回来的！！！\n\n    你获得了巨人之木，人鱼之泪和法老之焰,救出了翡翠公主\n\n\
	但公主很虚弱，昏迷不醒\n\n    你将公主送到了旅店\n\n旅店老板：\
			\n\n    听说用祭坛四灵之精华可以帮助人快速恢复···\n\n\n");
			place_sign=place.hotel;
			printf("%s",player.name);
			SlowDisplay("使用了巨人之木，人鱼之泪和法老之焰，攻击力+1000，防御力+1000，HP+1500,PP+100\n\n");
			gong+=1000;
			fang+=1000;
			player.max_health+=1500;
			player.max_PP+=100;
			player.health=player.max_health;
			player.PP=player.max_PP;
			kingdie=1;
		}
		return 1;				 //攻击有结果了返回1,否则返回0,用于判断是否继续做战斗行为
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
				printf("%s醒来了\n\n");
				Slp=0;
			} else {
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("仍在沉睡\n\n");
				sik=11;
			}
		} else if(Ice) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("仍未解冻\n\n");
			sik=11;
		} else if(Elec&&sik<=4) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("麻痹,无法移动\n\n");
			sik=11;
		} else if(Wory&&sik<=4) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("迷惑中,无法行动\n\n");
			sik=11;
		} else if(Sick&&sik<=2) {
			sik=11;
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("混乱,攻击了自己\n\n");
			if(guai.attack+s-guai.defense/3>1) {
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("的HP减少了%d\n\n",min(guai.health,guai.attack+s-guai.defense/3));
				guai.health-=min(guai.health,guai.attack+s-guai.defense/3);
			} else {
				guai.health-=1;
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("的HP减少了1\n\n");
			}
		} else if(BrBow) {
			if(sik<9) {
				sik=11;
				color(guai.color);
				printf("%s",guai.name);
				color(12);
				printf("攻击 %s闪避\n\n",player.name);
			} else {
				if(guai.attack*10-battle_player.defense>0) {
					int hiuuthug=guai.attack*10-battle_player.defense;
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("攻击 %s因虚化受到重伤,被造成了%d点伤害\n\n",player.name,min(battle_player.health,hiuuthug));
					battle_player.health-=min(battle_player.health,hiuuthug);
					if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
						SlowDisplay("横公鱼发动<邪病>,本回合敌人伤害无效化\n\n");
						battle_player.health=HHHP;
					} else if(rand()%100<xuan[37].Baif&&xuan[37].PN==-10) {
						SlowDisplay("白泽发动<化吉>,本回合敌人伤害无效化\n\n");
						battle_player.health=HHHP;
					}
				} else {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("攻击 %s因虚化受到重伤,被造成了%d点伤害\n\n",player.name,min(battle_player.health,(sik+1)));
					battle_player.health-=min(battle_player.health,(sik+1));
					if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
						SlowDisplay("横公鱼发动<邪病>,本回合敌人伤害无效化\n\n");
						battle_player.health=HHHP;
					} else if(rand()%100<xuan[37].Baif&&xuan[37].PN==-10) {
						SlowDisplay("白泽发动<化吉>,本回合敌人伤害无效化\n\n");
						battle_player.health=HHHP;
					}
				}
				sik=11;
				if(battle_player.health<=0) {
					if(xuan[37].PN==-16&&rand()%200<xuan[37].Baif) {
						SlowDisplay("你战死了\n\n但朱雀发动<重生>,你回到满HP与满PP\n\n");
						battle_player.health=battle_player.max_health;
						battle_player.PP=battle_player.max_PP;
					} else {
						battle=0;
						xuan[37]=xuan[0];
						printf("%s战死!金币掉落%d\n\n\n",player.name,money);
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
			printf("的混乱解除了\n");
		}
		if(Elec==1||EElec==1) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("的麻痹解除了\n");
		}
		if(Ice==1||IIce==1) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("的冰冻解除了\n");
		}
		if(Wory==1||WWory==1) {
			color(guai.color);
			printf("%s",guai.name);
			color(12);
			printf("的迷惑解除了\n");
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
						printf("攻击,伤害反弹给");
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("造成%d点伤害\n\n\n",min(Bkll,guai.health));
						Bkll=0;
					} else {
						battle_player.health-=1;
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("攻击,你的HP减少了1\n\n");
					}
				} else {
					if(rand()%100<guai.baoji) {
						if(Bkll) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("暴击,伤害反弹给%s造成%d点伤害\n\n\n",guai.name,min((guai.attack+s-battle_player.defense/3)*Bkll*9/5,guai.health));
							guai.health-=min((guai.attack+s-battle_player.defense/3)*Bkll*9/5,guai.health);
							Bkll=suran=0;
						} else if(suran) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("暴击,你的HP减少了%d\n\n",min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health));
							printf("同时,因<肃然>给%s造成%d点伤害\n\n\n",guai.name,min((guai.attack+s-battle_player.defense/3)*9/5,guai.health));
							guai.health-=min((guai.attack+s-battle_player.defense/3)*9/5,guai.health);
							battle_player.health-=min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health);
							suran=0;
						} else {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("暴击,你的HP减少了%d\n\n",min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health));
							battle_player.health-=min((guai.attack+s-battle_player.defense/3)*9/5,battle_player.health);
						}
					} else {
						if(Bkll) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("攻击,伤害反弹给");
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("造成%d点伤害\n\n\n",min((guai.attack+s-battle_player.defense/3)*Bkll,guai.health));
							guai.health-=min((guai.attack+s-battle_player.defense/3)*Bkll,guai.health);
							Bkll=suran=0;
						} else if(suran) {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("攻击,你的HP减少了%d\n\n",min(guai.attack+s-battle_player.defense/3,guai.health));
							printf("同时,因<肃然>给");
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("造成%d点伤害\n\n\n",(guai.attack+s-battle_player.defense/3));
							guai.health-=min(guai.attack+s-battle_player.defense/3,guai.health);
							battle_player.health-=min(guai.attack+s-battle_player.defense/3,battle_player.health);
							suran=0;
						} else {
							color(guai.color);
							printf("%s",guai.name);
							color(12);
							printf("攻击,你的HP减少了%d\n\n",min(battle_player.health,guai.attack+s-battle_player.defense/3));
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
					printf("被焰所伤,减少%dHP\n\n",min(guai.health,yann+UHGRUhgtR));
					guai.health-=min(guai.health,yann+UHGRUhgtR);
				}
				s=rand()%60+1-30;
				if(Fire&&guai.Frr>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("烧伤,失去%dHP\n\n",min(guai.health,guai.Frr+s));
					guai.health-=min(guai.health,guai.Frr+s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("身上的火熄灭了\n\n");
					}
				}
				if(Fire&&guai.Frr<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("因烧伤受到的火焰伤害,恢复%dHP\n\n",-(guai.Frr+s));
					guai.health-=(guai.Frr-s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("身上的火熄灭了\n\n");
					}
				}
				if(Kill) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("中毒,失去%dHP\n\n",min(guai.health,guai.ill+s));
					guai.health-=min(guai.health,guai.ill+s);
					Kill--;
					if(Kill==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("的毒解除了\n\n");
					}
				}
				if(Squid&&guai.lft+s>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("因被寄生,失去%dHP,%s恢复%dHP\n\n",min(guai.health,guai.lft+s),player.name,min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s)));
					guai.health-=min(guai.health,guai.lft+s);
					battle_player.health+=min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s));
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("的寄生解除了\n\n");
					}
				} else if(Squid&&guai.lft+s<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("因被寄生受到草木伤害,恢复%dHP\n\n",0-(guai.lft+s));
					guai.health+=-(guai.lft+s);
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("的寄生解除了\n\n");
					}
				}
				Bkll=0;
				if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
					SlowDisplay("横公鱼发动<邪病>,本回合敌人伤害无效化\n\n");
					battle_player.health=HHHP;
				} else if(rand()%100<xuan[37].Baif&&xuan[37].PN==-10) {
					SlowDisplay("白泽发动<化吉>,本回合敌人伤害无效化\n\n");
					battle_player.health=HHHP;
				}
				if(battle_player.health<=0) {
					if(xuan[37].PN==-16&&rand()%200<xuan[37].Baif) {
						SlowDisplay("你战死了\n\n但朱雀发动<重生>,你回到满HP与满PP\n\n");
						battle_player.health=battle_player.max_health;
						battle_player.PP=battle_player.max_PP;
					} else {
						battle=0;
						xuan[37]=xuan[0];
						printf("%s战死!金币掉落%d\n\n\n",player.name,money);
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
				printf("攻击 %s闪避\n\n",player.name);
				s=rand()%60+1-30;
				if(Fire&&guai.Frr>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("烧伤,失去%dHP\n\n",min(guai.health,guai.Frr+s));
					guai.health-=min(guai.health,guai.Frr+s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("身上的火熄灭了\n\n");
					}
				}
				if(Fire&&guai.Frr<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("因烧伤受到的火焰伤害,恢复%dHP\n\n",-(guai.Frr+s));
					guai.health-=(guai.Frr-s);
					Fire--;
					if(Fire==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("身上的火熄灭了\n\n");
					}
				}
				if(Kill) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("中毒,失去%dHP\n\n",min(guai.health,guai.ill+s));
					guai.health-=min(guai.health,guai.ill+s);
					Kill--;
					if(Kill==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("的毒解除了\n\n");
					}
				}
				if(Squid&&guai.lft+s>0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("因被寄生,失去%dHP,%s恢复%dHP\n\n",min(guai.health,guai.lft+s),player.name,min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s)));
					guai.health-=min(guai.health,guai.lft+s);
					battle_player.health+=min(battle_player.max_health-battle_player.health,min(guai.health,guai.lft+s));
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("的寄生解除了\n\n");
					}
				} else if(Squid&&guai.lft+s<0) {
					color(guai.color);
					printf("%s",guai.name);
					color(12);
					printf("因被寄生受到草木伤害,恢复%dHP\n\n",0-(guai.lft+s));
					guai.health+=-(guai.lft+s);
					Squid--;
					if(Squid==0) {
						color(guai.color);
						printf("%s",guai.name);
						color(12);
						printf("的寄生解除了\n\n");
					}
				}
				Bkll=0;
			}
		}
		if(guai.health<=0) {
			battle=0;
			color(14);
			xuan[37]=xuan[0];
			printf("战斗胜利!\n\n");
			int D=rand()%40+20;
			int MMM=rand()%40-20;
			if(guai.boss_!=2) {
				printf("获得金币%d,经验%d\n\n\n",guai.money+MMM,guai.exp+D);
				player.exp+=guai.exp+D;
				money+=guai.money+MMM;
			}
			player.health=battle_player.health;
			player.PP=battle_player.PP;
			s=SuiJi();
			if(guai.wupin_sign<0) {
				color(14);
				SlowDisplay("你从敌人的怀中发现幼·");
				printf("%s\n\n\n",guai.wupin);
				AddWupin(guai.wupin_sign);
			}
			if(s<=guai.wupinpro&&guai.wupin_sign>0) {
				color(14);
				SlowDisplay("从敌人尸骸中发现");
				printf("%s\n\n\n",guai.wupin);
				AddWupin(guai.wupin_sign);
			}
			WhetherLevelUp();
			if(strcmp(guai.name,"黑暗大帝")==0) {
				color(14);
				SlowDisplay("黑暗大帝：   你给我等着，我会回来的！！！\n\n    你获得了巨人之木，人鱼之泪和法老之焰,救出了翡翠公主\n\n\
	但公主很虚弱，昏迷不醒\n\n    你将公主送到了旅店\n\n旅店老板：\
			\n\n    听说用祭坛四灵之精华可以帮助人快速恢复···\n\n\n");
				place_sign=place.hotel;
				printf("%s",player.name);
				SlowDisplay("使用了巨人之木，人鱼之泪和法老之焰，攻击力+1000，防御力+1000，HP+1500,PP+100\n\n");
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
		printf("   %s升了%3d级!\n\n\n   攻击力+%3d, 防御力+%3d, HP上限+%3d PP上限+%3d\n\n\n",player.name,j,Gong,Fang,h_p,may);
		player.max_health+=h_p;
		player.defense+=Fang;
		player.attack+=Gong;
		player.max_PP+=may;
		player.health=player.max_health;
		player.PP=player.max_PP;
	}
}
void OrdinaryAct() {			//正常行为菜单(移动,物品,对话,查看状态,装备,退出游戏)
	while(1) {
		fsave();
		if(cccsss==3)money=999999999;
		if(place_sign!=place.bank&&place_sign!=place.bar&&place_sign!=place.hotel) {
			color(11);
			puts("===================================================================================");
			printf("要做什么?\n\n\n1,移  动 2,道  具 3,闲  逛 4,状  态 5,装  备 6,技  能 7,宠  物 8,信  息 0,退  出\n\n\n");
			puts("===================================================================================");
		} else if(place_sign!=place.bank) {
			color(11);
			puts("===================================================================================");
			printf("要做什么?\n\n\n1,移  动 2,道  具 3,对  话 4,状  态 5,装  备 6,技  能 7,宠  物 8,信  息 0,退  出\n\n\n");
			puts("===================================================================================");
		} else if(place_sign!=place.jitan4&&place_sign!=place.jitan3&&place_sign!=place.jitan2&&place_sign!=place.jitan1) {
			color(11);
			puts("===================================================================================");
			printf("要做什么?\n\n\n1,移  动 2,道  具 3,存取款 4,状  态 5,装  备 6,技  能 7,宠  物 8,信  息 0,退  出\n\n\n");
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
				printf(" 1, 帮  助  2,特别鸣谢  3,充  值   0,返  回\n\n");
				cin>>st;
				if(opw(st)==1) {
					help();
					break;
				} else if(opw(st)==2) {
					printf("特别鸣谢Boss_Xuan,创世菌,Monkey等人的帮助与支持\n\n");
				} else if(opw(st)==3){
					system("start https://www.baidu.com");
					massbox("充值?","就一C++小游戏，满足不了你想花钱的愿望",1);
				}
				break;
			case 1:									//显示移动菜单
				SlowDisplay("要去哪里?\n\n\n");
				printf(" 1,集市  2,旅馆  3,银行");
				printf("\n 4,森林一层  5,森林二层  6,森林三层 ");
				printf("\n 7,深海一层  8,深海二层  9,深海三层 ");
				printf("\n10,沙漠一层 11,沙漠二层 12,沙漠三层 ");
				printf("\n13,荒原一层 14,荒原二层 15,荒原三层 ");
				printf("\n16,水之祭坛 17,火之祭坛 18,土之祭坛 19,风之祭坛\n\n\n");
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
								SlowDisplay("水之灵，火之灵，土之灵，风之灵已融入翡翠公主体内\n\n翡翠公主：\n\n   谢谢\n\n你成功地救出了公主\n\n");
								system("pause");
								MessageBox(NULL,st.c_str(),"胜利",MB_OK);
								exit(0);
							} else
								color(8);
							SlowDisplay("要住店吗? 200个金币 1,是  0,否\n\n\n");
							st="1";
							cin>>st;
							switch(opw(st)) {
								case 1:
									if(money-200<0)SlowDisplay("Sorry,你的钱不够~\n\n\n");
									else {
										SlowDisplay("好好休息\n\tHP满  PP满\n\t\t第二天了\n\n");
										money-=200;
										player.health=player.max_health;	//体力满
										player.PP=player.max_PP;
										if(cccsss==3)money=999999999;
									}
									break;
								case 0:
									SlowDisplay("下次再来!\n\n\n");
									break;
								default:
									printf("输入错误!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
								printf("冲了过来!\n\n\n");
							}
							if(strongman_arm==0&&TTDIE==1)SlowDisplay("森林巨人王：   你休想拿走我们的圣草\n\n\n");
							else SlowDisplay("森林巨人王之祖：   把圣草还给我们\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
								printf("冲了过来!\n\n\n");
							}
							if(fishman_tail==0&&FMDIE==1)SlowDisplay("深海人鱼王:   你休想拿走我们的圣水\n\n\n");
							else SlowDisplay("深海人鱼王之祖：   把圣水还给我们\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
								printf("冲了过来!\n\n\n");
							}
							if(falao_fire==0&&FODIE==1)SlowDisplay("沙漠法老王:   你休想拿走我们的圣火\n\n\n");
							else SlowDisplay ("沙漠法老王之祖:   把圣火还给我们\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
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
									if(DIII==1)SlowDisplay("神秘老人:\n\n\n你又回来了？\n\n那就是准备好死了？！！\n\n\n");
									else SlowDisplay("神秘老人:\n\n\n    哈哈,年轻人,做的不错。\n\n    不过...\n\n    嘿嘿,你上当啦!巨人之木，人鱼之泪和法老之焰我要了,翡翠你也别想带走!\n\n\n");
									guai=shitu1;
									DIII=1;
									color(12);
									{
										color(guai.color);
										printf("%s",guai.name);
										color(12);
										printf("冲了过来!\n\n\n");
									}
									BattleAct();
									if(strcmp(guai.name,"火之使徒")==0) {
										guai=shitu2;
										battle_player=player;
										color(12);
										battle=1;
										{
											color(guai.color);
											printf("%s",guai.name);
											color(12);
											printf("冲了过来!\n\n\n");
										}
										BattleAct();
										if(strcmp(guai.name,"水之使徒")==0) {
											guai=shitu3;
											battle_player=player;
											color(12);
											battle=1;
											{
												color(guai.color);
												printf("%s",guai.name);
												color(12);
												printf("冲了过来!\n\n\n");
											}
											BattleAct();
											if(strcmp(guai.name,"草之使徒")==0) {
												guai=king;
												battle_player=player;
												battle=1;
												color(12);
												SlowDisplay("黑暗大帝:\n\n\n    什么？！！你竟然能击败我的使徒？！！\n\n\n\r   \r   \r   \r 	  你很厉害，但我决不会将翡翠交给你的！！！\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里安全\n\n\n");
							}
							break;
						case 16:
							place_sign=place.jitan1;
							if(kingdie==1&&SHUIL==1) {
								SlowDisplay("水之灵主：被那该死的黑暗大帝封印了这么久，我终于又出来了\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu1;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里什么也没有\n\n\n");
							}
							break;
						case 17:
							place_sign=place.jitan2;
							if(kingdie==1&&HUOL==1) {
								SlowDisplay("火之灵主：被那该死的黑暗大帝封印了这么久，我终于又出来了\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu2;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里什么也没有\n\n\n");
							}
							break;
						case 18:
							place_sign=place.jitan3;
							if(kingdie==1&&TUL==1) {
								SlowDisplay("土之灵主：那该死的黑暗大帝封印了这么久，我终于又出来了\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu3;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里什么也没有\n\n\n");
							}
							break;
						case 19:
							place_sign=place.jitan4;
							if(kingdie==1&&FENGL==1) {
								SlowDisplay("风之灵主：那该死的黑暗大帝封印了这么久，我终于又出来了\n\n\n");
								battle=1;
								color(12);
								guai=lingzhu4;
								battle_player=player;
								BattleAct();
							} else {
								color(10);
								SlowDisplay("这里什么也没有\n\n\n");
							}
							break;
						default:
							printf("输入错误!\n\n\n");
					}
				break;
			case 2:
				ChooseWupin();
				break;
			case 3:
				if(place_sign==place.bar) {
					color(11);
					if(ghgh==false)SlowDisplay("要和谁说话?\n\n\n1,红发女郎 2,赏金猎人 3,道具店 4,技能小贩 5,铁匠铺 6,驯兽大师 7,赌神\n\n\n");
					if(ghgh==true)SlowDisplay("要和谁说话?\n\n\n0,神秘老人 1,红发女郎 2,赏金猎人 3,道具店 4.技能小贩 5,铁匠铺 6,驯兽大师 7,赌神\n\n\n");	 //显示对话人物
					cin>>st;
					switch(opw(st)) {
						case 0: {
							if(ghgh==true) {
								color(5);
								SlowDisplay("神秘老人:\n\n\n    年轻人,你好啊.如果你有巨人之木，人鱼之泪和法老之焰,我可以告诉你翡翠的下落哦~\n\n\n");
								printf("%s:谢谢\n\n\n",player.name);
								ghgh=false;
								SlowDisplay("神秘老人:\n\n\n    如果想救公主，就带好东西来荒原找我哦……\n\n神秘老人消失了~\n\n\n");
								break;
							} else SlowDisplay("输入错误\n\n\n");
						}
						color(11);
						break;
						case 1:
							color(4);
							if(sby==0) {
								SlowDisplay("红发女郎:\n\n\n    听说你经常外出打猎,外面的路你应该很熟悉的!\n\n    但还是小心为好，这是2瓶超级云南白药，你先收下吧\n\n\n");
								printf("%s:谢谢\n\n\n",player.name);
								superbaiyao+=2;
								sby=1;
								break;
							} else SlowDisplay("红发女郎:\n\n\n    奋斗吧,少年!\n\n\n    不要被狂风暴雨吓倒!\n\n\n");
							color(11);
							break;
						case 2:
							color(6);
							if(liuman==0) {
								SlowDisplay("赏金猎人:\n\n\n    你要救翡翠啊!好胆量!\n\n\n    不过外面的丛林和草原很险恶,而且越深越危险,这是匕首和布衣,对你会有些帮助的,拿去吧!\n\n\n");
								printf("%s:谢谢\n\n\n",player.name);
								gong1n++;
								fang1n++;
								liuman=1;
							} else SlowDisplay("赏金猎人:\n\n\n    加油吧,年轻人!\n\n\n    不要被外面丛林和草原所吓倒!\n\n\n");
							color(11);
							break;
						case 3:
							color(15);
							printf("要买点什么?\n\n\n   1,止血草250金币  2,急救包500金币  3,云南白药750金币  4,超级云南白药1550金币\n\
					\n   5,元气丹250金币  6,神仙草500金币  7,修罗汤750金币  8,超级修罗汤1550金币\n\
					\n   9,标枪400金币 10,毒镖900金币 11,螺旋手里剑1500金币 12,红莲爆炎刃4500金币  0,返回\n\n\n");
							st="1";
							while(opw(st)) {
								cin>>st;
								switch(opw(st)) {
									case 1:
										if(money<250)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个止血草\n");
											money=money-250;
											if(cccsss==3)money=999999999;
											cao++;
										}
										break;
									case 2:
										if(money<500)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个急救包\n");
											money=money-500;
											if(cccsss==3)money=999999999;
											jijiubao++;
										}
										break;
									case 3:
										if(money<750)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个云南白药\n");
											money=money-750;
											if(cccsss==3)money=999999999;
											baiyao++;
										}
										break;
									case 4:
										if(money<1550)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个超级云南白药\n");
											money=money-1550;
											if(cccsss==3)money=999999999;
											superbaiyao++;
										}
										break;
									case 5:
										if(money<250)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个元气丹\n");
											money=money-250;
											if(cccsss==3)money=999999999;
											dan++;
										}
										break;
									case 6:
										if(money<500)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个神仙草\n");
											money=money-500;
											if(cccsss==3)money=999999999;
											xiancao++;
										}
										break;
									case 7:
										if(money<750)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个修罗汤\n");
											money=money-750;
											if(cccsss==3)money=999999999;
											xlsoup++;
										}
										break;
									case 8:
										if(money<1550)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个超级修罗汤\n");
											money=money-1550;
											if(cccsss==3)money=999999999;
											xlsoup++;
										}
										break;
									case 9:
										if(money<400)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个标枪\n");
											money=money-400;
											if(cccsss==3)money=999999999;
											boom++;
										}
										break;
									case 10:
										if(money<900)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个毒镖\n");
											money=money-900;
											if(cccsss==3)money=999999999;
											dubiao++;
										}
										break;
									case 11:
										if(money<1500)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个螺旋手里剑\n");
											money=money-1500;
											if(cccsss==3)money=999999999;
											atom_boom++;
										}
										break;
									case 12:
										if(money<4500)SlowDisplay("钱不够!\n");
										else {
											printf("你购买了一个红莲爆炎刃\n");
											money=money-4500;
											if(cccsss==3)money=999999999;
											hlbyr++;
										}
										break;
									case 0:
										SlowDisplay("下次再来!\n");
										break;
									default:
										SlowDisplay("输入错误\n\n\n");
								}
							}
							color(11);
							break;
						case 4:
							color(13);
							printf("小伙子，你要点什么?新技能，五折热卖中……\n\n\n 1,寄生种子10000金币  2,漫天毒针10000金币  3,迷惑射线10000金币  4,星火燎原10000金币\
\n 5,怒雷九天10000金币  6,破坏死光10000金币  7,寒冻九天10000金币  8,枯骨黑雾10000金币\
\n 9,巨炮之术12000金币 10,噬血狂术15000金币 11,毁天灭地40000金币 12,龙盘聚气12000金币\
\n13,龙之吐息18000金币 14,再生之术12000金币 15,回光返照18000金币 16,血祭之气20000金币\
\n17,光之屏障12000金币 18,铜墙铁壁12000金币 19,究极冲击18000金币 20,镜面反射12000金币\n21,双重反射18000金币 22,虚化隐术15000金币 0,返回\n\n\n");
							st="1";
							while(opw(st)) {
								cin>>st;
								switch(opw(st)) {
									case 1:
										SlowDisplay("寄生种子:投掷苞弹寄生敌人\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_jszz.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了寄生种子\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_jszz.hadd++;
										}
										break;
									case 2:
										SlowDisplay("漫天毒针:使对方中毒\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_mtdz.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了漫天毒针\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_mtdz.hadd++;
										}
										break;
									case 3:
										SlowDisplay("迷惑射线:使对方迷惑\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_mhsx.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了迷惑射线\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_mhsx.hadd++;
										}
										break;
									case 4:
										SlowDisplay("星火燎原:使对方烧伤\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_xhly.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了星火燎原\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_xhly.hadd++;
										}
										break;
									case 5:
										SlowDisplay("怒雷九天:使对方麻痹\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_nljt.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了怒雷九天\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_nljt.hadd++;
										}
										break;
									case 6:
										SlowDisplay("破坏死光:使对方混乱\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_phsg.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了破坏死光\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_phsg.hadd++;
										}
										break;
									case 7:
										SlowDisplay("寒冻九天:使对方冻结\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_hdjt.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了寒冻九天\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_hdjt.hadd++;
										}
										break;
									case 8:
										SlowDisplay("枯骨黑雾:使对方昏迷\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<10000)SlowDisplay("钱不够!\n");
										else if(jn_kghw.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了枯骨黑雾\n");
											money=money-10000;
											if(cccsss==3)money=999999999;
											jn_kghw.hadd++;
										}
										break;
									case 9:
										SlowDisplay("巨炮之术:无法闪避，必定暴击\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<12000)SlowDisplay("钱不够!\n");
										else if(jn_jpzs.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了巨炮之术\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_jpzs.hadd++;
										}
										break;
									case 10:
										SlowDisplay("噬血狂术:攻击敌人并吸取敌人一定HP\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<15000)SlowDisplay("钱不够!\n");
										else if(jn_getb.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了噬血狂术\n");
											money=money-15000;
											if(cccsss==3)money=999999999;
											jn_getb.hadd++;
										}
										break;
									case 11:
										SlowDisplay("毁天灭地:倾尽全力，造成极大的伤害，有一定几率秒杀（对BOSS无效）\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<40000)SlowDisplay("钱不够!\n");
										else if(jn_htmd.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了毁天灭地\n");
											money=money-40000;
											if(cccsss==3)money=999999999;
											jn_htmd.hadd++;
										}
										break;
									case 12:
										SlowDisplay("龙盘聚气:能够回复少量PP\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<12000)SlowDisplay("钱不够!\n");
										else if(jn_lpjq.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了龙盘聚气\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_lpjq.hadd++;
										}
										break;
									case 13:
										SlowDisplay("龙之吐息:能够回复大量PP\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<18000)SlowDisplay("钱不够!\n");
										else if(jn_lztx.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了龙之吐息\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_lztx.hadd++;
										}
										break;
									case 14:
										SlowDisplay("再生之术:能够回复少量HP\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<12000)SlowDisplay("钱不够!\n");
										else if(jn_zszs.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了再生之术\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_zszs.hadd++;
										}
										break;
									case 15:
										SlowDisplay("回光返照:能够回复大量HP\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<18000)SlowDisplay("钱不够!\n");
										else if(jn_hgfz.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了回光返照\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_hgfz.hadd++;
										}
										break;
									case 16:
										SlowDisplay("血祭之气:能够回满PP,但需要一定的HP作为代价\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<20000)SlowDisplay("钱不够!\n");
										else if(jn_xjzq.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了血祭之气\n");
											money=money-20000;
											if(cccsss==3)money=999999999;
											jn_xjzq.hadd++;
										}
										break;
									case 17:
										SlowDisplay("光之屏障:3回合内，抵御一半魔法伤害\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<12000)SlowDisplay("钱不够!\n");
										else if(jn_gzpz.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了光之屏障\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_gzpz.hadd++;
										}
										break;
									case 18:
										SlowDisplay("铜墙铁壁:3回合内，抵御一半物理伤害\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<12000)SlowDisplay("钱不够!\n");
										else if(jn_tqtb.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了铜墙铁壁\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_tqtb.hadd++;
										}
										break;
									case 19:
										SlowDisplay("究极冲击:杀伤力极高，但自身也会受到一定的伤害\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<18000)SlowDisplay("钱不够!\n");
										else if(jn_jjcj.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了究极冲击\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_jjcj.hadd++;
										}
										break;
									case 20:
										SlowDisplay("镜面反射:能将对方本回合对你的伤害反弹回敌人身上\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<12000)SlowDisplay("钱不够!\n");
										else if(jn_jmfs.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了镜面反射\n");
											money=money-12000;
											if(cccsss==3)money=999999999;
											jn_jmfs.hadd++;
										}
										break;
									case 21:
										SlowDisplay("双重反射:能将对方本回合对你的伤害双倍反弹回敌人身上\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<18000)SlowDisplay("钱不够!\n");
										else if(jn_scfs.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了双重反射\n");
											money=money-18000;
											if(cccsss==3)money=999999999;
											jn_scfs.hadd++;
										}
										break;
									case 22:
										SlowDisplay("虚化隐术:2回合内敌人命中率降低90%，但自身也会因此极其脆弱\n\n\n小伙子，你真的要吗?\n\n1,继续 0,取消本次交易\n\n");
										cin>>st;
										if(opw(st)==0) {
											SlowDisplay("小伙子，欢迎下次光临……\n\n");
											break;
										} else if(money<15000)SlowDisplay("钱不够!\n");
										else if(jn_xhys.hadd==1)SlowDisplay("你已购买过了!\n");
										else {
											printf("你购买了虚化隐术\n");
											money=money-15000;
											if(cccsss==3)money=999999999;
											jn_xhys.hadd++;
										}
										break;
									case 0:
										SlowDisplay("下次再来!\n");
										break;
									default:
										SlowDisplay("输入错误\n\n\n");
								}
								break;
							}
							color(11);
							break;
						case 5:
							color(7);
							printf("将装备提升一个档次需五个同样的装备（未装备的）:(0,返回)\n");
							printf("你想提升什么？\n1.利锋=>碧血剑(500金币)2.碧血剑=>绝世宝剑(2000金币)3.绝世宝剑=>屠龙千古剑(5000金币)\n");
							printf("4.鳞甲=>银甲(500金币)  5.银甲=>金甲圣衣(2000金币)  6.金甲圣衣=>究极战神甲(5000金币)\n");
							printf("7.人魂=>魔魂(500金币)  8.魔魂=> 神魂 (2000金币)    9.神魂=>冥古苍魂(5000金币)\n\n");
							printf("10.红焰=>蓝焰(500金币)11.蓝焰=> 鬼火 (2000金币)   12.鬼火=>滔天圣火(5000金币)\n");
							cin>>st;
							switch(opw(st)) {
								case 1:
									if(money<500)SlowDisplay("钱不够!\n");
									else if(gong2n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五把利锋，锻造失败\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										gong2n-=5;
									} else {
										printf("你失去了五把利锋，锻造成了一把碧血剑\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										gong2n-=5;
										gong3n++;
									}
									break;
								case 2:
									if(money<2000)SlowDisplay("钱不够!\n");
									else if(gong3n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五把碧血剑，锻造失败\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										gong3n-=5;
									} else {
										printf("你失去了五把碧血剑，锻造成了一把绝世宝剑\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										gong3n-=5;
										gong4n++;
									}
									break;
								case 3:
									if(money<5000)SlowDisplay("钱不够!\n");
									else if(gong4n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五把绝世宝剑，锻造失败\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										gong4n-=5;
									} else {
										printf("你失去了五把绝世宝剑，锻造成了一把屠龙千古剑\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										gong4n-=5;
										gong5n++;
									}
									break;
								case 4:
									if(money<500)SlowDisplay("钱不够!\n");
									else if(fang2n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五件鳞甲，锻造失败\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										fang2n-=5;
									} else {
										printf("你失去了五件鳞甲，锻造成了一件银甲\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										fang2n-=5;
										fang3n++;
									}
									break;
								case 5:
									if(money<2000)SlowDisplay("钱不够!\n");
									else if(fang3n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五件银甲，锻造失败\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										fang3n-=5;
									} else {
										printf("你失去了五件银甲，锻造成了一件金甲圣衣\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										fang3n-=5;
										fang4n++;
									}
									break;
								case 6:
									if(money<5000)SlowDisplay("钱不够!\n");
									else if(fang4n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五件金甲圣衣，锻造失败\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										fang4n-=5;
									} else {
										printf("你失去了五件金甲圣衣，锻造成了一件究极战神甲\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										fang4n-=5;
										fang5n++;
									}
									break;
								case 7:
									if(money<500)SlowDisplay("钱不够!\n");
									else if(hun1n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五个人魂，锻造失败\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										hun1n-=5;
									} else {
										printf("你失去了五个人魂，锻造成了一个魔魂\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										hun1n-=5;
										hun2n++;
									}
									break;
								case 8:
									if(money<500)SlowDisplay("钱不够!\n");
									else if(hun2n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五个魔魂，锻造失败\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										hun2n-=5;
									} else {
										printf("你失去了五个魔魂，锻造成了一个神魂\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										hun2n-=5;
										hun3n++;
									}
									break;
								case 9:
									if(money<5000)SlowDisplay("钱不够!\n");
									else if(hun3n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五个神魂，锻造失败\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										hun3n-=5;
									} else {
										printf("你失去了五个神魂，锻造成了一个冥古苍魂\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										hun3n-=5;
										hun4n++;
									}
									break;
								case 10:
									if(money<500)SlowDisplay("钱不够!\n");
									else if(yan1n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五个红焰，锻造失败\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										yan1n-=5;
									} else {
										printf("你失去了五个红焰，锻造成了一个蓝焰\n");
										money=money-500;
										if(cccsss==3)money=999999999;
										yan1n-=5;
										yan2n++;
									}
									break;
								case 11:
									if(money<2000)SlowDisplay("钱不够!\n");
									else if(yan2n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五个蓝焰，锻造失败\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										yan2n-=5;
									} else {
										printf("你失去了五个蓝焰，锻造成了一个鬼火\n");
										money=money-2000;
										if(cccsss==3)money=999999999;
										yan2n-=5;
										yan3n++;
									}
									break;
								case 12:
									if(money<5000)SlowDisplay("钱不够!\n");
									else if(yan3n<5)SlowDisplay("材料不够!\n");
									else if(rand()%100<5) {
										printf("你失去了五个鬼火，锻造失败\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										yan3n-=5;
									} else {
										printf("你失去了五个鬼火，锻造成了一个滔天圣火\n");
										money=money-5000;
										if(cccsss==3)money=999999999;
										yan3n-=5;
										yan4n++;
									}
									break;
								case 0:
									SlowDisplay("下次再来!\n");
									break;
								default:
									SlowDisplay("输入错误\n\n\n");
									break;
							}
							color(11);
							break;
						case 6:
							PetsTeach();
							break;
						case 7:
							SlowDisplay("赌神：你想玩游戏，还是想挂机？\n\n");
							printf("1,键盘狂人 2,石头剪刀布 3,投色子 4,挂机池 0,返回\n\n");
							cin>>st;
							while(opw(st)>5||opw(st)<1)
								cin>>st;
							switch(opw(st)) {
								case 1:
									printf("规则：交付50元入场费后5秒时间内尽可能多的点击键盘，每点击一下获得1元，入场费不退还，是否继续？1，继续，0，返回\n\n");
									cin>>st;
									if(opw(st)!=1)break;
									else if(money<50) {
										cout<<"钱不够\n\n";
										break;
									} else {
										money-=50;
										if(cccsss==3)money=999999999;
										little_game();
									}
									break;
								case 2:
									printf("规则：放上100元押金后与赌神石头剪刀布，获胜的一方获得场上所有钱,是否继续？1，继续，0，返回\n\n");
									cin>>st;
									if(opw(st)!=1)break;
									else if(money<100) {
										cout<<"钱不够\n\n";
										break;
									} else {
										money-=100;
										if(cccsss==3)money=999999999;
										int ko=rand()%3,ok;
										printf("你出什么？\n1,石头 2,剪刀 3,布\n\n");
										cin>>st;
										while(opw(st)>3||opw(st)<1)
											cin>>st;
										ok=opw(st);
										ok--;
										if(ok==ko) {
											if(ok==2)
												SlowDisplay("你出了布，赌神也出了布，平局，押金退还\n\n");
											else if(ok==0)
												SlowDisplay("你出了石头，赌神也出了石头，平局，押金退还\n\n");
											else if(ok==1)
												SlowDisplay("你出了剪刀，赌神也出了剪刀，平局，押金退还\n\n");
											money+=100;
											if(cccsss==3)money=999999999;
										} else if((ok==1&&ko==0)||(ok==2&&ko==1)||(ok==0&&ko==2)) {
											if(ok==1) {
												SlowDisplay("你出了剪刀，但赌神出了石头，赌神赢走了你的押金\n\n");
											} else if(ok==2) {
												SlowDisplay("你出了布，但赌神出了剪刀，赌神赢走了你的押金\n\n");
											} else if(ok==0) {
												SlowDisplay("你出了石头，但赌神出了布，赌神赢走了你的押金\n\n");
											}
										} else if((ok==2&&ko==0)||(ok==0&&ko==1)||(ok==1&&ko==2)) {
											if(ok==1) {
												SlowDisplay("你出了剪刀，但赌神出了布，你赢走了赌神的押金\n\n");
											} else if(ok==2) {
												SlowDisplay("你出了布，但赌神出了石头，你赢走了赌神的押金\n\n");
											} else if(ok==0) {
												SlowDisplay("你出了石头，但赌神出了剪刀，你赢走了赌神的押金\n\n");
											}
											money+=200;
											if(cccsss==3)money=999999999;
										}
										break;
									}
								case 3:
									printf("规则：放上100元押金后与赌神投色子，获胜的一方获得场上所有钱,是否继续？1，继续，0，返回\n\n");
									cin>>st;
									if(opw(st)!=1)break;
									else if(money<100) {
										cout<<"钱不够\n\n";
										break;
									} else {
										money-=100;
										if(cccsss==3)money=999999999;
										int Sez=rand()%6+1,hux[7]= {0,0,0,0,0,0,0};
										printf("你赌哪三个数？(1,2,3or4,5,6)\n\n");
										printf("选前三个数请输入1，否则输入2\n\n");
										cin>>st;
										while(opw(st)>2||opw(st)<1)
											cin>>st;
										if(opw(st)==2)hux[4]=hux[5]=hux[6]=1;
										else hux[1]=hux[2]=hux[3]=1;
										printf("掷骰子中……\n\n");
										Sleep(700);
										SlowDisplay("骰子停下了，数字为");
										cout<<Sez<<endl<<endl;
										if(hux[Sez]==1) {
											SlowDisplay("你获胜，赢得200元\n\n");
											money+=200;
											if(cccsss==3)money=999999999;
										} else {
											SlowDisplay("你输了，赌神赢走了你的押金\n\n");
										}
										break;
									}
								case 4:
									SlowDisplay("挂机也能赚钱？\n\n \r \r \rYes\n\n");
									printf("请选择挂机池……\n\n");
									printf("1,辣鸡挂机池(30min,最高3000元，500元入场) \n2,农民挂机池(60min,最高30000元，5000元入场) \n3,大神挂机池(90min,最高90000元，10000元入场) \n0,返回\n\n");
									cin>>st;
									int spend,time,speed;
									if(opw(st)>3||opw(st)<1)break;
									else {
										if(opw(st)==1) {
											if(money<500)
												printf("你的钱不够\n\n");
											else money-=500,stay__gj(30,5);
											break;
										} else if(opw(st)==2) {
											if(money<5000)
												printf("你的钱不够\n\n");
											else money-=5000,stay__gj(60,5);
											break;
										} else if(opw(st)==3) {
											if(money<10000)
												printf("你的钱不够\n\n");
											else money-=10000,stay__gj(90,50);
											break;
										}
									}
								case 0:
									SlowDisplay("下次再来!\n");
									break;
								default:
									SlowDisplay("输入错误\n\n\n");
									break;
							}
							break;
						default:
							SlowDisplay("输入错误\n\n\n");
							break;
					}
					break;
				} else if(place_sign==place.hotel) {
					SlowDisplay("“老板娘!我...”\n\n\n“我忙着呢，没空理你~”\n\n\n");
					break;
				} else if(place_sign==place.bank) {
					SlowDisplay("你想做什么？\n\n1.存钱    2.取钱    0.返回\n\n\n");
					cin>>st;
					switch(opw(st)) {
						case 1: {
							if(cccsss==3)money=999999999;
							printf("你现在有%d元，银行现存%d元,你想存多少？\n(银行最多存款1000000000金币，超出部分上交国家)\n\n\n",money,mony);
							cin>>st;
							xiangcun=opw(st);
							if(xiangcun<0)SlowDisplay("输入错误\n\n");
							else if(xiangcun<=money) {
								SlowDisplay("请稍候   \n   \n   \n");
								if(mony+xiangcun>=1000000000)mony=1000000000;
								else mony=mony+xiangcun;
								money=money-xiangcun;
								printf("你存了%d元\n",xiangcun);
							} else SlowDisplay("你没有这么多钱。\n\n\n");
							break;
						}
						case 2: {
							if(cccsss==3)money=999999999;
							printf("你现在有%d元，银行现存%d元,你想取多少？\n\n\n",money,mony);
							cin>>st;
							xiangcun=opw(st);
							if(xiangcun<0)SlowDisplay("输入错误\n\n");
							else if(xiangcun<=mony) {
								SlowDisplay("请稍候   \n   \n   \n");
								money=money+xiangcun;
								mony=mony-xiangcun;
								printf("你取了%d元\n",xiangcun);
							} else SlowDisplay("你没存这么多钱。\n\n\n");
							break;
						}
					}
					break;
				} else {
					int a=rand()%100;
					if(a<=3) {
						b=rand()%100+51;
						money+=b;
						printf("你捡到了%d金币\n\n",b);
					} else if(a<=7) {
						b=rand()%11+1;
						switch(b) {
							case 1:
								SlowDisplay("你捡到了一个止血草\n\n");
								cao++;
								break;
							case 2:
								SlowDisplay("你捡到了一个急救包\n\n");
								jijiubao++;
								break;
							case 3:
								SlowDisplay("你捡到了一个云南白药\n\n");
								baiyao++;
								break;
							case 4:
								SlowDisplay("你捡到了一个超级云南白药\n\n");
								superbaiyao++;
								break;
							case 5:
								SlowDisplay("你捡到了一个元气丹\n\n");
								dan++;
								break;
							case 6:
								SlowDisplay("你捡到了一个神仙草\n\n");
								xiancao++;
								break;
							case 7:
								SlowDisplay("你捡到了一个修罗汤\n\n");
								xlsoup++;
								break;
							case 8:
								SlowDisplay("你捡到了一个超级修罗汤\n\n");
								superxlsoup++;
								break;
							case 9:
								SlowDisplay("你捡到了一个标枪\n\n");
								boom++;
								break;
							case 10:
								SlowDisplay("你捡到了一个毒镖\n\n");
								dubiao++;
								break;
							case 11:
								SlowDisplay("你捡到了一个螺旋手里剑\n\n");
								atom_boom++;
								break;
							case 12:
								SlowDisplay("你捡到了一个红莲爆炎刃\n\n");
								hlbyr++;
								break;
						}
					} else if(a<=17) {
						int b=rand()%35+1,c=rand()%15+5;
						SlowDisplay("你捡到了");
						cout<<c;
						SlowDisplay("个");
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
							printf("祖·%s",xuan[b].name);
							color(12);
							printf("冲了出来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
								printf("冲了过来!\n\n\n");
							}
							if(strongman_arm==0&&TTDIE==1)SlowDisplay("森林巨人王：   你休想拿走我们的圣草\n\n\n");
							else SlowDisplay("森林巨人王之祖：   把圣草还给我们\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
								printf("冲了过来!\n\n\n");
							}
							if(fishman_tail==0&&FMDIE==1)SlowDisplay("深海人鱼王:   你休想拿走我们的圣水\n\n\n");
							else SlowDisplay("深海人鱼王之祖：   把圣水还给我们\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
								printf("冲了过来!\n\n\n");
							}
							if(falao_fire==0&&FODIE==1)SlowDisplay("沙漠法老王:   你休想拿走我们的圣火\n\n\n");
							else SlowDisplay ("沙漠法老王之祖:   把圣火还给我们\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									printf("冲了过来!\n\n\n");
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
									if(DIII==1)SlowDisplay("神秘老人:\n\n\n你又回来了？\n\n那就是准备好死了？！！\n\n\n");
									else SlowDisplay("神秘老人:\n\n\n    哈哈,年轻人,做的不错。\n\n    不过...\n\n    嘿嘿,你上当啦!巨人之木，人鱼之泪和法老之焰我要了,翡翠你也别想带走!\n\n\n");
									guai=shitu1;
									DIII=1;
									color(12);
									{
										color(guai.color);
										printf("%s",guai.name);
										color(12);
										printf("冲了过来!\n\n\n");
									}
									BattleAct();
									if(strcmp(guai.name,"火之使徒")==0) {
										guai=shitu2;
										battle_player=player;
										color(12);
										battle=1;
										{
											color(guai.color);
											printf("%s",guai.name);
											color(12);
											printf("冲了过来!\n\n\n");
										}
										BattleAct();
										if(strcmp(guai.name,"水之使徒")==0) {
											guai=shitu3;
											battle_player=player;
											color(12);
											battle=1;
											printf("%s冲了过来!\n\n\n",guai.name);
											BattleAct();
											if(strcmp(guai.name,"草之使徒")==0) {
												guai=king;
												battle_player=player;
												battle=1;
												color(12);
												SlowDisplay("黑暗大帝:\n\n\n    什么？！！你竟然能击败我的使徒？！！\n\n\n\r   \r   \r   \r 	  你很厉害，但我决不会将翡翠交给你的！！！\n\n\n");
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
									printf("冲了过来!\n\n\n");
								}
								battle_player=player;
								BattleAct();
							}
						} else {
							color(10);
							SlowDisplay("这里什么也没有……\n\n");
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
				printf("攻装: 1,匕首:%d个  2,利锋:%d个  3,碧血剑:%d个4,绝世宝剑:%d个  5,屠龙千古剑:%d个\n\n\n",gong1n,gong2n,gong3n,gong4n,gong5n);
				printf("防装: 6,布衣:%d个  7,鳞甲:%d个  8,银甲:%d个  9,金甲圣衣:%d个 10,究极战神甲:%d个\n\n\n",fang1n,fang2n,fang3n,fang4n,fang5n);
				printf(" 魂 :11,人魂:%d个 12,魔魂:%d个 13,神魂:%d个 14,冥古苍魂:%d个\n\n\n",hun1n,hun2n,hun3n,hun4n);
				printf(" 焰 :15,红焰:%d个 16,蓝焰:%d个 17,鬼火:%d个 18,滔天圣火:%d个  0,返回\n\n\n\n\n\n",yan1n,yan2n,yan3n,yan4n);
				SlowDisplay("选择要装备或出售的装备:\n\n\n");
				cin>>st;
				switch(opw(st)) {
					case 1:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong1n>=1) {
								SlowDisplay("拿起了匕首\n\n\n");
								if(strcmp(gongname,"匕首")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"利锋")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"碧血剑")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"绝世宝剑")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"屠龙千古剑")==0)
									gong5n++,gong-=gong5;
								gong+=gong1;
								gong1n--;
								strcpy(gongname,"匕首");
							} else SlowDisplay("你没有匕首可以装备\n\n\n");
						} else if(choose_number==0) {
							if(gong1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一把匕首，得到了20金币\n\n\n");
									money+=20;
								} else SlowDisplay("你遇到了强盗，被抢走了一把匕首\n\n\n");
								gong1n--;
							} else SlowDisplay("你没有匕首可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 2:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong2n>=1) {
								SlowDisplay("拿起了利锋\n\n\n");
								if(strcmp(gongname,"匕首")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"利锋")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"碧血剑")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"绝世宝剑")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"屠龙千古剑")==0)
									gong5n++,gong-=gong5;
								gong+=gong2;
								gong2n--;
								strcpy(gongname,"利锋");
							} else SlowDisplay("你没有利锋可以装备\n\n\n");
						} else if(choose_number==0) {
							if(gong2n>=js) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一把利锋，得到了100金币\n\n\n");
									money+=100;
								} else SlowDisplay("你遇到了强盗，被抢走了一把利锋\n\n\n");
								gong2n--;
							} else SlowDisplay("你没有利锋可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 3:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong3n>=1) {
								SlowDisplay("拿起了碧血剑\n\n\n");
								if(strcmp(gongname,"匕首")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"利锋")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"碧血剑")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"绝世宝剑")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"屠龙千古剑")==0)
									gong5n++,gong-=gong5;
								gong+=gong3;
								gong3n--;
								strcpy(gongname,"碧血剑");
							} else SlowDisplay("你没有碧血剑可以装备\n\n\n");
						} else if(choose_number==0) {
							if(gong3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一把碧血剑，得到了200金币\n\n\n");
									money+=200;
								} else SlowDisplay("你遇到了强盗，被抢走了一把碧血剑\n\n\n");
								gong3n--;
							} else SlowDisplay("你没有碧血剑可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 4:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong4n>=1) {
								SlowDisplay("拿起了绝世宝剑\n\n\n");
								if(strcmp(gongname,"匕首")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"利锋")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"碧血剑")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"绝世宝剑")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"屠龙千古剑")==0)
									gong5n++,gong-=gong5;
								gong+=gong4;
								gong4n--;
								strcpy(gongname,"绝世宝剑");
							} else SlowDisplay("你没有绝世宝剑可以装备\n\n\n");
						} else if(choose_number==0) {
							if(gong4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一把绝世宝剑，得到了500金币\n\n\n");
									money+=500;
								} else SlowDisplay("你遇到了强盗，被抢走了一把绝世宝剑\n\n\n");
								gong4n--;
							} else SlowDisplay("你没有绝世宝剑可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 5:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(gong5n>=1) {
								SlowDisplay("拿起了屠龙千古剑\n\n\n");
								if(strcmp(gongname,"匕首")==0)
									gong1n++,gong-=gong1;
								else if(strcmp(gongname,"利锋")==0)
									gong2n++,gong-=gong2;
								else if(strcmp(gongname,"碧血剑")==0)
									gong3n++,gong-=gong3;
								else if(strcmp(gongname,"绝世宝剑")==0)
									gong4n++,gong-=gong4;
								else if(strcmp(gongname,"屠龙千古剑")==0)
									gong5n++,gong-=gong5;
								gong+=gong5;
								gong5n--;
								strcpy(gongname,"屠龙千古剑");
							} else SlowDisplay("你没有屠龙千古剑可以装备\n\n\n");
						} else if(choose_number==0) {
							if(gong5n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一把屠龙千古剑，得到了1000金币\n\n\n");
									money+=1000;
								} else
									SlowDisplay("你遇到了强盗，被抢走了一把屠龙千古剑\n\n\n");
								gong5n--;
							} else SlowDisplay("你没有屠龙千古剑可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 6:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang1n>=1) {
								SlowDisplay("穿上了布衣\n\n\n");
								if(strcmp(fangname,"布衣")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"鳞甲")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"银甲")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"金甲圣衣")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"究极战神甲")==0)
									fang5n++,fang-=fang5;
								fang+=fang1;
								fang1n--;
								strcpy(fangname,"布衣");
							} else SlowDisplay("你没有布衣可以装备\n\n\n");
						} else if(choose_number==0) {
							if(fang1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一件布衣，得到了20金币\n\n\n");
									money+=20;
								} else SlowDisplay("你遇到了强盗，被抢走了一件布衣\n\n\n");
								fang1n--;
							} else SlowDisplay("你没有布衣可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 7:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang2n>=1) {
								SlowDisplay("穿上了鳞甲\n\n\n");
								if(strcmp(fangname,"布衣")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"鳞甲")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"银甲")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"金甲圣衣")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"究极战神甲")==0)
									fang5n++,fang-=fang5;
								fang+=fang2;
								fang2n--;
								strcpy(fangname,"鳞甲");
							} else SlowDisplay("你没有鳞甲可以装备\n\n\n");
						} else if(choose_number==0) {
							if(fang2n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一件鳞甲，得到了100金币\n\n\n");
									money+=100;
								} else SlowDisplay("你遇到了强盗，被抢走了一件鳞甲\n\n\n");
								fang2n--;
							} else SlowDisplay("你没有鳞甲可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 8:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang3n>=1) {
								SlowDisplay("穿上了银甲\n\n\n");
								if(strcmp(fangname,"布衣")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"鳞甲")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"银甲")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"金甲圣衣")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"究极战神甲")==0)
									fang5n++,fang-=fang5;
								fang+=fang3;
								fang3n--;
								strcpy(fangname,"银甲");
							} else SlowDisplay("你没有银甲可以装备\n\n\n");
						} else if(choose_number==0) {
							if(fang3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一件银甲，得到了200金币\n\n\n");
									money+=200;
								} else SlowDisplay("你遇到了强盗，被抢走了一件银甲\n\n\n");
								fang3n--;
							} else SlowDisplay("你没有银甲可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 9:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang4n>=1) {
								SlowDisplay("穿上了金甲圣衣\n\n\n");
								if(strcmp(fangname,"布衣")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"鳞甲")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"银甲")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"金甲圣衣")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"究极战神甲")==0)
									fang5n++,fang-=fang5;
								fang+=fang4;
								fang4n--;
								strcpy(fangname,"金甲圣衣");
							} else SlowDisplay("你没有金甲圣衣可以装备\n\n\n");
						} else if(choose_number==0) {
							if(fang4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一件金甲圣衣，得到了500金币\n\n\n");
									money+=500;
								} else SlowDisplay("你遇到了强盗，被抢走了一件金甲圣衣\n\n\n");
								fang4n--;
							} else SlowDisplay("你没有金甲圣衣可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 10:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(fang5n>=1) {
								SlowDisplay("穿上了究极战神甲\n\n\n");
								if(strcmp(fangname,"布衣")==0)
									fang1n++,fang-=fang1;
								else if(strcmp(fangname,"鳞甲")==0)
									fang2n++,fang-=fang2;
								else if(strcmp(fangname,"银甲")==0)
									fang3n++,fang-=fang3;
								else if(strcmp(fangname,"金甲圣衣")==0)
									fang4n++,fang-=fang4;
								else if(strcmp(fangname,"究极战神甲")==0)
									fang5n++,fang-=fang5;
								fang+=fang5;
								fang5n--;
								strcpy(fangname,"究极战神甲");
							} else SlowDisplay("你没有究极战神甲可以装备\n\n\n");
						} else if(choose_number==0) {
							if(fang5n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一件究极战神甲，得到了1000金币\n\n\n");
									money+=1000;
								} else
									SlowDisplay("你遇到了强盗，被抢走了一件究极战神甲\n\n\n");
								fang5n--;
							} else SlowDisplay("你没有究极战神甲可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 11:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun1n>=1) {
								SlowDisplay("附上了人魂\n\n\n");
								if(strcmp(hunname,"人魂")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"魔魂")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"神魂")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"冥古苍魂")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun1+gong;
								fang=fang+hun1;
								hun1n--;
								strcpy(hunname,"人魂");
							} else SlowDisplay("你没有人魂可以装备\n\n\n");
						} else if(choose_number==0) {
							if(hun1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个人魂，得到了50金币\n\n\n");
									money+=50;
								} else SlowDisplay("你遇到了强盗，被抢走了一个人魂\n\n\n");
								hun1n--;
							} else SlowDisplay("你没有人魂可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 12:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun2n>=1) {
								SlowDisplay("附上了魔魂\n\n\n");
								if(strcmp(hunname,"人魂")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"魔魂")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"神魂")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"冥古苍魂")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun2+gong;
								fang=fang+hun2;
								hun2n--;
								strcpy(hunname,"魔魂");
							} else SlowDisplay("你没有魔魂可以装备\n\n\n");
						} else if(choose_number==0) {
							if(hun2n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个魔魂，得到了100金币\n\n\n");
									money+=100;
								} else SlowDisplay("你遇到了强盗，被抢走了一个魔魂\n\n\n");
								hun2n--;
							} else SlowDisplay("你没有魔魂可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 13:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun3n>=1) {
								SlowDisplay("附上了神魂\n\n\n");
								if(strcmp(hunname,"人魂")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"魔魂")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"神魂")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"冥古苍魂")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun3+gong;
								fang=fang+hun3;
								hun3n--;
								strcpy(hunname,"神魂");
							} else SlowDisplay("你没有神魂可以装备\n\n\n");
						} else if(choose_number==0) {
							if(hun3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个神魂，得到了200金币\n\n\n");
									money+=200;
								} else SlowDisplay("你遇到了强盗，被抢走了一个神魂\n\n\n");
								hun3n--;
							} else SlowDisplay("你没有神魂可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 14:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(hun4n>=1) {
								SlowDisplay("附上了冥古苍魂\n\n\n");
								if(strcmp(hunname,"人魂")==0)
									hun1n++,gong-=hun1,fang-=hun1;
								else if(strcmp(hunname,"魔魂")==0)
									hun2n++,gong-=hun2,fang-=hun2;
								else if(strcmp(hunname,"神魂")==0)
									hun3n++,gong-=hun3,fang-=hun3;
								else if(strcmp(hunname,"冥古苍魂")==0)
									hun4n++,gong-=hun4,fang-=hun4;
								gong=hun4+gong;
								fang=fang+hun4;
								hun4n--;
								strcpy(hunname,"冥古苍魂");
							} else SlowDisplay("你没有冥古苍魂可以装备\n\n\n");
						} else if(choose_number==0) {
							if(hun4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个冥古苍魂，得到了1000金币\n\n\n");
									money+=1000;
								} else
									SlowDisplay("你遇到了强盗，被抢走了一个冥古苍魂\n\n\n");
								hun4n--;
							} else SlowDisplay("你没有冥古苍魂可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 15:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan1n>=1) {
								SlowDisplay("附上了红焰\n\n\n");
								if(strcmp(yanname,"红焰")==0)
									yan1n++;
								else if(strcmp(yanname,"蓝焰")==0)
									yan2n++;
								else if(strcmp(yanname,"鬼火")==0)
									yan3n++;
								else if(strcmp(yanname,"滔天圣火")==0)
									yan4n++;
								yan=yan1n;
								yann=yan1;
								yan1n--;
								strcpy(yanname,"红焰");
							} else SlowDisplay("你没有红焰可以装备\n\n\n");
						} else if(choose_number==0) {
							if(yan1n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个红焰，得到了50金币\n\n\n");
									money+=50;
								} else SlowDisplay("你遇到了强盗，被抢走了一个红焰\n\n\n");
								yan1n--;
							} else SlowDisplay("你没有红焰可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 16:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan2n>=1) {
								SlowDisplay("附上了蓝焰\n\n\n");
								if(strcmp(yanname,"红焰")==0)
									yan1n++;
								else if(strcmp(yanname,"蓝焰")==0)
									yan2n++;
								else if(strcmp(yanname,"鬼火")==0)
									yan3n++;
								else if(strcmp(yanname,"滔天圣火")==0)
									yan4n++;
								yan=yan2n;
								yann=yan2;
								yan2n--;
								strcpy(yanname,"蓝焰");
							} else SlowDisplay("你没有蓝焰可以装备\n\n\n");
						} else if(choose_number==0) {
							if(yan2n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个蓝焰，得到了100金币\n\n\n");
									money+=100;
								} else
									SlowDisplay("你遇到了强盗，被抢走了一个蓝焰\n\n\n");
								yan2n--;
							} else SlowDisplay("你没有蓝焰可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 17:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan3n>=1) {
								SlowDisplay("附上了鬼火\n\n\n");
								if(strcmp(yanname,"红焰")==0)
									yan1n++;
								else if(strcmp(yanname,"蓝焰")==0)
									yan2n++;
								else if(strcmp(yanname,"鬼火")==0)
									yan3n++;
								else if(strcmp(yanname,"滔天圣火")==0)
									yan4n++;
								yan=yan3n;
								yann=yan3;
								yan3n--;
								strcpy(yanname,"鬼火");
							} else SlowDisplay("你没有鬼火可以装备\n\n\n");
						} else if(choose_number==0) {
							if(yan3n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个鬼火，得到了200金币\n\n\n");
									money+=200;
								} else SlowDisplay("你遇到了强盗，被抢走了一个鬼火\n\n\n");
								yan3n--;
							} else SlowDisplay("你没有鬼火可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 18:
						cout<<"你想做什么？\n0.出售   1.装备   2.返回\n\n\n";
						cin>>st;
						choose_number=opw(st);
						if(choose_number==1) {
							if(yan4n>=1) {
								SlowDisplay("附上了滔天圣火\n\n\n");
								if(strcmp(yanname,"红焰")==0)
									yan1n++;
								else if(strcmp(yanname,"蓝焰")==0)
									yan2n++;
								else if(strcmp(yanname,"鬼火")==0)
									yan3n++;
								else if(strcmp(yanname,"滔天圣火")==0)
									yan4n++;
								yan=yan4n;
								yann=yan4;
								yan4n--;
								strcpy(yanname,"滔天圣火");
							} else SlowDisplay("你没有滔天圣火可以装备\n\n\n");
						} else if(choose_number==0) {
							if(yan4n>=1) {
								if(rand()%100>=5) {
									SlowDisplay("你出售了一个滔天圣火，得到了1000金币\n\n\n");
									money+=1000;
								} else
									SlowDisplay("你遇到了强盗，被抢走了一个滔天圣火\n\n\n");
								yan4n--;
							} else SlowDisplay("你没有滔天圣火可以出售\n\n\n");
						} else SlowDisplay("   \r");
						break;
					case 0:
						SlowDisplay("未进行操作\n\n\n");
						break;
					default:
						printf("输入错误!\n");
				}
				break;
			case 0:
				color(6);
				SlowDisplay("确定退出游戏?(Y/N)\n\n\n");
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
					SlowDisplay("数据存储中...");
					Sleep(100);
					massbox("提示","数据存储完毕",1);
					exit(0);
					return;
				} else if(proof=='n'||proof=='N')printf("继续游戏!\n\n\n");
				else SlowDisplay("继续!\n\n\n");
				break;
			default:
				SlowDisplay("输入错误!\n\n\n");
		}
	}
}
void DisplayState() {
	if(battle) {
		char Cle[101]="\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                     ";
		if(xuan[0].PN!=0)Cle[0]='\0';
		color(12);
		printf("%s 攻击力:%d+%d=%d  防御力:%d+%d=%d  HP:%d/%d PP:%d/%d \n\n\n",battle_player.name,battle_player.attack,gong,battle_player.attack+gong,battle_player.defense,fang,battle_player.defense+fang,battle_player.health,battle_player.max_health,battle_player.PP,battle_player.max_PP);
		printf("等级:%d  经验:%d/%d 还需要%d经验升级 金币:%d \n\n\n",battle_player.level,battle_player.exp,battle_player.max_exp,battle_player.max_exp-battle_player.exp,money);
		cout<<"攻装:"<<gongname<<"  防装:"<<fangname<<"  魂 :"<<hunname<<"  焰 :"<<yanname<<" \n\n\n";
		printf("特殊道具:巨人之木*%d，人鱼之泪*%d，法老之焰*%d，\n\n\n",strongman_arm,fishman_tail,falao_fire);
		printf("特殊道具:水之灵*%d，火之灵*%d，土之灵*%d，风之灵*%d，\n\n\n",shuiling,huoling,tuling,fengling);
		printf("携带宠物:%s，Lv.%d，技能：%s%s，攻：%d.%s\n\n\n",xuan[0].chu,xuan[0].level,xuan[0].PNm,Roman[(xuan[0].level+9)/10],xuan[0].attack,Cle);
	} else {
		char Cle[101]="\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                     ";
		if(xuan[0].PN!=0)Cle[0]='\0';
		color(11);
		printf("%s 攻击力:%d+%d=%d  防御力:%d+%d=%d  HP:%d/%d PP:%d/%d \n\n\n",player.name,player.attack,gong,player.attack+gong,player.defense,fang,player.defense+fang,player.health,player.max_health,player.PP,player.max_PP);
		printf("等级:%d  经验:%d/%d 还需要%d经验升级 金币:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money);
		cout<<"攻装:"<<gongname<<"  防装:"<<fangname<<"  魂 :"<<hunname<<"  焰 :"<<yanname<<" \n\n\n";
		printf("特殊道具:巨人之木*%d，人鱼之泪*%d，法老之焰*%d，\n\n\n",strongman_arm,fishman_tail,falao_fire);
		printf("特殊道具:水之灵*%d，火之灵*%d，土之灵*%d，风之灵*%d，\n\n\n",shuiling,huoling,tuling,fengling);
		printf("技能:%s，%s，%s，%s，\n\n\n",jn_1.name,jn_2.name,jn_3.name,jn_4.name);
		printf("携带宠物:%s，Lv.%d，技能：%s%s，攻：%d.%s\n\n\n",xuan[0].chu,xuan[0].level,xuan[0].PNm,Roman[(xuan[0].level+9)/10],xuan[0].attack,Cle);
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
		printf("要怎么办?\n\n\n    1,攻击 2,物品 3,查看状态 4,逃跑\n\n\n");
		cin>>st;
		switch(opw(st)) {
			case 1:
				printf("===================================================================================");
				printf("\n\n选择技能发动\n\n1,%s :%s\n\n2,%s :%s(PP：%d)\n\n3,%s :%s(PP：%d)\n\n4,%s :%s(PP：%d)\n\n5,%s :%s(PP：%d)\n\n0,返回\n",jn_0.name,jn_0.xxx,jn_1.name,jn_1.xxx,jn_1.pp,jn_2.name,jn_2.xxx,jn_2.pp,jn_3.name,jn_3.xxx,jn_3.pp,jn_4.name,jn_4.xxx,jn_4.pp);
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
					SlowDisplay("BOSS挑战不可逃跑\n\n\n");
				else {
					s=SuiJi();
					if(s<4) {
						printf("%s逃跑了~\n\n\n",player.name);
						player.health=battle_player.health;
						player.PP=battle_player.PP;
						battle=0;
						return;
					} else {
						printf("%s逃跑失败!\n\n\n",player.name);
						AttackResult();
					}
				}
				break;
			default:
				SlowDisplay("输入错误,重新输入!\n\n\n");
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
			printf("%s闪避!\n\n\n",guai.name);
		else {
			maybe=rand()%100;
			if(maybe<battle_player.baoji) {
				maybe=(rand()%100+100)/100;
				if((battle_player.attack+gong-guai.defense/3)*1.8<=0||(battle_player.attack+gong-guai.defense)/3*18/10<=0) {
					printf("%s攻击! %s减少1HP\n\n\n",player.name,guai.name);
					guai.health-=1;
					if(guai.health>=1)
						printf("%s还有%dHP\n\n",guai.name,guai.health);
				} else if((battle_player.attack+gong-guai.defense)/3*9/5>0) {
					printf("%s暴击! %sHP减少%d\n\n\n",player.name,guai.name,min((battle_player.attack+gong-guai.defense/3)*9/5,guai.health));
					guai.health-=min((battle_player.attack+gong-guai.defense/3)*9/5,guai.health);
					if(guai.health>0)printf("%s还有%dHP\n\n",guai.name,guai.health);
				}
			} else {
				s=SuiJi();
				if(battle_player.attack+s+gong-guai.defense/3<=0) {
					printf("%s攻击! %s减少1HP\n\n\n",player.name,guai.name);
					guai.health-=1;
					if(guai.health>=1)
						printf("%s还有%dHP\n\n",guai.name,guai.health);
				} else {
					printf("%s攻击! %s减少%dHP\n\n\n",player.name,guai.name,min(guai.health,battle_player.attack+s+gong-guai.defense/3));
					guai.health-=min(guai.health,battle_player.attack+s+gong-guai.defense/3);
					if(guai.health>0)printf("%s还有%dHP\n\n",guai.name,guai.health);
				}
			}
		}
	} else {
		switch(choose_number) {
			case 2:
				if(jn_1.num&&battle_player.PP>=jn_1.pp)jn_=jn_1;
				else if(battle_player.PP<=jn_1.pp) {
					printf("PP不够,请重新选择：");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("请重新选择：");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			case 3:
				if(jn_2.num&&battle_player.PP>=jn_2.pp)jn_=jn_2;
				else if(battle_player.PP<=jn_2.pp) {
					printf("PP不够,请重新选择：");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("请重新选择：");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			case 4:
				if(jn_3.num&&battle_player.PP>=jn_3.pp)jn_=jn_3;
				else if(battle_player.PP<=jn_3.pp) {
					printf("PP不够,请重新选择：");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("请重新选择：");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			case 5:
				if(jn_4.num&&battle_player.PP>=jn_4.pp)jn_=jn_4;
				else if(battle_player.PP<=jn_4.pp) {
					printf("PP不够,请重新选择：");
					cin>>st;
					choose_jn();
					return;
				} else {
					printf("请重新选择：");
					cin>>st;
					choose_jn();
					return;
				}
				break;
			default:
				printf("请重新选择：");
				cin>>st;
				choose_jn();
				return;
		}
		printf("%s发动了技能%s\n\n",player.name,jn_.name);
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
			printf("%s暴击! %sHP减少%d\n\n\n",player.name,guai.name,min((battle_player.attack+gong-guai.defense/3)*18/5,guai.health));
			guai.health-=min((battle_player.attack+gong-guai.defense/3)*18/5,guai.health);
			if(guai.health>=1)printf("%s还有%dHP\n\n",guai.name,guai.health);
		}
		if(jn_.xixe) {
			int b=rand()%100-50;
			printf("%s攻击了%s%dHP并从中吸取了%dHP\n\n\n",player.name,guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health),min(battle_player.max_health-battle_player.health,(min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health)/2+b)));
			guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health);
			battle_player.health+=min(battle_player.max_health-battle_player.health,(min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*4/5,guai.health)/2+b));
			if(guai.health>=1)printf("%s还有%dHP\n\n",guai.name,guai.health);
		}
		if(jn_.huimie) {
			if(rand()%10<3&&guai.boss_==0) {
				guai.health=0;
				printf("%s被秒杀\n\n\n",guai.name);
			} else {
				printf("%s减少HP%d\n\n\n",guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*18/5,guai.health));
				guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*18/5,guai.health);
			}
			if(guai.health>=1)printf("%s还有%dHP\n\n",guai.name,guai.health);
		}
		if(jn_.num==19) {
			printf("%s攻击! %sHP减少%d\n\n\n",player.name,guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health));
			guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health);
			if(dgggg<0) {
				printf("%s自身受到%6d点伤害\n\n\n",player.name,0-dgggg);
				battle_player.health+=dgggg;
				if(rand()%100<xuan[37].Baif&&xuan[37].PN==13) {
					SlowDisplay("横公鱼发动<邪病>,本次受到伤害无效化\n\n");
					battle_player.health==dgggg;
				}
				dgggg=0;
			}
			if(guai.health>=1)printf("%s还有%dHP\n\n",guai.name,guai.health);
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
						printf("%s攻击! %s减少1HP\n\n\n",player.name,guai.name);
						guai.health-=1;
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s又烧伤了\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s烧伤了\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s又中毒了\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s中毒了\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s又迷惑了\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s迷惑了\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s又被寄生了\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s被寄生了\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s又睡着了\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s睡着了\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s又被冰冻了\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s被冰冻了\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s又麻痹了\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s麻痹了\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s又混乱了\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s混乱了\n\n",guai.name);
							Sick=3;
						}
						if(guai.health>=1)printf("%s还有%6dHP\n\n",guai.name,guai.health);
					} else {
						printf("%s暴击! %sHP减少%d\n\n\n",player.name,guai.name,min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health));
						guai.health-=min((battle_player.attack+jn_.attack_jc+gong-guai.defense/3)*7/5,guai.health);
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s又烧伤了\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s烧伤了\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s又中毒了\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s中毒了\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s又迷惑了\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s迷惑了\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s又被寄生了\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s被寄生了\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s又睡着了\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s睡着了\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s又被冰冻了\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s被冰冻了\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s又麻痹了\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s麻痹了\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s又混乱了\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s混乱了\n\n",guai.name);
							Sick=3;
						}
						if(guai.health>0)printf("%s还有%6dHP\n\n",guai.name,guai.health);
					}
				} else {
					s=SuiJi();
					if(battle_player.attack+jn_.attack_jc+s+gong-guai.defense/3<=0) {
						printf("%s攻击! %s减少1HP\n\n\n",player.name,guai.name);
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s又烧伤了\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s烧伤了\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s又中毒了\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s中毒了\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s又迷惑了\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s迷惑了\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s又被寄生了\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s被寄生了\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s又睡着了\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s睡着了\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s又被冰冻了\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s被冰冻了\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s又麻痹了\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s麻痹了\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s又混乱了\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s混乱了\n\n",guai.name);
							Sick=3;
						}
						guai.health-=1;
						if(guai.health>=1)printf("%s还有%6dHP\n\n",guai.name,guai.health);
					} else {
						int a=min(guai.health,battle_player.attack+jn_.attack_jc+gong-guai.defense/3);
						printf("%s攻击! %sHP减少%d\n\n\n",player.name,guai.name,a);
						guai.health-=a;
						if(jn_.shaoshang&&Fire!=0) {
							printf("%s又烧伤了\n\n",guai.name);
							Fire=3;
						} else if(jn_.shaoshang) {
							printf("%s烧伤了\n\n",guai.name);
							Fire=3;
						}
						if(jn_.zhongdu&&Kill!=0) {
							printf("%s又中毒了\n\n",guai.name);
							Kill=3;
						} else if(jn_.zhongdu) {
							printf("%s中毒了\n\n",guai.name);
							Kill=3;
						}
						if(jn_.mihuo&&Wory!=0) {
							printf("%s又迷惑了\n\n",guai.name);
							Wory=3;
						} else if(jn_.mihuo) {
							printf("%s迷惑了\n\n",guai.name);
							Wory=3;
						}
						if(jn_.jisheng&&Squid!=0) {
							printf("%s又被寄生了\n\n",guai.name);
							Squid=3;
						} else if(jn_.jisheng) {
							printf("%s被寄生了\n\n",guai.name);
							Squid=3;
						}
						if(jn_.cuimian&&Slp!=0) {
							printf("%s又睡着了\n\n",guai.name);
							Slp=3;
						} else if(jn_.cuimian) {
							printf("%s睡着了\n\n",guai.name);
							Slp=3;
						}
						if(jn_.dongjie&&Ice!=0) {
							printf("%s又被冰冻了\n\n",guai.name);
							Ice=3;
						} else if(jn_.dongjie) {
							printf("%s被冰冻了\n\n",guai.name);
							Ice=3;
						}
						if(jn_.mabi&&Elec!=0) {
							printf("%s又麻痹了\n\n",guai.name);
							Elec=3;
						} else if(jn_.mabi) {
							printf("%s麻痹了\n\n",guai.name);
							Elec=3;
						}
						if(jn_.hunluan&&Sick!=0) {
							printf("%s又混乱了\n\n",guai.name);
							Sick=3;
						} else if(jn_.hunluan) {
							printf("%s混乱了\n\n",guai.name);
							Sick=3;
						}
						if(guai.health>=0)printf("%s还有%6dHP\n\n",guai.name,guai.health);
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
					SlowDisplay("发动<冲击>，对敌人造成了");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)/3+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)/3+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("点伤害\n\n");
					break;
				}
				break;
				case -4: {
					int agn=rand()%40+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<天阳>，对敌人造成了");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)/3+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)/3+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("点伤害\n\n");
					agn=rand()%50;
					if(agn<30) {
						SlowDisplay(",并造成敌人烧伤\n\n");
						Fire+=2;
					}
					break;
				}
				break;
				case -5: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<投掷>，对敌人造成了");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)/3+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)/3+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("点伤害\n\n");
					if(battle_player.miss<=86)
						battle_player.miss+=4;
					else battle_player.miss=90;
					break;
				}
				case -7: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<祥瑞>，你回复了");
					cout<<min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					battle_player.health+=min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					SlowDisplay("点HP\n\n");
					break;
				}
				case -8:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<填海>");
					if(guai.color==9) {
						cout<<"大幅降低对方的攻击，防御\n\n";
						guai.attack*=4;
						guai.attack/=7;
						guai.defense*=4;
						guai.defense/=7;
					} else cout<<"却并没有什么用\n\n";
					break;
				case -15: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<虎跃>，对敌人造成了");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min(guai.health,(xuan[37].attack-guai.defense)/4*3+agn);
						guai.health-=min(guai.health,(xuan[37].attack-guai.defense)/4*3+agn);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("点伤害\n\n");
					break;
				}
				case 1:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<催眠>，敌人睡着了\n\n");
					Slp+=2;
					break;
				case 2:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<震慑>，敌人攻击下降了\n\n");
					guai.attack*=5;
					guai.attack/=7;
					break;
				case 3:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<奋战>，敌人防御下降了\n\n");
					guai.defense*=5;
					guai.defense/=7;
					break;
				case 4:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<吼退>，敌人攻击和防御下降了\n\n");
					guai.defense*=6;
					guai.defense/=7;
					guai.attack*=6;
					guai.attack/=7;
					break;
				case 5: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<佛香>，你回复了");
					cout<<min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					battle_player.health+=min(battle_player.max_health-battle_player.health,xuan[37].attack+agn);
					SlowDisplay("点HP\n\n");
					break;
				}
				break;
				case 6:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<坚稳>，玩家暴击率上升了\n\n");
					if(battle_player.baoji<=86)
						battle_player.baoji+=4;
					else battle_player.baoji=90;
					break;
				case 7:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<肃然>\n\n");
					suran=1;
					break;
				case 8:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<斯文>，玩家攻击上升了\n\n");
					battle_player.baoji*=5;
					battle_player.attack/=4;
					break;
				case 9:
					printf("%s",xuan[0].name);
					SlowDisplay("发动<消火>");
					if(guai.color==12) {
						cout<<"大幅降低对方的攻击\n\n";
						guai.attack*=4;
						guai.attack/=7;
					} else cout<<"却并没有什么用\n\n";
					break;
				case 10: {
					int agn=rand()%40+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<兴雨>，暴击对敌人造成了");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)*3/2+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)*3/2+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("点伤害,并提升了玩家的攻击，防御\n\n");
					battle_player.attack=battle_player.attack*11/10;
					battle_player.defense=battle_player.defense*11/10;
					break;
				}
				case 11: {
					int agn=rand()%40+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<水起>，对敌人造成了");
					if(xuan[37].attack-guai.defense>0) {
						cout<<min((xuan[37].attack-guai.defense)*5/4+agn,guai.health);
						guai.health-=min((xuan[37].attack-guai.defense)*5/4+agn,guai.health);
					} else cout<<agn;
					guai.health-=agn;
					SlowDisplay("点伤害\n\n");
					break;
				}
				case 12: {
					int agn=rand()%5+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<青阳>\n\n");
					if(agn<3)cout<<"却什么也没有发生\n\n";
					else if(agn<4) {
						Fire+=2;
						cout<<"敌人烧伤了\n\n";
					} else if(agn<5) {
						Elec+=2;
						cout<<"敌人麻痹了\n\n";
					} else if(agn<6) {
						Ice+=2;
						cout<<"敌人被冻结了\n\n";
					}
					break;
				}
				case 18: {
					int agn=rand()%30+1;
					printf("%s",xuan[0].name);
					SlowDisplay("发动<龙马>，你回复了");
					cout<<min(xuan[37].attack/10+agn,battle_player.max_PP-battle_player.PP);
					battle_player.health+=min(xuan[37].attack/10+agn,battle_player.max_PP-battle_player.PP);
					SlowDisplay("点PP\n\n");
					break;
				}
				break;
				default:
					if(xuan[37].Hav!=0) {
						int agn=rand()%50;
						SlowDisplay(xuan[37].name);
						if(rand()%100>=xuan[37].baoji) {
							SlowDisplay("攻击，给敌人造成");
							cout<<min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
							guai.health-=min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
							SlowDisplay("点攻击\n\n");
						} else {
							SlowDisplay("暴击，给敌人造成");
							cout<<min(guai.health,(abs(xuan[37].attack-guai.defense)/3+agn)*9/5);
							guai.health-=min(guai.health,(abs(xuan[37].attack-guai.defense)/3+agn)*9/5);
							SlowDisplay("点攻击\n\n");
						}
					}
					break;
			}
		} else {
			if(xuan[37].Hav!=0) {
				int agn=rand()%50;
				SlowDisplay(xuan[37].name);
				if(rand()%100>=xuan[37].baoji) {
					SlowDisplay("攻击，给敌人造成");
					cout<<min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
					guai.health-=min(guai.health,abs(xuan[37].attack-guai.defense)/3+agn);
					SlowDisplay("点攻击\n\n");
				} else {
					SlowDisplay("暴击，给敌人造成");
					cout<<min((abs(xuan[37].attack-guai.defense)/3+agn)*9/5,guai.health);
					guai.health-=min((abs(xuan[37].attack-guai.defense)/3+agn)*9/5,guai.health);
					SlowDisplay("点攻击\n\n");
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
	printf("\n金色技能为你所拥有而未学或已忘记了的技能：（输入技能名称以学习）\n");
	color(8);
	if(jn_jszz.hadd==1&&jn_jszz.haddd==0)color(14);
	printf("1,寄生种子:投掷苞弹寄生敌人\n");
	color(8);
	if(jn_mtdz.hadd==1&&jn_mtdz.haddd==0)color(14);
	printf("2,漫天毒针:使对方中毒\n");
	color(8);
	if(jn_mhsx.hadd==1&&jn_mhsx.haddd==0)color(14);
	printf("3,迷惑射线:使对方迷惑\n");
	color(8);
	if(jn_xhly.hadd==1&&jn_xhly.haddd==0)color(14);
	printf("4,星火燎原:使对方烧伤\n");
	color(8);
	if(jn_nljt.hadd==1&&jn_nljt.haddd==0)color(14);
	printf("5,怒雷九天:使对方麻痹\n");
	color(8);
	if(jn_phsg.hadd==1&&jn_phsg.haddd==0)color(14);
	printf("6,破坏死光:使对方混乱\n");
	color(8);
	if(jn_hdjt.hadd==1&&jn_hdjt.haddd==0)color(14);
	printf("7,寒冻九天:使对方冻结\n");
	color(8);
	if(jn_kghw.hadd==1&&jn_kghw.haddd==0)color(14);
	printf("8,枯骨黑雾:使对方昏迷\n");
	color(8);
	if(jn_jpzs.hadd==1&&jn_jpzs.haddd==0)color(14);
	printf("9,巨炮之术:无法闪避，必定暴击\n");
	color(8);
	if(jn_getb.hadd==1&&jn_getb.haddd==0)color(14);
	printf("10,噬血狂术:攻击敌人并吸取敌人一定HP\n");
	color(8);
	if(jn_htmd.hadd==1&&jn_htmd.haddd==0)color(14);
	printf("11,毁天灭地:倾尽全力，造成极大的伤害，有一定几率秒杀（对BOSS无效）\n");
	color(8);
	if(jn_lpjq.hadd==1&&jn_lpjq.haddd==0)color(14);
	printf("12,龙盘聚气:能够回复少量PP\n");
	color(8);
	if(jn_lztx.hadd==1&&jn_lztx.haddd==0)color(14);
	printf("13,龙之吐息:能够回复大量PP\n");
	color(8);
	if(jn_zszs.hadd==1&&jn_zszs.haddd==0)color(14);
	printf("14,再生之术:能够回复少量HP\n");
	color(8);
	if(jn_hgfz.hadd==1&&jn_hgfz.haddd==0)color(14);
	printf("15,回光返照:能够回复大量HP\n");
	color(8);
	if(jn_xjzq.hadd==1&&jn_xjzq.haddd==0)color(14);
	printf("16,血祭之气:能够回满PP,但需要一定的HP作为代价\n");
	color(8);
	if(jn_gzpz.hadd==1&&jn_gzpz.haddd==0)color(14);
	printf("17,光之屏障:3回合内，抵御一半魔法伤害\n");
	color(8);
	if(jn_tqtb.hadd==1&&jn_tqtb.haddd==0)color(14);
	printf("18,铜墙铁壁:3回合内，抵御一半物理伤害\n");
	color(8);
	if(jn_jjcj.hadd==1&&jn_jjcj.haddd==0)color(14);
	printf("19,究极冲击:杀伤力极高，但自身也会受到一定的伤害\n");
	color(8);
	if(jn_jmfs.hadd==1&&jn_jmfs.haddd==0)color(14);
	printf("20,镜面反射:能将对方本回合对你的伤害反弹回敌人身上\n");
	color(8);
	if(jn_scfs.hadd==1&&jn_scfs.haddd==0)color(14);
	printf("21,双重反射:能将对方本回合对你的伤害双倍反弹回敌人身上\n");
	color(8);
	if(jn_xhys.hadd==1&&jn_xhys.haddd==0)color(14);
	printf("22,虚化隐术:2回合内敌人命中率降低90%，但自身也会因此极其脆弱\n");
	color(8);
	printf("0,返回");
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
			} else printf("你没有这个技能……\n\n");
			break;
		case 2:
			if(jn_mtdz.hadd==1&&jn_mtdz.haddd==0) {
				jn_=jn_mtdz;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 3:
			if(jn_mhsx.hadd==1&&jn_mhsx.haddd==0) {
				jn_=jn_mhsx;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 4:
			if(jn_xhly.hadd==1&&jn_xhly.haddd==0) {
				jn_=jn_xhly;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 5:
			if(jn_nljt.hadd==1&&jn_nljt.haddd==0) {
				jn_=jn_nljt;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 6:
			if(jn_phsg.hadd==1&&jn_phsg.haddd==0) {
				jn_=jn_phsg;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 7:
			if(jn_hdjt.hadd==1&&jn_hdjt.haddd==0) {
				jn_=jn_hdjt;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 8:
			if(jn_kghw.hadd==1&&jn_kghw.haddd==0) {
				jn_=jn_kghw;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 9:
			if(jn_jpzs.hadd==1&&jn_jpzs.haddd==0) {
				jn_=jn_jpzs;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 10:
			if(jn_getb.hadd==1&&jn_getb.haddd==0) {
				jn_=jn_getb;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 11:
			if(jn_htmd.hadd==1&&jn_htmd.haddd==0) {
				jn_=jn_htmd;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 12:
			if(jn_lpjq.hadd==1&&jn_lpjq.haddd==0) {
				jn_=jn_lpjq;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 13:
			if(jn_lztx.hadd==1&&jn_lztx.haddd==0) {
				jn_=jn_lztx;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 14:
			if(jn_zszs.hadd==1&&jn_zszs.haddd==0) {
				jn_=jn_zszs;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 15:
			if(jn_hgfz.hadd==1&&jn_hgfz.haddd==0) {
				jn_=jn_hgfz;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 16:
			if(jn_xjzq.hadd==1&&jn_xjzq.haddd==0) {
				jn_=jn_xjzq;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 17:
			if(jn_gzpz.hadd==1&&jn_gzpz.haddd==0) {
				jn_=jn_gzpz;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 18:
			if(jn_tqtb.hadd==1&&jn_tqtb.haddd==0) {
				jn_=jn_tqtb;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 19:
			if(jn_jjcj.hadd==1&&jn_jjcj.haddd==0) {
				jn_=jn_jjcj;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 20:
			if(jn_jmfs.hadd==1&&jn_jmfs.haddd==0) {
				jn_=jn_jmfs;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 21:
			if(jn_scfs.hadd==1&&jn_scfs.haddd==0) {
				jn_=jn_scfs;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
		case 22:
			if(jn_xhys.hadd==1&&jn_xhys.haddd==0) {
				jn_=jn_xhys;
				changejn();
			} else printf("你没有这个技能……\n\n");
			break;
	}
}
void changejn() {
	printf("\n===================================================================================\n");
	printf("请选择一个技能替换:\n");
	printf("1:%s:%s\n",jn_1.name,jn_1.xxx);
	printf("2:%s:%s\n",jn_2.name,jn_2.xxx);
	printf("3:%s:%s\n",jn_3.name,jn_3.xxx);
	printf("4:%s:%s\n",jn_4.name,jn_4.xxx);
	printf("0:返回\n");
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
			SlowDisplay("输入错误\n\n\n");
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
		SlowDisplay("驯兽大师：你就是他们谈到的那个勇士？\n\n");
		SlowDisplay(player.name);
		SlowDisplay("：是的\n\n驯兽大师：哦，你的任务实在重要，想必你也需要帮助吧，那宠物就是个好助手了，我可以送你一只\n\n");
		SlowDisplay("请在下面的宠物中挑选一只：\n\n");
		int t=0;
		Hpet=1;
		for(int i=1; i<=36; i++) {
			if(xuan[i].PN==10) {
				t=1;
				continue;
			}
			printf("%d,%s：%s(%s)\n",i-t,xuan[i].name,xuan[i].PNm,xuan[i].XM);
			xuan[i].Lup+=20;
		}
		xuan[27].Lup+=20;
		cin>>st;
		while(opw(st)>=36||opw(st)<=0) {
			printf("你在说啥？\n\n");
			cin>>st;
		}
		t=opw(st);
		if(xuan[t].PN>=10)t++;
		xuan[t].Hav=1;
		xuan[t].level=1;
		SlowDisplay("你获得了");
		SlowDisplay(xuan[t].name);
		SlowDisplay("\n驯兽大师：喏，这里是它们的进阶道具，拿好\n\n另外，宠物进阶等你也可以来咨询我哦\n\n");
	} else {
		while(1) {
			int an=0;
			for(int i=18; i<=26; i++) {
				an+=xuan[i].Hav;
			}
			if(an>=3&&xuan[27].Hav==0) {
				SlowDisplay("驯兽大师：小伙，没看出来啊，你竟然获得了九龙里的三龙了\n\n");
				SlowDisplay("驯兽大师：跟我来,你可要有心理准备啊\n\n");
				SlowDisplay("你来到了一个祭坛前");
				for(int i=18; i<=26; i++) {
					SlowDisplay(",");
					SlowDisplay(xuan[i].name);
				}
				SlowDisplay("从身边掠过，飞向祭坛\n\n");
				SlowDisplay("在一道强光中，一道黑影逐渐清晰\n\n");
				guai=xian[27];
				SlowDisplay("黑影渐渐变大，变清晰，一条龙出现在你的面前\n\n");
				SlowDisplay("那是龙王!!!\n\n");
				color(15);
				SlowDisplay("龙王");
				color(12);
				SlowDisplay("冲了出来\n\n");
				battle=1;
				BattleAct();
			} else {
				printf("你想做什么？\n\n");
				printf("1,宠物进阶 2,一键进阶 0,返回");
				printf("\n===================================================================================\n");
				cin>>st;
				switch(opw(st)) {
					case 1: {
						for(int i=1; i<=36; i++)
							printf("%d,%s(%d级)%s*%d\n",i,xuan[i].chu,xuan[i].level,xuan[i].Lvup,xuan[i].Lup);
						cin>>st;
						while(opw(st)>36||opw(st)<0) {
							cout<<"输入错误\n\n";
							cin>>st;
						}
						if(opw(st)==0)break;
						if(xuan[opw(st)].Hav==0) {
							SlowDisplay("你还没有");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("\n\n");
						} else if(xuan[opw(st)].level==100) {
							SlowDisplay("你的");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("已经满级了\n\n");
						} else {
							xuan[opw(st)].Lup--;
							xuan[opw(st)].level++;
							xuan[opw(st)].attack+=(xuan[opw(st)].attack_+rand()%5-2);
							if(xuan[opw(st)].level%10==1) {
								if(xuan[opw(st)].level==11) {
									char cs[3]="虚";
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
									char cs[5]="真·";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].chu[2]=cs[2];
									xuan[opw(st)].chu[3]=cs[3];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==41) {
									char cs[3]="绊";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==51) {
									char cs[3]="幻";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==61) {
									char cs[3]="圣";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==71) {
									char cs[3]="帝";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==81) {
									char cs[3]="祖";
									xuan[opw(st)].chu[0]=cs[0];
									xuan[opw(st)].chu[1]=cs[1];
									xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
								} else if(xuan[opw(st)].level==91) {
									char cs[5]="始源";
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
							printf("%d,%s(%d级)%s*%d\n",i,xuan[i].chu,xuan[i].level,xuan[i].Lvup,xuan[i].Lup);
						cin>>st;
						while(opw(st)>36||opw(st)<0) {
							cout<<"输入错误\n\n";
							cin>>st;
						}
						if(opw(st)==0)break;
						if(xuan[opw(st)].Hav==0) {
							SlowDisplay("你还没有");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("\n\n");
						} else if(xuan[opw(st)].level==100) {
							SlowDisplay("你的");
							SlowDisplay(xuan[opw(st)].name);
							SlowDisplay("已经满级了\n\n");
						} else {
							while(xuan[opw(st)].Lup>0&&xuan[opw(st)].level!=100) {
								xuan[opw(st)].Lup--;
								xuan[opw(st)].level++;
								xuan[opw(st)].attack+=(xuan[opw(st)].attack_+rand()%5-2);
								if(xuan[opw(st)].level%10==1) {
									if(xuan[opw(st)].level==11) {
										char cs[3]="虚";
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
										char cs[5]="真·";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].chu[2]=cs[2];
										xuan[opw(st)].chu[3]=cs[3];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==41) {
										char cs[3]="绊";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==51) {
										char cs[3]="幻";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==61) {
										char cs[3]="圣";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==71) {
										char cs[3]="帝";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==81) {
										char cs[3]="祖";
										xuan[opw(st)].chu[0]=cs[0];
										xuan[opw(st)].chu[1]=cs[1];
										xuan[opw(st)].Baif+=xuan[opw(st)].Baif_;
									} else if(xuan[opw(st)].level==91) {
										char cs[5]="始源";
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
	cout<<"读入中……\n\n";
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
	cout<<"读入成功！\n\n";
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
				printf("计时器\n");
				b_=(a_/3600+8)%24;
				c_=(a_/60)%60;
				d_=a_%60;
				printf("%02d:%02d:%02d\n",b_,c_,d_);
			}
			a1_=a_;
			if(a_==first_+5)break;
		}
	}
	cout<<"你一共点击了"<<num_<<"下\n\n";
	cout<<"你获得了"<<num_<<"元\n\n";
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
			cout<<"挂机中，按任意键可退出……\n\n(你已挂机"<<(a_-b_)/60<<"min"<<(a_-b_)%60<<"s)";
		}
		c_=a_;
		cout<<" \b";
	}
	system("CLS");
	char ch_=getch();
	cout<<"你在挂机池中待了"<<(a_-b_)/60<<"min"<<(a_-b_)%60<<"s,获得"<<(a_-b_)*stay/3<<"元\n";
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
	cout<<"╔═════════════════════╗"<<endl;
	cout<<"║                                           ║"<<endl;
	cout<<"╚═════════════════════╝"<<endl;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	color(11);
	for(int i=0;i<21;i++)
	{
		Sleep(rand()%2*p);
		cout<<"█";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	Sleep(1000);
}
