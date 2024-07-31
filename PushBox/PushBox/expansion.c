#include "title.h"

//颜色
void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置
    //注：SetConsoleTextAttribute是一个API（应用程序编程接口）
}

//隐藏光标
void HideCursor()
{
    CONSOLE_CURSOR_INFO curInfo; //定义光标信息的结构体变量
    curInfo.dwSize = 1; //如果没赋值的话，光标隐藏无效
    curInfo.bVisible = FALSE; //将光标设置为不可见
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorInfo(handle, &curInfo); //设置光标信息
}

//光标跳转(和项目文件中的gotoXY功能相近,实际上有点差别)
void CursorJump(int x, int y)
{
    COORD pos; //定义光标位置的结构体变量
    pos.X = x; //横坐标
    pos.Y = y; //纵坐标
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorPosition(handle, pos); //设置光标位置
}

//***

//菜单音乐,下同
void m_menu(int t) {
    mciSendString(L"open music\\主菜单.mp3 alias menu", NULL, 0, NULL);//打开音乐文件
    switch (t) 
    {
    case 1:
        mciSendString(L"play menu repeat", NULL, 0, NULL);//如果输入1,播放音乐并循环播放
        switch (volume1)//根据音量参数,调整音量大小
        {
        case 0:mciSendString(L"setaudio menu volume to 0", NULL, 0, NULL);break;
        case 1:mciSendString(L"setaudio menu volume to 330", NULL, 0, NULL);break;
        case 2:mciSendString(L"setaudio menu volume to 660", NULL, 0, NULL);break;
        case 3:mciSendString(L"setaudio menu volume to 990", NULL, 0, NULL);break;
        }
        break;
    case 0:mciSendString(L"close menu", NULL, 0, NULL);break;//如果输入0,关闭音乐
    }
}

//游戏音乐
void m_game(int t) {
    switch (music_num)//根据音乐号,选择要播放的音乐
    {
    case 0:
        mciSendString(L"open music\\经典游戏.mp3 alias game0", NULL, 0, NULL);
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
        case 0:mciSendString(L"stop game0 ", NULL, 0, NULL);break;//暂停播放
        }break;
    case 1:
        mciSendString(L"open music\\英雄之证.mp3 alias game1", NULL, 0, NULL);
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
        mciSendString(L"open music\\钢琴曲.mp3", NULL, 0, NULL);
        switch (t)
        {
        case 1:
            mciSendString(L"play music\\钢琴曲.mp3 repeat", NULL, 0, NULL);
            switch (volume1)
            {
            case 0:mciSendString(L"setaudio music\\钢琴曲.mp3 volume to 0", NULL, 0, NULL);break;
            case 1:mciSendString(L"setaudio music\\钢琴曲.mp3 volume to 330", NULL, 0, NULL);break;
            case 2:mciSendString(L"setaudio music\\钢琴曲.mp3 volume to 660", NULL, 0, NULL);break;
            case 3:mciSendString(L"setaudio music\\钢琴曲.mp3 volume to 990", NULL, 0, NULL);break;
            }break;
        case 0:mciSendString(L"stop music\\钢琴曲.mp3", NULL, 0, NULL);break;
        }break;
    }
}

//排行榜音乐
void m_rank(int t) {
    mciSendString(L"open music\\排行榜.mp3 alias rank", NULL, 0, NULL);
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

//胜利音乐
void m_win() {//因为胜利音乐太短,就不需要设置开关了
    mciSendString(L"play music\\成功.mp3", NULL, 0, NULL);
    switch (volume1)
    {
    case 0:mciSendString(L"setaudio music\\成功.mp3 volume to 0", NULL, 0, NULL);break;
    case 1:mciSendString(L"setaudio music\\成功.mp3 volume to 330", NULL, 0, NULL);break;
    case 2:mciSendString(L"setaudio music\\成功.mp3 volume to 660", NULL, 0, NULL);break;
    case 3:mciSendString(L"setaudio music\\成功.mp3 volume to 990", NULL, 0, NULL);break;
    }
}

//游戏音效

//移动光标
void m_move() {
    mciSendString(L"play music\\移动选项.mp3 ", NULL, 0, NULL);
    switch (volume2)
    {
    case 0:mciSendString(L"setaudio music\\移动选项.mp3 volume to 0", NULL, 0, NULL);break;
    case 1:mciSendString(L"setaudio music\\移动选项.mp3 volume to 330", NULL, 0, NULL);break;
    case 2:mciSendString(L"setaudio music\\移动选项.mp3 volume to 660", NULL, 0, NULL);break;
    case 3:mciSendString(L"setaudio music\\移动选项.mp3 volume to 990", NULL, 0, NULL);break;
    }
    mciSendString(L"play music\\移动选项.mp3 ", NULL, 0, NULL);
} 

//进行选择
void m_click() {
    mciSendString(L"play music\\点击菜单.mp3 ", NULL, 0, NULL);
    switch (volume2)
    {
    case 0:mciSendString(L"setaudio music\\点击菜单.mp3 volume to 0", NULL, 0, NULL);break;
    case 1:mciSendString(L"setaudio music\\点击菜单.mp3 volume to 330", NULL, 0, NULL);break;
    case 2:mciSendString(L"setaudio music\\点击菜单.mp3 volume to 660", NULL, 0, NULL);break;
    case 3:mciSendString(L"setaudio music\\点击菜单.mp3 volume to 990", NULL, 0, NULL);break;
    }
    mciSendString(L"play music\\点击菜单.mp3 ", NULL, 0, NULL);

} 