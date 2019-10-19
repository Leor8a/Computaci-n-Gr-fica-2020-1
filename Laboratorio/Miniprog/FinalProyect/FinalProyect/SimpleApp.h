//
//  SimpleApp.h
//  FinalProyect
//
//  Created by Luis Ernesto Ochoa Rios on 10/19/19.
//  Copyright © 2019 Luis Ernesto Ochoa Rios. All rights reserved.
//
#include<iostream>
#include<vector>
#include<string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#ifndef SimpleApp_h
#define SimpleApp_h

class SimpleApp{
public:
    static const int WINDOW_WIDTH = 1024;
    static const int WINDOW_HEIGHT = 768;
    
    SimpleApp();
    ~SimpleApp();
    
    bool init();
    //void resize(int x, int y);
    void prepare();
    void render();
   

//private:
    
    
};

#endif /* SimpleApp_h */
