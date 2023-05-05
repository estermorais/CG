#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>

#define velocidade 1

GLuint idTexturaAviao;
// GLuint cubeDL;
GLdouble ox=0.0,oy=0.0,oz=0.0;

int aux = 0;
int aux2 = 0;
int aux3 = 0;
int aux4 = 0;
float razaoAspecto;
float mousex;
float mousey;
int posicao[4] = {0, 0, 0, 0}; // FRENTE, ATRÁS, ESQUERDA, DIREITA
int desenhaQuadradoAtivo = 0;
int desenhaCirculoAtivo = 0;

typedef struct
{

    float x;
    float y;
    float velx;
    float vely;

} aviao_struct;

aviao_struct aviao;

void inicializa_struct()
{
    aviao.x = 0;
    aviao.y = -70;
}

void redimensiona(int width, int height)
{

    razaoAspecto = (float)glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100 * razaoAspecto, 100 * razaoAspecto, -100, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void teclado(unsigned char key, int x, int y)
{

    switch (key)
    {

    case (27):

        exit(0);

    case ('w'):

        if (posicao[0] == 1)
            posicao[0] = 0;
        else
            posicao[0] = 1;

        aux4 = 0;

        break;

    case ('a'):

        if (posicao[2] == 1)
            posicao[2] = 0;
        else
            posicao[2] = 1;

        aux = 0;

        break;

    case ('s'):

        if (posicao[1] == 1)
            posicao[1] = 0;
        else
            posicao[1] = 1;

        aux3 = 0;

        break;

    case ('d'):

        if (posicao[3] == 1)
            posicao[3] = 0;
        else
            posicao[3] = 1;

        aux2 = 0;

        break;

    case ('W'):

        if (posicao[0] == 1)
            posicao[0] = 0;
        else
            posicao[0] = 1;

        aux4 = 0;

        break;

    case ('A'):

        if (posicao[2] == 1)
            posicao[2] = 0;
        else
            posicao[2] = 1;

        aux = 0;

        break;

    case ('S'):

        if (posicao[1] == 1)
            posicao[1] = 0;
        else
            posicao[1] = 1;

        aux3 = 0;

        break;

    case ('D'):

        if (posicao[3] == 1)
            posicao[3] = 0;
        else
            posicao[3] = 1;

        aux2 = 0;

        break;
    }
}

void movimento()
{
    aviao.x += (posicao[3] - posicao[2]) * (velocidade + 0.5);
    aviao.y += (posicao[0] - posicao[1]) * (velocidade + 0.5);

    if (aviao.y >= 100 - 30)
    {
        aviao.y = 100 - 30;
    }

    if (aviao.y <= -100 + 30)
    {
        aviao.y = -100 + 30;
    }

    if (aviao.x <= (-100 * razaoAspecto) + 30)
    {
        aviao.x = -100 * razaoAspecto + 30;
    }

    if (aviao.x >= (100 * razaoAspecto) - 30)
    {
        aviao.x = 100 * razaoAspecto - 30;
    }
}

GLuint carregaTextura(const char *arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
        arquivo,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y);

    if (idTextura == 0)
    {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

void inicializa()
{
    glClearColor(0.0, 0.7, 0.9, 0.0); // fundo

    // habilita mesclagem de cores, para termos suporte a texturas com transparência
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaAviao = carregaTextura("avioes.png");
}

void desenhaAviao()
{
    glColor3f(1, 1, 1);

    // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);

    // Começa a usar a textura
    glBindTexture(GL_TEXTURE_2D, idTexturaAviao);
    glBegin(GL_TRIANGLE_FAN);

    // Associamos um canto da textura para cada vértice

    // Posição inicial
    // Nenhuma tecla sendo apertada
    if (posicao[0] == 0 && posicao[1] == 0 && posicao[2] == 0 && posicao[3] == 0)
    {

        glTexCoord2f(0.6, 0.4);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0.4);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.6);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.6);
        glVertex2f(-30, 30);
    }

    // Clicando 'w' e 's'
    if (posicao[0] == 1 && posicao[1] == 1 && posicao[2] == 0 && posicao[3] == 0)
    {

        glTexCoord2f(0.6, 0.4);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0.4);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.6);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.6);
        glVertex2f(-30, 30);
    }

    // Clicando 'a' e 'd'
    if (posicao[0] == 0 && posicao[1] == 0 && posicao[2] == 1 && posicao[3] == 1)
    {

        glTexCoord2f(0.6, 0.4);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0.4);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.6);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.6);
        glVertex2f(-30, 30);
    }

    // Clicando 'a' e 's' e 'd' e 'w'
    if (posicao[0] == 1 && posicao[1] == 1 && posicao[2] == 1 && posicao[3] == 1)
    {

        glTexCoord2f(0.6, 0);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.2);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.2);
        glVertex2f(-30, 30);
    }

    // Posição frente
    // Clicando 'w'
    if (aux3 < 20 && posicao[0] == 1 && posicao[1] == 0 && posicao[2] == 0 && posicao[3] == 0)
    {

        glTexCoord2f(0.6, 0.4);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0.4);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.6);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.6);
        glVertex2f(-30, 30);

        aux3++;
    }

    // Posição frente
    // Clicando 'w'
    if (aux3 >= 20 && aux3 < 40 && posicao[0] == 1 && posicao[1] == 0 && posicao[2] == 0 && posicao[3] == 0)
    {

        glTexCoord2f(0.6, 0.6);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0.6);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.8);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.8);
        glVertex2f(-30, 30);

        aux3++;
    }

    // Posição frente
    // Clicando 'w'
    if (aux3 >= 40 && posicao[0] == 1 && posicao[1] == 0 && posicao[2] == 0 && posicao[3] == 0)
    {

        glTexCoord2f(0.6, 0.8);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0.8);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 1);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 1);
        glVertex2f(-30, 30);

        aux3++;
    }

    // Posição atrás
    // Clicando 's'
    if (aux4 < 20 && posicao[1] == 1 && posicao[0] == 0 && posicao[2] == 0 && posicao[3] == 0)
    {

        glTexCoord2f(0.6, 0.2);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0.2);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.4);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.4);
        glVertex2f(-30, 30);

        aux4++;
    }

    // Posição atrás
    // Clicando 's'
    if (aux4 >= 20 && aux4 < 40 && posicao[1] == 1 && posicao[0] == 0 && posicao[2] == 0 && posicao[3] == 0)
    {

        glTexCoord2f(0.6, 0);
        glVertex2f(-30, -30);

        glTexCoord2f(0.4, 0);
        glVertex2f(30, -30);

        glTexCoord2f(0.4, 0.2);
        glVertex2f(30, 30);

        glTexCoord2f(0.6, 0.2);
        glVertex2f(-30, 30);
    }

    // Posição direita 1
    // Clicando 'd' ou clicando 'd' e 'w' ou clicando 'd' e 's'
    if ((posicao[3] == 1 && aux < 10 && posicao[1] == 0 && posicao[0] == 0 && posicao[2] == 0) || (aux < 10 && posicao[3] == 1 && posicao[0] == 1) || (aux < 10 && posicao[3] == 1 && posicao[1] == 1))
    {

        glTexCoord2f(0.4, 0);
        glVertex2f(-30, -30);

        glTexCoord2f(0.2, 0);
        glVertex2f(30, -30);

        glTexCoord2f(0.2, 0.2);
        glVertex2f(30, 30);

        glTexCoord2f(0.4, 0.2);
        glVertex2f(-30, 30);

        aux++;
    }

    // Posição direita 2
    // Clicando 'd' ou clicando 'd' e 'w' ou clicando 'd' e 's'
    if ((posicao[3] == 1 && aux >= 10 && posicao[1] == 0 && posicao[0] == 0 && posicao[2] == 0) || (aux >= 10 && posicao[3] == 1 && posicao[0] == 1) || (aux >= 10 && posicao[3] == 1 && posicao[1] == 1))
    {

        glTexCoord2f(0.2, 0);
        glVertex2f(-30, -30);

        glTexCoord2f(0, 0);
        glVertex2f(30, -30);

        glTexCoord2f(0, 0.2);
        glVertex2f(30, 30);

        glTexCoord2f(0.2, 0.2);
        glVertex2f(-30, 30);
    }

    // Posição esquerda 1
    // Clicando 'a' ou clicando 'a' e 'w' ou clicando 'a' e 's'
    if ((posicao[2] == 1 && aux2 < 10 && posicao[1] == 0 && posicao[0] == 0 && posicao[3] == 0) || (aux2 < 10 && posicao[2] == 1 && posicao[0] == 1) || (aux2 < 10 && posicao[2] == 1 && posicao[1] == 1))
    {

        glTexCoord2f(0.8, 0);
        glVertex2f(-30, -30);

        glTexCoord2f(0.6, 0);
        glVertex2f(30, -30);

        glTexCoord2f(0.6, 0.2);
        glVertex2f(30, 30);

        glTexCoord2f(0.8, 0.2);
        glVertex2f(-30, 30);

        aux2++;
    }

    // Posição esquerda 2
    // Clicando 'a' ou clicando 'a' e 'w' ou clicando 'a' e 's'
    if ((posicao[2] == 1 && aux2 >= 10 && posicao[1] == 0 && posicao[0] == 0 && posicao[3] == 0) || (aux2 >= 10 && posicao[2] == 1 && posicao[0] == 1) || (aux2 >= 10 && posicao[2] == 1 && posicao[1] == 1))
    {

        glTexCoord2f(1, 0);
        glVertex2f(-30, -30);

        glTexCoord2f(0.8, 0);
        glVertex2f(30, -30);

        glTexCoord2f(0.8, 0.2);
        glVertex2f(30, 30);

        glTexCoord2f(1, 0.2);
        glVertex2f(-30, 30);
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void desenhaTexto(void *fonte, char *texto, float x, float y)
{
    glRasterPos2f(x, y);

    for (int i = 0; i < strlen(texto); i++)
    {
        glutBitmapCharacter(fonte, texto[i]);
    }
}

void desenhaMeuFundo()
{
    // cubeDL = glGenLists(1);
    // glNewList(cubeDL, GL_COMPILE);

    // grama 1
    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-100, -100, 0);
    glVertex3f(-100, 60, 0);
    glVertex3f(-55, 60, 0);
    glVertex3f(-55, -100, 0);
    glEnd();

    // grama 2
    glColor3f(0.5, 0.8, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(100, -100, 0);
    glVertex3f(100, 60, 0);
    glVertex3f(55, 60, 0);
    glVertex3f(55, -100, 0);
    glEnd();

    // grama 3
    glColor3f(0.2, 0.6, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(-55, -100, 0);
    glVertex3f(-55, 60, 0);
    glVertex3f(-50, 60, 0);
    glVertex3f(-50, -100, 0);
    glEnd();

    // grama 4
    glColor3f(0.2, 0.6, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(55, -100, 0);
    glVertex3f(55, 60, 0);
    glVertex3f(50, 60, 0);
    glVertex3f(50, -100, 0);
    glEnd();

    // faixa 1
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-50, -100, 0);
    glVertex3f(-50, 60, 0);
    glVertex3f(-42, 60, 0);
    glVertex3f(-42, -100, 0);
    glEnd();

    // faixa 2
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(50, -100, 0);
    glVertex3f(50, 60, 0);
    glVertex3f(42, 60, 0);
    glVertex3f(42, -100, 0);
    glEnd();

    // faixa 3
    glColor3f(0.7, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(-42, -100, 0);
    glVertex3f(-42, 60, 0);
    glVertex3f(-40, 60, 0);
    glVertex3f(-40, -100, 0);
    glEnd();

    // faixa 4
    glColor3f(0.7, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(42, -100, 0);
    glVertex3f(42, 60, 0);
    glVertex3f(40, 60, 0);
    glVertex3f(40, -100, 0);
    glEnd();

    // asfalto
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(-40, -100, 0);
    glVertex3f(-40, 60, 0);
    glVertex3f(40, 60, 0);
    glVertex3f(40, -100, 0);
    glEnd();

    // pontilhado 1
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-5, 30, 0);
    glVertex3f(-5, 50, 0);
    glVertex3f(5, 50, 0);
    glVertex3f(5, 30, 0);
    glEnd();

    // pontilhado 2
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-5, 0, 0);
    glVertex3f(-5, 20, 0);
    glVertex3f(5, 20, 0);
    glVertex3f(5, 0, 0);
    glEnd();

    // pontilhado 3
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-5, -30, 0);
    glVertex3f(-5, -10, 0);
    glVertex3f(5, -10, 0);
    glVertex3f(5, -30, 0);
    glEnd();

    // pontilhado 4
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-5, -60, 0);
    glVertex3f(-5, -40, 0);
    glVertex3f(5, -40, 0);
    glVertex3f(5, -60, 0);
    glEnd();

    // pontilhado 5
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-5, -90, 0);
    glVertex3f(-5, -70, 0);
    glVertex3f(5, -70, 0);
    glVertex3f(5, -90, 0);
    glEnd();

    desenhaTexto(GLUT_BITMAP_TIMES_ROMAN_24, "Ester Morais Neves", -35, 90);

    // glEndList();
}

