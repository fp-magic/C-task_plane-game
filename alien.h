#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include<GL/glut.h>
#include<windows.h>
class alien//敌方飞机主类，每一种敌方飞机从这里公有派生出来
{
private:
    GLfloat x,y;//飞船当前坐标，范围是-1.0f到1.0f
public:
    virtual void paint()//调用此函数来绘制一个敌方飞机，不同种类飞机长的自然不一样
    virtual void fly()//调用此函数来更新飞机的位置，不同种类飞机飞行规则有区别
};
class alien:public alien1//举例
{
public:
    void paint();
    void fly();
};
//所有函数在alien.cpp内补全
#endif // ALIEN_H_INCLUDED
