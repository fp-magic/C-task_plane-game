#ifndef WEAPONS_H_INCLUDED
#define WEAPONS_H_INCLUDED
#include<GL/glut.h>
#include<windows.h>
#include<queue>
#include<stdio.h>
using namespace std;
class Weapon//武器基类，所有武器由此派生
{
protected:
    int num;//子弹数量
    int tmp;//时间变量
public:
    int head,tail;
    GLfloat wx[105],wy[105];//每个子弹的位置，注意每个子弹的位置即为碰撞点
    virtual void paint(){}//绘制武器（即子弹）位置
    virtual void fly(GLfloat fx,GLfloat fy){}//更新武器位置
    //击中目标时触发飞机效果，故不需要析构函数
};
class Weapon_Human0:public Weapon
{
public:
    Weapon_Human0(GLfloat fx,GLfloat fy);
    void paint();
    void fly(GLfloat fx,GLfloat fy);
};
class Weapon_Alien0:public Weapon
{
public:
    Weapon_Alien0(GLfloat fx,GLfloat fy);
    void paint();
    void fly(GLfloat fx,GLfloat fy);
};
//所有函数在planes.cpp内补全
#endif // WEAPONS_H_INCLUDED
