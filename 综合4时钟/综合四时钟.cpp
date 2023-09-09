#undef UNICODE
#include <graphics.h>
#include<stdio.h>
#include <math.h>


#define High 480*1.5
#define Width 640*1.5
#define center_x  Width / 2
#define center_y  High / 2
#define  PI 3.141592653589
#define BackColor 0xFFC0CB//背景色
#define Silver 0xC0C0C0  //银色
#define PlateColor BLACK//0xDB7093//表盘颜色
SYSTEMTIME ti;  //定义系统变量    //用于直接获取系统时间
double Lenth = Width / 5 + 10;  //长度
char day_num[7][3] = { "SU", "MO", "TU", "WE", "TH", "FR", "SA" }, s[20],ss[20],sss[80];


void Draw_Pointer(int Num, double Lenth, int Color, int Size); //画指针
void draw_circular(double x, double y, int type, int line_size, int line_color, int fill_color, double Lenth); //画圆
void draw_main(); //画表盘刻度
void draw_line(int x, int y, int x1, int y1, int type, int size, int color); //画直线
void show_string(int x, int y, int height, int width, int back_color, int text_color, int num, char a[], int judge);//显示字符
void Plate(int month, int dayofweek, int hour, int day,int min,int sec); //画小表盘


int main() {
   
    initgraph(Width, High);//graphics库自带函数，创建一个窗口
    setbkcolor(BackColor);//设置背景色
    cleardevice(); //用背景色刷新背景
    
    BeginBatchDraw();
    draw_circular(center_x, center_y, PS_SOLID, 2, Silver, PlateColor, Lenth);//画表盘
    
    while (1)
    {
        draw_circular(center_x, center_y, PS_SOLID, 2, PlateColor, PlateColor, Lenth - 15);//覆盖上一次表盘内容
        GetLocalTime(&ti);  //获取当前时间
        Plate(ti.wMonth, ti.wDayOfWeek, ti.wHour, ti.wDay,ti.wMinute,ti.wSecond); //画三个小表盘
        
        draw_main();
        FlushBatchDraw();  //批量绘制
    }
    EndBatchDraw();
    closegraph();
    return 0;
}


