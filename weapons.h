#ifndef WEAPONS_H_INCLUDED
#define WEAPONS_H_INCLUDED
#include<GL/glut.h>
#include<windows.h>
#include<queue>
#include<stdio.h>
using namespace std;
class Weapon//�������࣬���������ɴ�����
{
protected:
    int num;//�ӵ�����
    int tmp;//ʱ�����
public:
    int head,tail;
    GLfloat wx[105],wy[105];//ÿ���ӵ���λ�ã�ע��ÿ���ӵ���λ�ü�Ϊ��ײ��
    virtual void paint(){}//�������������ӵ���λ��
    virtual void fly(GLfloat fx,GLfloat fy){}//��������λ��
    //����Ŀ��ʱ�����ɻ�Ч�����ʲ���Ҫ��������
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
//���к�����planes.cpp�ڲ�ȫ
#endif // WEAPONS_H_INCLUDED
