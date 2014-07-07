//
//  DrawPrimitives.cpp
//  SimonSays
//

#include "DrawPrimitives.hpp"
#include <iostream>
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
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glLineWidth(2.5);
	glColor4f(0, 0, 0, 1);
    // BOTTOM
    glBegin(GL_LINES);
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

    glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();

	// BACK
	glBegin(GL_LINES);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	// RIGHT
	glBegin(GL_LINES);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();

	// LEFT
	glBegin(GL_LINES);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();

	// TOP
	glBegin(GL_LINES);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glEnd();

	
    
    glFlush();
}
void drawButton(int const colorId, int const highlightColorId){
	glScalef(0.03, 0.03, 0.03);

    if(colorId==COLOR_RED)
        glColor4f( 1.0, (highlightColorId == COLOR_RED ? 1 : 0.0), (highlightColorId == COLOR_RED ? 1 : 0.0), 1.0 );
    else if(colorId==COLOR_GREEN)
        glColor4f( (highlightColorId == COLOR_GREEN ? 1 : 0.0), 1.0, (highlightColorId == COLOR_GREEN ? 1 : 0.0), 1.0 );
    else if(colorId==COLOR_BLUE)
        glColor4f( (highlightColorId == COLOR_BLUE ? 1 : 0.0), (highlightColorId == COLOR_BLUE ? 1 : 0.0), 1.0, 1.0 );
    else if(colorId==COLOR_YELLOW)
        glColor4f( 1.0, 1.0, (highlightColorId == COLOR_YELLOW ? 1 : 0.0), 1.0 );
    else if(colorId==START_MARKER)
        glColor4f( 0.0, 1.0, 1.0, 1.0 );
    drawCube(  );
}

void drawHeart(){

	//glRotatef(90, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(1, 0, 0, 1);
	glVertex3f(0, -0.15, 0.5);//bottom
	glVertex3f(-0.2, 0.1, 0.5);
	glVertex3f(-0.18, 0.16, 0.5);
	glVertex3f(-0.1, 0.2, 0.5);
	glVertex3f(0, 0.15, 0.5);
	glVertex3f(0.1, 0.2, 0.5);
	glVertex3f(0.18, 0.16, 0.5);
	glVertex3f(0.2, 0.1, 0.5);
	glEnd();
	glFlush();

}