cmake_minimum_required(VERSION 3.16)

project(praxis_ex VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.1
)

FetchContent_MakeAvailable(glm)

find_package(Qt6 REQUIRED COMPONENTS OpenGL OpenGLWidgets Widgets)

set(${PROJECT_NAME}_RESOURCES
    "/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/bonsai(size=256x256x256,spacing=1x1x1).raw"
    "/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/neghip(size=64x64x64,spacing=1x1x1).raw"
    "/Users/asjalrashidi/TUDa/Academics/Spring 2026/CG II/Exercises/Programming Exercise 1/framework/data/Stanford_Bunny_sample(size=128x128x128,spacing=1x1x1).raw"
)

set(PROJECT_HEADERS
    include/ui/MainWindow.h
    include/ui/RenderWidget.h
    include/gris/GridCell.h
    include/gris/TriangeMesh.h
    include/gris/Camera.h
    include/gris/BoundingBox.h
    include/gris/VolumeData.h
    include/ui/SettingsWidget.h
    include/gris/mc_look_up.h
    include/VolumeVisualisation.h
    include/ui/LoadDialog.h
)

set(PROJECT_SOURCES
    src/main.cpp
    src/ui/MainWindow.cpp
    src/ui/RenderWidget.cpp
    src/gris/Camera.cpp

    src/ui/SettingsWidget.cpp
    src/VolumeVisualisation.cpp
    src/ui/LoadDialog.cpp
)

qt_wrap_ui(PROJECT_SOURCES
    ui/MainWindow.ui
    ui/SettingsWidget.ui
    ui/LoadDialog.ui
)

qt_wrap_cpp(PROJECT_SOURCES
    include/ui/MainWindow.h
    include/ui/RenderWidget.h
    include/ui/SettingsWidget.h
    include/ui/LoadDialog.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src
    include
    ${CMAKE_CURRENT_BINARY_DIR}

)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glm::glm
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    Qt6::Widgets
)

foreach(${PROJECT_NAME}_RESOURCE ${${PROJECT_NAME}_RESOURCES})
    configure_file(${${PROJECT_NAME}_RESOURCE} ${${PROJECT_NAME}_RESOURCE} COPYONLY)
endforeach()


set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
