//***
#include "title.h"

void menuView() {
	foot[level] = 0;//清空步数
	m_game(0);//暂停游戏音乐
	m_rank(0);//关闭排行榜音乐
	m_menu(1);//打开菜单音乐
	//刷新打印,打印边框
	system("cls");//清屏
	printBOX();//打印边框
	//打印文字
	CursorJump(17, 2);
	printf("一一一一一一一一一");
	CursorJump(17, 3);
	printf("推      箱      子");
	CursorJump(17, 4);
	printf("一一一一一一一一一");
	CursorJump(22, 6);
	printf("开始游戏");
	CursorJump(22, 8);
	printf("游戏设置");
	CursorJump(22, 10);
	printf("游戏排行");
	CursorJump(22, 12);
	printf("游戏说明");
	CursorJump(22, 14);
	printf("退出游戏");
	//实现与玩家交互
	int input;
start://开始
	CursorJump(22, 6);
	color(0x60);//黄色高亮,下同
	printf("开始游戏");
	input = getch();//接受输入,下同
	
	CursorJump(22, 6);
	color(0x07);//变回正常颜色,下同
	printf("开始游戏");
	switch (input)//选项跳转,下同
	{
	case 'w':
	case 'W':
		m_move();//播放移动音乐
		goto exit;
		break;
	case 's':
	case 'S':
		m_move();
		goto setup;
		break;
	case ENTER:
		m_click();//播放点击音乐
		levelchoose();
		break;
	default:
		goto start;
	}

setup://设置
	CursorJump(22, 8);
	color(0x60);
	printf("游戏设置");
	input = getch();
	CursorJump(22, 8);
	color(0x07);
	printf("游戏设置");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto start;
		break;
	case 's':
	case 'S':
		m_move();
		goto rank;
		break;
	case ENTER:
		m_click();
		setupView();
		break;
	default:
		goto setup;
	}

rank://排行
	CursorJump(22, 10);
	color(0x60);
	printf("游戏排行");
	input = getch();
	CursorJump(22, 10);
	color(0x07);
	printf("游戏排行");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto setup;
		break;
	case 's':
	case 'S':
		m_move();
		goto intruction;
		break;
	case ENTER:
		m_click();
		rankView();
		break;
	default:
		goto rank;
	}

intruction://说明
	CursorJump(22, 12);
	color(0x60);
	printf("游戏说明");
	input = getch();
	CursorJump(22, 12);
	color(0x07);
	printf("游戏说明");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto rank;
		break;
	case 's':
	case 'S':
		m_move();
		goto exit;
		break;
	case ENTER:
		m_click();
		instruView();
		break;
	default:
		goto intruction;
	}

exit://退出
	CursorJump(22, 14);
	color(0x60);
	printf("退出游戏");
	input = getch();
	CursorJump(22, 14);
	color(0x07);
	printf("退出游戏");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto intruction;
		break;
	case 's':
	case 'S':
		m_move();
		goto start;
		break;
	case ENTER:
		m_click();
		exitView();
		break;
	default:
		goto exit;
	}
}

void levelchoose() {//选关界面
	system("cls");
	printBOX();
	CursorJump(22, 2);
	printf("选择关卡");
	CursorJump(15, 7);
	printf("A <                > D");
	CursorJump(21, 12);
	printf("返回主菜单");
	CursorJump(14, 15);
	printf("输入ws选择,输入回车确认");
	int choose = 0;//选择变量
	int input;
	do {
		switch (choose) {
		case 0://光标跳转到数字
			CursorJump(25, 7);
			printf("  ");
			CursorJump(25, 7);
			color(0x60);
			printf("%d", level + 1);
			input = getch();
			CursorJump(25, 7);
			color(0x07);
			printf("%d", level + 1);
			break;
		case 1://光标跳转到"返回主菜单"
			CursorJump(21, 12);
			color(0x60);
			printf("返回主菜单");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("返回主菜单");
			break;
		}
		switch (input) {//用输入控制变量值
		case'w':
		case'W'://光标跳转
			m_move();
			choose--;
			break;
		case's':
		case'S':
			m_move();
			choose++;
			break;
		case'a'://音量调节
		case'A':
			m_move();
			if (choose == 0)
				level--;
			break;
		case'd':
		case'D':
			m_move();
			if (choose == 0)
				level++;
			break;
		case ENTER:
			m_click();
			if (choose == 0)
				gameView(level);
			if (choose == 1)
				menuView();
			break;
		case 'e':
		case 'E':
			m_click();
			if (choose == 0) {
				createRead(0);
				createView(level);
			}break;
		case 'r':
		case 'R':
			m_click();
			if (choose == 0) {
				createRead(1);
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
			}break;
		}
		if (choose == -1)//防止变量大小越界
			choose = 1;
		if (choose == 2)
			choose = 0;
		if (level == 20)
			level = 19;
		if (level == -1)
			level = 0;
	} while (1);
}

