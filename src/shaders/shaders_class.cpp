#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

#include "shader.h"
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // REQUIRED for lINUX!

    GLFWwindow* window = glfwCreateWindow(800, 600, "Learnn", NULL, NULL);
    if (window == NULL){
        const char* description;
        int code = glfwGetError(&description);
        std::cout << "Failed to create GLFW window. Error (" << code << "): " << description << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader ((GLADloadproc)glfwGetProcAddress)){
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    // ----------------------------------------------
    // build and compile our shader program

    // ---- Shader class ----
    Shader ourShader("shader2.vs", "shader2.fs");

    //-----------------------------------------------------------

    // set up vertex data and configure vertex attributes
    float vertices[] = {
        0.5f,  -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,  // bottom right (red)
        -0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,  // bottom left (green)
        0.0f, 0.5f, 0.0f,       0.0f, 0.0f, 1.0f    // top (blue)
    };


    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind vao, bind and set vertex buffers -> configure vertex attributes
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    // glBindBuffer(GL_ARRAY_BUFFER, 0);

    // glBindBuffer(GL_ELELEMT_ARRAY_BUFhFER, 0);


    //glBindVertexArray(0);

    // for wireframe
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    


    // render loop
    while (!glfwWindowShouldClose(window)){
        processInput(window);

        // clear
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // activate program
        ourShader.use();

        // update xposition to right
        float offset = 0.3f;
        ourShader.setFloat("xoffset", offset);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glBindVertexArray(0);

        // swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Deallocate all resoures
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    
    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
