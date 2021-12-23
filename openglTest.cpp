#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <cmath>
#include <cstdlib>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    window.setVerticalSyncEnabled(true);
    glEnable(GL_TEXTURE_2D);
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-10,10);
    glViewport(0, 0, 500, 500);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    GLfloat vertex[5][2] = {
        {-1,6},
        {1,6},
        {1,-5},
        {-1,-5},
        {-8,0}
    };
    GLfloat colorArray[5][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1},
        {1,1,0},
        {0,1,1}
    };
    GLubyte triangleIndexArray[3] = {0,1,2};
    GLubyte quadIndexArray[4] = { 0,2,3,4 };
    GLubyte lineIndexArray[6] = { 0,1,2,3,4,0 };
    GLubyte triangleArray2[3][3] = {
        {1,4,0},{4,1,2},{2,3,4}
    };
   /* GLuint cubeVertexArray[8][3] = {
        -1,-1,-1,
        -1,-1,1,
        -1,1,-1,
        -1,1,1,
        1,-1,-1,
        1,-1,1,
        1,1,-1,
        1,1,1
    };
    GLuint cubeIndexArray[6][3] = {
        1,5,7,3,
        5,4,6,7,
        4,0,2,6,
        3,2,0,1,
        3,7,
    };*/
    glVertexPointer(2, GL_FLOAT, 0, vertex);
    glColorPointer(3, GL_FLOAT, 0, colorArray);
    bool wire = false;
    while (window.isOpen())
    {
        sf::Event event;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Left:
                    glTranslatef(-1, 0, 0);
                    break;
                case sf::Keyboard::Right:
                    glTranslatef(1, 0, 0);
                    break;
                case sf::Keyboard::Up:
                    glTranslatef(0, 1, 0);
                    break;
                case sf::Keyboard::Down:
                    glTranslatef(0, -1, 0);
                    break;
                case sf::Keyboard::Add:
                    glScalef(1.1, 1.1, 1.1);
                    break;
                case sf::Keyboard::Subtract:
                    glScalef(1.0 / 1.1, 1 / 1.1, 1 / 1.1);
                    break;
                case sf::Keyboard::Q:
                    glRotatef(10, 0, 0, 1);
                    break;
                case sf::Keyboard::E:
                    glRotatef(-10, 0, 0, 1);                    
                    break;
                case sf::Keyboard::W:
                    glRotatef(10, 0, 1, 0);
                    break;
                case sf::Keyboard::S:
                    glRotatef(-10, 0, 1, 0);
                    break;
                case sf::Keyboard::Space:
                    wire = !wire;
                    break;

                default:
                    break;
                }
            }
        }
        
        if(wire)
            glDrawElements(GL_LINE_STRIP, 6, GL_UNSIGNED_BYTE, lineIndexArray);
        else
            glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_BYTE, triangleArray2);
            
        window.display();
    }

    return 0;
}