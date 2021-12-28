#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <iostream>
#include <math.h>
using namespace std;
class Figure
{
public:
    int color;
    int bgcolor;
    int xCoordinate, yCoordinate;
    Figure()
    {
        color = 0;
        bgcolor = 15;
        xCoordinate = 0;
        yCoordinate = 0;
    }

    void drawCircle()
    {
        int radius;
        cout << "Enter the X Coordinate";
        cin >> xCoordinate;
        cout << "Enter the Y Coordinate";
        cin >> yCoordinate;
        cout << "Enter the radius";
        cin >> radius;
        cout << "Enter the color number from the color scheme";
        cin >> color;
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        circle(xCoordinate, yCoordinate, radius);
        floodfill(xCoordinate, yCoordinate, color);
    }
    void drawRectangle()
    {
        int bottomX, bottomY;
        cout << "Enter the Top X Coordinate";
        cin >> xCoordinate;
        cout << "Enter the Top Y Coordinate";
        cin >> yCoordinate;
        cout << "Enter the Bottom X Coordinate";
        cin >> bottomX;
        cout << "Enter the Bottom Y Coordinate";
        cin >> bottomY;
        cout << "Enter the color number from the color scheme";
        cin >> color;
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        bar(xCoordinate, yCoordinate, bottomX, bottomY);
        floodfill(xCoordinate, yCoordinate, color);
    }
    void drawEllipse()
    {
        int stangle, endangle, xradius, yradius;
        cout << "Enter the X Coordinate";
        cin >> xCoordinate;
        cout << "Enter the Y Coordinate";
        cin >> yCoordinate;
        cout << "Enter the xradius";
        cin >> xradius;
        cout << "Enter the yradius";
        cin >> yradius;
        cout << "Enter the Start Angle";
        cin >> stangle;
        cout << "Enter the End Angle";
        cin >> endangle;
        cout << "Enter the color number from the color scheme";
        cin >> color;
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        ellipse(xCoordinate, yCoordinate, stangle, endangle, xradius, yradius);
        floodfill(xCoordinate, yCoordinate, color);
    }
    void drawArc()
    {
        int stangle, endangle, radius;
        cout << "Enter the X Coordinate";
        cin >> xCoordinate;
        cout << "Enter the Y Coordinate";
        cin >> yCoordinate;
        cout << "Enter the radius";
        cin >> radius;
        cout << "Enter the Start Angle";
        cin >> stangle;
        cout << "Enter the End Angle";
        cin >> endangle;
        cout << "Enter the color number from the color scheme";
        cin >> color;
        setcolor(color);
        arc(xCoordinate, yCoordinate, stangle, endangle, radius);
       
    }
};

void translation()
{
    int x1 = 200, y1 = 150, x2 = 300, y2 = 250;
    int tx = 50, ty = 50;
    cout << "Rectangle before translation" << endl;
    setcolor(3);
    rectangle(x1, y1, x2, y2);
    setcolor(4);
    cout << "Rectangle after translation" << endl;
    rectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
}
void rotation()
{
    long x1 = 200, y1 = 200, x2 = 300, y2 = 300;
    double a;
    cout << "Rectangle with rotation" << endl;
    setcolor(3);
    rectangle(x1, y1, x2, y2);
    cout << "Angle of rotation:";
    cin >> a;
    a = (a * 3.14) / 180;
    long xr = x1 + ((x2 - x1) * cos(a) - (y2 - y1) * sin(a));
    long yr = y1 + ((x2 - x1) * sin(a) + (y2 - y1) * cos(a));
    setcolor(2);
    rectangle(x1, y1, xr, yr);
}
void scaling()
{
    int x1 = 30, y1 = 30, x2 = 70, y2 = 70, y = 2, x = 2;
    cout << "Before scaling" << endl;
    setcolor(3);
    rectangle(x1, y1, x2, y2);
    cout << "After scaling" << endl;
    setcolor(10);
    rectangle(x1 * x, y1 * y, x2 * x, y2 * y);
}
void reflections()
{
    int x1 = 200, y1 = 300, x2 = 500, y2 = 300, x3 = 350, y3 = 400;
    cout << "triangle before reflection" << endl;
    setcolor(3);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    cout << "triangle after reflection" << endl;
    setcolor(5);
    line(x1, -y1 + 500, x2, -y2 + 500);
    line(x1, -y1 + 500, x3, -y3 + 500);
    line(x2, -y2 + 500, x3, -y3 + 500);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    outtextxy(200, 0, "Welcome to Graphics Editing Project");
    Figure draw;
    int ch = 0;
    cout << "Welcome to Graphics Editor Project\n";
    cout << "Color Schema\n";
    cout << "COLOR               INT VALUES\n-------------------------------\nBLACK                   0\nBLUE                    1\nGREEN                   2\nCYAN                    color   \nRED                     4\nMAGENTA                 5\nBROWN                   6 \nLIGHTGRAY               7 \nDARKGRAY                8\nLIGHTBLUE               9\nLIGHTGREEN             10\nLIGHTCYAN              11\nLIGHTRED               12\nLIGHTMAGENTA           1color\nYELLOW                 14\nWHITE                  15";
    cout << "\nFunctions\n";

    while (ch != 10)
    {
        cout << "1. Draw Circle\n2.Draw Rectangle\n3.Draw Ellipse\n4.Draw arc\n5.See Rotation Example\n6.See Translation Example\n7.See Scaling Example\n8.See Reflection Example\n9.Clear Screen\n10.Exit";
        cout << "Selection";
        cin >> ch;
        switch (ch)
        {
        case 1:
            draw.drawCircle();
            break;
        case 2:
            draw.drawRectangle();
            break;
        case 3:
            draw.drawEllipse();
            break;
        case 4:
            draw.drawArc();
            break;
        case 5:
            rotation();
            break;
        case 6:
            translation();
            break;
        case 7:
            scaling();
            break;
        case 8:
            reflections(); 
        case 9:
            cleardevice();
        case 10:
            break;
        default:
            cout << "Enter a Valid Choice";
        }
    }
    draw.drawCircle();
    closegraph();
    return 0;
}