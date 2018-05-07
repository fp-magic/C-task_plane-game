#include<windows.h>
#include<GL/glut.h>
#include"planes.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int Plane::ifbeat(Plane* onePlane)
{
    if(state==0||onePlane->isyourdaddy()||onePlane->isdie())return 0;
    int xtime=0,ytime=0;
    for(int i=0;i<2;i++)
        if(sx[i]<=onePlane->sx[1]&&sx[i]>=onePlane->sx[0])xtime++;
    for(int i=0;i<2;i++)
        if(sy[i]<=onePlane->sy[1]&&sy[i]>=onePlane->sy[0])ytime++;
    if(xtime>=1&&ytime>=1)return 1;
    for(int j=wp->head;j!=wp->tail;j=(j+1)%100)
    {
        xtime=0;ytime=0;
        if(onePlane->sx[0]<=wp->wx[j]&&onePlane->sx[1]>=wp->wx[j])xtime++;
        if(onePlane->sy[0]<=wp->wy[j]&&onePlane->sy[1]>=wp->wy[j])ytime++;
        if(xtime>=1&&ytime>=1)return 1;
    }
    return 0;
}
void Plane::todie()
{
    if(--life<=0)state=0;
    else state=2,tmp=0;
}
int Plane::isyourdaddy()
{
    return state==2;
}
int Plane::isdie()
{
    return state==0;
}
Human::Human()
{
    x=240.0f;
    y=10.0f;
    sx[0]=x;sy[0]=y;
    sx[1]=x+40.0f;sy[1]=y+60.0f;
    gx[0]=x;gx[1]=x+13.0f;gx[2]=x+27.0f;gx[3]=x+40.0f;
    gx[4]=x+24.0f;gx[5]=x+20.0f;gx[6]=x+16.0f;gx[7]=x;
    gy[0]=y;gy[1]=y+10;gy[2]=y+10;gy[3]=y;
    gy[4]=y+25.0f;gy[5]=y+60.0f;gy[6]=y+25.0f;gy[7]=y;
    wp=new Weapon_Human0(x+(sx[1]-sx[0])/2.0f,sy[1]);
    state=1;
    life=3;
}
void Human::paint()
{
    glColor3f(0.98f, 0.625f, 0.12f);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<8;i++)
        glVertex2f(gx[i],gy[i]);

    glEnd();
    if(state==2&&tmp%10>=5)
    {
        glBegin(GL_LINE_LOOP);
        glVertex2f(sx[0],sy[0]);
        glVertex2f(sx[1],sy[0]);
        glVertex2f(sx[1],sy[1]);
        glVertex2f(sx[0],sy[1]);
        glEnd();
    }
    wp->paint();
}
void Human::fly()
{
    tmp++;
    if(tmp>=100)state=1;
    wp->fly(x+(sx[1]-sx[0])/2.0f,sy[1]);
}
void Human::moveleft()
{
    if(x>=15.0f)
    {
        x-=10.0f;sx[0]-=10.0f;sx[1]-=10.0f;
        for(int i=0;i<8;i++)gx[i]-=10.0f;
    }
}
void Human::moveright()
{
    if(x<=435.0f)
    {
        x+=10.0f;sx[0]+=10.0f;sx[1]+=10.0f;
        for(int i=0;i<8;i++)gx[i]+=10.0f;
    }
}
void Human::moveup()
{
    if(y<=635.0f)
    {
        y+=10.0f;sy[0]+=10.0f;sy[1]+=10.0f;
        for(int i=0;i<8;i++)gy[i]+=10.0f;
    }
}
void Human::movedown()
{
    if(y>=15.0f)
    {
        y-=10.0f;sy[0]-=10.0f;sy[1]-=10.0f;
        for(int i=0;i<8;i++)gy[i]-=10.0f;
    }
}
Human::~Human()
{
    delete wp;
}

Alien_1::Alien_1(GLfloat px)
{
    x=px;
    y=730.0f;
    sx[0]=x;sy[0]=y;
    sx[1]=x+60.0f;sy[1]=y+40.0f;
    gx[0]=x;gx[1]=x+15.0f;gx[2]=x+45.0f;gx[3]=x+60.0f;
    gx[4]=x+60.0f;gx[5]=x+45.0f;gx[6]=x+15.0f;gx[7]=x;
    gy[0]=y;gy[1]=y+15.0f;gy[2]=y+15.0f;gy[3]=y;
    gy[4]=y+40.0f;gy[5]=y+25.0f;gy[6]=y+25.0f;gy[7]=y+40.0f;
    wp=new Weapon_Alien0(x+(sx[1]-sx[0])/2.0f,sy[0]);
    state=1;
    life=1;
}
void Alien_1::paint()
{
    if(state==0)return;
    glColor3f(0.28f, 0.625f, 0.82f);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<8;i++)
        glVertex2f(gx[i],gy[i]);
    glEnd();
    wp->paint();
}
void Alien_1::fly()
{
    if(state==0)return;
    y-=5.0f;
    sy[0]-=5.0f;
    sy[1]-=5.0f;
    for(int i=0;i<8;i++)gy[i]-=5.0f;
    wp->fly(x+(sx[1]-sx[0])/2.0f,sy[0]);
}
int Alien_1::ifout()
{
    if(y<=0.0f)return 1;
    else return 0;
}
Alien_1::~Alien_1()
{
    delete wp;
}
Alien_1_1::Alien_1_1(GLfloat px):Alien_1(px)
{
    life=3;
}
void Alien_1_1::fly()
{
    if(state==0)return;
    if(state==2)state=1;
    y-=7.0f;
    sy[0]-=7.0f;
    sy[1]-=7.0f;
    if(dir==0)
    {
        if(rand()>=31000)dir=1;
    }else
        if(rand()>=31000)dir=0;
    if(x<=15.0f)dir=1;
    if(x>=450.0f)dir=0;
    for(int i=0;i<8;i++)gy[i]-=7.0f;
    if(dir==0)
    {
        x-=3.0f;
        sx[0]-=3.0f;
        sx[1]-=3.0f;
        for(int i=0;i<8;i++)gx[i]-=3.0f;
    }else
    {
        x+=3.0f;
        sx[0]+=3.0f;
        sx[1]+=3.0f;
        for(int i=0;i<8;i++)gx[i]+=3.0f;
    }
    wp->fly(x+(sx[1]-sx[0])/2.0f,sy[0]);
    //printf("%d\n",life);
}
void generate_Plane(int &head,int &tail,Plane**allplane,int &speed )
{

    if(rand()>=31500-10*speed)
    {
        if(rand()>=28000-20*speed)
        {
            allplane[tail]=new Alien_1_1((GLfloat)(rand()/(GLfloat)RAND_MAX*450.0f+10.0f));
        }
        else
            allplane[tail]=new Alien_1((GLfloat)(rand()/(GLfloat)RAND_MAX*450.0f+10.0f));
        tail=(tail+1)%100;
        while(allplane[head]->ifout())head=(head+1)%100;
    }
}
