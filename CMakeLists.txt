cmake_minimum_required(VERSION 3.10)
project(GraphicalTextEditor)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(SOURCES
    main.cpp
    text_editor.cpp
)

set(HEADERS
    text_editor.h
)

# Add the moc generation step
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

add_executable(graphical_text_editor ${SOURCES} ${MOC_SOURCES})
target_link_libraries(graphical_text_editor Qt5::Widgets)
