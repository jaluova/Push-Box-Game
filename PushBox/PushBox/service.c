#include "title.h"

//***
void init(int level) {
	//1.��ֵ
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] = temp[level][i][j];
		}
	}
	//2.�ҵ��������
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == PLAYER) {
				x = i;
				y = j;
			}
		}
	}
}

//*****
int move(char dir) {
	int a, b, c, d, e, f;//������ʱ����ı���

	switch (dir)
	{
	case 'w':
	case 'W':
		a = x;
		b = y;//��һ�ԣ������λ��
		c = x;
		d = y - 1;//�ڶ��ԣ�����һ���λ��
		e = x;
		f = y - 2;//�����ԣ����������λ��
		if (movejudge(a, b, c, d, e, f)) {
			y--;
			return 1;
		}
		else {
			return 0;
		}
	case 's':
	case 'S':
		a = x;
		b = y;
		c = x;
		d = y + 1;
		e = x;
		f = y + 2;
		if (movejudge(a, b, c, d, e, f)) {
			y++;
			return 1;
		}
		else {
			return 0;
		}
	case 'a':
	case 'A':
		a = x;
		b = y;
		c = x - 1;
		d = y;
		e = x - 2;
		f = y;
		if (movejudge(a, b, c, d, e, f)) {
			x--;
			return 1;
		}
		else {
			return 0;
		}
	case 'd':
	case 'D':
		a = x;
		b = y;
		c = x + 1;
		d = y;
		e = x + 2;
		f = y;
		if (movejudge(a, b, c, d, e, f)) {
			x++;
			return 1;
		}
		else {
			return 0;
		}
	default:
		return 0;
	}
}

int movejudge(int a, int b, int c, int d, int e, int f) {
	int ok = 0;//�ж�ֵ
	switch (map[c][d]) {//�ж��Ƿ�����ƶ�
	case KONG:
	case DEST:
	case RWALL2:
	case BWALL2:
	case RDEST:
	case BDEST:
		ok = 1;
		break;
	case BOX:
	case BOND:
	case BONRD:
	case BONBD:
	case BONRW:
	case BONBW:
		switch (map[e][f]) {
		case WALL:
		case RWALL:
		case BWALL:
		case BOX:
		case BOND:
		case BONRD:
		case BONBD:
		case BONRW:
		case BONBW:
			return 0;
			break;
		case KONG:
		case DEST:
		case RWALL2:
		case BWALL2:
		case RDEST:
		case BDEST:
			ok = 2;
			break;
		}
		break;
	case WALL:
	case RWALL:
	case BWALL:
		return 0;
		break;
	default:
		return 0;
		break;
	}

	switch (map[a][b])//�޸�ԭʼ��ͼ
	{
	case PLAYER:
		map[a][b] = KONG;
		break;
	case POND:
		map[a][b] = DEST;
		break;
	case PONRD:
		map[a][b] = RDEST;
		break;
	case PONBD:
		map[a][b] = BDEST;
		break;
	case PONRW:
		map[a][b] = RWALL2;
		break;
	case PONBW:
		map[a][b] = BWALL2;
		break;
	default:
		return 1;
	}
	Printf(a, b);

	switch (map[c][d]) //�޸����ڵ�һ���ͼ
	{
	case KONG:
	case BOX:
		map[c][d] = PLAYER;
		break;
	case RWALL2:
	case BONRW:
		map[c][d] = PONRW;
		break;
	case BWALL2:
	case BONBW:
		map[c][d] = PONBW;
		break;
	case DEST:
	case BOND:
		map[c][d] = POND;
		break;
	case RDEST:
	case BONRD:
		map[c][d] = PONRD;
		break;
	case BDEST:
	case BONBD:
		map[c][d] = PONBD;
		break;
	default:
		return 1;
	}
	Printf(c, d);
	if (ok == 2) {//�����Ӻ�
		switch (map[e][f]) {//�޸����ڵڶ����ͼ
		case KONG:
			map[e][f] = BOX;
			break;
		case RWALL2:
			map[e][f] = BONRW;
			break;
		case BWALL2:
			map[e][f] = BONBW;
			break;
		case RDEST:
			map[e][f] = BONRD;
			break;
		case BDEST:
			map[e][f] = BONBD;
			break;
		case DEST:
			map[e][f] = BOND;
			break;
		default:
			return 1;
		}
		Printf(e, f);
	}
	if (ok == 2) {
		isClear();
	}
	return 1;
}
//****
int isClear() {
	int r = 0;
	int b = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (map[i][j] == BONRD) {
				r = 1;
			}
			if (map[i][j] == BONBD) {
				b = 1;
			}
		}
	}
	if (r == 1) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (map[i][j] == RWALL) {
					map[i][j] = RWALL2;
					Printf(i, j);
				}
			}
		}
	}
	else {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (map[i][j] == RWALL2) {
					map[i][j] = RWALL;
					Printf(i, j);
				}
			}
		}
	}
	if (b == 1) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (map[i][j] == BWALL) {
					map[i][j] = BWALL2;
					Printf(i, j);
				}
			}
		}
	}
	else {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (map[i][j] == BWALL2) {
					map[i][j] = BWALL;
					Printf(i, j);
				}
			}
		}
	}
}

//****
int isWin() {
	int win = 1;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (map[i][j] == DEST 
				|| map[i][j] == RDEST 
				|| map[i][j] == BDEST 
				|| map[i][j] == POND 
				|| map[i][j] == PONRD 
				|| map[i][j] == PONBD)
			{
				win = 0;
				break;
			}
		}
		if (win == 0) {
			break;
		}
	}
	return win;
}

void Printf(row, col) {
	CursorJump(row * 2 + 12, col + 1);
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

//��ʼ�����а�����,ȫ��Ϊ0
void initRank() {
	FILE* fp = fopen("file\\rank.txt", "w");
	for (int i = 0;i < LEVEL;i++) {
		for (int j = 0;j < 3;j++) {
			fputs("0000", fp);
		}
	}
	fclose(fp);
}