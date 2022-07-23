#include <quick_imgui/quick_imgui.hpp>
#include "ImGuiWrapper.h"

namespace quick_imgui {

void loop(const char* window_name, std::function<void()> callback)
{
    GLFWwindow* const window = ImGuiWrapper::create_window(window_name);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGuiWrapper::begin_frame();
        callback();
        ImGuiWrapper::end_frame(window, {0.302f, 0.302f, 0.302f, 1.000f});
    }

    ImGuiWrapper::shutdown(window);
}

} // namespace quick_imgui
