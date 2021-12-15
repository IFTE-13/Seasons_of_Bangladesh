#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
# define PI 3.1415926535897932384

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

/// Variables

int triangleAmount;
float _translate_Train,_translate_Plane = 4.0f, _translate_car, _translate_Bird, _translate_Rain = 2.0f, b_red, b_green, b_blue, x, y, radius, twicePi, i = 0.0f, _translate = 0.0f;
bool plane, rain, spring, winter, train, night, bird = true, sound;

/// Object functions
void _car(){

    /// Body
    glBegin(GL_QUADS);
    glColor3ub(36,70,240);
    glVertex2f(-0.24f,-0.18f);
    glVertex2f(0.255f, -0.18f);
    glVertex2f(0.255f, -0.1f);
    glVertex2f(-0.24f, -0.1f);
    glEnd();

    /// Head light
    if(rain)
    {
        glPushMatrix();
        glTranslatef(-0.35, -0.23, 0.0);
        glBegin(GL_TRIANGLES);
        glColor3ub(255,255,255);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.1, 0.1);
        glVertex2f(0.0, 0.2);
        glEnd();
        glPopMatrix();
    }


    /// Roof ///
    glBegin(GL_QUADS);
    glColor3ub(250, 209,5);
    glVertex2f(-0.16f,-0.1f);
    glVertex2f(0.18f, -0.1f);
    glVertex2f(0.13f, -0.0165f);
    glVertex2f(-0.1f, -0.0165f);
    glEnd();


    /// Blue Inside Glass ///
    glBegin(GL_QUADS);
    glColor3ub(0,0,0); /// black color
    glVertex2f(-0.13f,-0.1f);    /// x, y
    glVertex2f(0.15f, -0.1f);
    glVertex2f(0.10f, -0.03f);
    glVertex2f(-0.07f, -0.03f);
    glEnd();


    /// Right Wheel
	 x=0.14;  y=-0.18f; radius =0.060f;

	 twicePi = 2.0f * PI;
    glColor3ub(26, 22, 22);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <=20;i++)
            {
			glVertex2f
			(
                x + (radius * cos(i *  twicePi / 20)),
			    y + (radius * sin(i * twicePi / 20))
			);
		}
	glEnd();


	/// Left Wheel
	 x=-0.14;  y=-0.18f; radius =0.060f;

	 twicePi = 2.0f * PI;
    glColor3ub(26, 22, 22);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <=20;i++)
            {
			glVertex2f
			(
                x + (radius * cos(i *  twicePi / 20)),
			    y + (radius * sin(i * twicePi / 20))
			);
		}
	glEnd();

	glPopMatrix();
    glPopMatrix();
}

