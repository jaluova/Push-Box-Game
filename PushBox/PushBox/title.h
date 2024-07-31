//--------------------------------基础头文件--------------------------------
#include <stdio.h>               //用于实现基础功能
#include <windows.h>             //用于控制光标,字体颜色,音乐播放(仅windows平台)
#include <conio.h>               //用于实现键盘输入,如kbhit(),getch()等函数
#include <time.h>                //帧数,速度控制,随机数生成
#include <stdlib.h>              //用于动态内存,system()
#include <Mmsystem.h>            //用于音乐播放,需要放在#include <windows.h>代码下面
#pragma comment(lib,"winmm.lib") //用于音乐播放,导入winmm库

//禁用vs中不必要的警告,如scanf不安全等
#pragma warning(disable:4996)
#pragma warning(disable:6031)

//宏定义一下按键  不过要注意,这个是不能改的,这是按照ASCII码来的
#define ESC   27
#define ENTER 13

//----------------------------------数据设计--------------------------------
/*
   地图:
       map[ROW][COL]表示一个大小ROW行COL列的地图
       map[i][j]表示  数组图表  上的第i行,第j列的值
       0表示空地                   例:
       1表示普通墙体                  {
       2表示玩家                       {0,0,0,0},
       3表示箱子                       {0,0,0,0}
       4表示目标点                     {0,0,0,0}
       5表示人在目标点上                {1,0,0,0}
       6表示箱子在目标点上             }
       (红蓝砖规则之后考虑)            map[4][1]=1
*/
#define ROW 15    //行
#define COL 15    //列

#define KONG     0   //空地   
#define WALL     1   //墙体   
#define PLAYER   2   //玩家 
#define BOX      3   //箱子   
#define DEST     4   //目标点
#define POND     5   //PlayerONDest简写为POND
#define BOND     6   //BoxONDest简写为BOND  

#define RWALL    7   //红墙
#define RWALL2  -7   //可走过的红墙
#define PONRW   -1   //player on redwall可走过的红墙
#define BONRW   -3   //箱子在可走过的红墙上

#define BWALL    8   //蓝墙
#define BWALL2  -8   //可走过的蓝墙
#define PONBW   -2   //player on bluewall可走过的蓝墙
#define BONBW   -4   //箱子在可走过的蓝墙上

#define RDEST    9   //红目标点
#define BONRD   -9   //箱子在红目标点
#define PONRD   -5   //玩家在红目标点

#define BDEST   10   //蓝目标点
#define BONBD  -10   //箱子在蓝目标点
#define PONBD   -6   //玩家在蓝目标点
//这个是宏定义,之后就可以用map[i][j]=PLAYER这种形式直观地表示玩家的位置了
extern int map[ROW][COL];


/*
   临时地图:
           temp[LEVEL]ROW][COL]表示LEVEL张大小ROW行COL列的临时地图
           temp[level][i][j],level表示关卡数

*/
#define LEVEL  20  //总关卡数
extern int temp[LEVEL][ROW][COL];

/*
   玩家坐标:
          x表示玩家横坐标;
          y表示玩家纵坐标;
          但是要注意与map[i][j]中i,j的关系
         O┌─────────────→x   这个控制台中光标所确定的坐标关系
          │                  而一个墙体"口"看似是正方形
          │                  实际上占了两个单位的横坐标,一个单位的纵坐标
          │                  因此我们有对应关系
          │                  2j=x,i=y
          ↓                  这个在打印和移动中容易弄错
          y
*/
extern int x, y;

/*
   游戏关卡数:
         输入各函数的基础数据
*/
extern int level;

/*
   其他数据(拓展):
*/
extern int foot[LEVEL];   //游戏步数
extern int style;         //游戏风格
extern int volume1;       //音乐大小
extern int volume2;       //音效大小
extern int rank[3][LEVEL];//游戏排行 只表示前三名
extern int music_num;     //音乐代号
/*
0  经典音乐
1  英雄之证
2  Kongo
3  MC
4  钢琴曲


*/
//----------------------------------数据设计--------------------------------


//----------------------------------service--------------------------------

/*
    负责人:minato
    功能: 根据关卡号,初始化游戏数据
        1. 根据关卡号 获取temp[level][][]的内容
        2. 依次赋值给map数组(遍历)
        3. 在map数组中,找到玩家坐标,赋值给x,y

    参数: level关卡号
    返回值: void

*/
void init(int level);

/*
    负责人:minato,余某
    功能:移动,并判断移动的结果(玩家单独移动,和箱子一起移动,无法移动)
       1.根据玩家坐标,确认前进方向情况,判断移动结果
       2. 如果
            1)玩家前面是空地或者空目的地       移动并修改map和xy的值 重新打印
                    返回1
            2)玩家前面是箱子 判断箱子后面
                 如果是墙或者箱子或者满目的地   移动失败
                    返回0
                 如果是空地或者空目的地         移动并修改map和xy的值 重新打印
                    返回1
             3)玩家前面是墙                   移动失败
                    返回0
    参数: dir,表示用户输入的方向  需要用到getch()函数
    返回值: int,0表示移动失败,1表示移动成功
*/
int move(char dir);
int movejudge(int a, int b, int c, int d, int e, int f);//用于简化代码的判定函数,由组长余某设计


/*
    负责人:余某
    功能:判断有色目标点是否被填满
         如果红色被填满  修改地图值，返回1
         如果蓝色被填满  修改地图值，返回2
         如果无         返回0
    参数: void
    返回值: 0  1  2
*/
int isClear();