//****
void setupView() {//设计思路同上
	system("cls");
	color(0x07);
	printBOX();
	CursorJump(22, 2);
	printf("游戏设置");
	CursorJump(18, 4);
	printf("A <         > D  bgm种类");//0
	CursorJump(18, 6);
	printf("A <    %d    > D  bgm大小", volume1);//1
	CursorJump(18, 8);
	printf("A <    %d    > D  音效大小", volume2);//2
	CursorJump(18, 10);
	printf("A <    %d    > D  地图风格", style);//3
	CursorJump(21, 12);
	printf("返回主菜单");//4
	CursorJump(14, 14);
	printf("输入ws选择,输入回车确认");
	int choose = 0;
	int input;
	do {
		switch (choose) {
		case 0:
			CursorJump(22, 4);
			printf("        ");
			color(0x60);
			CursorJump(22, 4);
			switch (music_num) 
			{
			case 0:printf("经典音乐");break;
			case 1:printf("英雄之证");break;
			case 2:printf("Kongo");break;
			case 3:printf("MC");break;
			case 4:printf("钢琴曲");break;
			}
			input = getch();
			CursorJump(22, 4);
			color(0x07);
			switch (music_num)
			{
			case 0:printf("经典音乐");break;
			case 1:printf("英雄之证");break;
			case 2:printf("Kongo");break;
			case 3:printf("MC");break;
			case 4:printf("钢琴曲");break;
			}
			break;
		case 1:
			CursorJump(25, 6);
			color(0x60);
			printf("%d", volume1);
			input = getch();
			CursorJump(25, 6);
			color(0x07);
			printf("%d", volume1);
			break;
		case 2:
			CursorJump(25, 8);
			color(0x60);
			printf("%d", volume2);
			input = getch();
			CursorJump(25, 8);
			color(0x07);
			printf("%d", volume2);
			break;
		case 3:
			CursorJump(25, 10);
			color(0x60);
			printf("%d",style);
			input = getch();
			CursorJump(25, 10);
			color(0x07);
			printf("%d",style);
			break;
		case 4:
			CursorJump(21, 12);
			color(0x60);
			printf("返回主菜单");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("返回主菜单");
			break;
		}
		switch (input) {
		case'w':
		case'W':
			m_move();
			choose--;
			break;
		case's':
		case'S':
			m_move();
			choose++;
			break;
		case'a':
		case'A':
			m_move();
			if (choose == 0)
				music_num--;
			if (choose == 1) 
			{
				volume1--;
				m_menu(1);
			}
			if (choose == 2)
				volume2--;
			break;
		case'd':
		case'D':
			m_move();
			if (choose == 0)
				music_num++;
			if (choose == 1)
			{
				volume1++;
				m_menu(1);
			}
			if (choose == 2)
				volume2++;
			break;
		case ENTER:
			m_click();
			if (choose == 4)
				menuView();
			break;
		}
		if (choose == -1)
			choose = 6;
		if (choose == 7)
			choose = 0;
		if (volume1 == 4)
			volume1 = 3;
		if (volume1 == -1)
			volume1 = 0;
		if (volume2 == 4)
			volume2 = 3;
		if (volume2 == -1)
			volume2 = 0;
		if (music_num == 5)
			music_num = 4;
		if (music_num == -1)
			music_num = 0;
	} while (1);
}

