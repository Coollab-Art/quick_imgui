#include <quick_imgui/quick_imgui.hpp>

int main()
{
    quick_imgui::loop("Quick ImGui", []() {
        ImGui::ShowDemoWindow();
    });
}