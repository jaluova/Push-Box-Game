#include "title.h"

//��ɫ
void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //��ɫ����
    //ע��SetConsoleTextAttribute��һ��API��Ӧ�ó����̽ӿڣ�
}

//���ع��
void HideCursor()
{
    CONSOLE_CURSOR_INFO curInfo; //��������Ϣ�Ľṹ�����
    curInfo.dwSize = 1; //���û��ֵ�Ļ������������Ч
    curInfo.bVisible = FALSE; //���������Ϊ���ɼ�
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
    SetConsoleCursorInfo(handle, &curInfo); //���ù����Ϣ
}

//�����ת(����Ŀ�ļ��е�gotoXY�������,ʵ�����е���)
void CursorJump(int x, int y)
{
    COORD pos; //������λ�õĽṹ�����
    pos.X = x; //������
    pos.Y = y; //������
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ����̨���
    SetConsoleCursorPosition(handle, pos); //���ù��λ��
}

//***

//�˵�����,��ͬ
void m_menu(int t) {
    mciSendString(L"open music\\���˵�.mp3 alias menu", NULL, 0, NULL);//�������ļ�
    switch (t) 
    {
    case 1:
        mciSendString(L"play menu repeat", NULL, 0, NULL);//�������1,�������ֲ�ѭ������
        switch (volume1)//������������,����������С
        {
        case 0:mciSendString(L"setaudio menu volume to 0", NULL, 0, NULL);break;
        case 1:mciSendString(L"setaudio menu volume to 330", NULL, 0, NULL);break;
        case 2:mciSendString(L"setaudio menu volume to 660", NULL, 0, NULL);break;
        case 3:mciSendString(L"setaudio menu volume to 990", NULL, 0, NULL);break;
        }
        break;
    case 0:mciSendString(L"close menu", NULL, 0, NULL);break;//�������0,�ر�����
    }
}

//��Ϸ����
void m_game(int t) {
    switch (music_num)//�������ֺ�,ѡ��Ҫ���ŵ�����
    {
    case 0:
        mciSendString(L"open music\\������Ϸ.mp3 alias game0", NULL, 0, NULL);
        switch (t)
        {

        case 1:
            mciSendString(L"play game0 repeat", NULL, 0, NULL);
            switch (volume1)
            {
            case 0:mciSendString(L"setaudio game0 volume to 0", NULL, 0, NULL);break;
            case 1:mciSendString(L"setaudio game0 volume to 330", NULL, 0, NULL);break;
            case 2:mciSendString(L"setaudio game0 volume to 660", NULL, 0, NULL);break;
            case 3:mciSendString(L"setaudio game0 volume to 990", NULL, 0, NULL);break;
            }break;
        case 0:mciSendString(L"stop game0 ", NULL, 0, NULL);break;//��ͣ����
        }break;
    case 1:
        mciSendString(L"open music\\Ӣ��֤֮.mp3 alias game1", NULL, 0, NULL);
        switch (t)
        {

        case 1:
            mciSendString(L"play game1 repeat", NULL, 0, NULL);
            switch (volume1)
            {
            case 0:mciSendString(L"setaudio game1 volume to 0", NULL, 0, NULL);break;
            case 1:mciSendString(L"setaudio game1 volume to 330", NULL, 0, NULL);break;
            case 2:mciSendString(L"setaudio game1 volume to 660", NULL, 0, NULL);break;
            case 3:mciSendString(L"setaudio game1 volume to 990", NULL, 0, NULL);break;
            }break;
        case 0:mciSendString(L"stop game1", NULL, 0, NULL);break;
        }break;
    case 2:
        mciSendString(L"open music\\Kongo.mp3 alias game2", NULL, 0, NULL);
        switch (t)
        {
        case 1:
            mciSendString(L"play game2 repeat", NULL, 0, NULL);
            switch (volume1)
            {
            case 0:mciSendString(L"setaudio game2 volume to 0", NULL, 0, NULL);break;
            case 1:mciSendString(L"setaudio game2 volume to 330", NULL, 0, NULL);break;
            case 2:mciSendString(L"setaudio game2 volume to 660", NULL, 0, NULL);break;
            case 3:mciSendString(L"setaudio game2 volume to 990", NULL, 0, NULL);break;
            }break;
        case 0:mciSendString(L"stop game2", NULL, 0, NULL);break;
        }break;
    case 3:
        mciSendString(L"open music\\mc.mp3 alias game3", NULL, 0, NULL);
        switch (t)
        {
        case 1:
            mciSendString(L"play game3 repeat", NULL, 0, NULL);
            switch (volume1)
            {
            case 0:mciSendString(L"setaudio game3 volume to 0", NULL, 0, NULL);break;
            case 1:mciSendString(L"setaudio game3 volume to 330", NULL, 0, NULL);break;
            case 2:mciSendString(L"setaudio game3 volume to 660", NULL, 0, NULL);break;
            case 3:mciSendString(L"setaudio game3 volume to 990", NULL, 0, NULL);break;
            }break;
        case 0:mciSendString(L"stop game3", NULL, 0, NULL);break;
        }break;
    case 4:
        mciSendString(L"open music\\������.mp3", NULL, 0, NULL);
        switch (t)
        {
        case 1:
            mciSendString(L"play music\\������.mp3 repeat", NULL, 0, NULL);
            switch (volume1)
            {
            case 0:mciSendString(L"setaudio music\\������.mp3 volume to 0", NULL, 0, NULL);break;
            case 1:mciSendString(L"setaudio music\\������.mp3 volume to 330", NULL, 0, NULL);break;
            case 2:mciSendString(L"setaudio music\\������.mp3 volume to 660", NULL, 0, NULL);break;
            case 3:mciSendString(L"setaudio music\\������.mp3 volume to 990", NULL, 0, NULL);break;
            }break;
        case 0:mciSendString(L"stop music\\������.mp3", NULL, 0, NULL);break;
        }break;
    }
}