//****
void rankView() {
	m_menu(0);
	m_game(0);
	m_rank(1);
	system("cls");
	color(0x07);
	printBOX();
	CursorJump(22, 2);
	printf("排行榜");
	CursorJump(14, 5);
	printf("A <                > D");
	CursorJump(20, 8);
	color(0x07);
	printf("1");
	CursorJump(20, 9);
	printf("2");
	CursorJump(20, 10);
	printf("3");
	CursorJump(21, 12);
	printf("返回主菜单");
	CursorJump(14, 14);
	printf("输入ws选择,输入回车确认");
	CursorJump(18, 15);
	printf("输入r可重置排行榜");
	int choose = 0;
	int input;
	do {
		printRNAK(level);
		switch (choose) {
		case 0:
			CursorJump(25, 5);
			printf("  ");
			CursorJump(25, 5);
			color(0x60);
			printf("%d", level + 1);
			input = getch();
			CursorJump(25, 5);
			color(0x07);
			printf("%d", level + 1);
			break;
		case 1:
			CursorJump(21, 12);
			color(0x60);
			printf("返回主菜单");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("返回主菜单");
			break;
		}
		switch (input) {
		case'w':
		case'W':
			m_move();
			choose--;
			break;
		case's':
		case'S':
			m_move();
			choose++;
			break;
		case'a':
		case'A':
			m_move();
			if(choose == 0)
				level--;
			break;
		case'd':
		case'D':
			m_move();
			if (choose == 0)
				level++;
			break;
		case'r':
		case'R':
			m_click();
			initRank();//初始化排行榜
			ReadData();//读取数据
			break;
		case ENTER:
			m_click();
			if (choose == 1)
			{
				level = 0;
				menuView();
			}
			break;
		}
		if (choose == -1)
			choose = 1;
		if (choose == 2)
			choose = 0;
		if (level == 20)
			level = 19;
		if (level == -1)
			level = 0;
	} while (1);
}

void instruView() {//设计思路同菜单界面
	system("cls");
	printBOX();
	CursorJump(22, 3);
	printf("游戏说明");
	CursorJump(22, 9);
	printf("关于我们");
	CursorJump(21, 12);
	printf("返回主菜单");
	int input;
instru_1:
	CursorJump(22, 6);
	color(0x60);
	printf("操作说明");
	input = getch();
	CursorJump(22, 6);
	color(0x07);
	printf("操作说明");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto menu;
		break;
	case 's':
	case 'S':
		m_move();
		goto instru_2;
		break;
	case ENTER:
		m_click();
		instruView_1();
		break;
	default:
		goto instru_1;
	}
instru_2:
	CursorJump(22, 9);
	color(0x60);
	printf("关于我们");
	input = getch();
	CursorJump(22, 9);
	color(0x07);
	printf("关于我们");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto instru_1;
		break;
	case 's':
	case 'S':
		m_move();
		goto menu;
		break;
	case ENTER:
		m_click();
		instruView_2();
		break;
	default:
		goto instru_2;
	}
menu:
	CursorJump(21, 12);
	color(0x60);
	printf("返回主菜单");
	input = getch();
	CursorJump(21, 12);
	color(0x07);
	printf("返回主菜单");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto instru_2;
		break;
	case 's':
	case 'S':
		m_move();
		goto instru_1;
		break;
	case ENTER:
		m_click();
		menuView();
		break;
	default:
		goto menu;
	}
}

void instruView_1() {
	system("cls");
	color(0x07);
	printBOX();
	CursorJump(20, 3);
	printf("游戏玩法说明");
	CursorJump(22, 5);
	printf("WASD:移动");
	CursorJump(18, 7);
	printf("推动箱子进入目的地");
    CursorJump(16, 9);
    printf("压住红目标点时消除红墙");
	CursorJump(16, 11);
	printf("压住蓝目标点时消除蓝墙");
	CursorJump(19, 14);
	printf("返回（Esc/回车)");
	while (1) {//循环,直到输入正确的值,下同
		int input = getch();
		m_click();
		if (input == ENTER || input == ESC)
			menuView();
		else
			continue;
	}
}

void instruView_2() {
	system("cls");
	color(0x07);
	printBOX();
	CursorJump(22, 2);
	printf("制作人员");
	CursorJump(6, 4);
	printf("小组成员                    特别感谢");
	CursorJump(5, 6);
	printf("组长：   余某              01星球图灵院");
	CursorJump(5, 7);
	printf("副组长： 阿绾              东东哥");
	CursorJump(5, 8);
	printf("信息官： 阿梦              星竹学姐");
	CursorJump(5, 9);
	printf("产品经理:涵                阿天小学长");
	CursorJump(5, 10);
	printf("         土豆              云海学长");
	CursorJump(5, 11);
	printf("技术官： 阿氟");
	CursorJump(5, 12);
	printf("         无阁");
	CursorJump(5, 13);
	printf("         minato            返回（Esc/回车)");
	while (1) {
		int input = getch();
		m_click();
		if (input == ENTER || input == ESC)
			menuView();
		else
			continue;
	}
}

