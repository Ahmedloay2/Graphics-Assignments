///////////////////////////////////
// Assignment1_Scene.cpp
//
// OpenGL program to draw a 2D scene with 6 objects.
// Objects: House, Car, Tree, Sun, Cloud, Fence
// 
// Team Members: 6
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

    // ========== BACKGROUND: SKY (Draw first) ==========
    glColor3f(0.53f, 0.81f, 0.92f); // Sky blue
    glBegin(GL_QUADS);
    glVertex3f(0.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 15.0, 0.0);
    glVertex3f(0.0, 15.0, 0.0);
    glEnd();
    
    // ========== BACKGROUND: GROUND/GRASS ==========
    glColor3f(0.4f, 0.7f, 0.3f); // Green grass
    glBegin(GL_QUADS);
    glVertex3f(0.0, 15.0, 0.0);
    glVertex3f(100.0, 15.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    // ========== OBJECT 1: SUN (Partially clipped - demonstrates viewing box effect) ==========
    // Positioned at top-right corner to show clipping
    glColor3f(1.0f, 0.9f, 0.0f); // Bright yellow
    
    // Sun circle using GL_TRIANGLE_FAN
    float sunCenterX = 95.0f;
    float sunCenterY = 95.0f;
    float sunRadius = 12.0f;
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(sunCenterX, sunCenterY, 0.0);
    for (int i = 0; i <= 20; i++) {
        float angle = 2.0f * M_PI * i / 20;
        float x = sunCenterX + sunRadius * cos(angle);
        float y = sunCenterY + sunRadius * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    
    // Sun rays using GL_LINES
    glColor3f(1.0f, 0.8f, 0.0f); // Orange-yellow
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++) {
        float angle = 2.0f * M_PI * i / 8;
        float x1 = sunCenterX + (sunRadius + 2) * cos(angle);
        float y1 = sunCenterY + (sunRadius + 2) * sin(angle);
        float x2 = sunCenterX + (sunRadius + 6) * cos(angle);
        float y2 = sunCenterY + (sunRadius + 6) * sin(angle);
        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2, 0.0);
    }
    glEnd();

    // ========== OBJECT 2: CLOUD ==========
    glColor3f(0.9f, 0.9f, 0.95f); // Light gray-white
    
    // Cloud made of multiple circles using GL_POLYGON
    float cloudX = 30.0f;
    float cloudY = 85.0f;
    
    // Left circle
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 15; i++) {
        float angle = 2.0f * M_PI * i / 15;
        float x = cloudX + 4.0f * cos(angle);
        float y = cloudY + 4.0f * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    
    // Middle circle
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 15; i++) {
        float angle = 2.0f * M_PI * i / 15;
        float x = cloudX + 7.0f + 5.0f * cos(angle);
        float y = cloudY + 1.0f + 5.0f * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    
    // Right circle
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 15; i++) {
        float angle = 2.0f * M_PI * i / 15;
        float x = cloudX + 14.0f + 4.0f * cos(angle);
        float y = cloudY + 4.0f * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    // ========== OBJECT 3: HOUSE ==========
    // House base using GL_QUADS
    glColor3f(0.8f, 0.4f, 0.2f); // Brown
    glBegin(GL_QUADS);
    glVertex3f(10.0, 40.0, 0.0);  // Top-left corner of house
    glVertex3f(35.0, 40.0, 0.0);  // Top-right corner of house
    glVertex3f(35.0, 15.0, 0.0);  // Bottom-right corner of house
    glVertex3f(10.0, 15.0, 0.0);  // Bottom-left corner of house
    glEnd();

    // Roof using GL_TRIANGLES
    glColor3f(0.6f, 0.2f, 0.1f); // Dark red-brown
    glBegin(GL_TRIANGLES);
    glVertex3f(8.0, 40.0, 0.0);   // Bottom-left of roof (extends beyond house)
    glVertex3f(22.5, 52.0, 0.0);  // Peak of roof
    glVertex3f(37.0, 40.0, 0.0);  // Bottom-right of roof (extends beyond house)
    glEnd();

    // Door using GL_QUADS
    glColor3f(0.4f, 0.2f, 0.1f); // Dark brown
    glBegin(GL_QUADS);
    glVertex3f(18.0, 30.0, 0.0);  // Top-left of door
    glVertex3f(24.0, 30.0, 0.0);  // Top-right of door
    glVertex3f(24.0, 15.0, 0.0);  // Bottom-right of door
    glVertex3f(18.0, 15.0, 0.0);  // Bottom-left of door
    glEnd();

    // Windows using GL_QUADS
    glColor3f(0.6f, 0.8f, 1.0f); // Light blue window glass
    glBegin(GL_QUADS);
    // Left window
    glVertex3f(13.0, 36.0, 0.0);  // Top-left of left window
    glVertex3f(17.0, 36.0, 0.0);  // Top-right of left window
    glVertex3f(17.0, 32.0, 0.0);  // Bottom-right of left window
    glVertex3f(13.0, 32.0, 0.0);  // Bottom-left of left window

    // Right window
    glVertex3f(28.0, 36.0, 0.0);  // Top-left of right window
    glVertex3f(32.0, 36.0, 0.0);  // Top-right of right window
    glVertex3f(32.0, 32.0, 0.0);  // Bottom-right of right window
    glVertex3f(28.0, 32.0, 0.0);  // Bottom-left of right window
    glEnd();

    // Window frames using GL_LINE_LOOP
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray for window frames
    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glVertex3f(13.0, 36.0, 0.0);  // Frame top-left
    glVertex3f(17.0, 36.0, 0.0);  // Frame top-right
    glVertex3f(17.0, 32.0, 0.0);  // Frame bottom-right
    glVertex3f(13.0, 32.0, 0.0);  // Frame bottom-left
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(28.0, 36.0, 0.0);  // Frame top-left
    glVertex3f(32.0, 36.0, 0.0);  // Frame top-right
    glVertex3f(32.0, 32.0, 0.0);  // Frame bottom-right
    glVertex3f(28.0, 32.0, 0.0);  // Frame bottom-left
    glEnd();

    // Window cross frames (muntins) using GL_LINES
    glLineWidth(1.5);
    glBegin(GL_LINES);
    // Left window cross
    glVertex3f(15.0, 32.0, 0.0);  // Vertical line bottom
    glVertex3f(15.0, 36.0, 0.0);  // Vertical line top
    glVertex3f(17.0, 34.0, 0.0);  // Horizontal line right
    glVertex3f(13.0, 34.0, 0.0);  // Horizontal line left
    glEnd();

    glBegin(GL_LINES);
    // Right window cross
    glVertex3f(30.0, 32.0, 0.0);  // Vertical line bottom
    glVertex3f(30.0, 36.0, 0.0);  // Vertical line top
    glVertex3f(32.0, 34.0, 0.0);  // Horizontal line right
    glVertex3f(28.0, 34.0, 0.0);  // Horizontal line left
    glEnd();

    // ========== OBJECT 4: HUMAN ==========

// ----- TORSO -----
    glColor3f(0.3f, 0.5f, 0.9f); // Blue shirt
    glBegin(GL_QUADS);
    glVertex3f(26.0, 28.0, 0.0);
    glVertex3f(29.0, 28.0, 0.0);
    glVertex3f(29.0, 20.0, 0.0);
    glVertex3f(26.0, 20.0, 0.0);
    glEnd();

    // ----- HEAD -----
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex3f(26.5, 31.0, 0.0);
    glVertex3f(28.5, 31.0, 0.0);
    glVertex3f(28.5, 28.0, 0.0);
    glVertex3f(26.5, 28.0, 0.0);
    glEnd();

    // ----- HAIR -----
    glColor3f(0.4f, 0.25f, 0.1f); // Brown hair
    glBegin(GL_QUADS);
    glVertex3f(26.5, 31.0, 0.0);
    glVertex3f(28.5, 31.0, 0.0);
    glVertex3f(28.5, 30.0, 0.0);
    glVertex3f(26.5, 30.0, 0.0);
    glEnd();

    // ----- LEFT ARM -----
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex3f(25.0, 27.0, 0.0);
    glVertex3f(26.0, 27.0, 0.0);
    glVertex3f(26.0, 22.0, 0.0);
    glVertex3f(25.0, 22.0, 0.0);
    glEnd();

    // ----- RIGHT ARM -----
    glColor3f(1.0f, 0.8f, 0.6f); // Skin color
    glBegin(GL_QUADS);
    glVertex3f(29.0, 27.0, 0.0);
    glVertex3f(30.0, 27.0, 0.0);
    glVertex3f(30.0, 22.0, 0.0);
    glVertex3f(29.0, 22.0, 0.0);
    glEnd();

    // ----- PANTS / LEGS -----
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray pants
    glBegin(GL_QUADS);
    // Left leg
    glVertex3f(26.0, 20.0, 0.0);
    glVertex3f(27.0, 20.0, 0.0);
    glVertex3f(27.0, 15.0, 0.0);
    glVertex3f(26.0, 15.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    // Right leg
    glVertex3f(28.0, 20.0, 0.0);
    glVertex3f(29.0, 20.0, 0.0);
    glVertex3f(29.0, 15.0, 0.0);
    glVertex3f(28.0, 15.0, 0.0);
    glEnd();

    // ----- SHOES -----
    glColor3f(0.1f, 0.1f, 0.1f); // Black shoes
    glBegin(GL_QUADS);
    // Left shoe
    glVertex3f(26.0, 15.0, 0.0);
    glVertex3f(27.0, 15.0, 0.0);
    glVertex3f(27.0, 14.5, 0.0);
    glVertex3f(26.0, 14.5, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    // Right shoe
    glVertex3f(28.0, 15.0, 0.0);
    glVertex3f(29.0, 15.0, 0.0);
    glVertex3f(29.0, 14.5, 0.0);
    glVertex3f(28.0, 14.5, 0.0);
    glEnd();
    // ========== OBJECT 5: TREE ==========
    // Tree trunk using GL_QUADS
    glColor3f(0.4f, 0.25f, 0.1f); // Brown
    glBegin(GL_QUADS);
    glVertex3f(70.0, 30.0, 0.0);
    glVertex3f(75.0, 30.0, 0.0);
    glVertex3f(75.0, 15.0, 0.0);
    glVertex3f(70.0, 15.0, 0.0);
    glEnd();
    
    // Tree foliage using GL_TRIANGLES (multiple layers)
    glColor3f(0.1f, 0.6f, 0.1f); // Green
    
    // Bottom layer
    glBegin(GL_TRIANGLES);
    glVertex3f(60.0, 30.0, 0.0);
    glVertex3f(72.5, 43.0, 0.0);
    glVertex3f(85.0, 30.0, 0.0);
    glEnd();
    
    // Middle layer
    glColor3f(0.15f, 0.65f, 0.15f); // Slightly lighter green
    glBegin(GL_TRIANGLES);
    glVertex3f(63.0, 37.0, 0.0);
    glVertex3f(72.5, 48.0, 0.0);
    glVertex3f(82.0, 37.0, 0.0);
    glEnd();
    
    // Top layer
    glColor3f(0.2f, 0.7f, 0.2f); // Even lighter green
    glBegin(GL_TRIANGLES);
    glVertex3f(66.0, 43.0, 0.0);
    glVertex3f(72.5, 53.0, 0.0);
    glVertex3f(79.0, 43.0, 0.0);
    glEnd();

    // ========== OBJECT 6: CAR ==========
    // Car body using GL_QUADS
    glColor3f(0.8f, 0.0f, 0.0f); // Red
    glBegin(GL_QUADS);
    // Main body
    glVertex3f(42.0, 24.0, 0.0);
    glVertex3f(58.0, 24.0, 0.0);
    glVertex3f(58.0, 17.0, 0.0);
    glVertex3f(42.0, 17.0, 0.0);
    
    // Car roof
    glVertex3f(45.0, 29.0, 0.0);
    glVertex3f(55.0, 29.0, 0.0);
    glVertex3f(55.0, 24.0, 0.0);
    glVertex3f(45.0, 24.0, 0.0);
    glEnd();
    
    // Car windows using GL_QUADS
    glColor3f(0.7f, 0.9f, 1.0f); // Light blue
    glBegin(GL_QUADS);
    // Front window
    glVertex3f(45.5, 28.5, 0.0);
    glVertex3f(49.5, 28.5, 0.0);
    glVertex3f(49.5, 24.5, 0.0);
    glVertex3f(45.5, 24.5, 0.0);
    
    // Back window
    glVertex3f(50.5, 28.5, 0.0);
    glVertex3f(54.5, 28.5, 0.0);
    glVertex3f(54.5, 24.5, 0.0);
    glVertex3f(50.5, 24.5, 0.0);
    glEnd();

    // Window cross frames for car windows
    glColor3f(0.2f, 0.2f, 0.2f); // Dark gray for window frames
    glLineWidth(1.5);
    glBegin(GL_LINES);
    // Front window cross
    glVertex3f(47.5, 24.5, 0.0); // Vertical line top
    glVertex3f(47.5, 28.5, 0.0); // Vertical line bottom
    glVertex3f(49.5, 26.5, 0.0); // Horizontal line right
    glVertex3f(45.5, 26.5, 0.0); // Horizontal line left
    glEnd();

    glBegin(GL_LINES);
    // Back window cross
    glVertex3f(52.5, 28.5, 0.0); // Vertical line top
    glVertex3f(52.5, 24.5, 0.0); // Vertical line bottom
    glVertex3f(54.5, 26.5, 0.0); // Horizontal line right
    glVertex3f(50.5, 26.5, 0.0); // Horizontal line left
    glEnd();
    // Car wheels using GL_POLYGON (circles)
    glColor3f(0.1f, 0.1f, 0.1f); // Black
    
    // Left wheel
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 15; i++) {
        float angle = 2.0f * M_PI * i / 15;
        float x = 46.0f + 2.0f * cos(angle);
        float y = 17.0f + 2.0f * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    
    // Right wheel
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 15; i++) {
        float angle = 2.0f * M_PI * i / 15;
        float x = 54.0f + 2.0f * cos(angle);
        float y = 17.0f + 2.0f * sin(angle);
        glVertex3f(x, y, 0.0);
    }
    glEnd();
    
    // Wheel centers (hubcaps)
    glColor3f(0.6f, 0.6f, 0.6f); // Gray
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex3f(46.0, 18.0, 0.0);
    glVertex3f(54.0, 18.0, 0.0);
    glEnd();

    // ========== OBJECT 7: FENCE ==========
    // Ground line first
    glColor3f(0.3f, 0.5f, 0.2f); // Dark green for grass line
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 15.0, 0.0);
    glVertex3f(100.0, 15.0, 0.0);
    glEnd();
    
    // Fence using GL_QUADS and GL_LINES
    glColor3f(0.5f, 0.35f, 0.2f); // Light brown
    
    // Vertical fence posts using GL_QUADS
    for (int i = 0; i < 10; i++) {
        float x = 5.0f + i * 10.0f;
        glBegin(GL_QUADS);
        glVertex3f(x, 15.0, 0.0);
        glVertex3f(x + 1.0, 15.0, 0.0);
        glVertex3f(x + 1.0, 8.0, 0.0);
        glVertex3f(x, 8.0, 0.0);
        glEnd();
    }
    
    // Horizontal fence rails using GL_QUADS
    glBegin(GL_QUADS);
    // Top rail
    glVertex3f(5.0, 14.0, 0.0);
    glVertex3f(95.0, 14.0, 0.0);
    glVertex3f(95.0, 13.5, 0.0);
    glVertex3f(5.0, 13.5, 0.0);
    
    // Bottom rail
    glVertex3f(5.0, 10.5, 0.0);
    glVertex3f(95.0, 10.5, 0.0);
    glVertex3f(95.0, 10.0, 0.0);
    glVertex3f(5.0, 10.0, 0.0);
    glEnd();
    
    // Fence post tops using GL_TRIANGLES (pointed tops)
    glColor3f(0.45f, 0.3f, 0.15f); // Darker brown
    for (int i = 0; i < 10; i++) {
        float x = 5.0f + i * 10.0f;
        glBegin(GL_TRIANGLES);
        glVertex3f(x, 15.0, 0.0);
        glVertex3f(x + 0.5, 16.5, 0.0);
        glVertex3f(x + 1.0, 15.0, 0.0);
        glEnd();
    }

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // ESC key to exit
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Assignment 1 - 2D Scene with 6 Objects");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}