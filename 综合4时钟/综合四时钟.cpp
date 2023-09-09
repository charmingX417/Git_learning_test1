#undef UNICODE
#include <graphics.h>
#include<stdio.h>
#include <math.h>


#define High 480*1.5
#define Width 640*1.5
#define center_x  Width / 2
#define center_y  High / 2
#define  PI 3.141592653589
#define BackColor 0xFFC0CB//����ɫ
#define Silver 0xC0C0C0  //��ɫ
#define PlateColor BLACK//0xDB7093//������ɫ
SYSTEMTIME ti;  //����ϵͳ����    //����ֱ�ӻ�ȡϵͳʱ��
double Lenth = Width / 5 + 10;  //����
char day_num[7][3] = { "SU", "MO", "TU", "WE", "TH", "FR", "SA" }, s[20],ss[20],sss[80];


void Draw_Pointer(int Num, double Lenth, int Color, int Size); //��ָ��
void draw_circular(double x, double y, int type, int line_size, int line_color, int fill_color, double Lenth); //��Բ
void draw_main(); //�����̶̿�
void draw_line(int x, int y, int x1, int y1, int type, int size, int color); //��ֱ��
void show_string(int x, int y, int height, int width, int back_color, int text_color, int num, char a[], int judge);//��ʾ�ַ�
void Plate(int month, int dayofweek, int hour, int day,int min,int sec); //��С����


int main() {
   
    initgraph(Width, High);//graphics���Դ�����������һ������
    setbkcolor(BackColor);//���ñ���ɫ
    cleardevice(); //�ñ���ɫˢ�±���
    
    BeginBatchDraw();
    draw_circular(center_x, center_y, PS_SOLID, 2, Silver, PlateColor, Lenth);//������
    
    while (1)
    {
        draw_circular(center_x, center_y, PS_SOLID, 2, PlateColor, PlateColor, Lenth - 15);//������һ�α�������
        GetLocalTime(&ti);  //��ȡ��ǰʱ��
        Plate(ti.wMonth, ti.wDayOfWeek, ti.wHour, ti.wDay,ti.wMinute,ti.wSecond); //������С����
        
        draw_main();
        FlushBatchDraw();  //��������
    }
    EndBatchDraw();
    closegraph();
    return 0;
}


void show_string(int x, int y, int height, int width, int back_color, int text_color, int num, char a[], int judge) {
    LOGFONT f;
    setbkcolor(back_color);//���ñ���ɫ
    gettextstyle(&f);                      // ��ȡ��ǰ��������
    settextcolor(text_color);
    f.lfHeight = 15;                   //���������С
    f.lfWidth = 10;
    f.lfQuality = ANTIALIASED_QUALITY;        // �������Ч��Ϊ�����
    settextstyle(&f);                        // ����������ʽ
    if (judge) {
        sprintf_s(s, "%d", num);
        outtextxy(x, y, s);     //outtextxy������������ַ�����ָ��λ��
    }
    else outtextxy(x, y, a);
}
void draw_line(int x, int y, int x1, int y1, int type, int size, int color) {
    setlinestyle(PS_SOLID, size);  //��������������  PS_SOLID ʵ�� PS_DASH ���� PS_DOT ���� PS_DASHDOT �㻯�� PS_DASHDOTDOT ˫�㻯��
    setcolor(color); //���û�����ɫ
    line(x, y, x1, y1);
}
void Draw_Pointer(int Num, double Lenth, int Color, int Size) {
    double Angle = Num * 2 * PI / 60 / 12; //��ȡ��ǰ������
    double x = center_x + Lenth * sin(Angle);
    double y = center_y - Lenth * cos(Angle);
    draw_line(center_x, center_y, x, y, PS_SOLID, Size, Color);
}
void draw_circular(double x, double y, int type, int line_size, int line_color, int fill_color, double Lenth) {
    setlinestyle(type, line_size);  //��������������  PS_SOLID ʵ�� PS_DASH ���� PS_DOT ���� PS_DASHDOT �㻯�� PS_DASHDOTDOT ˫�㻯��
    setfillcolor(fill_color);//�趨�����ɫ
    setcolor(line_color);  //�趨������ɫ
    fillcircle(x, y, Lenth); //��仭Բ
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
            setfillcolor(Silver);//�趨�����ɫ
            setcolor(Silver);  //�趨������ɫ
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
    Draw_Pointer((1.0 * ti.wMinute / 60 + ti.wHour) * 60, Lenth - 70, YELLOW, 10);//ʱ��
    Draw_Pointer((1.0 * ti.wSecond / 60 + ti.wMinute) * 12, Lenth - 30, RED, 6);//����
    Draw_Pointer((1.0 * ti.wMilliseconds / 1000 + ti.wSecond) * 12, Lenth - 20, GREEN, 4); //����
    draw_circular(center_x, center_y, PS_SOLID, 2, BLACK, BLACK, 3);
}
void Plate(int month, int dayofweek, int hour, int day,int min,int sec)
{
    int COLOR = 0xDB7093;
  
    TCHAR sa[] = "�ֽ���";              //�ڴ�������ַ���
    settextstyle(30, 0, ("����"));  //�����ַ�����С������
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
    setfillcolor(WHITE);//�趨�����ɫ
    setcolor(Silver);  //�趨������ɫ
    setlinestyle(PS_SOLID, 4);  //��������������  PS_SOLID ʵ�� PS_DASH ���� PS_DOT ���� PS_DASHDOT �㻯�� PS_DASHDOTDOT ˫�㻯��
   
    //�����������򣬺ͷ�������ַ�������
    char a1[] = "��"; char a2[] = "ʱ"; char a3[] = "��"; char a4[] = "��";
    char atri[] = "ʱ��ֹͣ�ɣ����Ƕ�ô����";
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
    setbkcolor(WHITE);//���ñ���ɫ

    drawtext(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(ss, &rr, DT_CENTER | DT_VCENTER | DT_SINGLELINE); 
    drawtext(sss, &rrr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�����������д���ı��Ľӿ�
}