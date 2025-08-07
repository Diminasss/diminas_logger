cmake_minimum_required(VERSION 3.13)
project(diminas_logger VERSION 1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Default to Release if no build type is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build" FORCE)
endif()

# Allow building shared or static libraries
option(BUILD_SHARED_LIBS "Build diminas_logger as a shared library" ON)

# Collect source files
file(GLOB LOGGER_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/src/*.cpp
)

# Create the library target (shared or static)
add_library(diminas_logger ${LOGGER_SOURCES})

target_compile_definitions(diminas_logger
        PRIVATE DIMINAS_LOGGER_EXPORTS
)

# Ensure static builds are position-independent (for linking into shared libs)
if(NOT BUILD_SHARED_LIBS)
    set_target_properties(diminas_logger PROPERTIES POSITION_INDEPENDENT_CODE ON)
endif()

# Include directories for consumers
target_include_directories(diminas_logger
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib/include>
        $<INSTALL_INTERFACE:include>
)

# Set versioning for shared libraries
set_target_properties(diminas_logger PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Main executable
add_executable(main main.cpp)

target_link_libraries(main
        PRIVATE diminas_logger
)

# Installation rules
include(GNUInstallDirs)

install(TARGETS diminas_logger
        EXPORT diminas_loggerTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY lib/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT diminas_loggerTargets
        FILE diminas_loggerConfig.cmake
        NAMESPACE diminas_logger::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/diminas_logger
)
