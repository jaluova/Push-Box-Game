//*****
#include "title.h"

void gameView(int level) {
	system("cls");//清屏
	m_menu(0);//关闭菜单音乐
	m_rank(0);//关闭排行榜音乐
	m_game(1);//打开游戏音乐
	
	if (foot[level] == 0)//如果步数为零则初始化游戏数据(考虑到暂停游戏的情况)
		init(level);

	gameView_ShowMap(level);//打印游戏界面
	
	do {
		CursorJump(4, 2);
		printf("步数:%d", foot[level]);//实时显示步数
		int input = getch();//接受输入
		m_move();//音效
		switch (input) {
		case ESC://暂停
			pauseView();
		case 'w'://移动
		case 'W':
		case 'a':
		case 'A':
		case 's':
		case 'S':
		case 'd':
		case 'D':
			if (move(input)) {//判定是否可移动
				Printf(x + 1, y);//局部打印重绘,避免显示错误
                foot[level]++;//步数加一
				if (isWin() == 1)//判定胜利
					winView(level);//调出胜利画面
				else
					continue;//否则,继续循环
			}
			else
				continue;//否则,继续循环
		}
	}while (1);//循环
} 

void gameView_ShowMap(int level) {
	for (int row = 0;row < ROW;row++) {
		CursorJump(12, row + 1);
		for (int col = 0;col < COL;col++) {//根据数组的值,打印各类方块
			switch (map[col][row]) {
			case KONG:
				printf("  ");
				break;
			case PLAYER:
				color(0x02); //绿色
				printf("囧");
				color(0x07); //白色
				break;
			case POND:
				color(0x62); //黄底绿色
				printf("囧");
				color(0x07); //白色
			case PONBD:
				color(0x12); //蓝底绿色
				printf("囧");
				color(0x07); //白色
				break;
			case PONRD:
				color(0x42); //红底绿色
				printf("囧");
				color(0x07); //白色
				break;
			case PONBW:
				color(0x01); //蓝色
				printf("囧");
				color(0x07); //白色
				break;
			case PONRW:
				color(0x04); //红色
				printf("囧");
				color(0x07); //白色
				break;


			case BOX:
				color(0x06); //黄色
				printf("口");
				color(0x07); //白色
				break;
			case BOND:
				color(0x60); //黄底黑色
				printf("口");
				color(0x07); //白色
				break;
			case BONBD:
				color(0x16); //蓝底黄色
				printf("口");
				color(0x07); //白色
				break;
			case BONRD:
				color(0x46); //红底黄色
				printf("口");
				color(0x07); //白色
				break;
			case BONBW:
				color(0x01); //蓝色
				printf("回");
				color(0x07); //白色
				break;
			case BONRW:
				color(0x04); //红色
				printf("回");
				color(0x07); //白色
				break;


			case WALL:
				color(0x07); //白色
				printf("口");
				break;
			case BWALL:
				color(0x01); //蓝色
				printf("口");
				color(0x07); //白色
				break;
			case RWALL:
				color(0x04); //红色
				printf("口");
				color(0x07); //白色
				break;
			case BWALL2:
				color(0x01); //蓝色
				printf("**");
				color(0x07); //白色
				break;
			case RWALL2:
				color(0x04); //红色
				printf("**");
				color(0x07); //白色
				break;


			case DEST:
				color(0x60); //黄底
				printf("  ");
				color(0x07); //白色
				break;
			case BDEST:
				color(0x10); //蓝底
				printf("  ");
				color(0x07); //白色
				break;
			case RDEST:
				color(0x40); //红底
				printf("  ");
				color(0x07); //白色
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		CursorJump(i * 2, 0);
		printf("口");
	}	
	for (int i = 0; i < 26; i++) {
		CursorJump(i * 2, 16);
		printf("口");
	}
	for (int i = 0; i < 17; i++) {
		CursorJump(0, i);
		printf("口");
	}
	for (int i = 0; i < 17; i++) {
		CursorJump(26 * 2, i);
		printf("口");
	}
	CursorJump(4, 1);
	printf("第%d关", level + 1);//打印显示相关提示文字
	CursorJump(4, 3);
	printf("移动：");
	CursorJump(4, 4);
	printf("wasd");
	CursorJump(4, 5);
	printf("暂停：");
	CursorJump(4, 6);
	printf("ESC");
}