//
//  DrawPrimitives.cpp
//  SimonSays
//
//  Created by mustafa tok on 6/27/14.
//  Copyright (c) 2014 Mustafa Tok. All rights reserved.
//

#include "DrawPrimitives.hpp"


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
	glScalef(0.03, 0.03, 0.03);
    
    if(colorId==COLOR_RED)
        glColor4f( 1.0, 0.0, 0.0, 1.0 );
    else if(colorId==COLOR_GREEN)
        glColor4f( 0.0, 1.0, 0.0, 1.0 );
    else if(colorId==COLOR_BLUE)
        glColor4f( 0.0, 0.0, 1.0, 1.0 );
    else if(colorId==COLOR_YELLOW)
        glColor4f( 1.0, 1.0, 0.0, 1.0 );
    else if(colorId==START_MARKER)
        glColor4f( 0.0, 1.0, 1.0, 1.0 );
    glTranslatef( 0.0, 0.0, 0.0 );
    drawCube(  );
}