/*
    负责人:余某
    功能: 游戏胜利判断
        判断地图中是否有单独的箱子
        如果有     返回0
        如果没有   返回1
    参数: void
    返回值: 0表示没有胜利  1表示游戏胜利

*/
int isWin();
void Printf(row, col);//用于打印移动后的图像以及覆盖移动前的图像

//----------------------------------service--------------------------------

//------------------------------------view---------------------------------

/*
    负责人:阿氟
    功能:
            1.根据关卡号初始化数据map,x,y
        init(level);

            2. 打印游戏界面
        gameView_ShowMap(level);
        while(1){

            3. 接收输入:
               判断输入的类型
        switch case
        esc: 暂停 调用暂停界面
        w|s|a|d（大小写都考虑）:if(move())

            4. 移动结果
                移动失败 continue;
                移动成功 下一步

            5. 判断
         胜利判断
         if(isWin())
                实现界面转换
        }
    参数: level表示关卡号
    返回值: void
*/
void gameView(int level);


/*
    负责人:阿氟,余某
    功能:遍历map数组,读取数据,打印相应图形
        根据设置中的判断,选择游戏风格
    参数: level表示关卡号
    返回值: void
*/
void gameView_ShowMap(int level);

/*
    负责人:涵
    功能:以游戏原型图为准
        1. 展示菜单选项: 开始游戏 游戏设置 排行榜 游戏说明 退出游戏
        2. 接收用户输入
            w/s 切换上下
            回车 调用函数
        3. 根据用户选择 调用不同的界面
            开始游戏:进入选关界面 levelchoose()
            游戏设置:进入设置界面 setupView()
            排行榜:进入排行榜界面 rankView()
            游戏说明:进入说明界面 instruView()
            退出游戏: exitView()
    参数: void
    返回值: void

*/
void menuView();

/*
    负责人:涵,阿氟
    功能:以游戏原型图为准
        1.展示选关界面
        2.接收用户输入
            w s切换上下
            在选择关卡时，输入a d进行切换关卡（修改level的值）
            回车进行选择
        3.根据选择调用函数
    参数: void
    返回值: void

*/
void levelchoose();

/*
    负责人:阿绾
    功能:以游戏原型图为准   游戏设置
    参数: void
    返回值: void

*/
void setupView();

/*
    负责人:无阁,阿氟
    功能:以游戏原型图为准   排行榜
    参数: void
    返回值: void

*/
void rankView();

/*
    负责人:无阁
    功能:以游戏原型图为准    游戏说明
        打印游戏说明
        接收输入：
            w s切换选择
            esc返回主菜单，调用menuView()
            回车：进行选择
        根据选择调用对应的界面函数
    参数: void
    返回值: void

*/
void instruView();

/*
    负责人:土豆
    功能:以游戏原型图为准    游戏玩法说明
        打印游戏玩法说明
        接收输入：输入esc或回车返回,调用void instruView()
    参数: void
    返回值: void

*/
void instruView_1();

/*
    负责人:土豆
    功能:以游戏原型图为准     制作组介绍
        打印制作组信息
        接收输入：输入esc或回车返回,调用void instruView()
    参数: void
    返回值: void

*/
void instruView_2();

/*
    负责人:阿梦
    功能:以游戏原型图为准
        根据关卡数,打印胜利界面(包含最终胜利)
        接受玩家输入,进入下一关或其他
    参数: void
    返回值: void

*/
void winView();

/*
    负责人:阿梦
    功能:以游戏原型图为准      退出游戏
        "真的忍心离开吗"
        接收输入
            w s 进行选择
            回车确认选择
        根据选择调用相应函数
        exit(0);
    参数: void
    返回值: void

*/
void exitView();

/*
    负责人:阿绾
    功能:以游戏原型图为准     暂停界面
         暂停游戏界面
    参数: void
    返回值: void

*/
void pauseView();

//------------------------------------view---------------------------------





//------------------------------------print--------------------------------

void color(int c);//颜色

void HideCursor();//隐藏光标

void CursorJump(int x, int y);//光标跳转

void printBOX();//打印界面边框

//------------------------------------print--------------------------------
 




//------------------------------------music--------------------------------

/*
    负责人:阿绾
    功能:负责音乐开关,一些场景要考虑音乐重复播放
    参数: t等于1,播放音乐;t等于0,关闭音乐
    返回值: void

*/

//菜单音乐
void m_menu(int t);

//游戏音乐
void m_game(int t);

//排行榜
void m_rank(int t);

//胜利音乐
void m_win();

//游戏音效
void m_move();  //移动光标

void m_click(); //进行选择

//------------------------------------music---------------------------------




//-------------------------------------rank---------------------------------
/*
   负责人:阿氟
   功能:实现排行榜的基本功能
   参数: level,data
   返回值: void
*/


void printRNAK();//打印排行榜信息

void givenum(int ch, int* p);//辅助读取数据

void givestring(char* p, int a);//辅助写入数据

void WriteData(int data);//写入数据

void ReadData();//读取数据

void initRank();//将排行榜文件中的值全部重置为0

//-------------------------------------rank---------------------------------




//------------------------------------create--------------------------------
                          
extern int create_num;

void createInit(int level);

void createView(int level);

void createView_ShowMap(int level);

int createMove(char input);

void createRead(int t);

void createWrite();

void createExit();

void createCursor();

void createPrint(int row, int col);

//------------------------------------create--------------------------------