/*void display() {

  glCallList(cubeDL);// Chamando a display list
  glutSwapBuffers();// Atualizando a tela
}*/

void desenhaQuadrado()
{

    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex2f(mousex - 50, mousey - 50);
    glVertex2f(mousex + 50, mousey + 50);
    glVertex2f(mousex + 50, mousey - 50);
    glVertex2f(mousex - 50, mousey + 50);
    glEnd();

}

void desenhaCirculo()
{

    float angulo;

    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(mousex, mousey);
    for (int i = 0; i <= 100; ++i)
    {
        angulo = 2 * 3.1415 * i / 100;
        glVertex2f(mousex + cos(angulo) * 100, mousey + sin(angulo));
    }
    glEnd();

}

void mouse(int button, int state, int x, int y)
{

    GLint viewport[4];
    GLdouble modelview[16], projection[16];
    GLfloat wx = x, wy, wz;

    glGetIntegerv(GL_VIEWPORT, viewport);
    y = viewport[3] - y;
    wy = y;
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glReadPixels(x, y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &wz);
    gluUnProject(wx, wy, wz, modelview, projection, viewport, &ox, &oy, &oz);

    mousex = ox;
    mousey = oy;
    

    if (button == GLUT_LEFT_BUTTON)
    {

        if (state == GLUT_DOWN)
        {
            desenhaQuadrado();
            glutSwapBuffers();

        }
        if (state == GLUT_UP)
        {
            return;
        }
    }

    if (button == GLUT_RIGHT_BUTTON)
    {

        if (state == GLUT_DOWN)
        {
            desenhaCirculo();
            glutSwapBuffers();
        }
        if (state == GLUT_UP)
        {
            return;
        }
    }

    /*if (desenhaQuadradoAtivo)
    {
        desenhaQuadrado(ox, oy);
        glutSwapBuffers();
    }

    if (desenhaCirculoAtivo)
    {

        desenhaCirculo(ox, oy);
        glutSwapBuffers();
    }*/

    glutPostRedisplay();
}


void cenario()
{

    glClear(GL_COLOR_BUFFER_BIT);
    desenhaMeuFundo(); // Inicializando o OpenGL e criando a display list
    // glutDisplayFunc(display);// Registrando a função de exibição
    glPushMatrix();
    glTranslatef(aviao.x, aviao.y, 1);
    desenhaAviao();
    glPopMatrix();
    glutSwapBuffers();
}

void timer()
{

    movimento();
    glutPostRedisplay();

    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 100);

    glutCreateWindow("Ester Morais");
    inicializa_struct();
    inicializa();

    glutDisplayFunc(cenario);
    glutReshapeFunc(redimensiona);
    glutMouseFunc(mouse);

    glutKeyboardFunc(teclado); // Faz o movimento pelas teclas
    glutKeyboardUpFunc(teclado);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();

    return 0;
}