void _train()
{
    ///=============================================== Train boggy 1=====================================
    glPushMatrix();
    glTranslated(3,0.0, -0.5);
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix();//Train BOX
   glColor3ub(102,205,0);
   glScaled(2,1,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //Train Connection Boxes
   glColor3f(0,0,0);
   glTranslated(-1,-0.35,0);
   glScaled(1,0.09,0.09);
   glutSolidCube(1);
   glPopMatrix();
     glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
    glPopMatrix();

///===========================================================  Train boggy 2 =======================================

    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-2.5,0,0);
    glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix();//Train BOX
   glColor3ub(139,139,122);
   glScaled(2,1,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //Train Connection Boxes
   glColor3f(0,0,0);
   glTranslated(-1,-0.35,0);
   glScaled(1,0.09,0.09);
   glutSolidCube(1);
   glPopMatrix();
     glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
    glPopMatrix();


///==================================================== Train boggy 3 ===================================================

glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-5.0,0,0);
    glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix();//Train BOX
   glColor3ub(255,106,106);
   glScaled(2,1,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //Train Connection Boxes
   glColor3f(0,0,0);
   glTranslated(-1,-0.35,0);
   glScaled(1,0.09,0.09);
   glutSolidCube(1);
   glPopMatrix();
     glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
    glPopMatrix();

///============================================================= Train boggy 4 =====================================


glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-7.5,0,0);
    glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix();//Train BOX
   glColor3ub(255,0,0);
   glScaled(2,1,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();
   glPushMatrix(); //Train Connection Boxes
   glColor3f(0,0,0);
   glTranslated(-1,-0.35,0);
   glScaled(1,0.09,0.09);
   glutSolidCube(1);
   glPopMatrix();
     glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
    glPopMatrix();


///==============================================================End of train boggy 3====================================

glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(-10.0,0,0);
    glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, -0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix();//Train BOX
   glColor3ub(255,0,255);
   glScaled(2,1,1);
   glutSolidCube(1);
   glColor3f(0,0,0);
   glutWireCube(1);
   glPopMatrix();

  glPushMatrix(); //Train Connection Boxes
   glColor3f(0,0,0);
   glTranslated(-1,-0.35,0);
   glScaled(1,0.09,0.09);
   glutSolidCube(1);
   glPopMatrix();

     glPushMatrix(); //Right Wheel Far
   glColor3f(1,1,1);
   glTranslated(0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
   glPushMatrix(); //Left Wheel Far
   glColor3f(1,1,1);
   glTranslated(-0.75,-0.5, 0.5);
   glRotated(30,0,0,1);
   glutSolidTorus (0.1,0.2,10,10);
   glPopMatrix();
    glPopMatrix();
///*********************************************************** Engine Up ************************************************
glPushMatrix();
   glScalef(0.5,0.5,0.5);
   glTranslatef(0.0,0.50,0.0);
    glPushMatrix();
    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.5,1.0,0.0);
    glVertex3f(0.0,1.0,0.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    glTranslatef(0.5,0.0,0.0);
    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.5,0.0,0.0);
    glVertex3f(1.5,1.0,0.0);
    glVertex3f(0.0,1.0,0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();


///============================================================= End of train ============================================
     glPopMatrix();

}

void _rain()
{
    glPushMatrix();

    for (float i =-8.0f; i < 100; i++){
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0f,(0.0f + (i*0.3)),0.0f);
    glVertex3f(0.0f,(0.15f + (i*0.3)),0.0f);
    glEnd();
    glPopMatrix();
    }
    glPopMatrix();

}

void _tree()
{
    glPushMatrix();
    if(spring){glColor3ub(255,140,0);}
    else if(rain){glColor3ub(0,100,0);}
    else if(winter){glColor3ub(107,142,35);}
    else {glColor3ub(34,139,34);}

    glPushMatrix();
	glTranslatef(0.35f, 0.7f,0.0);
	glutSolidSphere(.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.1f, 0.7f,0.0);
	glutSolidSphere(.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.15f, 0.7f,0.0);
	glutSolidSphere(.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.0f,0.9f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.2f, 0.9f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.09f, 1.1f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(139,70,0);
    glVertex3f(0.05, 0.0, 0.0);
    glVertex3f(0.15, 0.0, 0.0);
    glVertex3f(0.15, 0.7, 0.0);
    glVertex3f(0.05, 0.7, 0.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

void _cloud()
{
    glPushMatrix();
    if(!rain){glColor3ub(255,255,255);}
    else{glColor3ub(140,140,140);}
    glPushMatrix();
	glTranslatef(0.0f + _translate, 2.0f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.2f + _translate, 2.0f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.4f + _translate, 2.0f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.3f + _translate, 2.2f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.1f + _translate, 2.2f,0.0);
	glutSolidSphere(0.2,30,40);
    glPopMatrix();
}

void _bird()
{
    glPushMatrix();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.0f,0.7f);
    glVertex2f(0.05f,0.68f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.05f,0.68f);
    glVertex2f(0.0f,0.66);
    glEnd();

    glTranslated(0.08,0.0,0);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.0f,0.7f);
    glVertex2f(0.05f,0.68f);

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.05f,0.68f);
    glVertex2f(0.0f,0.66);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.0f,0.7f);
    glVertex2f(0.05f,0.68f);

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.05f,0.68f);
    glVertex2f(0.0f,0.66);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.0f,0.8f);
    glVertex2f(0.05f,0.78f);

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0.05f,0.78f);
    glVertex2f(0.0f,0.76);
    glEnd();
    glPopMatrix();

    glLoadIdentity();
}


