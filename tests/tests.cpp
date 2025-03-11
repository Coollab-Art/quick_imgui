#include <iostream>
#include "quick_imgui/quick_imgui.hpp"

void key_callback(int key, int scancode, int action, int mods)
{
    std::cout << "Key: " << key << " Scancode: " << scancode << " Action: " << action << " Mods: " << mods << std::endl;
}

int main()
{
    quick_imgui::loop(
        "Quick ImGui",
        {
            .init = []() { std::cout << "Init\n"; },
            .loop = []() { ImGui::ShowDemoWindow(); },
            .key_callback = key_callback,
            .mouse_button_callback = [](int button, int action, int mods) { std::cout << "Button: " << button << " Action: " << action << " Mods: " << mods << std::endl; },
        }
    );
}