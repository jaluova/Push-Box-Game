//***
#include "title.h"

void menuView() {
	foot[level] = 0;//��ղ���
	m_game(0);//��ͣ��Ϸ����
	m_rank(0);//�ر����а�����
	m_menu(1);//�򿪲˵�����
	//ˢ�´�ӡ,��ӡ�߿�
	system("cls");//����
	printBOX();//��ӡ�߿�
	//��ӡ����
	CursorJump(17, 2);
	printf("һһһһһһһһһ");
	CursorJump(17, 3);
	printf("��      ��      ��");
	CursorJump(17, 4);
	printf("һһһһһһһһһ");
	CursorJump(22, 6);
	printf("��ʼ��Ϸ");
	CursorJump(22, 8);
	printf("��Ϸ����");
	CursorJump(22, 10);
	printf("��Ϸ����");
	CursorJump(22, 12);
	printf("��Ϸ˵��");
	CursorJump(22, 14);
	printf("�˳���Ϸ");
	//ʵ������ҽ���
	int input;
start://��ʼ
	CursorJump(22, 6);
	color(0x60);//��ɫ����,��ͬ
	printf("��ʼ��Ϸ");
	input = getch();//��������,��ͬ
	
	CursorJump(22, 6);
	color(0x07);//���������ɫ,��ͬ
	printf("��ʼ��Ϸ");
	switch (input)//ѡ����ת,��ͬ
	{
	case 'w':
	case 'W':
		m_move();//�����ƶ�����
		goto exit;
		break;
	case 's':
	case 'S':
		m_move();
		goto setup;
		break;
	case ENTER:
		m_click();//���ŵ������
		levelchoose();
		break;
	default:
		goto start;
	}

setup://����
	CursorJump(22, 8);
	color(0x60);
	printf("��Ϸ����");
	input = getch();
	CursorJump(22, 8);
	color(0x07);
	printf("��Ϸ����");
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

rank://����
	CursorJump(22, 10);
	color(0x60);
	printf("��Ϸ����");
	input = getch();
	CursorJump(22, 10);
	color(0x07);
	printf("��Ϸ����");
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

intruction://˵��
	CursorJump(22, 12);
	color(0x60);
	printf("��Ϸ˵��");
	input = getch();
	CursorJump(22, 12);
	color(0x07);
	printf("��Ϸ˵��");
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

exit://�˳�
	CursorJump(22, 14);
	color(0x60);
	printf("�˳���Ϸ");
	input = getch();
	CursorJump(22, 14);
	color(0x07);
	printf("�˳���Ϸ");
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

void levelchoose() {//ѡ�ؽ���
	system("cls");
	printBOX();
	CursorJump(22, 2);
	printf("ѡ��ؿ�");
	CursorJump(15, 7);
	printf("A <                > D");
	CursorJump(21, 12);
	printf("�������˵�");
	CursorJump(14, 15);
	printf("����wsѡ��,����س�ȷ��");
	int choose = 0;//ѡ�����
	int input;
	do {
		switch (choose) {
		case 0://�����ת������
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
		case 1://�����ת��"�������˵�"
			CursorJump(21, 12);
			color(0x60);
			printf("�������˵�");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("�������˵�");
			break;
		}
		switch (input) {//��������Ʊ���ֵ
		case'w':
		case'W'://�����ת
			m_move();
			choose--;
			break;
		case's':
		case'S':
			m_move();
			choose++;
			break;
		case'a'://��������
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
		if (choose == -1)//��ֹ������СԽ��
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
void setupView() {//���˼·ͬ��
	system("cls");
	color(0x07);
	printBOX();
	CursorJump(22, 2);
	printf("��Ϸ����");
	CursorJump(18, 4);
	printf("A <         > D  bgm����");//0
	CursorJump(18, 6);
	printf("A <    %d    > D  bgm��С", volume1);//1
	CursorJump(18, 8);
	printf("A <    %d    > D  ��Ч��С", volume2);//2
	CursorJump(18, 10);
	printf("A <    %d    > D  ��ͼ���", style);//3
	CursorJump(21, 12);
	printf("�������˵�");//4
	CursorJump(14, 14);
	printf("����wsѡ��,����س�ȷ��");
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
			case 0:printf("��������");break;
			case 1:printf("Ӣ��֤֮");break;
			case 2:printf("Kongo");break;
			case 3:printf("MC");break;
			case 4:printf("������");break;
			}
			input = getch();
			CursorJump(22, 4);
			color(0x07);
			switch (music_num)
			{
			case 0:printf("��������");break;
			case 1:printf("Ӣ��֤֮");break;
			case 2:printf("Kongo");break;
			case 3:printf("MC");break;
			case 4:printf("������");break;
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
			printf("�������˵�");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("�������˵�");
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
	printf("���а�");
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
	printf("�������˵�");
	CursorJump(14, 14);
	printf("����wsѡ��,����س�ȷ��");
	CursorJump(18, 15);
	printf("����r���������а�");
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
			printf("�������˵�");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("�������˵�");
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
			initRank();//��ʼ�����а�
			ReadData();//��ȡ����
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

void instruView() {//���˼·ͬ�˵�����
	system("cls");
	printBOX();
	CursorJump(22, 3);
	printf("��Ϸ˵��");
	CursorJump(22, 9);
	printf("��������");
	CursorJump(21, 12);
	printf("�������˵�");
	int input;
instru_1:
	CursorJump(22, 6);
	color(0x60);
	printf("����˵��");
	input = getch();
	CursorJump(22, 6);
	color(0x07);
	printf("����˵��");
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
	printf("��������");
	input = getch();
	CursorJump(22, 9);
	color(0x07);
	printf("��������");
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
	printf("�������˵�");
	input = getch();
	CursorJump(21, 12);
	color(0x07);
	printf("�������˵�");
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
	printf("��Ϸ�淨˵��");
	CursorJump(22, 5);
	printf("WASD:�ƶ�");
	CursorJump(18, 7);
	printf("�ƶ����ӽ���Ŀ�ĵ�");
    CursorJump(16, 9);
    printf("ѹס��Ŀ���ʱ������ǽ");
	CursorJump(16, 11);
	printf("ѹס��Ŀ���ʱ������ǽ");
	CursorJump(19, 14);
	printf("���أ�Esc/�س�)");
	while (1) {//ѭ��,ֱ��������ȷ��ֵ,��ͬ
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
	printf("������Ա");
	CursorJump(6, 4);
	printf("С���Ա                    �ر��л");
	CursorJump(5, 6);
	printf("�鳤��   ��ĳ              01����ͼ��Ժ");
	CursorJump(5, 7);
	printf("���鳤�� ���              ������");
	CursorJump(5, 8);
	printf("��Ϣ�٣� ����              ����ѧ��");
	CursorJump(5, 9);
	printf("��Ʒ����:��                ����Сѧ��");
	CursorJump(5, 10);
	printf("         ����              �ƺ�ѧ��");
	CursorJump(5, 11);
	printf("�����٣� ����");
	CursorJump(5, 12);
	printf("         �޸�");
	CursorJump(5, 13);
	printf("         minato            ���أ�Esc/�س�)");
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
		printf("��        ϲ");
		CursorJump(9, 9);
		printf("��ͨ���˵�%d��,�밴ENTER��������һ��", level + 1);
		CursorJump(20, 11);
		printf("��Ĳ�����%d", foot[level]);
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
		printf("��   ϲ   !   !");
		CursorJump(16, 7);
		printf("��ͨ����ȫ���ؿ�");
		CursorJump(16, 9);
		printf("����ESC�������˵�");
		CursorJump(14, 11);
		printf("����ENTER�鿴������Ա");
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

void exitView() {//���˼·ͬ�˵�
	system("cls");
	color(0x07);
	printBOX();
	CursorJump(16, 3);
	printf("��������뿪��?  QwQ");
	CursorJump(22, 7);
	printf("����");
	CursorJump(22, 10);
	printf("�뿪");
	CursorJump(13, 14);
	printf("����wsѡ��,����س�ȷ��");
	int input;
stay:
	CursorJump(22, 7);
	color(0x60);
	printf("����");
	input = getch();
	CursorJump(22, 7);
	color(0x07);
	printf("����");
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
	printf("�뿪");
	input = getch();
	CursorJump(22, 10);
	color(0x07);
	printf("�뿪");
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
void pauseView() {//����˼·ͬ����,ѡ��
	system("cls");
	printBOX();
	CursorJump(23, 2);
	printf("��ͣ��");
	CursorJump(22, 4);
	printf("������Ϸ");
	CursorJump(19, 6);
	printf("A <   %d   > D  bgm��С", volume1);
	CursorJump(19, 8);
	printf("A <   %d   > D  ��Ч��С", volume2);
	CursorJump(20, 10);
	printf("���¿�ʼ����");
	CursorJump(21, 12);
	printf("�������˵�");
	CursorJump(14, 14);
	printf("����wsѡ��,����س�ȷ��");
	int choose = 0;
	int input;
	do{
		switch (choose) {
		case 0:
			CursorJump(22, 4);
			color(0x60);
			printf("������Ϸ");
			input = getch();
			CursorJump(22, 4);
			color(0x07);
			printf("������Ϸ");
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
			printf("���¿�ʼ����");
			input = getch();
			CursorJump(20, 10);
			color(0x07);
			printf("���¿�ʼ����");
			break;
		case 4:
			CursorJump(21, 12);
			color(0x60);
			printf("�������˵�");
			input = getch();
			CursorJump(21, 12);
			color(0x07);
			printf("�������˵�");
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
	printf("�ڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿ�\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("�ڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿڿ�\n");
}

void printRNAK() {//��ӡ���а�����
	CursorJump(25, 8);
	printf("    ");
	CursorJump(25, 8);
	color(0x07);
	printf("%d",rank[0][level]);//��һ��
	CursorJump(25, 9);
	printf("    ");
	CursorJump(25, 9);
	printf("%d", rank[1][level]);//�ڶ���
	CursorJump(25, 10);
	printf("    ");
	CursorJump(25, 10);
	printf("%d", rank[2][level]);//������
}

void WriteData(int data) {//д������data
	int a, b, c, d;
	FILE* fp = fopen("file\\rank.txt", "w");
	//�����������ݵĴ�С,�ı������ֵ
	if (data < rank[0][level])//�����������С�ڵ�һ��
	{
		rank[2][level] = rank[1][level];//�ڶ���ȡ��������
        rank[1][level] = rank[0][level];//��һ��ȡ���ڶ���
        rank[0][level] = data;//����ȡ����һ��
	}
	else if (data < rank[1][level])//����������ݴ��ڵ�һ��,��С�ڵڶ���
	{
		rank[2][level] = rank[1][level];
        rank[1][level] = data;
	}
	else if (data < rank[2][level])//����������ݴ��ڵ�һ,����,��С�ڵ�����
		rank[2][level] = data;
	else if (rank[0][level] == 0)//���ǵ���ʼ������0
		rank[0][level] = data;
	else if(rank[1][level] == 0)
		rank[1][level] = data;
	else if (rank[2][level] == 0)
		rank[2][level] = data;
	
	for (int i = 0;i < LEVEL;i++) {//����������ת���ļ�����
		for (int j = 0;j < 3;j++) {
			char ch;
			a = rank[j][i] / 1000;
			b = (rank[j][i] - a * 1000) / 100;
			c = (rank[j][i] - b * 100 - a * 1000) / 10;
			d = rank[j][i] % 10;//���ÿ�����ֵ�ǧ,��,ʮ,��λ
			givestring(&ch, a);//д������ļ�
			fputc(ch, fp);
			givestring(&ch, b);
			fputc(ch, fp);
			givestring(&ch, c);
			fputc(ch, fp);
			givestring(&ch,d);
			fputc(ch, fp);
		}
	}
	fclose(fp);//�ر��ļ�
}

void ReadData() {//��ȡ�ļ�����
	int a, b, c, d, e;
	FILE* fp = fopen("file\\rank.txt", "r");
	for (int i = 0;i < LEVEL;i++) {
		for (int j = 0;j < 3;j++) {
			fseek(fp, i * 12 + j * 4, SEEK_SET);
			int ch = fgetc(fp);
			givenum(ch, &a);
			ch = fgetc(fp);//��ȡǧ,��,ʮ,��λ������Ϣ
			givenum(ch, &b);
			ch = fgetc(fp);
			givenum(ch, &c);
			ch = fgetc(fp);
			givenum(ch, &d);
			e = a * 1000 + b * 100 + c * 10 + d;//��ȡ��������
			rank[j][i] = e;//����λ��������
		}
	}
	fclose(fp);
}

void givenum(int ch, int* p) {//ת���ַ�Ϊ����
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

void givestring(char* p, int a) {//ת������Ϊ�ַ�
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
