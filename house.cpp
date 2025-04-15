#include <GL/glut.h>
#include <iostream>
#include <cmath>

void drawCircle(float x, float y, float radius, int segments = 100) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.1416f * i / segments;
        glVertex2f(x + radius * cosf(angle), y + radius * sinf(angle));
    }
    glEnd();
}

//for sun
void drawSun() {
    glColor3f(1.0f, 0.9f, 0.0f); // Yellow sun
    drawCircle(0.75f, 0.75f, 0.1f);
}

//for cloud
void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.06f);
    drawCircle(x + 0.07f, y + 0.02f, 0.06f);
    drawCircle(x + 0.14f, y, 0.06f);
}

// House function 
void drawhouse() {
    // Roof
    glBegin(GL_TRIANGLES);
        glColor3f(0.3f, 0.0f, 0.0f);
        glVertex2f(-0.68f, 0.06f);
        glVertex2f(0.68f, 0.06f);
        glVertex2f(0.0f, 0.85f);
    glEnd();

    // House body
    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex2f(-0.65f, 0.06f);
        glVertex2f(0.65f, 0.06f);
        glVertex2f(0.65f, -0.85f);
        glVertex2f(-0.65f, -0.85f);
    glEnd();

    // Left window
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.8f, 0.8f);
        glVertex2f(-0.5f, -0.4f);
        glVertex2f(-0.3f, -0.4f);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.5f, -0.2f);
    glEnd();

    // Right window
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.8f, 0.8f);
        glVertex2f(0.5f, -0.4f);
        glVertex2f(0.3f, -0.4f);
        glVertex2f(0.3f, -0.2f);
        glVertex2f(0.5f, -0.2f);
    glEnd();

    // Door
    glBegin(GL_QUADS);
        glColor3f(0.8f, 0.6f, 0.4f);
        glVertex2f(-0.15f, -0.83f);
        glVertex2f(0.15f, -0.83f);
        glVertex2f(0.15f, -0.2f);
        glVertex2f(-0.15f, -0.2f);
    glEnd();

    // Grass
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.0f); 
        glVertex2f(-1.0f, -1.0f); 
        glVertex2f(1.0f, -1.0f);  
        glVertex2f(1.0f, -0.85f); 
        glVertex2f(-1.0f, -0.85f); 
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawSun();
    drawCloud(-0.8f, 0.75f);
    drawCloud(-0.4f, 0.8f);
    drawCloud(0.1f, 0.75f);
    drawCloud(0.6f, 0.7f);


    drawhouse();

    glFlush();
}

void init() {
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f); // Light blue sky
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Scene: House, Clouds,Sun");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