void _lampPost()
{
    glPushMatrix();
    glScalef(0.5,0.7, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(30, 144, 255);
    glVertex3f(-0.1, 0.8, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.4, 1.0, 0.0);
    glVertex3f(0.3, 0.8, 0.0);
    glEnd();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(119, 136, 153);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.03, 0.0, 0.0);
    glVertex3f(0.03, 0.9, 0.0);
    glVertex3f(0.0, 0.9, 0.0);
    glEnd();
    glPopMatrix();

    if(rain || night)
    {
        glPushMatrix();
        glScalef(0.7, 0.7, 0.0);
        glTranslatef(0.3, 0.45, 0.0);
        glRotatef(-90,1.0,0.0,0.0);
        glColor3f(255,255,255);
        glutSolidCone(.35, 0.9, 10, 10);
        glPopMatrix();
    }

    glPopMatrix();
}

void _circle(float x)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r = x;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
}

void _road()
{
    glPushMatrix();
	glScalef(8.0,2.8f,0);

    /// Lower Road white line
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(228, 232, 9);
    glVertex2f(-1.0f,-0.96f);
	glVertex2f(1.0f, -0.96f);
    glEnd();

	 /// Upper Road white line
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(228, 232, 9);
    glVertex2f(-1.0f,-0.76f);
	glVertex2f(1.0f, -0.76f);
    glEnd();

	/// Main Black Road
    glBegin(GL_QUADS);
    glColor3ub(54, 49, 48);
    glVertex2f(-1.0f,-0.76f);
	glVertex2f(-1.0f, -0.97f);
	glVertex2f(1.0f,-0.97f);
	glVertex2f(1.0f, -0.76f);
    glEnd();

    glPopMatrix();
}

void _building()
{
    glPushMatrix();
    glLineWidth(3);


    glColor3ub(0, 0, 0);
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.5, 1.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(-0.5, 1.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(0.5, 1.0, 0.0);
    glVertex3f(-0.5, 1.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,0.4,0.0);
    glBegin(GL_QUADS);
    if(rain || night){ glColor3ub(255, 215, 0); }
    else { glColor3ub(0,0,0);}
    glVertex3f(-0.3, 0.2, 0.0);
    glVertex3f(-0.3, 0.4, 0.0);
    glVertex3f(-0.1, 0.4, 0.0);
    glVertex3f(-0.1, 0.2, 0.0);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glBegin(GL_QUADS);
    if(rain || night){ glColor3ub(0, 0, 0); }
    else { glColor3ub(220, 220, 220);}
    glVertex3f(-0.3, 0.2, 0.0);
    glVertex3f(-0.3, 0.4, 0.0);
    glVertex3f(-0.1, 0.4, 0.0);
    glVertex3f(-0.1, 0.2, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    if(rain || night){ glColor3ub(255, 215, 0); }
    else { glColor3ub(220, 220, 220);}
    glVertex3f(0.3, 0.2, 0.0);
    glVertex3f(0.3, 0.4, 0.0);
    glVertex3f(0.1, 0.4, 0.0);
    glVertex3f(0.1, 0.2, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,0.4,0.0);
    glBegin(GL_QUADS);
    if(rain || night){ glColor3ub(255, 215, 0); }
    else { glColor3ub(220, 220, 220);}
    glVertex3f(0.3, 0.2, 0.0);
    glVertex3f(0.3, 0.4, 0.0);
    glVertex3f(0.1, 0.4, 0.0);
    glVertex3f(0.1, 0.2, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(b_red, b_green, b_blue);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.5, 1.0, 0.0);
    glVertex3f(-0.5, 1.0, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(rain){glClearColor(0.0f, 0.0f, 0.5f, 0.0);}
    else if(spring){glClearColor(0.8f, 0.36f, 0.36f, 0.0);}
    else if(winter){glClearColor(0.373f, 0.6196f, 0.627f, 0.0);}
    else if(night) {glClearColor(0.184, 0.3098, 0.3098,0.0);}
    else{glClearColor(0.0f, 0.75f, 1.0f, 0.0); }

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(0.0, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

    glPushMatrix();


///*********************************************** Rain ***************************************

    if(rain)
    {
        glPushMatrix();
        glRotatef(-30, 0.0, 0.0, 1.0);
        for(float i = -65.0f; i< 150.0f; i++)
        {
            glPushMatrix();
            glTranslatef((i*0.4), 0.0f - _translate_Rain, 0.0f);
            _rain();
            glPopMatrix();
        }
        glPopMatrix();
    }

///*********************************************** Cloud **************************************

    glPushMatrix();

    glPushMatrix();
    _cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, 0.1f,0.0);
    _cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.0f, 0.2f,0.0);
    _cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, -0.2f,0.0);
    _cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.7f, -0.1f,0.0);
    _cloud();
    glPopMatrix();

    glPopMatrix();

///********************************************** Bird *************************************

    if(bird)
    {
        glPushMatrix();

        glPushMatrix();
        glRotatef(180, 0.0, 1.0, 0.0);
        glTranslatef(0.0f + _translate_Bird, 1.4f, 0.0);
        _bird();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.7f + _translate_Bird, 1.1f, 0.0);
        _bird();
        glPopMatrix();

        glPopMatrix();
    }


