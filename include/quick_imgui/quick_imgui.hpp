#pragma once
#include <imgui/imgui.h>
#include <chrono>
#include <functional>
#include <vector>

namespace quick_imgui {

void loop(const char* window_name, std::function<void()> const& loop_callback);
void loop(const char* window_name, std::function<void()> const& init_callback, std::function<void()> const& loop_callback);

/// A convenience class to measure the performance of a block of code, and display it with ImGui
/// Press space to pause the graphics
class AverageTime {
public:
    void start();
    void stop();
    auto average_time_ms() const -> float;
    void imgui_plot() const;

private:
    std::chrono::steady_clock::time_point _start_time{};
    std::vector<float>                    _times{};
    mutable std::vector<float>            _times_when_paused{};
};

} // namespace quick_imgui
