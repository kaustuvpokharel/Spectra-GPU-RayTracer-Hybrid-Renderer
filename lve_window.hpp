#ifndef LVE_WINDOW_H
#define LVE_WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace lve
{
    class LveWindow
    {
    public:
        LveWindow(int w, int h, std::string name);
        ~LveWindow();

        //deletes copy constructor
        LveWindow(const LveWindow&) = delete;
        //deletes assignment operator deletion
        LveWindow& operator=(const LveWindow&) = delete;

        bool shouldClose()
        {
            return glfwWindowShouldClose(window);
        }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
    private:
        void initWindow();


        const int width;
        const int height;

        std::string windowName;
        GLFWwindow* window;
    };
}


#endif // LVE_WINDOW_H