///********************************************** Plane *************************************

    if(plane)
    {
        glPushMatrix();
        glTranslatef(0.0f - _translate_Plane, 2.0f,0.0);

        for(int i = -3; i<3; i++)
        {
            glPushMatrix();
            glTranslatef((-0.3 + (i*0.1)), 0.07, 0.0);
            glBegin(GL_QUADS);
            glColor3ub(0,0,0);
            glVertex3f( 0.0,  0.0, 0.0);
            glVertex3f( 0.025, 0.0, 0.0);
            glVertex3f(0.025, 0.025, 0.0);
            glVertex3f(0.0,  0.025, 0.0);
            glEnd();
            glPopMatrix();
        }

        glPushMatrix();
        glTranslatef(-0.7, 0.0, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex3f( 0.0,  0.0, 0.0);
        glVertex3f( 0.05, 0.0, 0.0);
        glVertex3f(0.05, 0.05, 0.0);
        glVertex3f(0.0,  0.05, 0.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.85, 0.07, 0.0);
        glBegin(GL_QUADS);
        glColor3ub(0,0,0);
        glVertex3f( 0.0,  0.0, 0.0);
        glVertex3f( 0.07, 0.0, 0.0);
        glVertex3f(0.07, 0.07, 0.0);
        glVertex3f( 0.0,  0.0, 0.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3ub(135, 206, 235);
        glVertex3f( 0.05,  0.25, 0.0);
        glVertex3f( 0.05, -0.05, 0.0);
        glVertex3f(-0.05, -0.05, 0.0);
        glVertex3f(-0.05,  0.5, 0.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3ub(135, 206, 235);
        glVertex3f(-0.4, -0.01, 0.0);
        glVertex3f(-0.15, -0.25, 0.0);
        glVertex3f(-0.3, -0.25, 0.0);
        glVertex3f(-0.6, -0.01, 0.0);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3ub(135, 206, 235);
        glVertex3f(-0.05,  0.15, 0.0);
        glVertex3f(-0.05, -0.05, 0.0);
        glVertex3f(-0.8, -0.05, 0.0);
        glVertex3f(-0.8,  0.15, 0.0);
        glEnd();
        glPopMatrix();



        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3ub(135, 206, 235);
        glVertex3f(-0.8, -0.05, 0.0);
        glVertex3f(-0.9, 0.05, 0.0);
        glVertex3f(-0.9, 0.05, 0.0);
        glVertex3f(-0.8,  0.15, 0.0);
        glEnd();
        glPopMatrix();



        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3ub(135, 206, 235);
        glVertex3f(-0.25, 0.35, 0.0);
        glVertex3f(-0.5, -0.01, 0.0);
        glVertex3f(-0.7, -0.01, 0.0);
        glVertex3f(-0.4, 0.35, 0.0);
        glEnd();
        glPopMatrix();

    if(rain || night)
    {
        glPushMatrix();
        glTranslatef(-0.52, -0.17, 0.0);
        glBegin(GL_TRIANGLES);
        glColor3ub(255,255,255);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.0, 0.1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.47, -0.22, 0.0);
        glBegin(GL_TRIANGLES);
        glColor3ub(255,255,255);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.0, 0.1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.52, 0.18, 0.0);
        glBegin(GL_TRIANGLES);
        glColor3ub(255,255,255);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.0, 0.1);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.47, 0.22, 0.0);
        glBegin(GL_TRIANGLES);
        glColor3ub(255,255,255);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.05, 0.05);
        glVertex2f(0.0, 0.1);
        glEnd();
        glPopMatrix();
    }

        glPopMatrix();
    }

