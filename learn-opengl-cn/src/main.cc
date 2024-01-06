#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
    /***
     * GLFW是一个专门针对OpenGL的C语言库，它提供了一些渲染物体所需的最低限度的接口。它允许用户创建OpenGL上下文、定义窗口参数以及处理用户输入。
    */
    glfwInit();                                                         // 初始化GLFW
    /**
     * 配置GLFW,主版本号和次版本号都设为3,同时明确告诉GLFW我们使用的是核心模式(Core-profile)
    */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                      
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);  // 创建窗口, 这个窗口对象存放了所有和窗口相关的数据，而且会被GLFW的其他函数频繁地用到
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    /**
     * 因为OpenGL只是一个标准/规范，具体的实现是由驱动开发商针对特定显卡实现的。由于OpenGL驱动版本众多，
     * 它大多数函数的位置都无法在编译时确定下来，需要在运行时查询。所以任务就落在了开发者身上，开发者需要
     * 在运行时获取函数地址并将其保存在一个函数指针中供以后使用。而这个过程繁琐复杂，GLAD是一个开源的库,
     * 它能简化这个过程。它用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化GLAD。
    */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    /**
     * 开始渲染之前还有一件重要的事情要做，必须告诉OpenGL渲染窗口的尺寸大小，即视口(Viewport)，
     * 这样OpenGL才只能知道怎样根据窗口大小显示数据和坐标。
    */
    glViewport(0, 0, 800, 600);   

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  // 设置回调函数,每当窗口改变大小，GLFW会调用这个函数并填充相应的参数供我们处理。

    // 渲染循环
    while(!glfwWindowShouldClose(window))
    {
        // 输入
        processInput(window);
        // 渲染指令
        /**
         * 在每个新的渲染迭代开始的时候我们总是希望清屏，否则我们仍能看见上一次迭代的渲染结果（这可能是你想要的效果，但通常这不是）。我们可以通过调用glClear函数来清空
         * 屏幕的颜色缓冲，它接受一个缓冲位(Buffer Bit)来指定要清空的缓冲，可能的缓冲位有GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT。
         * 由于现在我们只关心颜色值，所以我们只清空颜色缓冲。
        */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // 检查并调用事件，交换缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}