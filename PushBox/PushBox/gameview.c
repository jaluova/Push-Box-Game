//*****
#include "title.h"

void gameView(int level) {
	system("cls");//����
	m_menu(0);//�رղ˵�����
	m_rank(0);//�ر����а�����
	m_game(1);//����Ϸ����
	
	if (foot[level] == 0)//�������Ϊ�����ʼ����Ϸ����(���ǵ���ͣ��Ϸ�����)
		init(level);

	gameView_ShowMap(level);//��ӡ��Ϸ����
	
	do {
		CursorJump(4, 2);
		printf("����:%d", foot[level]);//ʵʱ��ʾ����
		int input = getch();//��������
		m_move();//��Ч
		switch (input) {
		case ESC://��ͣ
			pauseView();
		case 'w'://�ƶ�
		case 'W':
		case 'a':
		case 'A':
		case 's':
		case 'S':
		case 'd':
		case 'D':
			if (move(input)) {//�ж��Ƿ���ƶ�
				Printf(x + 1, y);//�ֲ���ӡ�ػ�,������ʾ����
                foot[level]++;//������һ
				if (isWin() == 1)//�ж�ʤ��
					winView(level);//����ʤ������
				else
					continue;//����,����ѭ��
			}
			else
				continue;//����,����ѭ��
		}
	}while (1);//ѭ��
} 

void gameView_ShowMap(int level) {
	for (int row = 0;row < ROW;row++) {
		CursorJump(12, row + 1);
		for (int col = 0;col < COL;col++) {//���������ֵ,��ӡ���෽��
			switch (map[col][row]) {
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
	}
	for (int i = 0; i < 26; i++) {
		CursorJump(i * 2, 0);
		printf("��");
	}	
	for (int i = 0; i < 26; i++) {
		CursorJump(i * 2, 16);
		printf("��");
	}
	for (int i = 0; i < 17; i++) {
		CursorJump(0, i);
		printf("��");
	}
	for (int i = 0; i < 17; i++) {
		CursorJump(26 * 2, i);
		printf("��");
	}
	CursorJump(4, 1);
	printf("��%d��", level + 1);//��ӡ��ʾ�����ʾ����
	CursorJump(4, 3);
	printf("�ƶ���");
	CursorJump(4, 4);
	printf("wasd");
	CursorJump(4, 5);
	printf("��ͣ��");
	CursorJump(4, 6);
	printf("ESC");
}