///*********************************************** Sun ***************************************


    if(night)
    {
        glPushMatrix();
        glTranslatef(-0.1, 0.1, 0.0);
        glColor3f(0.184, 0.3098, 0.3098);
        glTranslatef(3.5, 2.3,  0.0);
        _circle(0.30f);
        glPopMatrix();

        glPushMatrix();
        glColor3ub(255,215,255);
        glTranslatef(3.5, 2.3,  0.0);
        _circle(0.30f);
        glPopMatrix();
    }
    else if(!rain)
    {
        glPushMatrix();
        glColor3ub(255,215,0);
        glTranslatef(3.5, 2.3,  0.0);
        _circle(0.30f);
        glPopMatrix();
    }
///*********************************************** LampPost **********************************

    glPushMatrix();
    glTranslatef(0.0, -1.3, 0.0f);

    glPushMatrix();
    _lampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.4, 0.0, 0.0f);
    _lampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.4, 0.0, 0.0f);
    _lampPost();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.8, 0.0, 0.0f);
    _lampPost();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(1.2, -1.4, 0.0f);
    _lampPost();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(-1.2, -1.4, 0.0f);
    _lampPost();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(3.6, -1.4, 0.0f);
    _lampPost();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(-3.6, -1.4, 0.0f);
    _lampPost();
    glPopMatrix();

    glPopMatrix();

///*********************************************** Trees **************************************
    glPushMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(6.1, -1.7, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.9, 0.9, 0.0);
    glTranslatef(2.9, -1.25, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(1.3, -1.7, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.8, -1.2, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(-1.1, -1.7, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(-3.5, -1.7, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.4, 0.4, 0.0);
    glTranslatef(-9.6, -2.9, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0, -1.15, 0.0);
    _tree();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(-8.3, -1.7, 0.0);
    _tree();
    glPopMatrix();

    glPopMatrix();

///********************************************* Network Tower **********************************

    glPushMatrix();
    glTranslatef(1.2, 0.9, 0.0);
    glPushMatrix();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.2, 0.4);
    glVertex2f(0.2, 0.6);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 0.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.3, 0.0);
    glVertex2f(0.0, 0.3);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.3, 0.0);
    glVertex2f(0.0, 0.3);
    glEnd();

    glPopMatrix();

    glPopMatrix();

///*********************************************** Train ***************************************

    glPushMatrix();
    glTranslatef(+ _translate_Train, -2.01, 0.0);
    glScalef(0.4, 0.4, 0.0);
    _train();
    glPopMatrix();

