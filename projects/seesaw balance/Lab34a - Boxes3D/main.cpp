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
#include <string>

using namespace std;
#define PI 3.1415926
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
int t1,t2,f1,f2,m1=10,m2=10,a=9.8,d1=400,d2=400;
double ang=.01;
unsigned char* image;
GLuint texture[4];
    float theta;
int angle_arr[360]={
180,181,182,183,184,185,186,187,188,189,
190,191,192,193,194,195,196,197,198,199,
300,301,302,303,304,305,306,307,308,309,
310,311,312,313,314,315,316,317,318,319,
320,321,322,323,324,325,326,327,328,329,
330,331,332,333,334,335,336,337,338,339,
340,341,342,343,344,345,346,347,348,349,
350,351,352,353,354,355,356,357,358,359,
360,
359,358,357,356,355,354,353,352,351,350,
349,348,347,346,345,344,343,342,341,340,
339,338,337,336335,334,333,332,331,330,
329,328,327,326,325,324,323,322,321,320,
319,318,317,316,315,314,313,312,311,310,
309,308,307,306,305,304,303,302,301,300,
199,198,197,196,195,194,193,192,191,190,
189,188,187,186,185,184,183,182,181,180,
};

int weight=0;
static int menu_id;
static int submenu_id;
static int submenu_id_m1;
static int submenu_id_m2;
static int submenu_id_d1;
static int submenu_id_d2;
static int value = 0;
void menu(int num){
  if(num == 0){
value = num;

  }else{
    value = num;
    weight=value;
  }
  glutPostRedisplay();
}

void weight_m1(int num){
  if(num == 0){
m1 = num;

  }else{

    m1 = num;

  }
  glutPostRedisplay();
}

void weight_m2(int num){
  if(num == 0){
m2 = num;

  }else{
    m2 = num;

  }
  glutPostRedisplay();
}
void dist_f_p_1(int num){
  if(num == 0){
d1 = num;

  }else{

  d1 = num;

  }
  glutPostRedisplay();
}
void dist_f_p_2(int num){
  if(num == 0){
d2 = num;

  }else{

  d2 = num;

  }
  glutPostRedisplay();
}

void createMenu(void){
             submenu_id_d1 = glutCreateMenu(dist_f_p_1);

    glutAddMenuEntry("800 meter", 800);
    glutAddMenuEntry("700 meter", 700);
    glutAddMenuEntry("600 meter", 600);
    glutAddMenuEntry("500 meter", 500);
        glutAddMenuEntry("400 meter", 400);
    glutAddMenuEntry("300 meter", 300);
    glutAddMenuEntry("200 meter", 200);
    glutAddMenuEntry("100 meter", 100);

    submenu_id_d2 = glutCreateMenu(dist_f_p_2);
 glutAddMenuEntry("800 meter", 800);
    glutAddMenuEntry("700 meter", 700);
    glutAddMenuEntry("600 meter", 600);
    glutAddMenuEntry("500 meter", 500);
 glutAddMenuEntry("400 meter", 400);
    glutAddMenuEntry("300 meter", 300);
    glutAddMenuEntry("200 meter", 200);
    glutAddMenuEntry("100 meter", 100);

    submenu_id_m1 = glutCreateMenu(weight_m1);

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
submenu_id_m2 = glutCreateMenu(weight_m2);

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
    glutAddSubMenu("weight_m1", submenu_id_m1);
    glutAddSubMenu("weight_m2", submenu_id_m2);
      glutAddSubMenu("distance_m1", submenu_id_d1);
    glutAddSubMenu("distance_m2", submenu_id_d2);
    glutAddMenuEntry("Quit", 0);     glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int h,w;
float inc=.2, pz=-1500;
int x=0; int y=500; int r=800; int startAngle=0; int endAngle=360;
float i=180;


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
        image = SOIL_load_image("E:/Textures/brick2.bmp",&w,&h,0,SOIL_LOAD_RGB);

    //Generate Texture
    glBindTexture(GL_TEXTURE_2D,texture[1]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    ///
            image = SOIL_load_image("E:/Textures/Wood1.bmp",&w,&h,0,SOIL_LOAD_RGB);

    //Generate Texture
    glBindTexture(GL_TEXTURE_2D,texture[2]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
     image = SOIL_load_image("E:/Textures/Ground1.bmp",&w,&h,0,SOIL_LOAD_RGB);

    //Generate Texture
    glBindTexture(GL_TEXTURE_2D,texture[3]);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,w,h,0,GL_RGB,GL_UNSIGNED_BYTE,image);
    SOIL_free_image_data(image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);

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
void DrawBox(int w,int h,int b,int q1,int q2)
{int z=0;
    glBegin(GL_QUADS);
        //Back Face
        theta = q1*3.142/180;
        glTexCoord2f(0.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)+h,z+b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)+h,z+b);
 theta = q2*3.142/180;
        glTexCoord2f(1.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)-h,z+b);
        //Left Face
        theta = q1*3.142/180;
        glTexCoord2f(0.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)-h,z-b);
        theta = q2*3.142/180;
        glTexCoord2f(1.0, 1.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)+h,z+b);
