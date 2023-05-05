#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

void desenhaMinhaCena()
{
    glClearColor(0.8, 0.0, 0.4, 0.0); //fundo
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

void redimencionandoTela(int x, int y){

    //printando no terminal a nova largura e altura da janela

    std::cout << "Largura da janela: " << x << std::endl;
    std::cout << "Altura da janela: " << y << std::endl;
    std::cout << "\n";

}

void pressionamentoTecla(unsigned char key, int x, int y){

    //printando no terminal qual tecla foi pressionada e em qual posição o mouse estava no momento da ação

    std::cout << "Tecla pressionada:" << key << std::endl;
    std::cout << "Posição do mouse na tela em x = " << x << std::endl;
    std::cout << "Posição do mouse na tela em y = " << y << std::endl;
    std::cout << "\n";
    

}

void cliqueMouse(int button, int state, int x, int y){

    
    //analisando qual botão foi pressionado e printando no terminal

    if(state == GLUT_DOWN){

        if(button == GLUT_LEFT_BUTTON)

            std::cout << "O botão esquedo do mouse foi pressionado"<< std::endl;

        if(button == GLUT_RIGHT_BUTTON)

            std::cout << "O botão direito do mouse foi pressionado"<< std::endl;

        if(button == GLUT_MIDDLE_BUTTON)

            std::cout << "O botão do meio do mouse foi pressionado"<< std::endl;
    }

    //analisando qual botão foi solto e printando no terminal

    if(state == GLUT_UP){

        if(button == GLUT_LEFT_BUTTON)

            std::cout << "O botão esquedo do mouse foi solto"<< std::endl;

        if(button == GLUT_RIGHT_BUTTON)

            std::cout << "O botão direito do mouse foi solto"<< std::endl;

        if(button == GLUT_MIDDLE_BUTTON)

            std::cout << "O botão do meio do mouse foi solto"<< std::endl;
    }

    //printando no terminal qual a posição do mouse 
    
    std::cout << "Posição do mouse na tela em x = " << x << std::endl;
    std::cout << "Posição do mouse na tela em y = " << y << std::endl;
    std::cout << "\n";


}

void movimentoMouse(int x, int y){

    //printando no terminal qual a posição do mouse 

    std::cout << "Posição do mouse na tela em x = " << x << std::endl;
    std::cout << "Posição do mouse na tela em y = " << y << std::endl;
    std::cout << "\n";

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500); //determinando o tamanho da janela
    glutInitWindowPosition(600,300); //determinando onde a janela será aberta
    glutCreateWindow("Testando Callbacks"); //título da janela
    glutDisplayFunc(desenhaMinhaCena); //colorindo o fundo de rosa
    glutReshapeFunc(redimencionandoTela); //determinando o tamanho da janela
    glutKeyboardFunc(pressionamentoTecla); //determinando qual tecla foi pressionado em qual posição o mouse estava no momento da ação
    glutMouseFunc(cliqueMouse); //determinando qual botão do mouse foi pressionado/solto e qual posição o mouse estava no momento da ação
    glutPassiveMotionFunc(movimentoMouse); //determinando qual a posição do mouse 
    glutMainLoop(); //entregando tudo para a glut
    return 0;

    //OBSERVAÇÃO: vale destacar que a origem do plano cartesiano da tela do computador é no canto superior esquerdo, onde x cresce para a direita e y para baixo
    //Por esse motivo, as coordenas de x e y assumem valores tão grandes
}