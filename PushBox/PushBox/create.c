//此部分为后续添加,和前面有点冲突,就不展示给玩家了
//因为储存特性
//最好用来修改普通关卡
#include "title.h"

void createInit(int level) {
	//1.赋值
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] = temp[level][j][i];
		}
	}
	//2.找到玩家坐标
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == PLAYER) {
				x = 2*j;
				y = i;
			}
		}
	}
}

void createView(int level) {
	system("cls");//清屏
	m_menu(0);//关闭菜单音乐

	if (foot[level] == 0)
		createInit(level);

	createView_ShowMap(level);
	while (1) {
		CursorJump(0, ROW + 1);
		createPrint(y, x / 2);
		createCursor();
		CursorJump(x, y);
		printf("**");

		int input = getch();//接受输入
		m_move();//音效
		switch (input) {
		case ESC://暂停
			foot[level] = 0;
			createWrite();
			createExit();
		case 'w'://移动
		case 'W':
		case 'a':
		case 'A':
		case 's':
		case 'S':
		case 'd':
		case 'D':
			if (createMove(input)) {//判定是否可移动
				foot[level]++;//步数加一
			}
			else
				continue;//否则,继续循环
			break;
		case 'q':
		case 'Q':
			create_num--;
			if (create_num == -1)
				create_num = 0;
			break;
		case 'e':
		case 'E':
			create_num++;
			if (create_num == 8)
				create_num = 7;
			break;
		case ENTER:
			if (map[y][x / 2] == KONG) 
			{
				switch (create_num)
				{
				case 0:
					map[y][x / 2] = PLAYER;break;
				case 1:
					map[y][x / 2] = BOX;break;
				case 2:
					map[y][x / 2] = WALL;break;
				case 3:
					map[y][x / 2] = BWALL;break;
				case 4:
					map[y][x / 2] = RWALL;break;
				case 5:
					map[y][x / 2] = DEST;break;
				case 6:
					map[y][x / 2] = BDEST;break;
				case 7:
					map[y][x / 2] = RDEST;break;
				}
				CursorJump(x, y);
				createPrint(y, x / 2);
			}
			else {
				map[y][x / 2] = KONG;
				CursorJump(x, y);
				createPrint(y, x/2);
			}
		}
	}
}

void createView_ShowMap(int level) {
	for (int row = 0;row < ROW;row++) {
		for (int col = 0;col < COL;col++) {//根据数组的值,打印各类方块
			createPrint(row, col);
		}
		printf("\n");
	}
	CursorJump(0, ROW + 2);
	color(0x02); //绿色
	printf("囧");
	color(0x07); //白色
	CursorJump(2, ROW + 2);
	color(0x06); //黄色
	printf("口");
	color(0x07); //白色
	CursorJump(4, ROW + 2);
	color(0x07); //白色
	printf("口");
	CursorJump(6, ROW + 2);
	color(0x01); //蓝色
	printf("口");
	color(0x07); //白色
	CursorJump(8, ROW + 2);
	color(0x04); //红色
	printf("口");
	color(0x07); //白色
	CursorJump(10, ROW + 2);
	color(0x60); //黄底
	printf("  ");
	color(0x07); //白色
	CursorJump(12, ROW + 2);
	color(0x10); //蓝底
	printf("  ");
	color(0x07); //白色
	CursorJump(14, ROW + 2);
	color(0x40); //红底
	printf("  ");
	color(0x07); //白色
}

void createPrint(int row,int col) {
	switch (map[row][col]) {
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

int createMove(char input) {
	if (x / 2 < COL) {
		if (y < ROW) 
		{
			switch (input) 
			{
			case 'w':
			case 'W':
				CursorJump(x, y);
				createPrint(y, x / 2);
				y--;
				break;
			case 's':
			case 'S':
				CursorJump(x, y);
				createPrint(y, x / 2);
				y++;
				break;
			case 'a':
			case 'A':
				CursorJump(x, y);
				createPrint(y, x / 2);
				x-=2;
				break;
			case 'd':
			case 'D':
				CursorJump(x, y);
				createPrint(y, x / 2);
				x+=2;
				break;
			}
			return 1;
		}
		else return 0;
	}
	else return 0;
}

void createRead(int t) {
	if (t == 0) {
		FILE* fp = fopen("file\\temp.txt", "r");

		int ch;
		for (int k = 0;k < LEVEL;k++) {
			for (int i = 0; i < ROW; i++) {
				for (int j = 0; j < COL; j++) {
					ch = fgetc(fp);
					givenum(ch, &temp[k][i][j]);
				}
			}
		}
		fclose(fp);
	}
	else {
		FILE* fp = fopen("file\\map.txt", "r");

		int ch;
		for (int k = 0;k < LEVEL;k++) {
			for (int i = 0; i < ROW; i++) {
				for (int j = 0; j < COL; j++) {
					ch = fgetc(fp);
					givenum(ch, &temp[k][i][j]);
				}
			}
		}
		fclose(fp);
	}
}

void createWrite() {
	//1.赋值
	
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			temp[level][j][i] = map[i][j];
		}
	}

	FILE* fp = fopen("file\\temp.txt", "w");
	
	int ch;
	for (int k = 0;k < LEVEL;k++) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				givestring(&ch, temp[k][i][j]);
				fputc(ch, fp);
			}
		}
	}
	fclose(fp);
}

void createExit() {
	int choose;
	system("cls");//清屏
	printf("是否返回主菜单并保存?(1/0)");
	scanf("%d", &choose);
	if (choose) 
	{
	    menuView();
		foot[level] = 0;
	}
	else
		createView(level);
}

void createCursor() {
	CursorJump(0, ROW + 3);
	printf("                               ");
	switch (create_num)
	{
	case 0:
		CursorJump(0, ROW + 3);
		printf("**");
		break;
	case 1:
		CursorJump(2, ROW + 3);
		printf("**");
		break;
	case 2:
		CursorJump(4, ROW + 3);
		printf("**");
		break;
	case 3:
		CursorJump(6, ROW + 3);
		printf("**");
		break;
	case 4:
		CursorJump(8, ROW + 3);
		printf("**");
		break;
	case 5:
		CursorJump(10, ROW + 3);
		printf("**");
		break;
	case 6:
		CursorJump(12, ROW + 3);
		printf("**");
		break;
	case 7:
		CursorJump(14, ROW + 3);
		printf("**");
		break;
	}
}
