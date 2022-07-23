cmake_minimum_required(VERSION 3.8)

add_library(quick_imgui)
add_library(quick_imgui::quick_imgui ALIAS quick_imgui)
target_compile_features(quick_imgui PUBLIC cxx_std_11)

# ---Add source files---
target_include_directories(quick_imgui PUBLIC include)
target_sources(quick_imgui PRIVATE
    src/quick_imgui.cpp
    src/ImGuiWrapper.cpp
)

# ---Setup warnings---
if(QUICK_IMGUI_ENABLE_WARNINGS_AS_ERRORS)
    message("-- [quick_imgui] Enabling warnings as errors for quick_imgui")

    if(MSVC)
        target_compile_options(quick_imgui PRIVATE /WX /W4)
    else()
        target_compile_options(quick_imgui PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
    endif()
else()
    message("-- [quick_imgui] Not using warnings as errors for quick_imgui")
endif()

# ---Add GLFW---
add_subdirectory(lib/glfw)
target_link_libraries(quick_imgui PRIVATE glfw)

# ---Add glad---
add_library(glad lib/glad/src/glad.c)
target_include_directories(glad PUBLIC lib/glad/include)
target_link_libraries(quick_imgui PRIVATE glad)

# ---Add Dear ImGui---
add_library(ImGui)
target_sources(ImGui PRIVATE
    lib/imgui/imgui_demo.cpp
    lib/imgui/imgui_draw.cpp
    lib/imgui/imgui_tables.cpp
    lib/imgui/imgui_widgets.cpp
    lib/imgui/imgui.cpp
    lib/imgui/misc/cpp/imgui_stdlib.cpp
)
target_include_directories(ImGui PUBLIC lib/imgui)

# Build ImGui with glfw
target_link_libraries(ImGui PRIVATE glfw)
target_sources(ImGui PRIVATE lib/imgui/backends/imgui_impl_glfw.cpp)

# Build ImGui with OpenGL
target_sources(ImGui PRIVATE lib/imgui/backends/imgui_impl_opengl3.cpp)

# Link to ImGui
target_link_libraries(quick_imgui PUBLIC ImGui)
target_include_directories(quick_imgui PUBLIC lib)