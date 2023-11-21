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
#include <time.h>
#include <string>
#define PI 3.1415926
using namespace std;
double ang=.01;
int flagg=1;
unsigned char* image;
GLuint texture[4];


int h,w;
float inc=.2, pz=-1500;
int x=0; int y=1000; int r=700; int startAngle=190; int endAngle=350;
float i=190;
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
int  abd=num;


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
    GLfloat lightPosition[] = {0,0,2050,1};

  glClearColor(151/255.0,217/255.0,234/255.0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90,1.78,1,20000);
    gluLookAt(100,100,pz,0,0,0,0,1,0);

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
int z=0;
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
        glTexCoord2f(0.0, 0.0); glVertex3f(-2800,01,-2000);
        glTexCoord2f(0.0, 10.0); glVertex3f(-2800,01,2000);
        glTexCoord2f(10.0, 10.0); glVertex3f(2800,01,2000);
        glTexCoord2f(10.0, 0.0); glVertex3f(2800,01,-2000);
    glEnd();

 glBindTexture(GL_TEXTURE_2D,texture[0]);
if(i==startAngle){flagg=1;}
if(i==endAngle){flagg=-1;}
i+=flagg;
   ///
    float theta;
    z++;
 //  i=angle_arr[z]

                glBegin(GL_POINTS);
            theta = i*3.142/180; /**< Convert angle to radian */
            glVertex3i(x+r*cos(theta), y+r*sin(theta),0);
            glEnd();
    ///
    delay(10);

    glPointSize(22);
    glBegin(GL_LINES);
    glVertex2i(0,1200);
    glVertex2i(x+r*cos(theta), y+r*sin(theta));
    glEnd();
     glBindTexture(GL_TEXTURE_2D,texture[0]);
 Draw3DBox(0,1200,0,30,30,30);
    // Draw3DBox(x+r*cos(theta), y+r*sin(theta)*2,0,50,50,50);
   //
   if(r*cos(theta)>0){
    displaymarks( r*cos(theta),1100,r*cos(theta)+100); displaytext("P.E",1200,r*cos(theta)+100);}
     if(r*cos(theta)<0){
    displaymarks( -1*(r*cos(theta)),1100,-1*(r*cos(theta))+100);}displaytext("P.E",1200,-1*(r*cos(theta))+100);
    Draw3DBox(1100,0,0,100,r*cos(theta),100);
    displaymarks( -r*sin(theta),1400,-r*sin(theta)+100);displaytext("K.E",1500,-r*sin(theta)+100);
    Draw3DBox(1300,0,0,100,r*sin(theta),100);
displaymarks( 700,1600,700);
displaymarks( 600,1600,600);
displaymarks( 500,1600,500);
displaymarks( 400,1600,400);
displaymarks( 300,1600,300);
displaymarks( 200,1600,200);
displaymarks( 100,1600,100);
displaymarks( 000,1600,000);
//
//
 //
   //
//
 //
displaytext("In a simple pendulum with no friction, mechanical",2100,1210);
displaytext("energy is conserved.  Total mechanical energy is",2100,1160);
displaytext(" a combination of kinetic energy and gravitational potential energy.",2100,1110);
displaytext("As the pendulum swings back and forth, there is a",2100,1060);
displaytext("constant exchange between kinetic energy",2100,1010);
displaytext("and gravitational potential energy.",2100,960);
///
displaytext("K.E is MINIMUM at extreme position",-450,1100);
             displaytext("and maximum at maen position",-450,1000);
displaytext("P.E is Maximum at extreme position",-450,900);
            displaytext(" and minimum at maen position",-450,800);

displaymarks( 600,600,1250);

displaymarks( 400,400,1250);

displaymarks( 200,200,1250);

displaymarks( 000,000,1250);

displaymarks( -600,-600,1250);

displaymarks( -400,-400,1250);

displaymarks( -200,-200,1250);

displaymarks( -000,-000,1250);


    if(YC>0){
            incre+=0.5;;
    YC-=incre;

}
    glutSwapBuffers();
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);


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
    glutCreateWindow("3D K.E and P.E pendulum semulation ");
    setup();
    loadTextures();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}