///************************************ Road Side Railing *************************************

    glPushMatrix();
    for(i = -60.0f; i < 100; i++)
    {
        glPushMatrix();
        glTranslatef((0.0+(i*0.1)), -1.32, 0.0);
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.1);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    for(i = -60.0f; i < 100; i++)
    {
        glPushMatrix();
        glTranslatef((0.0+(i*0.1)), -2.22, 0.0);
        glScalef(1.0, 7.4, 0.0);
        glRotatef(-65, 0.0, 0.0, 1.0);
        glBegin(GL_LINES);
        glColor3ub(220, 220, 220);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.1);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    for(i = -60.0f; i < 100; i++)
    {
        glPushMatrix();
        glTranslatef((0.0+(i*0.1)), -2.8, 0.0);
        glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.1);
        glEnd();
        glPopMatrix();
    }
    glPopMatrix();

///*********************************************** Building **************************************

    glPushMatrix();
    glTranslatef(0.0, -0.8, 0);

    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    b_red = 85, b_green = 107, b_blue = 47;
    _building();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.7,0.7,0.0);
    glTranslatef(2.5, 0.0, 0.0);
    glRotatef(180, 0.0, 1.0, 0.0);
    b_red = 70, b_green = 130, b_blue = 80;
    _building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.2, 0.0, 0.0);
    b_red = 205, b_green = 205, b_blue = 92;
    _building();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.7,1.3,0.0);
    glTranslatef(1.7, 0.0, 0.0);
    b_red = 176, b_green = 48, b_blue = 96;
    _building();
    glPopMatrix();


    glPushMatrix();
    glScalef(1.3,1.7,0.0);
    glTranslatef(0.7, 1.0, 0.0);
    glRotatef(180, 0.0, 0.0, 1.0);
    b_red = 55, b_green = 50, b_blue = 205;
    _building();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 1.0 ,0.0);
    glTranslatef(-1.7, 0.0, 0.0);
    b_red = 145, b_green = 55, b_blue = 255;
    _building();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.1,2.2,0.0);
    glTranslatef(-0.8, 0.0, 0.0);
    b_red = 122, b_green = 55, b_blue = 139;
    _building();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.1, 2.2, 0.0);
    glTranslatef(-2.3, 1.0, 0.0);
    glRotatef(180, 0.0, 0.0, 1.0);
    b_red = 205, b_green = 133, b_blue = 0;
    _building();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.2, 1.2, 0.0);
    glTranslatef(-3.7, 0.0, 0.0);
    b_red = 122, b_green = 55, b_blue = 139;
    _building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.3, 0.0, 0.0);
    b_red = 141, b_green = 182, b_blue = 205;
    _building();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5, 1.5, 0.0);
    glTranslatef(-2.3, 0.0, 0.0);
    glRotatef(180, 0.0, 1.0, 0.0);
    b_red = 176, b_green = 48, b_blue = 96;
    _building();
    glPopMatrix();

    glPopMatrix();

///*********************************************** Walking Path ***************************************

    glPushMatrix();
    glTranslatef(0.0, -0.8, 0);

    glPushMatrix();
    glLineWidth(3);

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(6,0);
    glVertex2f(-6,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(6,-0.5);
    glVertex2f(-6,-0.5);
    glEnd();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f,0.0f,0);
    glColor3ub(205,197,191);
    glBegin(GL_QUADS);
    glVertex2f(6,-0.5);
    glVertex2f(-6,-0.5);
    glVertex2f(-6,0);
    glVertex2f(6,0);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -2.8, 0);

    glPushMatrix();
    glLineWidth(3);

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(6,0);
    glVertex2f(-6,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(6,-0.5);
    glVertex2f(-6,-0.5);
    glEnd();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.0f,0.0f,0);
    glColor3ub(205,197,191);
    glBegin(GL_QUADS);
    glVertex2f(6,-0.5);
    glVertex2f(-6,-0.5);
    glVertex2f(-6,0);
    glVertex2f(6,0);
    glEnd();
    glPopMatrix();

    glPopMatrix();



///*********************************************** Car ***************************************

    glPushMatrix();

    glPushMatrix();
    glTranslatef(0.0 - _translate_car, -1.5, 0.0);
    _car();
    glPopMatrix();


    glPushMatrix();
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(0.0 - _translate_car, -2.5, 0.0);
    _car();
    glPopMatrix();

    glPopMatrix();

