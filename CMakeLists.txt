cmake_minimum_required(VERSION 3.10)
project(advcalclib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/algebra.cpp
    src/calc.cpp
    src/calculus.cpp
    src/elec.cpp
    src/geom.cpp
    src/physics.cpp
    src/utils.cpp
    src/stat.cpp
)

# Header files
set(HEADERS
    include/algebra.hpp
    include/calc.hpp
    include/calculus.hpp
    include/elec.hpp
    include/geom.hpp
    include/physics.hpp
    include/stat.hpp
    include/utils.hpp
)

# Create shared library
add_library(advcalclib SHARED ${SOURCES})

# Include directories
target_include_directories(advcalclib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Installation rules (cross-platform)
install(TARGETS advcalclib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)

install(FILES advcalclib.pc
    DESTINATION lib/pkgconfig
    OPTIONAL
)

install(FILES advcalclibConfig.cmake
    DESTINATION lib/cmake/advcalclib
    OPTIONAL
)
# Example executable
#add_executable(exam example.cpp)
target_link_libraries(exam PRIVATE advcalclib)
