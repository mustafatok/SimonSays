#ifndef GLFW_INCLUDE_GLU
#define GLFW_INCLUDE_GLU
#include <glfw/glfw3.h>
#endif

#ifndef __DRAWPRIMITIVES_H__
#define __DRAWPRIMITIVES_H__
/* COLOR_IDS */
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_BLUE 3
#define COLOR_YELLOW 4
#define START_MARKER 9

#include <vector>

typedef std::vector<int> ColorSequence;

void drawCube();
void drawButton(int const colorId, int const highlightColorId);
#endif