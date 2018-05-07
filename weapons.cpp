#include<windows.h>
#include<GL/glut.h>
#include"weapons.h"
#include<stdio.h>
using namespace std;
Weapon_Human0::Weapon_Human0(GLfloat fx,GLfloat fy)
{
    num=0;
    tmp=0;
    head=0;tail=1;
    wx[0]=fx;
    wy[0]=fy;
}
void Weapon_Human0::paint()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    for(int i=head;i!=tail;i=(i+1)%100)
    {
        glRectf(wx[i]-3,wy[i]-4,wx[i]+3.0f,wy[i]+4.0f);
    }
}
void Weapon_Human0::fly(GLfloat fx,GLfloat fy)
{
    tmp++;
    for(int i=head;i!=tail;i=(i+1)%100)
    {
        wy[i]+=10.0f;
    }
    if(tmp%5==0)
    {
        tmp%=5;
        tail=(tail+1)%100;
        wx[tail]=fx;
        wy[tail]=fy;
        while(wy[head]>720&&((head+1)%100!=tail))head=(head+1)%100;
    }
}
Weapon_Alien0::Weapon_Alien0(GLfloat fx,GLfloat fy)
{
    num=0;
    tmp=0;
    head=0;tail=1;
    wx[0]=fx;
    wy[0]=fy;
}
void Weapon_Alien0::paint()
{
    glColor3f(0.2f, 1.0f, 0.2f);
    for(int i=head;i!=tail;i=(i+1)%100)
    {
        glRectf(wx[i]-3,wy[i]-4,wx[i]+3.0f,wy[i]+4.0f);
    }
}
void Weapon_Alien0::fly(GLfloat fx,GLfloat fy)
{
    tmp++;
    for(int i=head;i!=tail;i=(i+1)%100)
    {
        wy[i]-=10.0f;
    }printf("\n");
    if(tmp%30==0)
    {
        tmp%=30;
        wx[tail]=fx;
        wy[tail]=fy;
        tail=(tail+1)%100;
        while(wy[head]<0&&((head+1)%100!=tail))head=(head+1)%100;
    }
}