void show_string(int x, int y, int height, int width, int back_color, int text_color, int num, char a[], int judge) {
    LOGFONT f;
    setbkcolor(back_color);//设置背景色
    gettextstyle(&f);                      // 获取当前字体设置
    settextcolor(text_color);
    f.lfHeight = 15;                   //设置字体大小
    f.lfWidth = 10;
    f.lfQuality = ANTIALIASED_QUALITY;        // 设置输出效果为抗锯齿
    settextstyle(&f);                        // 设置字体样式
    if (judge) {
        sprintf_s(s, "%d", num);
        outtextxy(x, y, s);     //outtextxy函数用于输出字符串在指定位置
    }
    else outtextxy(x, y, a);
}
void draw_line(int x, int y, int x1, int y1, int type, int size, int color) {
    setlinestyle(PS_SOLID, size);  //设置线条的类型  PS_SOLID 实线 PS_DASH 虚线 PS_DOT 点线 PS_DASHDOT 点化线 PS_DASHDOTDOT 双点化线
    setcolor(color); //设置画笔颜色
    line(x, y, x1, y1);
}
void Draw_Pointer(int Num, double Lenth, int Color, int Size) {
    double Angle = Num * 2 * PI / 60 / 12; //获取当前的秒数
    double x = center_x + Lenth * sin(Angle);
    double y = center_y - Lenth * cos(Angle);
    draw_line(center_x, center_y, x, y, PS_SOLID, Size, Color);
}
void draw_circular(double x, double y, int type, int line_size, int line_color, int fill_color, double Lenth) {
    setlinestyle(type, line_size);  //设置线条的类型  PS_SOLID 实线 PS_DASH 虚线 PS_DOT 点线 PS_DASHDOT 点化线 PS_DASHDOTDOT 双点化线
    setfillcolor(fill_color);//设定填充颜色
    setcolor(line_color);  //设定边线颜色
    fillcircle(x, y, Lenth); //填充画圆
}
void draw_main() {
    draw_circular(center_x, center_y - (Width / 5 - 4), PS_SOLID, 2, GREEN, GREEN, 8);
    draw_circular(center_x + Width / 5 - 4, center_y, PS_SOLID, 2, 0xDB7093, 0xDB7093, 8);
    draw_circular(center_x, center_y + Width / 5 - 4, PS_SOLID, 2, RED, RED, 8);
    draw_circular(center_x - (Width / 5 - 4), center_y, PS_SOLID, 2, YELLOW, YELLOW, 8);
    for (int i = 0; i < 12; i++) {
        if (i % 3 != 0) {
            double x = center_x + (Lenth - 5) * sin(PI * i / 6);
            double y = center_y - (Lenth - 5) * cos(PI * i / 6);
            draw_circular(x, y, PS_SOLID, 2, WHITE, WHITE, 2);
        }
    }
    for (int i = 0; i < 60; i++) {
        if (i % 5 != 0) {
            double x = center_x + (Lenth - 3) * sin(PI * i / 30);
            double y = center_y - (Lenth - 3) * cos(PI * i / 30);
            double x1 = center_x + (Lenth - 10) * sin(PI * i / 30);
            double y1 = center_y - (Lenth - 10) * cos(PI * i / 30);
            draw_line(x, y, x1, y1, PS_SOLID, 1, WHITE);
        }
    }
    for (int i = 0; i < 360; i += 30) {
        if ((i / 30) % 3 != 0) {
            double a = 15, c = Lenth - 10, d = Lenth - 30, angle = 1;
            setfillcolor(Silver);//设定填充颜色
            setcolor(Silver);  //设定边线颜色
            POINT x_y[] = {
                    { 1.0 * d * sin(2 * PI * (1.0 * i / 360)) + 1.0 * center_x, 1.0 * (-d) * cos(2 * PI * (1.0 * i / 360)) + 1.0 * center_y },
                    { 1.0 * (a + d) * sin(2 * PI * (1.0 * i / 360)) + 1.0 * center_x, 1.0 * (-d - a) * cos(2 * PI * (1.0 * i / 360)) + 1.0 * center_y },
                    { c * sin(2 * PI * (1.0 * i / 360) - 2 * PI * (angle / 360)) + center_x, -c * cos(2 * PI * (1.0 * i / 360) - 2 * PI * (angle / 360)) + center_y },
            };

            fillpolygon(x_y, 3);
            POINT x_y1[3] = {
                    { 1.0 * d * sin(2 * PI * (1.0 * i / 360)) + 1.0 * center_x, 1.0 * (-d) * cos(2 * PI * (1.0 * i / 360)) + 1.0 * center_y },
                    { 1.0 * (a + d) * sin(2 * PI * (1.0 * i / 360)) + 1.0 * center_x, 1.0 * (-d - a) * cos(2 * PI * (1.0 * i / 360)) + 1.0 * center_y },
                    { c * sin(2 * PI * (1.0 * i / 360) + 2 * PI * (angle / 360)) + center_x, -c * cos(2 * PI * (1.0 * i / 360) + 2 * PI * (angle / 360)) + center_y },
            };
            fillpolygon(x_y1, 3);
        }
    }
    draw_circular(center_x, center_y, PS_SOLID, 2, WHITE, WHITE, 8);
    Draw_Pointer((1.0 * ti.wMinute / 60 + ti.wHour) * 60, Lenth - 70, YELLOW, 10);//时针
    Draw_Pointer((1.0 * ti.wSecond / 60 + ti.wMinute) * 12, Lenth - 30, RED, 6);//分针
    Draw_Pointer((1.0 * ti.wMilliseconds / 1000 + ti.wSecond) * 12, Lenth - 20, GREEN, 4); //秒针
    draw_circular(center_x, center_y, PS_SOLID, 2, BLACK, BLACK, 3);
}
void Plate(int month, int dayofweek, int hour, int day,int min,int sec)
{
    int COLOR = 0xDB7093;
  
    TCHAR sa[] = "林健波";              //在窗口输出字符串
    settextstyle(30, 0, ("楷体"));  //设置字符串大小和字体
    outtextxy(center_x-50, center_y+200, sa);
   
    for (int i = 60; i <= 360; i += 120) {
        double center_x1 = center_x + (Lenth / 5 * 2) * sin(PI * i * 2 / 360);
        double center_y1 = center_y - (Lenth / 5 * 2) * cos(PI * i * 2 / 360);
        if (i == 300) {
            for (int j = 0; j < 14; j++) {
                if (j % 2 == 0) {
                    double x = center_x1 + (Lenth / 4) * sin(PI * j / 7);
                    double y = center_y1 - (Lenth / 4) * cos(PI * j / 7);
                    double x1 = center_x1 + (Lenth / 4 - 6) * sin(PI * j / 7);
                    double y1 = center_y1 - (Lenth / 4 - 6) * cos(PI * j / 7);
                    draw_line(x, y, x1, y1, PS_SOLID, 1, WHITE);
                    x = -8 + center_x1 + (Lenth / 4 - 18) * sin(PI * j / 7);
                    y = -8 + center_y1 - (Lenth / 4 - 18) * cos(PI * j / 7);
                    show_string(x, y, 10, 5, PlateColor, WHITE, 0, day_num[(j + 2) / 2 - 1], 0);

                }
            }
            double x1 = center_x1 + (Lenth / 4 - 12) * sin(PI * dayofweek / 3.5);
            double y1 = center_y1 - (Lenth / 4 - 12) * cos(PI * dayofweek / 3.5);
            draw_line(center_x1, center_y1, x1, y1, PS_SOLID, 2, COLOR);
            draw_circular(center_x1, center_y1, PS_SOLID, 2, COLOR, COLOR, 2);
        }
        if (i == 60) {
            for (int j = 0; j < 24; j++) {
                if (j % 2 == 0) {
                    double x = center_x1 + (Lenth / 4) * sin(PI * j / 12);
                    double y = center_y1 - (Lenth / 4) * cos(PI * j / 12);
                    double x1 = center_x1 + (Lenth / 4 - 6) * sin(PI * j / 12);
                    double y1 = center_y1 - (Lenth / 4 - 6) * cos(PI * j / 12);
                    draw_line(x, y, x1, y1, PS_SOLID, 1, WHITE);
                    if (j % 4 == 0) {
                        double x = -6 + center_x1 + (Lenth / 4 - 18) * sin(PI * j / 12);
                        double y = -6 + center_y1 - (Lenth / 4 - 18) * cos(PI * j / 12);
                        show_string(x, y, 10, 5, PlateColor, WHITE, 12 - j / 2, 0, 1);
                    }
                }
            }
            double x1 = center_x1 + (Lenth / 4 - 12) * sin(PI * (12 - month) / 6);
            double y1 = center_y1 - (Lenth / 4 - 12) * cos(PI * (12 - month) / 6);
            draw_line(center_x1, center_y1, x1, y1, PS_SOLID, 2, COLOR);
            draw_circular(center_x1, center_y1, PS_SOLID, 2, COLOR, COLOR, 2);
        }
        else if (i == 180) {
            for (int j = 0; j < 24; j++) {
                if (j % 2 == 0 && j % 6 != 0) {
                    double x = center_x1 + (Lenth / 4) * sin(PI * j / 12);
                    double y = center_y1 - (Lenth / 4) * cos(PI * j / 12);
                    double x1 = center_x1 + (Lenth / 4 - 6) * sin(PI * j / 12);
                    double y1 = center_y1 - (Lenth / 4 - 6) * cos(PI * j / 12);
                    draw_line(x, y, x1, y1, PS_SOLID, 1, WHITE);
                }
                else if (j % 2 != 0) {
                    double x = center_x1 + (Lenth / 4) * sin(PI * j / 12);
                    double y = center_y1 - (Lenth / 4) * cos(PI * j / 12);
                    double x1 = center_x1 + (Lenth / 4 - 2) * sin(PI * j / 12);
                    double y1 = center_y1 - (Lenth / 4 - 2) * cos(PI * j / 12);
                    draw_line(x, y, x1, y1, PS_SOLID, 1, WHITE);
                }
                else {
                    double x = -6 + center_x1 + (Lenth / 4) * sin(PI * j / 12);
                    double y = -8 + center_y1 - (Lenth / 4) * cos(PI * j / 12);
                    show_string(x, y, 10, 5, PlateColor, WHITE, (24 + j) % 24, 0, 1);
                }
            }
            double x1 = center_x1 + (Lenth / 4 - 12) * sin(PI * hour / 12);
            double y1 = center_y1 - (Lenth / 4 - 12) * cos(PI * hour / 12);
            draw_line(center_x1, center_y1, x1, y1, PS_SOLID, 2, COLOR);
            draw_circular(center_x1, center_y1, PS_SOLID, 2, COLOR, COLOR, 2);
        }
    }
    setfillcolor(WHITE);//设定填充颜色
    setcolor(Silver);  //设定边线颜色
    setlinestyle(PS_SOLID, 4);  //设置线条的类型  PS_SOLID 实线 PS_DASH 虚线 PS_DOT 点线 PS_DASHDOT 点化线 PS_DASHDOTDOT 双点化线
   
    //创建矩形区域，和方框进行字符串输入
    char a1[] = "日"; char a2[] = "时"; char a3[] = "分"; char a4[] = "秒";
    char atri[] = "时间停止吧，你是多么美丽";
    fillrectangle(center_x + 80, center_y + 40, center_x + 180, center_y + 60);
    RECT r = { center_x + 80,center_y + 40,center_x + 180,center_y + 60 };
    sprintf_s(s, "%d%s:%d%s",min,a3,sec,a4);
    fillrectangle(center_x + -80, center_y + 40, center_x - 180, center_y + 60);
    RECT rr = { center_x -80,center_y + 40,center_x -180,center_y + 60 };
    sprintf_s(ss, "%d%s:%d%s", day,a1, hour,a2);
    fillrectangle(center_x -130, center_y - 100, center_x+130 , center_y -130);
    RECT rrr = { center_x-130 ,center_y - 100,center_x+130 ,center_y -130 };
    sprintf_s(sss, "%s", atri);

    settextcolor(BLACK);
    setbkcolor(WHITE);//设置背景色

    drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(ss, &rr, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
    drawtext(sss, &rrr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//这里才是真正写入文本的接口
}