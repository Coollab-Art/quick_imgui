#include <backends/imgui_impl_glfw.h>
#include <quick_imgui/quick_imgui.hpp>
#include "GLFW/glfw3.h"
#include "ImGuiWrapper.hpp"

namespace quick_imgui {

namespace {
    Callbacks& CallbackUserDataFromWindow(GLFWwindow* window) {
        return *static_cast<Callbacks*>(glfwGetWindowUserPointer(window));
    }
}

void loop(const char* window_name, Callbacks callbacks) {
    GLFWwindow* const window = ImGuiWrapper::create_window(window_name);
    callbacks.init_callback();

    // It will work as the local copy of callbacks will live during this loop function (same lifetime as the window)
    glfwSetWindowUserPointer(window, &callbacks);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        CallbackUserDataFromWindow(window).key_callback(key, scancode, action, mods);
        ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
    });

    glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
        CallbackUserDataFromWindow(window).mouse_button_callback(button, action, mods);
        ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
    });

    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos) {
        CallbackUserDataFromWindow(window).cursor_position_callback(xpos, ypos);
        ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);
    });


    glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
        CallbackUserDataFromWindow(window).scroll_callback(xoffset, yoffset);
        ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
    });

    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        CallbackUserDataFromWindow(window).size_callback(width, height);
    });

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGuiWrapper::begin_frame({0.302f, 0.302f, 0.302f, 1.000f});
        callbacks.loop_callback();
        ImGuiWrapper::end_frame(window);
    }

    ImGuiWrapper::shutdown(window);
}

} // namespace quick_imgui
