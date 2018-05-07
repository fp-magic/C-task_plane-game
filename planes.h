#ifndef PLANES_H_INCLUDED
#define PLANES_H_INCLUDED
#include<GL/glut.h>
#include<windows.h>
#include<vector>
#include"weapons.h"
using namespace std;
class Plane//�ɻ����࣬ÿһ�ַɻ������﹫����������
{
protected:
    GLfloat x,y;//�ɴ���ǰ�����꣬��Χ��-1.0f��1.0f
    GLfloat gx[8],gy[8];//�ɴ���������
    Weapon* wp;//�ɴ�Я��������,�ݶ�ֻ��һ��
    int state;//��ʾ�ɴ��Ƿ���
    int i,tmp;
public:
    int life;
    GLfloat sx[2],sy[2];//�ɻ����귶Χ����������ײ�ķ�Χ��Ϊ����Σ��ݶ�Ϊ����
    virtual void paint(){}//���ô˺���������һ���ɻ���Ҫ�����������ƣ���ͬ����ɻ�������Ȼ��һ��
    virtual void fly(){}//���ô˺��������·ɻ���λ�ã�Ҫ��������λ�ø��£���ͬ����ɻ����й���������
    int ifbeat(Plane* onePlane);//�ж��Ƿ���ɻ���ײ���Ƿ���1�����򷵻�0
    void todie();
    int isdie();
    int isyourdaddy();
    virtual int ifout(){return 0;}//�ж��Ƿ���ȫ�뿪�����淶Χ
    virtual ~Plane(){}//ifcrashΪtrueʱ���ã���Ҫ���Ʊ�ըͼ��
};

class Human:public Plane//�ҷ��ɻ�,�ݶ�ֻ��һ��
{
public:
    Human();
    void paint();
    void fly();
    void moveleft();
    void moveright();
    void moveup();
    void movedown();//ע�ⲻҪ����ͼ��
    ~Human();
};

class Alien_1:public Plane//�з��ɻ�����
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
void generate_Plane(int &head,int &tail,Plane**allplane,int &speed);//�����µĵз��ɻ�������һ�β��������Ҳ���Բ�������������Ҫ�������ɻ��ص�
#endif // PLANES_H_INCLUDED
