#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Display {
public:
    GLFWwindow* window = NULL;
    unsigned int width;
    unsigned int height;

    bool setup() {
        if (!glfwInit()) {
            std::cerr << "Unable to initialize GLFW!" << std::endl;
            cleanup();
            return false;
        }

        glfwSetErrorCallback(error_callback);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(800, 600, "GLFW Window", NULL, NULL);
        if (window == NULL) {
            std::cerr << "Unable to create window!" << std::endl;
            cleanup();
            return false;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD!" << std::endl;
            cleanup();
            return false;
        }

        glViewport(0, 0, 800, 600);

        width = 800;
        height = 600;

        return true;
    }

    void update() {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    bool isWindowClosed() {
        return window == NULL ? true : glfwWindowShouldClose(window);
    }

    void cleanup() {
        if (window) {
            glfwDestroyWindow(window);
            window = NULL;
        }
        glfwTerminate();
    }

    static void error_callback(int error, const char* description) {
        std::cerr << "An error (" << error << ") occurred!\n" << description << std::endl;
    }
};

int main(int, char**) {
    Display display;
    if (!display.setup()) {
        std::cerr << "Unable to setup display!" << std::endl;
        display.cleanup();
        return -1;
    }

    // other OpenGL stuff would go here

    // while (!display.isWindowClosed()) {
    //     glClearColor(0.25f, 0.1f, 0.25f, 1.0f);
    //     glClear(GL_COLOR_BUFFER_BIT);

    //     // drawing logic...

    //     display.update();
    // }

    display.cleanup();

    return 0;
}