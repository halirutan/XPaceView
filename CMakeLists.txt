cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(XPaceView VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_PREFIX_PATH   "/home/patrick/Qt/5.12.6/gcc_64/lib/cmake")
set(QT_QMAKE_EXECUTABLE "/home/patrick/Qt/5.12.6/gcc_64/bin/qmake")

find_package(Qt5 COMPONENTS Core Gui Qml Quick QuickControls2 REQUIRED)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DQT_QML_DEBUG ")

# Only used to make qml files accessible in VS
file(GLOB_RECURSE QML_SRC "*.qml")
file(GLOB_RECURSE JS_SRC "*.js")
source_group("Qml Files" FILES ${QML_SRC})

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/backend.cpp
        resources.qrc
        ${QML_SRC}
        ${JS_SRC}
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        src
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Qml
        Qt5::Quick
        Qt5::QuickControls2
        )

target_compile_features(${PROJECT_NAME}
        PUBLIC
        cxx_std_14
        )

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        AUTOMOC ON
        AUTORCC ON
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )
