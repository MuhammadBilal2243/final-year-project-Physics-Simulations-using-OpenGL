#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <windows.h>
#include <math.h>
#include<GL/glext.h>
#include "SOIL.h"

#include <string>
using namespace std;
#define PI 3.1415926

int weight=0;
static int menu_id;
static int submenu_id;
static int value = 0;
void menu(int num){

    value = num;
    weight=value;

  glutPostRedisplay();
}
void createMenu(void){     submenu_id = glutCreateMenu(menu);

     glutAddMenuEntry("1 kg", 1);
    glutAddMenuEntry("2 kg", 2);
    glutAddMenuEntry("3 kg", 3);
    glutAddMenuEntry("4 kg", 4);
    glutAddMenuEntry("5 kg", 5);
    glutAddMenuEntry("6 kg", 6);
    glutAddMenuEntry("7 kg", 7);
    glutAddMenuEntry("8 kg", 8);
    glutAddMenuEntry("9 kg", 9);
    glutAddMenuEntry("10 kg", 10);
      menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("weight less", 0);
    glutAddSubMenu("weight", submenu_id);
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}



GLfloat pz=-1000,px=0,py=100;
unsigned char* image;
int width, height;
GLuint textures[6];
GLint mx,my;



    //delay(20);


void  verticle_spring (int x,int y,float radius,float limit,int w)
{float comp;
    float tx,ty,tz=-90;
    float i;
    float a=radius;

    switch(w){
    case 0:
      comp=0.13;
      break;
      case 1:
      comp=0.12;
      break;
    case 2:
        comp=0.095;
    break;
    case 3:comp=0.090;
    break;
    case 4:comp=0.085;
    break;
    case 5:comp=0.080;
    break;
    case 6:comp=0.075;
    break;
    case 7:comp=0.070;
    break;
    case 8:comp=0.065;
    break;
    case 9:comp=0.060;
    break;
    case 10:comp=0.055;
    break;
    case 11:comp=0.050;
    break;
    case 12:comp=0.045;
    break;
    case 13:comp=0.043;
    break;
    case 14:comp=0.040;
    break;
    case 15:comp=0.038;
    break;
    case 16:comp=0.035;
    break;
    case 17:comp=0.030;
    break;
    case 18:comp=0.028;
    break;
    case 19:comp=0.025;
    break;


    }
    glPointSize(3);
    glBegin(GL_POINTS);
    for (i = 0; i < limit; i=i+.05)
    {
        tz=tz+comp;


        tx=x+a*cos(i);
        ty=y+a*sin(i);

        glVertex3f(tx,tz,ty);
    }
    glEnd();
    int yy=tz,xx=tx;
    if(weight>0){
     glBindTexture(GL_TEXTURE_2D,textures[0]);
Draw3DBox(xx,yy+12*w,0,w*12,w*12,w*12);
    }





    //delay(20);
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
    gluLookAt(px,py,pz,  mx,my,pz+500,   0,1,0);

    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,w);
    glLightfv(GL_LIGHT0,GL_POSITION,p);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,w);
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
   glBindTexture(GL_TEXTURE_2D,textures[0]);
   //Draw3DBox(500,50,150,500,500,10);


glBindTexture(GL_TEXTURE_2D,textures[3]);
 verticle_spring(-300,50,30,200,weight);
 glBindTexture(GL_TEXTURE_2D,textures[2]);
 verticle_spring(-100,50,30,200,0);

glBindTexture(GL_TEXTURE_2D,textures[3]);

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

void Draw3DBox(int x, int y, int z,int w,int h,int b)
{
    glBegin(GL_QUADS);


        //Front Face
        glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z-b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y-h,z-b);
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y+h,z-b);

        //Bottom Face
          glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y-h,z+b);
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y-h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y-h,z-b);


           //Top Face
          glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y+h,z+b);

        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y+h,z+b);
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y+h,z-b);

      //Right Face
      glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+w,y+h,z+b);
        glTexCoord2f(0.0, 0.0); glVertex3i(x+w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y-h,z-b);


        //Left Face
         glTexCoord2f(1.0, 1.0); glVertex3i(x-w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y+h,z+b);
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x-w,y-h,z-b);

            //Back Face
            glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y-h,z+b);
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z+b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y+h,z+b);



    glEnd();
}

void kb2(unsigned char key, int x, int y)
{

    switch(key)
    {
    case 'a':
        glDisable(GL_LIGHT0);
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


int  main(int argc,char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(50,50);
    glutCreateWindow("OpenGL Texturing and Lighting");
    setup();
    loadImages();
    createMenu();     glClearColor(1.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutSpecialFunc(kb);
    glutKeyboardFunc(kb2);
    glutIdleFunc(display);
    glutPassiveMotionFunc(mouse1);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glutMainLoop();
}
