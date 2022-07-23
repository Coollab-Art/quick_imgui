#pragma once
#include <imgui/imgui.h>
#include <functional>

namespace quick_imgui {

void loop(const char* window_name, std::function<void()> callback);

} // namespace quick_imgui