//**
void winView() {
	m_win();
	Sleep(500);
	system("cls");
	printBOX();
	WriteData(foot[level]);
	if (level != LEVEL - 1 ) {
		CursorJump(20, 5);
		printf("恭        喜");
		CursorJump(9, 9);
		printf("你通过了第%d关,请按ENTER键进入下一关", level + 1);
		CursorJump(20, 11);
		printf("你的步数是%d", foot[level]);
		foot[level] = 0;
		while(1) {
			int input = getch();
			if (input == ENTER)
			{
				level++;
				gameView(level);
			}
			else
				continue;
		} 
	}
	else {
		CursorJump(16, 5);
		printf("恭   喜   !   !");
		CursorJump(16, 7);
		printf("你通过了全部关卡");
		CursorJump(16, 9);
		printf("输入ESC返回主菜单");
		CursorJump(14, 11);
		printf("输入ENTER查看制作人员");
		while (1) {
			int input = getch();
			if (input == ESC)
				menuView();
			else if (input == ENTER)
				instruView_2();
			else
				continue;
		}
	}
}

void exitView() {//设计思路同菜单
	system("cls");
	color(0x07);
	printBOX();
	CursorJump(16, 3);
	printf("真的忍心离开吗?  QwQ");
	CursorJump(22, 7);
	printf("留下");
	CursorJump(22, 10);
	printf("离开");
	CursorJump(13, 14);
	printf("输入ws选择,输入回车确认");
	int input;
stay:
	CursorJump(22, 7);
	color(0x60);
	printf("留下");
	input = getch();
	CursorJump(22, 7);
	color(0x07);
	printf("留下");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto leave;
		break;
	case 's':
	case 'S':
		m_move();
		goto leave;
		break;
	case ENTER:
		m_click();
		menuView();
		break;
	default:
		goto stay;
	}
leave:
	CursorJump(22, 10);
	color(0x60);
	printf("离开");
	input = getch();
	CursorJump(22, 10);
	color(0x07);
	printf("离开");
	switch (input)
	{
	case 'w':
	case 'W':
		m_move();
		goto stay;
		break;
	case 's':
	case 'S':
		m_move();
		goto stay;
		break;
	case ENTER:
		m_click();
		CursorJump(22, 18);
		exit(0);
		break;
	default:
		goto leave;
	}
}

//****
void pauseView() {//设置思路同设置,选关
	system("cls");
	printBOX();
	CursorJump(23, 2);
	printf("暂停中");
	CursorJump(22, 4);
	printf("继续游戏");
	CursorJump(19, 6);
	printf("A <   %d   > D  bgm大小", volume1);
	CursorJump(19, 8);
	printf("A <   %d   > D  音效大小", volume2);
	CursorJump(20, 10);
	printf("重新开始本关");
	CursorJump(21, 12);
	printf("返回主菜单");
	CursorJump(14, 14);
	printf("输入ws选择,输入回车确认");
	int choose = 0;
	int input;
	do{
		switch (choose) {
		case 0:
			CursorJump(22, 4);
			color(0x60);
			printf("继续游戏");
			input = getch();
			CursorJump(22, 4);
			color(0x07);
			printf("继续游戏");
			break;
		case 1:
			CursorJump(25, 6);
			color(0x60);
			printf("%d", volume1);
			input = getch();
			CursorJump(25, 6);;
			color(0x07);
			printf("%d", volume1);
			break;
		case 2:
			CursorJump(25, 8);
			color(0x60);
			printf("%d", volume2);
			input = getch();
			CursorJump(25, 8);
			color(0x07);
			printf("%d", volume2);
			break;
		case 3:
			CursorJump(20, 10);
			color(0x60);
			printf("重新开始本关");
			input = getch();
			CursorJump(20, 10);
			color(0x07);
			printf("重新开始本关");
			break;
		case 4:
			CursorJump(21, 12);
			color(0x60);
			printf("返回主菜单");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("返回主菜单");
			break;
		}
		switch (input) {
		case'w':
		case'W':
			m_move();
			choose--;
			break;
		case's':
		case'S':
			m_move();
			choose++;
			break;
		case'a':
		case'A':
			m_move();
			if (choose == 1)
			{
				volume1--;
				m_game(1);
			}
			if (choose == 2)
				volume2--;
			break;
		case'd':
		case'D':
			m_move();
			if (choose == 1)
			{
				volume1++;
				m_game(1);
			}
			if (choose == 2)
				volume2++;
			break;
		case ENTER:
			m_click();
			if (choose == 0)
				gameView(level);
			if (choose == 3) 
			{
				foot[level] = 0;
				gameView(level);
			}
			if (choose == 4)
				menuView();
			break;
		}
		if (choose == -1)
			choose = 6;
		if (choose == 7)
			choose = 0;
		if (volume1 == 4)
			volume1 = 3;
		if (volume1 == -1)
			volume1 = 0;
		if (volume2 == 4)
			volume2 = 3;
		if (volume2 == -1)
			volume2 = 0;
	}while (1);
}

