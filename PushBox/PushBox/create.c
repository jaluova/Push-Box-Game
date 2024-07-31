//�˲���Ϊ�������,��ǰ���е��ͻ,�Ͳ�չʾ�������
//��Ϊ��������
//��������޸���ͨ�ؿ�
#include "title.h"

void createInit(int level) {
	//1.��ֵ
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] = temp[level][j][i];
		}
	}
	//2.�ҵ��������
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
	system("cls");//����
	m_menu(0);//�رղ˵�����

	if (foot[level] == 0)
		createInit(level);

	createView_ShowMap(level);
	while (1) {
		CursorJump(0, ROW + 1);
		createPrint(y, x / 2);
		createCursor();
		CursorJump(x, y);
		printf("**");

		int input = getch();//��������
		m_move();//��Ч
		switch (input) {
		case ESC://��ͣ
			foot[level] = 0;
			createWrite();
			createExit();
		case 'w'://�ƶ�
		case 'W':
		case 'a':
		case 'A':
		case 's':
		case 'S':
		case 'd':
		case 'D':
			if (createMove(input)) {//�ж��Ƿ���ƶ�
				foot[level]++;//������һ
			}
			else
				continue;//����,����ѭ��
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
		for (int col = 0;col < COL;col++) {//���������ֵ,��ӡ���෽��
			createPrint(row, col);
		}
		printf("\n");
	}
	CursorJump(0, ROW + 2);
	color(0x02); //��ɫ
	printf("��");
	color(0x07); //��ɫ
	CursorJump(2, ROW + 2);
	color(0x06); //��ɫ
	printf("��");
	color(0x07); //��ɫ
	CursorJump(4, ROW + 2);
	color(0x07); //��ɫ
	printf("��");
	CursorJump(6, ROW + 2);
	color(0x01); //��ɫ
	printf("��");
	color(0x07); //��ɫ
	CursorJump(8, ROW + 2);
	color(0x04); //��ɫ
	printf("��");
	color(0x07); //��ɫ
	CursorJump(10, ROW + 2);
	color(0x60); //�Ƶ�
	printf("  ");
	color(0x07); //��ɫ
	CursorJump(12, ROW + 2);
	color(0x10); //����
	printf("  ");
	color(0x07); //��ɫ
	CursorJump(14, ROW + 2);
	color(0x40); //���
	printf("  ");
	color(0x07); //��ɫ
}

void createPrint(int row,int col) {
	switch (map[row][col]) {
	case KONG:
		printf("  ");
		break;
	case PLAYER:
		color(0x02); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case POND:
		color(0x62); //�Ƶ���ɫ
		printf("��");
		color(0x07); //��ɫ
	case PONBD:
		color(0x12); //������ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case PONRD:
		color(0x42); //�����ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case PONBW:
		color(0x01); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case PONRW:
		color(0x04); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;


	case BOX:
		color(0x06); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case BOND:
		color(0x60); //�Ƶ׺�ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case BONBD:
		color(0x16); //���׻�ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case BONRD:
		color(0x46); //��׻�ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case BONBW:
		color(0x01); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case BONRW:
		color(0x04); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;


	case WALL:
		color(0x07); //��ɫ
		printf("��");
		break;
	case BWALL:
		color(0x01); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case RWALL:
		color(0x04); //��ɫ
		printf("��");
		color(0x07); //��ɫ
		break;
	case BWALL2:
		color(0x01); //��ɫ
		printf("**");
		color(0x07); //��ɫ
		break;
	case RWALL2:
		color(0x04); //��ɫ
		printf("**");
		color(0x07); //��ɫ
		break;


	case DEST:
		color(0x60); //�Ƶ�
		printf("  ");
		color(0x07); //��ɫ
		break;
	case BDEST:
		color(0x10); //����
		printf("  ");
		color(0x07); //��ɫ
		break;
	case RDEST:
		color(0x40); //���
		printf("  ");
		color(0x07); //��ɫ
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
	//1.��ֵ
	
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
	system("cls");//����
	printf("�Ƿ񷵻����˵�������?(1/0)");
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
