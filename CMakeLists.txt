cmake_minimum_required(VERSION 2.8)
project(ch2d)

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(ch2d_VERSION_MAJOR 0)
set(ch2d_VERSION_MINOR 1)

configure_file(
  "${PROJECT_SOURCE_DIR}/config/Config.hpp.in"
  "${PROJECT_BINARY_DIR}/config/Config.hpp"
  )

include_directories("${PROJECT_BINARY_DIR}/include/")

set(EXECUTABLE_NAME "ch2d")
add_executable(${EXECUTABLE_NAME}
    src/ch2d/ch2d.cpp
    src/ch2d/System.cpp
    src/ch2d/handlers/TextureHandler.cpp
    src/ch2d/handlers/SpriteHandler.cpp
    src/ch2d/handlers/EventHandler.cpp
    src/ch2d/handlers/ViewHandler.cpp
    src/ch2d/bindings/sprite.cpp
    src/ch2d/bindings/texture.cpp
    src/ch2d/bindings/keyboard.cpp
    src/ch2d/bindings/mouse.cpp
    src/ch2d/bindings/view.cpp
    src/ch2d/bindings/window.cpp
    src/ch2d/bindings/system.cpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

find_package(Lua 5.2 REQUIRED)
if(LUA_FOUND)
   include_directories(${LUA_INCLUDE_DIR})
   target_link_libraries(${EXECUTABLE_NAME} ${LUA_LIBRARIES})
endif()

add_definitions ("-Wall")
target_compile_features(ch2d PRIVATE cxx_range_for)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${ch2d_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${ch2d_VERSION_MINOR}")
include(CPack)