void printBOX() {
	printf("口口口口口口口口口口口口口口口口口口口口口口口口口口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口                                                口\n");
	printf("口口口口口口口口口口口口口口口口口口口口口口口口口口\n");
}

void printRNAK() {//打印排行榜数字
	CursorJump(25, 8);
	printf("    ");
	CursorJump(25, 8);
	color(0x07);
	printf("%d",rank[0][level]);//第一名
	CursorJump(25, 9);
	printf("    ");
	CursorJump(25, 9);
	printf("%d", rank[1][level]);//第二名
	CursorJump(25, 10);
	printf("    ");
	CursorJump(25, 10);
	printf("%d", rank[2][level]);//第三名
}

void WriteData(int data) {//写入数据data
	int a, b, c, d;
	FILE* fp = fopen("file\\rank.txt", "w");
	//根据输入数据的大小,改变数组的值
	if (data < rank[0][level])//如果输入数据小于第一名
	{
		rank[2][level] = rank[1][level];//第二名取代第三名
        rank[1][level] = rank[0][level];//第一名取代第二名
        rank[0][level] = data;//输入取代第一名
	}
	else if (data < rank[1][level])//如果输入数据大于第一名,且小于第二名
	{
		rank[2][level] = rank[1][level];
        rank[1][level] = data;
	}
	else if (data < rank[2][level])//如果输入数据大于第一,二名,且小于第三名
		rank[2][level] = data;
	else if (rank[0][level] == 0)//考虑到初始数据是0
		rank[0][level] = data;
	else if(rank[1][level] == 0)
		rank[1][level] = data;
	else if (rank[2][level] == 0)
		rank[2][level] = data;
	
	for (int i = 0;i < LEVEL;i++) {//将数组数据转入文件数据
		for (int j = 0;j < 3;j++) {
			char ch;
			a = rank[j][i] / 1000;
			b = (rank[j][i] - a * 1000) / 100;
			c = (rank[j][i] - b * 100 - a * 1000) / 10;
			d = rank[j][i] % 10;//拆分每个数字的千,百,十,个位
			givestring(&ch, a);//写入进入文件
			fputc(ch, fp);
			givestring(&ch, b);
			fputc(ch, fp);
			givestring(&ch, c);
			fputc(ch, fp);
			givestring(&ch,d);
			fputc(ch, fp);
		}
	}
	fclose(fp);//关闭文件
}

void ReadData() {//读取文件数据
	int a, b, c, d, e;
	FILE* fp = fopen("file\\rank.txt", "r");
	for (int i = 0;i < LEVEL;i++) {
		for (int j = 0;j < 3;j++) {
			fseek(fp, i * 12 + j * 4, SEEK_SET);
			int ch = fgetc(fp);
			givenum(ch, &a);
			ch = fgetc(fp);//读取千,百,十,个位数字信息
			givenum(ch, &b);
			ch = fgetc(fp);
			givenum(ch, &c);
			ch = fgetc(fp);
			givenum(ch, &d);
			e = a * 1000 + b * 100 + c * 10 + d;//获取最终数字
			rank[j][i] = e;//储存位数组数据
		}
	}
	fclose(fp);
}

void givenum(int ch, int* p) {//转换字符为数字
	if (ch == '0')
		*p = 0;
	else if (ch == '1')
		*p = 1;
	else if (ch == '2')
		*p = 2;
	else if (ch == '3')
		*p = 3;
	else if (ch == '4')
		*p = 4;
	else if (ch == '5')
		*p = 5;
	else if (ch == '6')
		*p = 6;
	else if (ch == '7')
		*p = 7;
	else if (ch == '8')
		*p = 8;
	else if (ch == '9')
		*p = 9;
}

void givestring(char* p, int a) {//转换数字为字符
	if (a == 0)
		*p = '0';
	else if (a == 1)
		*p = '1';
	else if (a == 2)
		*p = '2';
	else if (a == 3)
		*p = '3';
	else if (a == 4)
		*p = '4';
	else if (a == 5)
		*p = '5';
	else if (a == 6)
		*p = '6';
	else if (a == 7)
		*p = '7';
	else if (a == 8)
		*p = '8';
	else if (a == 9)
		*p = '9';
}
