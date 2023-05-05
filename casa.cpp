#include <GL/freeglut.h>
#include <GL/gl.h>

void desenhaMinhaCasa()
{
    glClearColor(0.0, 0.7, 0.9, 0.0); //fundo
    glClear(GL_COLOR_BUFFER_BIT);
    
    //chão marrom
    glColor3f(0.6, 0.2, 0.1); 
    glBegin(GL_QUADS);
        glVertex2f(-1.0, -1.0);
        glVertex2f(-1.0, -0.6);
        glVertex2f(1.0, -0.6);
        glVertex2f(1.0, -1.0);
    glEnd();

    //grama
    glColor3f(0.0, 0.5, 0.2); 
    glBegin(GL_QUADS);
        glVertex2f(-1.0, -0.6);
        glVertex2f(-1.0, -0.5);
        glVertex2f(1.0, -0.5);
        glVertex2f(1.0, -0.6);
    glEnd();

    //nuvem 1
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2f(0.78, 0.54);
        glVertex2f(0.78, 0.57);
        glVertex2f(0.86, 0.57);
        glVertex2f(0.86, 0.59);
        glVertex2f(0.9, 0.59);
        glVertex2f(0.9, 0.57);
        glVertex2f(0.92, 0.57);
        glVertex2f(0.92, 0.54); 
    glEnd();

    //nuvem 2
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2f(-0.74, 0.54);
        glVertex2f(-0.74, 0.57);
        glVertex2f(-0.8, 0.57);
        glVertex2f(-0.8, 0.59);
        glVertex2f(-0.86, 0.59);
        glVertex2f(-0.86, 0.57);
        glVertex2f(-0.88, 0.57);
        glVertex2f(-0.88, 0.54); 
    glEnd();

    //nuvem 3
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2f(-0.34, 0.74);
        glVertex2f(-0.34, 0.77);
        glVertex2f(-0.4, 0.77);
        glVertex2f(-0.4, 0.79);
        glVertex2f(-0.46, 0.79);
        glVertex2f(-0.46, 0.77);
        glVertex2f(-0.48, 0.77);
        glVertex2f(-0.48, 0.74); 
    glEnd();

    //nuvem 4
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2f(-0.04, 0.44);
        glVertex2f(-0.04, 0.47);
        glVertex2f(-0.1, 0.47);
        glVertex2f(-0.1, 0.49);
        glVertex2f(-0.16, 0.49);
        glVertex2f(-0.16, 0.47);
        glVertex2f(-0.18, 0.47);
        glVertex2f(-0.18, 0.44); 
    glEnd();

    //nuvem 5
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2f(0.2, 0.79);
        glVertex2f(0.2, 0.82);
        glVertex2f(0.26, 0.82);
        glVertex2f(0.26, 0.84);
        glVertex2f(0.32, 0.84);
        glVertex2f(0.32, 0.82);
        glVertex2f(0.38, 0.82);
        glVertex2f(0.38, 0.79); 
    glEnd();
    
    //base da casa
    glColor3f(0.66, 0.66, 0.66); 
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.0);
        glVertex2f(0.8, 0.0);
        glVertex2f(0.8, -0.5);
    glEnd();

    //2° andar
    glColor3f(0.66, 0.66, 0.66); 
    glBegin(GL_QUADS);
        glVertex2f(-0.1, 0.05);
        glVertex2f(-0.1, 0.55);
        glVertex2f(0.8, 0.55);
        glVertex2f(0.8, 0.05);
    glEnd();

    //sacada
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(-0.8, 0.0);
        glVertex2f(-0.8, 0.05);
        glVertex2f(0.8, 0.05);
        glVertex2f(0.8, 0.0);
    glEnd();

    //telhado
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.4, 0.55);
        glVertex2f(0.85, 0.65);
        glVertex2f(0.85, 0.55);
    glEnd();

    //grade 1
    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(-0.65, 0.2);
        glVertex2f(-0.6, 0.2);
        glVertex2f(-0.6, 0.05);
        glVertex2f(-0.65, 0.05);
    glEnd();

    //grade 2
    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(-0.4, 0.2);
        glVertex2f(-0.45, 0.2);
        glVertex2f(-0.45, 0.05);
        glVertex2f(-0.4, 0.05);
    glEnd();

    //grade 3
    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(-0.2, 0.2);
        glVertex2f(-0.25, 0.2);
        glVertex2f(-0.25, 0.05);
        glVertex2f(-0.2, 0.05);
    glEnd();

    //grade 4
    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(-0.1, 0.2);
        glVertex2f(-0.8, 0.2);
        glVertex2f(-0.8, 0.25);
        glVertex2f(-0.1, 0.25);
    glEnd();

    //porta
    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(0.0, -0.1);
        glVertex2f(-0.3, -0.1);
        glVertex2f(-0.3, -0.5);
        glVertex2f(0.0, -0.5);
    glEnd();

    //maçaneta
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(-0.25, -0.3);
        glVertex2f(-0.23, -0.3);
        glVertex2f(-0.23, -0.32);
        glVertex2f(-0.25, -0.32);
    glEnd();

    //janela1
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(0.2, -0.1);
        glVertex2f(0.2, -0.3);
        glVertex2f(0.6, -0.3);
        glVertex2f(0.6, -0.1);
    glEnd();

    //janela2
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.2, 0.4);
        glVertex2f(0.6, 0.4);
        glVertex2f(0.6, 0.2);
    glEnd();

    //grade janela1
    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(0.395, -0.1);
        glVertex2f(0.395, -0.3);
        glVertex2f(0.41, -0.3);
        glVertex2f(0.41, -0.1);
    glEnd();

    //grade anela2
    glColor3f(0.8, 0.0, 0.0); 
    glBegin(GL_QUADS);
        glVertex2f(0.395, 0.2);
        glVertex2f(0.395, 0.4);
        glVertex2f(0.41, 0.4);
        glVertex2f(0.41, 0.2);
    glEnd();

    

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Casa de Ester Morais");
    glutDisplayFunc(desenhaMinhaCasa);
    glutMainLoop();    
    return 0;
}