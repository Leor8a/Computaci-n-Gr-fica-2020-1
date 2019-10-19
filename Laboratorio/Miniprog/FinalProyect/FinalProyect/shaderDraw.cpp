//
//  mainFirst.cpp
//  FinalProyect
//
//  Created by Luis Ernesto Ochoa Rios on 10/19/19.
//  Copyright © 2019 Luis Ernesto Ochoa Rios. All rights reserved.
//
#include"SimpleApp.h"
#include "Shader.h"

SimpleApp myApp;

// General Function
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main (int argc, char** argv)
{
    //Initialize GLFW
    glfwInit();
    
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    
    //Creation of the GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window;
    
    window = glfwCreateWindow(SimpleApp::WINDOW_WIDTH, SimpleApp::WINDOW_HEIGHT, "Learn OpenGL", nullptr, nullptr);
    int screenWidth, screenHeight;
    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        
        return -1;
    }
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    //Prints current OpenGL Version
    std::cout << glGetString(GL_VERSION) << std::endl;
    glewExperimental = GL_TRUE;
    
    if (GLEW_OK != glewInit()){
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    
    glViewport(0, 0, screenWidth, screenHeight);   
    
    Shader ourShader("resources/shaders/core.vs", "resources/shaders/core.frag");
    
    GLfloat vertices[] =
    {
        //position              // color
        -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,//bottom left
        0.5f, -0.5f, 0.0f,      0.0f, 1.0f, 0.0f,// bottom right
        0.0f, 0.5f, 0.0f,       0.0f, 0.0f, 1.0f  // middle top
    };
    GLuint VBO, VAO;
    
    //use of arrays fragment and vertex
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT ,GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) 0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT ,GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    
    
    //GAMELOOP
    while(!glfwWindowShouldClose(window))
    {
        // Check if any events have been activated
        // (Key pressed, mouse moved, etc.) and
        // call corresponding response function.
        glfwPollEvents();
        
        myApp.render();
        ourShader.Use();
        glBindVertexArray(VAO);
        // Shader drawing
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
    }
    
    //myApp.deleteArrays();
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    //glViewport(0, 0, width, height);
    //myApp.resize();
    
    //Prevent a divide by zero error
    if (height <= 0){
        height = 1;
    }
    
    //When we resize the window we tell OpenGL about the new viewport size
    glViewport( 0, 0, (GLsizei)width, (GLsizei)height);
    myApp.render();
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    //Then we setup our projection matrix with the correct aspect ratio
    glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);
    
    glMatrixMode(GL_MODELVIEW); // Select Modelview Matrix
    glLoadIdentity();
}
