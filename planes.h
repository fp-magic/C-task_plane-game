#ifndef PLANES_H_INCLUDED
#define PLANES_H_INCLUDED
#include<GL/glut.h>
#include<windows.h>
#include<vector>
#include"weapons.h"
using namespace std;
class Plane//飞机基类，每一种飞机从这里公有派生出来
{
protected:
    GLfloat x,y;//飞船当前主坐标，范围是-1.0f到1.0f
    GLfloat gx[8],gy[8];//飞船绘制坐标
    Weapon* wp;//飞船携带的武器,暂定只有一种
    int state;//表示飞船是否存活
    int i,tmp;
public:
    int life;
    GLfloat sx[2],sy[2];//飞机坐标范围，即产生碰撞的范围，为多边形，暂定为矩形
    virtual void paint(){}//调用此函数来绘制一个飞机，要调用武器绘制，不同种类飞机长的自然不一样
    virtual void fly(){}//调用此函数来更新飞机的位置，要调用武器位置更新，不同种类飞机飞行规则有区别
    int ifbeat(Plane* onePlane);//判断是否与飞机相撞，是返回1，否则返回0
    void todie();
    int isdie();
    int isyourdaddy();
    virtual int ifout(){return 0;}//判断是否完全离开主界面范围
    virtual ~Plane(){}//ifcrash为true时调用，需要绘制爆炸图像
};

class Human:public Plane//我方飞机,暂定只有一种
{
public:
    Human();
    void paint();
    void fly();
    void moveleft();
    void moveright();
    void moveup();
    void movedown();//注意不要出地图了
    ~Human();
};

class Alien_1:public Plane//敌方飞机举例
{
public:
    Alien_1(GLfloat px);
    void paint();
    void fly();
    int ifout();
    ~Alien_1();
};
class Alien_1_1:public Alien_1
{
protected:
    int dir;
public:
    Alien_1_1(GLfloat px);
    void fly();
};
void generate_Plane(int &head,int &tail,Plane**allplane,int &speed);//产生新的敌方飞机，可以一次产生多个，也可以不产生，尽量不要和其他飞机重叠
#endif // PLANES_H_INCLUDED
