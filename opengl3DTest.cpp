#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

    GLfloat cubeColor[8][3]={
        1,0,0,
        0,1,0,
        0,0,1,
        1,1,0,
        0,1,1,
        1,0,1,
        0.5,0.5,0.5,
        1,1,1,
    };
    GLfloat pyramidColor[10][3] ={
        1,1,1,
        1,1,0,
        1,0,0,
        1,0,1,
        0,1,1,
        0,1,0,
        0,0,1,
        1,1,0.5,
        0.5,1,1
    };
    GLint cubeVertex[8][3]={
        -1,-1,-1,
        -1,-1,1,
        -1,1,-1,
        -1,1,1,
        1,-1,-1,
        1,-1,1,
        1,1,-1,
        1,1,1
    };
    GLuint cubeFace[6][4]={
        1,5,7,3,
        5,4,6,7,
        4,0,2,6,
        3,2,0,1,
        3,7,6,2,
        4,5,1,0
    };

    GLfloat pyramidVertex[7][3];
    GLuint pyramidFaces[10][3];
    pyramidVertex[0][0]=0;
    pyramidVertex[0][1]=1;
    pyramidVertex[0][2]=0;
    for(int i=0;i<6;i++){
        pyramidVertex[i+1][0]=cos(2*3.1415/6*i);
        pyramidVertex[i+1][2]=sin(2*3.1415/6*i);
        pyramidVertex[i+1][1]=0;    
        std::cout << pyramidVertex[i+1][0]<<' '<<pyramidVertex[i+1][1]<<' ' << pyramidVertex[i+1][2]<<std::endl;
    }
    for(int i=1;i<=6;i++){
        pyramidFaces[i-1][1]=i;
        pyramidFaces[i-1][2]=i%6+1;
        pyramidFaces[i-1][0]=0;
        std::cout << pyramidFaces[i-1][0] <<' '<<pyramidFaces[i-1][1] << ' '<< pyramidFaces[i-1][2]<<std::endl;
    }
    for(int i=1;i<6;i+=2){
        pyramidFaces[6+i/2][2]=i;
        pyramidFaces[6+i/2][1]=i%6+1;
        pyramidFaces[6+i/2][0]=(i+1)%6+1;
        std::cout << pyramidFaces[5+i/2][0] <<' '<<pyramidFaces[5+i/2][1] << ' '<< pyramidFaces[5+i/2][2]<<std::endl;

    }
   

    pyramidFaces[9][0]=5;
    pyramidFaces[9][1]=3;
    pyramidFaces[9][2]=1;


    window.setVerticalSyncEnabled(true);
    glEnable(GL_TEXTURE_3D);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-10,10,-10,10,-10,10);
    glViewport(0,0,500,500);
    glShadeModel(GL_FLAT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_CULL_FACE);


    while (window.isOpen())
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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
                case sf::Keyboard::A:
                    glRotatef(10, 1, 0, 0);
                    break;
                case sf::Keyboard::D:
                    glRotatef(-10, 1, 0, 0);
                    break;
                default:
                    break;
                }
            }
        }
        glPushMatrix();
        glTranslatef(1,0,0);
        glScalef(0.8,0.8,0.8);
        glColorPointer(3,GL_FLOAT,0,cubeColor);
        glVertexPointer(3,GL_INT,0,cubeVertex);
            
        glDrawElements(GL_QUADS,24,GL_UNSIGNED_INT,cubeFace);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1,0,0);
        glScalef(0.8,0.8,0.8);
        glColorPointer(3,GL_FLOAT,0,pyramidColor);
        glVertexPointer(3,GL_FLOAT,0,pyramidVertex);
        glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_INT,pyramidFaces);
        glPopMatrix();
        window.display();
    }

} 
