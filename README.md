# quick_imgui

This library was designed to quickly get a test ImGui project up and running. It is not meant for production-ready apps, but instead for tests or quick demos. We use it inside CoolLibs to test libraries that require clients to have ImGui installed.

## Usage

To download and link this library to your project, simply add these lines to your *CMakeLists.txt*:
```cmake
include(FetchContent)
FetchContent_Declare(
    quick_imgui
    GIT_REPOSITORY https://github.com/CoolLibs/quick_imgui
    GIT_TAG 3b13c9e999ecf3e7a19f2642d4ae120e55552477
)
FetchContent_MakeAvailable(quick_imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE quick_imgui::quick_imgui)
```
If the library you are testing needs to link ImGui, also add this line in your *CMakeLists.txt*:
```cmake
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${quick_imgui_SOURCE_DIR}/lib)
```
Then you can use it like this:
```cpp
#include <quick_imgui/quick_imgui.hpp>

int main()
{
    quick_imgui::loop("Quick ImGui", []() {
        ImGui::ShowDemoWindow();
    });
}
```

## Running the tests

Simply use "tests/CMakeLists.txt" to generate a project, then run it.<br/>
If you are using VSCode and the CMake extension, this project already contains a *.vscode/settings.json* that will use the right CMakeLists.txt automatically.