//���а�����
void m_rank(int t) {
    mciSendString(L"open music\\���а�.mp3 alias rank", NULL, 0, NULL);
    switch (t)
    {
    case 1:mciSendString(L"play rank repeat", NULL, 0, NULL);
        switch (volume1)
        {
        case 0:mciSendString(L"setaudio rank volume to 0", NULL, 0, NULL);break;
        case 1:mciSendString(L"setaudio rank volume to 330", NULL, 0, NULL);break;
        case 2:mciSendString(L"setaudio rank volume to 660", NULL, 0, NULL);break;
        case 3:mciSendString(L"setaudio rank volume to 990", NULL, 0, NULL);break;
        }
        break;
    case 0:mciSendString(L"close rank", NULL, 0, NULL);break;
    }
}

//ʤ������
void m_win() {//��Ϊʤ������̫��,�Ͳ���Ҫ���ÿ�����
    mciSendString(L"play music\\�ɹ�.mp3", NULL, 0, NULL);
    switch (volume1)
    {
    case 0:mciSendString(L"setaudio music\\�ɹ�.mp3 volume to 0", NULL, 0, NULL);break;
    case 1:mciSendString(L"setaudio music\\�ɹ�.mp3 volume to 330", NULL, 0, NULL);break;
    case 2:mciSendString(L"setaudio music\\�ɹ�.mp3 volume to 660", NULL, 0, NULL);break;
    case 3:mciSendString(L"setaudio music\\�ɹ�.mp3 volume to 990", NULL, 0, NULL);break;
    }
}

//��Ϸ��Ч

//�ƶ����
void m_move() {
    mciSendString(L"play music\\�ƶ�ѡ��.mp3 ", NULL, 0, NULL);
    switch (volume2)
    {
    case 0:mciSendString(L"setaudio music\\�ƶ�ѡ��.mp3 volume to 0", NULL, 0, NULL);break;
    case 1:mciSendString(L"setaudio music\\�ƶ�ѡ��.mp3 volume to 330", NULL, 0, NULL);break;
    case 2:mciSendString(L"setaudio music\\�ƶ�ѡ��.mp3 volume to 660", NULL, 0, NULL);break;
    case 3:mciSendString(L"setaudio music\\�ƶ�ѡ��.mp3 volume to 990", NULL, 0, NULL);break;
    }
    mciSendString(L"play music\\�ƶ�ѡ��.mp3 ", NULL, 0, NULL);
} 

//����ѡ��
void m_click() {
    mciSendString(L"play music\\����˵�.mp3 ", NULL, 0, NULL);
    switch (volume2)
    {
    case 0:mciSendString(L"setaudio music\\����˵�.mp3 volume to 0", NULL, 0, NULL);break;
    case 1:mciSendString(L"setaudio music\\����˵�.mp3 volume to 330", NULL, 0, NULL);break;
    case 2:mciSendString(L"setaudio music\\����˵�.mp3 volume to 660", NULL, 0, NULL);break;
    case 3:mciSendString(L"setaudio music\\����˵�.mp3 volume to 990", NULL, 0, NULL);break;
    }
    mciSendString(L"play music\\����˵�.mp3 ", NULL, 0, NULL);

} 