#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include<GL/glext.h>
#include "SOIL.h"

#define PI 3.1415926

float BallX=-380,BallY=430;

float angleStart=5.24;

float rad=400,inc=1/1500000.0;
float speed=0.0001/8;
float angle=5.23;
float angleEnd=4.2;

GLfloat pz=-700,px=0,py=0;
unsigned char* image;
int width, height;
GLuint textures[6];
GLint mx,my;
static int menu_id;

static int submenu_id;

void menu(int num){

   rad= num;
speed= 0.0001/(rad/70);


  glutPostRedisplay();
}
void createMenu(void){     submenu_id = glutCreateMenu(menu);

    glutAddMenuEntry("100", 100); glutAddMenuEntry("150", 150);
    glutAddMenuEntry("200", 200); glutAddMenuEntry("250", 250);
    glutAddMenuEntry("300", 300); glutAddMenuEntry("350", 350);
    glutAddMenuEntry("400", 400); glutAddMenuEntry("450", 450);



      menu_id = glutCreateMenu(menu);

    glutAddSubMenu("lenght", submenu_id);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void sleep2(int duration)
{
    int end=clock()+duration;
    while(clock()<=end);
}



void loadImages()
{
    glGenTextures(6,textures);

    //Walls Texture
    image=SOIL_load_image("E:/Textures/Brick2.bmp",&width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D,textures[0]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    //Set Texture Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

    //Ceiling Texture
    image=SOIL_load_image("E:/Textures/Ceiling.bmp",&width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D,textures[1]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    //Set Texture Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

    //Floor Texture
    image=SOIL_load_image("E:/Textures/Wood1.bmp",&width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D,textures[2]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    //Set Texture Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

    //Painting Texture
    image=SOIL_load_image("E:/Textures/Baby.bmp",&width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D,textures[3]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    //Set Texture Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

    image=SOIL_load_image("E:/Textures/Ground1.bmp",&width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D,textures[4]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    //Set Texture Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

    image=SOIL_load_image("E:/Textures/Carpet.bmp",&width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D,textures[5]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    //Set Texture Parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

}
void setup()
{
    GLfloat w[]={1,1,1,1};
    GLfloat p[]={0,100,100,1};

    glClearColor(151/255.0,217/255.0,234/255.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1.33,1,2000);
    gluLookAt(px,100,pz,  mx,my,pz+400,   0,1,0);

    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,w);
    glLightfv(GL_LIGHT0,GL_POSITION,p);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,w);
}
void drawCircle(float xc,float yc, float radius)
{
    float x,y,angle,inc=2*PI/32;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.5,0.5,0);
    glVertex2i(xc,yc);
    for(angle=0;angle<=2*PI+inc;angle+=inc)
    {

        x=xc+radius*cos(angle);
        y=yc+radius*sin(angle);
        glColor3f(0.25,0.25,0);
        glVertex2i(x,y);
    }
    glEnd();
}

void display()
{
    GLfloat w[]={1,1,1,1};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_TEXTURE_2D);




     glBindTexture(GL_TEXTURE_2D,textures[4]);
    glBegin(GL_QUADS);
        //Ground
        glTexCoord2f(0.0, 0.0); glVertex3f(-1800,-101,-2000);
        glTexCoord2f(0.0, 10.0); glVertex3f(-1800,-101,2000);
        glTexCoord2f(10.0, 10.0); glVertex3f(1800,-101,2000);
        glTexCoord2f(10.0, 0.0); glVertex3f(1800,-101,-2000);
    glEnd();
    //left tawer
    glBindTexture(GL_TEXTURE_2D,textures[1]);
line3d(80,-500,80,0,-70,0);

glBindTexture(GL_TEXTURE_2D,textures[1]);

line3d(80,-80,80,100,-70,0);


line3d(80,-500,80,-900,-70,0);

line3d(980,-80,80,-900,430,0);


///
   //Draw Vert Suspension

    glBegin(GL_LINES);
        glVertex2i(-380,430);
        glVertex2i(BallX,BallY);
    glEnd();

    //Draw Ball

    drawCircle(BallX,BallY,50);


    //Now Animate the Pendulum
    BallX=-380+rad*cos(angle);
    BallY=430+rad*sin(angle);

    if(angle<=angleEnd || angle>=angleStart)
    {
        inc*=-1;
    }
    if(BallX>-380)
        inc+=speed;
    else
        inc-=speed;

angle-=inc;

    //Draw some text
    glColor3f(1,0,1);


    glFlush();

    glDisable(GL_TEXTURE_2D);
}

void kb(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            pz+=10;
            break;
        case GLUT_KEY_DOWN:
            pz-=10;
            break;
        case GLUT_KEY_LEFT:
            px+=10;
            break;
        case GLUT_KEY_RIGHT:
            px-=10;
            break;
    }

    setup();
}

void line3d(int w,int h,int b,int x1,int y1,int z1){


glBegin(GL_QUADS);
       // glColor3f(1,0,0);
glTexCoord2f(0.0, 0.0); glVertex3f(x1,y1,z1);
glTexCoord2f(0.0, 1.0); glVertex3f(x1,y1-h,z1);
glTexCoord2f(1.0, 1.0); glVertex3f(x1+w,y1-h,z1);
glTexCoord2f(1.0, 0.0); glVertex3f(x1+w,y1,z1);
       ///right
       //  glColor3f(0,1,0);
glTexCoord2f(0.0, 0.0);glVertex3f(x1+w,y1,z1);
glTexCoord2f(0.0, 1.0);glVertex3f(x1+w,y1-h,z1);
glTexCoord2f(1.0, 1.0);glVertex3f(x1+w,y1-h,z1+b);
glTexCoord2f(1.0, 0.0);glVertex3f(x1+w,y1,z1+b);

        ////back
         //   glColor3f(0,0,1);
glTexCoord2f(0.0, 0.0);glVertex3f(x1+w,y1,z1+b);
glTexCoord2f(0.0, 1.0);glVertex3f(x1+w,y1-h,z1+b);
glTexCoord2f(1.0, 1.0);glVertex3f(x1,y1-h,z1+b);
glTexCoord2f(1.0, 0.0);glVertex3f(x1,y1,z1+b);

 //left
  //glColor3f(0,1,1);
glTexCoord2f(0.0, 0.0);glVertex3f(x1,y1,z1+b);
glTexCoord2f(0.0, 1.0);glVertex3f(x1,y1-h,z1+b);
glTexCoord2f(1.0, 1.0);glVertex3f(x1,y1-h,z1);
glTexCoord2f(1.0, 0.0);glVertex3f(x1,y1,z1);

 /// top
  //glColor3f(1,1,0);
glTexCoord2f(0.0, 0.0);glVertex3f(x1,y1,z1);
glTexCoord2f(0.0, 1.0);glVertex3f(x1+w,y1,z1);
glTexCoord2f(1.0, 1.0);glVertex3f(x1+w,y1,z1+b);
glTexCoord2f(1.0, 0.0);glVertex3f(x1,y1,z1+b);

   ///bottom
    //glColor3f(1,1,0);
glTexCoord2f(0.0, 0.0); glVertex3f(x1,y1-h,z1);
glTexCoord2f(0.0, 1.0); glVertex3f(x1+w,y1-h,z1);
glTexCoord2f(1.0, 1.0); glVertex3f(x1+w,y1-h,z1+b);
glTexCoord2f(1.0, 0.0); glVertex3f(x1,y1-h,z1+b);

       glEnd();}

void kb2(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'a':
        glEnable(GL_LIGHT0);
        break;
    case 's':
        glEnable(GL_LIGHT0);
    }
}

void mouse1(int x, int y)
{
    x=400-x;
    y=300-y;
    mx=x;
    my=y;

    setup();
}

int main(int argc,char** argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("pendulam changing lenght and time period");
    setup();
    loadImages();
      createMenu();     glClearColor(1,1.0,0.0,0.0);
    glutDisplayFunc(display);
    glutSpecialFunc(kb);
    glutKeyboardFunc(kb2);
    glutIdleFunc(display);
    glutPassiveMotionFunc(mouse1);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glutMainLoop();
}
