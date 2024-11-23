#include <iostream>
#include "quick_imgui/quick_imgui.hpp"

int main()
{
    quick_imgui::loop(
        "Quick ImGui",
        /* init callback */ []() { std::cout << "Init\n"; },
        /* loop callback */ []() { ImGui::ShowDemoWindow(); }
    );
}