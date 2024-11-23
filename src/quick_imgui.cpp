#include <quick_imgui/quick_imgui.hpp>
#include "ImGuiWrapper.hpp"

namespace quick_imgui {

void loop(const char* window_name, std::function<void()> const& loop_callback)
{
    loop(window_name, []() {}, loop_callback);
}

void loop(const char* window_name, std::function<void()> const& init_callback, std::function<void()> const& loop_callback) // NOLINT(*easily-swappable-parameters)
{
    GLFWwindow* const window = ImGuiWrapper::create_window(window_name);
    init_callback();
    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGuiWrapper::begin_frame();
        loop_callback();
        ImGuiWrapper::end_frame(window, {0.302f, 0.302f, 0.302f, 1.000f});
    }

    ImGuiWrapper::shutdown(window);
}

} // namespace quick_imgui