///*********************************************** Road ***************************************

    glPushMatrix();

    glPushMatrix();
    _road();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.9, 0.0);
    _road();
    glPopMatrix();

///******************************************* Rail Track *************************************
    glPushMatrix();

    glTranslatef(0.0f,-1.7f,0);
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(6,-0.5);
    glVertex2f(-6,-0.5);
    glVertex2f(-6,0);
    glVertex2f(6,0);
    glEnd();
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();

	/// End of Code
    glPopMatrix();
	glutSwapBuffers();
}

/// Translation Function

    void CloudTranslation(){
      _translate+= 0.05f;
      if(_translate > 10){
        _translate = -10.0f;
      }
    }

    void PlaneTranslation(){
      _translate_Plane+= 0.05f;
      if(_translate_Plane > 8){
        _translate_Plane = -8.0f;
      }
    }

    void BirdTranslation(){
    _translate_Bird += 0.05f;
      if(_translate_Bird > 7){
        _translate_Bird = -10.0f;
      }
    }

    void TrainTranslation(){
    if(train){_translate_Train += 0.05f;}
      else{_translate_Train;}
      if(_translate_Train > 7){
        _translate_Train = -10.0f;
      }
    }

    void RainTranslation(){
      _translate_Rain += 0.05f;
      if(_translate_Rain > 15){
        _translate_Rain = 2.0f;
      }
    }

    void CarTranslation(){
      _translate_car += 0.05f;
      if(_translate_car > 7){
        _translate_car = -10.0f;
      }
    }

/// Update Functions

void updateCar(int value)
{
    CarTranslation();
	glutPostRedisplay();

    glutTimerFunc(40, updateCar, 0);
}

void updateBird(int value)
{
    BirdTranslation();
	glutPostRedisplay();

    glutTimerFunc(180, updateBird, 0);
}

void updateTrain(int value)
{
    TrainTranslation();
	glutPostRedisplay();

    glutTimerFunc(50, updateTrain, 0);
}

void updateCloud(int value)
{
    CloudTranslation();
    glutPostRedisplay();

    glutTimerFunc(500, updateCloud, 0);
}

void updatePlane(int value)
{
    PlaneTranslation();
    glutPostRedisplay();

    glutTimerFunc(50, updatePlane, 0);
}

void updateRain(int value)
{
    RainTranslation();
    glutPostRedisplay();

    glutTimerFunc(20, updateRain, 0);
}


void keyboard(unsigned char key, int x, int y){
    switch(key){
    case 's': /// for summer season
        winter = false;
        rain = false;
        spring = false;
        night = false;
        bird = true;
        break;
    case 'r': /// for rainy season
        rain = true;
        winter = false;
        spring = false;
        night = false;
        bird = false;
        break;
    case 'a': /// for spring season
        spring = true;
        winter = false;
        rain = false;
        night = false;
        bird = true;
        break;
    case 'p':
        plane = true;
        break;
    case 'P':
        plane = false;
        break;
    case 'w':
        spring = false;
        winter = true;
        rain = false;
        night = false;
        bird = true;
        break;
    case 'n':
        spring = false;
        winter = false;
        rain = false;
        night = true;
        bird = false;
        break;
    case 'T':
        train = false;
        break;
    case 't':
        train = true;
        break;
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 800);
	glutInitWindowPosition(200,100);

	//Create the window
	glutCreateWindow("Season OF Bangladesh");
	glutKeyboardFunc(keyboard);
	glutFullScreen();
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	/// Timer Functions
	glutTimerFunc(100, updateCloud, 0);
    glutTimerFunc(100, updateCar, 0);
    glutTimerFunc(100, updateBird, 0);
    glutTimerFunc(100, updateTrain, 0);
    glutTimerFunc(100, updateRain, 0);
    glutTimerFunc(100, updatePlane, 0);

	glutMainLoop();
	return 0;
}
