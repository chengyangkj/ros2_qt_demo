cmake_minimum_required(VERSION 3.5)
project(ros2_qt_demo)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Note: Compilation flag -fPIC is necessary. Otherwise, you'll receive error "You must build your code with position independent code if Qt was built with -reduce-relocations."
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -fPIC)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
# Note that ament_target_dependencies() in algo cannot export Boost::thread to downstream. As a result, qt_example_node, as a downstream of libalgo.so, needs to explicitly find_package() for Boost again so that qt_example_node is able to link to Boost::thread.
find_package(Boost 1.71.0 REQUIRED COMPONENTS thread)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB PRO_FORM_DIR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB PRO_RESOURCES_DIR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resource/*.qrc)
file(GLOB_RECURSE PRO_INCLUDE_DIR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/${PROJECT_NAME}/*.hpp *.h )
file(GLOB_RECURSE PRO_SOURCES_DIR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)
#搜索头文件的位置
include_directories(
        include/${PROJECT_NAME}
       ${CMAKE_CURRENT_BINARY_DIR}
)
#qt头文件moc文件resource文件处理
qt5_wrap_ui(QT_UI_HPP ${PRO_FORM_DIR})
qt5_wrap_cpp(QT_MOC_HPP ${PRO_INCLUDE_DIR})
qt5_add_resources(QT_RESOURCES_CPP ${PRO_RESOURCES_DIR})
add_executable(${PROJECT_NAME}
        ${PRO_SOURCES_DIR}
        ${QT_RESOURCES_CPP}
        ${PRO_INCLUDE_DIR}
        ${QT_MOC_HPP}
        ${PRO_FORM_DIR}
)
# Note that ament_target_dependencies() in algo cannot export Boost::thread to downstream. As a result, qt_example_node, as a downstream of libalgo.so, needs to explicitly ament_target_dependencies() for Boost again so that qt_example_node is able to link to Boost::thread.
ament_target_dependencies(${PROJECT_NAME} rclcpp  Boost)

target_link_libraries(${PROJECT_NAME}
        Qt5::Widgets
)

install(TARGETS ${PROJECT_NAME}
        DESTINATION lib/${PROJECT_NAME}
)

ament_package()
