#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <string>
#define PI 3.1415926
float g=9.8;
float Height;
float Range;
int Vel=500;
int  Angle=45;
using namespace std;
int gDist;

static int menu_id;
static int Angle_manu;
static int submenu_id;
static int value = 0;
void menu(int num){

   Vel= num*100;

  glutPostRedisplay();
}

void dist_f_p_2(int num){

Angle = num;


  glutPostRedisplay();
}
void createMenu(void){     submenu_id = glutCreateMenu(menu);

     glutAddMenuEntry("100", 1);
    glutAddMenuEntry("200", 2);
    glutAddMenuEntry("300", 3);
    glutAddMenuEntry("400", 4);
    glutAddMenuEntry("500", 5);
    glutAddMenuEntry("600", 6);
    glutAddMenuEntry("700", 7);
    glutAddMenuEntry("800", 8);
    glutAddMenuEntry("900", 9);
    glutAddMenuEntry("1000", 10);
Angle_manu = glutCreateMenu(dist_f_p_2);
 glutAddMenuEntry("10", 10);
    glutAddMenuEntry("20", 20);
    glutAddMenuEntry("30", 30);
    glutAddMenuEntry("40", 40);
    glutAddMenuEntry("45", 45);
    glutAddMenuEntry("50", 50);
    glutAddMenuEntry("60", 60);
    glutAddMenuEntry("70", 70);
    glutAddMenuEntry("80", 80);
    glutAddMenuEntry("90", 90);

      menu_id = glutCreateMenu(menu);

    glutAddSubMenu("initial velocity", submenu_id);
    glutAddSubMenu("projection angle", Angle_manu);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void DrawCircle(float cx, float cy, float r, int num_segments) {

    glBegin(GL_TRIANGLE_FAN);
    for (int ii = 0; ii < num_segments; ii++)   {

        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();

}
void displaymarks( float num,int px,int py ){
float abd=num;


string str= to_string(abd);

   char ch[str.size() + 1];
   strcpy(ch, str.c_str());
  glLoadIdentity();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos2i(px, py);
    int i;
    for( i = 0; i<strlen(ch); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);

    }

}
void displaymark( int num,int px,int py ){
int abd=num;


string str= to_string(abd);

   char ch[str.size() + 1];
   strcpy(ch, str.c_str());
  glLoadIdentity();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos2i(px, py);
    int i;
    for( i = 0; i<strlen(ch); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);

    }

}
void displaytext( char ch[],int px,int py ){



   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos2i(px, py);
    int i;
    for( i = 0; i<strlen(ch); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);

    }

}
static bool spinning = true;

// This is the number of frames per second to render.
static const int FPS = 60;

// This global variable keeps track of the current orientation of the square.
// It is better to maintain the "state" of the animation globally rather
// than trying to successively accumulate transformations.  Over a period of
// time the approach of accumulating transformation matrices generally
// degrades due to rounding errors.
static GLfloat currentAngleOfRotation = 0.0;
void timer(int v) {
  if (spinning) {
    currentAngleOfRotation += 1.0;
    if (currentAngleOfRotation > 360.0) {
      currentAngleOfRotation -= 360.0;
    }
    glutPostRedisplay();
  }
  glutTimerFunc(1000/FPS, timer, v);
}

void delay(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}


int i=1;
void projectit(int angle,int vel ,int xc,int yc)
{int ux=0, uy=0;
int t=0;

 float theta=3.14*angle/180;//angle to radians

   Height=((Vel*sin(theta))*(Vel*sin(theta)))/(2*g);
 Range=((Vel*Vel)*sin((2*theta)))/(g);
 ux=vel*cos(theta);//X coord init value
 uy=vel*sin(theta);//Y coord init value
glPointSize(5);
t=((vel*vel)*(2*(sin(theta)*cos(theta))))/g;//maximum range that projectile can reach



i++;//nr of projectile (i=time) (t=distance to travel)
glColor3b(1,1,0);

    glMatrixMode(GL_MODELVIEW);
    float x=ux*i;//X coord value
float y=uy*i+(0.5*(-9.8)*(i*i));//Y coord value
//////
//  h=(v0 sinθ0)2/2g
//   R = v02 sin 2θ0/g

//time
float T=(float)t/10000;
displaymarks( Height,130,450 );
displaytext("height",50,450);
///

glPointSize(5);
glBegin(GL_LINES);
glVertex2d(0,390);
glVertex2d(1100,390);
glEnd();
displaymark( 0,0,380 );
displaymark( 500,100,380 );
displaymark( 1000,200,380 );
displaymark( 1500,300,380 );
displaymark( 2000,400,380 );
displaymark( 2500,500,380 );
displaymark( 3000,600,380 );

glPointSize(5);
////y xxx

displaymark( 2500,0,60 );
displaymark( 5000,0,110 );
displaymark( 7500,0,160 );
displaymark( 10000,0,210 );
displaymark( 12500,0,260 );
displaymark( 15000,0,310 );
displaymark( 15500,0,360 );
displaymark( 20000,0,410 );
displaymark( angle,450,450 );
displaytext("ANGLE of projection",300,450);//
//
displaymarks( Vel,450,400 );
displaytext("speed",300,400);
//angle
displaymarks( Range,100,400 );
displaytext("RANGE",50,400);

displaytext("starting hight",xc,yc);
   displaytext("000",000,0);

    //////string
    ///////////
   glTranslated((x/50),y/50,0);
  //glRotated(currentAngleOfRotation += 5,0,0,1);


  glFlush();
   DrawCircle(xc, yc, 6, 36000);
  glFlush();




delay(53);

if((y/50)<=(1-yc)){
     gDist=x/50;
     int xd=gDist,yd=y/50;
     i=0;
    projectit(Angle,Vel,00,20);

}
}
void setup()
{


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0,700,0,500,0,600);

}

void display()
{

 projectit(Angle,Vel,00,20);
glClearColor(1,1,0,0);
 glClear(GL_COLOR_BUFFER_BIT);

}


int main(int argc,char** argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(924,668);
    glutInitWindowPosition(0,0);

    glutCreateWindow("Projectile motion");
    createMenu();     glClearColor(1,1.0,0.0,0.0);

    setup();


    glutDisplayFunc(display);

    glutTimerFunc(100, timer, 0);
    glutMainLoop();
}
