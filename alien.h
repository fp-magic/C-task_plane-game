#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#include<GL/glut.h>
#include<windows.h>
class alien//�з��ɻ����࣬ÿһ�ֵз��ɻ������﹫����������
{
private:
    GLfloat x,y;//�ɴ���ǰ���꣬��Χ��-1.0f��1.0f
public:
    virtual void paint()//���ô˺���������һ���з��ɻ�����ͬ����ɻ�������Ȼ��һ��
    virtual void fly()//���ô˺��������·ɻ���λ�ã���ͬ����ɻ����й���������
};
class alien:public alien1//����
{
public:
    void paint();
    void fly();
};
//���к�����alien.cpp�ڲ�ȫ
#endif // ALIEN_H_INCLUDED
