#include<windows.h>
#pragma comment(linker, "/subsystem:/"windows/" /entry:/"mainCRTStartup/"" )
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include"weapons.h"
#include"planes.h"
using namespace std;
const GLfloat Pi=3.14159265359f;
GLfloat windowWidth;
GLfloat windowHeight;
int MainState;
int speed,score;
Human *humanplane;
Plane* allplane[105];
int ahead,atail;
void bg0()
{
    char *str = "press s to start game";
    int n = strlen(str);
    glRasterPos2i(windowWidth*0.2f,windowHeight*0.5f);
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *(str+i));
}
void bg1()
{
    char str[20];
    sprintf(str,"%d lives left",humanplane->life);
    int n = strlen(str);
    glRasterPos2i(0.0f,windowHeight*0.95f);
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *(str+i));
    char str2[20];
    sprintf(str2,"score: %d",score);
    int n2 = strlen(str2);
    glRasterPos2i(0.0f,windowHeight*0.90f);
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *(str2+i));
    humanplane->paint();
    for(int i=ahead;i!=atail;i=(i+1)%100)
    {
        allplane[i]->paint();
        if(allplane[i]->ifbeat(humanplane))
        {
            humanplane->todie();
            if(!humanplane->isyourdaddy())
            {
                for(int j=ahead;j!=atail;j=(j+1)%100)delete allplane[j];
                ahead=0;atail=0;
                speed=0;score=0;
                MainState=2;
                break;
            }
        }
        if(humanplane->ifbeat(allplane[i]))
        {
            allplane[i]->todie();
            if(allplane[i]->isdie())score++;
        }
    }
}
void bg2()
{
    char *str = "you died, press s to restart";
    int n = strlen(str);
    glRasterPos2i(windowWidth*0.05f,windowHeight*0.5f);
    for (int i = 0; i < n; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *(str+i));
}
void RenderScene()//绘制新的一帧
{
    glClear(GL_COLOR_BUFFER_BIT);//清空
    if(MainState==0)bg0();
    if(MainState==1)bg1();
    if(MainState==2)bg2();
    glutSwapBuffers();//将绘制结果放入缓存
}
void ChangeSize(GLsizei w,GLsizei h)//根据窗口大小调整
{
    if (h == 0)
    {
        h = 1;
    }
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    {
        windowHeight = 720.0f*h/w;
        windowWidth = 480.0f;
    }
    else
    {
        windowHeight = 720.0f;
        windowWidth =480.0f*w/h;
    }
    glOrtho(0.0f,windowWidth,0.0f,windowHeight,1.0f,-1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void TimerFunction(int value)
{
    /*
    刷新时修改的内容
    */
    if(MainState==1)
    {
        humanplane->fly();
        generate_Plane(ahead,atail,allplane,speed);
        for(int i=ahead;i!=atail;i=(i+1)%100)
        {
            allplane[i]->fly();
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20,TimerFunction,value);//刷新时间，设为20ms
}
void init()
{
    /*
    初始化用
    */
    srand((unsigned)time(NULL));
    MainState=0;
    ahead=0;atail=0;
    speed=0;score=0;
}
void myKeys(unsigned char key,int px,int py)
{
    //键盘处理
    if(key==27)exit(0);
    if(MainState==0||MainState==2)
    {
        if(key=='s')
        {
            delete humanplane;
            humanplane=new Human;
            MainState=1;
        }
    }
    if(MainState==1)
    {
        if(key=='w')
        {
            humanplane->moveup();
        }
        if(key=='a')
        {
            humanplane->moveleft();
        }
        if(key=='s')
        {
            humanplane->movedown();
        }
        if(key=='d')
        {
            humanplane->moveright();
        }
    }
}
int main(int argc,char * argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("plane game");
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(myKeys);
    glutTimerFunc(20,TimerFunction,1);
    glutMainLoop();
    return 0;
}

