#include <GL\glut.h>

GLfloat xRotated = 45, yRotated = 90, zRotated = 30;

GLfloat wheelRotated = 30;

void display(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

	//road
	glPushMatrix();
		glTranslatef(0.0,-2.5,-3.0);
		glColor3f(0.8, 0.2, 0.1); 
		glRotatef(xRotated,1.0,0.0,0.0);
		glRotatef(yRotated,0.0,1.0,0.0);
		glRotatef(zRotated,0.0,0.0,1.0);
		glScalef(1.0,1.0,1.0);
		glutSolidTorus(1.5,1,20,100);   
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5,-.5,-3.0);
		glColor3f(0.1, 0.1, 0.1); 
		glRotatef(xRotated,1.0,0.0,0.0);
		glRotatef(yRotated,0.0,1.0,0.0);
		glRotatef(zRotated,0.0,0.0,1.0);
		glScalef(1.0,1.0,1.0);
		glutSolidTorus(0.5,0.5,2,55);   
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5,-.5,-3.0);
		glColor3f(0.1, 0.1, 0.1); 
		glRotatef(xRotated,1.0,0.0,0.0);
		glRotatef(yRotated,0.0,1.0,0.0);
		glRotatef(zRotated,0.0,0.0,1.0);
		glScalef(1.0,1.0,1.0);
		glutSolidTorus(0.5,0.5,2,55);   
	glPopMatrix();

    

	// car
	glPushMatrix();

		glTranslatef(0,0.1,-3);
		glRotatef(90,0.0,10.0,0.0);
		glScalef(0.5,0.5,0.5);

		glColor3f(0.3, 0.5, 0.2);

		glPushMatrix();                  
			glScalef(2,.5,1);
			glutSolidCube(.5);
		glPopMatrix();
			glTranslatef(0,0,.25);
			glPushMatrix();
				glPushMatrix();
					glTranslatef(-.4,-.2,0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glutSolidTorus(.05,.1,8,8);      
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(.8,-0.1,0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glutSolidTorus(.05,.1,8,8);       
				glPopMatrix();

			glPopMatrix();

			glTranslatef(0,0,-.5);

			glPushMatrix();
				
				glPushMatrix();
					glTranslatef(-.4,-.2,0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glutSolidTorus(.05,.1,8,8);     
				glPopMatrix();
	
				glPushMatrix();
					glTranslatef(.8,-0.1,0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glRotatef(wheelRotated,0.0,0.0,1.0);
					glutSolidTorus(.05,.1,8,8);       
				glPopMatrix();

			glPopMatrix();
		glPopMatrix();

    glFlush();        

}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return; 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glViewport(0,0,x,y);
}

void update(void)
{
     zRotated += 0.01;
	 wheelRotated -= 0.05;
     display();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(700,700);
    glutCreateWindow("Moving Car 3D");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glClearColor(1.0,1.0,1.0,1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(update);
    glutMainLoop();
    return 0;
}