theta = q1*3.142/180;
        //Right Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)-h,z-b);
        theta = q2*3.142/180;
        glTexCoord2f(1.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)+h,z+b);
theta = q1*3.142/180;
        //Top Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)+h,z-b);
        theta = q2*3.142/180;
        glTexCoord2f(1.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)+h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)+h,z+b);
theta = q1*3.142/180;
        //Bottom Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)-h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)-h,z-b);
      theta = q2*3.142/180;
        glTexCoord2f(1.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)-h,z+b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)-h,z+b);
theta = q1*3.142/180;
        //Front Face
        glTexCoord2f(0.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)+h,z-b);
        glTexCoord2f(0.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)+h,z-b);
        theta = q2*3.142/180;
        glTexCoord2f(1.0, 1.0); glVertex3i(x+r*cos(theta)+w,y+r*sin(theta)-h,z-b);
        glTexCoord2f(1.0, 0.0); glVertex3i(x+r*cos(theta)-w,y+r*sin(theta)-h,z-b);

    glEnd();
    theta = q1*3.142/180;
     glBindTexture(GL_TEXTURE_2D,texture[2]);
    Draw3DBox(d1*cos(theta),y+d1*sin(theta),0,m1*10,m1*10,m1*10);
      theta = q2*3.142/180;
      glBindTexture(GL_TEXTURE_2D,texture[2]);
    Draw3DBox(d2*cos(theta),y+d2*sin(theta),0,m2*10,m2*10,m2*10);

    ///


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
    glBindTexture(GL_TEXTURE_2D,texture[3]);

    glBegin(GL_QUADS);
        //Ground
        glTexCoord2f(0.0, 0.0); glVertex3f(-2800,-101,-2000);
        glTexCoord2f(0.0, 10.0); glVertex3f(-2800,-101,2000);
        glTexCoord2f(10.0, 10.0); glVertex3f(2800,-101,2000);
        glTexCoord2f(10.0, 0.0); glVertex3f(2800,-101,-2000);
    glEnd();

    ///

f1=m1*a;
f2=m2*a;

t1=f1*d1;
t2=f2*d2;
if(t1-t2==0){
    DrawBox(10,10,10,0,180);

  }
  if(t1<t2){DrawBox(10,10,10,157+5,337+5);
   }
   if(t1>t2){DrawBox(10,10,10,203-5,23-5);
   }
   glBindTexture(GL_TEXTURE_2D,texture[0]);
       Draw3DBox(0,0,0,20,500,20);
       glBindTexture(GL_TEXTURE_2D,texture[0]);
    Draw3DBox(-1500,0,0,100,1200,100);


    if(YC>0){
            incre+=5;;
    YC-=incre;

}
   glBindTexture(GL_TEXTURE_2D,texture[1]);
  displaymarks( m1,1300,1200);
    displaytext( "Mass 1    =",1800,1200 );
    displaymarks( m2,1300,1150);
    displaytext( "Mass 2     =",1800,1150 );
    displaymarks( d1,1300,1100);
    displaytext( "Dist 1      =",1800,1100 );
    displaymarks( d2,1300,1050);
    displaytext( "Dist 2     =",1800,1050 );
    displaymarks( t1,1300,1000);
    displaytext( "Torgue1   =",1800,1000 );
    displaymarks( t2,1300,950);
    displaytext( "Torgue2  =",1800,950 );
     displaymarks( f1,1300,900);
    displaytext( "Force1   =",1800,900 );
    displaymarks( f2,1300,850);
    displaytext( "Force 2  =",1800,850 );
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
    glutCreateWindow("seesaw balance torque");
    setup();
    loadTextures();
     createMenu();     glClearColor(1.0,0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}

