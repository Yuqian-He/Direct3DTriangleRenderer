cmake_minimum_required(VERSION 3.15)
project(Direct3D12Renderer)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SYSTEM_VERSION "10.0.22621.0")

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.22621.0/um")
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.22621.0/shared")
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.22621.0/winrt")

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB SHADERS ${CMAKE_SOURCE_DIR}/shaders/*.hlsl)
file(GLOB SHADERS ${CMAKE_SOURCE_DIR}/include/*.h)

# 添加可执行文件
add_definitions(-DUNICODE -D_UNICODE)
add_executable(Direct3D12Renderer WIN32 src/main.cpp src/Renderer.cpp)

link_directories("C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22621.0/um/x64")

# 链接 Direct3D12 和 DXGI 库
target_link_libraries(Direct3D12Renderer d3d12 dxgi d3dcompiler)
