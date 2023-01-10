#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <string>

using namespace std;







static int slices = 16;
static int stacks = 16;
float ss=0;
float aa=0;

float cloud_x = 0;
float cloud_y = 0;
float cloud_x2 = 0;
float cloud_y2 = 0;
int cloudstatus = 1;
float Step=0;
float Angle = 0.0;


GLfloat angle = 45.0f;
int refreshmill = 1;


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    Step+=0.025;      //animation
    
    Angle += 0.8;
    if(Angle>360.0){
        Angle = Angle - 360.0;  //rotation
    }
}

void timer2(int){
    glutPostRedisplay();
    glutTimerFunc(refreshmill, timer2 , 0);
}


void drawCircle( float cx , float cy, float r, int num_segments){
    glBegin(GL_POLYGON);
    for ( int i = 0; i<num_segments; i++){
        float theta = 2.0f * 3.14 * float(i) / float(num_segments);
        float x = r*cosf(theta);
        float y = r*sinf(theta);   //circles
        
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCloud(){
    //glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    drawCircle(1.2+Step, 8, 0.5, 500);
    drawCircle(1.5+Step, 8.5, 0.5, 500);//first cloud
    drawCircle(2+Step, 8, 0.5, 500);
    drawCircle(2+Step, 7.5, 0.5, 500);
    
    
    
    drawCircle(6.00+Step, 5.90, 0.75, 1000);
    drawCircle(6.30+Step, 6.00, 0.75, 1000);
    drawCircle(5.80+Step, 6.00, 0.75, 1000);//second cloud
    drawCircle(6.10+Step, 6.20, 0.75, 1000);
    
    
}



static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    
    glLoadIdentity();
    
    drawCloud();
    


//sky
    glPushMatrix();
    glTranslated(2,1,-10);
    glRotated(180,0,1,0);
    glScaled(15,15,3);
    glColor3ub(31, 41, 100);
    glutSolidSphere(1,slices,stacks);
    glPopMatrix();



//land

    glPushMatrix();
      glTranslated(2,-2.5,-10);
      glRotated(180,0,1,0);
     glScaled(15,10,3);
     glColor3ub(172, 209, 224);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();
glPushMatrix();
glTranslated(aa,0,ss);
    
    
    
    mmmlkkk
   

    
    

//cloth
 glPushMatrix();
     glTranslated(0,-1.6,-6);
     glRotated(-90,0.1,0,0);
     glColor3ub(255, 95, 0);
     glScaled(1,1,1);
     glutSolidCone(1,2,slices,stacks);
     glPopMatrix();

//3black

  glPushMatrix();

glTranslated(0,-.5,-4);
     glRotated(90,1,0,0);
     glScaled(.1,.1,.1);
     glColor3f(0,0,0);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();

       glPushMatrix();

   glTranslated(0,-.8,-4);
     glRotated(90,1,0,0);
     glScaled(.1,.1,.1);
     glColor3f(0,0,0);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();

       glPushMatrix();

glTranslated(0,-1.1,-4);
     glRotated(90,1,0,0);
     glScaled(.1,.1,.1);
     glColor3f(0,0,0);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();

     //second

glPushMatrix();
     glTranslated(0,-.35,-5.7);
     glRotated(-90,0.1,0,0);
     glColor3ub(0, 234, 0);
     glScaled(1,1,1);
     glutSolidCone(1,2,slices,stacks);
     glPopMatrix();
    
    
    
    
    
    //cone above his head
    glPushMatrix ();
    glTranslatef(0,1.3,-4.5);
    glColor3f(1.0, 0.0, 0.0);
    glRotatef(-90.0, 1,0,0);
    //glRotatef(zRotated, 0,0,1);
    glScalef(1.0,1.0,1.0);
    glutSolidCone(0.29,0.7,20,20);//draw cone
    glPopMatrix ();//pops the coordinates to a matrix to make the object appear
    //face

     glPushMatrix();
     glTranslated(0,.8,-5.8);
     glRotated(90,1,0,0);
     glScaled(1.,1.,1);
     glColor3ub(244, 224, 190);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();

    //left leg

     glPushMatrix();

glTranslated(-.74,-2.2,-6);

     glRotated(90,1,0,0);
     glScaled(.5,.5,.5);
     glColor3ub(128, 128, 128);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();


 glPushMatrix();
glTranslated(-.74,-2.8,-6.1);
     glRotated(-90,0.1,0,0);
     glColor3ub(0,0,0);
     glScaled(.5,.5,.5);
     glutSolidCone(1,2,slices,stacks);
     glPopMatrix();

//right leg
     glPushMatrix();

glTranslated(.74,-2.2,-6);
     glRotated(90,1,0,0);
     glScaled(.5,.5,.5);
     glColor3ub(128, 128, 128);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();

glPushMatrix();
glTranslated(.74,-2.8,-6.1);
     glRotated(-90,0.1,0,0);
     glColor3ub(0,0,0);
     glScaled(.5,.5,.5);
     glutSolidCone(1,2,slices,stacks);
     glPopMatrix();


     //hand

          glPushMatrix();
     glTranslated(1,-.55,-6);
       glRotated(60,0,1,0);
     glScaled(1.3,.2,.5);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();

 glPushMatrix();
     glTranslated(-1,-.55,-6);
       glRotated(-60,0,1,0);
     glScaled(1.3,.2,.5);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();


     //mouse
     glPushMatrix();
     glTranslated(0,.3,-3);
       glRotated(180,0,.5,-1);
     glScaled(.2,-.2,.2);
     glutSolidCone(1,2,slices,stacks);
     glPopMatrix();

     //white
        glPushMatrix();
     glTranslated(0,0.1,-3);
       glRotated(-180,0,.5,-1);
       glColor3f(1,1,1);
     glScaled(.1,.1,.1);
     glutSolidCube(.3);
     glPopMatrix();

      glPushMatrix();
     glTranslated(-.04,0.1,-3);
       glRotated(-180,0,.5,-1);
       glColor3f(1,1,1);
     glScaled(.1,.1,.1);
     glutSolidCube(.3);
     glPopMatrix();

 glPushMatrix();
     glTranslated(.04,0.1,-3);
       glRotated(-180,0,.5,-1);
       glColor3f(1,1,1);
     glScaled(.1,.1,.1);
     glutSolidCube(.3);
     glPopMatrix();

//eye
//right
       glPushMatrix();

glTranslated(.32,.73,-4);
     glRotated(90,1,0,0);
     glScaled(.05,.05,.05);
     glColor3f(0,0,0);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();
//white
      glPushMatrix();

glTranslated(.35,.8,-4.3);
     glRotated(90,0,1,0);
     glScaled(.1,.15,.1);
     glColor3f(1,1,1);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();


     //left
       glPushMatrix();

glTranslated(-.32,.73,-4);
     glRotated(90,1,0,0);
     glScaled(.05,.05,.05);
     glColor3f(0,0,0);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();

//white
  glPushMatrix();

glTranslated(-.35,.8,-4.3);
     glRotated(90,0,1,0);
     glScaled(.1,.15,.1);
     glColor3f(1,1,1);
     glutSolidSphere(1,slices,stacks);
     glPopMatrix();



     //upeye
     //left

        glPushMatrix();
     glTranslated(-.4,1.1,-4.3);
       glRotated(120,1,0,1);
     glScaled(.025,.1,.1);
     glColor3f(0,0,0);
     glutSolidCone(1,2,slices,stacks);
     glPopMatrix();

     //right

          glPushMatrix();
     glTranslated(.35,1.1,-4.3);
       glRotated(120,1,0,1);
     glScaled(.025,.1,.1);
     glColor3f(0,0,0);
     glutSolidCone(1,2,slices,stacks);
     glPopMatrix();

     glPopMatrix();
    
    
    
    int zRotated = 45;
    // the first lower cone of the tree
                glPushMatrix ();//push the coordinates to a matrix to make the object appear
                glTranslatef(2,-1.0,-4.5);//set  position
                glColor3f(0.0, 1.0, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                // the second lower cone of the tree
                glPushMatrix ();//push the coordinates to a matrix to make the object appear
                glTranslatef(2,-0.62,-4.5);//set  position
                glColor3f(0.0, 1.0, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                // the third lower cone of the tree
                glPushMatrix ();//push the coordinates to a matrix to make the object appear
                glTranslatef(2,-0.25,-4.5);//set  position
                glColor3f(0.0, 1.0, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                // the upper cone of the tree
                glPushMatrix ();//push the coordinates to a matrix to make the object appear
                glTranslatef(2,0.1,-4.5);//set  position
                glColor3f(0.0, 1.0, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                //star
                glPushMatrix(); //push the coordinates to a matrix to make the object appear
                glTranslatef(2,0.9,-4.5);//set  position
                glRotatef(360, 0,1,0);//used for rotation
                
                glColor3f(1.0, 1.0, 0.0);//set color of star
                glScalef(0.2,0.2,0.2);//set its scale
                glutSolidIcosahedron();//draw star on tree
                glPopMatrix ();//pops the coordinates to a matrix to make the object appear
    
    glutSwapBuffers();
    
}

// keyboard inputs
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

        case 'w':
            ss-=0.1;
            break;
        case 's':
            ss+=0.1;
            break;

        case 'd':
            aa+=0.1;
             break;

        case 'a':
            aa-=0.1;
             break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };





void init(){
    glClearColor(0.12, 0.63, 0.82, 1.0);
}




int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(200,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("20101209");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutTimerFunc(0,timer,0);
    //system(command.c_str());
    
    
    init();

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    
    //PlaySound("/Users/zeyadhassan/Desktop/Hamoud Habibi [HD 60FPS].mp3", NULL, SND_FILENAME|SND_LOOP);
    
    glutMainLoop();

    return EXIT_SUCCESS;
}
















/*const int steps = 100;
const float angle = 3.1415926*2.f / steps;

float x,y,i;
float PI = 3.1416;

static int slices = 16;
static int stacks = 16;
float ss=0;
float aa=0;


float cloud_x = 0;
float cloud_y = 0;
float cloud_x2 = 0;
float cloud_y2 = 0;
int cloudstatus = 1;
float Step=0;
float Angle = 0.0;

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    Step+=0.025;      //animation
    
    Angle += 0.8;
    if(Angle>360.0){
        Angle = Angle - 360.0;  //rotation
    }
    
}


void drawCircle( float cx , float cy, float r, int num_segments){
    glBegin(GL_POLYGON);
    for ( int i = 0; i<num_segments; i++){
        float theta = 2.0f * 3.14 * float(i) / float(num_segments);
        float x = r*cosf(theta);
        float y = r*sinf(theta);   //circles
        
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void drawMoon(){
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    drawCircle(-6.7, 8, 1.5, 100);  //Moon
    
    glRotatef(Angle, 1.0, 1.0, 1.0);  //rotation of the moon
    
    glPopMatrix();
}


void drawCloud(){
    //glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    drawCircle(1.2+Step, 8, 0.5, 500);
    drawCircle(1.5+Step, 8.5, 0.5, 500);//first cloud
    drawCircle(2+Step, 8, 0.5, 500);
    drawCircle(2+Step, 7.5, 0.5, 500);
    
    
    
    drawCircle(6.00+Step, 5.90, 0.75, 1000);
    drawCircle(6.30+Step, 6.00, 0.75, 1000);
    drawCircle(5.80+Step, 6.00, 0.75, 1000);//second cloud
    drawCircle(6.10+Step, 6.20, 0.75, 1000);
    
}


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    
    
    
    
    
    
    glLineWidth(0.5);
    
    
    //sky
        glPushMatrix();
        glTranslated(2,1,-10);
        glRotated(180,0,1,0);
        glScaled(15,15,3);
        glColor3ub(31, 41, 100);
        glutSolidSphere(1,slices,stacks);
        glPopMatrix();
         
         
         
         

    //land

        glPushMatrix();
          glTranslated(2,-2.5,-10);
          glRotated(180,0,1,0);
         glScaled(15,10,3);
         glColor3ub(172, 209, 224);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();
    glPushMatrix();
    glTranslated(aa,0,ss);
    
    
    
    

    //cloth
     glPushMatrix();
         glTranslated(0,-1.6,-6);
         glRotated(-90,0.1,0,0);
         glColor3ub(255, 95, 0);
         glScaled(1,1,1);
         glutSolidCone(1,2,slices,stacks);
         glPopMatrix();

    //3black

      glPushMatrix();

    glTranslated(0,-.5,-4);
         glRotated(90,1,0,0);
         glScaled(.1,.1,.1);
         glColor3f(0,0,0);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();

           glPushMatrix();

       glTranslated(0,-.8,-4);
         glRotated(90,1,0,0);
         glScaled(.1,.1,.1);
         glColor3f(0,0,0);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();

           glPushMatrix();

    glTranslated(0,-1.1,-4);
         glRotated(90,1,0,0);
         glScaled(.1,.1,.1);
         glColor3f(0,0,0);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();

         //second

    glPushMatrix();
         glTranslated(0,-.35,-5.7);
         glRotated(-90,0.1,0,0);
         glColor3ub(0, 234, 0);
         glScaled(1,1,1);
         glutSolidCone(1,2,slices,stacks);
         glPopMatrix();
        
        
        
        
        
        //cone above his head
        glPushMatrix ();
        glTranslatef(0,1.3,-4.5);
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(-90.0, 1,0,0);
        //glRotatef(zRotated, 0,0,1);
        glScalef(1.0,1.0,1.0);
        glutSolidCone(0.29,0.7,20,20);//draw cone
        glPopMatrix ();//pops the coordinates to a matrix to make the object appear
        //face

         glPushMatrix();
         glTranslated(0,.8,-5.8);
         glRotated(90,1,0,0);
         glScaled(1.,1.,1);
         glColor3ub(244, 224, 190);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();

        //left leg

         glPushMatrix();

    glTranslated(-.74,-2.2,-6);

         glRotated(90,1,0,0);
         glScaled(.5,.5,.5);
         glColor3ub(128, 128, 128);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();


     glPushMatrix();
    glTranslated(-.74,-2.8,-6.1);
         glRotated(-90,0.1,0,0);
         glColor3ub(0,0,0);
         glScaled(.5,.5,.5);
         glutSolidCone(1,2,slices,stacks);
         glPopMatrix();

    //right leg
         glPushMatrix();

    glTranslated(.74,-2.2,-6);
         glRotated(90,1,0,0);
         glScaled(.5,.5,.5);
         glColor3ub(128, 128, 128);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();

    glPushMatrix();
    glTranslated(.74,-2.8,-6.1);
         glRotated(-90,0.1,0,0);
         glColor3ub(0,0,0);
         glScaled(.5,.5,.5);
         glutSolidCone(1,2,slices,stacks);
         glPopMatrix();


         //hand

              glPushMatrix();
         glTranslated(1,-.55,-6);
           glRotated(60,0,1,0);
         glScaled(1.3,.2,.5);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();

     glPushMatrix();
         glTranslated(-1,-.55,-6);
           glRotated(-60,0,1,0);
         glScaled(1.3,.2,.5);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();


         //mouse
         glPushMatrix();
         glTranslated(0,.3,-3);
           glRotated(180,0,.5,-1);
         glScaled(.2,-.2,.2);
         glutSolidCone(1,2,slices,stacks);
         glPopMatrix();

         //white
            glPushMatrix();
         glTranslated(0,0.1,-3);
           glRotated(-180,0,.5,-1);
           glColor3f(1,1,1);
         glScaled(.1,.1,.1);
         glutSolidCube(.3);
         glPopMatrix();

          glPushMatrix();
         glTranslated(-.04,0.1,-3);
           glRotated(-180,0,.5,-1);
           glColor3f(1,1,1);
         glScaled(.1,.1,.1);
         glutSolidCube(.3);
         glPopMatrix();

     glPushMatrix();
         glTranslated(.04,0.1,-3);
           glRotated(-180,0,.5,-1);
           glColor3f(1,1,1);
         glScaled(.1,.1,.1);
         glutSolidCube(.3);
         glPopMatrix();

    //eye
    //right
           glPushMatrix();

    glTranslated(.32,.73,-4);
         glRotated(90,1,0,0);
         glScaled(.05,.05,.05);
         glColor3f(0,0,0);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();
    //white
          glPushMatrix();

    glTranslated(.35,.8,-4.3);
         glRotated(90,0,1,0);
         glScaled(.1,.15,.1);
         glColor3f(1,1,1);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();


         //left
           glPushMatrix();

    glTranslated(-.32,.73,-4);
         glRotated(90,1,0,0);
         glScaled(.05,.05,.05);
         glColor3f(0,0,0);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();

    //white
      glPushMatrix();

    glTranslated(-.35,.8,-4.3);
         glRotated(90,0,1,0);
         glScaled(.1,.15,.1);
         glColor3f(1,1,1);
         glutSolidSphere(1,slices,stacks);
         glPopMatrix();



         //upeye
         //left

            glPushMatrix();
         glTranslated(-.4,1.1,-4.3);
           glRotated(120,1,0,1);
         glScaled(.025,.1,.1);
         glColor3f(0,0,0);
         glutSolidCone(1,2,slices,stacks);
         glPopMatrix();

         //right

              glPushMatrix();
         glTranslated(.35,1.1,-4.3);
           glRotated(120,1,0,1);
         glScaled(.025,.1,.1);
         glColor3f(0,0,0);
         glutSolidCone(1,2,slices,stacks);
         glPopMatrix();

         glPopMatrix();
        
        
        
        int zRotated = 45;
        // the first lower cone of the tree
                    glPushMatrix ();//push the coordinates to a matrix to make the object appear
                    glTranslatef(2,-1.0,-4.5);//set  position
                    glColor3f(0.0, 1.0, 0.0);
                    glRotatef(-90.0, 1,0,0);
                    glRotatef(zRotated,0,0,1);
                    glScalef(1.0,1.0,1.0);
                    glutSolidCone(0.555,0.9,20,20);//draw cone
                    glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                    // the second lower cone of the tree
                    glPushMatrix ();//push the coordinates to a matrix to make the object appear
                    glTranslatef(2,-0.62,-4.5);//set  position
                    glColor3f(0.0, 1.0, 0.0);
                    glRotatef(-90.0, 1,0,0);
                    glRotatef(zRotated, 0,0,1);
                    glScalef(1.0,1.0,1.0);
                    glutSolidCone(0.45,0.9,20,20);//draw cone
                    glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                    // the third lower cone of the tree
                    glPushMatrix ();//push the coordinates to a matrix to make the object appear
                    glTranslatef(2,-0.25,-4.5);//set  position
                    glColor3f(0.0, 1.0, 0.0);
                    glRotatef(-90.0, 1,0,0);
                    glRotatef(zRotated, 0,0,1);
                    glScalef(1.0,1.0,1.0);
                    glutSolidCone(0.35,0.9,20,20);//draw cone
                    glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                    // the upper cone of the tree
                    glPushMatrix ();//push the coordinates to a matrix to make the object appear
                    glTranslatef(2,0.1,-4.5);//set  position
                    glColor3f(0.0, 1.0, 0.0);
                    glRotatef(-90.0, 1,0,0);
                    glRotatef(zRotated, 0,0,1);
                    glScalef(1.0,1.0,1.0);
                    glutSolidCone(0.29,0.7,20,20);//draw cone
                    glPopMatrix ();//pops the coordinates to a matrix to make the object appear

                    //star
                    glPushMatrix(); //push the coordinates to a matrix to make the object appear
                    glTranslatef(2,0.9,-4.5);//set  position
                    glRotatef(90, 1,1,1);//used for rotation
                    
                    glColor3f(1.0, 1.0, 0.0);//set color of star
                    glScalef(0.2,0.2,0.2);//set its scale
                    glutSolidIcosahedron();//draw star on tree
                    glPopMatrix ();//pops the coordinates to a matrix to make the object appear
        
        
    
    
    
    
    glutSwapBuffers();
    
}


// keyboard inputs
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

        case 'w':
            ss-=0.1;
            break;
        case 's':
            ss+=0.1;
            break;

        case 'd':
            aa+=0.1;
             break;

        case 'a':
            aa-=0.1;
             break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void reshape(int w,int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    
}




int main(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    
    glutInitWindowPosition(200,0 );
    glutInitWindowSize(1200, 800);
    
    glutCreateWindow("20101209");
    
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);

    
    glutReshapeFunc(resize);
    
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    
    //PlaySound("/Users/zeyadhassan/Desktop/Hamoud Habibi [HD 60FPS].mp3", NULL, SND_FILENAME|SND_LOOP);
    
    glutMainLoop();

    return EXIT_SUCCESS;
}

*/






