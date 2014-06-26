
#define GLFW_INCLUDE_GLU
#include <glfw/glfw3.h>

/* COLOR_IDS */
#ifndef COLOR_IDS
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_BLUE 3
#define COLOR_YELLOW 4
#endif

void drawCube() {
    
    // FRONT
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    // BACK
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
    
    // RIGHT
    glBegin(GL_POLYGON);
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();
    
    // LEFT
    glBegin(GL_POLYGON);
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    // TOP
    glBegin(GL_POLYGON);
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();
    
    // BOTTOM
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    glFlush();
}
void drawButton(int const colorId){
    glRotatef( -90, 0, 0, 0 );
	glScalef(0.03, 0.03, 0.03);
    
    if(colorId==COLOR_RED)
        glColor4f( 1.0, 0.0, 0.0, 1.0 );
    else if(colorId==COLOR_GREEN)
        glColor4f( 0.0, 1.0, 0.0, 1.0 );
    else if(colorId==COLOR_BLUE)
        glColor4f( 0.0, 0.0, 1.0, 1.0 );
    else if(colorId==COLOR_YELLOW)
        glColor4f( 1.0, 1.0, 0.0, 1.0 );
    glTranslatef( 0.0, 0.0, 0.0 );
    drawCube(  );
}
