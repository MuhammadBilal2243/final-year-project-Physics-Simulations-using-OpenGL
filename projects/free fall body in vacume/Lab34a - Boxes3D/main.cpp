#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <SOIL.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define PI 3.1415926
#include <string>
using namespace std;
unsigned char* image;
GLuint texture[4];
int h,w;
float inc=.2, pz=-1500;
void displaytext( char ch[],int px,int py ){



   glPixelStorei(GL_UNPACK_ALIGNMENT, 2);
    glRasterPos3i(px, py,-200);
    int i;
    for( i = 0; i<strlen(ch); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);

    }

}
void displaymarks( float num,int px,int py ){
int  abd=num;


string str= to_string(abd);

   char ch[str.size() + 1];
   strcpy(ch, str.c_str());
  glLoadIdentity();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 111);
    glRasterPos3i(px, py,10);
    int i;
    for( i = 0; i<strlen(ch); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);

    }

}
void delay(int duration)
{
   int end=clock()+duration;
    while(clock()<=end);
}

void loadTextures()
{
    glGenTextures(4,texture);

    image = SOIL_load_image("E:/Textures/Woodbox.bmp",&w,&h,0,SOIL_LOAD_RGB);

    //Generate Texture
    glBindTexture(GL_TEXTURE_2D,texture[0]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    ///
        image = SOIL_load_image("E:/Textures/Brick2.bmp",&w,&h,0,SOIL_LOAD_RGB);

    //Generate Texture
    glBindTexture(GL_TEXTURE_2D,texture[1]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);///
        image = SOIL_load_image("E:/Textures/Ground1.bmp",&w,&h,0,SOIL_LOAD_RGB);

    //Generate Texture
    glBindTexture(GL_TEXTURE_2D,texture[2]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    //


            image = SOIL_load_image("E:/Textures/Ceiling.bmp",&w,&h,0,SOIL_LOAD_RGB);

    //Generate Texture
    glBindTexture(GL_TEXTURE_2D,texture[3]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    //


}
void setup()
{
    GLfloat lightColor[] = {1,1,1,1};
    GLfloat lightPosition[] = {2050,2050,2050,1};

  glClearColor(151/255.0,217/255.0,234/255.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90,1.78,1,20000);

gluLookAt(100,300,-1500,0,0,0,0,1,0);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightColor);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPosition);

    glMatrixMode(GL_MODELVIEW);
}

void Draw3DBox(int x, int y, int z,int w,int h,int b)
{
    glBegin(GL_QUADS);
        //Back Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z+b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y+h,z+b);
        glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y-h,z+b);

        //Left Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x-w,y-h,z-b);
        glTexCoord2f(1.0, 1.0); glVertex3i(x-w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y+h,z+b);

        //Right Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x+w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y-h,z-b);
        glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+w,y+h,z+b);

        //Top Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y+h,z-b);
        glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y+h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y+h,z+b);

        //Bottom Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y-h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y-h,z-b);
        glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y-h,z+b);

        //Front Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x-w,y+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+w,y+h,z-b);
        glTexCoord2f(1.0, 1.0); glVertex3i(x+w,y-h,z-b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x-w,y-h,z-b);

    glEnd();
}
int YC=900;

int incre=10;

void display()
{

    setup();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[2]);

    glBegin(GL_QUADS);
        //Ground
        glTexCoord2f(0.0, 0.0); glVertex3f(-2800,-101,-2000);
        glTexCoord2f(0.0, 10.0); glVertex3f(-2800,-101,2000);
        glTexCoord2f(10.0, 10.0); glVertex3f(2800,-101,2000);
        glTexCoord2f(10.0, 0.0); glVertex3f(2800,-101,-2000);
    glEnd();

    glBegin(GL_QUADS);
        //Ground
        glTexCoord2f(0.0, 0.0); glVertex3f(-2800,1101,-2000);
        glTexCoord2f(0.0, 10.0); glVertex3f(-2800,1101,2000);
        glTexCoord2f(10.0, 10.0); glVertex3f(2800,1101,2000);
        glTexCoord2f(10.0, 0.0); glVertex3f(2800,1101,-2000);
    glEnd();    glBindTexture(GL_TEXTURE_2D,texture[1]);
 Draw3DBox(2000,0,0,110,1100,1100);
 glBindTexture(GL_TEXTURE_2D,texture[1]);
  Draw3DBox(2000,0,1000,5100,1100,100);
  glBindTexture(GL_TEXTURE_2D,texture[1]);
  Draw3DBox(-2000,0,0,100,1100,1100);

    glBindTexture(GL_TEXTURE_2D,texture[1]);
Draw3DBox(210,0,-210,110,100,100);
Draw3DBox(210,100,-210,110,100,100);
Draw3DBox(210,200,-210,110,100,100);
Draw3DBox(210,300,-210,110,100,100);
Draw3DBox(210,400,-210,110,100,100);
Draw3DBox(210,500,-210,110,100,100);
Draw3DBox(210,600,-210,110,100,100);
Draw3DBox(210,700,-210,110,100,100);


glBindTexture(GL_TEXTURE_2D,texture[1]);
       Draw3DBox(-200,YC,-100,50,50,50);
       glBindTexture(GL_TEXTURE_2D,texture[3]);
       Draw3DBox(-450,YC,-100,50,50,50);
    if(YC>0){
            incre+=9.8;
    YC-=incre;
delay(500);
}

glBindTexture(GL_TEXTURE_2D,texture[3]);
displaymarks(1000,100,900);displaytext( "free fall two bodies of different masses are compared in the absence of air resistance. free-falling objects are accelerating downwards at a rate of 9.8 m/s2   ", 1500,1000);
 displaytext( "Objects with higher mass and objects with smaller mass  will reach the ground at same time. ",1500,950 );

 displaytext( "The acceleration is constant and equal to the gravitational acceleration g which is 9.8 meters per square second at sea level on the Earth",1500,900 );

displaymarks( 500,100,400); displaytext( "bricks = 50kg",-100,850 );displaytext( "box =10kg",-500,850 );

displaymarks( 00,100,-100);
    glutSwapBuffers();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);

    pz+=inc;
    if(pz>=1500 || pz<=-1500)
        inc*=-1;
}

int main(int argc,char** argv)
{
  if(YC>0){
    YC--;



}
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(50,50);
    glutCreateWindow("OpenGL 3D");
    setup();
    loadTextures();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}

