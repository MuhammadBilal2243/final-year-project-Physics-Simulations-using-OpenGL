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
double ang=.01;
unsigned char* image;
GLuint texture[3];
int h,w;
float inc=0.2, pz=-1500;
void displaytext( char ch[],int px,int py ){

  glLoadIdentity();

   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glRasterPos2i(px, py);
    int i;
    for( i = 0; i<strlen(ch); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);

    }

}
void displaymarks( float num,int px,int py ){
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
void delay(int duration)
{
   int end=clock()+duration;
    while(clock()<=end);
}

void loadTextures()
{
    glGenTextures(3,texture);

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

}
void setup()
{
    GLfloat lightColor[] = {1,1,1,1};
    GLfloat lightPosition[] = {0,0,2050,1};

  glClearColor(151/255.0,217/255.0,234/255.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90,1.78,1,20000);
    //gluLookAt(100,800,pz,0,0,0,0,1,0);
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
int YC1=900;
int incre=10;
int incre1=10;
void display()
{

    setup();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[2]);

    glBegin(GL_QUADS);
        //Ground
        glTexCoord2f(0.0, 0.0); glVertex3f(-2800,0,-2000);
        glTexCoord2f(0.0, 10.0); glVertex3f(-2800,0,2000);
        glTexCoord2f(10.0, 10.0); glVertex3f(2800,0,2000);
        glTexCoord2f(10.0, 0.0); glVertex3f(2800,0,-2000);
    glEnd();
    glBindTexture(GL_TEXTURE_2D,texture[1]);
Draw3DBox(300,0,0,110,900,100);
Draw3DBox(275,900,50,50,300,50);
glBindTexture(GL_TEXTURE_2D,texture[1]);
       Draw3DBox(0,YC,0,50,50,50);
       glBindTexture(GL_TEXTURE_2D,texture[0]);
       Draw3DBox(-200,YC1,0,50,50,50);
    if(YC>100){
            incre+=9.8;
    YC-=incre;
delay(100);
}
    if(YC1>100){
            incre1+=2;
    YC1-=incre1;
delay(100);
}

displaymarks( 900,600,900);
displaymarks( 800,600,800);
displaymarks( 700,600,700);
displaymarks( 600,600,600);
displaymarks( 500,600,500);
displaymarks( 400,600,400);
displaymarks( 300,600,300);
displaymarks( 200,600,200);
displaymarks( 100,600,100);
displaymarks( 000,600,000);
displaytext( "IN the presense of air resistance  ",1800,900 );
displaytext( "the drag force act on the bodies",1800,800 );
displaytext( "both bodies cover the same area ",1800,700 );
displaytext( "but different masses ",1800,600 );
displaytext( "greater mass object or box",1800,500 );
displaytext( " will reach faster then smaler mass object ",1800,400 );


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
    glutCreateWindow("free fall motion in presence of air resistance");
    setup();
    loadTextures();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}

