
#define GLFW_INCLUDE_GLU
#include <glfw/glfw3.h>
//#include <GL/glew.h>
#include <iostream>
#include <iomanip>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "DrawPrimitives.hpp"
#include "PoseEstimation.hpp"
#include "MarkerTracker.hpp"
#define BUTTON_SIZE 4

using namespace std;

cv::VideoCapture cap;


struct Position { double x,y,z; };

float resultTransposedMatrix[16];

//camera settings
const int camera_width  = 640;
const int camera_height = 480;
const int virtual_camera_angle = 60;
unsigned char bkgnd[camera_width*camera_height*3];


void initVideoStream( cv::VideoCapture &cap ) {
	if( cap.isOpened() )
		cap.release();
    
	cap.open(0); // open the default camera
	if ( cap.isOpened()==false ) {
		std::cout << "No webcam found, using a video file" << std::endl;
		cap.open("MarkerMovie.mpg");
		if ( cap.isOpened()==false ) {
			std::cout << "No video file found. Exiting."      << std::endl;
			exit(0);
		}
	}
    
}

/* program & OpenGL initialization */
void initGL(int argc, char *argv[])
{
	// initialize the GL library
	
    // pixel storage/packing stuff
    glPixelStorei( GL_PACK_ALIGNMENT,   1 ); // for glReadPixels
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 ); // for glTexImage2D
    glPixelZoom( 1.0, -1.0 );
    
    // enable and set colors
    glEnable( GL_COLOR_MATERIAL );
    glClearColor( 0, 0, 0, 1.0 );
    
	// enable and set depth parameters
	glEnable( GL_DEPTH_TEST );
	glClearDepth( 1.0 );
    
	// light parameters
	GLfloat light_pos[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_amb[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_dif[] = { 0.7, 0.7, 0.7, 1.0 };
    
	// enable lighting
	glLightfv( GL_LIGHT0, GL_POSITION, light_pos );
	glLightfv( GL_LIGHT0, GL_AMBIENT,  light_amb );
	glLightfv( GL_LIGHT0, GL_DIFFUSE,  light_dif );
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );
    
    
}

void transpose(float resultMatrix[16], float (&resultTransposedMatrix)[16]){
    for (int x=0; x<4; ++x)
		for (int y=0; y<4; ++y)
			resultTransposedMatrix[x*4+y] = resultMatrix[y*4+x];
}
void display_background(GLFWwindow* window, const cv::Mat &img_bgr){
    memcpy( bkgnd, img_bgr.data, sizeof(bkgnd) );
    
	int width0, height0;
	glfwGetFramebufferSize(window, &width0, &height0);
    
    // clear buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
    // draw background image
    glDisable( GL_DEPTH_TEST );
    
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D( 0.0, camera_width, 0.0, camera_height );
    
    glRasterPos2i( 0, camera_height-1 );
//    Mac Code: Commented on Windows
    glDrawPixels( camera_width, camera_height, GL_BGR, GL_UNSIGNED_BYTE, bkgnd );
    
//    Windows Code: Commented on Mac
//    glDrawPixels( camera_width, camera_height, GL_BGR_EXT, GL_UNSIGNED_BYTE, bkgnd );
    
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);

}
void display_buttons(std::vector<Marker> &markers){
    // move to marker-position
    glMatrixMode( GL_MODELVIEW );
    
	for(int i=0; i<markers.size(); i++){
        transpose(markers[i].resultMatrix, resultTransposedMatrix);
        glLoadMatrixf( resultTransposedMatrix );
        drawButton(markers[i].colorID);
	}
    
}
void display_countDown(){
    
}

void reshape( GLFWwindow* window, int width, int height ) {
    
	// set a whole-window viewport
	glViewport( 0, 0, (GLsizei)width, (GLsizei)height );
    
	// create a perspective projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    
	// Note: Just setting the Perspective is an easy hack. In fact, the camera should be calibrated.
	// With such a calibration we would get the projection matrix. This matrix could then be loaded
	// to GL_PROJECTION.
	// If you are using another camera (which you'll do in most cases), you'll have to adjust the FOV
	// value. How? Fiddle around: Move Marker to edge of display and check if you have to increase or
	// decrease.
	gluPerspective( virtual_camera_angle, ((GLfloat)width/(GLfloat)height), 0.01, 100 );
    
}

cv::Mat getCameraImage(){
    cv::Mat img_bgr, tmp;
    /* Capture here */
    cap >> img_bgr;
    
    resize(img_bgr, tmp, cv::Size(640, 480));
    img_bgr = tmp;
    
    
    if(img_bgr.empty()){
        std::cout << "Could not query frame. Trying to reinitialize." << std::endl;
        initVideoStream(cap);
        cv::waitKey(1000); /// Wait for one sec.
    }
    return img_bgr;
}

int main(int argc, char* argv[])
{
    
	GLFWwindow* window;
    
	/* Initialize the library */
	if (!glfwInit())
		return -1;
    
    
	// initialize the window system
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(camera_width, camera_height, "Simon Says", NULL, NULL);
	if (!window){
		glfwTerminate();
		return -1;
	}
	
	// Set callback functions for GLFW
	glfwSetFramebufferSizeCallback(window, reshape);
    
	glfwMakeContextCurrent(window);
	glfwSwapInterval( 1 );
	
	int window_width, window_height;
	glfwGetFramebufferSize(window, &window_width, &window_height);
	reshape(window, window_width, window_height);
    
	glViewport(0, 0, window_width, window_height);
    
	// initialize the GL library
	initGL(argc, argv);
    
    // setup OpenCV
	cv::Mat img_bgr;
	initVideoStream(cap);
	const double kMarkerSize = 0.048; // [m]
	MarkerTracker markerTracker(kMarkerSize);
	
	std::vector<Marker> markers;
	/* Loop until the user closes the window */
    
    bool gameStarted = false;
	while (!glfwWindowShouldClose(window))
	{
		markers.resize(0);

        img_bgr = getCameraImage();
        if(img_bgr.empty()){
            continue;
        }
        display_background(window, img_bgr);

        /* Track a marker */
		markerTracker.findMarker(img_bgr, markers);
        display_buttons(markers);
        
        if(markers.size() == BUTTON_SIZE && !gameStarted){
            gameStarted = true;
            display_countDown();
        }
		      
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
        
		/* Poll for and process events */
		glfwPollEvents();
	}
    
	glfwTerminate();
    
    
    return 0;
}

