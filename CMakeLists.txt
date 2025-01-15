cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(TinyEngine)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/framework/thirdParty/glfw-3.3.8)

find_package(OpenGL REQUIRED)

# 设置源文件和头文件
set(SOURCES
    main.cpp
    framework/common/BaseApplication.cpp
    framework/graphics/OpenGLApplication.cpp
)

set(HEADERS
    framework/interface/IRuntimeModule.h
    framework/interface/Interface.h
    framework/interface/IApplication.h
    framework/common/BaseApplication.h
    framework/graphics/OpenGLApplication.h
)

# 包含头文件目录
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/common
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/thirdParty/glad/include
)

add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/framework/thirdParty/glad/src/glad.c)

# 将文件按目录分组
source_group("framework\\common" FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/common/BaseApplication.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/common/BaseApplication.h
)
source_group("framework\\interface" FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/interface/IApplication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/interface/Interface.h
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/interface/IRuntimeModule.h
)
source_group("framework\\graphics" FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/graphics/OpenGLApplication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/framework/graphics/OpenGLApplication.cpp
)

# 创建可执行文件
add_executable(TinyEngine ${SOURCES} ${HEADERS})

target_link_libraries(TinyEngine OpenGL::GL glfw glad)

# 判断平台，设置平台特定的配置
if(WIN32)
    message(STATUS "Building on Windows")
    
    # 设置 Windows 特有的设置（如果有的话）
    # 比如可能需要设置特定的链接库，或者编译选项
    
elseif(APPLE)
    message(STATUS "Building on macOS")

    # 设置 macOS 特有的设置（如果有的话）
    # 比如可以添加 macOS 特定的编译选项
    # target_link_libraries(TinyEngine PRIVATE macos_specific_lib)

elseif(UNIX)
    message(STATUS "Building on Linux")
    
    # 设置 Linux 特有的设置（如果有的话）
    # target_link_libraries(TinyEngine PRIVATE linux_specific_lib)

else()
    message(STATUS "Unknown platform")
endif()
