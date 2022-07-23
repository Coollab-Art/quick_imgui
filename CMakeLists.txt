cmake_minimum_required(VERSION 3.8)

add_library(quick_imgui)
add_library(quick_imgui::quick_imgui ALIAS quick_imgui)
target_compile_features(quick_imgui PUBLIC cxx_std_11)

# ---Add source files---
target_include_directories(quick_imgui PUBLIC include)
target_sources(quick_imgui PRIVATE
    src/quick_imgui.cpp
)

# ---Setup warnings---
if (QUICK_IMGUI_ENABLE_WARNINGS_AS_ERRORS)
    message("-- [quick_imgui] Enabling warnings as errors for quick_imgui")
    if(MSVC)
        target_compile_options(quick_imgui PRIVATE /WX /W4)
    else()
        target_compile_options(quick_imgui PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
    endif()
else()
    message("-- [quick_imgui] Not using warnings as errors for quick_imgui")
endif()
