project(mgl)
cmake_minimum_required(VERSION 3.18)
include(FetchContent)
# set(CMAKE_OSX_ARCHITECTURES "arm64")
enable_language(OBJCXX)
enable_language(OBJC)
enable_language(CXX)

FILE(GLOB MyCSources MGL/src/*.c)
FILE(GLOB MyMSources MGL/src/*.m)

add_library(mgl SHARED ${MyCSources} ${MyMSources})

target_include_directories(mgl PUBLIC MGL/include MGL/include/GL)

set_source_files_properties(MGL/src/MGLRenderer.m PROPERTIES COMPILE_FLAGS "-x objective-c")
set_source_files_properties(MGL/src/MGLTextures.m PROPERTIES COMPILE_FLAGS "-x objective-c")

# set(CMAKE_C_FLAGS "-fobjc-arc")
target_compile_options(mgl PRIVATE "-fobjc-arc")

# target_compile_definitions(mgl PUBLIC 
#                                 ENABLE_OPT=0 
#                                 SPIRV_CROSS_C_API_MSL=1
#                                 SPIRV_CROSS_C_API_GLSL=1
#                                 SPIRV_CROSS_C_API_CPP=1
#                                 SPIRV_CROSS_C_API_REFLECT=1
#                                 )

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(CMAKE_SHARED_LINKER_FLAGS "-lc++ -framework Quartz -framework AppKit -framework Quartzcore -framework IOKit -framework Metal -framework ApplicationServices -framework CoreGraphics -framework Cocoa  -framework Foundation")

# find_package(glm REQUIRED)
find_package(OpenGL REQUIRED)
# find_library(GLSLANG glslang external/glslang/build/glslang)
# find_library(GENERICCODEGEN GenericCodeGen external/glslang/build/glslang)
# find_library(MACHINEINDEPENDENT MachineIndependent external/glslang/build/glslang)
# find_library(OGLCOMPILER OGLCompiler external/glslang/build/OGLCompilersDLL)
# find_library(OSDEPENDENT OSDependent external/glslang/build/glslang/OSDependent/Unix)

# find_library(SPIRVCROSS spirv-cross-core external/SPIRV-Cross/build)
# find_library(SPIRVCROSSC spirv-cross-c external/SPIRV-Cross/build)
# find_library(SPIRVCROSSCPP spirv-cross-cpp external/SPIRV-Cross/build)
# find_library(SPIRVCROSSMSL spirv-cross-msl external/SPIRV-Cross/build)
# find_library(SPIRVCROSSGLSL spirv-cross-glsl external/SPIRV-Cross/build)
# find_library(SPIRVCROSSHLSL spirv-cross-hlsl external/SPIRV-Cross/build)
# find_library(SPIRVCROSSREFLECT spirv-cross-reflect external/SPIRV-Cross/build)
# find_library(SPIRVCROSSUTIL spirv-cross-util external/SPIRV-Cross/build)

# find_library(GLSLANGDEFAULT glslang-default-resource-limits external/glslang/build/StandAlone)

# find_library(SPIRVLIB SPIRV external/glslang/build/SPIRV)
# find_library(SPVREMAPPER SPVRemapper external/glslang/build/SPIRV)

# find_library(SPIRVTOOLS SPIRV-Tools external/SPIRV-Tools/build/source)
# find_library(SPIRVTOOLSOPT SPIRV-Tools-opt external/SPIRV-Tools/build/source/opt)
# find_library(CUSTOMGLFW glfw3 external/glfw/build/src)

# SPIRV-Headers
if (NOT SPIRV_Headers_POPULATED)
    FetchContent_Declare(
        SPIRV-Headers
        GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Headers.git
        GIT_SHALLOW TRUE
        GIT_TAG main
    )
    FetchContent_MakeAvailable(SPIRV-Headers)
endif()

FetchContent_Declare(
        SPIRV-Tools
        GIT_REPOSITORY https://github.com/KhronosGroup/SPIRV-Tools.git
        GIT_SHALLOW TRUE
        GIT_TAG main
)
FetchContent_MakeAvailable(SPIRV-Tools)

if (NOT glslang_POPULATED)
    set(ENABLE_OPT OFF CACHE BOOL "" FORCE)
    set(ENABLE_HLSL OFF CACHE BOOL "" FORCE)
    set(ALLOW_EXTERNAL_SPIRV_TOOLS ON CACHE BOOL "" FORCE)
    FetchContent_Declare(
        glslang
        # URL https://github.com/KhronosGroup/glslang/archive/14.3.0.tar.gz
        GIT_REPOSITORY https://github.com/KhronosGroup/glslang.git
        GIT_TAG main
        GIT_SHALLOW TRUE
    )
    set(SPIRV_CROSS_ENABLE_TESTS OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(
        SPIRV-Cross
        GIT_REPOSITORY https://github.com/r58Playz/SPIRV-Cross.git
        GIT_TAG uniform-constants
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(glslang SPIRV-Cross)
endif()

if(NOT OpenGL_Registry_POPULATED)
    FetchContent_Declare(
        OpenGL-Registry
        GIT_REPOSITORY https://github.com/KhronosGroup/OpenGL-Registry.git
        GIT_SHALLOW TRUE
        GIT_TAG main
    )
    FetchContent_MakeAvailable(OpenGL-Registry)
endif()

if(NOT ezxml_POPULATED)
    FetchContent_Declare(
        ezxml
        GIT_REPOSITORY https://github.com/lxfontes/ezxml.git
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(ezxml)
endif()


 target_include_directories(${PROJECT_NAME} PUBLIC
         ${spirv-tools_SOURCE_DIR}/include
#                             external/SPIRV-Cross/include
#                             external/SPIRV-Cross
#                             external/glslang/glslang/Include
#                             external/SPIRV-Tools/include
#                             glfwlib/include
                             )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

target_link_libraries(${PROJECT_NAME}
    OpenGL::GL
    glslang::glslang
    glslang::SPIRV
    glslang::glslang-default-resource-limits
    # spirv-tools::spirv-tools
    spirv-cross-c
    #SPIRV-Headers
    ${SPIRV_TOOLS}
)

add_subdirectory(test_mgl)
