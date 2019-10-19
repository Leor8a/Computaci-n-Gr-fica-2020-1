//
//  SimpleApp.cpp
//  FinalProyect
//
//  Created by Luis Ernesto Ochoa Rios on 10/19/19.
//  Copyright © 2019 Luis Ernesto Ochoa Rios. All rights reserved.
//

#include "SimpleApp.h"

SimpleApp::SimpleApp(){
 
}
SimpleApp::~SimpleApp(){
    
}

bool SimpleApp::init()
{
    //Enable depth testing
    glEnable(GL_DEPTH_TEST);
    
    return true;
}

void SimpleApp::render()
{
    //Render, clear the color buffer
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    
    glLoadIdentity();
    
}

//void SimpleApp::deleteArrays(){
    //glDeleteVertexArrays(1, &VAO);
    //glDeleteBuffers(1, &VBO);
//}
